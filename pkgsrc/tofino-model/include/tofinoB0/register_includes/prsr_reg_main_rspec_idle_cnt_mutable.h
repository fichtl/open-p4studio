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
#ifndef __REGISTER_INCLUDES_PRSR_REG_MAIN_RSPEC_IDLE_CNT_MUTABLE_H__
#define __REGISTER_INCLUDES_PRSR_REG_MAIN_RSPEC_IDLE_CNT_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofinoB0 {
  namespace register_classes {

class PrsrRegMainRspecIdleCntMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum PmarbRspecEnum {
    kEbp18Reg,
    kIbp18Reg
  };
public:
  PrsrRegMainRspecIdleCntMutable(
      int chipNumber, int index_pipe_addrmap, PmarbRspecEnum selector_pmarb_rspec, int index_ebp_rspec, int index_prsr_reg_main_rspec_idle_cnt, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_pmarb_rspec, index_ebp_rspec, index_prsr_reg_main_rspec_idle_cnt), 8, true, write_callback, read_callback, std::string("PrsrRegMainRspecIdleCntMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_pmarb_rspec) + "," + boost::lexical_cast<std::string>(index_ebp_rspec) + "," + boost::lexical_cast<std::string>(index_prsr_reg_main_rspec_idle_cnt))
    {
    }
  PrsrRegMainRspecIdleCntMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PrsrRegMainRspecIdleCntMutable")
    {
    }
public:





  uint64_t cnt() { return cnt_; }
  void cnt(const uint64_t &v) { cnt_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (cnt_ & 0xffffffff);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = ((cnt_ & UINT64_C(0xffffffff00000000)) >> 32);
    }
    else {
      assert(0);
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      cnt_ = ((static_cast<uint64_t>(data) & 0xffffffff) | (cnt_ & UINT64_C(0xffffffff00000000)));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      cnt_ = (((static_cast<uint64_t>(data) << 32) & UINT64_C(0xffffffff00000000)) | (cnt_ & 0xffffffff));
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    cnt_ = UINT64_C(0x0);
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PrsrRegMainRspecIdleCntMutable") + ":\n";
    r += indent_string + "  " + std::string("cnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt_) ) + "\n";
    all_zeros &= (0 == cnt_);
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
    r += indent_string + std::string("PrsrRegMainRspecIdleCntMutable") + ":\n";
    r += indent_string + "  " + std::string("cnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt_) ) + "\n";
    all_zeros &= (0 == cnt_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint64_t cnt_;
private:
  static int StartOffset(
      int index_pipe_addrmap, PmarbRspecEnum selector_pmarb_rspec, int index_ebp_rspec, int index_prsr_reg_main_rspec_idle_cnt
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    switch (selector_pmarb_rspec) {
      case kEbp18Reg:
        offset += 0x40000; // to get to ebp18_reg
        assert(index_ebp_rspec < 18);
        offset += index_ebp_rspec * 0x2000; // ebp_rspec[]
        offset += 0xe0; // to get to idle_cnt
        assert(index_prsr_reg_main_rspec_idle_cnt < 4);
        offset += index_prsr_reg_main_rspec_idle_cnt * 0x8; // prsr_reg_main_rspec_idle_cnt[]
        break;
      case kIbp18Reg:
        assert(index_ebp_rspec < 18);
        offset += index_ebp_rspec * 0x2000; // ibp_rspec[]
        offset += 0xe0; // to get to idle_cnt
        assert(index_prsr_reg_main_rspec_idle_cnt < 4);
        offset += index_prsr_reg_main_rspec_idle_cnt * 0x8; // prsr_reg_main_rspec_idle_cnt[]
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};








  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PRSR_REG_MAIN_RSPEC_IDLE_CNT_MUTABLE_H__
