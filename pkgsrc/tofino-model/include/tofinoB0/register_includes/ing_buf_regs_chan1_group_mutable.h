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
#ifndef __REGISTER_INCLUDES_ING_BUF_REGS_CHAN1_GROUP_MUTABLE_H__
#define __REGISTER_INCLUDES_ING_BUF_REGS_CHAN1_GROUP_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "chnl_afull_mutable.h"
#include "chnl_ctrl_mutable.h"
#include "chnl_deparser_drop_pkt_mutable.h"
#include "chnl_deparser_send_pkt_mutable.h"
#include "chnl_drop_mutable.h"
#include "chnl_macs_received_pkt_mutable.h"
#include "chnl_metadata_fix2_mutable.h"
#include "chnl_metadata_fix_mutable.h"
#include "chnl_parser_discard_pkt_mutable.h"
#include "chnl_parser_send_pkt_mutable.h"
#include "chnl_pktnum0_mutable.h"
#include "chnl_pktnum1_mutable.h"
#include "chnl_ptr_fifo_min_max_mutable.h"
#include "chnl_recirc_discard_pkt_mutable.h"
#include "chnl_recirc_fifo_min_max_mutable.h"
#include "chnl_recirc_received_pkt_mutable.h"
#include "chnl_tx_xoff_mutable.h"
#include "chnl_wsch_discard_pkt_mutable.h"
#include "chnl_wsch_trunc_pkt_mutable.h"

namespace tofinoB0 {
  namespace register_classes {

class IngBufRegsChan1GroupMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  IngBufRegsChan1GroupMutable(
      int chipNumber, int index_pipe_addrmap, int index_ibp_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ibp_rspec), 96, true, write_callback, read_callback, std::string("IngBufRegsChan1GroupMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ibp_rspec))
    {
    }
  IngBufRegsChan1GroupMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "IngBufRegsChan1GroupMutable")
    {
    }
public:





  ChnlCtrlMutable &chan1_group_chnl_ctrl() { return chan1_group_chnl_ctrl_; }






  ChnlAfullMutable &chan1_group_chnl_afull() { return chan1_group_chnl_afull_; }






  ChnlTxXoffMutable &chan1_group_chnl_tx_xoff() { return chan1_group_chnl_tx_xoff_; }






  ChnlDropMutable &chan1_group_chnl_drop() { return chan1_group_chnl_drop_; }





  ChnlMetadataFixMutable &chan1_group_chnl_metadata_fix() { return chan1_group_chnl_metadata_fix_; }





  ChnlMetadataFix2Mutable &chan1_group_chnl_metadata_fix2() { return chan1_group_chnl_metadata_fix2_; }








  ChnlPktnum0Mutable &chan1_group_chnl_pktnum0() { return chan1_group_chnl_pktnum0_; }








  ChnlPktnum1Mutable &chan1_group_chnl_pktnum1() { return chan1_group_chnl_pktnum1_; }





  ChnlPtrFifoMinMaxMutable &chan1_group_chnl_ptr_fifo_min_max() { return chan1_group_chnl_ptr_fifo_min_max_; }





  ChnlRecircFifoMinMaxMutable &chan1_group_chnl_recirc_fifo_min_max() { return chan1_group_chnl_recirc_fifo_min_max_; }





  ChnlDeparserDropPktMutable &chan1_group_chnl_deparser_drop_pkt() { return chan1_group_chnl_deparser_drop_pkt_; }





  ChnlWschDiscardPktMutable &chan1_group_chnl_wsch_discard_pkt() { return chan1_group_chnl_wsch_discard_pkt_; }





  ChnlWschTruncPktMutable &chan1_group_chnl_wsch_trunc_pkt() { return chan1_group_chnl_wsch_trunc_pkt_; }





  ChnlRecircDiscardPktMutable &chan1_group_chnl_recirc_discard_pkt() { return chan1_group_chnl_recirc_discard_pkt_; }





  ChnlParserDiscardPktMutable &chan1_group_chnl_parser_discard_pkt() { return chan1_group_chnl_parser_discard_pkt_; }





  ChnlParserSendPktMutable &chan1_group_chnl_parser_send_pkt() { return chan1_group_chnl_parser_send_pkt_; }





