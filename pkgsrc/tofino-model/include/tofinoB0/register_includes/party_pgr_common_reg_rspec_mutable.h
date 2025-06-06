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
#ifndef __REGISTER_INCLUDES_PARTY_PGR_COMMON_REG_RSPEC_MUTABLE_H__
#define __REGISTER_INCLUDES_PARTY_PGR_COMMON_REG_RSPEC_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "pgr_credit_ctrl_mutable.h"
#include "pgr_ctr48_port16_crc_err_mutable.h"
#include "pgr_ctr48_port17_crc_err_mutable.h"
#include "pgr_freeze_en_mutable.h"
#include "pgr_int_en0_mutable.h"
#include "pgr_int_inj_mutable.h"
#include "pgr_int_stat_mutable.h"
#include "pgr_mbe_log_mutable.h"
#include "pgr_pgen_log_mutable.h"
#include "pgr_port16_ctrl_mutable.h"
#include "pgr_port16_ts_mutable.h"
#include "pgr_port17_ctrl1_mutable.h"
#include "pgr_port17_ctrl2_mutable.h"
#include "pgr_port17_ts_mutable.h"
#include "pgr_port_down_dis_mutable.h"
#include "pgr_sbe_log_mutable.h"

namespace tofinoB0 {
  namespace register_classes {

class PartyPgrCommonRegRspecMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PartyPgrCommonRegRspecMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4096, true, write_callback, read_callback, std::string("PartyPgrCommonRegRspecMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PartyPgrCommonRegRspecMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PartyPgrCommonRegRspecMutable")
    {
    }
public:





  PgrPort16TsMutable &port16_ts() { return port16_ts_; }





  PgrPort17TsMutable &port17_ts() { return port17_ts_; }





  PgrPort16CtrlMutable &port16_ctrl() { return port16_ctrl_; }





  PgrPort17Ctrl1Mutable &port17_ctrl1() { return port17_ctrl1_; }





  PgrPort17Ctrl2Mutable &port17_ctrl2() { return port17_ctrl2_; }





  PgrPortDownDisMutable &port_down_dis() { return port_down_dis_; }





  PgrIntStatMutable &int_stat() { return int_stat_; }





  PgrIntEn0Mutable &int_en0() { return int_en0_; }





  PgrIntEn0Mutable &int_en1() { return int_en1_; }





  PgrFreezeEnMutable &freeze_en() { return freeze_en_; }





  PgrIntInjMutable &int_inj() { return int_inj_; }







  PgrCtr48Port16CrcErrMutable &port16_crc_err_count(int j0) { return port16_crc_err_count_[j0]; }







  PgrCtr48Port17CrcErrMutable &port17_crc_err_count(int j0) { return port17_crc_err_count_[j0]; }





  PgrSbeLogMutable &sbe_log() { return sbe_log_; }





  PgrMbeLogMutable &mbe_log() { return mbe_log_; }





  PgrPgenLogMutable &pgen_log() { return pgen_log_; }





