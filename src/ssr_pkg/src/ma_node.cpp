#include <ros/ros.h>
#include <qq_msgs/carry.h>

void chao_callback(const qq_msgs::carry::ConstPtr& msg)
{
    ROS_INFO("Grade: %s", msg->grade.c_str());
    ROS_WARN("Star: %d", msg->star); // 假设star是整数类型
    ROS_INFO("Data: %s", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    ros::init(argc,argv, "ma_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chat_messages",10,chao_callback);

    while(ros::ok())
    {
        ros::spin();
    }
    return 0;
}