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
#ifndef __REGISTER_INCLUDES_GPIO_PAIR_REGS_I2C_RDATA_MUTABLE_H__
#define __REGISTER_INCLUDES_GPIO_PAIR_REGS_I2C_RDATA_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofino {
  namespace register_classes {

class GpioPairRegsI2cRdataMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum TofinoEnum {
    kEthgpiobr,
    kEthgpiotl
  };
public:
  GpioPairRegsI2cRdataMutable(
      int chipNumber, TofinoEnum selector_tofino, int index_gpio_pair_regs, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_tofino, index_gpio_pair_regs), 4, true, write_callback, read_callback, std::string("GpioPairRegsI2cRdataMutable")+":"+boost::lexical_cast<std::string>(selector_tofino) + "," + boost::lexical_cast<std::string>(index_gpio_pair_regs))
    {
    }
  GpioPairRegsI2cRdataMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "GpioPairRegsI2cRdataMutable")
    {
    }
public:






  uint32_t i2c_rdata() { return i2c_rdata_; }
  void i2c_rdata(const uint32_t &v) { i2c_rdata_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = i2c_rdata_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    i2c_rdata_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    i2c_rdata_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("GpioPairRegsI2cRdataMutable") + ":\n";
    r += indent_string + "  " + std::string("i2c_rdata") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_rdata_) ) + "\n";
    all_zeros &= (0 == i2c_rdata_);
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
    r += indent_string + std::string("GpioPairRegsI2cRdataMutable") + ":\n";
    r += indent_string + "  " + std::string("i2c_rdata") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i2c_rdata_) ) + "\n";
    all_zeros &= (0 == i2c_rdata_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t i2c_rdata_;
private:
  static int StartOffset(
      TofinoEnum selector_tofino, int index_gpio_pair_regs
      ) {
    int offset=0;
    switch (selector_tofino) {
      case kEthgpiobr:
        offset += 0x1820000; // to get to ethgpiobr
        assert(index_gpio_pair_regs < 6);
        offset += index_gpio_pair_regs * 0x2c; // gpio_pair_regs[]
        offset += 0x1c; // to get to i2c_rdata
        break;
      case kEthgpiotl:
        offset += 0x1840000; // to get to ethgpiotl
        assert(index_gpio_pair_regs < 6);
        offset += index_gpio_pair_regs * 0x2c; // gpio_pair_regs[]
        offset += 0x1c; // to get to i2c_rdata
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_GPIO_PAIR_REGS_I2C_RDATA_MUTABLE_H__
