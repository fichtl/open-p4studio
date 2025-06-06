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
#ifndef __REGISTER_INCLUDES_PARITY_CONTROL_R_MUTABLE_H__
#define __REGISTER_INCLUDES_PARITY_CONTROL_R_MUTABLE_H__


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

class ParityControlRMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum PardeGlueStnRegEnum {
    kEpbprsr4reg,
    kIpbprsr4reg
  };
public:
  ParityControlRMutable(
      int chipNumber, int index_pipe_addrmap, PardeGlueStnRegEnum selector_parde_glue_stn_reg, int index_epb_prsr4_reg, int index_prsr_reg_main_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_parde_glue_stn_reg, index_epb_prsr4_reg, index_prsr_reg_main_rspec), 4, true, write_callback, read_callback, std::string("ParityControlRMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_parde_glue_stn_reg) + "," + boost::lexical_cast<std::string>(index_epb_prsr4_reg) + "," + boost::lexical_cast<std::string>(index_prsr_reg_main_rspec))
    {
    }
  ParityControlRMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "ParityControlRMutable")
    {
    }
public:




  uint8_t tcam_disable_check() { return tcam_disable_check_; }
  void tcam_disable_check(const uint8_t &v) { tcam_disable_check_=v; }




  uint8_t tcam_inject_sbe() { return tcam_inject_sbe_; }
  void tcam_inject_sbe(const uint8_t &v) { tcam_inject_sbe_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (tcam_disable_check_ & 0x1);
    *data |= ((tcam_inject_sbe_ & 0x1) << 1);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    tcam_disable_check_ = (data & 0x1);
    tcam_inject_sbe_ = ((data >> 1) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    tcam_disable_check_ = 0x0;
    tcam_inject_sbe_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("ParityControlRMutable") + ":\n";
    r += indent_string + "  " + std::string("tcam_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_disable_check_) ) + "\n";
    all_zeros &= (0 == tcam_disable_check_);
    r += indent_string + "  " + std::string("tcam_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_inject_sbe_) ) + "\n";
    all_zeros &= (0 == tcam_inject_sbe_);
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
    r += indent_string + std::string("ParityControlRMutable") + ":\n";
    r += indent_string + "  " + std::string("tcam_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_disable_check_) ) + "\n";
    all_zeros &= (0 == tcam_disable_check_);
    r += indent_string + "  " + std::string("tcam_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_inject_sbe_) ) + "\n";
    all_zeros &= (0 == tcam_inject_sbe_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t tcam_disable_check_;
  uint8_t tcam_inject_sbe_;
private:
  static int StartOffset(
      int index_pipe_addrmap, PardeGlueStnRegEnum selector_parde_glue_stn_reg, int index_epb_prsr4_reg, int index_prsr_reg_main_rspec
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    switch (selector_parde_glue_stn_reg) {
      case kEpbprsr4reg:
        offset += 0x20000; // to get to epbprsr4reg
        assert(index_epb_prsr4_reg < 9);
        offset += index_epb_prsr4_reg * 0x2000; // epb_prsr4_reg[]
        offset += 0x1000; // to get to prsr
        assert(index_prsr_reg_main_rspec < 4);
        offset += index_prsr_reg_main_rspec * 0x400; // prsr_reg_main_rspec[]
        offset += 0x1e0; // to get to parity
        break;
      case kIpbprsr4reg:
        assert(index_epb_prsr4_reg < 9);
        offset += index_epb_prsr4_reg * 0x2000; // ipb_prsr4_reg[]
        offset += 0x1000; // to get to prsr
        assert(index_prsr_reg_main_rspec < 4);
        offset += index_prsr_reg_main_rspec * 0x400; // prsr_reg_main_rspec[]
        offset += 0x1e0; // to get to parity
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

#endif // __REGISTER_INCLUDES_PARITY_CONTROL_R_MUTABLE_H__
