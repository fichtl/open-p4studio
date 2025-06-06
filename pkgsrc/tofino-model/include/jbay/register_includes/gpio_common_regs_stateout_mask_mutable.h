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
#ifndef __REGISTER_INCLUDES_GPIO_COMMON_REGS_STATEOUT_MASK_MUTABLE_H__
#define __REGISTER_INCLUDES_GPIO_COMMON_REGS_STATEOUT_MASK_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbay {
  namespace register_classes {

class GpioCommonRegsStateoutMaskMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum JbayRegEnum {
    kEthgpiobr,
    kEthgpiotl
  };
public:
  GpioCommonRegsStateoutMaskMutable(
      int chipNumber, JbayRegEnum selector_jbay_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_jbay_reg), 4, true, write_callback, read_callback, std::string("GpioCommonRegsStateoutMaskMutable")+":"+boost::lexical_cast<std::string>(selector_jbay_reg))
    {
    }
  GpioCommonRegsStateoutMaskMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "GpioCommonRegsStateoutMaskMutable")
    {
    }
public:






  uint32_t stateout_mask() { return stateout_mask_; }
  void stateout_mask(const uint32_t &v) { stateout_mask_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = stateout_mask_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    stateout_mask_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    stateout_mask_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("GpioCommonRegsStateoutMaskMutable") + ":\n";
    r += indent_string + "  " + std::string("stateout_mask") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stateout_mask_) ) + "\n";
    all_zeros &= (0 == stateout_mask_);
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
    r += indent_string + std::string("GpioCommonRegsStateoutMaskMutable") + ":\n";
    r += indent_string + "  " + std::string("stateout_mask") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stateout_mask_) ) + "\n";
    all_zeros &= (0 == stateout_mask_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t stateout_mask_;
private:
  static int StartOffset(
      JbayRegEnum selector_jbay_reg
      ) {
    int offset=0;
    switch (selector_jbay_reg) {
      case kEthgpiobr:
        offset += 0x2880000; // to get to ethgpiobr
        offset += 0x200; // to get to gpio_common_regs
        offset += 0x17c; // to get to stateout_mask
        break;
      case kEthgpiotl:
        offset += 0x2840000; // to get to ethgpiotl
        offset += 0x200; // to get to gpio_common_regs
        offset += 0x17c; // to get to stateout_mask
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_GPIO_COMMON_REGS_STATEOUT_MASK_MUTABLE_H__
