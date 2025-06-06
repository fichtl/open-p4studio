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
#ifndef __REGISTER_INCLUDES_PBUS_DIAG_VALUE_MUTABLE_H__
#define __REGISTER_INCLUDES_PBUS_DIAG_VALUE_MUTABLE_H__


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

class PbusDiagValueMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PbusDiagValueMutable(
      int chipNumber, int index_pbus_diag_value, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pbus_diag_value), 4, true, write_callback, read_callback, std::string("PbusDiagValueMutable")+":"+boost::lexical_cast<std::string>(index_pbus_diag_value))
    {
    }
  PbusDiagValueMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PbusDiagValueMutable")
    {
    }
public:





  uint32_t edge() { return edge_; }
  void edge(const uint32_t &v) { edge_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (edge_ & 0x1ffff);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    edge_ = (data & 0x1ffff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    edge_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PbusDiagValueMutable") + ":\n";
    r += indent_string + "  " + std::string("edge") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(edge_) ) + "\n";
    all_zeros &= (0 == edge_);
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
    r += indent_string + std::string("PbusDiagValueMutable") + ":\n";
    r += indent_string + "  " + std::string("edge") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(edge_) ) + "\n";
    all_zeros &= (0 == edge_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t edge_;
private:
  static int StartOffset(
      int index_pbus_diag_value
      ) {
    int offset=0;
    offset += 0x100000; // to get to pbc
    offset += 0xb0; // to get to diag_value
    assert(index_pbus_diag_value < 4);
    offset += index_pbus_diag_value * 0x4; // pbus_diag_value[]
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_PBUS_DIAG_VALUE_MUTABLE_H__
