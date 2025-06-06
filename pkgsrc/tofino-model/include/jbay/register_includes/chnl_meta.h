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
#ifndef __REGISTER_INCLUDES_CHNL_META_H__
#define __REGISTER_INCLUDES_CHNL_META_H__


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

class ChnlMeta : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum IpbRspecEnum {
    kChan0Group,
    kChan1Group,
    kChan2Group,
    kChan3Group,
    kChan4Group,
    kChan5Group,
    kChan6Group,
    kChan7Group
  };
public:
  ChnlMeta(
      int chipNumber, int index_pipe_addrmap, int index_ipb_prsr4_reg, IpbRspecEnum selector_ipb_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ipb_prsr4_reg, selector_ipb_rspec), 16, false, write_callback, read_callback, std::string("ChnlMeta")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ipb_prsr4_reg) + "," + boost::lexical_cast<std::string>(selector_ipb_rspec))
    {
    }
  ChnlMeta(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "ChnlMeta")
    {
    }
public:





  uint32_t &meta1_0() { return meta1_0_; }





  uint32_t &meta1_1() { return meta1_1_; }





  uint32_t &meta1_2() { return meta1_2_; }





  uint32_t &meta1_3() { return meta1_3_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = meta1_0_;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = meta1_1_;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      if (read_callback_) read_callback_();
      *data = meta1_2_;
    }
    else if (offset >= 0xc && offset < 0x10) {
      if (read_callback_) read_callback_();
      *data = meta1_3_;
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
      meta1_0_ = data;
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      meta1_1_ = data;
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      meta1_2_ = data;
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      meta1_3_ = data;
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    meta1_0_ = 0x0;
    meta1_1_ = 0x0;
    meta1_2_ = 0x0;
    meta1_3_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("ChnlMeta") + ":\n";
    r += indent_string + "  " + std::string("meta1_0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_0_) ) + "\n";
    all_zeros &= (0 == meta1_0_);
    r += indent_string + "  " + std::string("meta1_1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_1_) ) + "\n";
    all_zeros &= (0 == meta1_1_);
    r += indent_string + "  " + std::string("meta1_2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_2_) ) + "\n";
    all_zeros &= (0 == meta1_2_);
    r += indent_string + "  " + std::string("meta1_3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_3_) ) + "\n";
    all_zeros &= (0 == meta1_3_);
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
    r += indent_string + std::string("ChnlMeta") + ":\n";
    r += indent_string + "  " + std::string("meta1_0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_0_) ) + "\n";
    all_zeros &= (0 == meta1_0_);
    r += indent_string + "  " + std::string("meta1_1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_1_) ) + "\n";
    all_zeros &= (0 == meta1_1_);
    r += indent_string + "  " + std::string("meta1_2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_2_) ) + "\n";
    all_zeros &= (0 == meta1_2_);
    r += indent_string + "  " + std::string("meta1_3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meta1_3_) ) + "\n";
    all_zeros &= (0 == meta1_3_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t meta1_0_;
  uint32_t meta1_1_;
  uint32_t meta1_2_;
  uint32_t meta1_3_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ipb_prsr4_reg, IpbRspecEnum selector_ipb_rspec
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    assert(index_ipb_prsr4_reg < 9);
    offset += index_ipb_prsr4_reg * 0x2000; // ipb_prsr4_reg[]
    switch (selector_ipb_rspec) {
      case kChan0Group:
        offset += 0x810; // to get to chan0_group_chnl_meta
        break;
      case kChan1Group:
        offset += 0x910; // to get to chan1_group_chnl_meta
        break;
      case kChan2Group:
        offset += 0xa10; // to get to chan2_group_chnl_meta
        break;
      case kChan3Group:
        offset += 0xb10; // to get to chan3_group_chnl_meta
        break;
      case kChan4Group:
        offset += 0xc10; // to get to chan4_group_chnl_meta
        break;
      case kChan5Group:
        offset += 0xd10; // to get to chan5_group_chnl_meta
        break;
      case kChan6Group:
        offset += 0xe10; // to get to chan6_group_chnl_meta
        break;
      case kChan7Group:
        offset += 0xf10; // to get to chan7_group_chnl_meta
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_CHNL_META_H__
