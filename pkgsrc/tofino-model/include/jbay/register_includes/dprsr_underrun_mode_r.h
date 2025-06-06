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
#ifndef __REGISTER_INCLUDES_DPRSR_UNDERRUN_MODE_R_H__
#define __REGISTER_INCLUDES_DPRSR_UNDERRUN_MODE_R_H__


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

class DprsrUnderrunModeR : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum DprsrRegRspecEnum {
    kHoE,
    kHoI
  };
public:
  DprsrUnderrunModeR(
      int chipNumber, int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec, int index_dprsr_ho_e, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_dprsr_reg_rspec, index_dprsr_ho_e), 4, false, write_callback, read_callback, std::string("DprsrUnderrunModeR")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_dprsr_reg_rspec) + "," + boost::lexical_cast<std::string>(index_dprsr_ho_e))
    {
    }
  DprsrUnderrunModeR(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "DprsrUnderrunModeR")
    {
    }
public:




  uint8_t &mac0() { return mac0_; }





  uint8_t &mac1() { return mac1_; }





  uint8_t &mac2() { return mac2_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (mac0_ & 0x3);
    *data |= (mac1_ << 8);
    *data |= (mac2_ << 16);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    mac0_ = (data & 0x3);
    mac1_ = (data >> 8);
    mac2_ = (data >> 16);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    mac0_ = 0x0;
    mac1_ = 0x0;
    mac2_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DprsrUnderrunModeR") + ":\n";
    r += indent_string + "  " + std::string("mac0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac0_) ) + "\n";
    all_zeros &= (0 == mac0_);
    r += indent_string + "  " + std::string("mac1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac1_) ) + "\n";
    all_zeros &= (0 == mac1_);
    r += indent_string + "  " + std::string("mac2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac2_) ) + "\n";
    all_zeros &= (0 == mac2_);
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
    r += indent_string + std::string("DprsrUnderrunModeR") + ":\n";
    r += indent_string + "  " + std::string("mac0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac0_) ) + "\n";
    all_zeros &= (0 == mac0_);
    r += indent_string + "  " + std::string("mac1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac1_) ) + "\n";
    all_zeros &= (0 == mac1_);
    r += indent_string + "  " + std::string("mac2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac2_) ) + "\n";
    all_zeros &= (0 == mac2_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t mac0_;
  uint8_t mac1_;
  uint8_t mac2_;
private:
  static int StartOffset(
      int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec, int index_dprsr_ho_e
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    switch (selector_dprsr_reg_rspec) {
      case kHoE:
        offset += 0x38000; // to get to ho_e
        assert(index_dprsr_ho_e < 4);
        offset += index_dprsr_ho_e * 0x2000; // dprsr_ho_e[]
        offset += 0x1000; // to get to out_egr
        offset += 0x444; // to get to u_mode
        break;
      case kHoI:
        offset += 0x30000; // to get to ho_i
        assert(index_dprsr_ho_e < 4);
        offset += index_dprsr_ho_e * 0x2000; // dprsr_ho_i[]
        offset += 0x1000; // to get to out_ingr
        offset += 0x330; // to get to u_mode
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

#endif // __REGISTER_INCLUDES_DPRSR_UNDERRUN_MODE_R_H__
