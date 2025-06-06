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
#ifndef __REGISTER_INCLUDES_TM_CAA_CDM_RSPEC_ECC_H__
#define __REGISTER_INCLUDES_TM_CAA_CDM_RSPEC_ECC_H__


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

class TmCaaCdmRspecEcc : public model_core::RegisterBlock<RegisterCallback> {
public:
  TmCaaCdmRspecEcc(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 8, false, write_callback, read_callback, std::string("TmCaaCdmRspecEcc"))
    {
    }
  TmCaaCdmRspecEcc(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "TmCaaCdmRspecEcc")
    {
    }
public:




  uint8_t &pipe0_cell0_disable_check() { return pipe0_cell0_disable_check_; }




  uint8_t &pipe0_cell1_disable_check() { return pipe0_cell1_disable_check_; }




  uint8_t &pipe0_cell2_disable_check() { return pipe0_cell2_disable_check_; }




  uint8_t &pipe1_cell0_disable_check() { return pipe1_cell0_disable_check_; }




  uint8_t &pipe1_cell1_disable_check() { return pipe1_cell1_disable_check_; }




  uint8_t &pipe1_cell2_disable_check() { return pipe1_cell2_disable_check_; }




  uint8_t &pipe2_cell0_disable_check() { return pipe2_cell0_disable_check_; }




  uint8_t &pipe2_cell1_disable_check() { return pipe2_cell1_disable_check_; }




  uint8_t &pipe2_cell2_disable_check() { return pipe2_cell2_disable_check_; }




  uint8_t &pipe3_cell0_disable_check() { return pipe3_cell0_disable_check_; }




  uint8_t &pipe3_cell1_disable_check() { return pipe3_cell1_disable_check_; }




  uint8_t &pipe3_cell2_disable_check() { return pipe3_cell2_disable_check_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (pipe0_cell0_disable_check_ & 0x1);
      *data |= ((pipe0_cell1_disable_check_ & 0x1) << 4);
      *data |= ((pipe0_cell2_disable_check_ & 0x1) << 8);
      *data |= ((pipe1_cell0_disable_check_ & 0x1) << 12);
      *data |= ((pipe1_cell1_disable_check_ & 0x1) << 16);
      *data |= ((pipe1_cell2_disable_check_ & 0x1) << 20);
      *data |= ((pipe2_cell0_disable_check_ & 0x1) << 24);
      *data |= ((pipe2_cell1_disable_check_ & 0x1) << 28);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = (pipe2_cell2_disable_check_ & 0x1);
      *data |= ((pipe3_cell0_disable_check_ & 0x1) << 4);
      *data |= ((pipe3_cell1_disable_check_ & 0x1) << 8);
      *data |= ((pipe3_cell2_disable_check_ & 0x1) << 12);
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
      pipe0_cell0_disable_check_ = (data & 0x1);
      pipe0_cell1_disable_check_ = ((data >> 4) & 0x1);
      pipe0_cell2_disable_check_ = ((data >> 8) & 0x1);
      pipe1_cell0_disable_check_ = ((data >> 12) & 0x1);
      pipe1_cell1_disable_check_ = ((data >> 16) & 0x1);
      pipe1_cell2_disable_check_ = ((data >> 20) & 0x1);
      pipe2_cell0_disable_check_ = ((data >> 24) & 0x1);
      pipe2_cell1_disable_check_ = ((data >> 28) & 0x1);
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      pipe2_cell2_disable_check_ = (data & 0x1);
      pipe3_cell0_disable_check_ = ((data >> 4) & 0x1);
      pipe3_cell1_disable_check_ = ((data >> 8) & 0x1);
      pipe3_cell2_disable_check_ = ((data >> 12) & 0x1);
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    pipe0_cell0_disable_check_ = 0x0;
    pipe0_cell1_disable_check_ = 0x0;
    pipe0_cell2_disable_check_ = 0x0;
    pipe1_cell0_disable_check_ = 0x0;
    pipe1_cell1_disable_check_ = 0x0;
    pipe1_cell2_disable_check_ = 0x0;
    pipe2_cell0_disable_check_ = 0x0;
    pipe2_cell1_disable_check_ = 0x0;
    pipe2_cell2_disable_check_ = 0x0;
    pipe3_cell0_disable_check_ = 0x0;
    pipe3_cell1_disable_check_ = 0x0;
    pipe3_cell2_disable_check_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("TmCaaCdmRspecEcc") + ":\n";
    r += indent_string + "  " + std::string("pipe0_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe0_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe0_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe0_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe0_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe0_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe0_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe0_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe0_cell2_disable_check_);
    r += indent_string + "  " + std::string("pipe1_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe1_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe1_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe1_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe1_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe1_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe1_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe1_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe1_cell2_disable_check_);
    r += indent_string + "  " + std::string("pipe2_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe2_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe2_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe2_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe2_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe2_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe2_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe2_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe2_cell2_disable_check_);
    r += indent_string + "  " + std::string("pipe3_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe3_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe3_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe3_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe3_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe3_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe3_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe3_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe3_cell2_disable_check_);
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
    r += indent_string + std::string("TmCaaCdmRspecEcc") + ":\n";
    r += indent_string + "  " + std::string("pipe0_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe0_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe0_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe0_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe0_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe0_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe0_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe0_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe0_cell2_disable_check_);
    r += indent_string + "  " + std::string("pipe1_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe1_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe1_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe1_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe1_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe1_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe1_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe1_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe1_cell2_disable_check_);
    r += indent_string + "  " + std::string("pipe2_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe2_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe2_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe2_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe2_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe2_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe2_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe2_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe2_cell2_disable_check_);
    r += indent_string + "  " + std::string("pipe3_cell0_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe3_cell0_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe3_cell0_disable_check_);
    r += indent_string + "  " + std::string("pipe3_cell1_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe3_cell1_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe3_cell1_disable_check_);
    r += indent_string + "  " + std::string("pipe3_cell2_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pipe3_cell2_disable_check_) ) + "\n";
    all_zeros &= (0 == pipe3_cell2_disable_check_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t pipe0_cell0_disable_check_;
  uint8_t pipe0_cell1_disable_check_;
  uint8_t pipe0_cell2_disable_check_;
  uint8_t pipe1_cell0_disable_check_;
  uint8_t pipe1_cell1_disable_check_;
  uint8_t pipe1_cell2_disable_check_;
  uint8_t pipe2_cell0_disable_check_;
  uint8_t pipe2_cell1_disable_check_;
  uint8_t pipe2_cell2_disable_check_;
  uint8_t pipe3_cell0_disable_check_;
  uint8_t pipe3_cell1_disable_check_;
  uint8_t pipe3_cell2_disable_check_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0x40000; // to get to tm_caa
    offset += 0x20000; // to get to cdm
    offset += 0x8; // to get to ecc
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_TM_CAA_CDM_RSPEC_ECC_H__
