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
#ifndef __REGISTER_INCLUDES_MAU_CFG_REGS_ADDRMAP_H__
#define __REGISTER_INCLUDES_MAU_CFG_REGS_ADDRMAP_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "amod_ecc.h"
#include "amod_ecc_mbe_errlog.h"
#include "amod_ecc_sbe_errlog.h"
#include "amod_pre_drain_delay.h"
#include "amod_protocol_errlog.h"
#include "amod_req_interval.h"
#include "amod_req_limit.h"
#include "amod_wide_bubble_rsp_delay.h"
#include "idle_dump_ctl.h"
#include "intr_decode_top.h"
#include "intr_enable0_mau_cfg.h"
#include "intr_enable1_mau_cfg.h"
#include "intr_freeze_enable_mau_cfg.h"
#include "intr_inject_mau_cfg.h"
#include "intr_status_mau_cfg.h"
#include "mau_cfg_cmd_queue_timeout.h"
#include "mau_cfg_dram_thread.h"
#include "mau_cfg_imem_bubble_req.h"
#include "mau_cfg_lt_thread.h"
#include "mau_cfg_mem_slow_mode.h"
#include "mau_cfg_movereg_tcam_only.h"
#include "mau_cfg_mram_thread.h"
#include "mau_cfg_sreq_timeout.h"
#include "mau_cfg_stats_alu_lt.h"
#include "mau_cfg_uram_thread.h"
#include "mau_diag_cfg_ctl.h"
#include "mau_diag_cfg_oxbar_ctl.h"
#include "mau_diag_pbus_enable.h"
#include "mau_diag_tcam_hit_xbar_ctl.h"
#include "mau_diag_valid_ctl.h"
#include "pbs_creq_ecc.h"
#include "pbs_creq_errlog.h"
#include "pbs_cresp_ecc.h"
#include "pbs_cresp_errlog.h"
#include "pbs_sreq_ecc.h"
#include "pbs_sreq_errlog.h"
#include "q_hole_acc_errlog_hi.h"
#include "q_hole_acc_errlog_lo.h"
#include "sreq_idle_timeout_errlog.h"
#include "sreq_stats_timeout_errlog.h"
#include "stage_dump_ctl.h"
#include "stats_dump_ctl.h"
#include "tcam_scrub_ctl.h"

