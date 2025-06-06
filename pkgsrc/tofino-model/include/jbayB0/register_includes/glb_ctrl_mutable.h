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
#ifndef __REGISTER_INCLUDES_GLB_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_GLB_CTRL_MUTABLE_H__


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

class GlbCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  GlbCtrlMutable(
      int chipNumber, int index_pipe_addrmap, int index_ipb_prsr4_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ipb_prsr4_reg), 8, true, write_callback, read_callback, std::string("GlbCtrlMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ipb_prsr4_reg))
    {
    }
  GlbCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "GlbCtrlMutable")
    {
    }
public:





  uint8_t en_resubmit() { return en_resubmit_; }
  void en_resubmit(const uint8_t &v) { en_resubmit_=v; }







  uint8_t prsr_update() { return prsr_update_; }
  void prsr_update(const uint8_t &v) { prsr_update_=v; }





  uint8_t free_list_init() { return free_list_init_; }
  void free_list_init(const uint8_t &v) { free_list_init_=v; }





  uint8_t prsr_chnl_rst() { return prsr_chnl_rst_; }
  void prsr_chnl_rst(const uint8_t &v) { prsr_chnl_rst_=v; }






  uint32_t prsr_crd() { return prsr_crd_; }
  void prsr_crd(const uint32_t &v) { prsr_crd_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (en_resubmit_ & 0x1);
      *data |= ((prsr_update_ & 0xf) << 1);
      *data |= ((free_list_init_ & 0x1) << 5);
      *data |= ((prsr_chnl_rst_ & 0xf) << 6);
      *data |= ((prsr_crd_ & 0x3fffff) << 10);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = ((prsr_crd_ & 0xffc00000) >> 22);
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
      en_resubmit_ = (data & 0x1);
      prsr_update_ = ((data >> 1) & 0xf);
      free_list_init_ = ((data >> 5) & 0x1);
      prsr_chnl_rst_ = ((data >> 6) & 0xf);
      prsr_crd_ = (((data >> 10) & 0x3fffff) | (prsr_crd_ & 0xffc00000));
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      prsr_crd_ = (((data << 22) & 0xffc00000) | (prsr_crd_ & 0x3fffff));
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    en_resubmit_ = 0x1;
    prsr_update_ = 0x0;
    free_list_init_ = 0x0;
    prsr_chnl_rst_ = 0x0;
    prsr_crd_ = 0x88888888;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("GlbCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("en_resubmit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en_resubmit_) ) + "\n";
    all_zeros &= (0 == en_resubmit_);
    r += indent_string + "  " + std::string("prsr_update") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_update_) ) + "\n";
    all_zeros &= (0 == prsr_update_);
    r += indent_string + "  " + std::string("free_list_init") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(free_list_init_) ) + "\n";
    all_zeros &= (0 == free_list_init_);
    r += indent_string + "  " + std::string("prsr_chnl_rst") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_chnl_rst_) ) + "\n";
    all_zeros &= (0 == prsr_chnl_rst_);
    r += indent_string + "  " + std::string("prsr_crd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_crd_) ) + "\n";
    all_zeros &= (0 == prsr_crd_);
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
    r += indent_string + std::string("GlbCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("en_resubmit") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en_resubmit_) ) + "\n";
    all_zeros &= (0 == en_resubmit_);
    r += indent_string + "  " + std::string("prsr_update") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_update_) ) + "\n";
    all_zeros &= (0 == prsr_update_);
    r += indent_string + "  " + std::string("free_list_init") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(free_list_init_) ) + "\n";
    all_zeros &= (0 == free_list_init_);
    r += indent_string + "  " + std::string("prsr_chnl_rst") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_chnl_rst_) ) + "\n";
    all_zeros &= (0 == prsr_chnl_rst_);
    r += indent_string + "  " + std::string("prsr_crd") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_crd_) ) + "\n";
    all_zeros &= (0 == prsr_crd_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t en_resubmit_;
  uint8_t prsr_update_;
  uint8_t free_list_init_;
  uint8_t prsr_chnl_rst_;
  uint32_t prsr_crd_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ipb_prsr4_reg
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    assert(index_ipb_prsr4_reg < 9);
    offset += index_ipb_prsr4_reg * 0x2000; // ipb_prsr4_reg[]
    offset += 0x20; // to get to glb_group_glb_ctrl
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_GLB_CTRL_MUTABLE_H__
