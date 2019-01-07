#include<ros/ros.h>
#include"tutorials/msgf.h"

int main(int argc, char *argv[])
{

int x, y;
ros::init(argc,argv,"ros_tutorials_pub");
ros::NodeHandle nh;
srand(time(NULL));
//std::vector<int>i;
ros::Publisher pub = nh.advertise<tutorials::msgf>("message",1000);
ros::Rate loop_rate(10);
tutorials::msgf msg;
while(ros::ok())
{
x=rand()%20+1;
msg.v.resize(x);
msg.stamp = ros::Time::now();
for(int i=0;i<x;i++)
{
y= 1+ rand()%20;
msg.v[i]=y;
}
pub.publish(msg);

loop_rate.sleep();
}
return 0;
}