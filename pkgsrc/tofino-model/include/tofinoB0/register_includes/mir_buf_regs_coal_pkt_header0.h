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
#ifndef __REGISTER_INCLUDES_MIR_BUF_REGS_COAL_PKT_HEADER0_H__
#define __REGISTER_INCLUDES_MIR_BUF_REGS_COAL_PKT_HEADER0_H__


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

class MirBufRegsCoalPktHeader0 : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirBufRegsCoalPktHeader0(
      int chipNumber, int index_pipe_addrmap, int index_mir_buf_regs_coal_desc_grp, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mir_buf_regs_coal_desc_grp), 4, false, write_callback, read_callback, std::string("MirBufRegsCoalPktHeader0")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mir_buf_regs_coal_desc_grp))
    {
    }
  MirBufRegsCoalPktHeader0(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MirBufRegsCoalPktHeader0")
    {
    }
public:





  uint32_t &coal_pkt_hdr0() { return coal_pkt_hdr0_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = coal_pkt_hdr0_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    coal_pkt_hdr0_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    coal_pkt_hdr0_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MirBufRegsCoalPktHeader0") + ":\n";
    r += indent_string + "  " + std::string("coal_pkt_hdr0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(coal_pkt_hdr0_) ) + "\n";
    all_zeros &= (0 == coal_pkt_hdr0_);
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
    r += indent_string + std::string("MirBufRegsCoalPktHeader0") + ":\n";
    r += indent_string + "  " + std::string("coal_pkt_hdr0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(coal_pkt_hdr0_) ) + "\n";
    all_zeros &= (0 == coal_pkt_hdr0_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t coal_pkt_hdr0_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mir_buf_regs_coal_desc_grp
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    offset += 0x20000; // to get to mirror
    offset += 0x8000; // to get to mir_buf_regs
    assert(index_mir_buf_regs_coal_desc_grp < 8);
    offset += index_mir_buf_regs_coal_desc_grp * 0x1c; // mir_buf_regs_coal_desc_grp[]
    offset += 0x208; // to get to coal_desc_grp_coal_pkt_header0
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_MIR_BUF_REGS_COAL_PKT_HEADER0_H__
