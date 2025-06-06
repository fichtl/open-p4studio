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
#ifndef __REGISTER_INCLUDES_PARDE_DPRSR_REG_RSPEC_CSR_RING_FULL_THRESH_MUTABLE_H__
#define __REGISTER_INCLUDES_PARDE_DPRSR_REG_RSPEC_CSR_RING_FULL_THRESH_MUTABLE_H__


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

class PardeDprsrRegRspecCsrRingFullThreshMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PardeDprsrRegRspecCsrRingFullThreshMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, true, write_callback, read_callback, std::string("PardeDprsrRegRspecCsrRingFullThreshMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PardeDprsrRegRspecCsrRingFullThreshMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PardeDprsrRegRspecCsrRingFullThreshMutable")
    {
    }
public:







  uint8_t i_any(int j0) { return i_any_[j0]; }
  void i_any(int j0,const uint8_t &v) { i_any_[j0]=v; }







  uint8_t i_ind(int j0) { return i_ind_[j0]; }
  void i_ind(int j0,const uint8_t &v) { i_ind_[j0]=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (i_any_[0] & 0x7);
    *data |= ((i_any_[1] & 0x7) << 3);
    *data |= ((i_any_[2] & 0x7) << 6);
    *data |= ((i_any_[3] & 0x7) << 9);
    *data |= ((i_ind_[0] & 0x7) << 12);
    *data |= ((i_ind_[1] & 0x7) << 15);
    *data |= ((i_ind_[2] & 0x7) << 18);
    *data |= ((i_ind_[3] & 0x7) << 21);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    i_any_[0] = (data & 0x7);
    i_any_[1] = ((data >> 3) & 0x7);
    i_any_[2] = ((data >> 6) & 0x7);
    i_any_[3] = ((data >> 9) & 0x7);
    i_ind_[0] = ((data >> 12) & 0x7);
    i_ind_[1] = ((data >> 15) & 0x7);
    i_ind_[2] = ((data >> 18) & 0x7);
    i_ind_[3] = ((data >> 21) & 0x7);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    i_any_[0] = 0x4;
    i_any_[1] = 0x4;
    i_any_[2] = 0x4;
    i_any_[3] = 0x4;
    i_ind_[0] = 0x2;
    i_ind_[1] = 0x2;
    i_ind_[2] = 0x2;
    i_ind_[3] = 0x2;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PardeDprsrRegRspecCsrRingFullThreshMutable") + ":\n";
    for (uint32_t f=0;f<4;++f) {
      r += indent_string + "  " + std::string("i_any") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i_any_[f]) ) + "\n";
      all_zeros &= (0 == i_any_[f]);
    }
    for (uint32_t f=0;f<4;++f) {
      r += indent_string + "  " + std::string("i_ind") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i_ind_[f]) ) + "\n";
      all_zeros &= (0 == i_ind_[f]);
    }
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
    r += indent_string + std::string("PardeDprsrRegRspecCsrRingFullThreshMutable") + ":\n";
    for (uint32_t f=0;f<4;++f) {
      r += indent_string + "  " + std::string("i_any") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i_any_[f]) ) + "\n";
      all_zeros &= (0 == i_any_[f]);
    }
    for (uint32_t f=0;f<4;++f) {
      r += indent_string + "  " + std::string("i_ind") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(i_ind_[f]) ) + "\n";
      all_zeros &= (0 == i_ind_[f]);
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< uint8_t, 4 > i_any_;
  std::array< uint8_t, 4 > i_ind_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    offset += 0x2f800; // to get to dprsr_csr_ring
    offset += 0x8; // to get to csr_ring_full_thresh
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PARDE_DPRSR_REG_RSPEC_CSR_RING_FULL_THRESH_MUTABLE_H__
