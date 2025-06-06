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
#ifndef __REGISTER_INCLUDES_CBUS_DMA_LOG_MUTABLE_H__
#define __REGISTER_INCLUDES_CBUS_DMA_LOG_MUTABLE_H__


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

class CbusDmaLogMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  CbusDmaLogMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 12, true, write_callback, read_callback, std::string("CbusDmaLogMutable"))
    {
    }
  CbusDmaLogMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "CbusDmaLogMutable")
    {
    }
public:







  uint8_t wl_read_statemachine(int j0) { return wl_read_statemachine_[j0]; }
  void wl_read_statemachine(int j0,const uint8_t &v) { wl_read_statemachine_[j0]=v; }







  uint8_t wl_write_statemachine(int j0) { return wl_write_statemachine_[j0]; }
  void wl_write_statemachine(int j0,const uint8_t &v) { wl_write_statemachine_[j0]=v; }







  uint16_t wl_data_credit(int j0) { return wl_data_credit_[j0]; }
  void wl_data_credit(int j0,const uint16_t &v) { wl_data_credit_[j0]=v; }







  uint8_t rb_read_statemachine(int j0) { return rb_read_statemachine_[j0]; }
  void rb_read_statemachine(int j0,const uint8_t &v) { rb_read_statemachine_[j0]=v; }







  uint8_t rb_write_statemachine(int j0) { return rb_write_statemachine_[j0]; }
  void rb_write_statemachine(int j0,const uint8_t &v) { rb_write_statemachine_[j0]=v; }







  uint16_t rb_data_credit(int j0) { return rb_data_credit_[j0]; }
  void rb_data_credit(int j0,const uint16_t &v) { rb_data_credit_[j0]=v; }







  uint16_t rb_resp_credit(int j0) { return rb_resp_credit_[j0]; }
  void rb_resp_credit(int j0,const uint16_t &v) { rb_resp_credit_[j0]=v; }







  uint8_t rb_req_mem_credit(int j0) { return rb_req_mem_credit_[j0]; }
  void rb_req_mem_credit(int j0,const uint8_t &v) { rb_req_mem_credit_[j0]=v; }





  uint8_t lq_write_statemachine() { return lq_write_statemachine_; }
  void lq_write_statemachine(const uint8_t &v) { lq_write_statemachine_=v; }





  uint8_t lq_req_mem_credit() { return lq_req_mem_credit_; }
  void lq_req_mem_credit(const uint8_t &v) { lq_req_mem_credit_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (wl_read_statemachine_[0] & 0x1);
      *data |= ((wl_read_statemachine_[1] & 0x1) << 1);
      *data |= ((wl_write_statemachine_[0] & 0x7) << 2);
      *data |= ((wl_write_statemachine_[1] & 0x7) << 5);
      *data |= ((wl_data_credit_[0] & 0x1ff) << 8);
      *data |= ((wl_data_credit_[1] & 0x1ff) << 17);
      *data |= ((rb_read_statemachine_[0] & 0x1) << 26);
      *data |= ((rb_read_statemachine_[1] & 0x1) << 27);
      *data |= ((rb_write_statemachine_[0] & 0x7) << 28);
      *data |= ((rb_write_statemachine_[1] & 0x1) << 31);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = ((rb_write_statemachine_[1] & 0x6) >> 1);
      *data |= ((rb_data_credit_[0] & 0x1ff) << 2);
      *data |= ((rb_data_credit_[1] & 0x1ff) << 11);
      *data |= ((rb_resp_credit_[0] & 0x1ff) << 20);
      *data |= ((rb_resp_credit_[1] & 0x7) << 29);
    }
    else if (offset >= 0x8 && offset < 0xc) {
      if (read_callback_) read_callback_();
      *data = ((rb_resp_credit_[1] & 0x1f8) >> 3);
      *data |= ((rb_req_mem_credit_[0] & 0x7) << 6);
      *data |= ((rb_req_mem_credit_[1] & 0x7) << 9);
      *data |= ((lq_write_statemachine_ & 0x7) << 12);
      *data |= ((lq_req_mem_credit_ & 0x7) << 15);
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
      wl_read_statemachine_[0] = (data & 0x1);
      wl_read_statemachine_[1] = ((data >> 1) & 0x1);
      wl_write_statemachine_[0] = ((data >> 2) & 0x7);
      wl_write_statemachine_[1] = ((data >> 5) & 0x7);
      wl_data_credit_[0] = ((data >> 8) & 0x1ff);
      wl_data_credit_[1] = ((data >> 17) & 0x1ff);
      rb_read_statemachine_[0] = ((data >> 26) & 0x1);
      rb_read_statemachine_[1] = ((data >> 27) & 0x1);
      rb_write_statemachine_[0] = ((data >> 28) & 0x7);
      rb_write_statemachine_[1] = (((data >> 31) & 0x1) | (rb_write_statemachine_[1] & 0x6));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      rb_write_statemachine_[1] = (((data << 1) & 0x6) | (rb_write_statemachine_[1] & 0x1));
      rb_data_credit_[0] = ((data >> 2) & 0x1ff);
      rb_data_credit_[1] = ((data >> 11) & 0x1ff);
      rb_resp_credit_[0] = ((data >> 20) & 0x1ff);
      rb_resp_credit_[1] = (((data >> 29) & 0x7) | (rb_resp_credit_[1] & 0x1f8));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      rb_resp_credit_[1] = (((data << 3) & 0x1f8) | (rb_resp_credit_[1] & 0x7));
      rb_req_mem_credit_[0] = ((data >> 6) & 0x7);
      rb_req_mem_credit_[1] = ((data >> 9) & 0x7);
      lq_write_statemachine_ = ((data >> 12) & 0x7);
      lq_req_mem_credit_ = ((data >> 15) & 0x7);
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    wl_read_statemachine_[0] = 0x0;
    wl_read_statemachine_[1] = 0x0;
    wl_write_statemachine_[0] = 0x0;
    wl_write_statemachine_[1] = 0x0;
    wl_data_credit_[0] = 0x0;
    wl_data_credit_[1] = 0x0;
    rb_read_statemachine_[0] = 0x0;
    rb_read_statemachine_[1] = 0x0;
    rb_write_statemachine_[0] = 0x0;
    rb_write_statemachine_[1] = 0x0;
    rb_data_credit_[0] = 0x0;
    rb_data_credit_[1] = 0x0;
    rb_resp_credit_[0] = 0x0;
    rb_resp_credit_[1] = 0x0;
    rb_req_mem_credit_[0] = 0x0;
    rb_req_mem_credit_[1] = 0x0;
    lq_write_statemachine_ = 0x0;
    lq_req_mem_credit_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("CbusDmaLogMutable") + ":\n";
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("wl_read_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_read_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == wl_read_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("wl_write_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_write_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == wl_write_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("wl_data_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_data_credit_[f]) ) + "\n";
      all_zeros &= (0 == wl_data_credit_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_read_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_read_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == rb_read_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_write_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_write_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == rb_write_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_data_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_data_credit_[f]) ) + "\n";
      all_zeros &= (0 == rb_data_credit_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_resp_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_resp_credit_[f]) ) + "\n";
      all_zeros &= (0 == rb_resp_credit_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_req_mem_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_req_mem_credit_[f]) ) + "\n";
      all_zeros &= (0 == rb_req_mem_credit_[f]);
    }
    r += indent_string + "  " + std::string("lq_write_statemachine") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_write_statemachine_) ) + "\n";
    all_zeros &= (0 == lq_write_statemachine_);
    r += indent_string + "  " + std::string("lq_req_mem_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_req_mem_credit_) ) + "\n";
    all_zeros &= (0 == lq_req_mem_credit_);
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
    r += indent_string + std::string("CbusDmaLogMutable") + ":\n";
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("wl_read_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_read_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == wl_read_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("wl_write_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_write_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == wl_write_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("wl_data_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_data_credit_[f]) ) + "\n";
      all_zeros &= (0 == wl_data_credit_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_read_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_read_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == rb_read_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_write_statemachine") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_write_statemachine_[f]) ) + "\n";
      all_zeros &= (0 == rb_write_statemachine_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_data_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_data_credit_[f]) ) + "\n";
      all_zeros &= (0 == rb_data_credit_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_resp_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_resp_credit_[f]) ) + "\n";
      all_zeros &= (0 == rb_resp_credit_[f]);
    }
    for (uint32_t f=0;f<2;++f) {
      r += indent_string + "  " + std::string("rb_req_mem_credit") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_req_mem_credit_[f]) ) + "\n";
      all_zeros &= (0 == rb_req_mem_credit_[f]);
    }
    r += indent_string + "  " + std::string("lq_write_statemachine") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_write_statemachine_) ) + "\n";
    all_zeros &= (0 == lq_write_statemachine_);
    r += indent_string + "  " + std::string("lq_req_mem_credit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_req_mem_credit_) ) + "\n";
    all_zeros &= (0 == lq_req_mem_credit_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< uint8_t, 2 > wl_read_statemachine_;
  std::array< uint8_t, 2 > wl_write_statemachine_;
  std::array< uint16_t, 2 > wl_data_credit_;
  std::array< uint8_t, 2 > rb_read_statemachine_;
  std::array< uint8_t, 2 > rb_write_statemachine_;
  std::array< uint16_t, 2 > rb_data_credit_;
  std::array< uint16_t, 2 > rb_resp_credit_;
  std::array< uint8_t, 2 > rb_req_mem_credit_;
  uint8_t lq_write_statemachine_;
  uint8_t lq_req_mem_credit_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x280000; // to get to cbc
    offset += 0xe0; // to get to dma_log
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_CBUS_DMA_LOG_MUTABLE_H__
