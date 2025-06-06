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
#ifndef __REGISTER_INCLUDES_MAU_MEMORY_DATA_HV_SWITCHBOX_ROW_CONTROL_ADDRMAP_H__
#define __REGISTER_INCLUDES_MAU_MEMORY_DATA_HV_SWITCHBOX_ROW_CONTROL_ADDRMAP_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "b_oflo2dn_wr_o_mux_select.h"
#include "b_oflo2up_rd_o_mux_select.h"
#include "b_oflo_wr_o_mux_select.h"
#include "l_meter_alu_o_mux_select.h"
#include "l_oflo2_wr_o_mux_select.h"
#include "l_oflo_wr_o_mux_select.h"
#include "l_stats_alu_o_mux_select.h"
#include "r_action_o_mux_select.h"
#include "r_l_action_o_mux_select.h"
#include "r_meter_alu_o_mux_select.h"
#include "r_oflo2_wr_o_mux_select.h"
#include "r_oflo_wr_o_mux_select.h"
#include "r_stats_alu_o_mux_select.h"
#include "t_oflo2dn_rd_o_mux_select.h"
#include "t_oflo2up_wr_o_mux_select.h"
#include "t_oflo_rd_o_mux_select.h"

namespace jbayB0 {
  namespace register_classes {

class MauMemoryDataHvSwitchboxRowControlAddrmap : public model_core::RegisterBlock<RegisterCallback> {
public:
  MauMemoryDataHvSwitchboxRowControlAddrmap(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_memory_data_hv_switchbox_row_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_memory_data_hv_switchbox_row_addrmap), 64, false, write_callback, read_callback, std::string("MauMemoryDataHvSwitchboxRowControlAddrmap")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_memory_data_hv_switchbox_row_addrmap))
    {
    }
  MauMemoryDataHvSwitchboxRowControlAddrmap(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MauMemoryDataHvSwitchboxRowControlAddrmap")
    {
    }
public:






  RLActionOMuxSelect &r_l_action_o_mux_select() { return r_l_action_o_mux_select_; }






  LStatsAluOMuxSelect &l_stats_alu_o_mux_select() { return l_stats_alu_o_mux_select_; }






  LMeterAluOMuxSelect &l_meter_alu_o_mux_select() { return l_meter_alu_o_mux_select_; }






  LOfloWrOMuxSelect &l_oflo_wr_o_mux_select() { return l_oflo_wr_o_mux_select_; }






  LOflo2WrOMuxSelect &l_oflo2_wr_o_mux_select() { return l_oflo2_wr_o_mux_select_; }






  RActionOMuxSelect &r_action_o_mux_select() { return r_action_o_mux_select_; }






  RStatsAluOMuxSelect &r_stats_alu_o_mux_select() { return r_stats_alu_o_mux_select_; }






  RMeterAluOMuxSelect &r_meter_alu_o_mux_select() { return r_meter_alu_o_mux_select_; }








  ROfloWrOMuxSelect &r_oflo_wr_o_mux_select() { return r_oflo_wr_o_mux_select_; }






  ROflo2WrOMuxSelect &r_oflo2_wr_o_mux_select() { return r_oflo2_wr_o_mux_select_; }






  BOfloWrOMuxSelect &b_oflo_wr_o_mux_select() { return b_oflo_wr_o_mux_select_; }






  BOflo2dnWrOMuxSelect &b_oflo2dn_wr_o_mux_select() { return b_oflo2dn_wr_o_mux_select_; }






  BOflo2upRdOMuxSelect &b_oflo2up_rd_o_mux_select() { return b_oflo2up_rd_o_mux_select_; }






  TOfloRdOMuxSelect &t_oflo_rd_o_mux_select() { return t_oflo_rd_o_mux_select_; }






  TOflo2dnRdOMuxSelect &t_oflo2dn_rd_o_mux_select() { return t_oflo2dn_rd_o_mux_select_; }






  TOflo2upWrOMuxSelect &t_oflo2up_wr_o_mux_select() { return t_oflo2up_wr_o_mux_select_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      r_l_action_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      l_stats_alu_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      l_meter_alu_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      l_oflo_wr_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      l_oflo2_wr_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      r_action_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      r_stats_alu_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      r_meter_alu_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      r_oflo_wr_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      if (read_callback_) read_callback_();
      r_oflo2_wr_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      if (read_callback_) read_callback_();
      b_oflo_wr_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      if (read_callback_) read_callback_();
      b_oflo2dn_wr_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      b_oflo2up_rd_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      if (read_callback_) read_callback_();
      t_oflo_rd_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      if (read_callback_) read_callback_();
      t_oflo2dn_rd_o_mux_select_.read( offset, data );
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      if (read_callback_) read_callback_();
      t_oflo2up_wr_o_mux_select_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      r_l_action_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      l_stats_alu_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      l_meter_alu_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      l_oflo_wr_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      l_oflo2_wr_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r_action_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r_stats_alu_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r_meter_alu_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r_oflo_wr_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      r_oflo2_wr_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      b_oflo_wr_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      b_oflo2dn_wr_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      b_oflo2up_rd_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      t_oflo_rd_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      t_oflo2dn_rd_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      t_oflo2up_wr_o_mux_select_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    r_l_action_o_mux_select_.reset();
    l_stats_alu_o_mux_select_.reset();
    l_meter_alu_o_mux_select_.reset();
    l_oflo_wr_o_mux_select_.reset();
    l_oflo2_wr_o_mux_select_.reset();
    r_action_o_mux_select_.reset();
    r_stats_alu_o_mux_select_.reset();
    r_meter_alu_o_mux_select_.reset();
    r_oflo_wr_o_mux_select_.reset();
    r_oflo2_wr_o_mux_select_.reset();
    b_oflo_wr_o_mux_select_.reset();
    b_oflo2dn_wr_o_mux_select_.reset();
    b_oflo2up_rd_o_mux_select_.reset();
    t_oflo_rd_o_mux_select_.reset();
    t_oflo2dn_rd_o_mux_select_.reset();
    t_oflo2up_wr_o_mux_select_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x4) {
      offset -= 0x0;
      r += r_l_action_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += l_stats_alu_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += l_meter_alu_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += l_oflo_wr_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += l_oflo2_wr_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += r_action_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += r_stats_alu_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += r_meter_alu_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += r_oflo_wr_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      r += r_oflo2_wr_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      r += b_oflo_wr_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      r += b_oflo2dn_wr_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      r += b_oflo2up_rd_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      r += t_oflo_rd_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      r += t_oflo2dn_rd_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      r += t_oflo2up_wr_o_mux_select_.to_string(offset,print_zeros,indent_string) ;
    }
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
    all_zeros=false;
    r += r_l_action_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += l_stats_alu_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += l_meter_alu_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += l_oflo_wr_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += l_oflo2_wr_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += r_action_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += r_stats_alu_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += r_meter_alu_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += r_oflo_wr_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += r_oflo2_wr_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += b_oflo_wr_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += b_oflo2dn_wr_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += b_oflo2up_rd_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += t_oflo_rd_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += t_oflo2dn_rd_o_mux_select_.to_string(print_zeros,indent_string) ;
    r += t_oflo2up_wr_o_mux_select_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  RLActionOMuxSelect r_l_action_o_mux_select_;
  LStatsAluOMuxSelect l_stats_alu_o_mux_select_;
  LMeterAluOMuxSelect l_meter_alu_o_mux_select_;
  LOfloWrOMuxSelect l_oflo_wr_o_mux_select_;
  LOflo2WrOMuxSelect l_oflo2_wr_o_mux_select_;
  RActionOMuxSelect r_action_o_mux_select_;
  RStatsAluOMuxSelect r_stats_alu_o_mux_select_;
  RMeterAluOMuxSelect r_meter_alu_o_mux_select_;
  ROfloWrOMuxSelect r_oflo_wr_o_mux_select_;
  ROflo2WrOMuxSelect r_oflo2_wr_o_mux_select_;
  BOfloWrOMuxSelect b_oflo_wr_o_mux_select_;
  BOflo2dnWrOMuxSelect b_oflo2dn_wr_o_mux_select_;
  BOflo2upRdOMuxSelect b_oflo2up_rd_o_mux_select_;
  TOfloRdOMuxSelect t_oflo_rd_o_mux_select_;
  TOflo2dnRdOMuxSelect t_oflo2dn_rd_o_mux_select_;
  TOflo2upWrOMuxSelect t_oflo2up_wr_o_mux_select_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_memory_data_hv_switchbox_row_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    assert(index_mau_memory_data_hv_switchbox_row_addrmap < 8);
    offset += index_mau_memory_data_hv_switchbox_row_addrmap * 0x40; // mau_memory_data_hv_switchbox_row_addrmap[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MAU_MEMORY_DATA_HV_SWITCHBOX_ROW_CONTROL_ADDRMAP_H__
