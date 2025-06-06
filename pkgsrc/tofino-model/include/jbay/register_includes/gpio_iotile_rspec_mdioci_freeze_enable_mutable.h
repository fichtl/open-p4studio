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
#ifndef __REGISTER_INCLUDES_GPIO_IOTILE_RSPEC_MDIOCI_FREEZE_ENABLE_MUTABLE_H__
#define __REGISTER_INCLUDES_GPIO_IOTILE_RSPEC_MDIOCI_FREEZE_ENABLE_MUTABLE_H__


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

class GpioIotileRspecMdiociFreezeEnableMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum JbayRegEnum {
    kGpioIotileBl,
    kGpioIotileBr,
    kGpioIotileTl,
    kGpioIotileTr
  };
public:
  GpioIotileRspecMdiociFreezeEnableMutable(
      int chipNumber, JbayRegEnum selector_jbay_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_jbay_reg), 4, true, write_callback, read_callback, std::string("GpioIotileRspecMdiociFreezeEnableMutable")+":"+boost::lexical_cast<std::string>(selector_jbay_reg))
    {
    }
  GpioIotileRspecMdiociFreezeEnableMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "GpioIotileRspecMdiociFreezeEnableMutable")
    {
    }
public:
  uint8_t int0() { return int0_; }
  void int0(const uint8_t &v) { int0_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (int0_ & 0x1);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    int0_ = (data & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    int0_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("GpioIotileRspecMdiociFreezeEnableMutable") + ":\n";
    r += indent_string + "  " + std::string("int0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(int0_) ) + "\n";
    all_zeros &= (0 == int0_);
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
    r += indent_string + std::string("GpioIotileRspecMdiociFreezeEnableMutable") + ":\n";
    r += indent_string + "  " + std::string("int0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(int0_) ) + "\n";
    all_zeros &= (0 == int0_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t int0_;
private:
  static int StartOffset(
      JbayRegEnum selector_jbay_reg
      ) {
    int offset=0;
    switch (selector_jbay_reg) {
      case kGpioIotileBl:
        offset += 0x28c0000; // to get to gpio_iotile_bl
        offset += 0x24; // to get to mdioci_freeze_enable
        break;
      case kGpioIotileBr:
        offset += 0x2900000; // to get to gpio_iotile_br
        offset += 0x24; // to get to mdioci_freeze_enable
        break;
      case kGpioIotileTl:
        offset += 0x2980000; // to get to gpio_iotile_tl
        offset += 0x24; // to get to mdioci_freeze_enable
        break;
      case kGpioIotileTr:
        offset += 0x2940000; // to get to gpio_iotile_tr
        offset += 0x24; // to get to mdioci_freeze_enable
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

#endif // __REGISTER_INCLUDES_GPIO_IOTILE_RSPEC_MDIOCI_FREEZE_ENABLE_MUTABLE_H__
