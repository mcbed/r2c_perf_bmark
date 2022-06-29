import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    urdf_file_name = 'config/bmark.urdf'
    urdf = os.path.join(
        get_package_share_directory('bmark_bringup'),
        urdf_file_name)
    with open(urdf, 'r') as infp:
        robot_description_content = infp.read()
    robot_description = {"robot_description": robot_description_content}

    bmark_controllers = PathJoinSubstitution(
        [
            FindPackageShare("bmark_bringup"),
            "config",
            "bmark_controllers.yaml",
        ]
    )

    controller_manager_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_description, bmark_controllers],
        output="screen",
    )

    spawn_bdb = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["bmark_duration_broadcaster"],
        output="screen",
    )

    nodes = [
        controller_manager_node,
        spawn_bdb,
    ]
    return LaunchDescription(nodes)