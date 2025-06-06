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
#ifndef __REGISTER_INCLUDES_DEF_METER_SBE_ERRLOG_MUTABLE_H__
#define __REGISTER_INCLUDES_DEF_METER_SBE_ERRLOG_MUTABLE_H__


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

class DefMeterSbeErrlogMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  DefMeterSbeErrlogMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_def_meter_sbe_errlog, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_def_meter_sbe_errlog), 4, true, write_callback, read_callback, std::string("DefMeterSbeErrlogMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_def_meter_sbe_errlog))
    {
    }
  DefMeterSbeErrlogMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DefMeterSbeErrlogMutable")
    {
    }
public:


  uint8_t def_sbe_errlog_addr() { return def_sbe_errlog_addr_; }
  void def_sbe_errlog_addr(const uint8_t &v) { def_sbe_errlog_addr_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = def_sbe_errlog_addr_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    def_sbe_errlog_addr_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    def_sbe_errlog_addr_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DefMeterSbeErrlogMutable") + ":\n";
    r += indent_string + "  " + std::string("def_sbe_errlog_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(def_sbe_errlog_addr_) ) + "\n";
    all_zeros &= (0 == def_sbe_errlog_addr_);
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
    r += indent_string + std::string("DefMeterSbeErrlogMutable") + ":\n";
    r += indent_string + "  " + std::string("def_sbe_errlog_addr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(def_sbe_errlog_addr_) ) + "\n";
    all_zeros &= (0 == def_sbe_errlog_addr_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t def_sbe_errlog_addr_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_def_meter_sbe_errlog
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x18000; // to get to match
    offset += 0x1c0; // to get to def_meter_sbe_errlog
    assert(index_def_meter_sbe_errlog < 4);
    offset += index_def_meter_sbe_errlog * 0x4; // def_meter_sbe_errlog[]
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_DEF_METER_SBE_ERRLOG_MUTABLE_H__
