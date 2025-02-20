# Dlancy_moveit2
## 这是Dlancy的寒假大作业，有moveit2的功能包创建
### 使用教程
你是一个什么都不懂的新手，无需担心，仅仅需要复制加钠即可。
#### 注意事项
(bash)yc-dlan@CHINAMI-FL55LMD:~/Dlancy_moveit2/.devcontainer$ docker-compose up -d  
上述代码中： 
- (bash)中()代表你当前所处的环境：-docker进入容器前 -bash容器中
- yc-dlan@CHINAMI-FL55LMD代表你当前的用户身份
- ~/Dlancy_moveit2/.devcontainer代表你当前所在的位置
- docker-compose up -d代表当前的指令操作（在执行本功能包功能时，仅需要复制$后的内容即可，并且注意区分当前位置）
#### 1.克隆主播的仓库
选一个你喜欢的地方准备安装仓库。
```bash
>(docker)$ git clone https://github.com/Yc-Dlan/Dlancy_moveit2.git（按HTTP复制）   
>(docker)$ git clone git@github.com:Yc-Dlan/Dlancy_moveit2.git（按SSH复制，如果没有配置过SSH密钥则用上面那种）   
```
#### 2.进入下载好的仓库
```bash
>(docker) ~$ cd Dlancy_moveit2
```
#### 3.构建容器
```bash
>(docker) ~/Dlancy_moveit2$ cd .devcontainer/
>(docker) ~/Dlancy_moveit2/.devcontainer$ docker-compose up --build
```
如果构建成功你应该会看到如下式样：  
> Starting moveit2_container ... done   
> Attaching to moveit2_container
#### 4.进入容器
```bash
>(docker) ~/Dlancy_moveit2$ cd .devcontainer/
>(docker) ~/Dlancy_moveit2/.devcontainer$ docker-compose up -d（-d表示后台运行）
>(docker) ~/Dlancy_moveit2/.devcontainer$ docker exec -it moveit2_container bash
```
完成上面的操作之后，你应该顺利进入了我们的moveit2_container容器当中
#### 5.编译
```bash
>(bash) ~/Dlancy_moveit2/ros2_ws$ colcon build
>(bash) ~/Dlancy_moveit2/ros2_ws$ source install/setup.bash
```
此时你以及完成了功能包的拷贝，主要包含`panda_moveit_config`&`my_moveit2driver`两个文件，屏幕中也会显示：  
> Summary: 2 packages finisher [times]
#### 6.launch
此时我们仅需要启动launch文件就可以了
```bash
>(bash) ~/Dlancy_moveit2/ros2_ws$ ros2 launch my_moveit2driver my_moveit2driver.launch.py
```
此时应该就可以正常运行，开始moveit的基本使用，这里我们仅仅启动了demo文件，未实现其他功能，如读者有兴趣可在chapter 7中自行尝试。
#### 7.else
```bash
>(bash) ~/Dlancy_moveit2/ros2_ws$ ros2 launch panda_moveit_config (一些基本的功能包)
Examples:
- 1.demo.launch.py
>功能：
启动完整的 MoveIt 演示环境，包括：
-- MoveGroup 节点（核心规划服务）
-- RViz 可视化界面（默认加载运动规划插件）
-- 虚拟机器人（fake 控制器模拟执行）
-- 规划场景监视器（监听碰撞对象和状态）
>使用场景：
-- 快速验证机器人模型、运动规划和 RViz 交互。
- 2.move_group.launch.py
>功能：
单独启动 MoveGroup 节点，提供以下核心服务：
-- 运动规划（/plan_kinematic_path）
-- 轨迹执行（/execute_trajectory）
-- 碰撞检测（通过 PlanningScene）
>使用场景：
-- 集成到自定义系统中（如与真实硬件或仿真器连接时）。
- 3.moveit_rviz.launch.py
>功能：
启动 RViz 可视化界面，预配置：
-- 机器人模型显示
-- 运动规划面板（设置目标位姿、规划路径）
-- 碰撞物体显示
>使用场景：
-- 单独调试 RViz 配置或手动规划路径。
- 4.rsp.launch.py
>功能：
启动 Robot State Publisher，发布以下信息：
-- 机器人关节状态（通过 /joint_states）
-- TF 坐标系（从 URDF 解析）
>使用场景：
-- 当需要独立发布机器人状态时（如与其他传感器数据同步）。
- 5.spawn_controllers.launch.py
>功能：
加载并激活 ROS2 Control 控制器，例如：
-- joint_trajectory_controller（机械臂轨迹控制）
-- gripper_controller（夹爪控制）
>使用场景：
-- 连接真实硬件或 Gazebo 仿真时，控制实际关节运动。
- 6.static_virtual_joint_tfs.launch.py
>功能：
发布 静态虚拟关节的 TF 变换，例如：
-- 从 world 到机器人基座（如 panda_link0）的固定坐标系
>使用场景：
-- 统一多机器人系统或复杂场景的坐标系。
- 7.warehouse_db.launch.py
>功能：
启动 MoveIt 规划场景数据库服务，支持：
-- 存储和加载预先规划的轨迹
-- 管理场景中的碰撞物体
>使用场景：
-- 需要复用历史规划数据或离线规划时。
```