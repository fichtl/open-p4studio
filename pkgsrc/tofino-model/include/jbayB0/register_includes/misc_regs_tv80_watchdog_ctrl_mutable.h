/*******************************************************************************
 *  Copyright (C) 2024 Intel Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions
 *  and limitations under the License.
 *
 *
 *  SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

// generated by split_classes.pl
#ifndef __REGISTER_INCLUDES_MISC_REGS_TV80_WATCHDOG_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_MISC_REGS_TV80_WATCHDOG_CTRL_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbayB0 {
  namespace register_classes {

class MiscRegsTv80WatchdogCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MiscRegsTv80WatchdogCtrlMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, true, write_callback, read_callback, std::string("MiscRegsTv80WatchdogCtrlMutable"))
    {
    }
  MiscRegsTv80WatchdogCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MiscRegsTv80WatchdogCtrlMutable")
    {
    }
public:





  uint32_t timeout_value() { return timeout_value_; }
  void timeout_value(const uint32_t &v) { timeout_value_=v; }





  uint8_t enable() { return enable_; }
  void enable(const uint8_t &v) { enable_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (timeout_value_ & 0x7fffffff);
    *data |= ((enable_ & 0x1) << 31);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    timeout_value_ = (data & 0x7fffffff);
    enable_ = ((data >> 31) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    timeout_value_ = 0x0;
    enable_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MiscRegsTv80WatchdogCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("timeout_value") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(timeout_value_) ) + "\n";
    all_zeros &= (0 == timeout_value_);
    r += indent_string + "  " + std::string("enable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(enable_) ) + "\n";
    all_zeros &= (0 == enable_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

  std::string to_string(
      bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MiscRegsTv80WatchdogCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("timeout_value") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(timeout_value_) ) + "\n";
    all_zeros &= (0 == timeout_value_);
    r += indent_string + "  " + std::string("enable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(enable_) ) + "\n";
    all_zeros &= (0 == enable_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t timeout_value_;
  uint8_t enable_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x80000; // to get to misc_regs
    offset += 0x1e8; // to get to tv80_watchdog_ctrl
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MISC_REGS_TV80_WATCHDOG_CTRL_MUTABLE_H__
