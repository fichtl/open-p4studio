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
#ifndef __REGISTER_INCLUDES_GATEWAY_INHIBIT_LUT_H__
#define __REGISTER_INCLUDES_GATEWAY_INHIBIT_LUT_H__


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

class GatewayInhibitLut : public model_core::RegisterBlock<RegisterCallback> {
public:
  GatewayInhibitLut(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_gateway_inhibit_lut, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_gateway_inhibit_lut), 4, false, write_callback, read_callback, std::string("GatewayInhibitLut")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_gateway_inhibit_lut))
    {
    }
  GatewayInhibitLut(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "GatewayInhibitLut")
    {
    }
public:
  uint8_t &gateway_inhibit_lut() { return gateway_inhibit_lut_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (gateway_inhibit_lut_ & 0x1f);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    gateway_inhibit_lut_ = (data & 0x1f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    gateway_inhibit_lut_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("GatewayInhibitLut") + ":\n";
    r += indent_string + "  " + std::string("gateway_inhibit_lut") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gateway_inhibit_lut_) ) + "\n";
    all_zeros &= (0 == gateway_inhibit_lut_);
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
    r += indent_string + std::string("GatewayInhibitLut") + ":\n";
    r += indent_string + "  " + std::string("gateway_inhibit_lut") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gateway_inhibit_lut_) ) + "\n";
    all_zeros &= (0 == gateway_inhibit_lut_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t gateway_inhibit_lut_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_gateway_inhibit_lut
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    offset += 0x18000; // to get to match
    offset += 0x4000; // to get to merge
    offset += 0x180; // to get to gateway_inhibit_lut
    assert(index_gateway_inhibit_lut < 16);
    offset += index_gateway_inhibit_lut * 0x4; // gateway_inhibit_lut[]
    return offset;
  }

};















  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_GATEWAY_INHIBIT_LUT_H__
