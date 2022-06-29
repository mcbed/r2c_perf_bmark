// Copyright 2022, ICube Laboratory, University of Strasbourg
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

#ifndef BMARK_CONTROLLERS__BMARK_CONTROLLERS_HPP_
#define BMARK_CONTROLLERS__BMARK_CONTROLLERS_HPP_

#include <memory>
#include <string>
#include <vector>

#include "controller_interface/controller_interface.hpp"
#include "bmark_controllers/visibility_control.h"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "realtime_tools/realtime_publisher.h"
#include "bmark_msgs/msg/duration.hpp"

namespace bmark_controllers
{
using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;
using BMsgType = bmark_msgs::msg::Duration;

class DurationBroadcaster : public controller_interface::ControllerInterface
{
public:
  BMARK_CONTROLLERS_PUBLIC
  DurationBroadcaster();

  BMARK_CONTROLLERS_PUBLIC
  CallbackReturn on_init() override;

  BMARK_CONTROLLERS_PUBLIC
  controller_interface::InterfaceConfiguration command_interface_configuration() const override;

  BMARK_CONTROLLERS_PUBLIC
  controller_interface::InterfaceConfiguration state_interface_configuration() const override;

  BMARK_CONTROLLERS_PUBLIC
  CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state) override;

  BMARK_CONTROLLERS_PUBLIC
  CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override;

  BMARK_CONTROLLERS_PUBLIC
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

  BMARK_CONTROLLERS_PUBLIC
  controller_interface::return_type update(const rclcpp::Time & time, const rclcpp::Duration & period) override;

protected:
  rclcpp::Publisher<BMsgType>::SharedPtr duration_publisher_;
  std::unique_ptr<realtime_tools::RealtimePublisher<BMsgType>> realtime_publisher_;
};

}  // namespace bmark_controllers

#endif  // BMARK_CONTROLLERS__BMARK_CONTROLLERS_HPP_
