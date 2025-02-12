FROM osrf/ros:humble-desktop-full

# 定义用户和用户组
ARG USERNAME=yc-dlan
ARG USER_UID=1000
ARG USER_GID=$USER_UID

ENV DEBIAN_FRONTEND=noninteractive

# 安装基础依赖
RUN apt-get update \
    && apt-get install -y \
    net-tools \
    nautilus \
    bash-completion \
    clangd \
    git \
    gedit \
    gdb \
    python3-pip \
    # 添加ROS2编译工具
    ros-dev-tools \
    # 安装MoveIt2核心依赖
    ros-humble-moveit \
    ros-humble-moveit-visual-tools \
    ros-humble-xacro \
    && pip3 install -U colcon-common-extensions

# 安装必要的 ROS 包
RUN apt-get update && apt-get install -y \
    ros-humble-geometric-shapes \
    ros-humble-urdf \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher \
    ros-humble-joint-state-publisher-gui \
    ros-humble-rviz2 \
    ros-humble-xacro \
    ros-humble-moveit-resources-panda-description
    
# 安装colcon构建系统
RUN pip3 install -U colcon-common-extensions

# 创建用户组和用户
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    # 配置环境变量
    && echo "$USERNAME:'" | chpasswd \
    # 允许用户使用 sudo
    && usermod -aG sudo $USERNAME \
    && echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers \
    && echo 'source /opt/ros/humble/setup.bash' >> /home/$USERNAME/.bashrc \
    # 使新用户的 `.bashrc` 文件生效
    && chown $USERNAME:$USERNAME /home/$USERNAME/.bashrc

# 创建工作空间目录
RUN mkdir -p /ros2_ws/src

WORKDIR /home/${USERNAME}

CMD [ "/bin/bash" ]