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
#ifndef __REGISTER_INCLUDES_PIPE_BLOCK_REG_QAC_CTR32_DROP_NO_DST_H__
#define __REGISTER_INCLUDES_PIPE_BLOCK_REG_QAC_CTR32_DROP_NO_DST_H__


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

class PipeBlockRegQacCtr32DropNoDst : public model_core::RegisterBlock<RegisterCallback> {
public:
  PipeBlockRegQacCtr32DropNoDst(
      int chipNumber, int index_tm_qac_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_qac_pipe_rspec), 4, false, write_callback, read_callback, std::string("PipeBlockRegQacCtr32DropNoDst")+":"+boost::lexical_cast<std::string>(index_tm_qac_pipe_rspec))
    {
    }
  PipeBlockRegQacCtr32DropNoDst(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PipeBlockRegQacCtr32DropNoDst")
    {
    }
public:






  uint32_t &ctr32() { return ctr32_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = ctr32_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    ctr32_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    ctr32_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PipeBlockRegQacCtr32DropNoDst") + ":\n";
    r += indent_string + "  " + std::string("ctr32") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ctr32_) ) + "\n";
    all_zeros &= (0 == ctr32_);
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
    r += indent_string + std::string("PipeBlockRegQacCtr32DropNoDst") + ":\n";
    r += indent_string + "  " + std::string("ctr32") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ctr32_) ) + "\n";
    all_zeros &= (0 == ctr32_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t ctr32_;
private:
  static int StartOffset(
      int index_tm_qac_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x100000; // to get to tm_qac_top
    offset += 0x20000; // to get to qac_pipe
    assert(index_tm_qac_pipe_rspec < 4);
    offset += index_tm_qac_pipe_rspec * 0x8000; // tm_qac_pipe_rspec[]
    offset += 0x40; // to get to qac_reg_qac_ctr32_drop_no_dst
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PIPE_BLOCK_REG_QAC_CTR32_DROP_NO_DST_H__
