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
#ifndef __REGISTER_INCLUDES_EPB_PRSR_PORT_REGS_INT_FREEZE_H__
#define __REGISTER_INCLUDES_EPB_PRSR_PORT_REGS_INT_FREEZE_H__


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

class EpbPrsrPortRegsIntFreeze : public model_core::RegisterBlock<RegisterCallback> {
public:
  EpbPrsrPortRegsIntFreeze(
      int chipNumber, int index_pipe_addrmap, int index_ebp_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ebp_rspec), 4, false, write_callback, read_callback, std::string("EpbPrsrPortRegsIntFreeze")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ebp_rspec))
    {
    }
  EpbPrsrPortRegsIntFreeze(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "EpbPrsrPortRegsIntFreeze")
    {
    }
public:





  uint8_t &int_freeze() { return int_freeze_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (int_freeze_ & 0x3f);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    int_freeze_ = (data & 0x3f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    int_freeze_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("EpbPrsrPortRegsIntFreeze") + ":\n";
    r += indent_string + "  " + std::string("int_freeze") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(int_freeze_) ) + "\n";
    all_zeros &= (0 == int_freeze_);
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
    r += indent_string + std::string("EpbPrsrPortRegsIntFreeze") + ":\n";
    r += indent_string + "  " + std::string("int_freeze") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(int_freeze_) ) + "\n";
    all_zeros &= (0 == int_freeze_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t int_freeze_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ebp_rspec
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    offset += 0x40000; // to get to ebp18_reg
    assert(index_ebp_rspec < 18);
    offset += index_ebp_rspec * 0x2000; // ebp_rspec[]
    offset += 0x1800; // to get to epb_prsr_port_regs
    offset += 0x38; // to get to int_freeze
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_EPB_PRSR_PORT_REGS_INT_FREEZE_H__
