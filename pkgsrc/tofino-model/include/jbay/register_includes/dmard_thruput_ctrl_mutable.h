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
#ifndef __REGISTER_INCLUDES_DMARD_THRUPUT_CTRL_MUTABLE_H__
#define __REGISTER_INCLUDES_DMARD_THRUPUT_CTRL_MUTABLE_H__


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

class DmardThruputCtrlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  DmardThruputCtrlMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, true, write_callback, read_callback, std::string("DmardThruputCtrlMutable"))
    {
    }
  DmardThruputCtrlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DmardThruputCtrlMutable")
    {
    }
public:





  uint16_t dmard_max_bytes() { return dmard_max_bytes_; }
  void dmard_max_bytes(const uint16_t &v) { dmard_max_bytes_=v; }





  uint8_t dmard_max_en() { return dmard_max_en_; }
  void dmard_max_en(const uint8_t &v) { dmard_max_en_=v; }








  uint8_t dmard_mot() { return dmard_mot_; }
  void dmard_mot(const uint8_t &v) { dmard_mot_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = dmard_max_bytes_;
    *data |= ((dmard_max_en_ & 0x1) << 16);
    *data |= (dmard_mot_ << 24);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    dmard_max_bytes_ = data;
    dmard_max_en_ = ((data >> 16) & 0x1);
    dmard_mot_ = (data >> 24);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    dmard_max_bytes_ = 0x0;
    dmard_max_en_ = 0x0;
    dmard_mot_ = 0x20;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DmardThruputCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("dmard_max_bytes") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dmard_max_bytes_) ) + "\n";
    all_zeros &= (0 == dmard_max_bytes_);
    r += indent_string + "  " + std::string("dmard_max_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dmard_max_en_) ) + "\n";
    all_zeros &= (0 == dmard_max_en_);
    r += indent_string + "  " + std::string("dmard_mot") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dmard_mot_) ) + "\n";
    all_zeros &= (0 == dmard_mot_);
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
    r += indent_string + std::string("DmardThruputCtrlMutable") + ":\n";
    r += indent_string + "  " + std::string("dmard_max_bytes") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dmard_max_bytes_) ) + "\n";
    all_zeros &= (0 == dmard_max_bytes_);
    r += indent_string + "  " + std::string("dmard_max_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dmard_max_en_) ) + "\n";
    all_zeros &= (0 == dmard_max_en_);
    r += indent_string + "  " + std::string("dmard_mot") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(dmard_mot_) ) + "\n";
    all_zeros &= (0 == dmard_mot_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t dmard_max_bytes_;
  uint8_t dmard_max_en_;
  uint8_t dmard_mot_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x28; // to get to dmard_thruput_ctrl
    return offset;
  }

};
















  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_DMARD_THRUPUT_CTRL_MUTABLE_H__
