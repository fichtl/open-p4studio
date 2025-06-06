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
#ifndef __REGISTER_INCLUDES_MISC_REGS_PCIE_PHY_OVR_MPLLB_CTRL2_MUTABLE_H__
#define __REGISTER_INCLUDES_MISC_REGS_PCIE_PHY_OVR_MPLLB_CTRL2_MUTABLE_H__


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

class MiscRegsPciePhyOvrMpllbCtrl2Mutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MiscRegsPciePhyOvrMpllbCtrl2Mutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, true, write_callback, read_callback, std::string("MiscRegsPciePhyOvrMpllbCtrl2Mutable"))
    {
    }
  MiscRegsPciePhyOvrMpllbCtrl2Mutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MiscRegsPciePhyOvrMpllbCtrl2Mutable")
    {
    }
public:








  uint32_t mpllb_ctrl2() { return mpllb_ctrl2_; }
  void mpllb_ctrl2(const uint32_t &v) { mpllb_ctrl2_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = mpllb_ctrl2_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    mpllb_ctrl2_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    mpllb_ctrl2_ = 0x28000;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MiscRegsPciePhyOvrMpllbCtrl2Mutable") + ":\n";
    r += indent_string + "  " + std::string("mpllb_ctrl2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mpllb_ctrl2_) ) + "\n";
    all_zeros &= (0 == mpllb_ctrl2_);
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
    r += indent_string + std::string("MiscRegsPciePhyOvrMpllbCtrl2Mutable") + ":\n";
    r += indent_string + "  " + std::string("mpllb_ctrl2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mpllb_ctrl2_) ) + "\n";
    all_zeros &= (0 == mpllb_ctrl2_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t mpllb_ctrl2_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x80000; // to get to misc_regs
    offset += 0x80; // to get to pcie_phy_ovr_mpllb_ctrl2
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MISC_REGS_PCIE_PHY_OVR_MPLLB_CTRL2_MUTABLE_H__
