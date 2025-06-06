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
#ifndef __REGISTER_INCLUDES_MIRROR_S2P_REGS_MUTABLE_H__
#define __REGISTER_INCLUDES_MIRROR_S2P_REGS_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "mirr_crc_ctrl_r_mutable.h"
#include "mirr_s2p_coal_to_interval_r_mutable.h"
#include "mirr_s2p_sess_cfg_word0_r_mutable.h"
#include "mirr_s2p_sess_cfg_word1_r_mutable.h"
#include "mirr_s2p_sess_cfg_word2_r_mutable.h"
#include "mirr_s2p_sess_cfg_word3_r_mutable.h"
#include "mirr_s2p_sess_cfg_word4_r_mutable.h"
#include "mirror_s2p_cnt48_inc_mutable.h"
#include "mirror_s2p_curr_credits_r_mutable.h"
#include "mirror_s2p_dprsr_bubble_width_r_mutable.h"
#include "mirror_s2p_regs_intr_mutable.h"
#include "mirror_s2p_regs_s2p_session_mbe_err_log_mutable.h"
#include "mirror_s2p_regs_s2p_session_sbe_err_log_mutable.h"
#include "s2p_credits_config_r_mutable.h"
#include "s2p_session_ecc_inj_ctrl_r_mutable.h"

namespace jbayB0 {
  namespace register_classes {

class MirrorS2pRegsMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirrorS2pRegsMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 256, true, write_callback, read_callback, std::string("MirrorS2pRegsMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  MirrorS2pRegsMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MirrorS2pRegsMutable")
    {
    }
public:





  S2pCreditsConfigRMutable &s2p_credit_cfg() { return s2p_credit_cfg_; }








  MirrS2pSessCfgWord0RMutable &sess_entry_word0() { return sess_entry_word0_; }





  MirrS2pSessCfgWord1RMutable &sess_entry_word1() { return sess_entry_word1_; }





  MirrS2pSessCfgWord2RMutable &sess_entry_word2() { return sess_entry_word2_; }





  MirrS2pSessCfgWord3RMutable &sess_entry_word3() { return sess_entry_word3_; }





  MirrS2pSessCfgWord4RMutable &sess_entry_word4() { return sess_entry_word4_; }





  MirrS2pCoalToIntervalRMutable &coal_to_interval() { return coal_to_interval_; }





  MirrorS2pRegsS2pSessionSbeErrLogMutable &s2p_session_sbe_err_log() { return s2p_session_sbe_err_log_; }





  MirrorS2pRegsS2pSessionMbeErrLogMutable &s2p_session_mbe_err_log() { return s2p_session_mbe_err_log_; }





  S2pSessionEccInjCtrlRMutable &s2p_session_ecc_ctrl() { return s2p_session_ecc_ctrl_; }





  MirrCrcCtrlRMutable &mirr_crc_ctrl() { return mirr_crc_ctrl_; }





  MirrorS2pCnt48IncMutable &ctr48() { return ctr48_; }






  MirrorS2pDprsrBubbleWidthRMutable &dprsr_bubble() { return dprsr_bubble_; }





