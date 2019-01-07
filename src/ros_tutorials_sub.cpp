#include<ros/ros.h>
#include"tutorials/msgf.h"

void printResult(const tutorials::msgfConstPtr& msg)
{
ROS_INFO_STREAM("result:"<<msg);
}

int main(int argc, char *argv[]){
ros::init(argc,argv,"ros_tutorials_sub");
ros::NodeHandle nh;
ros::Subscriber sub = nh.subscribe("message",10,printResult);

ros::spin();
return 0;
}

std::ostream& operator<<(std::ostream & out, const tutorials::msgfConstPtr& msg)
{
for(int i=0;i<msg->v.size();i++)
{
out<<msg->v[i]*msg->v[i]<<" ";
}
out<<msg->stamp;
return out;
}