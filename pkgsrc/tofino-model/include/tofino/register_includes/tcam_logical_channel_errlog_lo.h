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
#ifndef __REGISTER_INCLUDES_TCAM_LOGICAL_CHANNEL_ERRLOG_LO_H__
#define __REGISTER_INCLUDES_TCAM_LOGICAL_CHANNEL_ERRLOG_LO_H__


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

class TcamLogicalChannelErrlogLo : public model_core::RegisterBlock<RegisterCallback> {
public:
  TcamLogicalChannelErrlogLo(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_tcam_logical_channel_errlog_lo, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_tcam_logical_channel_errlog_lo), 4, false, write_callback, read_callback, std::string("TcamLogicalChannelErrlogLo")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_tcam_logical_channel_errlog_lo))
    {
    }
  TcamLogicalChannelErrlogLo(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "TcamLogicalChannelErrlogLo")
    {
    }
public:


  uint32_t &tcam_logical_channel_errlog_addr() { return tcam_logical_channel_errlog_addr_; }


  uint8_t &tcam_logical_channel_errlog_hit() { return tcam_logical_channel_errlog_hit_; }


  uint8_t &tcam_logical_channel_errlog_actionbit() { return tcam_logical_channel_errlog_actionbit_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (tcam_logical_channel_errlog_addr_ & 0x7ffff);
    *data |= ((tcam_logical_channel_errlog_hit_ & 0x1) << 19);
    *data |= ((tcam_logical_channel_errlog_actionbit_ & 0x1) << 20);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    tcam_logical_channel_errlog_addr_ = (data & 0x7ffff);
    tcam_logical_channel_errlog_hit_ = ((data >> 19) & 0x1);
    tcam_logical_channel_errlog_actionbit_ = ((data >> 20) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    tcam_logical_channel_errlog_addr_ = 0x0;
    tcam_logical_channel_errlog_hit_ = 0x0;
    tcam_logical_channel_errlog_actionbit_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("TcamLogicalChannelErrlogLo") + ":\n";
    r += indent_string + "  " + std::string("tcam_logical_channel_errlog_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_logical_channel_errlog_addr_) ) + "\n";
    all_zeros &= (0 == tcam_logical_channel_errlog_addr_);
    r += indent_string + "  " + std::string("tcam_logical_channel_errlog_hit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_logical_channel_errlog_hit_) ) + "\n";
    all_zeros &= (0 == tcam_logical_channel_errlog_hit_);
    r += indent_string + "  " + std::string("tcam_logical_channel_errlog_actionbit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_logical_channel_errlog_actionbit_) ) + "\n";
    all_zeros &= (0 == tcam_logical_channel_errlog_actionbit_);
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
    r += indent_string + std::string("TcamLogicalChannelErrlogLo") + ":\n";
    r += indent_string + "  " + std::string("tcam_logical_channel_errlog_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_logical_channel_errlog_addr_) ) + "\n";
    all_zeros &= (0 == tcam_logical_channel_errlog_addr_);
    r += indent_string + "  " + std::string("tcam_logical_channel_errlog_hit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_logical_channel_errlog_hit_) ) + "\n";
    all_zeros &= (0 == tcam_logical_channel_errlog_hit_);
    r += indent_string + "  " + std::string("tcam_logical_channel_errlog_actionbit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_logical_channel_errlog_actionbit_) ) + "\n";
    all_zeros &= (0 == tcam_logical_channel_errlog_actionbit_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t tcam_logical_channel_errlog_addr_;
  uint8_t tcam_logical_channel_errlog_hit_;
  uint8_t tcam_logical_channel_errlog_actionbit_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_tcam_logical_channel_errlog_lo
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x40800; // to get to tcams
    offset += 0x1c0; // to get to tcam_logical_channel_errlog_lo
    assert(index_tcam_logical_channel_errlog_lo < 4);
    offset += index_tcam_logical_channel_errlog_lo * 0x4; // tcam_logical_channel_errlog_lo[]
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_TCAM_LOGICAL_CHANNEL_ERRLOG_LO_H__
