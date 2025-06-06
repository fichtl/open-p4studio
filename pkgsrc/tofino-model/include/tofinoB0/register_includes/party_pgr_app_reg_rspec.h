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
#ifndef __REGISTER_INCLUDES_PARTY_PGR_APP_REG_RSPEC_H__
#define __REGISTER_INCLUDES_PARTY_PGR_APP_REG_RSPEC_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "pgr_app_ctr48_batch.h"
#include "pgr_app_ctr48_packet.h"
#include "pgr_app_ctr48_trigger.h"
#include "pgr_app_ctrl.h"
#include "pgr_app_event_ibg.h"
#include "pgr_app_event_ipg.h"
#include "pgr_app_event_jitter_mask.h"
#include "pgr_app_event_jitter_value.h"
#include "pgr_app_event_number.h"
#include "pgr_app_event_timer.h"
#include "pgr_app_ingr_port_ctrl.h"
#include "pgr_app_log.h"
#include "pgr_app_payload_ctrl.h"
#include "pgr_app_recir_match_mask.h"
#include "pgr_app_recir_match_value.h"

namespace tofinoB0 {
  namespace register_classes {

class PartyPgrAppRegRspec : public model_core::RegisterBlock<RegisterCallback> {
public:
  PartyPgrAppRegRspec(
      int chipNumber, int index_pipe_addrmap, int index_party_pgr_app_reg_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_party_pgr_app_reg_rspec), 512, false, write_callback, read_callback, std::string("PartyPgrAppRegRspec")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_party_pgr_app_reg_rspec))
    {
    }
  PartyPgrAppRegRspec(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PartyPgrAppRegRspec")
    {
    }
public:





  PgrAppCtrl &ctrl() { return ctrl_; }





  PgrAppPayloadCtrl &payload_ctrl() { return payload_ctrl_; }





  PgrAppIngrPortCtrl &ingr_port_ctrl() { return ingr_port_ctrl_; }





  PgrAppRecirMatchValue &recir_match_value() { return recir_match_value_; }





  PgrAppRecirMatchMask &recir_match_mask() { return recir_match_mask_; }





  PgrAppEventNumber &event_number() { return event_number_; }





  PgrAppEventIbg &event_ibg() { return event_ibg_; }





  PgrAppEventJitterValue &event_ibg_jitter_value() { return event_ibg_jitter_value_; }





  PgrAppEventJitterMask &event_ibg_jitter_mask() { return event_ibg_jitter_mask_; }





  PgrAppEventIpg &event_ipg() { return event_ipg_; }





  PgrAppEventJitterValue &event_ipg_jitter_value() { return event_ipg_jitter_value_; }





  PgrAppEventJitterMask &event_ipg_jitter_mask() { return event_ipg_jitter_mask_; }





  PgrAppEventTimer &event_timer() { return event_timer_; }





  PgrAppCtr48Trigger &ctr48_trigger() { return ctr48_trigger_; }





  PgrAppCtr48Batch &ctr48_batch() { return ctr48_batch_; }





  PgrAppCtr48Packet &ctr48_packet() { return ctr48_packet_; }





  PgrAppLog &log() { return log_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      ctrl_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      payload_ctrl_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      ingr_port_ctrl_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      recir_match_value_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      recir_match_mask_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      event_number_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      event_ibg_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      event_ibg_jitter_value_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      event_ibg_jitter_mask_.read( offset, data );
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      if (read_callback_) read_callback_();
      event_ipg_.read( offset, data );
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      if (read_callback_) read_callback_();
      event_ipg_jitter_value_.read( offset, data );
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      if (read_callback_) read_callback_();
      event_ipg_jitter_mask_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      event_timer_.read( offset, data );
    }
    else if (offset >= 0x38 && offset < 0x40) {
      offset -= 0x38;
      if (read_callback_) read_callback_();
      ctr48_trigger_.read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x48) {
      offset -= 0x40;
      if (read_callback_) read_callback_();
      ctr48_batch_.read( offset, data );
    }
    else if (offset >= 0x48 && offset < 0x50) {
      offset -= 0x48;
      if (read_callback_) read_callback_();
      ctr48_packet_.read( offset, data );
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      if (read_callback_) read_callback_();
      log_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      payload_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      ingr_port_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      recir_match_value_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      recir_match_mask_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      event_number_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      event_ibg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      event_ibg_jitter_value_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      event_ibg_jitter_mask_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      event_ipg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      event_ipg_jitter_value_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      event_ipg_jitter_mask_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      event_timer_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x38 && offset < 0x40) {
      offset -= 0x38;
      ctr48_trigger_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x48) {
      offset -= 0x40;
      ctr48_batch_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x48 && offset < 0x50) {
      offset -= 0x48;
      ctr48_packet_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    ctrl_.reset();
    payload_ctrl_.reset();
    ingr_port_ctrl_.reset();
    recir_match_value_.reset();
    recir_match_mask_.reset();
    event_number_.reset();
    event_ibg_.reset();
    event_ibg_jitter_value_.reset();
    event_ibg_jitter_mask_.reset();
    event_ipg_.reset();
    event_ipg_jitter_value_.reset();
    event_ipg_jitter_mask_.reset();
    event_timer_.reset();
    ctr48_trigger_.reset();
    ctr48_batch_.reset();
    ctr48_packet_.reset();
    log_.reset();
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
      r += ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += payload_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += ingr_port_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += recir_match_value_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += recir_match_mask_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += event_number_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += event_ibg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += event_ibg_jitter_value_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += event_ibg_jitter_mask_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      r += event_ipg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      r += event_ipg_jitter_value_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      r += event_ipg_jitter_mask_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      r += event_timer_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x38 && offset < 0x40) {
      offset -= 0x38;
      r += ctr48_trigger_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x48) {
      offset -= 0x40;
      r += ctr48_batch_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x48 && offset < 0x50) {
      offset -= 0x48;
      r += ctr48_packet_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      r += log_.to_string(offset,print_zeros,indent_string) ;
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
    r += ctrl_.to_string(print_zeros,indent_string) ;
    r += payload_ctrl_.to_string(print_zeros,indent_string) ;
    r += ingr_port_ctrl_.to_string(print_zeros,indent_string) ;
    r += recir_match_value_.to_string(print_zeros,indent_string) ;
    r += recir_match_mask_.to_string(print_zeros,indent_string) ;
    r += event_number_.to_string(print_zeros,indent_string) ;
    r += event_ibg_.to_string(print_zeros,indent_string) ;
    r += event_ibg_jitter_value_.to_string(print_zeros,indent_string) ;
    r += event_ibg_jitter_mask_.to_string(print_zeros,indent_string) ;
    r += event_ipg_.to_string(print_zeros,indent_string) ;
    r += event_ipg_jitter_value_.to_string(print_zeros,indent_string) ;
    r += event_ipg_jitter_mask_.to_string(print_zeros,indent_string) ;
    r += event_timer_.to_string(print_zeros,indent_string) ;
    r += ctr48_trigger_.to_string(print_zeros,indent_string) ;
    r += ctr48_batch_.to_string(print_zeros,indent_string) ;
    r += ctr48_packet_.to_string(print_zeros,indent_string) ;
    r += log_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  PgrAppCtrl ctrl_;
  PgrAppPayloadCtrl payload_ctrl_;
  PgrAppIngrPortCtrl ingr_port_ctrl_;
  PgrAppRecirMatchValue recir_match_value_;
  PgrAppRecirMatchMask recir_match_mask_;
  PgrAppEventNumber event_number_;
  PgrAppEventIbg event_ibg_;
  PgrAppEventJitterValue event_ibg_jitter_value_;
  PgrAppEventJitterMask event_ibg_jitter_mask_;
  PgrAppEventIpg event_ipg_;
  PgrAppEventJitterValue event_ipg_jitter_value_;
  PgrAppEventJitterMask event_ipg_jitter_mask_;
  PgrAppEventTimer event_timer_;
  PgrAppCtr48Trigger ctr48_trigger_;
  PgrAppCtr48Batch ctr48_batch_;
  PgrAppCtr48Packet ctr48_packet_;
  PgrAppLog log_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_party_pgr_app_reg_rspec
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    offset += 0x3c000; // to get to pgr_reg
    assert(index_party_pgr_app_reg_rspec < 8);
    offset += index_party_pgr_app_reg_rspec * 0x200; // party_pgr_app_reg_rspec[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_PARTY_PGR_APP_REG_RSPEC_H__
