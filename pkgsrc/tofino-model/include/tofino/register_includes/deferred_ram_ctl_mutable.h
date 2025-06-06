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
#ifndef __REGISTER_INCLUDES_DEFERRED_RAM_CTL_MUTABLE_H__
#define __REGISTER_INCLUDES_DEFERRED_RAM_CTL_MUTABLE_H__


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

class DeferredRamCtlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  DeferredRamCtlMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_deferred_ram_ctl_0, int index_deferred_ram_ctl_1, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_deferred_ram_ctl_0, index_deferred_ram_ctl_1), 4, true, write_callback, read_callback, std::string("DeferredRamCtlMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_deferred_ram_ctl_0) + "," + boost::lexical_cast<std::string>(index_deferred_ram_ctl_1))
    {
    }
  DeferredRamCtlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DeferredRamCtlMutable")
    {
    }
public:



  uint8_t deferred_ram_thread() { return deferred_ram_thread_; }
  void deferred_ram_thread(const uint8_t &v) { deferred_ram_thread_=v; }



  uint8_t deferred_ram_en() { return deferred_ram_en_; }
  void deferred_ram_en(const uint8_t &v) { deferred_ram_en_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (deferred_ram_thread_ & 0x1);
    *data |= ((deferred_ram_en_ & 0x1) << 1);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    deferred_ram_thread_ = (data & 0x1);
    deferred_ram_en_ = ((data >> 1) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    deferred_ram_thread_ = 0x0;
    deferred_ram_en_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DeferredRamCtlMutable") + ":\n";
    r += indent_string + "  " + std::string("deferred_ram_thread") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(deferred_ram_thread_) ) + "\n";
    all_zeros &= (0 == deferred_ram_thread_);
    r += indent_string + "  " + std::string("deferred_ram_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(deferred_ram_en_) ) + "\n";
    all_zeros &= (0 == deferred_ram_en_);
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
    r += indent_string + std::string("DeferredRamCtlMutable") + ":\n";
    r += indent_string + "  " + std::string("deferred_ram_thread") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(deferred_ram_thread_) ) + "\n";
    all_zeros &= (0 == deferred_ram_thread_);
    r += indent_string + "  " + std::string("deferred_ram_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(deferred_ram_en_) ) + "\n";
    all_zeros &= (0 == deferred_ram_en_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t deferred_ram_thread_;
  uint8_t deferred_ram_en_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_deferred_ram_ctl_0, int index_deferred_ram_ctl_1
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x18000; // to get to match
    offset += 0xc0; // to get to deferred_ram_ctl
    assert(index_deferred_ram_ctl_0 < 2);
    offset += index_deferred_ram_ctl_0 * 0x10; // deferred_ram_ctl[]
    assert(index_deferred_ram_ctl_1 < 4);
    offset += index_deferred_ram_ctl_1 * 0x4; // deferred_ram_ctl[][]
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_DEFERRED_RAM_CTL_MUTABLE_H__
