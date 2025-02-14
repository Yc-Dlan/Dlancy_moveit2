cmake_minimum_required(VERSION 3.8)
project(my_moveit2driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(urdf REQUIRED)
find_package(geometric_shapes REQUIRED)
find_package(moveit_resources_panda_description REQUIRED)
find_package(panda_moveit_config REQUIRED)

include_directories(
  ${rclcpp_INCLUDE_DIRS}
  ${moveit2_core_INCLUDE_DIRS}
  ${moveit_ros_planning_interface_INCLUDE_DIRS}
  ${urdf_INCLUDE_DIRS}
  ${geometric_shapes_INCLUDE_DIRS}
  ${moveit_resources_panda_description_INCLUDE_DIRS}
  ${panda_moveit_config_INCLUDE_DIRS}
)
add_executable(moveit2_node node/moveit2_node.cpp)

ament_target_dependencies(moveit2_node
  rclcpp
  moveit_core
  moveit_ros_planning_interface
  urdf
  geometric_shapes
  moveit_resources_panda_description
  panda_moveit_config
)

target_link_libraries(moveit2_node
  ${rclcpp_LIBRARIES}
  ${moveit_core_LIBRARIES}
  ${moveit_ros_planning_interface_LIBRARIES}
  ${urdf_LIBRARIES}
  ${geometric_shapes_LIBRARIES}
  ${moveit_resources_panda_description_LIBRARIES}
  ${panda_moveit_config_LIBRARIES}
)

install(TARGETS moveit2_node
  DESTINATION lib/${PROJECT_NAME})
  

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
