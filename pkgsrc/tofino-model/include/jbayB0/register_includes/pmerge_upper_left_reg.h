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
#ifndef __REGISTER_INCLUDES_PMERGE_UPPER_LEFT_REG_H__
#define __REGISTER_INCLUDES_PMERGE_UPPER_LEFT_REG_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "pmerge_upper_left_reg_i_mac_empty_8_5.h"
#include "pmerge_upper_left_reg_i_pre_wr_addr.h"
#include "pmerge_upper_left_reg_phv_clr_on_wr_127_0.h"
#include "pmerge_upper_left_reg_phv_owner_127_0.h"
#include "pmerge_upper_left_reg_port_rate_cfg_8_5.h"

namespace jbayB0 {
  namespace register_classes {

class PmergeUpperLeftReg : public model_core::RegisterBlock<RegisterCallback> {
public:
  PmergeUpperLeftReg(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 512, false, write_callback, read_callback, std::string("PmergeUpperLeftReg")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PmergeUpperLeftReg(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PmergeUpperLeftReg")
    {
    }
public:









  PmergeUpperLeftRegPortRateCfg_8_5 &port_rate_cfg_8_5(int j0) { return port_rate_cfg_8_5_[j0]; }





  PmergeUpperLeftRegPhvOwner_127_0 &phv_owner_127_0() { return phv_owner_127_0_; }






  PmergeUpperLeftRegPhvClrOnWr_127_0 &phv_clr_on_wr_127_0() { return phv_clr_on_wr_127_0_; }







  PmergeUpperLeftRegIMacEmpty_8_5 &i_mac_empty_8_5(int j0) { return i_mac_empty_8_5_[j0]; }







  PmergeUpperLeftRegIPreWrAddr &i_pre_wr_addr() { return i_pre_wr_addr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      port_rate_cfg_8_5_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x30) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      phv_owner_127_0_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x40) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      phv_clr_on_wr_127_0_.read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x50) {
      offset -= 0x40;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      i_mac_empty_8_5_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      if (read_callback_) read_callback_();
      i_pre_wr_addr_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      port_rate_cfg_8_5_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x30) {
      offset -= 0x20;
      phv_owner_127_0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x40) {
      offset -= 0x30;
      phv_clr_on_wr_127_0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x50) {
      offset -= 0x40;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      i_mac_empty_8_5_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      i_pre_wr_addr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    for (auto &f0 : port_rate_cfg_8_5_) {
      f0.reset();
    }
    phv_owner_127_0_.reset();
    phv_clr_on_wr_127_0_.reset();
    for (auto &f0 : i_mac_empty_8_5_) {
      f0.reset();
    }
    i_pre_wr_addr_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += port_rate_cfg_8_5_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x30) {
      offset -= 0x20;
      r += phv_owner_127_0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x40) {
      offset -= 0x30;
      r += phv_clr_on_wr_127_0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x50) {
      offset -= 0x40;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += i_mac_empty_8_5_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      r += i_pre_wr_addr_.to_string(offset,print_zeros,indent_string) ;
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
    for (uint32_t a0=0;a0<4;++a0) {
      r += port_rate_cfg_8_5_[a0].to_string(print_zeros,indent_string) ;
    }
    r += phv_owner_127_0_.to_string(print_zeros,indent_string) ;
    r += phv_clr_on_wr_127_0_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<4;++a0) {
      r += i_mac_empty_8_5_[a0].to_string(print_zeros,indent_string) ;
    }
    r += i_pre_wr_addr_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< PmergeUpperLeftRegPortRateCfg_8_5, 4 > port_rate_cfg_8_5_;
  PmergeUpperLeftRegPhvOwner_127_0 phv_owner_127_0_;
  PmergeUpperLeftRegPhvClrOnWr_127_0 phv_clr_on_wr_127_0_;
  std::array< PmergeUpperLeftRegIMacEmpty_8_5, 4 > i_mac_empty_8_5_;
  PmergeUpperLeftRegIPreWrAddr i_pre_wr_addr_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x12000; // to get to pmergereg
    offset += 0x200; // to get to ul
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PMERGE_UPPER_LEFT_REG_H__
