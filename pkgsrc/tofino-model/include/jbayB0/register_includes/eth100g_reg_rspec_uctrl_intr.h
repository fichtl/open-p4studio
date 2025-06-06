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
#ifndef __REGISTER_INCLUDES_ETH100G_REG_RSPEC_UCTRL_INTR_H__
#define __REGISTER_INCLUDES_ETH100G_REG_RSPEC_UCTRL_INTR_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "eth100g_reg_rspec_uctrl_intr_en0.h"
#include "eth100g_reg_rspec_uctrl_intr_en1.h"
#include "eth100g_reg_rspec_uctrl_intr_freeze_enable.h"
#include "eth100g_reg_rspec_uctrl_intr_inj.h"
#include "eth100g_reg_rspec_uctrl_intr_stat.h"

namespace jbayB0 {
  namespace register_classes {

class Eth100gRegRspecUctrlIntr : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum JbayRegEnum {
    kEth100gRegs,
    kEth100gRegsRot
  };
public:
  Eth100gRegRspecUctrlIntr(
      int chipNumber, JbayRegEnum selector_jbay_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_jbay_reg), 20, false, write_callback, read_callback, std::string("Eth100gRegRspecUctrlIntr")+":"+boost::lexical_cast<std::string>(selector_jbay_reg))
    {
    }
  Eth100gRegRspecUctrlIntr(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "Eth100gRegRspecUctrlIntr")
    {
    }
public:






  Eth100gRegRspecUctrlIntrStat &uctrl_intr_stat() { return uctrl_intr_stat_; }







  Eth100gRegRspecUctrlIntrEn0 &uctrl_intr_en0() { return uctrl_intr_en0_; }







  Eth100gRegRspecUctrlIntrEn1 &uctrl_intr_en1() { return uctrl_intr_en1_; }








  Eth100gRegRspecUctrlIntrInj &uctrl_intr_inj() { return uctrl_intr_inj_; }





  Eth100gRegRspecUctrlIntrFreezeEnable &uctrl_intr_freeze_enable() { return uctrl_intr_freeze_enable_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x120 && offset < 0x124) {
      offset -= 0x120;
      if (read_callback_) read_callback_();
      uctrl_intr_stat_.read( offset, data );
    }
    else if (offset >= 0x124 && offset < 0x128) {
      offset -= 0x124;
      if (read_callback_) read_callback_();
      uctrl_intr_en0_.read( offset, data );
    }
    else if (offset >= 0x128 && offset < 0x12c) {
      offset -= 0x128;
      if (read_callback_) read_callback_();
      uctrl_intr_en1_.read( offset, data );
    }
    else if (offset >= 0x12c && offset < 0x130) {
      offset -= 0x12c;
      if (read_callback_) read_callback_();
      uctrl_intr_inj_.read( offset, data );
    }
    else if (offset >= 0x130 && offset < 0x134) {
      offset -= 0x130;
      if (read_callback_) read_callback_();
      uctrl_intr_freeze_enable_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x120 && offset < 0x124) {
      offset -= 0x120;
      uctrl_intr_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x124 && offset < 0x128) {
      offset -= 0x124;
      uctrl_intr_en0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x128 && offset < 0x12c) {
      offset -= 0x128;
      uctrl_intr_en1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x12c && offset < 0x130) {
      offset -= 0x12c;
      uctrl_intr_inj_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x130 && offset < 0x134) {
      offset -= 0x130;
      uctrl_intr_freeze_enable_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    uctrl_intr_stat_.reset();
    uctrl_intr_en0_.reset();
    uctrl_intr_en1_.reset();
    uctrl_intr_inj_.reset();
    uctrl_intr_freeze_enable_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x120 && offset < 0x124) {
      offset -= 0x120;
      r += uctrl_intr_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x124 && offset < 0x128) {
      offset -= 0x124;
      r += uctrl_intr_en0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x128 && offset < 0x12c) {
      offset -= 0x128;
      r += uctrl_intr_en1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x12c && offset < 0x130) {
      offset -= 0x12c;
      r += uctrl_intr_inj_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x130 && offset < 0x134) {
      offset -= 0x130;
      r += uctrl_intr_freeze_enable_.to_string(offset,print_zeros,indent_string) ;
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
    r += uctrl_intr_stat_.to_string(print_zeros,indent_string) ;
    r += uctrl_intr_en0_.to_string(print_zeros,indent_string) ;
    r += uctrl_intr_en1_.to_string(print_zeros,indent_string) ;
    r += uctrl_intr_inj_.to_string(print_zeros,indent_string) ;
    r += uctrl_intr_freeze_enable_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  Eth100gRegRspecUctrlIntrStat uctrl_intr_stat_;
  Eth100gRegRspecUctrlIntrEn0 uctrl_intr_en0_;
  Eth100gRegRspecUctrlIntrEn1 uctrl_intr_en1_;
  Eth100gRegRspecUctrlIntrInj uctrl_intr_inj_;
  Eth100gRegRspecUctrlIntrFreezeEnable uctrl_intr_freeze_enable_;
private:
  static int StartOffset(
      JbayRegEnum selector_jbay_reg
      ) {
    int offset=0;
    switch (selector_jbay_reg) {
      case kEth100gRegs:
        offset += 0x2000000; // to get to eth100g_regs
        offset += 0x1fc00; // to get to eth100g_reg
        break;
      case kEth100gRegsRot:
        offset += 0x29c0000; // to get to eth100g_regs_rot
        offset += 0x1fc00; // to get to eth100g_reg
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};





  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_ETH100G_REG_RSPEC_UCTRL_INTR_H__
