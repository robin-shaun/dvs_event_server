# DVS Event Server

## Introduce
This package is used to transport "dvs/events" ROS topic to Python, because Python ROS callback has a large delay.

## Dependency
[rpg_dvs_ros](https://github.com/uzh-rpg/rpg_dvs_ros)

[cppzmq](https://github.com/zeromq/cppzmq)

[protobuf](https://developers.google.com/protocol-buffers/docs/cpptutorial)

## Compile
Once the dependencies above are installed, the proto files need to be recompiled.

```
cd src/
protoc event_array.proto --cpp_out .
```

## Usage
See [E2VID_ROS](https://github.com/robin-shaun/E2VID_ROS) 