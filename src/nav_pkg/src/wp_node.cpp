#include <ros/ros.h>
#include <std_msgs/String.h>

ros::Publisher nav_pub;
int current_waypoint = 1;
bool navigation_complete = false; // 添加导航完成标志

void NavResultCallback(const std_msgs::String &msg)
{
    ROS_WARN("[NavResultCallback] %s",msg.data.c_str());

    if(msg.data == "done")
    {
        if (current_waypoint < 4)
        {
            current_waypoint++;
            std_msgs::String next_msg;
            next_msg.data = std::to_string(current_waypoint);
            nav_pub.publish(next_msg);
            ROS_INFO("Published waypoint: %s",next_msg.data.c_str());
        }
        else{
            ROS_INFO("All waypoints (1-4) have completed!");
            navigation_complete = true; // 设置导航完成标志
        }
    }
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"wp_node");

    ros::NodeHandle n;
    nav_pub = n.advertise<std_msgs::String>("/waterplus/navi_waypoint",10);
    ros::Subscriber res_sub = n.subscribe("/waterplus/navi_result",10,NavResultCallback);

    // 等待发布者连接建立
    ros::Rate rate(10);
    while(nav_pub.getNumSubscribers() == 0 && ros::ok())
    {
        ROS_INFO("Waiting for subscribers...");
        rate.sleep();
    }

    // 发布第一个航点
    std_msgs::String nav_msg;
    nav_msg.data = "1";
    nav_pub.publish(nav_msg);
    ROS_INFO("Initial waypoint published!");

    // 使用ros::spinOnce()和循环代替ros::spin()
    while(ros::ok() && !navigation_complete)
    {
        ros::spinOnce(); // 处理一次回调
        rate.sleep();    // 控制循环频率
    }

    ROS_INFO("Exiting waypoint navigation node...");
    return 0;
}
