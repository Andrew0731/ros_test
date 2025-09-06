#include <ros/ros.h>
#include <qq_msgs/carry.h>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"chao_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<qq_msgs::carry>("chat_messages",10);
    ros::Rate loop_rate(1);
    while(ros::ok())
    {
        printf("here i am!!!\n");
        qq_msgs::carry msg;
        msg.grade = "level 5";
        msg.star = 5;
        msg.data = "interesting";
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}
