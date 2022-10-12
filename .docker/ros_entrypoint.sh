#!/bin/bash
set -e

sysctl -w kernel.sched_rt_runtime_us=-1

# setup ros environment
source "/opt/ros/$ROS_DISTRO/setup.bash"
export ROS_DOMAIN_ID=38
source "/ros2_dev/install/setup.bash"
exec "$@"