  PgrCreditCtrlMutable &credit_ctrl() { return credit_ctrl_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      port16_ts_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      port17_ts_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      port16_ctrl_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      port17_ctrl1_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      port17_ctrl2_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x3c) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      port_down_dis_.read( offset, data );
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      if (read_callback_) read_callback_();
      int_stat_.read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      if (read_callback_) read_callback_();
      int_en0_.read( offset, data );
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      if (read_callback_) read_callback_();
      int_en1_.read( offset, data );
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      if (read_callback_) read_callback_();
      freeze_en_.read( offset, data );
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      if (read_callback_) read_callback_();
      int_inj_.read( offset, data );
    }
    else if (offset >= 0x60 && offset < 0x80) {
      offset -= 0x60;
      int i0 = offset / 0x8;
      offset  -= i0 * 0x8;
      if (read_callback_) read_callback_();
      port16_crc_err_count_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x80 && offset < 0xa0) {
      offset -= 0x80;
      int i0 = offset / 0x8;
      offset  -= i0 * 0x8;
      if (read_callback_) read_callback_();
      port17_crc_err_count_[ i0 ].read( offset, data );
    }
    else if (offset >= 0xa0 && offset < 0xa4) {
      offset -= 0xa0;
      if (read_callback_) read_callback_();
      sbe_log_.read( offset, data );
    }
    else if (offset >= 0xa4 && offset < 0xa8) {
      offset -= 0xa4;
      if (read_callback_) read_callback_();
      mbe_log_.read( offset, data );
    }
    else if (offset >= 0xa8 && offset < 0xac) {
      offset -= 0xa8;
      if (read_callback_) read_callback_();
      pgen_log_.read( offset, data );
    }
    else if (offset >= 0xac && offset < 0xb0) {
      offset -= 0xac;
      if (read_callback_) read_callback_();
      credit_ctrl_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      port16_ts_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      port17_ts_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      port16_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      port17_ctrl1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      port17_ctrl2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x3c) {
      offset -= 0x30;
      port_down_dis_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      int_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      int_en0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      int_en1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      freeze_en_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      int_inj_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x60 && offset < 0x80) {
      offset -= 0x60;
      int i0 = offset / 0x8;
      offset  -= i0 * 0x8;
      port16_crc_err_count_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80 && offset < 0xa0) {
      offset -= 0x80;
      int i0 = offset / 0x8;
      offset  -= i0 * 0x8;
      port17_crc_err_count_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa0 && offset < 0xa4) {
      offset -= 0xa0;
      sbe_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa4 && offset < 0xa8) {
      offset -= 0xa4;
      mbe_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa8 && offset < 0xac) {
      offset -= 0xa8;
      pgen_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xac && offset < 0xb0) {
      offset -= 0xac;
      credit_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    port16_ts_.reset();
    port17_ts_.reset();
    port16_ctrl_.reset();
    port17_ctrl1_.reset();
    port17_ctrl2_.reset();
    port_down_dis_.reset();
    int_stat_.reset();
    int_en0_.reset();
    int_en1_.reset();
    freeze_en_.reset();
    int_inj_.reset();
    for (auto &f0 : port16_crc_err_count_) {
      f0.reset();
    }
    for (auto &f0 : port17_crc_err_count_) {
      f0.reset();
    }
    sbe_log_.reset();
    mbe_log_.reset();
    pgen_log_.reset();
    credit_ctrl_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += port16_ts_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += port17_ts_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += port16_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += port17_ctrl1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += port17_ctrl2_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x3c) {
      offset -= 0x30;
      r += port_down_dis_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      r += int_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      r += int_en0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      r += int_en1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      r += freeze_en_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      r += int_inj_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x60 && offset < 0x80) {
      offset -= 0x60;
      int i0 = offset / 0x8;
      offset  -= i0 * 0x8;
      r += port16_crc_err_count_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80 && offset < 0xa0) {
      offset -= 0x80;
      int i0 = offset / 0x8;
      offset  -= i0 * 0x8;
      r += port17_crc_err_count_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa0 && offset < 0xa4) {
      offset -= 0xa0;
      r += sbe_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa4 && offset < 0xa8) {
      offset -= 0xa4;
      r += mbe_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa8 && offset < 0xac) {
      offset -= 0xa8;
      r += pgen_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xac && offset < 0xb0) {
      offset -= 0xac;
      r += credit_ctrl_.to_string(offset,print_zeros,indent_string) ;
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
    r += port16_ts_.to_string(print_zeros,indent_string) ;
    r += port17_ts_.to_string(print_zeros,indent_string) ;
    r += port16_ctrl_.to_string(print_zeros,indent_string) ;
    r += port17_ctrl1_.to_string(print_zeros,indent_string) ;
    r += port17_ctrl2_.to_string(print_zeros,indent_string) ;
    r += port_down_dis_.to_string(print_zeros,indent_string) ;
    r += int_stat_.to_string(print_zeros,indent_string) ;
    r += int_en0_.to_string(print_zeros,indent_string) ;
    r += int_en1_.to_string(print_zeros,indent_string) ;
    r += freeze_en_.to_string(print_zeros,indent_string) ;
    r += int_inj_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<4;++a0) {
      r += port16_crc_err_count_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<4;++a0) {
      r += port17_crc_err_count_[a0].to_string(print_zeros,indent_string) ;
    }
    r += sbe_log_.to_string(print_zeros,indent_string) ;
    r += mbe_log_.to_string(print_zeros,indent_string) ;
    r += pgen_log_.to_string(print_zeros,indent_string) ;
    r += credit_ctrl_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  PgrPort16TsMutable port16_ts_;
  PgrPort17TsMutable port17_ts_;
  PgrPort16CtrlMutable port16_ctrl_;
  PgrPort17Ctrl1Mutable port17_ctrl1_;
  PgrPort17Ctrl2Mutable port17_ctrl2_;
  PgrPortDownDisMutable port_down_dis_;
  PgrIntStatMutable int_stat_;
  PgrIntEn0Mutable int_en0_;
  PgrIntEn0Mutable int_en1_;
  PgrFreezeEnMutable freeze_en_;
  PgrIntInjMutable int_inj_;
  std::array< PgrCtr48Port16CrcErrMutable, 4 > port16_crc_err_count_;
  std::array< PgrCtr48Port17CrcErrMutable, 4 > port17_crc_err_count_;
  PgrSbeLogMutable sbe_log_;
  PgrMbeLogMutable mbe_log_;
  PgrPgenLogMutable pgen_log_;
  PgrCreditCtrlMutable credit_ctrl_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    offset += 0x3c000; // to get to pgr_reg
    offset += 0x1000; // to get to pgr_common
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PARTY_PGR_COMMON_REG_RSPEC_MUTABLE_H__
