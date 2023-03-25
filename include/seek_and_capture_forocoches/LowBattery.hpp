// Copyright 2021 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SEEK_AND_CAPTURE_FOROCOCHES__LOWBATTERY_HPP_
#define SEEK_AND_CAPTURE_FOROCOCHES__LOWBATTERY_HPP_

#include <string>

#include "behaviortree_cpp_v3/behavior_tree.h"
#include "behaviortree_cpp_v3/bt_factory.h"

#include "sensor_msgs/msg/battery_state.hpp"
#include "rclcpp/rclcpp.hpp"


namespace seek_and_capture_forocoches
{

class LowBattery : public BT::ConditionNode
{
public:
  explicit LowBattery(
    const std::string & xml_tag_name,
    const BT::NodeConfiguration & conf);

  BT::NodeStatus tick();

  static BT::PortsList providedPorts()
  {
    return BT::PortsList(
      {
        BT::InputPort<double>("battery_threshold")
      });
  }

  void battery_callback(sensor_msgs::msg::BatteryState::UniquePtr msg);

private:
  rclcpp::Node::SharedPtr node_;
  rclcpp::Time last_reading_time_;
  rclcpp::Subscription<sensor_msgs::msg::BatteryState>::SharedPtr battery_sub_;
  sensor_msgs::msg::BatteryState::UniquePtr last_battery_state_;
};
}  // namespace seek_and_capture_forocoches
#endif  // SEEK_AND_CAPTURE_FOROCOCHES__LOWBATTERY_HPP_