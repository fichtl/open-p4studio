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
#ifndef __REGISTER_INCLUDES_WAC_OFFSET_H__
#define __REGISTER_INCLUDES_WAC_OFFSET_H__


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

class WacOffset : public model_core::RegisterBlock<RegisterCallback> {
public:
  WacOffset(
      int chipNumber, int index_tm_wac_pipe_rspec, int index_wac_offset, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_wac_pipe_rspec, index_wac_offset), 4, false, write_callback, read_callback, std::string("WacOffset")+":"+boost::lexical_cast<std::string>(index_tm_wac_pipe_rspec) + "," + boost::lexical_cast<std::string>(index_wac_offset))
    {
    }
  WacOffset(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "WacOffset")
    {
    }
public:






  uint16_t &offset() { return offset_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (offset_ & 0x3ff);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    offset_ = (data & 0x3ff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    offset_ = 0x10;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("WacOffset") + ":\n";
    r += indent_string + "  " + std::string("offset") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(offset_) ) + "\n";
    all_zeros &= (0 == offset_);
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
    r += indent_string + std::string("WacOffset") + ":\n";
    r += indent_string + "  " + std::string("offset") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(offset_) ) + "\n";
    all_zeros &= (0 == offset_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t offset_;
private:
  static int StartOffset(
      int index_tm_wac_pipe_rspec, int index_wac_offset
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    assert(index_tm_wac_pipe_rspec < 4);
    offset += index_tm_wac_pipe_rspec * 0x8000; // tm_wac_pipe_rspec[]
    offset += 0x380; // to get to wac_reg_offset_profile
    assert(index_wac_offset < 32);
    offset += index_wac_offset * 0x4; // wac_offset[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_WAC_OFFSET_H__
