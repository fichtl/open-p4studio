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
#ifndef __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_MDIOCI_ADDR_H__
#define __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_MDIOCI_ADDR_H__


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

class Eth100gRegRspecEthMdiociAddr : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum JbayRegEnum {
    kEth100gRegs,
    kEth100gRegsRot
  };
public:
  Eth100gRegRspecEthMdiociAddr(
      int chipNumber, JbayRegEnum selector_jbay_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_jbay_reg), 4, false, write_callback, read_callback, std::string("Eth100gRegRspecEthMdiociAddr")+":"+boost::lexical_cast<std::string>(selector_jbay_reg))
    {
    }
  Eth100gRegRspecEthMdiociAddr(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "Eth100gRegRspecEthMdiociAddr")
    {
    }
public:








  uint8_t &cpu_addrreg() { return cpu_addrreg_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = cpu_addrreg_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    cpu_addrreg_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    cpu_addrreg_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("Eth100gRegRspecEthMdiociAddr") + ":\n";
    r += indent_string + "  " + std::string("cpu_addrreg") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cpu_addrreg_) ) + "\n";
    all_zeros &= (0 == cpu_addrreg_);
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
    r += indent_string + std::string("Eth100gRegRspecEthMdiociAddr") + ":\n";
    r += indent_string + "  " + std::string("cpu_addrreg") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cpu_addrreg_) ) + "\n";
    all_zeros &= (0 == cpu_addrreg_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t cpu_addrreg_;
private:
  static int StartOffset(
      JbayRegEnum selector_jbay_reg
      ) {
    int offset=0;
    switch (selector_jbay_reg) {
      case kEth100gRegs:
        offset += 0x2000000; // to get to eth100g_regs
        offset += 0x1fc00; // to get to eth100g_reg
        offset += 0x1d0; // to get to eth_mdioci_addr
        break;
      case kEth100gRegsRot:
        offset += 0x29c0000; // to get to eth100g_regs_rot
        offset += 0x1fc00; // to get to eth100g_reg
        offset += 0x1d0; // to get to eth_mdioci_addr
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_MDIOCI_ADDR_H__
