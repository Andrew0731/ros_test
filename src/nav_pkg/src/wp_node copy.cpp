#include <ros/ros.h>
#include <std_msgs/String.h>

ros::Publisher nav_pub;
int current_waypoint = 1;
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
        }
    }
}
int main(int argc, char** argv)
{
    ros::init(argc,argv,"wp_node");

    ros::NodeHandle n;
    nav_pub = n.advertise<std_msgs::String>("/waterplus/navi_waypoint",10);
    ros::Subscriber res_sub = n.subscribe("/waterplus/navi_result",10,NavResultCallback);

    sleep(1);

    std_msgs::String nav_msg;
    nav_msg.data = "1";
    nav_pub.publish(nav_msg);
    ROS_INFO("Initial waypoint published!");

    ros::spin();
    return 0;
}