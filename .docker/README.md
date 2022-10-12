# ROS2 Docker Containers
Provides a basic preconfigured docker container for development and deployment purposes. To use it, make sure you have [Docker](https://docs.docker.com/get-docker/) installed, then build and run the image :

```shell
$ docker build --tag r2cperfbmark:humble --file .docker/Dockerfile .
$ docker run -it --privileged --network=host r2cperfbmark:humble ros2 launch bmark_bringup bmark.launch.py
```