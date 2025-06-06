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
#ifndef __REGISTER_INCLUDES_QCLC_PIPE_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_QCLC_PIPE_CTRL_MUTABLE_H__


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

class QclcPipeCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  QclcPipeCtrlMutable(
      int chipNumber, int index_tm_clc_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_clc_pipe_rspec), 4, true, write_callback, read_callback, std::string("QclcPipeCtrlMutable")+":"+boost::lexical_cast<std::string>(index_tm_clc_pipe_rspec))
    {
    }
  QclcPipeCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "QclcPipeCtrlMutable")
    {
    }
public:





  uint8_t dod_400g_mode() { return dod_400g_mode_; }
  void dod_400g_mode(const uint8_t &v) { dod_400g_mode_=v; }





  uint8_t mem_init_en() { return mem_init_en_; }
  void mem_init_en(const uint8_t &v) { mem_init_en_=v; }





  uint8_t freeze_on_error() { return freeze_on_error_; }
  void freeze_on_error(const uint8_t &v) { freeze_on_error_=v; }





  uint8_t ecc_dis() { return ecc_dis_; }
  void ecc_dis(const uint8_t &v) { ecc_dis_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = ((dod_400g_mode_ & 0x1) << 28);
    *data |= ((mem_init_en_ & 0x1) << 29);
    *data |= ((freeze_on_error_ & 0x1) << 30);
    *data |= ((ecc_dis_ & 0x1) << 31);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    dod_400g_mode_ = ((data >> 28) & 0x1);
    mem_init_en_ = ((data >> 29) & 0x1);
    freeze_on_error_ = ((data >> 30) & 0x1);
    ecc_dis_ = ((data >> 31) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    dod_400g_mode_ = 0x0;
    mem_init_en_ = 0x0;
    freeze_on_error_ = 0x0;
    ecc_dis_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("QclcPipeCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("dod_400g_mode") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dod_400g_mode_) ) + "\n";
    all_zeros &= (0 == dod_400g_mode_);
    r += indent_string + "  " + std::string("mem_init_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mem_init_en_) ) + "\n";
    all_zeros &= (0 == mem_init_en_);
    r += indent_string + "  " + std::string("freeze_on_error") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(freeze_on_error_) ) + "\n";
    all_zeros &= (0 == freeze_on_error_);
    r += indent_string + "  " + std::string("ecc_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ecc_dis_) ) + "\n";
    all_zeros &= (0 == ecc_dis_);
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
    r += indent_string + std::string("QclcPipeCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("dod_400g_mode") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dod_400g_mode_) ) + "\n";
    all_zeros &= (0 == dod_400g_mode_);
    r += indent_string + "  " + std::string("mem_init_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mem_init_en_) ) + "\n";
    all_zeros &= (0 == mem_init_en_);
    r += indent_string + "  " + std::string("freeze_on_error") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(freeze_on_error_) ) + "\n";
    all_zeros &= (0 == freeze_on_error_);
    r += indent_string + "  " + std::string("ecc_dis") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ecc_dis_) ) + "\n";
    all_zeros &= (0 == ecc_dis_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t dod_400g_mode_;
  uint8_t mem_init_en_;
  uint8_t freeze_on_error_;
  uint8_t ecc_dis_;
private:
  static int StartOffset(
      int index_tm_clc_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x280000; // to get to tm_clc_top
    assert(index_tm_clc_pipe_rspec < 4);
    offset += index_tm_clc_pipe_rspec * 0x4000; // tm_clc_pipe_rspec[]
    offset += 0x4; // to get to pipe_ctrl
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_QCLC_PIPE_CTRL_MUTABLE_H__
