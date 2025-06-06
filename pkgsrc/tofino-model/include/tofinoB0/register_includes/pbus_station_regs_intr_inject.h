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
#ifndef __REGISTER_INCLUDES_PBUS_STATION_REGS_INTR_INJECT_H__
#define __REGISTER_INCLUDES_PBUS_STATION_REGS_INTR_INJECT_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofinoB0 {
  namespace register_classes {

class PbusStationRegsIntrInject : public model_core::RegisterBlock<RegisterCallback> {
public:
  PbusStationRegsIntrInject(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("PbusStationRegsIntrInject")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PbusStationRegsIntrInject(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PbusStationRegsIntrInject")
    {
    }
public:
  uint8_t &creq_ctrl_ecc_dual_err() { return creq_ctrl_ecc_dual_err_; }
  uint8_t &creq_ctrl_ecc_sngl_err() { return creq_ctrl_ecc_sngl_err_; }
  uint8_t &creq_data_ecc_dual_err() { return creq_data_ecc_dual_err_; }
  uint8_t &creq_data_ecc_sngl_err() { return creq_data_ecc_sngl_err_; }
  uint8_t &cresp_ctrl_ecc_dual_err() { return cresp_ctrl_ecc_dual_err_; }
  uint8_t &cresp_ctrl_ecc_sngl_err() { return cresp_ctrl_ecc_sngl_err_; }
  uint8_t &cresp_data_ecc_dual_err() { return cresp_data_ecc_dual_err_; }
  uint8_t &cresp_data_ecc_sngl_err() { return cresp_data_ecc_sngl_err_; }
  uint8_t &creq_il_err() { return creq_il_err_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (creq_ctrl_ecc_dual_err_ & 0x1);
    *data |= ((creq_ctrl_ecc_sngl_err_ & 0x1) << 1);
    *data |= ((creq_data_ecc_dual_err_ & 0x1) << 2);
    *data |= ((creq_data_ecc_sngl_err_ & 0x1) << 3);
    *data |= ((cresp_ctrl_ecc_dual_err_ & 0x1) << 4);
    *data |= ((cresp_ctrl_ecc_sngl_err_ & 0x1) << 5);
    *data |= ((cresp_data_ecc_dual_err_ & 0x1) << 6);
    *data |= ((cresp_data_ecc_sngl_err_ & 0x1) << 7);
    *data |= ((creq_il_err_ & 0x1) << 8);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    creq_ctrl_ecc_dual_err_ = (data & 0x1);
    creq_ctrl_ecc_sngl_err_ = ((data >> 1) & 0x1);
    creq_data_ecc_dual_err_ = ((data >> 2) & 0x1);
    creq_data_ecc_sngl_err_ = ((data >> 3) & 0x1);
    cresp_ctrl_ecc_dual_err_ = ((data >> 4) & 0x1);
    cresp_ctrl_ecc_sngl_err_ = ((data >> 5) & 0x1);
    cresp_data_ecc_dual_err_ = ((data >> 6) & 0x1);
    cresp_data_ecc_sngl_err_ = ((data >> 7) & 0x1);
    creq_il_err_ = ((data >> 8) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    creq_ctrl_ecc_dual_err_ = 0x0;
    creq_ctrl_ecc_sngl_err_ = 0x0;
    creq_data_ecc_dual_err_ = 0x0;
    creq_data_ecc_sngl_err_ = 0x0;
    cresp_ctrl_ecc_dual_err_ = 0x0;
    cresp_ctrl_ecc_sngl_err_ = 0x0;
    cresp_data_ecc_dual_err_ = 0x0;
    cresp_data_ecc_sngl_err_ = 0x0;
    creq_il_err_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PbusStationRegsIntrInject") + ":\n";
    r += indent_string + "  " + std::string("creq_ctrl_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_ctrl_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == creq_ctrl_ecc_dual_err_);
    r += indent_string + "  " + std::string("creq_ctrl_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_ctrl_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == creq_ctrl_ecc_sngl_err_);
    r += indent_string + "  " + std::string("creq_data_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_data_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == creq_data_ecc_dual_err_);
    r += indent_string + "  " + std::string("creq_data_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_data_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == creq_data_ecc_sngl_err_);
    r += indent_string + "  " + std::string("cresp_ctrl_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_ctrl_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == cresp_ctrl_ecc_dual_err_);
    r += indent_string + "  " + std::string("cresp_ctrl_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_ctrl_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == cresp_ctrl_ecc_sngl_err_);
    r += indent_string + "  " + std::string("cresp_data_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_data_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == cresp_data_ecc_dual_err_);
    r += indent_string + "  " + std::string("cresp_data_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_data_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == cresp_data_ecc_sngl_err_);
    r += indent_string + "  " + std::string("creq_il_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_il_err_) ) + "\n";
    all_zeros &= (0 == creq_il_err_);
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
    r += indent_string + std::string("PbusStationRegsIntrInject") + ":\n";
    r += indent_string + "  " + std::string("creq_ctrl_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_ctrl_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == creq_ctrl_ecc_dual_err_);
    r += indent_string + "  " + std::string("creq_ctrl_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_ctrl_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == creq_ctrl_ecc_sngl_err_);
    r += indent_string + "  " + std::string("creq_data_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_data_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == creq_data_ecc_dual_err_);
    r += indent_string + "  " + std::string("creq_data_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_data_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == creq_data_ecc_sngl_err_);
    r += indent_string + "  " + std::string("cresp_ctrl_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_ctrl_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == cresp_ctrl_ecc_dual_err_);
    r += indent_string + "  " + std::string("cresp_ctrl_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_ctrl_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == cresp_ctrl_ecc_sngl_err_);
    r += indent_string + "  " + std::string("cresp_data_ecc_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_data_ecc_dual_err_) ) + "\n";
    all_zeros &= (0 == cresp_data_ecc_dual_err_);
    r += indent_string + "  " + std::string("cresp_data_ecc_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cresp_data_ecc_sngl_err_) ) + "\n";
    all_zeros &= (0 == cresp_data_ecc_sngl_err_);
    r += indent_string + "  " + std::string("creq_il_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(creq_il_err_) ) + "\n";
    all_zeros &= (0 == creq_il_err_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t creq_ctrl_ecc_dual_err_;
  uint8_t creq_ctrl_ecc_sngl_err_;
  uint8_t creq_data_ecc_dual_err_;
  uint8_t creq_data_ecc_sngl_err_;
  uint8_t cresp_ctrl_ecc_dual_err_;
  uint8_t cresp_ctrl_ecc_sngl_err_;
  uint8_t cresp_data_ecc_dual_err_;
  uint8_t cresp_data_ecc_sngl_err_;
  uint8_t creq_il_err_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    offset += 0x34000; // to get to pbusstat_reg
    offset += 0xc; // to get to intr_inject
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PBUS_STATION_REGS_INTR_INJECT_H__
