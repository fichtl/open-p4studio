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
#ifndef __REGISTER_INCLUDES_GPIO_PAIR_REGS_I2C_CTRL_H__
#define __REGISTER_INCLUDES_GPIO_PAIR_REGS_I2C_CTRL_H__


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

class GpioPairRegsI2cCtrl : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum JbayRegEnum {
    kEthgpiobr,
    kEthgpiotl
  };
public:
  GpioPairRegsI2cCtrl(
      int chipNumber, JbayRegEnum selector_jbay_reg, int index_gpio_pair_regs, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_jbay_reg, index_gpio_pair_regs), 4, false, write_callback, read_callback, std::string("GpioPairRegsI2cCtrl")+":"+boost::lexical_cast<std::string>(selector_jbay_reg) + "," + boost::lexical_cast<std::string>(index_gpio_pair_regs))
    {
    }
  GpioPairRegsI2cCtrl(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "GpioPairRegsI2cCtrl")
    {
    }
public:










  uint8_t &i2c_type() { return i2c_type_; }










  uint8_t &i2c_cmd() { return i2c_cmd_; }





  uint8_t &i2c_addrnum() { return i2c_addrnum_; }





  uint8_t &i2c_devaddr() { return i2c_devaddr_; }





  uint8_t &i2c_exec() { return i2c_exec_; }








  uint8_t &i2c_datanum() { return i2c_datanum_; }





  uint8_t &i2c_stateaddr() { return i2c_stateaddr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (i2c_type_ & 0x3);
    *data |= ((i2c_cmd_ & 0x3) << 2);
    *data |= ((i2c_addrnum_ & 0x7) << 4);
    *data |= ((i2c_devaddr_ & 0x7f) << 8);
    *data |= ((i2c_exec_ & 0x1) << 15);
    *data |= (i2c_datanum_ << 16);
    *data |= (i2c_stateaddr_ << 24);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    i2c_type_ = (data & 0x3);
    i2c_cmd_ = ((data >> 2) & 0x3);
    i2c_addrnum_ = ((data >> 4) & 0x7);
    i2c_devaddr_ = ((data >> 8) & 0x7f);
    i2c_exec_ = ((data >> 15) & 0x1);
    i2c_datanum_ = (data >> 16);
    i2c_stateaddr_ = (data >> 24);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    i2c_type_ = 0x0;
    i2c_cmd_ = 0x0;
    i2c_addrnum_ = 0x0;
    i2c_devaddr_ = 0x0;
    i2c_exec_ = 0x0;
    i2c_datanum_ = 0x0;
    i2c_stateaddr_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("GpioPairRegsI2cCtrl") + ":\n";
    r += indent_string + "  " + std::string("i2c_type") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_type_) ) + "\n";
    all_zeros &= (0 == i2c_type_);
    r += indent_string + "  " + std::string("i2c_cmd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_cmd_) ) + "\n";
    all_zeros &= (0 == i2c_cmd_);
    r += indent_string + "  " + std::string("i2c_addrnum") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_addrnum_) ) + "\n";
    all_zeros &= (0 == i2c_addrnum_);
    r += indent_string + "  " + std::string("i2c_devaddr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_devaddr_) ) + "\n";
    all_zeros &= (0 == i2c_devaddr_);
    r += indent_string + "  " + std::string("i2c_exec") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_exec_) ) + "\n";
    all_zeros &= (0 == i2c_exec_);
    r += indent_string + "  " + std::string("i2c_datanum") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_datanum_) ) + "\n";
    all_zeros &= (0 == i2c_datanum_);
    r += indent_string + "  " + std::string("i2c_stateaddr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_stateaddr_) ) + "\n";
    all_zeros &= (0 == i2c_stateaddr_);
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
    r += indent_string + std::string("GpioPairRegsI2cCtrl") + ":\n";
    r += indent_string + "  " + std::string("i2c_type") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_type_) ) + "\n";
    all_zeros &= (0 == i2c_type_);
    r += indent_string + "  " + std::string("i2c_cmd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_cmd_) ) + "\n";
    all_zeros &= (0 == i2c_cmd_);
    r += indent_string + "  " + std::string("i2c_addrnum") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_addrnum_) ) + "\n";
    all_zeros &= (0 == i2c_addrnum_);
    r += indent_string + "  " + std::string("i2c_devaddr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_devaddr_) ) + "\n";
    all_zeros &= (0 == i2c_devaddr_);
    r += indent_string + "  " + std::string("i2c_exec") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_exec_) ) + "\n";
    all_zeros &= (0 == i2c_exec_);
    r += indent_string + "  " + std::string("i2c_datanum") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_datanum_) ) + "\n";
    all_zeros &= (0 == i2c_datanum_);
    r += indent_string + "  " + std::string("i2c_stateaddr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_stateaddr_) ) + "\n";
    all_zeros &= (0 == i2c_stateaddr_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t i2c_type_;
  uint8_t i2c_cmd_;
  uint8_t i2c_addrnum_;
  uint8_t i2c_devaddr_;
  uint8_t i2c_exec_;
  uint8_t i2c_datanum_;
  uint8_t i2c_stateaddr_;
private:
  static int StartOffset(
      JbayRegEnum selector_jbay_reg, int index_gpio_pair_regs
      ) {
    int offset=0;
    switch (selector_jbay_reg) {
      case kEthgpiobr:
        offset += 0x2880000; // to get to ethgpiobr
        assert(index_gpio_pair_regs < 6);
        offset += index_gpio_pair_regs * 0x30; // gpio_pair_regs[]
        offset += 0x10; // to get to i2c_ctrl
        break;
      case kEthgpiotl:
        offset += 0x2840000; // to get to ethgpiotl
        assert(index_gpio_pair_regs < 6);
        offset += index_gpio_pair_regs * 0x30; // gpio_pair_regs[]
        offset += 0x10; // to get to i2c_ctrl
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

#endif // __REGISTER_INCLUDES_GPIO_PAIR_REGS_I2C_CTRL_H__
