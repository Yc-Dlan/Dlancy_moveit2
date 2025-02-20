#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/pose.hpp>

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("moveit_demo");
    
    // 初始化MoveIt接口
    moveit::planning_interface::MoveGroupInterface move_group_interface(node, "arm_group");
    
    // 设置目标位置（示例坐标）
    geometry_msgs::msg::Pose target_pose;
    target_pose.position.x = 0.3;
    target_pose.position.y = 0.2;
    target_pose.position.z = 0.5;
    target_pose.orientation.w = 1.0;
    
    try {
        // 设置目标位姿
        move_group_interface.setPoseTarget(target_pose);
        
        // 创建一个 Plan 对象
        moveit::planning_interface::MoveGroupInterface::Plan plan;

        // 规划运动
        moveit::core::MoveItErrorCode success = move_group_interface.plan(plan);
        if (!success) {
            RCLCPP_ERROR(node->get_logger(), "Planning failed!");
            return 1;
        }
        
        // 执行规划的轨迹
        if (plan.trajectory_.joint_trajectory.points.empty()) {
            RCLCPP_ERROR(node->get_logger(), "Trajectory is empty. Planning failed!");
            return 1;
        }
        
        move_group_interface.execute(plan);
        RCLCPP_INFO(node->get_logger(), "Motion executed successfully!");
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node->get_logger(), "Error: %s", e.what());
    }
    
    rclcpp::shutdown();
    return 0;
}