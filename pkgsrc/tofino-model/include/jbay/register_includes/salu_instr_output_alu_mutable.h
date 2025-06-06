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
#ifndef __REGISTER_INCLUDES_SALU_INSTR_OUTPUT_ALU_MUTABLE_H__
#define __REGISTER_INCLUDES_SALU_INSTR_OUTPUT_ALU_MUTABLE_H__


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

class SaluInstrOutputAluMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  SaluInstrOutputAluMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap, int index_salu_instr_output_alu_0, int index_salu_instr_output_alu_1, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_meter_alu_group_addrmap, index_salu_instr_output_alu_0, index_salu_instr_output_alu_1), 4, true, write_callback, read_callback, std::string("SaluInstrOutputAluMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_meter_alu_group_addrmap) + "," + boost::lexical_cast<std::string>(index_salu_instr_output_alu_0) + "," + boost::lexical_cast<std::string>(index_salu_instr_output_alu_1))
    {
    }
  SaluInstrOutputAluMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "SaluInstrOutputAluMutable")
    {
    }
public:


  uint16_t salu_output_cmpfn() { return salu_output_cmpfn_; }
  void salu_output_cmpfn(const uint16_t &v) { salu_output_cmpfn_=v; }













  uint8_t salu_output_asrc() { return salu_output_asrc_; }
  void salu_output_asrc(const uint8_t &v) { salu_output_asrc_=v; }




  uint8_t salu_lmatch_adr_bit_enable() { return salu_lmatch_adr_bit_enable_; }
  void salu_lmatch_adr_bit_enable(const uint8_t &v) { salu_lmatch_adr_bit_enable_=v; }


  uint8_t salu_pred_disable() { return salu_pred_disable_; }
  void salu_pred_disable(const uint8_t &v) { salu_pred_disable_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = salu_output_cmpfn_;
    *data |= ((salu_output_asrc_ & 0xf) << 16);
    *data |= ((salu_lmatch_adr_bit_enable_ & 0x1) << 20);
    *data |= ((salu_pred_disable_ & 0x1) << 21);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    salu_output_cmpfn_ = data;
    salu_output_asrc_ = ((data >> 16) & 0xf);
    salu_lmatch_adr_bit_enable_ = ((data >> 20) & 0x1);
    salu_pred_disable_ = ((data >> 21) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    salu_output_cmpfn_ = 0x0;
    salu_output_asrc_ = 0x0;
    salu_lmatch_adr_bit_enable_ = 0x0;
    salu_pred_disable_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("SaluInstrOutputAluMutable") + ":\n";
    r += indent_string + "  " + std::string("salu_output_cmpfn") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_output_cmpfn_) ) + "\n";
    all_zeros &= (0 == salu_output_cmpfn_);
    r += indent_string + "  " + std::string("salu_output_asrc") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_output_asrc_) ) + "\n";
    all_zeros &= (0 == salu_output_asrc_);
    r += indent_string + "  " + std::string("salu_lmatch_adr_bit_enable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_lmatch_adr_bit_enable_) ) + "\n";
    all_zeros &= (0 == salu_lmatch_adr_bit_enable_);
    r += indent_string + "  " + std::string("salu_pred_disable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_pred_disable_) ) + "\n";
    all_zeros &= (0 == salu_pred_disable_);
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
    r += indent_string + std::string("SaluInstrOutputAluMutable") + ":\n";
    r += indent_string + "  " + std::string("salu_output_cmpfn") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_output_cmpfn_) ) + "\n";
    all_zeros &= (0 == salu_output_cmpfn_);
    r += indent_string + "  " + std::string("salu_output_asrc") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_output_asrc_) ) + "\n";
    all_zeros &= (0 == salu_output_asrc_);
    r += indent_string + "  " + std::string("salu_lmatch_adr_bit_enable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_lmatch_adr_bit_enable_) ) + "\n";
    all_zeros &= (0 == salu_lmatch_adr_bit_enable_);
    r += indent_string + "  " + std::string("salu_pred_disable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(salu_pred_disable_) ) + "\n";
    all_zeros &= (0 == salu_pred_disable_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t salu_output_cmpfn_;
  uint8_t salu_output_asrc_;
  uint8_t salu_lmatch_adr_bit_enable_;
  uint8_t salu_pred_disable_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap, int index_salu_instr_output_alu_0, int index_salu_instr_output_alu_1
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    offset += 0x10000; // to get to map_alu
    offset += 0x3000; // to get to meter_group
    assert(index_mau_meter_alu_group_addrmap < 4);
    offset += index_mau_meter_alu_group_addrmap * 0x400; // mau_meter_alu_group_addrmap[]
    offset += 0x200; // to get to stateful
    offset += 0x180; // to get to salu_instr_output_alu
    assert(index_salu_instr_output_alu_0 < 4);
    offset += index_salu_instr_output_alu_0 * 0x10; // salu_instr_output_alu[]
    assert(index_salu_instr_output_alu_1 < 4);
    offset += index_salu_instr_output_alu_1 * 0x4; // salu_instr_output_alu[][]
    return offset;
  }

};











  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_SALU_INSTR_OUTPUT_ALU_MUTABLE_H__
