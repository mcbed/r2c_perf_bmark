ARG ROS_DISTRO="humble"
FROM ros:${ROS_DISTRO}

COPY . /ros2_dev/src/r2c_perf_bmark

RUN apt update && apt upgrade -y && \
    apt install autoconf libtool -y && \
    apt install ros-$ROS_DISTRO-ros2-control ros-$ROS_DISTRO-ros2-controllers -y
# Build all packages
RUN cd /ros2_dev && \
    . /opt/ros/humble/setup.sh  && \
    rosdep install --ignore-src --from-paths . -y -r && \
    colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release --symlink-install && \
    . install/setup.sh
# Add entrypoint
COPY .docker/ros_entrypoint.sh /ros_entrypoint.sh
RUN chmod 755 /ros_entrypoint.sh
ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]