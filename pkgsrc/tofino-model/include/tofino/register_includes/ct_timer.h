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
#ifndef __REGISTER_INCLUDES_CT_TIMER_H__
#define __REGISTER_INCLUDES_CT_TIMER_H__


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

class CtTimer : public model_core::RegisterBlock<RegisterCallback> {
public:
  CtTimer(
      int chipNumber, int index_tm_pex_pipe_rspec, int index_ct_timer, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_pex_pipe_rspec, index_ct_timer), 4, false, write_callback, read_callback, std::string("CtTimer")+":"+boost::lexical_cast<std::string>(index_tm_pex_pipe_rspec) + "," + boost::lexical_cast<std::string>(index_ct_timer))
    {
    }
  CtTimer(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "CtTimer")
    {
    }
public:






  uint8_t &ct_timer_hi0() { return ct_timer_hi0_; }






  uint8_t &ct_timer_lo0() { return ct_timer_lo0_; }






  uint8_t &ct_timer_hi1() { return ct_timer_hi1_; }






  uint8_t &ct_timer_lo1() { return ct_timer_lo1_; }






  uint8_t &ct_timer_hi2() { return ct_timer_hi2_; }






  uint8_t &ct_timer_lo2() { return ct_timer_lo2_; }






  uint8_t &ct_timer_hi3() { return ct_timer_hi3_; }






  uint8_t &ct_timer_lo3() { return ct_timer_lo3_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (ct_timer_hi0_ & 0xf);
    *data |= ((ct_timer_lo0_ & 0xf) << 4);
    *data |= ((ct_timer_hi1_ & 0xf) << 8);
    *data |= ((ct_timer_lo1_ & 0xf) << 12);
    *data |= ((ct_timer_hi2_ & 0xf) << 16);
    *data |= ((ct_timer_lo2_ & 0xf) << 20);
    *data |= ((ct_timer_hi3_ & 0xf) << 24);
    *data |= ((ct_timer_lo3_ & 0xf) << 28);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    ct_timer_hi0_ = (data & 0xf);
    ct_timer_lo0_ = ((data >> 4) & 0xf);
    ct_timer_hi1_ = ((data >> 8) & 0xf);
    ct_timer_lo1_ = ((data >> 12) & 0xf);
    ct_timer_hi2_ = ((data >> 16) & 0xf);
    ct_timer_lo2_ = ((data >> 20) & 0xf);
    ct_timer_hi3_ = ((data >> 24) & 0xf);
    ct_timer_lo3_ = ((data >> 28) & 0xf);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    ct_timer_hi0_ = 0x6;
    ct_timer_lo0_ = 0x3;
    ct_timer_hi1_ = 0x9;
    ct_timer_lo1_ = 0x7;
    ct_timer_hi2_ = 0x9;
    ct_timer_lo2_ = 0x5;
    ct_timer_hi3_ = 0x9;
    ct_timer_lo3_ = 0x7;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("CtTimer") + ":\n";
    r += indent_string + "  " + std::string("ct_timer_hi0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi0_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi0_);
    r += indent_string + "  " + std::string("ct_timer_lo0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo0_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo0_);
    r += indent_string + "  " + std::string("ct_timer_hi1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi1_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi1_);
    r += indent_string + "  " + std::string("ct_timer_lo1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo1_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo1_);
    r += indent_string + "  " + std::string("ct_timer_hi2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi2_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi2_);
    r += indent_string + "  " + std::string("ct_timer_lo2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo2_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo2_);
    r += indent_string + "  " + std::string("ct_timer_hi3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi3_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi3_);
    r += indent_string + "  " + std::string("ct_timer_lo3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo3_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo3_);
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
    r += indent_string + std::string("CtTimer") + ":\n";
    r += indent_string + "  " + std::string("ct_timer_hi0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi0_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi0_);
    r += indent_string + "  " + std::string("ct_timer_lo0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo0_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo0_);
    r += indent_string + "  " + std::string("ct_timer_hi1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi1_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi1_);
    r += indent_string + "  " + std::string("ct_timer_lo1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo1_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo1_);
    r += indent_string + "  " + std::string("ct_timer_hi2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi2_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi2_);
    r += indent_string + "  " + std::string("ct_timer_lo2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo2_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo2_);
    r += indent_string + "  " + std::string("ct_timer_hi3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_hi3_) ) + "\n";
    all_zeros &= (0 == ct_timer_hi3_);
    r += indent_string + "  " + std::string("ct_timer_lo3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_timer_lo3_) ) + "\n";
    all_zeros &= (0 == ct_timer_lo3_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t ct_timer_hi0_;
  uint8_t ct_timer_lo0_;
  uint8_t ct_timer_hi1_;
  uint8_t ct_timer_lo1_;
  uint8_t ct_timer_hi2_;
  uint8_t ct_timer_lo2_;
  uint8_t ct_timer_hi3_;
  uint8_t ct_timer_lo3_;
private:
  static int StartOffset(
      int index_tm_pex_pipe_rspec, int index_ct_timer
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0x100000; // to get to tm_clc_top
    offset += 0x10000; // to get to pex
    assert(index_tm_pex_pipe_rspec < 4);
    offset += index_tm_pex_pipe_rspec * 0x4000; // tm_pex_pipe_rspec[]
    offset += 0x580; // to get to ct_timer
    assert(index_ct_timer < 18);
    offset += index_ct_timer * 0x4; // ct_timer[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_CT_TIMER_H__
