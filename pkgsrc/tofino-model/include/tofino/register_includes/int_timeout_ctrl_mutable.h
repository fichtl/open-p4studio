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
#ifndef __REGISTER_INCLUDES_INT_TIMEOUT_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_INT_TIMEOUT_CTRL_MUTABLE_H__


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

class IntTimeoutCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  IntTimeoutCtrlMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, true, write_callback, read_callback, std::string("IntTimeoutCtrlMutable"))
    {
    }
  IntTimeoutCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "IntTimeoutCtrlMutable")
    {
    }
public:






  uint16_t dma_int_timeout() { return dma_int_timeout_; }
  void dma_int_timeout(const uint16_t &v) { dma_int_timeout_=v; }






  uint8_t dma_ena_timeout() { return dma_ena_timeout_; }
  void dma_ena_timeout(const uint8_t &v) { dma_ena_timeout_=v; }








  uint16_t cpu_int_timeout() { return cpu_int_timeout_; }
  void cpu_int_timeout(const uint16_t &v) { cpu_int_timeout_=v; }






  uint8_t cpu_ena_timeout() { return cpu_ena_timeout_; }
  void cpu_ena_timeout(const uint8_t &v) { cpu_ena_timeout_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (dma_int_timeout_ & 0x7fff);
    *data |= ((dma_ena_timeout_ & 0x1) << 15);
    *data |= ((cpu_int_timeout_ & 0x7fff) << 16);
    *data |= ((cpu_ena_timeout_ & 0x1) << 31);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    dma_int_timeout_ = (data & 0x7fff);
    dma_ena_timeout_ = ((data >> 15) & 0x1);
    cpu_int_timeout_ = ((data >> 16) & 0x7fff);
    cpu_ena_timeout_ = ((data >> 31) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    dma_int_timeout_ = 0x3e7;
    dma_ena_timeout_ = 0x1;
    cpu_int_timeout_ = 0x7fff;
    cpu_ena_timeout_ = 0x1;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("IntTimeoutCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("dma_int_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dma_int_timeout_) ) + "\n";
    all_zeros &= (0 == dma_int_timeout_);
    r += indent_string + "  " + std::string("dma_ena_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dma_ena_timeout_) ) + "\n";
    all_zeros &= (0 == dma_ena_timeout_);
    r += indent_string + "  " + std::string("cpu_int_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cpu_int_timeout_) ) + "\n";
    all_zeros &= (0 == cpu_int_timeout_);
    r += indent_string + "  " + std::string("cpu_ena_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cpu_ena_timeout_) ) + "\n";
    all_zeros &= (0 == cpu_ena_timeout_);
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
    r += indent_string + std::string("IntTimeoutCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("dma_int_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dma_int_timeout_) ) + "\n";
    all_zeros &= (0 == dma_int_timeout_);
    r += indent_string + "  " + std::string("dma_ena_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dma_ena_timeout_) ) + "\n";
    all_zeros &= (0 == dma_ena_timeout_);
    r += indent_string + "  " + std::string("cpu_int_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cpu_int_timeout_) ) + "\n";
    all_zeros &= (0 == cpu_int_timeout_);
    r += indent_string + "  " + std::string("cpu_ena_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cpu_ena_timeout_) ) + "\n";
    all_zeros &= (0 == cpu_ena_timeout_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t dma_int_timeout_;
  uint8_t dma_ena_timeout_;
  uint16_t cpu_int_timeout_;
  uint8_t cpu_ena_timeout_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x2c; // to get to pcie_regs_int_timeout_ctrl
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_INT_TIMEOUT_CTRL_MUTABLE_H__
