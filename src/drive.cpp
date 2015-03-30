#include "ros/ros.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "iostream"
using namespace std;
#include "sstream"

int main(int argv,char **argc)
{
	ros::init(argv,argc,"talker");
	ros::NodeHandle n;
	ros::Publisher chat_t=n.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel",1);
	ros::Rate rate_loop(10);
	int count=0;
	stringstream ss;
	geometry_msgs::Vector3 speed;
	geometry_msgs::Vector3 angle;
	geometry_msgs::Twist msg;
	while(ros::ok())
	{
		ss.str("");
		ss<<"hello "<<count;
		speed.x=1.0;
		speed.y=0.0;
		speed.z=0.0;

		angle.x=0.0;
		angle.y=0.0;
		angle.z=0.0;

		msg.linear=speed;
		msg.angular=angle;



		chat_t.publish(msg);
		count++;
		ros::spinOnce();
		rate_loop.sleep();

	}
	speed.x=0.0;
	msg.linear=speed;
	chat_t.publish(msg);


}
