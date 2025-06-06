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
#ifndef __REGISTER_INCLUDES_MAU_CFG_DRAM_THREAD_H__
#define __REGISTER_INCLUDES_MAU_CFG_DRAM_THREAD_H__


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

class MauCfgDramThread : public model_core::RegisterBlock<RegisterCallback> {
public:
  MauCfgDramThread(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap), 4, false, write_callback, read_callback, std::string("MauCfgDramThread")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap))
    {
    }
  MauCfgDramThread(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MauCfgDramThread")
    {
    }
public:
  uint8_t &mau_cfg_dram_thread() { return mau_cfg_dram_thread_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = mau_cfg_dram_thread_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    mau_cfg_dram_thread_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    mau_cfg_dram_thread_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MauCfgDramThread") + ":\n";
    r += indent_string + "  " + std::string("mau_cfg_dram_thread") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mau_cfg_dram_thread_) ) + "\n";
    all_zeros &= (0 == mau_cfg_dram_thread_);
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
    r += indent_string + std::string("MauCfgDramThread") + ":\n";
    r += indent_string + "  " + std::string("mau_cfg_dram_thread") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mau_cfg_dram_thread_) ) + "\n";
    all_zeros &= (0 == mau_cfg_dram_thread_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t mau_cfg_dram_thread_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x40000; // to get to cfg_regs
    offset += 0x138; // to get to mau_cfg_dram_thread
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_MAU_CFG_DRAM_THREAD_H__
