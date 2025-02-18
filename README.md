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
