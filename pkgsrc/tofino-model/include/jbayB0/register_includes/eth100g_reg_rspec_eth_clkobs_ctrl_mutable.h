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
#ifndef __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_CLKOBS_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_CLKOBS_CTRL_MUTABLE_H__


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

class Eth100gRegRspecEthClkobsCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum JbayRegEnum {
    kEth100gRegs,
    kEth100gRegsRot
  };
public:
  Eth100gRegRspecEthClkobsCtrlMutable(
      int chipNumber, JbayRegEnum selector_jbay_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_jbay_reg), 4, true, write_callback, read_callback, std::string("Eth100gRegRspecEthClkobsCtrlMutable")+":"+boost::lexical_cast<std::string>(selector_jbay_reg))
    {
    }
  Eth100gRegRspecEthClkobsCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "Eth100gRegRspecEthClkobsCtrlMutable")
    {
    }
public:





  uint8_t ena_clkobs0() { return ena_clkobs0_; }
  void ena_clkobs0(const uint8_t &v) { ena_clkobs0_=v; }









  uint8_t div_clkobs0() { return div_clkobs0_; }
  void div_clkobs0(const uint8_t &v) { div_clkobs0_=v; }



















  uint8_t sel_clkobs0() { return sel_clkobs0_; }
  void sel_clkobs0(const uint8_t &v) { sel_clkobs0_=v; }





  uint8_t ena_clkobs1() { return ena_clkobs1_; }
  void ena_clkobs1(const uint8_t &v) { ena_clkobs1_=v; }









  uint8_t div_clkobs1() { return div_clkobs1_; }
  void div_clkobs1(const uint8_t &v) { div_clkobs1_=v; }



















  uint8_t sel_clkobs1() { return sel_clkobs1_; }
  void sel_clkobs1(const uint8_t &v) { sel_clkobs1_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (ena_clkobs0_ & 0x1);
    *data |= ((div_clkobs0_ & 0x3) << 2);
    *data |= ((sel_clkobs0_ & 0xf) << 4);
    *data |= ((ena_clkobs1_ & 0x1) << 8);
    *data |= ((div_clkobs1_ & 0x3) << 10);
    *data |= ((sel_clkobs1_ & 0xf) << 12);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    ena_clkobs0_ = (data & 0x1);
    div_clkobs0_ = ((data >> 2) & 0x3);
    sel_clkobs0_ = ((data >> 4) & 0xf);
    ena_clkobs1_ = ((data >> 8) & 0x1);
    div_clkobs1_ = ((data >> 10) & 0x3);
    sel_clkobs1_ = ((data >> 12) & 0xf);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    ena_clkobs0_ = 0x0;
    div_clkobs0_ = 0x0;
    sel_clkobs0_ = 0x0;
    ena_clkobs1_ = 0x0;
    div_clkobs1_ = 0x0;
    sel_clkobs1_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("Eth100gRegRspecEthClkobsCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("ena_clkobs0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ena_clkobs0_) ) + "\n";
    all_zeros &= (0 == ena_clkobs0_);
    r += indent_string + "  " + std::string("div_clkobs0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(div_clkobs0_) ) + "\n";
    all_zeros &= (0 == div_clkobs0_);
    r += indent_string + "  " + std::string("sel_clkobs0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel_clkobs0_) ) + "\n";
    all_zeros &= (0 == sel_clkobs0_);
    r += indent_string + "  " + std::string("ena_clkobs1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ena_clkobs1_) ) + "\n";
    all_zeros &= (0 == ena_clkobs1_);
    r += indent_string + "  " + std::string("div_clkobs1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(div_clkobs1_) ) + "\n";
    all_zeros &= (0 == div_clkobs1_);
    r += indent_string + "  " + std::string("sel_clkobs1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel_clkobs1_) ) + "\n";
    all_zeros &= (0 == sel_clkobs1_);
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
    r += indent_string + std::string("Eth100gRegRspecEthClkobsCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("ena_clkobs0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ena_clkobs0_) ) + "\n";
    all_zeros &= (0 == ena_clkobs0_);
    r += indent_string + "  " + std::string("div_clkobs0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(div_clkobs0_) ) + "\n";
    all_zeros &= (0 == div_clkobs0_);
    r += indent_string + "  " + std::string("sel_clkobs0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel_clkobs0_) ) + "\n";
    all_zeros &= (0 == sel_clkobs0_);
    r += indent_string + "  " + std::string("ena_clkobs1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ena_clkobs1_) ) + "\n";
    all_zeros &= (0 == ena_clkobs1_);
    r += indent_string + "  " + std::string("div_clkobs1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(div_clkobs1_) ) + "\n";
    all_zeros &= (0 == div_clkobs1_);
    r += indent_string + "  " + std::string("sel_clkobs1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel_clkobs1_) ) + "\n";
    all_zeros &= (0 == sel_clkobs1_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t ena_clkobs0_;
  uint8_t div_clkobs0_;
  uint8_t sel_clkobs0_;
  uint8_t ena_clkobs1_;
  uint8_t div_clkobs1_;
  uint8_t sel_clkobs1_;
private:
  static int StartOffset(
      JbayRegEnum selector_jbay_reg
      ) {
    int offset=0;
    switch (selector_jbay_reg) {
      case kEth100gRegs:
        offset += 0x2000000; // to get to eth100g_regs
        offset += 0x1fc00; // to get to eth100g_reg
        offset += 0x20; // to get to eth_clkobs_ctrl
        break;
      case kEth100gRegsRot:
        offset += 0x29c0000; // to get to eth100g_regs_rot
        offset += 0x1fc00; // to get to eth100g_reg
        offset += 0x20; // to get to eth_clkobs_ctrl
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

#endif // __REGISTER_INCLUDES_ETH100G_REG_RSPEC_ETH_CLKOBS_CTRL_MUTABLE_H__
