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
#ifndef __REGISTER_INCLUDES_ACC_CTRL_H__
#define __REGISTER_INCLUDES_ACC_CTRL_H__


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

class AccCtrl : public model_core::RegisterBlock<RegisterCallback> {
public:
  AccCtrl(
      int chipNumber, int index_pipe_addrmap, int index_ipb_prsr4_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ipb_prsr4_reg), 4, false, write_callback, read_callback, std::string("AccCtrl")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ipb_prsr4_reg))
    {
    }
  AccCtrl(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "AccCtrl")
    {
    }
public:






  uint16_t &glb_share() { return glb_share_; }






  uint16_t &glb_share_congest_thr() { return glb_share_congest_thr_; }






  uint16_t &glb_share_congest_hys() { return glb_share_congest_hys_; }





  uint8_t &clear_glb_share_max() { return clear_glb_share_max_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (glb_share_ & 0x3ff);
    *data |= ((glb_share_congest_thr_ & 0x3ff) << 10);
    *data |= ((glb_share_congest_hys_ & 0x3ff) << 20);
    *data |= ((clear_glb_share_max_ & 0x1) << 30);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    glb_share_ = (data & 0x3ff);
    glb_share_congest_thr_ = ((data >> 10) & 0x3ff);
    glb_share_congest_hys_ = ((data >> 20) & 0x3ff);
    clear_glb_share_max_ = ((data >> 30) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    glb_share_ = 0x0;
    glb_share_congest_thr_ = 0x0;
    glb_share_congest_hys_ = 0x0;
    clear_glb_share_max_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("AccCtrl") + ":\n";
    r += indent_string + "  " + std::string("glb_share") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(glb_share_) ) + "\n";
    all_zeros &= (0 == glb_share_);
    r += indent_string + "  " + std::string("glb_share_congest_thr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(glb_share_congest_thr_) ) + "\n";
    all_zeros &= (0 == glb_share_congest_thr_);
    r += indent_string + "  " + std::string("glb_share_congest_hys") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(glb_share_congest_hys_) ) + "\n";
    all_zeros &= (0 == glb_share_congest_hys_);
    r += indent_string + "  " + std::string("clear_glb_share_max") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(clear_glb_share_max_) ) + "\n";
    all_zeros &= (0 == clear_glb_share_max_);
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
    r += indent_string + std::string("AccCtrl") + ":\n";
    r += indent_string + "  " + std::string("glb_share") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(glb_share_) ) + "\n";
    all_zeros &= (0 == glb_share_);
    r += indent_string + "  " + std::string("glb_share_congest_thr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(glb_share_congest_thr_) ) + "\n";
    all_zeros &= (0 == glb_share_congest_thr_);
    r += indent_string + "  " + std::string("glb_share_congest_hys") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(glb_share_congest_hys_) ) + "\n";
    all_zeros &= (0 == glb_share_congest_hys_);
    r += indent_string + "  " + std::string("clear_glb_share_max") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(clear_glb_share_max_) ) + "\n";
    all_zeros &= (0 == clear_glb_share_max_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t glb_share_;
  uint16_t glb_share_congest_thr_;
  uint16_t glb_share_congest_hys_;
  uint8_t clear_glb_share_max_;
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
    offset += 0x28; // to get to glb_group_acc_ctrl
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_ACC_CTRL_H__
