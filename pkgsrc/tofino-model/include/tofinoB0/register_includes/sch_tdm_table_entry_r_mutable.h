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
#ifndef __REGISTER_INCLUDES_SCH_TDM_TABLE_ENTRY_R_MUTABLE_H__
#define __REGISTER_INCLUDES_SCH_TDM_TABLE_ENTRY_R_MUTABLE_H__


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

class SchTdmTableEntryRMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  SchTdmTableEntryRMutable(
      int chipNumber, int index_tm_sch_pipe_rspec, int index_sch_tdm_table_entry_r, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_sch_pipe_rspec, index_sch_tdm_table_entry_r), 4, true, write_callback, read_callback, std::string("SchTdmTableEntryRMutable")+":"+boost::lexical_cast<std::string>(index_tm_sch_pipe_rspec) + "," + boost::lexical_cast<std::string>(index_sch_tdm_table_entry_r))
    {
    }
  SchTdmTableEntryRMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "SchTdmTableEntryRMutable")
    {
    }
public:





  uint8_t id0() { return id0_; }
  void id0(const uint8_t &v) { id0_=v; }





  uint8_t id0_valid() { return id0_valid_; }
  void id0_valid(const uint8_t &v) { id0_valid_=v; }





  uint8_t id1() { return id1_; }
  void id1(const uint8_t &v) { id1_=v; }





  uint8_t id1_valid() { return id1_valid_; }
  void id1_valid(const uint8_t &v) { id1_valid_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (id0_ & 0x7f);
    *data |= ((id0_valid_ & 0x1) << 7);
    *data |= ((id1_ & 0x7f) << 8);
    *data |= ((id1_valid_ & 0x1) << 15);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    id0_ = (data & 0x7f);
    id0_valid_ = ((data >> 7) & 0x1);
    id1_ = ((data >> 8) & 0x7f);
    id1_valid_ = ((data >> 15) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    id0_ = 0x0;
    id0_valid_ = 0x0;
    id1_ = 0x0;
    id1_valid_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("SchTdmTableEntryRMutable") + ":\n";
    r += indent_string + "  " + std::string("id0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id0_) ) + "\n";
    all_zeros &= (0 == id0_);
    r += indent_string + "  " + std::string("id0_valid") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id0_valid_) ) + "\n";
    all_zeros &= (0 == id0_valid_);
    r += indent_string + "  " + std::string("id1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id1_) ) + "\n";
    all_zeros &= (0 == id1_);
    r += indent_string + "  " + std::string("id1_valid") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id1_valid_) ) + "\n";
    all_zeros &= (0 == id1_valid_);
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
    r += indent_string + std::string("SchTdmTableEntryRMutable") + ":\n";
    r += indent_string + "  " + std::string("id0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id0_) ) + "\n";
    all_zeros &= (0 == id0_);
    r += indent_string + "  " + std::string("id0_valid") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id0_valid_) ) + "\n";
    all_zeros &= (0 == id0_valid_);
    r += indent_string + "  " + std::string("id1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id1_) ) + "\n";
    all_zeros &= (0 == id1_);
    r += indent_string + "  " + std::string("id1_valid") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(id1_valid_) ) + "\n";
    all_zeros &= (0 == id1_valid_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t id0_;
  uint8_t id0_valid_;
  uint8_t id1_;
  uint8_t id1_valid_;
private:
  static int StartOffset(
      int index_tm_sch_pipe_rspec, int index_sch_tdm_table_entry_r
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0xc0000; // to get to tm_sch_top
    assert(index_tm_sch_pipe_rspec < 4);
    offset += index_tm_sch_pipe_rspec * 0x10000; // tm_sch_pipe_rspec[]
    offset += 0x200; // to get to tdm_table
    assert(index_sch_tdm_table_entry_r < 128);
    offset += index_sch_tdm_table_entry_r * 0x4; // sch_tdm_table_entry_r[]
    return offset;
  }

};














  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_SCH_TDM_TABLE_ENTRY_R_MUTABLE_H__
