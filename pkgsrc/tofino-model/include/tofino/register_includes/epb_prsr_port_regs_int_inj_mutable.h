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
#ifndef __REGISTER_INCLUDES_EPB_PRSR_PORT_REGS_INT_INJ_MUTABLE_H__
#define __REGISTER_INCLUDES_EPB_PRSR_PORT_REGS_INT_INJ_MUTABLE_H__


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

class EpbPrsrPortRegsIntInjMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  EpbPrsrPortRegsIntInjMutable(
      int chipNumber, int index_pipe_addrmap, int index_ebp_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ebp_rspec), 4, true, write_callback, read_callback, std::string("EpbPrsrPortRegsIntInjMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ebp_rspec))
    {
    }
  EpbPrsrPortRegsIntInjMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "EpbPrsrPortRegsIntInjMutable")
    {
    }
public:





  uint8_t err_inj() { return err_inj_; }
  void err_inj(const uint8_t &v) { err_inj_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (err_inj_ & 0x3f);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    err_inj_ = (data & 0x3f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    err_inj_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("EpbPrsrPortRegsIntInjMutable") + ":\n";
    r += indent_string + "  " + std::string("err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(err_inj_) ) + "\n";
    all_zeros &= (0 == err_inj_);
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
    r += indent_string + std::string("EpbPrsrPortRegsIntInjMutable") + ":\n";
    r += indent_string + "  " + std::string("err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(err_inj_) ) + "\n";
    all_zeros &= (0 == err_inj_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t err_inj_;
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
    offset += 0x34; // to get to int_inj
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_EPB_PRSR_PORT_REGS_INT_INJ_MUTABLE_H__
