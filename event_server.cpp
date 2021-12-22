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
using namespace std;
using namespace event_array::protobuf;
int event_window_size = 30000;
deque<double> ts;
deque<int32_t> x;
deque<int32_t> y;
deque<int32_t> polarity;

void eventCallback(const dvs_msgs::EventArray::ConstPtr &msg)
{
    for (auto event : msg->events) 
        {
            ts.push_back(event.ts.toSec());
            x.push_back(event.x);
            y.push_back(event.y);
            polarity.push_back(event.polarity);
            if (ts.size() >= event_window_size)
            {
                ts.pop_front();
                x.pop_front();
                y.pop_front();
                polarity.pop_front();
            }
        }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "event_server");
    ros::NodeHandle nh_;
    ros::Subscriber sub = nh_.subscribe("/dvs/events", 100, eventCallback);
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);

    Event_Array event_array;

    //接收客户端请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    thread ros_spin([&]() {
        ros::spin();
    });
    while(ros::ok())
    {
        int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

        //向客户端发送数据
        for (int i = 0; i < event_window_size; i++)
        {
            auto event = event_array.add_event();
            event->set_timestamp(ts.at(i));
            event->set_x(x.at(i));
            event->set_y(y.at(i));
            event->set_polarity(polarity.at(i));
        }
        string data;
        event_array.SerializeToString(&data);
        char bts[data.length()];
        sprintf(bts, "%s", data.c_str());
        write(clnt_sock, bts, sizeof(bts));
    
        //关闭套接字
        close(clnt_sock);
    }
    close(serv_sock);

    return 0;
}