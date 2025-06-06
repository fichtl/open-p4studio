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
#ifndef __REGISTER_INCLUDES_IPB_RSPEC_CHAN2_GROUP_MUTABLE_H__
#define __REGISTER_INCLUDES_IPB_RSPEC_CHAN2_GROUP_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "chnl_acc_ctrl_mutable.h"
#include "chnl_acc_stat_mutable.h"
#include "chnl_ctrl_mutable.h"
#include "chnl_deparser_drop_pkt_mutable.h"
#include "chnl_deparser_send_pkt_mutable.h"
#include "chnl_drop_trunc_pkt_mutable.h"
#include "chnl_fifo_ctrl_mutable.h"
#include "chnl_macs_received_pkt_mutable.h"
#include "chnl_meta_mutable.h"
#include "chnl_metanum_cfg_mutable.h"
#include "chnl_metanum_mutable.h"
#include "chnl_parser_discard_pkt_mutable.h"
#include "chnl_parser_send_pkt_mutable.h"
#include "chnl_pktnum0_cfg_mutable.h"
#include "chnl_pktnum0_mutable.h"
#include "chnl_pktnum1_cfg_mutable.h"
#include "chnl_pktnum1_mutable.h"
#include "chnl_resubmit_discard_pkt_mutable.h"
#include "chnl_resubmit_received_pkt_mutable.h"
#include "chnl_stat_mutable.h"
#include "chnl_wsch_discard_pkt_mutable.h"
#include "chnl_wsch_trunc_pkt_mutable.h"
#include "meta_fifo_ctrl_mutable.h"

namespace jbayB0 {
  namespace register_classes {

class IpbRspecChan2GroupMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  IpbRspecChan2GroupMutable(
      int chipNumber, int index_pipe_addrmap, int index_ipb_prsr4_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ipb_prsr4_reg), 216, true, write_callback, read_callback, std::string("IpbRspecChan2GroupMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ipb_prsr4_reg))
    {
    }
  IpbRspecChan2GroupMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "IpbRspecChan2GroupMutable")
    {
    }
public:





  ChnlCtrlMutable &chan2_group_chnl_ctrl() { return chan2_group_chnl_ctrl_; }






  ChnlMetaMutable &chan2_group_chnl_meta() { return chan2_group_chnl_meta_; }





  MetaFifoCtrlMutable &chan2_group_meta_fifo_ctrl() { return chan2_group_meta_fifo_ctrl_; }





  ChnlFifoCtrlMutable &chan2_group_chnl_fifo_ctrl() { return chan2_group_chnl_fifo_ctrl_; }





  ChnlAccCtrlMutable &chan2_group_chnl_acc_ctrl() { return chan2_group_chnl_acc_ctrl_; }





  ChnlAccStatMutable &chan2_group_chnl_acc_stat() { return chan2_group_chnl_acc_stat_; }







  ChnlPktnum0CfgMutable &chan2_group_chnl_pktnum0_cfg() { return chan2_group_chnl_pktnum0_cfg_; }







  ChnlPktnum1CfgMutable &chan2_group_chnl_pktnum1_cfg() { return chan2_group_chnl_pktnum1_cfg_; }







  ChnlMetanumCfgMutable &chan2_group_chnl_metanum_cfg() { return chan2_group_chnl_metanum_cfg_; }






  ChnlStatMutable &chan2_group_chnl_stat() { return chan2_group_chnl_stat_; }








  ChnlPktnum0Mutable &chan2_group_chnl_pktnum0() { return chan2_group_chnl_pktnum0_; }






  ChnlPktnum1Mutable &chan2_group_chnl_pktnum1() { return chan2_group_chnl_pktnum1_; }







  ChnlMetanumMutable &chan2_group_chnl_metanum() { return chan2_group_chnl_metanum_; }





  ChnlDeparserDropPktMutable &chan2_group_chnl_deparser_drop_pkt() { return chan2_group_chnl_deparser_drop_pkt_; }









