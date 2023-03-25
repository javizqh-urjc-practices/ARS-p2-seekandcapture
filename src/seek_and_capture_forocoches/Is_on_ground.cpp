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

#include "seek_and_capture_forocoches/Is_on_ground.hpp"

#include "behaviortree_cpp_v3/behavior_tree.h"

#include "sensor_msgs/msg/laser_scan.hpp"
#include "rclcpp/rclcpp.hpp"
namespace seek_and_capture_forocoches
{
using namespace std::chrono_literals;  // NOLINT
using namespace std::placeholders;

Is_on_ground::Is_on_ground(
  const std::string & xml_tag_name,
  const BT::NodeConfiguration & conf)
: BT::ConditionNode(xml_tag_name, conf)
{
  config().blackboard->get("node", node_);

  wheel_drop_sub_ = node_->create_subscription<kobuki_ros_interfaces::msg::WheelDropEvent>(
    "/scan", 100, std::bind(&Is_on_ground::wheel_drop_callback, this, _1));

  last_reading_time_ = node_->now();
}

void
Is_on_ground::wheel_drop_callback(kobuki_ros_interfaces::msg::WheelDropEvent::UniquePtr msg)
{
  last_wheel_dropped_ = std::move(msg);
}

BT::NodeStatus
Is_on_ground::tick()
{
  return BT::NodeStatus::SUCCESS;
  if (last_wheel_dropped_ == nullptr) {
    return BT::NodeStatus::FAILURE;
  }

  if (last_wheel_dropped_->state ==
    kobuki_ros_interfaces::msg::WheelDropEvent::DROPPED)
  {
    return BT::NodeStatus::FAILURE;
  } else {
    return BT::NodeStatus::SUCCESS;
  }
}
}  // namespace seek_and_capture_forocoches
#include "behaviortree_cpp_v3/bt_factory.h"
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<seek_and_capture_forocoches::Is_on_ground>("Is_on_ground");
}
