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

#ifndef SEEK_AND_CAPTURE_FOROCOCHES__IS_ON_GROUND_HPP_
#define SEEK_AND_CAPTURE_FOROCOCHES__IS_ON_GROUND_HPP_

#include <string>

#include "behaviortree_cpp_v3/behavior_tree.h"
#include "behaviortree_cpp_v3/bt_factory.h"

#include "kobuki_ros_interfaces/msg/wheel_drop_event.hpp"
#include "rclcpp/rclcpp.hpp"

#include "seek_and_capture_forocoches/DebugNode.hpp"

namespace seek_and_capture_forocoches
{
class Is_on_ground : public BT::ConditionNode
{
public:
  explicit Is_on_ground(
    const std::string & xml_tag_name,
    const BT::NodeConfiguration & conf);

  BT::NodeStatus tick();
  static BT::PortsList providedPorts()
  {
    return BT::PortsList({});
  }
  void wheel_drop_callback(kobuki_ros_interfaces::msg::WheelDropEvent::UniquePtr msg);

private:
  rclcpp::Node::SharedPtr node_;
  rclcpp::Time last_reading_time_;
  DebugNode::DebugPublisher debug_pub_;
  DebugNode::DebugMessage debug_msg_;
  rclcpp::Subscription<kobuki_ros_interfaces::msg::WheelDropEvent>::SharedPtr wheel_drop_sub_;
  kobuki_ros_interfaces::msg::WheelDropEvent::UniquePtr last_wheel_dropped_;
};
}  // namespace seek_and_capture_forocoches
#endif  // SEEK_AND_CAPTURE_FOROCOCHES__IS_ON_GROUND_HPP_
