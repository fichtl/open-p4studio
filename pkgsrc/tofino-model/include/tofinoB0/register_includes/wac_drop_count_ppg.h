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
#ifndef __REGISTER_INCLUDES_WAC_DROP_COUNT_PPG_H__
#define __REGISTER_INCLUDES_WAC_DROP_COUNT_PPG_H__


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

class WacDropCountPpg : public model_core::RegisterBlock<RegisterCallback> {
public:
  WacDropCountPpg(
      int chipNumber, int index_tm_wac_pipe_rspec, int index_wac_drop_count_ppg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_wac_pipe_rspec, index_wac_drop_count_ppg), 8, false, write_callback, read_callback, std::string("WacDropCountPpg")+":"+boost::lexical_cast<std::string>(index_tm_wac_pipe_rspec) + "," + boost::lexical_cast<std::string>(index_wac_drop_count_ppg))
    {
    }
  WacDropCountPpg(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "WacDropCountPpg")
    {
    }
public:






  uint64_t &cnt() { return cnt_; }






  uint8_t &ecc() { return ecc_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (cnt_ & 0xffffffff);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = ((cnt_ & UINT64_C(0xff00000000)) >> 32);
      *data |= ((ecc_ & 0x7f) << 8);
    }
    else {
      assert(0);
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      cnt_ = ((static_cast<uint64_t>(data) & 0xffffffff) | (cnt_ & UINT64_C(0xff00000000)));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      cnt_ = (((static_cast<uint64_t>(data) << 32) & UINT64_C(0xff00000000)) | (cnt_ & 0xffffffff));
      ecc_ = ((data >> 8) & 0x7f);
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    cnt_ = UINT64_C(0x0);
    ecc_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("WacDropCountPpg") + ":\n";
    r += indent_string + "  " + std::string("cnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt_) ) + "\n";
    all_zeros &= (0 == cnt_);
    r += indent_string + "  " + std::string("ecc") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ecc_) ) + "\n";
    all_zeros &= (0 == ecc_);
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
    r += indent_string + std::string("WacDropCountPpg") + ":\n";
    r += indent_string + "  " + std::string("cnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt_) ) + "\n";
    all_zeros &= (0 == cnt_);
    r += indent_string + "  " + std::string("ecc") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ecc_) ) + "\n";
    all_zeros &= (0 == ecc_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint64_t cnt_;
  uint8_t ecc_;
private:
  static int StartOffset(
      int index_tm_wac_pipe_rspec, int index_wac_drop_count_ppg
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    assert(index_tm_wac_pipe_rspec < 4);
    offset += index_tm_wac_pipe_rspec * 0x8000; // tm_wac_pipe_rspec[]
    offset += 0x1000; // to get to wac_reg_wac_drop_count_ppg
    assert(index_wac_drop_count_ppg < 201);
    offset += index_wac_drop_count_ppg * 0x8; // wac_drop_count_ppg[]
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_WAC_DROP_COUNT_PPG_H__
