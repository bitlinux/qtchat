# qtchat
Linux chat software based on QT5 

<html>
    <table style="margin-left: auto; margin-right: auto;">
        <tr>
            <td>
                <img src=https://github.com/bitlinux/qtchat/blob/master/resources/list.png  alt="list" />
            </td>
            <td>
                <img src=https://github.com/bitlinux/qtchat/blob/master/resources/logo2.png  alt="logo" />
            </td>
        </tr>
    </table>
</html>




***

### 吴杰
* 27/5/19  
需求分析和任务分配
* 3/6/19  
实现主界面基本图形框架(好友列表待实现
* 8/6/19  
实现好友列表中的frieditem，能够循环加入item到列表中（待实现从服务端获取数据和打开聊天窗口的界面）
* 9/6/19  
修复bug，新增修改昵称dialog、上传头像文件选取、item到窗口的链接
* 3/7/19  
实现好友列表、在线状态、好友请求列表实时刷新，完善私聊窗口文件传送
* 4/7/19  
增加BBS模块界面，编写bbsitem，新建帖子界面
待实现：帖子详情界面，在帖子详情界面实现回复和删除帖子（通过发帖用户id与自己id进行比较，来确定是否显示删除按钮），需要新增回复窗口或者使用点击用户昵称传递参数的功能；BBS的文件上传和下载模块的连接
* 5/7/19  
实现BBS帖子详情界面，实现帖子回复，帖子删除，BBS中帖子item的实时刷新功能，点击查看帖子详情的时候从服务器加载帖子下的所有回复
* 6/7/19  
界面美化：FriendItems和BBSItems之间绘制1px灰色分割线，Login界面添加Logo，文字布局/颜色调整；软件功能测试
* 7/7/19  
功能测试，项目文件清理，部分文档撰写

### 于浩淼
* 27/5/19  
数据库表设计
* 3/6/19  
设计实现私聊、群聊 GUI

### 张登凯
* 27/5/19  
sqlite数据库使用

### 李海龙
* 27/5/19  
Qt5 GUI开发框架使用
* 1/7/19  
设计实现BBS的文件分享模块的界面及功能，包括文件的上传，下载，显示
BBS文件分享服务器搭建、维护
* 3/7/19  
设计实现BBS新建帖子操作的界面、功能
* 7/7/19  
功能测试，部分项目文档撰写

---

