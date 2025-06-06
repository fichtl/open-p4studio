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
#ifndef __REGISTER_INCLUDES_QAC_PORT_RX_DISABLE_MUTABLE_H__
#define __REGISTER_INCLUDES_QAC_PORT_RX_DISABLE_MUTABLE_H__


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

class QacPortRxDisableMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  QacPortRxDisableMutable(
      int chipNumber, int index_tm_qac_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_qac_pipe_rspec), 12, true, write_callback, read_callback, std::string("QacPortRxDisableMutable")+":"+boost::lexical_cast<std::string>(index_tm_qac_pipe_rspec))
    {
    }
  QacPortRxDisableMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "QacPortRxDisableMutable")
    {
    }
public:






  uint64_t rx_dis0() { return rx_dis0_; }
  void rx_dis0(const uint64_t &v) { rx_dis0_=v; }






  uint64_t rx_dis1() { return rx_dis1_; }
  void rx_dis1(const uint64_t &v) { rx_dis1_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (rx_dis0_ & 0xffffffff);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = ((rx_dis0_ & UINT64_C(0xf00000000)) >> 32);
      *data |= ((rx_dis1_ & 0xfffffff) << 4);
    }
    else if (offset >= 0x8 && offset < 0xc) {
      if (read_callback_) read_callback_();
      *data = ((rx_dis1_ & UINT64_C(0xff0000000)) >> 28);
    }
    else {
      assert(0);
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      rx_dis0_ = ((static_cast<uint64_t>(data) & 0xffffffff) | (rx_dis0_ & UINT64_C(0xf00000000)));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      rx_dis0_ = (((static_cast<uint64_t>(data) << 32) & UINT64_C(0xf00000000)) | (rx_dis0_ & 0xffffffff));
      rx_dis1_ = (((static_cast<uint64_t>(data) >> 4) & 0xfffffff) | (rx_dis1_ & UINT64_C(0xff0000000)));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      rx_dis1_ = (((static_cast<uint64_t>(data) << 28) & UINT64_C(0xff0000000)) | (rx_dis1_ & 0xfffffff));
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    rx_dis0_ = UINT64_C(0x0);
    rx_dis1_ = UINT64_C(0x0);
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("QacPortRxDisableMutable") + ":\n";
    r += indent_string + "  " + std::string("rx_dis0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rx_dis0_) ) + "\n";
    all_zeros &= (0 == rx_dis0_);
    r += indent_string + "  " + std::string("rx_dis1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rx_dis1_) ) + "\n";
    all_zeros &= (0 == rx_dis1_);
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
    r += indent_string + std::string("QacPortRxDisableMutable") + ":\n";
    r += indent_string + "  " + std::string("rx_dis0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rx_dis0_) ) + "\n";
    all_zeros &= (0 == rx_dis0_);
    r += indent_string + "  " + std::string("rx_dis1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rx_dis1_) ) + "\n";
    all_zeros &= (0 == rx_dis1_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint64_t rx_dis0_;
  uint64_t rx_dis1_;
private:
  static int StartOffset(
      int index_tm_qac_pipe_rspec
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0x80000; // to get to tm_qac_top
    assert(index_tm_qac_pipe_rspec < 4);
    offset += index_tm_qac_pipe_rspec * 0x8000; // tm_qac_pipe_rspec[]
    offset += 0x7030; // to get to qac_reg_qac_port_rx_disable
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_QAC_PORT_RX_DISABLE_MUTABLE_H__
