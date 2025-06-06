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
#ifndef __REGISTER_INCLUDES_UNITRAM_CONFIG_MUTABLE_H__
#define __REGISTER_INCLUDES_UNITRAM_CONFIG_MUTABLE_H__


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

class UnitramConfigMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  UnitramConfigMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_map_and_alu_row_addrmap, int index_unitram_config_0, int index_unitram_config_1, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_map_and_alu_row_addrmap, index_unitram_config_0, index_unitram_config_1), 4, true, write_callback, read_callback, std::string("UnitramConfigMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_map_and_alu_row_addrmap) + "," + boost::lexical_cast<std::string>(index_unitram_config_0) + "," + boost::lexical_cast<std::string>(index_unitram_config_1))
    {
    }
  UnitramConfigMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "UnitramConfigMutable")
    {
    }
public:











  uint8_t unitram_type() { return unitram_type_; }
  void unitram_type(const uint8_t &v) { unitram_type_=v; }









  uint8_t unitram_vpn() { return unitram_vpn_; }
  void unitram_vpn(const uint8_t &v) { unitram_vpn_=v; }


  uint8_t unitram_logical_table() { return unitram_logical_table_; }
  void unitram_logical_table(const uint8_t &v) { unitram_logical_table_=v; }


  uint8_t unitram_ingress() { return unitram_ingress_; }
  void unitram_ingress(const uint8_t &v) { unitram_ingress_=v; }


  uint8_t unitram_egress() { return unitram_egress_; }
  void unitram_egress(const uint8_t &v) { unitram_egress_=v; }





  uint8_t unitram_action_subword_out_en() { return unitram_action_subword_out_en_; }
  void unitram_action_subword_out_en(const uint8_t &v) { unitram_action_subword_out_en_=v; }




  uint8_t unitram_enable() { return unitram_enable_; }
  void unitram_enable(const uint8_t &v) { unitram_enable_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (unitram_type_ & 0x7);
    *data |= ((unitram_vpn_ & 0x7f) << 3);
    *data |= ((unitram_logical_table_ & 0xf) << 10);
    *data |= ((unitram_ingress_ & 0x1) << 14);
    *data |= ((unitram_egress_ & 0x1) << 15);
    *data |= ((unitram_action_subword_out_en_ & 0x1) << 16);
    *data |= ((unitram_enable_ & 0x1) << 17);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    unitram_type_ = (data & 0x7);
    unitram_vpn_ = ((data >> 3) & 0x7f);
    unitram_logical_table_ = ((data >> 10) & 0xf);
    unitram_ingress_ = ((data >> 14) & 0x1);
    unitram_egress_ = ((data >> 15) & 0x1);
    unitram_action_subword_out_en_ = ((data >> 16) & 0x1);
    unitram_enable_ = ((data >> 17) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    unitram_type_ = 0x0;
    unitram_vpn_ = 0x0;
    unitram_logical_table_ = 0x0;
    unitram_ingress_ = 0x0;
    unitram_egress_ = 0x0;
    unitram_action_subword_out_en_ = 0x0;
    unitram_enable_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("UnitramConfigMutable") + ":\n";
    r += indent_string + "  " + std::string("unitram_type") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_type_) ) + "\n";
    all_zeros &= (0 == unitram_type_);
    r += indent_string + "  " + std::string("unitram_vpn") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_vpn_) ) + "\n";
    all_zeros &= (0 == unitram_vpn_);
    r += indent_string + "  " + std::string("unitram_logical_table") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_logical_table_) ) + "\n";
    all_zeros &= (0 == unitram_logical_table_);
    r += indent_string + "  " + std::string("unitram_ingress") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_ingress_) ) + "\n";
    all_zeros &= (0 == unitram_ingress_);
    r += indent_string + "  " + std::string("unitram_egress") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_egress_) ) + "\n";
    all_zeros &= (0 == unitram_egress_);
    r += indent_string + "  " + std::string("unitram_action_subword_out_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_action_subword_out_en_) ) + "\n";
    all_zeros &= (0 == unitram_action_subword_out_en_);
    r += indent_string + "  " + std::string("unitram_enable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_enable_) ) + "\n";
    all_zeros &= (0 == unitram_enable_);
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
    r += indent_string + std::string("UnitramConfigMutable") + ":\n";
    r += indent_string + "  " + std::string("unitram_type") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_type_) ) + "\n";
    all_zeros &= (0 == unitram_type_);
    r += indent_string + "  " + std::string("unitram_vpn") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_vpn_) ) + "\n";
    all_zeros &= (0 == unitram_vpn_);
    r += indent_string + "  " + std::string("unitram_logical_table") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_logical_table_) ) + "\n";
    all_zeros &= (0 == unitram_logical_table_);
    r += indent_string + "  " + std::string("unitram_ingress") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_ingress_) ) + "\n";
    all_zeros &= (0 == unitram_ingress_);
    r += indent_string + "  " + std::string("unitram_egress") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_egress_) ) + "\n";
    all_zeros &= (0 == unitram_egress_);
    r += indent_string + "  " + std::string("unitram_action_subword_out_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_action_subword_out_en_) ) + "\n";
    all_zeros &= (0 == unitram_action_subword_out_en_);
    r += indent_string + "  " + std::string("unitram_enable") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(unitram_enable_) ) + "\n";
    all_zeros &= (0 == unitram_enable_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t unitram_type_;
  uint8_t unitram_vpn_;
  uint8_t unitram_logical_table_;
  uint8_t unitram_ingress_;
  uint8_t unitram_egress_;
  uint8_t unitram_action_subword_out_en_;
  uint8_t unitram_enable_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_map_and_alu_row_addrmap, int index_unitram_config_0, int index_unitram_config_1
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x10000; // to get to map_alu
    offset += 0x2000; // to get to row
    assert(index_mau_map_and_alu_row_addrmap < 8);
    offset += index_mau_map_and_alu_row_addrmap * 0x400; // mau_map_and_alu_row_addrmap[]
    offset += 0x200; // to get to adrmux
    offset += 0x180; // to get to unitram_config
    assert(index_unitram_config_0 < 2);
    offset += index_unitram_config_0 * 0x20; // unitram_config[]
    assert(index_unitram_config_1 < 6);
    offset += index_unitram_config_1 * 0x4; // unitram_config[][]
    return offset;
  }

};





















  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_UNITRAM_CONFIG_MUTABLE_H__
