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
#ifndef __REGISTER_INCLUDES_SYNTH2PORT_FABRIC_CTL_H__
#define __REGISTER_INCLUDES_SYNTH2PORT_FABRIC_CTL_H__


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

class Synth2portFabricCtl : public model_core::RegisterBlock<RegisterCallback> {
public:
  Synth2portFabricCtl(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_map_and_alu_row_addrmap, int index_synth2port_fabric_ctl_0, int index_synth2port_fabric_ctl_1, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_map_and_alu_row_addrmap, index_synth2port_fabric_ctl_0, index_synth2port_fabric_ctl_1), 4, false, write_callback, read_callback, std::string("Synth2portFabricCtl")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_map_and_alu_row_addrmap) + "," + boost::lexical_cast<std::string>(index_synth2port_fabric_ctl_0) + "," + boost::lexical_cast<std::string>(index_synth2port_fabric_ctl_1))
    {
    }
  Synth2portFabricCtl(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "Synth2portFabricCtl")
    {
    }
public:




  uint8_t &stats_to_vbus_below() { return stats_to_vbus_below_; }


  uint8_t &meter_to_vbus_below() { return meter_to_vbus_below_; }




  uint8_t &oflo_to_vbus_below() { return oflo_to_vbus_below_; }


  uint8_t &oflo2_to_vbus_below() { return oflo2_to_vbus_below_; }


  uint8_t &stats_to_vbus_above() { return stats_to_vbus_above_; }


  uint8_t &meter_to_vbus_above() { return meter_to_vbus_above_; }




  uint8_t &oflo_to_vbus_above() { return oflo_to_vbus_above_; }


  uint8_t &oflo2_to_vbus_above() { return oflo2_to_vbus_above_; }




  uint8_t &synth2port_connect_below() { return synth2port_connect_below_; }




  uint8_t &synth2port_connect_above() { return synth2port_connect_above_; }




  uint8_t &synth2port_connect_below2above() { return synth2port_connect_below2above_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (stats_to_vbus_below_ & 0x1);
    *data |= ((meter_to_vbus_below_ & 0x1) << 1);
    *data |= ((oflo_to_vbus_below_ & 0x1) << 2);
    *data |= ((oflo2_to_vbus_below_ & 0x1) << 3);
    *data |= ((stats_to_vbus_above_ & 0x1) << 4);
    *data |= ((meter_to_vbus_above_ & 0x1) << 5);
    *data |= ((oflo_to_vbus_above_ & 0x1) << 6);
    *data |= ((oflo2_to_vbus_above_ & 0x1) << 7);
    *data |= ((synth2port_connect_below_ & 0x1) << 8);
    *data |= ((synth2port_connect_above_ & 0x1) << 9);
    *data |= ((synth2port_connect_below2above_ & 0x1) << 10);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    stats_to_vbus_below_ = (data & 0x1);
    meter_to_vbus_below_ = ((data >> 1) & 0x1);
    oflo_to_vbus_below_ = ((data >> 2) & 0x1);
    oflo2_to_vbus_below_ = ((data >> 3) & 0x1);
    stats_to_vbus_above_ = ((data >> 4) & 0x1);
    meter_to_vbus_above_ = ((data >> 5) & 0x1);
    oflo_to_vbus_above_ = ((data >> 6) & 0x1);
    oflo2_to_vbus_above_ = ((data >> 7) & 0x1);
    synth2port_connect_below_ = ((data >> 8) & 0x1);
    synth2port_connect_above_ = ((data >> 9) & 0x1);
    synth2port_connect_below2above_ = ((data >> 10) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    stats_to_vbus_below_ = 0x0;
    meter_to_vbus_below_ = 0x0;
    oflo_to_vbus_below_ = 0x0;
    oflo2_to_vbus_below_ = 0x0;
    stats_to_vbus_above_ = 0x0;
    meter_to_vbus_above_ = 0x0;
    oflo_to_vbus_above_ = 0x0;
    oflo2_to_vbus_above_ = 0x0;
    synth2port_connect_below_ = 0x0;
    synth2port_connect_above_ = 0x0;
    synth2port_connect_below2above_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("Synth2portFabricCtl") + ":\n";
    r += indent_string + "  " + std::string("stats_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == stats_to_vbus_below_);
    r += indent_string + "  " + std::string("meter_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meter_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == meter_to_vbus_below_);
    r += indent_string + "  " + std::string("oflo_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == oflo_to_vbus_below_);
    r += indent_string + "  " + std::string("oflo2_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo2_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == oflo2_to_vbus_below_);
    r += indent_string + "  " + std::string("stats_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == stats_to_vbus_above_);
    r += indent_string + "  " + std::string("meter_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meter_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == meter_to_vbus_above_);
    r += indent_string + "  " + std::string("oflo_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == oflo_to_vbus_above_);
    r += indent_string + "  " + std::string("oflo2_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo2_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == oflo2_to_vbus_above_);
    r += indent_string + "  " + std::string("synth2port_connect_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(synth2port_connect_below_) ) + "\n";
    all_zeros &= (0 == synth2port_connect_below_);
    r += indent_string + "  " + std::string("synth2port_connect_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(synth2port_connect_above_) ) + "\n";
    all_zeros &= (0 == synth2port_connect_above_);
    r += indent_string + "  " + std::string("synth2port_connect_below2above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(synth2port_connect_below2above_) ) + "\n";
    all_zeros &= (0 == synth2port_connect_below2above_);
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
    r += indent_string + std::string("Synth2portFabricCtl") + ":\n";
    r += indent_string + "  " + std::string("stats_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == stats_to_vbus_below_);
    r += indent_string + "  " + std::string("meter_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meter_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == meter_to_vbus_below_);
    r += indent_string + "  " + std::string("oflo_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == oflo_to_vbus_below_);
    r += indent_string + "  " + std::string("oflo2_to_vbus_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo2_to_vbus_below_) ) + "\n";
    all_zeros &= (0 == oflo2_to_vbus_below_);
    r += indent_string + "  " + std::string("stats_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(stats_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == stats_to_vbus_above_);
    r += indent_string + "  " + std::string("meter_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(meter_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == meter_to_vbus_above_);
    r += indent_string + "  " + std::string("oflo_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == oflo_to_vbus_above_);
    r += indent_string + "  " + std::string("oflo2_to_vbus_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(oflo2_to_vbus_above_) ) + "\n";
    all_zeros &= (0 == oflo2_to_vbus_above_);
    r += indent_string + "  " + std::string("synth2port_connect_below") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(synth2port_connect_below_) ) + "\n";
    all_zeros &= (0 == synth2port_connect_below_);
    r += indent_string + "  " + std::string("synth2port_connect_above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(synth2port_connect_above_) ) + "\n";
    all_zeros &= (0 == synth2port_connect_above_);
    r += indent_string + "  " + std::string("synth2port_connect_below2above") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(synth2port_connect_below2above_) ) + "\n";
    all_zeros &= (0 == synth2port_connect_below2above_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t stats_to_vbus_below_;
  uint8_t meter_to_vbus_below_;
  uint8_t oflo_to_vbus_below_;
  uint8_t oflo2_to_vbus_below_;
  uint8_t stats_to_vbus_above_;
  uint8_t meter_to_vbus_above_;
  uint8_t oflo_to_vbus_above_;
  uint8_t oflo2_to_vbus_above_;
  uint8_t synth2port_connect_below_;
  uint8_t synth2port_connect_above_;
  uint8_t synth2port_connect_below2above_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_map_and_alu_row_addrmap, int index_synth2port_fabric_ctl_0, int index_synth2port_fabric_ctl_1
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    offset += 0x10000; // to get to map_alu
    assert(index_mau_map_and_alu_row_addrmap < 8);
    offset += index_mau_map_and_alu_row_addrmap * 0x400; // mau_map_and_alu_row_addrmap[]
    offset += 0x80; // to get to i2portctl
    offset += 0x40; // to get to synth2port_fabric_ctl
    assert(index_synth2port_fabric_ctl_0 < 3);
    offset += index_synth2port_fabric_ctl_0 * 0x8; // synth2port_fabric_ctl[]
    assert(index_synth2port_fabric_ctl_1 < 2);
    offset += index_synth2port_fabric_ctl_1 * 0x4; // synth2port_fabric_ctl[][]
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_SYNTH2PORT_FABRIC_CTL_H__
