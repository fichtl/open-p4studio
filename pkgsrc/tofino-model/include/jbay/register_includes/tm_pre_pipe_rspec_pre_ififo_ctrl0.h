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
#ifndef __REGISTER_INCLUDES_TM_PRE_PIPE_RSPEC_PRE_IFIFO_CTRL0_H__
#define __REGISTER_INCLUDES_TM_PRE_PIPE_RSPEC_PRE_IFIFO_CTRL0_H__


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

class TmPrePipeRspecPreIfifoCtrl0 : public model_core::RegisterBlock<RegisterCallback> {
public:
  TmPrePipeRspecPreIfifoCtrl0(
      int chipNumber, int index_tm_pre_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_pre_pipe_rspec), 4, false, write_callback, read_callback, std::string("TmPrePipeRspecPreIfifoCtrl0")+":"+boost::lexical_cast<std::string>(index_tm_pre_pipe_rspec))
    {
    }
  TmPrePipeRspecPreIfifoCtrl0(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "TmPrePipeRspecPreIfifoCtrl0")
    {
    }
public:





  uint16_t &fifo_end() { return fifo_end_; }





  uint16_t &fifo_start() { return fifo_start_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (fifo_end_ & 0x7ff);
    *data |= ((fifo_start_ & 0x7ff) << 11);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    fifo_end_ = (data & 0x7ff);
    fifo_start_ = ((data >> 11) & 0x7ff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    fifo_end_ = 0xff;
    fifo_start_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("TmPrePipeRspecPreIfifoCtrl0") + ":\n";
    r += indent_string + "  " + std::string("fifo_end") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(fifo_end_) ) + "\n";
    all_zeros &= (0 == fifo_end_);
    r += indent_string + "  " + std::string("fifo_start") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(fifo_start_) ) + "\n";
    all_zeros &= (0 == fifo_start_);
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
    r += indent_string + std::string("TmPrePipeRspecPreIfifoCtrl0") + ":\n";
    r += indent_string + "  " + std::string("fifo_end") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(fifo_end_) ) + "\n";
    all_zeros &= (0 == fifo_end_);
    r += indent_string + "  " + std::string("fifo_start") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(fifo_start_) ) + "\n";
    all_zeros &= (0 == fifo_start_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t fifo_end_;
  uint16_t fifo_start_;
private:
  static int StartOffset(
      int index_tm_pre_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x480000; // to get to tm_pre_top
    assert(index_tm_pre_pipe_rspec < 4);
    offset += index_tm_pre_pipe_rspec * 0x8000; // tm_pre_pipe_rspec[]
    offset += 0x160; // to get to pre_ififo_ctrl0
    return offset;
  }

};











  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_TM_PRE_PIPE_RSPEC_PRE_IFIFO_CTRL0_H__
