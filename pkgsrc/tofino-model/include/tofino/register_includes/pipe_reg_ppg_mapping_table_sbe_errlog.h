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
#ifndef __REGISTER_INCLUDES_PIPE_REG_PPG_MAPPING_TABLE_SBE_ERRLOG_H__
#define __REGISTER_INCLUDES_PIPE_REG_PPG_MAPPING_TABLE_SBE_ERRLOG_H__


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

class PipeRegPpgMappingTableSbeErrlog : public model_core::RegisterBlock<RegisterCallback> {
public:
  PipeRegPpgMappingTableSbeErrlog(
      int chipNumber, int index_tm_wac_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_wac_pipe_rspec), 4, false, write_callback, read_callback, std::string("PipeRegPpgMappingTableSbeErrlog")+":"+boost::lexical_cast<std::string>(index_tm_wac_pipe_rspec))
    {
    }
  PipeRegPpgMappingTableSbeErrlog(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PipeRegPpgMappingTableSbeErrlog")
    {
    }
public:
  uint16_t &addr() { return addr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (addr_ & 0x1ff);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    addr_ = (data & 0x1ff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    addr_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PipeRegPpgMappingTableSbeErrlog") + ":\n";
    r += indent_string + "  " + std::string("addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_) ) + "\n";
    all_zeros &= (0 == addr_);
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
    r += indent_string + std::string("PipeRegPpgMappingTableSbeErrlog") + ":\n";
    r += indent_string + "  " + std::string("addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_) ) + "\n";
    all_zeros &= (0 == addr_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t addr_;
private:
  static int StartOffset(
      int index_tm_wac_pipe_rspec
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    assert(index_tm_wac_pipe_rspec < 4);
    offset += index_tm_wac_pipe_rspec * 0x8000; // tm_wac_pipe_rspec[]
    offset += 0x554; // to get to wac_reg_ppg_mapping_table_sbe_errlog
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_PIPE_REG_PPG_MAPPING_TABLE_SBE_ERRLOG_H__
