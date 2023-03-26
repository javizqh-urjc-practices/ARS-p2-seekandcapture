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

#include <string>
#include <utility>

#include "seek_and_capture_forocoches/LowBattery.hpp"

#include "behaviortree_cpp_v3/behavior_tree.h"

#include "sensor_msgs/msg/battery_state.hpp"
#include "rclcpp/rclcpp.hpp"

namespace seek_and_capture_forocoches
{

using namespace std::chrono_literals;  // NOLINT
using namespace std::placeholders;

LowBattery::LowBattery(
  const std::string & xml_tag_name,
  const BT::NodeConfiguration & conf)
: BT::ConditionNode(xml_tag_name, conf)
{
  config().blackboard->get("node", node_);

  debug_pub_ = node_->create_publisher<DebugNode::DebugMessage>(DebugNode::TOPIC_NAME, 10);

  battery_sub_ = node_->create_subscription<sensor_msgs::msg::BatteryState>(
    "input_battery_state", 100, std::bind(&LowBattery::battery_callback, this, _1));

  last_reading_time_ = node_->now();
}

void
LowBattery::battery_callback(sensor_msgs::msg::BatteryState::UniquePtr msg)
{
  last_battery_state_ = std::move(msg);
}

BT::NodeStatus
LowBattery::tick()
{
  return BT::NodeStatus::SUCCESS;
  if (last_battery_state_ == nullptr) {
    debug_msg_.data = DebugNode::ERROR;
    debug_pub_->publish(debug_msg_);
    return BT::NodeStatus::RUNNING;
  }

  double battery_threshold = 10.0;
  getInput("battery_threshold", battery_threshold);

  if (last_battery_state_->percentage > battery_threshold) {
    return BT::NodeStatus::SUCCESS;
  } else {
    debug_msg_.data = DebugNode::LOW_BATTERY;
    debug_pub_->publish(debug_msg_);
    return BT::NodeStatus::FAILURE;
  }
}
}  // namespace seek_and_capture_forocoches
#include "behaviortree_cpp_v3/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<seek_and_capture_forocoches::LowBattery>("LowBattery");
}
