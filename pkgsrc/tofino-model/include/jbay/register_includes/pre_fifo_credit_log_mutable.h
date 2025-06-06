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
#ifndef __REGISTER_INCLUDES_PRE_FIFO_CREDIT_LOG_MUTABLE_H__
#define __REGISTER_INCLUDES_PRE_FIFO_CREDIT_LOG_MUTABLE_H__


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

class PreFifoCreditLogMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PreFifoCreditLogMutable(
      int chipNumber, int index_tm_pre_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_pre_pipe_rspec), 4, true, write_callback, read_callback, std::string("PreFifoCreditLogMutable")+":"+boost::lexical_cast<std::string>(index_tm_pre_pipe_rspec))
    {
    }
  PreFifoCreditLogMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PreFifoCreditLogMutable")
    {
    }
public:





  uint8_t l0_fifo_credit() { return l0_fifo_credit_; }
  void l0_fifo_credit(const uint8_t &v) { l0_fifo_credit_=v; }





  uint8_t l1_fifo_credit() { return l1_fifo_credit_; }
  void l1_fifo_credit(const uint8_t &v) { l1_fifo_credit_=v; }





  uint8_t l1l2_fifo_credit() { return l1l2_fifo_credit_; }
  void l1l2_fifo_credit(const uint8_t &v) { l1l2_fifo_credit_=v; }





  uint8_t l2_fifo_credit() { return l2_fifo_credit_; }
  void l2_fifo_credit(const uint8_t &v) { l2_fifo_credit_=v; }





  uint8_t l2_sel_fifo_credit() { return l2_sel_fifo_credit_; }
  void l2_sel_fifo_credit(const uint8_t &v) { l2_sel_fifo_credit_=v; }





  uint8_t l2_port_fifo_credit() { return l2_port_fifo_credit_; }
  void l2_port_fifo_credit(const uint8_t &v) { l2_port_fifo_credit_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (l0_fifo_credit_ & 0x1f);
    *data |= ((l1_fifo_credit_ & 0x3f) << 5);
    *data |= ((l1l2_fifo_credit_ & 0x1f) << 11);
    *data |= ((l2_fifo_credit_ & 0x1f) << 16);
    *data |= ((l2_sel_fifo_credit_ & 0xf) << 21);
    *data |= ((l2_port_fifo_credit_ & 0x1f) << 25);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    l0_fifo_credit_ = (data & 0x1f);
    l1_fifo_credit_ = ((data >> 5) & 0x3f);
    l1l2_fifo_credit_ = ((data >> 11) & 0x1f);
    l2_fifo_credit_ = ((data >> 16) & 0x1f);
    l2_sel_fifo_credit_ = ((data >> 21) & 0xf);
    l2_port_fifo_credit_ = ((data >> 25) & 0x1f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    l0_fifo_credit_ = 0x0;
    l1_fifo_credit_ = 0x0;
    l1l2_fifo_credit_ = 0x0;
    l2_fifo_credit_ = 0x0;
    l2_sel_fifo_credit_ = 0x0;
    l2_port_fifo_credit_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PreFifoCreditLogMutable") + ":\n";
    r += indent_string + "  " + std::string("l0_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l0_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l0_fifo_credit_);
    r += indent_string + "  " + std::string("l1_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l1_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l1_fifo_credit_);
    r += indent_string + "  " + std::string("l1l2_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l1l2_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l1l2_fifo_credit_);
    r += indent_string + "  " + std::string("l2_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l2_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l2_fifo_credit_);
    r += indent_string + "  " + std::string("l2_sel_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l2_sel_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l2_sel_fifo_credit_);
    r += indent_string + "  " + std::string("l2_port_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l2_port_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l2_port_fifo_credit_);
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
    r += indent_string + std::string("PreFifoCreditLogMutable") + ":\n";
    r += indent_string + "  " + std::string("l0_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l0_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l0_fifo_credit_);
    r += indent_string + "  " + std::string("l1_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l1_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l1_fifo_credit_);
    r += indent_string + "  " + std::string("l1l2_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l1l2_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l1l2_fifo_credit_);
    r += indent_string + "  " + std::string("l2_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l2_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l2_fifo_credit_);
    r += indent_string + "  " + std::string("l2_sel_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l2_sel_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l2_sel_fifo_credit_);
    r += indent_string + "  " + std::string("l2_port_fifo_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(l2_port_fifo_credit_) ) + "\n";
    all_zeros &= (0 == l2_port_fifo_credit_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t l0_fifo_credit_;
  uint8_t l1_fifo_credit_;
  uint8_t l1l2_fifo_credit_;
  uint8_t l2_fifo_credit_;
  uint8_t l2_sel_fifo_credit_;
  uint8_t l2_port_fifo_credit_;
private:
  static int StartOffset(
      int index_tm_pre_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x480000; // to get to tm_pre_top
    assert(index_tm_pre_pipe_rspec < 4);
    offset += index_tm_pre_pipe_rspec * 0x8000; // tm_pre_pipe_rspec[]
    offset += 0x180; // to get to credit_log
    return offset;
  }

};











  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PRE_FIFO_CREDIT_LOG_MUTABLE_H__
