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
#ifndef __REGISTER_INCLUDES_STATS_BUBBLE_REQ_MUTABLE_H__
#define __REGISTER_INCLUDES_STATS_BUBBLE_REQ_MUTABLE_H__


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

class StatsBubbleReqMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  StatsBubbleReqMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_stats_bubble_req, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_stats_bubble_req), 4, true, write_callback, read_callback, std::string("StatsBubbleReqMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_stats_bubble_req))
    {
    }
  StatsBubbleReqMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "StatsBubbleReqMutable")
    {
    }
public:
  uint16_t bubble_req_2x_class_en() { return bubble_req_2x_class_en_; }
  void bubble_req_2x_class_en(const uint16_t &v) { bubble_req_2x_class_en_=v; }
  uint16_t bubble_req_1x_class_en() { return bubble_req_1x_class_en_; }
  void bubble_req_1x_class_en(const uint16_t &v) { bubble_req_1x_class_en_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = bubble_req_2x_class_en_;
    *data |= (bubble_req_1x_class_en_ << 16);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    bubble_req_2x_class_en_ = data;
    bubble_req_1x_class_en_ = (data >> 16);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    bubble_req_2x_class_en_ = 0x0;
    bubble_req_1x_class_en_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("StatsBubbleReqMutable") + ":\n";
    r += indent_string + "  " + std::string("bubble_req_2x_class_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bubble_req_2x_class_en_) ) + "\n";
    all_zeros &= (0 == bubble_req_2x_class_en_);
    r += indent_string + "  " + std::string("bubble_req_1x_class_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bubble_req_1x_class_en_) ) + "\n";
    all_zeros &= (0 == bubble_req_1x_class_en_);
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
    r += indent_string + std::string("StatsBubbleReqMutable") + ":\n";
    r += indent_string + "  " + std::string("bubble_req_2x_class_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bubble_req_2x_class_en_) ) + "\n";
    all_zeros &= (0 == bubble_req_2x_class_en_);
    r += indent_string + "  " + std::string("bubble_req_1x_class_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bubble_req_1x_class_en_) ) + "\n";
    all_zeros &= (0 == bubble_req_1x_class_en_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t bubble_req_2x_class_en_;
  uint16_t bubble_req_1x_class_en_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_stats_bubble_req
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x18000; // to get to match
    offset += 0x410; // to get to stats_bubble_req
    assert(index_stats_bubble_req < 2);
    offset += index_stats_bubble_req * 0x4; // stats_bubble_req[]
    return offset;
  }

};













  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_STATS_BUBBLE_REQ_MUTABLE_H__
