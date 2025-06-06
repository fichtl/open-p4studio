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
#ifndef __REGISTER_INCLUDES_PHV_EGRESS_THREAD_IMEM_H__
#define __REGISTER_INCLUDES_PHV_EGRESS_THREAD_IMEM_H__


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

class PhvEgressThreadImem : public model_core::RegisterBlock<RegisterCallback> {
public:
  PhvEgressThreadImem(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_phv_egress_thread_imem_0, int index_phv_egress_thread_imem_1, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_phv_egress_thread_imem_0, index_phv_egress_thread_imem_1), 4, false, write_callback, read_callback, std::string("PhvEgressThreadImem")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_phv_egress_thread_imem_0) + "," + boost::lexical_cast<std::string>(index_phv_egress_thread_imem_1))
    {
    }
  PhvEgressThreadImem(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PhvEgressThreadImem")
    {
    }
public:
  uint8_t &phv_egress_thread_imem() { return phv_egress_thread_imem_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = phv_egress_thread_imem_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    phv_egress_thread_imem_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    phv_egress_thread_imem_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PhvEgressThreadImem") + ":\n";
    r += indent_string + "  " + std::string("phv_egress_thread_imem") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(phv_egress_thread_imem_) ) + "\n";
    all_zeros &= (0 == phv_egress_thread_imem_);
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
    r += indent_string + std::string("PhvEgressThreadImem") + ":\n";
    r += indent_string + "  " + std::string("phv_egress_thread_imem") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(phv_egress_thread_imem_) ) + "\n";
    all_zeros &= (0 == phv_egress_thread_imem_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t phv_egress_thread_imem_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_phv_egress_thread_imem_0, int index_phv_egress_thread_imem_1
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to dp
    offset += 0x10080; // to get to phv_egress_thread_imem
    assert(index_phv_egress_thread_imem_0 < 2);
    offset += index_phv_egress_thread_imem_0 * 0x40; // phv_egress_thread_imem[]
    assert(index_phv_egress_thread_imem_1 < 14);
    offset += index_phv_egress_thread_imem_1 * 0x4; // phv_egress_thread_imem[][]
    return offset;
  }

};













  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PHV_EGRESS_THREAD_IMEM_H__