  ChnlWschDiscardPktMutable &chan2_group_chnl_wsch_discard_pkt() { return chan2_group_chnl_wsch_discard_pkt_; }





  ChnlWschTruncPktMutable &chan2_group_chnl_wsch_trunc_pkt() { return chan2_group_chnl_wsch_trunc_pkt_; }





  ChnlDropTruncPktMutable &chan2_group_chnl_drop_trunc_pkt() { return chan2_group_chnl_drop_trunc_pkt_; }





  ChnlResubmitDiscardPktMutable &chan2_group_chnl_resubmit_discard_pkt() { return chan2_group_chnl_resubmit_discard_pkt_; }





  ChnlParserDiscardPktMutable &chan2_group_chnl_parser_discard_pkt() { return chan2_group_chnl_parser_discard_pkt_; }








  ChnlParserSendPktMutable &chan2_group_chnl_parser_send_pkt() { return chan2_group_chnl_parser_send_pkt_; }








  ChnlDeparserSendPktMutable &chan2_group_chnl_deparser_send_pkt() { return chan2_group_chnl_deparser_send_pkt_; }





  ChnlMacsReceivedPktMutable &chan2_group_chnl_macs_received_pkt() { return chan2_group_chnl_macs_received_pkt_; }





  ChnlResubmitReceivedPktMutable &chan2_group_chnl_resubmit_received_pkt() { return chan2_group_chnl_resubmit_received_pkt_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0xa00 && offset < 0xa08) {
      offset -= 0xa00;
      if (read_callback_) read_callback_();
      chan2_group_chnl_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa10 && offset < 0xa20) {
      offset -= 0xa10;
      if (read_callback_) read_callback_();
      chan2_group_chnl_meta_.read( offset, data );
    }
    else if (offset >= 0xa20 && offset < 0xa24) {
      offset -= 0xa20;
      if (read_callback_) read_callback_();
      chan2_group_meta_fifo_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa30 && offset < 0xa3c) {
      offset -= 0xa30;
      if (read_callback_) read_callback_();
      chan2_group_chnl_fifo_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa40 && offset < 0xa4c) {
      offset -= 0xa40;
      if (read_callback_) read_callback_();
      chan2_group_chnl_acc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa4c && offset < 0xa50) {
      offset -= 0xa4c;
      if (read_callback_) read_callback_();
      chan2_group_chnl_acc_stat_.read( offset, data );
    }
    else if (offset >= 0xa50 && offset < 0xa54) {
      offset -= 0xa50;
      if (read_callback_) read_callback_();
      chan2_group_chnl_pktnum0_cfg_.read( offset, data );
    }
    else if (offset >= 0xa54 && offset < 0xa58) {
      offset -= 0xa54;
      if (read_callback_) read_callback_();
      chan2_group_chnl_pktnum1_cfg_.read( offset, data );
    }
    else if (offset >= 0xa58 && offset < 0xa5c) {
      offset -= 0xa58;
      if (read_callback_) read_callback_();
      chan2_group_chnl_metanum_cfg_.read( offset, data );
    }
    else if (offset >= 0xa5c && offset < 0xa60) {
      offset -= 0xa5c;
      if (read_callback_) read_callback_();
      chan2_group_chnl_stat_.read( offset, data );
    }
    else if (offset >= 0xa60 && offset < 0xa64) {
      offset -= 0xa60;
      if (read_callback_) read_callback_();
      chan2_group_chnl_pktnum0_.read( offset, data );
    }
    else if (offset >= 0xa64 && offset < 0xa68) {
      offset -= 0xa64;
      if (read_callback_) read_callback_();
      chan2_group_chnl_pktnum1_.read( offset, data );
    }
    else if (offset >= 0xa68 && offset < 0xa6c) {
      offset -= 0xa68;
      if (read_callback_) read_callback_();
      chan2_group_chnl_metanum_.read( offset, data );
    }
    else if (offset >= 0xa70 && offset < 0xa78) {
      offset -= 0xa70;
      if (read_callback_) read_callback_();
      chan2_group_chnl_deparser_drop_pkt_.read( offset, data );
    }
    else if (offset >= 0xa78 && offset < 0xa80) {
      offset -= 0xa78;
      if (read_callback_) read_callback_();
      chan2_group_chnl_wsch_discard_pkt_.read( offset, data );
    }
    else if (offset >= 0xa80 && offset < 0xa88) {
      offset -= 0xa80;
      if (read_callback_) read_callback_();
      chan2_group_chnl_wsch_trunc_pkt_.read( offset, data );
    }
    else if (offset >= 0xa88 && offset < 0xa90) {
      offset -= 0xa88;
      if (read_callback_) read_callback_();
      chan2_group_chnl_drop_trunc_pkt_.read( offset, data );
    }
    else if (offset >= 0xa90 && offset < 0xa98) {
      offset -= 0xa90;
      if (read_callback_) read_callback_();
      chan2_group_chnl_resubmit_discard_pkt_.read( offset, data );
    }
    else if (offset >= 0xa98 && offset < 0xaa0) {
      offset -= 0xa98;
      if (read_callback_) read_callback_();
      chan2_group_chnl_parser_discard_pkt_.read( offset, data );
    }
    else if (offset >= 0xaa0 && offset < 0xaac) {
      offset -= 0xaa0;
      if (read_callback_) read_callback_();
      chan2_group_chnl_parser_send_pkt_.read( offset, data );
    }
    else if (offset >= 0xab0 && offset < 0xabc) {
      offset -= 0xab0;
      if (read_callback_) read_callback_();
      chan2_group_chnl_deparser_send_pkt_.read( offset, data );
    }
    else if (offset >= 0xac0 && offset < 0xacc) {
      offset -= 0xac0;
      if (read_callback_) read_callback_();
      chan2_group_chnl_macs_received_pkt_.read( offset, data );
    }
    else if (offset >= 0xad0 && offset < 0xad8) {
      offset -= 0xad0;
      if (read_callback_) read_callback_();
      chan2_group_chnl_resubmit_received_pkt_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0xa00 && offset < 0xa08) {
      offset -= 0xa00;
      chan2_group_chnl_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa10 && offset < 0xa20) {
      offset -= 0xa10;
      chan2_group_chnl_meta_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa20 && offset < 0xa24) {
      offset -= 0xa20;
      chan2_group_meta_fifo_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa30 && offset < 0xa3c) {
      offset -= 0xa30;
      chan2_group_chnl_fifo_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa40 && offset < 0xa4c) {
      offset -= 0xa40;
      chan2_group_chnl_acc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa4c && offset < 0xa50) {
      offset -= 0xa4c;
      chan2_group_chnl_acc_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa50 && offset < 0xa54) {
      offset -= 0xa50;
      chan2_group_chnl_pktnum0_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa54 && offset < 0xa58) {
      offset -= 0xa54;
      chan2_group_chnl_pktnum1_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa58 && offset < 0xa5c) {
      offset -= 0xa58;
      chan2_group_chnl_metanum_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa5c && offset < 0xa60) {
      offset -= 0xa5c;
      chan2_group_chnl_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa60 && offset < 0xa64) {
      offset -= 0xa60;
      chan2_group_chnl_pktnum0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa64 && offset < 0xa68) {
      offset -= 0xa64;
      chan2_group_chnl_pktnum1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa68 && offset < 0xa6c) {
      offset -= 0xa68;
      chan2_group_chnl_metanum_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa70 && offset < 0xa78) {
      offset -= 0xa70;
      chan2_group_chnl_deparser_drop_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa78 && offset < 0xa80) {
      offset -= 0xa78;
      chan2_group_chnl_wsch_discard_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa80 && offset < 0xa88) {
      offset -= 0xa80;
      chan2_group_chnl_wsch_trunc_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa88 && offset < 0xa90) {
      offset -= 0xa88;
      chan2_group_chnl_drop_trunc_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa90 && offset < 0xa98) {
      offset -= 0xa90;
      chan2_group_chnl_resubmit_discard_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa98 && offset < 0xaa0) {
      offset -= 0xa98;
      chan2_group_chnl_parser_discard_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xaa0 && offset < 0xaac) {
      offset -= 0xaa0;
      chan2_group_chnl_parser_send_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xab0 && offset < 0xabc) {
      offset -= 0xab0;
      chan2_group_chnl_deparser_send_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xac0 && offset < 0xacc) {
      offset -= 0xac0;
      chan2_group_chnl_macs_received_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xad0 && offset < 0xad8) {
      offset -= 0xad0;
      chan2_group_chnl_resubmit_received_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    chan2_group_chnl_ctrl_.reset();
    chan2_group_chnl_meta_.reset();
    chan2_group_meta_fifo_ctrl_.reset();
    chan2_group_chnl_fifo_ctrl_.reset();
    chan2_group_chnl_acc_ctrl_.reset();
    chan2_group_chnl_acc_stat_.reset();
    chan2_group_chnl_pktnum0_cfg_.reset();
    chan2_group_chnl_pktnum1_cfg_.reset();
    chan2_group_chnl_metanum_cfg_.reset();
    chan2_group_chnl_stat_.reset();
    chan2_group_chnl_pktnum0_.reset();
    chan2_group_chnl_pktnum1_.reset();
    chan2_group_chnl_metanum_.reset();
    chan2_group_chnl_deparser_drop_pkt_.reset();
    chan2_group_chnl_wsch_discard_pkt_.reset();
    chan2_group_chnl_wsch_trunc_pkt_.reset();
    chan2_group_chnl_drop_trunc_pkt_.reset();
    chan2_group_chnl_resubmit_discard_pkt_.reset();
    chan2_group_chnl_parser_discard_pkt_.reset();
    chan2_group_chnl_parser_send_pkt_.reset();
    chan2_group_chnl_deparser_send_pkt_.reset();
    chan2_group_chnl_macs_received_pkt_.reset();
    chan2_group_chnl_resubmit_received_pkt_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0xa00 && offset < 0xa08) {
      offset -= 0xa00;
      r += chan2_group_chnl_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa10 && offset < 0xa20) {
      offset -= 0xa10;
      r += chan2_group_chnl_meta_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa20 && offset < 0xa24) {
      offset -= 0xa20;
      r += chan2_group_meta_fifo_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa30 && offset < 0xa3c) {
      offset -= 0xa30;
      r += chan2_group_chnl_fifo_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa40 && offset < 0xa4c) {
      offset -= 0xa40;
      r += chan2_group_chnl_acc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa4c && offset < 0xa50) {
      offset -= 0xa4c;
      r += chan2_group_chnl_acc_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa50 && offset < 0xa54) {
      offset -= 0xa50;
      r += chan2_group_chnl_pktnum0_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa54 && offset < 0xa58) {
      offset -= 0xa54;
      r += chan2_group_chnl_pktnum1_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa58 && offset < 0xa5c) {
      offset -= 0xa58;
      r += chan2_group_chnl_metanum_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa5c && offset < 0xa60) {
      offset -= 0xa5c;
      r += chan2_group_chnl_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa60 && offset < 0xa64) {
      offset -= 0xa60;
      r += chan2_group_chnl_pktnum0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa64 && offset < 0xa68) {
      offset -= 0xa64;
      r += chan2_group_chnl_pktnum1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa68 && offset < 0xa6c) {
      offset -= 0xa68;
      r += chan2_group_chnl_metanum_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa70 && offset < 0xa78) {
      offset -= 0xa70;
      r += chan2_group_chnl_deparser_drop_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa78 && offset < 0xa80) {
      offset -= 0xa78;
      r += chan2_group_chnl_wsch_discard_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa80 && offset < 0xa88) {
      offset -= 0xa80;
      r += chan2_group_chnl_wsch_trunc_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa88 && offset < 0xa90) {
      offset -= 0xa88;
      r += chan2_group_chnl_drop_trunc_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa90 && offset < 0xa98) {
      offset -= 0xa90;
      r += chan2_group_chnl_resubmit_discard_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa98 && offset < 0xaa0) {
      offset -= 0xa98;
      r += chan2_group_chnl_parser_discard_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xaa0 && offset < 0xaac) {
      offset -= 0xaa0;
      r += chan2_group_chnl_parser_send_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xab0 && offset < 0xabc) {
      offset -= 0xab0;
      r += chan2_group_chnl_deparser_send_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xac0 && offset < 0xacc) {
      offset -= 0xac0;
      r += chan2_group_chnl_macs_received_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xad0 && offset < 0xad8) {
      offset -= 0xad0;
      r += chan2_group_chnl_resubmit_received_pkt_.to_string(offset,print_zeros,indent_string) ;
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
    r += chan2_group_chnl_ctrl_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_meta_.to_string(print_zeros,indent_string) ;
    r += chan2_group_meta_fifo_ctrl_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_fifo_ctrl_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_acc_ctrl_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_acc_stat_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_pktnum0_cfg_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_pktnum1_cfg_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_metanum_cfg_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_stat_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_pktnum0_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_pktnum1_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_metanum_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_deparser_drop_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_wsch_discard_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_wsch_trunc_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_drop_trunc_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_resubmit_discard_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_parser_discard_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_parser_send_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_deparser_send_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_macs_received_pkt_.to_string(print_zeros,indent_string) ;
    r += chan2_group_chnl_resubmit_received_pkt_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  ChnlCtrlMutable chan2_group_chnl_ctrl_;
  ChnlMetaMutable chan2_group_chnl_meta_;
  MetaFifoCtrlMutable chan2_group_meta_fifo_ctrl_;
  ChnlFifoCtrlMutable chan2_group_chnl_fifo_ctrl_;
  ChnlAccCtrlMutable chan2_group_chnl_acc_ctrl_;
  ChnlAccStatMutable chan2_group_chnl_acc_stat_;
  ChnlPktnum0CfgMutable chan2_group_chnl_pktnum0_cfg_;
  ChnlPktnum1CfgMutable chan2_group_chnl_pktnum1_cfg_;
  ChnlMetanumCfgMutable chan2_group_chnl_metanum_cfg_;
  ChnlStatMutable chan2_group_chnl_stat_;
  ChnlPktnum0Mutable chan2_group_chnl_pktnum0_;
  ChnlPktnum1Mutable chan2_group_chnl_pktnum1_;
  ChnlMetanumMutable chan2_group_chnl_metanum_;
  ChnlDeparserDropPktMutable chan2_group_chnl_deparser_drop_pkt_;
  ChnlWschDiscardPktMutable chan2_group_chnl_wsch_discard_pkt_;
  ChnlWschTruncPktMutable chan2_group_chnl_wsch_trunc_pkt_;
  ChnlDropTruncPktMutable chan2_group_chnl_drop_trunc_pkt_;
  ChnlResubmitDiscardPktMutable chan2_group_chnl_resubmit_discard_pkt_;
  ChnlParserDiscardPktMutable chan2_group_chnl_parser_discard_pkt_;
  ChnlParserSendPktMutable chan2_group_chnl_parser_send_pkt_;
  ChnlDeparserSendPktMutable chan2_group_chnl_deparser_send_pkt_;
  ChnlMacsReceivedPktMutable chan2_group_chnl_macs_received_pkt_;
  ChnlResubmitReceivedPktMutable chan2_group_chnl_resubmit_received_pkt_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ipb_prsr4_reg
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    assert(index_ipb_prsr4_reg < 9);
    offset += index_ipb_prsr4_reg * 0x2000; // ipb_prsr4_reg[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_IPB_RSPEC_CHAN2_GROUP_MUTABLE_H__
