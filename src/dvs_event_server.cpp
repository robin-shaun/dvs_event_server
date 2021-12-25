#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ros/ros.h>
#include <dvs_msgs/EventArray.h>
#include <dvs_msgs/Event.h>
#include "event_array.pb.h"
#include <deque> 
#include <thread>
#include <zmq.hpp>

using namespace std;
using namespace event_array::protobuf;
deque<double> ts;
deque<int32_t> x;
deque<int32_t> y;
deque<int32_t> polarity;
bool start = false;
bool ready = false;
pthread_mutex_t event_vec_lock = PTHREAD_MUTEX_INITIALIZER;

void eventCallback(const dvs_msgs::EventArray::ConstPtr &msg, int event_window_size)
{
    if (!start)
        return;
    pthread_mutex_lock(&event_vec_lock);
    for (auto event : msg->events) 
        {
            ts.push_back(event.ts.toSec());
            x.push_back(event.x);
            y.push_back(event.y);
            polarity.push_back(event.polarity);
            if (ts.size() > event_window_size)
            {
                ready = true;
            }
            if (ts.size() > 100 * event_window_size)
            {
                ts.pop_front();
                x.pop_front();
                y.pop_front();
                polarity.pop_front();
            }
        }
    pthread_mutex_unlock(&event_vec_lock);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "dvs_event_server");
    ros::NodeHandle nh_("~");
    int event_window_size;
    nh_.param<int>("event_window_size", event_window_size, 30000);
    string event_topic_name;
    nh_.param<string>("event_topic_name", event_topic_name, "dvs/events");
    string ip_address;
    nh_.param<string>("ip_address", ip_address, "127.0.0.1");
    string port;
    nh_.param<string>("port", port, "10001");
    ros::Subscriber sub = nh_.subscribe<dvs_msgs::EventArray>(event_topic_name, 100, boost::bind(&eventCallback, _1, event_window_size));
    thread ros_spin([&]() {
        ros::spin();
    });

    Event_Array event_array;

    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://" + ip_address + ":" + port);

    while(ros::ok())
    {
        zmq::message_t request;

        // Wait for next request from client
        socket.recv(&request);
        start = true;
        // Send reply back to client
        if (!ready)
        {
            zmq::message_t reply(9);
            memcpy ((void *)reply.data(), "Not ready", 9);
            socket.send(reply);
        }
        else
        {
            pthread_mutex_lock(&event_vec_lock);
            for (int i = 0; i < event_window_size; i++)
            {
                event_array.add_timestamp(ts.at(0));
                ts.pop_front();
                event_array.add_x(x.at(0));
                x.pop_front();
                event_array.add_y(y.at(0));
                y.pop_front();
                event_array.add_polarity(polarity.at(0));
                polarity.pop_front();
            }
            pthread_mutex_unlock(&event_vec_lock);

            string data;
            event_array.SerializeToString(&data);
            zmq::message_t reply(data.size());
            memcpy ((void *)reply.data(), data.c_str(), data.size());
            socket.send(reply);

            event_array.Clear();
            ready = false;
        }
    }    
    return 0;
}