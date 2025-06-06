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
#ifndef __REGISTER_INCLUDES_CBUS_PRI_CTRL_H__
#define __REGISTER_INCLUDES_CBUS_PRI_CTRL_H__


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

class CbusPriCtrl : public model_core::RegisterBlock<RegisterCallback> {
public:
  CbusPriCtrl(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, false, write_callback, read_callback, std::string("CbusPriCtrl"))
    {
    }
  CbusPriCtrl(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "CbusPriCtrl")
    {
    }
public:





  uint8_t &wl_req_pri0() { return wl_req_pri0_; }





  uint8_t &wl_req_pri1() { return wl_req_pri1_; }





  uint8_t &rb_req_pri0() { return rb_req_pri0_; }





  uint8_t &rb_req_pri1() { return rb_req_pri1_; }





  uint8_t &lq_req_pri() { return lq_req_pri_; }





  uint8_t &int_req_pri() { return int_req_pri_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (wl_req_pri0_ & 0x1);
    *data |= ((wl_req_pri1_ & 0x1) << 1);
    *data |= ((rb_req_pri0_ & 0x1) << 2);
    *data |= ((rb_req_pri1_ & 0x1) << 3);
    *data |= ((lq_req_pri_ & 0x1) << 4);
    *data |= ((int_req_pri_ & 0x1) << 5);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    wl_req_pri0_ = (data & 0x1);
    wl_req_pri1_ = ((data >> 1) & 0x1);
    rb_req_pri0_ = ((data >> 2) & 0x1);
    rb_req_pri1_ = ((data >> 3) & 0x1);
    lq_req_pri_ = ((data >> 4) & 0x1);
    int_req_pri_ = ((data >> 5) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    wl_req_pri0_ = 0x0;
    wl_req_pri1_ = 0x0;
    rb_req_pri0_ = 0x0;
    rb_req_pri1_ = 0x0;
    lq_req_pri_ = 0x0;
    int_req_pri_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("CbusPriCtrl") + ":\n";
    r += indent_string + "  " + std::string("wl_req_pri0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_req_pri0_) ) + "\n";
    all_zeros &= (0 == wl_req_pri0_);
    r += indent_string + "  " + std::string("wl_req_pri1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_req_pri1_) ) + "\n";
    all_zeros &= (0 == wl_req_pri1_);
    r += indent_string + "  " + std::string("rb_req_pri0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_req_pri0_) ) + "\n";
    all_zeros &= (0 == rb_req_pri0_);
    r += indent_string + "  " + std::string("rb_req_pri1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_req_pri1_) ) + "\n";
    all_zeros &= (0 == rb_req_pri1_);
    r += indent_string + "  " + std::string("lq_req_pri") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_req_pri_) ) + "\n";
    all_zeros &= (0 == lq_req_pri_);
    r += indent_string + "  " + std::string("int_req_pri") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(int_req_pri_) ) + "\n";
    all_zeros &= (0 == int_req_pri_);
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
    r += indent_string + std::string("CbusPriCtrl") + ":\n";
    r += indent_string + "  " + std::string("wl_req_pri0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_req_pri0_) ) + "\n";
    all_zeros &= (0 == wl_req_pri0_);
    r += indent_string + "  " + std::string("wl_req_pri1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wl_req_pri1_) ) + "\n";
    all_zeros &= (0 == wl_req_pri1_);
    r += indent_string + "  " + std::string("rb_req_pri0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_req_pri0_) ) + "\n";
    all_zeros &= (0 == rb_req_pri0_);
    r += indent_string + "  " + std::string("rb_req_pri1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rb_req_pri1_) ) + "\n";
    all_zeros &= (0 == rb_req_pri1_);
    r += indent_string + "  " + std::string("lq_req_pri") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lq_req_pri_) ) + "\n";
    all_zeros &= (0 == lq_req_pri_);
    r += indent_string + "  " + std::string("int_req_pri") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(int_req_pri_) ) + "\n";
    all_zeros &= (0 == int_req_pri_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t wl_req_pri0_;
  uint8_t wl_req_pri1_;
  uint8_t rb_req_pri0_;
  uint8_t rb_req_pri1_;
  uint8_t lq_req_pri_;
  uint8_t int_req_pri_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x280000; // to get to cbc
    offset += 0x20; // to get to pri_ctrl
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_CBUS_PRI_CTRL_H__
