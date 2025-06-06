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
#ifndef __REGISTER_INCLUDES_STATS_DUMP_CTL_H__
#define __REGISTER_INCLUDES_STATS_DUMP_CTL_H__


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

class StatsDumpCtl : public model_core::RegisterBlock<RegisterCallback> {
public:
  StatsDumpCtl(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_stats_dump_ctl, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_stats_dump_ctl), 4, false, write_callback, read_callback, std::string("StatsDumpCtl")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_stats_dump_ctl))
    {
    }
  StatsDumpCtl(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "StatsDumpCtl")
    {
    }
public:



  uint8_t &stats_dump_entries_per_word() { return stats_dump_entries_per_word_; }



  uint8_t &stats_dump_has_bytes() { return stats_dump_has_bytes_; }



  uint8_t &stats_dump_has_packets() { return stats_dump_has_packets_; }


  uint8_t &stats_dump_offset() { return stats_dump_offset_; }


  uint8_t &stats_dump_size() { return stats_dump_size_; }


  uint8_t &stats_dump_remove_hole_pos() { return stats_dump_remove_hole_pos_; }


  uint8_t &stats_dump_remove_hole_en() { return stats_dump_remove_hole_en_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (stats_dump_entries_per_word_ & 0x7);
    *data |= ((stats_dump_has_bytes_ & 0x1) << 3);
    *data |= ((stats_dump_has_packets_ & 0x1) << 4);
    *data |= ((stats_dump_offset_ & 0x3f) << 5);
    *data |= ((stats_dump_size_ & 0x3f) << 11);
    *data |= ((stats_dump_remove_hole_pos_ & 0x7) << 17);
    *data |= ((stats_dump_remove_hole_en_ & 0x1) << 20);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    stats_dump_entries_per_word_ = (data & 0x7);
    stats_dump_has_bytes_ = ((data >> 3) & 0x1);
    stats_dump_has_packets_ = ((data >> 4) & 0x1);
    stats_dump_offset_ = ((data >> 5) & 0x3f);
    stats_dump_size_ = ((data >> 11) & 0x3f);
    stats_dump_remove_hole_pos_ = ((data >> 17) & 0x7);
    stats_dump_remove_hole_en_ = ((data >> 20) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    stats_dump_entries_per_word_ = 0x0;
    stats_dump_has_bytes_ = 0x0;
    stats_dump_has_packets_ = 0x0;
    stats_dump_offset_ = 0x0;
    stats_dump_size_ = 0x0;
    stats_dump_remove_hole_pos_ = 0x0;
    stats_dump_remove_hole_en_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("StatsDumpCtl") + ":\n";
    r += indent_string + "  " + std::string("stats_dump_entries_per_word") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_entries_per_word_) ) + "\n";
    all_zeros &= (0 == stats_dump_entries_per_word_);
    r += indent_string + "  " + std::string("stats_dump_has_bytes") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_has_bytes_) ) + "\n";
    all_zeros &= (0 == stats_dump_has_bytes_);
    r += indent_string + "  " + std::string("stats_dump_has_packets") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_has_packets_) ) + "\n";
    all_zeros &= (0 == stats_dump_has_packets_);
    r += indent_string + "  " + std::string("stats_dump_offset") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_offset_) ) + "\n";
    all_zeros &= (0 == stats_dump_offset_);
    r += indent_string + "  " + std::string("stats_dump_size") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_size_) ) + "\n";
    all_zeros &= (0 == stats_dump_size_);
    r += indent_string + "  " + std::string("stats_dump_remove_hole_pos") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_remove_hole_pos_) ) + "\n";
    all_zeros &= (0 == stats_dump_remove_hole_pos_);
    r += indent_string + "  " + std::string("stats_dump_remove_hole_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_remove_hole_en_) ) + "\n";
    all_zeros &= (0 == stats_dump_remove_hole_en_);
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
    r += indent_string + std::string("StatsDumpCtl") + ":\n";
    r += indent_string + "  " + std::string("stats_dump_entries_per_word") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_entries_per_word_) ) + "\n";
    all_zeros &= (0 == stats_dump_entries_per_word_);
    r += indent_string + "  " + std::string("stats_dump_has_bytes") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_has_bytes_) ) + "\n";
    all_zeros &= (0 == stats_dump_has_bytes_);
    r += indent_string + "  " + std::string("stats_dump_has_packets") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_has_packets_) ) + "\n";
    all_zeros &= (0 == stats_dump_has_packets_);
    r += indent_string + "  " + std::string("stats_dump_offset") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_offset_) ) + "\n";
    all_zeros &= (0 == stats_dump_offset_);
    r += indent_string + "  " + std::string("stats_dump_size") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_size_) ) + "\n";
    all_zeros &= (0 == stats_dump_size_);
    r += indent_string + "  " + std::string("stats_dump_remove_hole_pos") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_remove_hole_pos_) ) + "\n";
    all_zeros &= (0 == stats_dump_remove_hole_pos_);
    r += indent_string + "  " + std::string("stats_dump_remove_hole_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_dump_remove_hole_en_) ) + "\n";
    all_zeros &= (0 == stats_dump_remove_hole_en_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t stats_dump_entries_per_word_;
  uint8_t stats_dump_has_bytes_;
  uint8_t stats_dump_has_packets_;
  uint8_t stats_dump_offset_;
  uint8_t stats_dump_size_;
  uint8_t stats_dump_remove_hole_pos_;
  uint8_t stats_dump_remove_hole_en_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_stats_dump_ctl
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x40000; // to get to cfg_regs
    offset += 0xc0; // to get to stats_dump_ctl
    assert(index_stats_dump_ctl < 16);
    offset += index_stats_dump_ctl * 0x4; // stats_dump_ctl[]
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_STATS_DUMP_CTL_H__
