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
#ifndef __REGISTER_INCLUDES_MIRR_DBUFF_TH_H__
#define __REGISTER_INCLUDES_MIRR_DBUFF_TH_H__


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

class MirrDbuffTh : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirrDbuffTh(
      int chipNumber, int index_pipe_addrmap, int index_mirror_slice_regs, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mirror_slice_regs), 4, false, write_callback, read_callback, std::string("MirrDbuffTh")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mirror_slice_regs))
    {
    }
  MirrDbuffTh(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MirrDbuffTh")
    {
    }
public:





  uint8_t &th_lo() { return th_lo_; }





  uint8_t &th_hi() { return th_hi_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = th_lo_;
    *data |= (th_hi_ << 8);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    th_lo_ = data;
    th_hi_ = (data >> 8);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    th_lo_ = 0x50;
    th_hi_ = 0x60;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MirrDbuffTh") + ":\n";
    r += indent_string + "  " + std::string("th_lo") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(th_lo_) ) + "\n";
    all_zeros &= (0 == th_lo_);
    r += indent_string + "  " + std::string("th_hi") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(th_hi_) ) + "\n";
    all_zeros &= (0 == th_hi_);
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
    r += indent_string + std::string("MirrDbuffTh") + ":\n";
    r += indent_string + "  " + std::string("th_lo") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(th_lo_) ) + "\n";
    all_zeros &= (0 == th_lo_);
    r += indent_string + "  " + std::string("th_hi") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(th_hi_) ) + "\n";
    all_zeros &= (0 == th_hi_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t th_lo_;
  uint8_t th_hi_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mirror_slice_regs
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x80000; // to get to mirreg
    offset += 0x20000; // to get to slice_regs
    assert(index_mirror_slice_regs < 4);
    offset += index_mirror_slice_regs * 0x1000; // mirror_slice_regs[]
    offset += 0x54; // to get to dbuff_th
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MIRR_DBUFF_TH_H__
