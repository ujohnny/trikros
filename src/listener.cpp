#include "ros/ros.h"
#include "std_msgs/String.h"
#include <trikControl/brickFactory.h>
#include <QtWidgets/QApplication>

void demoCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("TEST");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "trikset");
  QApplication app(argc, argv);
  printf("%p\n", app.thread());
  trikControl::BrickFactory::create(*app.thread()
				    , "./system-config.xml", "./model-config.xml", "./");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("demo", 1000, demoCallback);
  ros::spin();

  return 0;
}
