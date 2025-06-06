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
#ifndef __REGISTER_INCLUDES_PRSR_REG_MAIN_RSPEC_PRI_MAP_H__
#define __REGISTER_INCLUDES_PRSR_REG_MAIN_RSPEC_PRI_MAP_H__


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

class PrsrRegMainRspecPriMap : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum PardeGlueStnRegEnum {
    kEpbprsr4reg,
    kIpbprsr4reg
  };
public:
  PrsrRegMainRspecPriMap(
      int chipNumber, int index_pipe_addrmap, PardeGlueStnRegEnum selector_parde_glue_stn_reg, int index_epb_prsr4_reg, int index_prsr_reg_main_rspec, int index_prsr_reg_main_rspec_pri_map, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_parde_glue_stn_reg, index_epb_prsr4_reg, index_prsr_reg_main_rspec, index_prsr_reg_main_rspec_pri_map), 4, false, write_callback, read_callback, std::string("PrsrRegMainRspecPriMap")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_parde_glue_stn_reg) + "," + boost::lexical_cast<std::string>(index_epb_prsr4_reg) + "," + boost::lexical_cast<std::string>(index_prsr_reg_main_rspec) + "," + boost::lexical_cast<std::string>(index_prsr_reg_main_rspec_pri_map))
    {
    }
  PrsrRegMainRspecPriMap(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PrsrRegMainRspecPriMap")
    {
    }
public:






  uint8_t &pri(int j0) { return pri_[j0]; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (pri_[0] & 0x3);
    *data |= ((pri_[1] & 0x3) << 2);
    *data |= ((pri_[2] & 0x3) << 4);
    *data |= ((pri_[3] & 0x3) << 6);
    *data |= ((pri_[4] & 0x3) << 8);
    *data |= ((pri_[5] & 0x3) << 10);
    *data |= ((pri_[6] & 0x3) << 12);
    *data |= ((pri_[7] & 0x3) << 14);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    pri_[0] = (data & 0x3);
    pri_[1] = ((data >> 2) & 0x3);
    pri_[2] = ((data >> 4) & 0x3);
    pri_[3] = ((data >> 6) & 0x3);
    pri_[4] = ((data >> 8) & 0x3);
    pri_[5] = ((data >> 10) & 0x3);
    pri_[6] = ((data >> 12) & 0x3);
    pri_[7] = ((data >> 14) & 0x3);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    pri_[0] = 0x0;
    pri_[1] = 0x0;
    pri_[2] = 0x0;
    pri_[3] = 0x0;
    pri_[4] = 0x0;
    pri_[5] = 0x0;
    pri_[6] = 0x0;
    pri_[7] = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PrsrRegMainRspecPriMap") + ":\n";
    for (uint32_t f=0;f<8;++f) {
      r += indent_string + "  " + std::string("pri") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pri_[f]) ) + "\n";
      all_zeros &= (0 == pri_[f]);
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
    r += indent_string + std::string("PrsrRegMainRspecPriMap") + ":\n";
    for (uint32_t f=0;f<8;++f) {
      r += indent_string + "  " + std::string("pri") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pri_[f]) ) + "\n";
      all_zeros &= (0 == pri_[f]);
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< uint8_t, 8 > pri_;
private:
  static int StartOffset(
      int index_pipe_addrmap, PardeGlueStnRegEnum selector_parde_glue_stn_reg, int index_epb_prsr4_reg, int index_prsr_reg_main_rspec, int index_prsr_reg_main_rspec_pri_map
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    switch (selector_parde_glue_stn_reg) {
      case kEpbprsr4reg:
        offset += 0x20000; // to get to epbprsr4reg
        assert(index_epb_prsr4_reg < 9);
        offset += index_epb_prsr4_reg * 0x2000; // epb_prsr4_reg[]
        offset += 0x1000; // to get to prsr
        assert(index_prsr_reg_main_rspec < 4);
        offset += index_prsr_reg_main_rspec * 0x400; // prsr_reg_main_rspec[]
        offset += 0x30; // to get to pri_map
        assert(index_prsr_reg_main_rspec_pri_map < 2);
        offset += index_prsr_reg_main_rspec_pri_map * 0x4; // prsr_reg_main_rspec_pri_map[]
        break;
      case kIpbprsr4reg:
        assert(index_epb_prsr4_reg < 9);
        offset += index_epb_prsr4_reg * 0x2000; // ipb_prsr4_reg[]
        offset += 0x1000; // to get to prsr
        assert(index_prsr_reg_main_rspec < 4);
        offset += index_prsr_reg_main_rspec * 0x400; // prsr_reg_main_rspec[]
        offset += 0x30; // to get to pri_map
        assert(index_prsr_reg_main_rspec_pri_map < 2);
        offset += index_prsr_reg_main_rspec_pri_map * 0x4; // prsr_reg_main_rspec_pri_map[]
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PRSR_REG_MAIN_RSPEC_PRI_MAP_H__
