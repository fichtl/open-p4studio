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
#ifndef __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_PPM_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_PPM_CTRL_MUTABLE_H__


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

class Eth100gRegRspecEthPpmCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum JbayRegEnum {
    kEth100gRegs,
    kEth100gRegsRot
  };
public:
  Eth100gRegRspecEthPpmCtrlMutable(
      int chipNumber, JbayRegEnum selector_jbay_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_jbay_reg), 4, true, write_callback, read_callback, std::string("Eth100gRegRspecEthPpmCtrlMutable")+":"+boost::lexical_cast<std::string>(selector_jbay_reg))
    {
    }
  Eth100gRegRspecEthPpmCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "Eth100gRegRspecEthPpmCtrlMutable")
    {
    }
public:






  uint32_t max_count() { return max_count_; }
  void max_count(const uint32_t &v) { max_count_=v; }







  uint8_t ppm_ena() { return ppm_ena_; }
  void ppm_ena(const uint8_t &v) { ppm_ena_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (max_count_ & 0x7fffffff);
    *data |= ((ppm_ena_ & 0x1) << 31);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    max_count_ = (data & 0x7fffffff);
    ppm_ena_ = ((data >> 31) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    max_count_ = 0x0;
    ppm_ena_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("Eth100gRegRspecEthPpmCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("max_count") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(max_count_) ) + "\n";
    all_zeros &= (0 == max_count_);
    r += indent_string + "  " + std::string("ppm_ena") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ppm_ena_) ) + "\n";
    all_zeros &= (0 == ppm_ena_);
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
    r += indent_string + std::string("Eth100gRegRspecEthPpmCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("max_count") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(max_count_) ) + "\n";
    all_zeros &= (0 == max_count_);
    r += indent_string + "  " + std::string("ppm_ena") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ppm_ena_) ) + "\n";
    all_zeros &= (0 == ppm_ena_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t max_count_;
  uint8_t ppm_ena_;
private:
  static int StartOffset(
      JbayRegEnum selector_jbay_reg
      ) {
    int offset=0;
    switch (selector_jbay_reg) {
      case kEth100gRegs:
        offset += 0x2000000; // to get to eth100g_regs
        offset += 0x1fc00; // to get to eth100g_reg
        offset += 0x1c8; // to get to eth_ppm_ctrl
        break;
      case kEth100gRegsRot:
        offset += 0x29c0000; // to get to eth100g_regs_rot
        offset += 0x1fc00; // to get to eth100g_reg
        offset += 0x1c8; // to get to eth_ppm_ctrl
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

#endif // __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_PPM_CTRL_MUTABLE_H__