  MirrorS2pCurrCreditsRMutable &curr_s2p() { return curr_s2p_; }
  MirrorS2pRegsIntrMutable &intr() { return intr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      s2p_credit_cfg_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      sess_entry_word0_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      sess_entry_word1_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      sess_entry_word2_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      sess_entry_word3_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      sess_entry_word4_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      coal_to_interval_.read( offset, data );
    }
    else if (offset >= 0x94 && offset < 0x98) {
      offset -= 0x94;
      if (read_callback_) read_callback_();
      s2p_session_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x98 && offset < 0x9c) {
      offset -= 0x98;
      if (read_callback_) read_callback_();
      s2p_session_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x9c && offset < 0xa0) {
      offset -= 0x9c;
      if (read_callback_) read_callback_();
      s2p_session_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa0 && offset < 0xa4) {
      offset -= 0xa0;
      if (read_callback_) read_callback_();
      mirr_crc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      if (read_callback_) read_callback_();
      ctr48_.read( offset, data );
    }
    else if (offset >= 0xb0 && offset < 0xb4) {
      offset -= 0xb0;
      if (read_callback_) read_callback_();
      dprsr_bubble_.read( offset, data );
    }
    else if (offset >= 0xb4 && offset < 0xb8) {
      offset -= 0xb4;
      if (read_callback_) read_callback_();
      curr_s2p_.read( offset, data );
    }
    else if (offset >= 0x80 && offset < 0x94) {
      offset -= 0x80;
      if (read_callback_) read_callback_();
      intr_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      s2p_credit_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      sess_entry_word0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      sess_entry_word1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      sess_entry_word2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      sess_entry_word3_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      sess_entry_word4_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      coal_to_interval_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x94 && offset < 0x98) {
      offset -= 0x94;
      s2p_session_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x98 && offset < 0x9c) {
      offset -= 0x98;
      s2p_session_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x9c && offset < 0xa0) {
      offset -= 0x9c;
      s2p_session_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa0 && offset < 0xa4) {
      offset -= 0xa0;
      mirr_crc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      ctr48_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb0 && offset < 0xb4) {
      offset -= 0xb0;
      dprsr_bubble_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb4 && offset < 0xb8) {
      offset -= 0xb4;
      curr_s2p_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80 && offset < 0x94) {
      offset -= 0x80;
      intr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    s2p_credit_cfg_.reset();
    sess_entry_word0_.reset();
    sess_entry_word1_.reset();
    sess_entry_word2_.reset();
    sess_entry_word3_.reset();
    sess_entry_word4_.reset();
    coal_to_interval_.reset();
    s2p_session_sbe_err_log_.reset();
    s2p_session_mbe_err_log_.reset();
    s2p_session_ecc_ctrl_.reset();
    mirr_crc_ctrl_.reset();
    ctr48_.reset();
    dprsr_bubble_.reset();
    curr_s2p_.reset();
    intr_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += s2p_credit_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += sess_entry_word0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += sess_entry_word1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += sess_entry_word2_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += sess_entry_word3_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += sess_entry_word4_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += coal_to_interval_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x94 && offset < 0x98) {
      offset -= 0x94;
      r += s2p_session_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x98 && offset < 0x9c) {
      offset -= 0x98;
      r += s2p_session_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x9c && offset < 0xa0) {
      offset -= 0x9c;
      r += s2p_session_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa0 && offset < 0xa4) {
      offset -= 0xa0;
      r += mirr_crc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      r += ctr48_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb0 && offset < 0xb4) {
      offset -= 0xb0;
      r += dprsr_bubble_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb4 && offset < 0xb8) {
      offset -= 0xb4;
      r += curr_s2p_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80 && offset < 0x94) {
      offset -= 0x80;
      r += intr_.to_string(offset,print_zeros,indent_string) ;
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
    r += s2p_credit_cfg_.to_string(print_zeros,indent_string) ;
    r += sess_entry_word0_.to_string(print_zeros,indent_string) ;
    r += sess_entry_word1_.to_string(print_zeros,indent_string) ;
    r += sess_entry_word2_.to_string(print_zeros,indent_string) ;
    r += sess_entry_word3_.to_string(print_zeros,indent_string) ;
    r += sess_entry_word4_.to_string(print_zeros,indent_string) ;
    r += coal_to_interval_.to_string(print_zeros,indent_string) ;
    r += s2p_session_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += s2p_session_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += s2p_session_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += mirr_crc_ctrl_.to_string(print_zeros,indent_string) ;
    r += ctr48_.to_string(print_zeros,indent_string) ;
    r += dprsr_bubble_.to_string(print_zeros,indent_string) ;
    r += curr_s2p_.to_string(print_zeros,indent_string) ;
    r += intr_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  S2pCreditsConfigRMutable s2p_credit_cfg_;
  MirrS2pSessCfgWord0RMutable sess_entry_word0_;
  MirrS2pSessCfgWord1RMutable sess_entry_word1_;
  MirrS2pSessCfgWord2RMutable sess_entry_word2_;
  MirrS2pSessCfgWord3RMutable sess_entry_word3_;
  MirrS2pSessCfgWord4RMutable sess_entry_word4_;
  MirrS2pCoalToIntervalRMutable coal_to_interval_;
  MirrorS2pRegsS2pSessionSbeErrLogMutable s2p_session_sbe_err_log_;
  MirrorS2pRegsS2pSessionMbeErrLogMutable s2p_session_mbe_err_log_;
  S2pSessionEccInjCtrlRMutable s2p_session_ecc_ctrl_;
  MirrCrcCtrlRMutable mirr_crc_ctrl_;
  MirrorS2pCnt48IncMutable ctr48_;
  MirrorS2pDprsrBubbleWidthRMutable dprsr_bubble_;
  MirrorS2pCurrCreditsRMutable curr_s2p_;
  MirrorS2pRegsIntrMutable intr_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x80000; // to get to mirreg
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MIRROR_S2P_REGS_MUTABLE_H__
