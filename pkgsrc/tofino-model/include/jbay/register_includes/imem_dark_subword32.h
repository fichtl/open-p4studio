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
#ifndef __REGISTER_INCLUDES_IMEM_DARK_SUBWORD32_H__
#define __REGISTER_INCLUDES_IMEM_DARK_SUBWORD32_H__


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

class ImemDarkSubword32 : public model_core::RegisterBlock<RegisterCallback> {
public:
  ImemDarkSubword32(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_imem_dark_subword32_0, int index_imem_dark_subword32_1, int index_imem_dark_subword32_2, int index_imem_dark_subword32_3, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_imem_dark_subword32_0, index_imem_dark_subword32_1, index_imem_dark_subword32_2, index_imem_dark_subword32_3), 4, false, write_callback, read_callback, std::string("ImemDarkSubword32")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_imem_dark_subword32_0) + "," + boost::lexical_cast<std::string>(index_imem_dark_subword32_1) + "," + boost::lexical_cast<std::string>(index_imem_dark_subword32_2) + "," + boost::lexical_cast<std::string>(index_imem_dark_subword32_3))
    {
    }
  ImemDarkSubword32(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "ImemDarkSubword32")
    {
    }
public:


  uint8_t &imem_dark_subword_instr() { return imem_dark_subword_instr_; }


  uint8_t &imem_dark_subword_color() { return imem_dark_subword_color_; }



  uint8_t &imem_dark_subword_parity() { return imem_dark_subword_parity_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (imem_dark_subword_instr_ & 0x3f);
    *data |= ((imem_dark_subword_color_ & 0x1) << 6);
    *data |= ((imem_dark_subword_parity_ & 0x1) << 7);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    imem_dark_subword_instr_ = (data & 0x3f);
    imem_dark_subword_color_ = ((data >> 6) & 0x1);
    imem_dark_subword_parity_ = ((data >> 7) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    imem_dark_subword_instr_ = 0x0;
    imem_dark_subword_color_ = 0x0;
    imem_dark_subword_parity_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("ImemDarkSubword32") + ":\n";
    r += indent_string + "  " + std::string("imem_dark_subword_instr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(imem_dark_subword_instr_) ) + "\n";
    all_zeros &= (0 == imem_dark_subword_instr_);
    r += indent_string + "  " + std::string("imem_dark_subword_color") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(imem_dark_subword_color_) ) + "\n";
    all_zeros &= (0 == imem_dark_subword_color_);
    r += indent_string + "  " + std::string("imem_dark_subword_parity") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(imem_dark_subword_parity_) ) + "\n";
    all_zeros &= (0 == imem_dark_subword_parity_);
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
    r += indent_string + std::string("ImemDarkSubword32") + ":\n";
    r += indent_string + "  " + std::string("imem_dark_subword_instr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(imem_dark_subword_instr_) ) + "\n";
    all_zeros &= (0 == imem_dark_subword_instr_);
    r += indent_string + "  " + std::string("imem_dark_subword_color") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(imem_dark_subword_color_) ) + "\n";
    all_zeros &= (0 == imem_dark_subword_color_);
    r += indent_string + "  " + std::string("imem_dark_subword_parity") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(imem_dark_subword_parity_) ) + "\n";
    all_zeros &= (0 == imem_dark_subword_parity_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t imem_dark_subword_instr_;
  uint8_t imem_dark_subword_color_;
  uint8_t imem_dark_subword_parity_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_imem_dark_subword32_0, int index_imem_dark_subword32_1, int index_imem_dark_subword32_2, int index_imem_dark_subword32_3
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x3000; // to get to imem_dark_subword32
    assert(index_imem_dark_subword32_0 < 2);
    offset += index_imem_dark_subword32_0 * 0x400; // imem_dark_subword32[]
    assert(index_imem_dark_subword32_1 < 2);
    offset += index_imem_dark_subword32_1 * 0x200; // imem_dark_subword32[][]
    assert(index_imem_dark_subword32_2 < 4);
    offset += index_imem_dark_subword32_2 * 0x80; // imem_dark_subword32[][][]
    assert(index_imem_dark_subword32_3 < 32);
    offset += index_imem_dark_subword32_3 * 0x4; // imem_dark_subword32[][][][]
    return offset;
  }

};













  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_IMEM_DARK_SUBWORD32_H__
