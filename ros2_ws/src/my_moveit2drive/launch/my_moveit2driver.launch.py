from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    # 定义被调用的 Launch 文件路径
    panda_moveit_launch = PathJoinSubstitution([
        FindPackageShare("panda_moveit_config"),       # 功能包名
        "launch",                               # 功能包下的 launch 目录
        "demo.launch.py"                        # 目标 Launch 文件
    ])

    # 包含目标 Launch 文件
    include_panda_moveit = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(panda_moveit_launch),
        launch_arguments={
            "use_sim_time": "false",            # 可选：传递参数
            "example_arg": "value"              # 自定义参数
        }.items()
    )

    return LaunchDescription([
        include_panda_moveit                     # 添加到 Launch 描述中
    ])