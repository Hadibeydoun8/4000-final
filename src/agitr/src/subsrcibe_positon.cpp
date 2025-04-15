/*
 * subposecpp.cpp
 *
 *  Created on: April 9, 2024
 *      Author: utayba
 * This program subscribes to turtle1/pose and shows its
 * messages on the screen.
 */
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <stdlib.h>
#include <chrono>
#include <functional>
#include <memory>
#include <string>

using std::placeholders::_1;

 
class subPose : public rclcpp::Node {
public:
	subPose():Node("subscribe_pose"){
	subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "my_topic", 10, std::bind(&subPose::topic_callback, this, _1));
	}

private:
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscriber_;

  void topic_callback(const geometry_msgs::msg::Twist & msg) {

    RCLCPP_INFO(this->get_logger(), "Voltage=%.2f, ATD=%.2f", msg.linear.x, msg.linear.y);

  }


};



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node=std::make_shared<subPose>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