  ChnlDeparserSendPktMutable &chan1_group_chnl_deparser_send_pkt() { return chan1_group_chnl_deparser_send_pkt_; }





  ChnlMacsReceivedPktMutable &chan1_group_chnl_macs_received_pkt() { return chan1_group_chnl_macs_received_pkt_; }





  ChnlRecircReceivedPktMutable &chan1_group_chnl_recirc_received_pkt() { return chan1_group_chnl_recirc_received_pkt_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x280 && offset < 0x284) {
      offset -= 0x280;
      if (read_callback_) read_callback_();
      chan1_group_chnl_ctrl_.read( offset, data );
    }
    else if (offset >= 0x284 && offset < 0x288) {
      offset -= 0x284;
      if (read_callback_) read_callback_();
      chan1_group_chnl_afull_.read( offset, data );
    }
    else if (offset >= 0x288 && offset < 0x28c) {
      offset -= 0x288;
      if (read_callback_) read_callback_();
      chan1_group_chnl_tx_xoff_.read( offset, data );
    }
    else if (offset >= 0x28c && offset < 0x290) {
      offset -= 0x28c;
      if (read_callback_) read_callback_();
      chan1_group_chnl_drop_.read( offset, data );
    }
    else if (offset >= 0x290 && offset < 0x298) {
      offset -= 0x290;
      if (read_callback_) read_callback_();
      chan1_group_chnl_metadata_fix_.read( offset, data );
    }
    else if (offset >= 0x298 && offset < 0x29c) {
      offset -= 0x298;
      if (read_callback_) read_callback_();
      chan1_group_chnl_metadata_fix2_.read( offset, data );
    }
    else if (offset >= 0x29c && offset < 0x2a0) {
      offset -= 0x29c;
      if (read_callback_) read_callback_();
      chan1_group_chnl_pktnum0_.read( offset, data );
    }
    else if (offset >= 0x2a0 && offset < 0x2a4) {
      offset -= 0x2a0;
      if (read_callback_) read_callback_();
      chan1_group_chnl_pktnum1_.read( offset, data );
    }
    else if (offset >= 0x2a4 && offset < 0x2a8) {
      offset -= 0x2a4;
      if (read_callback_) read_callback_();
      chan1_group_chnl_ptr_fifo_min_max_.read( offset, data );
    }
    else if (offset >= 0x2a8 && offset < 0x2ac) {
      offset -= 0x2a8;
      if (read_callback_) read_callback_();
      chan1_group_chnl_recirc_fifo_min_max_.read( offset, data );
    }
    else if (offset >= 0x2ac && offset < 0x2b0) {
      offset -= 0x2ac;
      if (read_callback_) read_callback_();
      chan1_group_chnl_deparser_drop_pkt_.read( offset, data );
    }
    else if (offset >= 0x2b0 && offset < 0x2b4) {
      offset -= 0x2b0;
      if (read_callback_) read_callback_();
      chan1_group_chnl_wsch_discard_pkt_.read( offset, data );
    }
    else if (offset >= 0x2b4 && offset < 0x2b8) {
      offset -= 0x2b4;
      if (read_callback_) read_callback_();
      chan1_group_chnl_wsch_trunc_pkt_.read( offset, data );
    }
    else if (offset >= 0x2b8 && offset < 0x2bc) {
      offset -= 0x2b8;
      if (read_callback_) read_callback_();
      chan1_group_chnl_recirc_discard_pkt_.read( offset, data );
    }
    else if (offset >= 0x2bc && offset < 0x2c0) {
      offset -= 0x2bc;
      if (read_callback_) read_callback_();
      chan1_group_chnl_parser_discard_pkt_.read( offset, data );
    }
    else if (offset >= 0x2c0 && offset < 0x2c8) {
      offset -= 0x2c0;
      if (read_callback_) read_callback_();
      chan1_group_chnl_parser_send_pkt_.read( offset, data );
    }
    else if (offset >= 0x2c8 && offset < 0x2d0) {
      offset -= 0x2c8;
      if (read_callback_) read_callback_();
      chan1_group_chnl_deparser_send_pkt_.read( offset, data );
    }
    else if (offset >= 0x2d0 && offset < 0x2d8) {
      offset -= 0x2d0;
      if (read_callback_) read_callback_();
      chan1_group_chnl_macs_received_pkt_.read( offset, data );
    }
    else if (offset >= 0x2d8 && offset < 0x2e0) {
      offset -= 0x2d8;
      if (read_callback_) read_callback_();
      chan1_group_chnl_recirc_received_pkt_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x280 && offset < 0x284) {
      offset -= 0x280;
      chan1_group_chnl_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x284 && offset < 0x288) {
      offset -= 0x284;
      chan1_group_chnl_afull_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x288 && offset < 0x28c) {
      offset -= 0x288;
      chan1_group_chnl_tx_xoff_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28c && offset < 0x290) {
      offset -= 0x28c;
      chan1_group_chnl_drop_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x290 && offset < 0x298) {
      offset -= 0x290;
      chan1_group_chnl_metadata_fix_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x298 && offset < 0x29c) {
      offset -= 0x298;
      chan1_group_chnl_metadata_fix2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x29c && offset < 0x2a0) {
      offset -= 0x29c;
      chan1_group_chnl_pktnum0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2a0 && offset < 0x2a4) {
      offset -= 0x2a0;
      chan1_group_chnl_pktnum1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2a4 && offset < 0x2a8) {
      offset -= 0x2a4;
      chan1_group_chnl_ptr_fifo_min_max_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2a8 && offset < 0x2ac) {
      offset -= 0x2a8;
      chan1_group_chnl_recirc_fifo_min_max_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2ac && offset < 0x2b0) {
      offset -= 0x2ac;
      chan1_group_chnl_deparser_drop_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2b0 && offset < 0x2b4) {
      offset -= 0x2b0;
      chan1_group_chnl_wsch_discard_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2b4 && offset < 0x2b8) {
      offset -= 0x2b4;
      chan1_group_chnl_wsch_trunc_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2b8 && offset < 0x2bc) {
      offset -= 0x2b8;
      chan1_group_chnl_recirc_discard_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2bc && offset < 0x2c0) {
      offset -= 0x2bc;
      chan1_group_chnl_parser_discard_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2c0 && offset < 0x2c8) {
      offset -= 0x2c0;
      chan1_group_chnl_parser_send_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2c8 && offset < 0x2d0) {
      offset -= 0x2c8;
      chan1_group_chnl_deparser_send_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2d0 && offset < 0x2d8) {
      offset -= 0x2d0;
      chan1_group_chnl_macs_received_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2d8 && offset < 0x2e0) {
      offset -= 0x2d8;
      chan1_group_chnl_recirc_received_pkt_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    chan1_group_chnl_ctrl_.reset();
    chan1_group_chnl_afull_.reset();
    chan1_group_chnl_tx_xoff_.reset();
    chan1_group_chnl_drop_.reset();
    chan1_group_chnl_metadata_fix_.reset();
    chan1_group_chnl_metadata_fix2_.reset();
    chan1_group_chnl_pktnum0_.reset();
    chan1_group_chnl_pktnum1_.reset();
    chan1_group_chnl_ptr_fifo_min_max_.reset();
    chan1_group_chnl_recirc_fifo_min_max_.reset();
    chan1_group_chnl_deparser_drop_pkt_.reset();
    chan1_group_chnl_wsch_discard_pkt_.reset();
    chan1_group_chnl_wsch_trunc_pkt_.reset();
    chan1_group_chnl_recirc_discard_pkt_.reset();
    chan1_group_chnl_parser_discard_pkt_.reset();
    chan1_group_chnl_parser_send_pkt_.reset();
    chan1_group_chnl_deparser_send_pkt_.reset();
    chan1_group_chnl_macs_received_pkt_.reset();
    chan1_group_chnl_recirc_received_pkt_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x280 && offset < 0x284) {
      offset -= 0x280;
      r += chan1_group_chnl_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x284 && offset < 0x288) {
      offset -= 0x284;
      r += chan1_group_chnl_afull_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x288 && offset < 0x28c) {
      offset -= 0x288;
      r += chan1_group_chnl_tx_xoff_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28c && offset < 0x290) {
      offset -= 0x28c;
      r += chan1_group_chnl_drop_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x290 && offset < 0x298) {
      offset -= 0x290;
      r += chan1_group_chnl_metadata_fix_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x298 && offset < 0x29c) {
      offset -= 0x298;
      r += chan1_group_chnl_metadata_fix2_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x29c && offset < 0x2a0) {
      offset -= 0x29c;
      r += chan1_group_chnl_pktnum0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2a0 && offset < 0x2a4) {
      offset -= 0x2a0;
      r += chan1_group_chnl_pktnum1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2a4 && offset < 0x2a8) {
      offset -= 0x2a4;
      r += chan1_group_chnl_ptr_fifo_min_max_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2a8 && offset < 0x2ac) {
      offset -= 0x2a8;
      r += chan1_group_chnl_recirc_fifo_min_max_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2ac && offset < 0x2b0) {
      offset -= 0x2ac;
      r += chan1_group_chnl_deparser_drop_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2b0 && offset < 0x2b4) {
      offset -= 0x2b0;
      r += chan1_group_chnl_wsch_discard_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2b4 && offset < 0x2b8) {
      offset -= 0x2b4;
      r += chan1_group_chnl_wsch_trunc_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2b8 && offset < 0x2bc) {
      offset -= 0x2b8;
      r += chan1_group_chnl_recirc_discard_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2bc && offset < 0x2c0) {
      offset -= 0x2bc;
      r += chan1_group_chnl_parser_discard_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2c0 && offset < 0x2c8) {
      offset -= 0x2c0;
      r += chan1_group_chnl_parser_send_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2c8 && offset < 0x2d0) {
      offset -= 0x2c8;
      r += chan1_group_chnl_deparser_send_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2d0 && offset < 0x2d8) {
      offset -= 0x2d0;
      r += chan1_group_chnl_macs_received_pkt_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2d8 && offset < 0x2e0) {
      offset -= 0x2d8;
      r += chan1_group_chnl_recirc_received_pkt_.to_string(offset,print_zeros,indent_string) ;
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
    r += chan1_group_chnl_ctrl_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_afull_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_tx_xoff_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_drop_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_metadata_fix_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_metadata_fix2_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_pktnum0_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_pktnum1_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_ptr_fifo_min_max_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_recirc_fifo_min_max_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_deparser_drop_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_wsch_discard_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_wsch_trunc_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_recirc_discard_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_parser_discard_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_parser_send_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_deparser_send_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_macs_received_pkt_.to_string(print_zeros,indent_string) ;
    r += chan1_group_chnl_recirc_received_pkt_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  ChnlCtrlMutable chan1_group_chnl_ctrl_;
  ChnlAfullMutable chan1_group_chnl_afull_;
  ChnlTxXoffMutable chan1_group_chnl_tx_xoff_;
  ChnlDropMutable chan1_group_chnl_drop_;
  ChnlMetadataFixMutable chan1_group_chnl_metadata_fix_;
  ChnlMetadataFix2Mutable chan1_group_chnl_metadata_fix2_;
  ChnlPktnum0Mutable chan1_group_chnl_pktnum0_;
  ChnlPktnum1Mutable chan1_group_chnl_pktnum1_;
  ChnlPtrFifoMinMaxMutable chan1_group_chnl_ptr_fifo_min_max_;
  ChnlRecircFifoMinMaxMutable chan1_group_chnl_recirc_fifo_min_max_;
  ChnlDeparserDropPktMutable chan1_group_chnl_deparser_drop_pkt_;
  ChnlWschDiscardPktMutable chan1_group_chnl_wsch_discard_pkt_;
  ChnlWschTruncPktMutable chan1_group_chnl_wsch_trunc_pkt_;
  ChnlRecircDiscardPktMutable chan1_group_chnl_recirc_discard_pkt_;
  ChnlParserDiscardPktMutable chan1_group_chnl_parser_discard_pkt_;
  ChnlParserSendPktMutable chan1_group_chnl_parser_send_pkt_;
  ChnlDeparserSendPktMutable chan1_group_chnl_deparser_send_pkt_;
  ChnlMacsReceivedPktMutable chan1_group_chnl_macs_received_pkt_;
  ChnlRecircReceivedPktMutable chan1_group_chnl_recirc_received_pkt_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ibp_rspec
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    assert(index_ibp_rspec < 18);
    offset += index_ibp_rspec * 0x2000; // ibp_rspec[]
    offset += 0x1800; // to get to ing_buf_regs
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_ING_BUF_REGS_CHAN1_GROUP_MUTABLE_H__
