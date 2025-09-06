#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"turltle_vel_ctrl_node");
    ros::NodeHandle nh;
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",20);
    ros::Rate loop_rate(1);
    while(ros::ok())
    {
        geometry_msgs::Twist vel_cmd;
        vel_cmd.linear.x=2;
        vel_cmd.linear.y=1;
        vel_cmd.linear.z=0;
        vel_cmd.angular.x=0;
        vel_cmd.angular.y=0;
        vel_cmd.angular.z=1;
        vel_pub.publish(vel_cmd);
        loop_rate.sleep(); 
        ros::spinOnce();
    }
    return 0;
}