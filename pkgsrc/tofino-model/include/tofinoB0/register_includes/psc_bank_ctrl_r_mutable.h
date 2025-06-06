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
#ifndef __REGISTER_INCLUDES_PSC_BANK_CTRL_R_MUTABLE_H__
#define __REGISTER_INCLUDES_PSC_BANK_CTRL_R_MUTABLE_H__


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

class PscBankCtrlRMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PscBankCtrlRMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 8, true, write_callback, read_callback, std::string("PscBankCtrlRMutable"))
    {
    }
  PscBankCtrlRMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PscBankCtrlRMutable")
    {
    }
public:




  uint16_t addr_freecnt() { return addr_freecnt_; }
  void addr_freecnt(const uint16_t &v) { addr_freecnt_=v; }




  uint16_t addr_usecnt() { return addr_usecnt_; }
  void addr_usecnt(const uint16_t &v) { addr_usecnt_=v; }




  uint16_t tailptr() { return tailptr_; }
  void tailptr(const uint16_t &v) { tailptr_=v; }




  uint16_t headptr() { return headptr_; }
  void headptr(const uint16_t &v) { headptr_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (addr_freecnt_ & 0xfff);
      *data |= ((addr_usecnt_ & 0xfff) << 12);
      *data |= ((tailptr_ & 0xff) << 24);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = ((tailptr_ & 0x700) >> 8);
      *data |= ((headptr_ & 0x7ff) << 3);
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
      addr_freecnt_ = (data & 0xfff);
      addr_usecnt_ = ((data >> 12) & 0xfff);
      tailptr_ = (((data >> 24) & 0xff) | (tailptr_ & 0x700));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      tailptr_ = (((data << 8) & 0x700) | (tailptr_ & 0xff));
      headptr_ = ((data >> 3) & 0x7ff);
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    addr_freecnt_ = 0x800;
    addr_usecnt_ = 0x0;
    tailptr_ = 0x0;
    headptr_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PscBankCtrlRMutable") + ":\n";
    r += indent_string + "  " + std::string("addr_freecnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_freecnt_) ) + "\n";
    all_zeros &= (0 == addr_freecnt_);
    r += indent_string + "  " + std::string("addr_usecnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_usecnt_) ) + "\n";
    all_zeros &= (0 == addr_usecnt_);
    r += indent_string + "  " + std::string("tailptr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tailptr_) ) + "\n";
    all_zeros &= (0 == tailptr_);
    r += indent_string + "  " + std::string("headptr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(headptr_) ) + "\n";
    all_zeros &= (0 == headptr_);
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
    r += indent_string + std::string("PscBankCtrlRMutable") + ":\n";
    r += indent_string + "  " + std::string("addr_freecnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_freecnt_) ) + "\n";
    all_zeros &= (0 == addr_freecnt_);
    r += indent_string + "  " + std::string("addr_usecnt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(addr_usecnt_) ) + "\n";
    all_zeros &= (0 == addr_usecnt_);
    r += indent_string + "  " + std::string("tailptr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tailptr_) ) + "\n";
    all_zeros &= (0 == tailptr_);
    r += indent_string + "  " + std::string("headptr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(headptr_) ) + "\n";
    all_zeros &= (0 == headptr_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t addr_freecnt_;
  uint16_t addr_usecnt_;
  uint16_t tailptr_;
  uint16_t headptr_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0x240000; // to get to tm_psc_top
    offset += 0x20000; // to get to psc_common
    offset += 0x3008; // to get to bank_indir_access_data
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PSC_BANK_CTRL_R_MUTABLE_H__
