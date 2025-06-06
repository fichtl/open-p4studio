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
#ifndef __REGISTER_INCLUDES_P2S_REG_INTR_STAT_H__
#define __REGISTER_INCLUDES_P2S_REG_INTR_STAT_H__


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

class P2sRegIntrStat : public model_core::RegisterBlock<RegisterCallback> {
public:
  P2sRegIntrStat(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("P2sRegIntrStat")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  P2sRegIntrStat(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "P2sRegIntrStat")
    {
    }
public:





  uint8_t &tm_sbe() { return tm_sbe_; }





  uint8_t &tm_mbe() { return tm_mbe_; }





  uint8_t &sb_0_sbe() { return sb_0_sbe_; }





  uint8_t &sb_0_mbe() { return sb_0_mbe_; }





  uint8_t &sb_1_sbe() { return sb_1_sbe_; }





  uint8_t &sb_1_mbe() { return sb_1_mbe_; }





  uint8_t &sb_2_sbe() { return sb_2_sbe_; }





  uint8_t &sb_2_mbe() { return sb_2_mbe_; }





  uint8_t &sb_3_sbe() { return sb_3_sbe_; }





  uint8_t &sb_3_mbe() { return sb_3_mbe_; }





  uint8_t &sb_4_sbe() { return sb_4_sbe_; }





  uint8_t &sb_4_mbe() { return sb_4_mbe_; }





  uint8_t &sb_oflow() { return sb_oflow_; }





  uint8_t &sb_uflow() { return sb_uflow_; }





  uint8_t &epb_cred_oflow() { return epb_cred_oflow_; }





  uint8_t &epb_cred_uflow() { return epb_cred_uflow_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (tm_sbe_ & 0x1);
    *data |= ((tm_mbe_ & 0x1) << 1);
    *data |= ((sb_0_sbe_ & 0x1) << 2);
    *data |= ((sb_0_mbe_ & 0x1) << 3);
    *data |= ((sb_1_sbe_ & 0x1) << 4);
    *data |= ((sb_1_mbe_ & 0x1) << 5);
    *data |= ((sb_2_sbe_ & 0x1) << 6);
    *data |= ((sb_2_mbe_ & 0x1) << 7);
    *data |= ((sb_3_sbe_ & 0x1) << 8);
    *data |= ((sb_3_mbe_ & 0x1) << 9);
    *data |= ((sb_4_sbe_ & 0x1) << 10);
    *data |= ((sb_4_mbe_ & 0x1) << 11);
    *data |= ((sb_oflow_ & 0x1) << 12);
    *data |= ((sb_uflow_ & 0x1) << 13);
    *data |= ((epb_cred_oflow_ & 0x1) << 14);
    *data |= ((epb_cred_uflow_ & 0x1) << 15);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    tm_sbe_ &= ~(data & 0x1);
    tm_mbe_ &= ~((data >> 1) & 0x1);
    sb_0_sbe_ &= ~((data >> 2) & 0x1);
    sb_0_mbe_ &= ~((data >> 3) & 0x1);
    sb_1_sbe_ &= ~((data >> 4) & 0x1);
    sb_1_mbe_ &= ~((data >> 5) & 0x1);
    sb_2_sbe_ &= ~((data >> 6) & 0x1);
    sb_2_mbe_ &= ~((data >> 7) & 0x1);
    sb_3_sbe_ &= ~((data >> 8) & 0x1);
    sb_3_mbe_ &= ~((data >> 9) & 0x1);
    sb_4_sbe_ &= ~((data >> 10) & 0x1);
    sb_4_mbe_ &= ~((data >> 11) & 0x1);
    sb_oflow_ &= ~((data >> 12) & 0x1);
    sb_uflow_ &= ~((data >> 13) & 0x1);
    epb_cred_oflow_ &= ~((data >> 14) & 0x1);
    epb_cred_uflow_ &= ~((data >> 15) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    tm_sbe_ = 0x0;
    tm_mbe_ = 0x0;
    sb_0_sbe_ = 0x0;
    sb_0_mbe_ = 0x0;
    sb_1_sbe_ = 0x0;
    sb_1_mbe_ = 0x0;
    sb_2_sbe_ = 0x0;
    sb_2_mbe_ = 0x0;
    sb_3_sbe_ = 0x0;
    sb_3_mbe_ = 0x0;
    sb_4_sbe_ = 0x0;
    sb_4_mbe_ = 0x0;
    sb_oflow_ = 0x0;
    sb_uflow_ = 0x0;
    epb_cred_oflow_ = 0x0;
    epb_cred_uflow_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("P2sRegIntrStat") + ":\n";
    r += indent_string + "  " + std::string("tm_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tm_sbe_) ) + "\n";
    all_zeros &= (0 == tm_sbe_);
    r += indent_string + "  " + std::string("tm_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tm_mbe_) ) + "\n";
    all_zeros &= (0 == tm_mbe_);
    r += indent_string + "  " + std::string("sb_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_0_sbe_) ) + "\n";
    all_zeros &= (0 == sb_0_sbe_);
    r += indent_string + "  " + std::string("sb_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_0_mbe_) ) + "\n";
    all_zeros &= (0 == sb_0_mbe_);
    r += indent_string + "  " + std::string("sb_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_1_sbe_) ) + "\n";
    all_zeros &= (0 == sb_1_sbe_);
    r += indent_string + "  " + std::string("sb_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_1_mbe_) ) + "\n";
    all_zeros &= (0 == sb_1_mbe_);
    r += indent_string + "  " + std::string("sb_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_2_sbe_) ) + "\n";
    all_zeros &= (0 == sb_2_sbe_);
    r += indent_string + "  " + std::string("sb_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_2_mbe_) ) + "\n";
    all_zeros &= (0 == sb_2_mbe_);
    r += indent_string + "  " + std::string("sb_3_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_3_sbe_) ) + "\n";
    all_zeros &= (0 == sb_3_sbe_);
    r += indent_string + "  " + std::string("sb_3_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_3_mbe_) ) + "\n";
    all_zeros &= (0 == sb_3_mbe_);
    r += indent_string + "  " + std::string("sb_4_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_4_sbe_) ) + "\n";
    all_zeros &= (0 == sb_4_sbe_);
    r += indent_string + "  " + std::string("sb_4_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_4_mbe_) ) + "\n";
    all_zeros &= (0 == sb_4_mbe_);
    r += indent_string + "  " + std::string("sb_oflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_oflow_) ) + "\n";
    all_zeros &= (0 == sb_oflow_);
    r += indent_string + "  " + std::string("sb_uflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_uflow_) ) + "\n";
    all_zeros &= (0 == sb_uflow_);
    r += indent_string + "  " + std::string("epb_cred_oflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(epb_cred_oflow_) ) + "\n";
    all_zeros &= (0 == epb_cred_oflow_);
    r += indent_string + "  " + std::string("epb_cred_uflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(epb_cred_uflow_) ) + "\n";
    all_zeros &= (0 == epb_cred_uflow_);
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
    r += indent_string + std::string("P2sRegIntrStat") + ":\n";
    r += indent_string + "  " + std::string("tm_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tm_sbe_) ) + "\n";
    all_zeros &= (0 == tm_sbe_);
    r += indent_string + "  " + std::string("tm_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tm_mbe_) ) + "\n";
    all_zeros &= (0 == tm_mbe_);
    r += indent_string + "  " + std::string("sb_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_0_sbe_) ) + "\n";
    all_zeros &= (0 == sb_0_sbe_);
    r += indent_string + "  " + std::string("sb_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_0_mbe_) ) + "\n";
    all_zeros &= (0 == sb_0_mbe_);
    r += indent_string + "  " + std::string("sb_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_1_sbe_) ) + "\n";
    all_zeros &= (0 == sb_1_sbe_);
    r += indent_string + "  " + std::string("sb_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_1_mbe_) ) + "\n";
    all_zeros &= (0 == sb_1_mbe_);
    r += indent_string + "  " + std::string("sb_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_2_sbe_) ) + "\n";
    all_zeros &= (0 == sb_2_sbe_);
    r += indent_string + "  " + std::string("sb_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_2_mbe_) ) + "\n";
    all_zeros &= (0 == sb_2_mbe_);
    r += indent_string + "  " + std::string("sb_3_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_3_sbe_) ) + "\n";
    all_zeros &= (0 == sb_3_sbe_);
    r += indent_string + "  " + std::string("sb_3_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_3_mbe_) ) + "\n";
    all_zeros &= (0 == sb_3_mbe_);
    r += indent_string + "  " + std::string("sb_4_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_4_sbe_) ) + "\n";
    all_zeros &= (0 == sb_4_sbe_);
    r += indent_string + "  " + std::string("sb_4_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_4_mbe_) ) + "\n";
    all_zeros &= (0 == sb_4_mbe_);
    r += indent_string + "  " + std::string("sb_oflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_oflow_) ) + "\n";
    all_zeros &= (0 == sb_oflow_);
    r += indent_string + "  " + std::string("sb_uflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sb_uflow_) ) + "\n";
    all_zeros &= (0 == sb_uflow_);
    r += indent_string + "  " + std::string("epb_cred_oflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(epb_cred_oflow_) ) + "\n";
    all_zeros &= (0 == epb_cred_oflow_);
    r += indent_string + "  " + std::string("epb_cred_uflow") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(epb_cred_uflow_) ) + "\n";
    all_zeros &= (0 == epb_cred_uflow_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t tm_sbe_;
  uint8_t tm_mbe_;
  uint8_t sb_0_sbe_;
  uint8_t sb_0_mbe_;
  uint8_t sb_1_sbe_;
  uint8_t sb_1_mbe_;
  uint8_t sb_2_sbe_;
  uint8_t sb_2_mbe_;
  uint8_t sb_3_sbe_;
  uint8_t sb_3_mbe_;
  uint8_t sb_4_sbe_;
  uint8_t sb_4_mbe_;
  uint8_t sb_oflow_;
  uint8_t sb_uflow_;
  uint8_t epb_cred_oflow_;
  uint8_t epb_cred_uflow_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x1c000; // to get to p2sreg
    offset += 0xb00; // to get to intr_stat
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_P2S_REG_INTR_STAT_H__
