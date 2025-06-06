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
#ifndef __REGISTER_INCLUDES_PARTY_GLUE_REG_RSPEC_DEBUG_CTRL_H__
#define __REGISTER_INCLUDES_PARTY_GLUE_REG_RSPEC_DEBUG_CTRL_H__


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

class PartyGlueRegRspecDebugCtrl : public model_core::RegisterBlock<RegisterCallback> {
public:
  PartyGlueRegRspecDebugCtrl(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("PartyGlueRegRspecDebugCtrl")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PartyGlueRegRspecDebugCtrl(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PartyGlueRegRspecDebugCtrl")
    {
    }
public:





  uint8_t &en0() { return en0_; }





  uint8_t &sel0() { return sel0_; }





  uint8_t &en1() { return en1_; }





  uint8_t &sel1() { return sel1_; }





  uint8_t &en2() { return en2_; }





  uint8_t &sel2() { return sel2_; }





  uint8_t &en3() { return en3_; }





  uint8_t &sel3() { return sel3_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (en0_ & 0x1);
    *data |= ((sel0_ & 0x7f) << 1);
    *data |= ((en1_ & 0x1) << 8);
    *data |= ((sel1_ & 0x7f) << 9);
    *data |= ((en2_ & 0x1) << 16);
    *data |= ((sel2_ & 0x7f) << 17);
    *data |= ((en3_ & 0x1) << 24);
    *data |= ((sel3_ & 0x7f) << 25);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    en0_ = (data & 0x1);
    sel0_ = ((data >> 1) & 0x7f);
    en1_ = ((data >> 8) & 0x1);
    sel1_ = ((data >> 9) & 0x7f);
    en2_ = ((data >> 16) & 0x1);
    sel2_ = ((data >> 17) & 0x7f);
    en3_ = ((data >> 24) & 0x1);
    sel3_ = ((data >> 25) & 0x7f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    en0_ = 0x0;
    sel0_ = 0x0;
    en1_ = 0x0;
    sel1_ = 0x0;
    en2_ = 0x0;
    sel2_ = 0x0;
    en3_ = 0x0;
    sel3_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PartyGlueRegRspecDebugCtrl") + ":\n";
    r += indent_string + "  " + std::string("en0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en0_) ) + "\n";
    all_zeros &= (0 == en0_);
    r += indent_string + "  " + std::string("sel0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel0_) ) + "\n";
    all_zeros &= (0 == sel0_);
    r += indent_string + "  " + std::string("en1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en1_) ) + "\n";
    all_zeros &= (0 == en1_);
    r += indent_string + "  " + std::string("sel1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel1_) ) + "\n";
    all_zeros &= (0 == sel1_);
    r += indent_string + "  " + std::string("en2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en2_) ) + "\n";
    all_zeros &= (0 == en2_);
    r += indent_string + "  " + std::string("sel2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel2_) ) + "\n";
    all_zeros &= (0 == sel2_);
    r += indent_string + "  " + std::string("en3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en3_) ) + "\n";
    all_zeros &= (0 == en3_);
    r += indent_string + "  " + std::string("sel3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel3_) ) + "\n";
    all_zeros &= (0 == sel3_);
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
    r += indent_string + std::string("PartyGlueRegRspecDebugCtrl") + ":\n";
    r += indent_string + "  " + std::string("en0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en0_) ) + "\n";
    all_zeros &= (0 == en0_);
    r += indent_string + "  " + std::string("sel0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel0_) ) + "\n";
    all_zeros &= (0 == sel0_);
    r += indent_string + "  " + std::string("en1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en1_) ) + "\n";
    all_zeros &= (0 == en1_);
    r += indent_string + "  " + std::string("sel1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel1_) ) + "\n";
    all_zeros &= (0 == sel1_);
    r += indent_string + "  " + std::string("en2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en2_) ) + "\n";
    all_zeros &= (0 == en2_);
    r += indent_string + "  " + std::string("sel2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel2_) ) + "\n";
    all_zeros &= (0 == sel2_);
    r += indent_string + "  " + std::string("en3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en3_) ) + "\n";
    all_zeros &= (0 == en3_);
    r += indent_string + "  " + std::string("sel3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sel3_) ) + "\n";
    all_zeros &= (0 == sel3_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t en0_;
  uint8_t sel0_;
  uint8_t en1_;
  uint8_t sel1_;
  uint8_t en2_;
  uint8_t sel2_;
  uint8_t en3_;
  uint8_t sel3_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    offset += 0x3e000; // to get to party_glue_reg
    offset += 0x4; // to get to debug_ctrl
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_PARTY_GLUE_REG_RSPEC_DEBUG_CTRL_H__