namespace jbay {
  namespace register_classes {

class MauCfgRegsAddrmap : public model_core::RegisterBlock<RegisterCallback> {
public:
  MauCfgRegsAddrmap(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap), 512, false, write_callback, read_callback, std::string("MauCfgRegsAddrmap")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap))
    {
    }
  MauCfgRegsAddrmap(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MauCfgRegsAddrmap")
    {
    }
public:






  PbsCrespEcc &pbs_cresp_ecc() { return pbs_cresp_ecc_; }






  PbsSreqEcc &pbs_sreq_ecc() { return pbs_sreq_ecc_; }





  AmodEcc &amod_ecc() { return amod_ecc_; }





  AmodEccSbeErrlog &amod_ecc_sbe_errlog() { return amod_ecc_sbe_errlog_; }





  AmodEccMbeErrlog &amod_ecc_mbe_errlog() { return amod_ecc_mbe_errlog_; }






  AmodReqInterval &amod_req_interval() { return amod_req_interval_; }






  AmodReqLimit &amod_req_limit() { return amod_req_limit_; }






  IntrStatusMauCfg &intr_status_mau_cfg() { return intr_status_mau_cfg_; }






  IntrEnable0MauCfg &intr_enable0_mau_cfg() { return intr_enable0_mau_cfg_; }






  IntrEnable1MauCfg &intr_enable1_mau_cfg() { return intr_enable1_mau_cfg_; }







  IntrInjectMauCfg &intr_inject_mau_cfg() { return intr_inject_mau_cfg_; }





  IntrFreezeEnableMauCfg &intr_freeze_enable_mau_cfg() { return intr_freeze_enable_mau_cfg_; }






  IntrDecodeTop &intr_decode_top() { return intr_decode_top_; }






  QHoleAccErrlogHi &q_hole_acc_errlog_hi() { return q_hole_acc_errlog_hi_; }






  QHoleAccErrlogLo &q_hole_acc_errlog_lo() { return q_hole_acc_errlog_lo_; }





  SreqStatsTimeoutErrlog &sreq_stats_timeout_errlog() { return sreq_stats_timeout_errlog_; }





  SreqIdleTimeoutErrlog &sreq_idle_timeout_errlog() { return sreq_idle_timeout_errlog_; }






  MauCfgMoveregTcamOnly &mau_cfg_movereg_tcam_only() { return mau_cfg_movereg_tcam_only_; }







  MauCfgMemSlowMode &mau_cfg_mem_slow_mode() { return mau_cfg_mem_slow_mode_; }






  MauCfgLtThread &mau_cfg_lt_thread() { return mau_cfg_lt_thread_; }






  MauCfgDramThread &mau_cfg_dram_thread() { return mau_cfg_dram_thread_; }







  MauCfgImemBubbleReq &mau_cfg_imem_bubble_req() { return mau_cfg_imem_bubble_req_; }







  MauCfgCmdQueueTimeout &mau_cfg_cmd_queue_timeout() { return mau_cfg_cmd_queue_timeout_; }





  MauDiagPbusEnable &mau_diag_pbus_enable() { return mau_diag_pbus_enable_; }








  StatsDumpCtl &stats_dump_ctl(int j0) { return stats_dump_ctl_[j0]; }








  IdleDumpCtl &idle_dump_ctl(int j0) { return idle_dump_ctl_[j0]; }





  MauDiagValidCtl &mau_diag_valid_ctl() { return mau_diag_valid_ctl_; }






  MauDiagCfgCtl &mau_diag_cfg_ctl() { return mau_diag_cfg_ctl_; }











  MauDiagTcamHitXbarCtl &mau_diag_tcam_hit_xbar_ctl() { return mau_diag_tcam_hit_xbar_ctl_; }











  AmodProtocolErrlog &amod_protocol_errlog() { return amod_protocol_errlog_; }









  MauDiagCfgOxbarCtl &mau_diag_cfg_oxbar_ctl(int j0) { return mau_diag_cfg_oxbar_ctl_[j0]; }









  PbsCreqErrlog &pbs_creq_errlog(int j0) { return pbs_creq_errlog_[j0]; }









  PbsCrespErrlog &pbs_cresp_errlog(int j0) { return pbs_cresp_errlog_[j0]; }









  PbsSreqErrlog &pbs_sreq_errlog(int j0) { return pbs_sreq_errlog_[j0]; }














  MauCfgStatsAluLt &mau_cfg_stats_alu_lt(int j0) { return mau_cfg_stats_alu_lt_[j0]; }








  MauCfgUramThread &mau_cfg_uram_thread(int j0) { return mau_cfg_uram_thread_[j0]; }














  AmodPreDrainDelay &amod_pre_drain_delay(int j0) { return amod_pre_drain_delay_[j0]; }










  AmodWideBubbleRspDelay &amod_wide_bubble_rsp_delay(int j0) { return amod_wide_bubble_rsp_delay_[j0]; }








  MauCfgMramThread &mau_cfg_mram_thread(int j0) { return mau_cfg_mram_thread_[j0]; }








  MauCfgSreqTimeout &mau_cfg_sreq_timeout(int j0) { return mau_cfg_sreq_timeout_[j0]; }





  TcamScrubCtl &tcam_scrub_ctl() { return tcam_scrub_ctl_; }






  StageDumpCtl &stage_dump_ctl() { return stage_dump_ctl_; }






  PbsCreqEcc &pbs_creq_ecc() { return pbs_creq_ecc_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      pbs_cresp_ecc_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      pbs_sreq_ecc_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      amod_ecc_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      amod_ecc_sbe_errlog_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      amod_ecc_mbe_errlog_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      amod_req_interval_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      amod_req_limit_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      intr_status_mau_cfg_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      intr_enable0_mau_cfg_.read( offset, data );
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      if (read_callback_) read_callback_();
      intr_enable1_mau_cfg_.read( offset, data );
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      if (read_callback_) read_callback_();
      intr_inject_mau_cfg_.read( offset, data );
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      if (read_callback_) read_callback_();
      intr_freeze_enable_mau_cfg_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      intr_decode_top_.read( offset, data );
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      if (read_callback_) read_callback_();
      q_hole_acc_errlog_hi_.read( offset, data );
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      if (read_callback_) read_callback_();
      q_hole_acc_errlog_lo_.read( offset, data );
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      if (read_callback_) read_callback_();
      sreq_stats_timeout_errlog_.read( offset, data );
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      if (read_callback_) read_callback_();
      sreq_idle_timeout_errlog_.read( offset, data );
    }
    else if (offset >= 0x84 && offset < 0x88) {
      offset -= 0x84;
      if (read_callback_) read_callback_();
      mau_cfg_movereg_tcam_only_.read( offset, data );
    }
    else if (offset >= 0x88 && offset < 0x8c) {
      offset -= 0x88;
      if (read_callback_) read_callback_();
      mau_cfg_mem_slow_mode_.read( offset, data );
    }
    else if (offset >= 0x8c && offset < 0x90) {
      offset -= 0x8c;
      if (read_callback_) read_callback_();
      mau_cfg_lt_thread_.read( offset, data );
    }
    else if (offset >= 0x90 && offset < 0x94) {
      offset -= 0x90;
      if (read_callback_) read_callback_();
      mau_cfg_dram_thread_.read( offset, data );
    }
    else if (offset >= 0x94 && offset < 0x98) {
      offset -= 0x94;
      if (read_callback_) read_callback_();
      mau_cfg_imem_bubble_req_.read( offset, data );
    }
    else if (offset >= 0x98 && offset < 0x9c) {
      offset -= 0x98;
      if (read_callback_) read_callback_();
      mau_cfg_cmd_queue_timeout_.read( offset, data );
    }
    else if (offset >= 0x9c && offset < 0xa0) {
      offset -= 0x9c;
      if (read_callback_) read_callback_();
      mau_diag_pbus_enable_.read( offset, data );
    }
    else if (offset >= 0xc0 && offset < 0x100) {
      offset -= 0xc0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      stats_dump_ctl_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x100 && offset < 0x140) {
      offset -= 0x100;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      idle_dump_ctl_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x140 && offset < 0x144) {
      offset -= 0x140;
      if (read_callback_) read_callback_();
      mau_diag_valid_ctl_.read( offset, data );
    }
    else if (offset >= 0x144 && offset < 0x148) {
      offset -= 0x144;
      if (read_callback_) read_callback_();
      mau_diag_cfg_ctl_.read( offset, data );
    }
    else if (offset >= 0x148 && offset < 0x14c) {
      offset -= 0x148;
      if (read_callback_) read_callback_();
      mau_diag_tcam_hit_xbar_ctl_.read( offset, data );
    }
    else if (offset >= 0x14c && offset < 0x150) {
      offset -= 0x14c;
      if (read_callback_) read_callback_();
      amod_protocol_errlog_.read( offset, data );
    }
    else if (offset >= 0x160 && offset < 0x180) {
      offset -= 0x160;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      mau_diag_cfg_oxbar_ctl_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x180 && offset < 0x190) {
      offset -= 0x180;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      pbs_creq_errlog_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x190 && offset < 0x1a0) {
      offset -= 0x190;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      pbs_cresp_errlog_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1a0 && offset < 0x1b0) {
      offset -= 0x1a0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      pbs_sreq_errlog_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1b0 && offset < 0x1c0) {
      offset -= 0x1b0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      mau_cfg_stats_alu_lt_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1c0 && offset < 0x1cc) {
      offset -= 0x1c0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      mau_cfg_uram_thread_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1d0 && offset < 0x1d8) {
      offset -= 0x1d0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      amod_pre_drain_delay_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1d8 && offset < 0x1e0) {
      offset -= 0x1d8;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      amod_wide_bubble_rsp_delay_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1e0 && offset < 0x1e8) {
      offset -= 0x1e0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      mau_cfg_mram_thread_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1e8 && offset < 0x1f0) {
      offset -= 0x1e8;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      mau_cfg_sreq_timeout_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x1f4 && offset < 0x1f8) {
      offset -= 0x1f4;
      if (read_callback_) read_callback_();
      tcam_scrub_ctl_.read( offset, data );
    }
    else if (offset >= 0x1f8 && offset < 0x1fc) {
      offset -= 0x1f8;
      if (read_callback_) read_callback_();
      stage_dump_ctl_.read( offset, data );
    }
    else if (offset >= 0x1fc && offset < 0x200) {
      offset -= 0x1fc;
      if (read_callback_) read_callback_();
      pbs_creq_ecc_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      pbs_cresp_ecc_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      pbs_sreq_ecc_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      amod_ecc_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      amod_ecc_sbe_errlog_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      amod_ecc_mbe_errlog_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      amod_req_interval_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      amod_req_limit_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      intr_status_mau_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      intr_enable0_mau_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      intr_enable1_mau_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      intr_inject_mau_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      intr_freeze_enable_mau_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      intr_decode_top_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      q_hole_acc_errlog_hi_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      q_hole_acc_errlog_lo_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      sreq_stats_timeout_errlog_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      sreq_idle_timeout_errlog_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x84 && offset < 0x88) {
      offset -= 0x84;
      mau_cfg_movereg_tcam_only_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x88 && offset < 0x8c) {
      offset -= 0x88;
      mau_cfg_mem_slow_mode_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8c && offset < 0x90) {
      offset -= 0x8c;
      mau_cfg_lt_thread_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x90 && offset < 0x94) {
      offset -= 0x90;
      mau_cfg_dram_thread_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x94 && offset < 0x98) {
      offset -= 0x94;
      mau_cfg_imem_bubble_req_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x98 && offset < 0x9c) {
      offset -= 0x98;
      mau_cfg_cmd_queue_timeout_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x9c && offset < 0xa0) {
      offset -= 0x9c;
      mau_diag_pbus_enable_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc0 && offset < 0x100) {
      offset -= 0xc0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      stats_dump_ctl_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x100 && offset < 0x140) {
      offset -= 0x100;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      idle_dump_ctl_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x140 && offset < 0x144) {
      offset -= 0x140;
      mau_diag_valid_ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x144 && offset < 0x148) {
      offset -= 0x144;
      mau_diag_cfg_ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x148 && offset < 0x14c) {
      offset -= 0x148;
      mau_diag_tcam_hit_xbar_ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14c && offset < 0x150) {
      offset -= 0x14c;
      amod_protocol_errlog_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x160 && offset < 0x180) {
      offset -= 0x160;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      mau_diag_cfg_oxbar_ctl_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x180 && offset < 0x190) {
      offset -= 0x180;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      pbs_creq_errlog_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x190 && offset < 0x1a0) {
      offset -= 0x190;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      pbs_cresp_errlog_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1a0 && offset < 0x1b0) {
      offset -= 0x1a0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      pbs_sreq_errlog_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1b0 && offset < 0x1c0) {
      offset -= 0x1b0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      mau_cfg_stats_alu_lt_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c0 && offset < 0x1cc) {
      offset -= 0x1c0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      mau_cfg_uram_thread_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1d0 && offset < 0x1d8) {
      offset -= 0x1d0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      amod_pre_drain_delay_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1d8 && offset < 0x1e0) {
      offset -= 0x1d8;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      amod_wide_bubble_rsp_delay_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1e0 && offset < 0x1e8) {
      offset -= 0x1e0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      mau_cfg_mram_thread_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1e8 && offset < 0x1f0) {
      offset -= 0x1e8;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      mau_cfg_sreq_timeout_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1f4 && offset < 0x1f8) {
      offset -= 0x1f4;
      tcam_scrub_ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1f8 && offset < 0x1fc) {
      offset -= 0x1f8;
      stage_dump_ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1fc && offset < 0x200) {
      offset -= 0x1fc;
      pbs_creq_ecc_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    pbs_cresp_ecc_.reset();
    pbs_sreq_ecc_.reset();
    amod_ecc_.reset();
    amod_ecc_sbe_errlog_.reset();
    amod_ecc_mbe_errlog_.reset();
    amod_req_interval_.reset();
    amod_req_limit_.reset();
    intr_status_mau_cfg_.reset();
    intr_enable0_mau_cfg_.reset();
    intr_enable1_mau_cfg_.reset();
    intr_inject_mau_cfg_.reset();
    intr_freeze_enable_mau_cfg_.reset();
    intr_decode_top_.reset();
    q_hole_acc_errlog_hi_.reset();
    q_hole_acc_errlog_lo_.reset();
    sreq_stats_timeout_errlog_.reset();
    sreq_idle_timeout_errlog_.reset();
    mau_cfg_movereg_tcam_only_.reset();
    mau_cfg_mem_slow_mode_.reset();
    mau_cfg_lt_thread_.reset();
    mau_cfg_dram_thread_.reset();
    mau_cfg_imem_bubble_req_.reset();
    mau_cfg_cmd_queue_timeout_.reset();
    mau_diag_pbus_enable_.reset();
    for (auto &f0 : stats_dump_ctl_) {
      f0.reset();
    }
    for (auto &f0 : idle_dump_ctl_) {
      f0.reset();
    }
    mau_diag_valid_ctl_.reset();
    mau_diag_cfg_ctl_.reset();
    mau_diag_tcam_hit_xbar_ctl_.reset();
    amod_protocol_errlog_.reset();
    for (auto &f0 : mau_diag_cfg_oxbar_ctl_) {
      f0.reset();
    }
    for (auto &f0 : pbs_creq_errlog_) {
      f0.reset();
    }
    for (auto &f0 : pbs_cresp_errlog_) {
      f0.reset();
    }
    for (auto &f0 : pbs_sreq_errlog_) {
      f0.reset();
    }
    for (auto &f0 : mau_cfg_stats_alu_lt_) {
      f0.reset();
    }
    for (auto &f0 : mau_cfg_uram_thread_) {
      f0.reset();
    }
    for (auto &f0 : amod_pre_drain_delay_) {
      f0.reset();
    }
    for (auto &f0 : amod_wide_bubble_rsp_delay_) {
      f0.reset();
    }
    for (auto &f0 : mau_cfg_mram_thread_) {
      f0.reset();
    }
    for (auto &f0 : mau_cfg_sreq_timeout_) {
      f0.reset();
    }
    tcam_scrub_ctl_.reset();
    stage_dump_ctl_.reset();
    pbs_creq_ecc_.reset();
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
      r += pbs_cresp_ecc_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += pbs_sreq_ecc_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += amod_ecc_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += amod_ecc_sbe_errlog_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += amod_ecc_mbe_errlog_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += amod_req_interval_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += amod_req_limit_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += intr_status_mau_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += intr_enable0_mau_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      r += intr_enable1_mau_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      r += intr_inject_mau_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      r += intr_freeze_enable_mau_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      r += intr_decode_top_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      r += q_hole_acc_errlog_hi_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      r += q_hole_acc_errlog_lo_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      r += sreq_stats_timeout_errlog_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      r += sreq_idle_timeout_errlog_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x84 && offset < 0x88) {
      offset -= 0x84;
      r += mau_cfg_movereg_tcam_only_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x88 && offset < 0x8c) {
      offset -= 0x88;
      r += mau_cfg_mem_slow_mode_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8c && offset < 0x90) {
      offset -= 0x8c;
      r += mau_cfg_lt_thread_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x90 && offset < 0x94) {
      offset -= 0x90;
      r += mau_cfg_dram_thread_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x94 && offset < 0x98) {
      offset -= 0x94;
      r += mau_cfg_imem_bubble_req_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x98 && offset < 0x9c) {
      offset -= 0x98;
      r += mau_cfg_cmd_queue_timeout_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x9c && offset < 0xa0) {
      offset -= 0x9c;
      r += mau_diag_pbus_enable_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc0 && offset < 0x100) {
      offset -= 0xc0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += stats_dump_ctl_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x100 && offset < 0x140) {
      offset -= 0x100;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += idle_dump_ctl_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x140 && offset < 0x144) {
      offset -= 0x140;
      r += mau_diag_valid_ctl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x144 && offset < 0x148) {
      offset -= 0x144;
      r += mau_diag_cfg_ctl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x148 && offset < 0x14c) {
      offset -= 0x148;
      r += mau_diag_tcam_hit_xbar_ctl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14c && offset < 0x150) {
      offset -= 0x14c;
      r += amod_protocol_errlog_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x160 && offset < 0x180) {
      offset -= 0x160;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += mau_diag_cfg_oxbar_ctl_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x180 && offset < 0x190) {
      offset -= 0x180;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += pbs_creq_errlog_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x190 && offset < 0x1a0) {
      offset -= 0x190;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += pbs_cresp_errlog_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1a0 && offset < 0x1b0) {
      offset -= 0x1a0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += pbs_sreq_errlog_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1b0 && offset < 0x1c0) {
      offset -= 0x1b0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += mau_cfg_stats_alu_lt_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c0 && offset < 0x1cc) {
      offset -= 0x1c0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += mau_cfg_uram_thread_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1d0 && offset < 0x1d8) {
      offset -= 0x1d0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += amod_pre_drain_delay_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1d8 && offset < 0x1e0) {
      offset -= 0x1d8;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += amod_wide_bubble_rsp_delay_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1e0 && offset < 0x1e8) {
      offset -= 0x1e0;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += mau_cfg_mram_thread_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1e8 && offset < 0x1f0) {
      offset -= 0x1e8;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += mau_cfg_sreq_timeout_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1f4 && offset < 0x1f8) {
      offset -= 0x1f4;
      r += tcam_scrub_ctl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1f8 && offset < 0x1fc) {
      offset -= 0x1f8;
      r += stage_dump_ctl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1fc && offset < 0x200) {
      offset -= 0x1fc;
      r += pbs_creq_ecc_.to_string(offset,print_zeros,indent_string) ;
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
    r += pbs_cresp_ecc_.to_string(print_zeros,indent_string) ;
    r += pbs_sreq_ecc_.to_string(print_zeros,indent_string) ;
    r += amod_ecc_.to_string(print_zeros,indent_string) ;
    r += amod_ecc_sbe_errlog_.to_string(print_zeros,indent_string) ;
    r += amod_ecc_mbe_errlog_.to_string(print_zeros,indent_string) ;
    r += amod_req_interval_.to_string(print_zeros,indent_string) ;
    r += amod_req_limit_.to_string(print_zeros,indent_string) ;
    r += intr_status_mau_cfg_.to_string(print_zeros,indent_string) ;
    r += intr_enable0_mau_cfg_.to_string(print_zeros,indent_string) ;
    r += intr_enable1_mau_cfg_.to_string(print_zeros,indent_string) ;
    r += intr_inject_mau_cfg_.to_string(print_zeros,indent_string) ;
    r += intr_freeze_enable_mau_cfg_.to_string(print_zeros,indent_string) ;
    r += intr_decode_top_.to_string(print_zeros,indent_string) ;
    r += q_hole_acc_errlog_hi_.to_string(print_zeros,indent_string) ;
    r += q_hole_acc_errlog_lo_.to_string(print_zeros,indent_string) ;
    r += sreq_stats_timeout_errlog_.to_string(print_zeros,indent_string) ;
    r += sreq_idle_timeout_errlog_.to_string(print_zeros,indent_string) ;
    r += mau_cfg_movereg_tcam_only_.to_string(print_zeros,indent_string) ;
    r += mau_cfg_mem_slow_mode_.to_string(print_zeros,indent_string) ;
    r += mau_cfg_lt_thread_.to_string(print_zeros,indent_string) ;
    r += mau_cfg_dram_thread_.to_string(print_zeros,indent_string) ;
    r += mau_cfg_imem_bubble_req_.to_string(print_zeros,indent_string) ;
    r += mau_cfg_cmd_queue_timeout_.to_string(print_zeros,indent_string) ;
    r += mau_diag_pbus_enable_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<16;++a0) {
      r += stats_dump_ctl_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<16;++a0) {
      r += idle_dump_ctl_[a0].to_string(print_zeros,indent_string) ;
    }
    r += mau_diag_valid_ctl_.to_string(print_zeros,indent_string) ;
    r += mau_diag_cfg_ctl_.to_string(print_zeros,indent_string) ;
    r += mau_diag_tcam_hit_xbar_ctl_.to_string(print_zeros,indent_string) ;
    r += amod_protocol_errlog_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<8;++a0) {
      r += mau_diag_cfg_oxbar_ctl_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<4;++a0) {
      r += pbs_creq_errlog_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<4;++a0) {
      r += pbs_cresp_errlog_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<4;++a0) {
      r += pbs_sreq_errlog_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<4;++a0) {
      r += mau_cfg_stats_alu_lt_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<3;++a0) {
      r += mau_cfg_uram_thread_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<2;++a0) {
      r += amod_pre_drain_delay_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<2;++a0) {
      r += amod_wide_bubble_rsp_delay_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<2;++a0) {
      r += mau_cfg_mram_thread_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<2;++a0) {
      r += mau_cfg_sreq_timeout_[a0].to_string(print_zeros,indent_string) ;
    }
    r += tcam_scrub_ctl_.to_string(print_zeros,indent_string) ;
    r += stage_dump_ctl_.to_string(print_zeros,indent_string) ;
    r += pbs_creq_ecc_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  PbsCrespEcc pbs_cresp_ecc_;
  PbsSreqEcc pbs_sreq_ecc_;
  AmodEcc amod_ecc_;
  AmodEccSbeErrlog amod_ecc_sbe_errlog_;
  AmodEccMbeErrlog amod_ecc_mbe_errlog_;
  AmodReqInterval amod_req_interval_;
  AmodReqLimit amod_req_limit_;
  IntrStatusMauCfg intr_status_mau_cfg_;
  IntrEnable0MauCfg intr_enable0_mau_cfg_;
  IntrEnable1MauCfg intr_enable1_mau_cfg_;
  IntrInjectMauCfg intr_inject_mau_cfg_;
  IntrFreezeEnableMauCfg intr_freeze_enable_mau_cfg_;
  IntrDecodeTop intr_decode_top_;
  QHoleAccErrlogHi q_hole_acc_errlog_hi_;
  QHoleAccErrlogLo q_hole_acc_errlog_lo_;
  SreqStatsTimeoutErrlog sreq_stats_timeout_errlog_;
  SreqIdleTimeoutErrlog sreq_idle_timeout_errlog_;
  MauCfgMoveregTcamOnly mau_cfg_movereg_tcam_only_;
  MauCfgMemSlowMode mau_cfg_mem_slow_mode_;
  MauCfgLtThread mau_cfg_lt_thread_;
  MauCfgDramThread mau_cfg_dram_thread_;
  MauCfgImemBubbleReq mau_cfg_imem_bubble_req_;
  MauCfgCmdQueueTimeout mau_cfg_cmd_queue_timeout_;
  MauDiagPbusEnable mau_diag_pbus_enable_;
  std::array< StatsDumpCtl, 16 > stats_dump_ctl_;
  std::array< IdleDumpCtl, 16 > idle_dump_ctl_;
  MauDiagValidCtl mau_diag_valid_ctl_;
  MauDiagCfgCtl mau_diag_cfg_ctl_;
  MauDiagTcamHitXbarCtl mau_diag_tcam_hit_xbar_ctl_;
  AmodProtocolErrlog amod_protocol_errlog_;
  std::array< MauDiagCfgOxbarCtl, 8 > mau_diag_cfg_oxbar_ctl_;
  std::array< PbsCreqErrlog, 4 > pbs_creq_errlog_;
  std::array< PbsCrespErrlog, 4 > pbs_cresp_errlog_;
  std::array< PbsSreqErrlog, 4 > pbs_sreq_errlog_;
  std::array< MauCfgStatsAluLt, 4 > mau_cfg_stats_alu_lt_;
  std::array< MauCfgUramThread, 3 > mau_cfg_uram_thread_;
  std::array< AmodPreDrainDelay, 2 > amod_pre_drain_delay_;
  std::array< AmodWideBubbleRspDelay, 2 > amod_wide_bubble_rsp_delay_;
  std::array< MauCfgMramThread, 2 > mau_cfg_mram_thread_;
  std::array< MauCfgSreqTimeout, 2 > mau_cfg_sreq_timeout_;
  TcamScrubCtl tcam_scrub_ctl_;
  StageDumpCtl stage_dump_ctl_;
  PbsCreqEcc pbs_creq_ecc_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x40000; // to get to cfg_regs
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_MAU_CFG_REGS_ADDRMAP_H__
