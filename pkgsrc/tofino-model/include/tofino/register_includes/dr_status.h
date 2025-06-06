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
#ifndef __REGISTER_INCLUDES_DR_STATUS_H__
#define __REGISTER_INCLUDES_DR_STATUS_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofino {
  namespace register_classes {

class DrStatus : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum CbcRspecEnum {
    kCbcLqFmDr,
    kCbcLqRxDr,
    kCbcWlCplDr,
    kCbcWlTxDr
  };
  enum MbcRspecEnum {
    kMbcMacCplDr,
    kMbcMacTxDr
  };
  enum PbcRspecEnum {
    kPbcDiagFmDr,
    kPbcDiagRxDr,
    kPbcIdleFmDr,
    kPbcIdleRxDr,
    kPbcIlCplDr,
    kPbcIlTxDr,
    kPbcRbCplDr,
    kPbcRbTxDr,
    kPbcStatFmDr,
    kPbcStatRxDr,
    kPbcWbCplDr,
    kPbcWbTxDr
  };
  enum TbcRspecEnum {
    kTbcCplDr,
    kTbcFmDr,
    kTbcRxDr,
    kTbcTxDr
  };
public:
  DrStatus(
      int chipNumber, CbcRspecEnum selector_cbc_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_cbc_rspec), 4, false, write_callback, read_callback, std::string("DrStatus")+":"+boost::lexical_cast<std::string>(selector_cbc_rspec))
    {
    }
  DrStatus(
      int chipNumber, MbcRspecEnum selector_mbc_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_mbc_rspec), 4, false, write_callback, read_callback, std::string("DrStatus")+":"+boost::lexical_cast<std::string>(selector_mbc_rspec))
    {
    }
  DrStatus(
      int chipNumber, PbcRspecEnum selector_pbc_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_pbc_rspec), 4, false, write_callback, read_callback, std::string("DrStatus")+":"+boost::lexical_cast<std::string>(selector_pbc_rspec))
    {
    }
  DrStatus(
      int chipNumber, PbcRspecEnum selector_pbc_rspec, int index_dru_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_pbc_rspec, index_dru_rspec), 4, false, write_callback, read_callback, std::string("DrStatus")+":"+boost::lexical_cast<std::string>(selector_pbc_rspec) + "," + boost::lexical_cast<std::string>(index_dru_rspec))
    {
    }
  DrStatus(
      int chipNumber, TbcRspecEnum selector_tbc_rspec, int index_dru_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_tbc_rspec, index_dru_rspec), 4, false, write_callback, read_callback, std::string("DrStatus")+":"+boost::lexical_cast<std::string>(selector_tbc_rspec) + "," + boost::lexical_cast<std::string>(index_dru_rspec))
    {
    }
  DrStatus(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "DrStatus")
    {
    }
public:





  uint8_t &ring_empty() { return ring_empty_; }





  uint8_t &ring_full() { return ring_full_; }





  uint8_t &queue_empty() { return queue_empty_; }





  uint8_t &queue_full() { return queue_full_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (ring_empty_ & 0x1);
    *data |= ((ring_full_ & 0x1) << 1);
    *data |= ((queue_empty_ & 0x1) << 2);
    *data |= ((queue_full_ & 0x1) << 3);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    ring_empty_ = (data & 0x1);
    ring_full_ = ((data >> 1) & 0x1);
    queue_empty_ = ((data >> 2) & 0x1);
    queue_full_ = ((data >> 3) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    ring_empty_ = 0x0;
    ring_full_ = 0x0;
    queue_empty_ = 0x0;
    queue_full_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DrStatus") + ":\n";
    r += indent_string + "  " + std::string("ring_empty") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ring_empty_) ) + "\n";
    all_zeros &= (0 == ring_empty_);
    r += indent_string + "  " + std::string("ring_full") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ring_full_) ) + "\n";
    all_zeros &= (0 == ring_full_);
    r += indent_string + "  " + std::string("queue_empty") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(queue_empty_) ) + "\n";
    all_zeros &= (0 == queue_empty_);
    r += indent_string + "  " + std::string("queue_full") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(queue_full_) ) + "\n";
    all_zeros &= (0 == queue_full_);
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
    r += indent_string + std::string("DrStatus") + ":\n";
    r += indent_string + "  " + std::string("ring_empty") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ring_empty_) ) + "\n";
    all_zeros &= (0 == ring_empty_);
    r += indent_string + "  " + std::string("ring_full") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ring_full_) ) + "\n";
    all_zeros &= (0 == ring_full_);
    r += indent_string + "  " + std::string("queue_empty") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(queue_empty_) ) + "\n";
    all_zeros &= (0 == queue_empty_);
    r += indent_string + "  " + std::string("queue_full") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(queue_full_) ) + "\n";
    all_zeros &= (0 == queue_full_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t ring_empty_;
  uint8_t ring_full_;
  uint8_t queue_empty_;
  uint8_t queue_full_;
private:
  static int StartOffset(
      CbcRspecEnum selector_cbc_rspec
      ) {
    int offset=0;
    offset += 0x140000; // to get to cbc
    switch (selector_cbc_rspec) {
      case kCbcLqFmDr:
        offset += 0x180; // to get to cbc_lq_fm_dr
        offset += 0x28; // to get to status
        break;
      case kCbcLqRxDr:
        offset += 0x1c0; // to get to cbc_lq_rx_dr
        offset += 0x28; // to get to status
        break;
      case kCbcWlCplDr:
        offset += 0x140; // to get to cbc_wl_cpl_dr
        offset += 0x28; // to get to status
        break;
      case kCbcWlTxDr:
        offset += 0x100; // to get to cbc_wl_tx_dr
        offset += 0x28; // to get to status
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

  static int StartOffset(
      MbcRspecEnum selector_mbc_rspec
      ) {
    int offset=0;
    offset += 0xc0000; // to get to mbc
    switch (selector_mbc_rspec) {
      case kMbcMacCplDr:
        offset += 0x140; // to get to mbc_mac_cpl_dr
        offset += 0x28; // to get to status
        break;
      case kMbcMacTxDr:
        offset += 0x100; // to get to mbc_mac_tx_dr
        offset += 0x28; // to get to status
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

  static int StartOffset(
      PbcRspecEnum selector_pbc_rspec
      ) {
    int offset=0;
    offset += 0x100000; // to get to pbc
    switch (selector_pbc_rspec) {
      case kPbcDiagFmDr:
        offset += 0xa00; // to get to pbc_diag_fm_dr
        offset += 0x28; // to get to status
        break;
      case kPbcDiagRxDr:
        offset += 0xa40; // to get to pbc_diag_rx_dr
        offset += 0x28; // to get to status
        break;
      case kPbcIdleFmDr:
        offset += 0x980; // to get to pbc_idle_fm_dr
        offset += 0x28; // to get to status
        break;
      case kPbcIdleRxDr:
        offset += 0x9c0; // to get to pbc_idle_rx_dr
        offset += 0x28; // to get to status
        break;
      case kPbcRbCplDr:
        offset += 0x8c0; // to get to pbc_rb_cpl_dr
        offset += 0x28; // to get to status
        break;
      case kPbcRbTxDr:
        offset += 0x880; // to get to pbc_rb_tx_dr
        offset += 0x28; // to get to status
        break;
      case kPbcStatFmDr:
        offset += 0x900; // to get to pbc_stat_fm_dr
        offset += 0x28; // to get to status
        break;
      case kPbcStatRxDr:
        offset += 0x940; // to get to pbc_stat_rx_dr
        offset += 0x28; // to get to status
        break;
      case kPbcWbCplDr:
        offset += 0x840; // to get to pbc_wb_cpl_dr
        offset += 0x28; // to get to status
        break;
      case kPbcWbTxDr:
        offset += 0x800; // to get to pbc_wb_tx_dr
        offset += 0x28; // to get to status
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

  static int StartOffset(
      PbcRspecEnum selector_pbc_rspec, int index_dru_rspec
      ) {
    int offset=0;
    offset += 0x100000; // to get to pbc
    switch (selector_pbc_rspec) {
      case kPbcIlCplDr:
        offset += 0x600; // to get to pbc_il_cpl_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x2c; // dru_rspec[]
        offset += 0x28; // to get to status
        break;
      case kPbcIlTxDr:
        offset += 0x400; // to get to pbc_il_tx_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x2c; // dru_rspec[]
        offset += 0x28; // to get to status
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

  static int StartOffset(
      TbcRspecEnum selector_tbc_rspec, int index_dru_rspec
      ) {
    int offset=0;
    offset += 0x180000; // to get to tbc
    switch (selector_tbc_rspec) {
      case kTbcCplDr:
        offset += 0x200; // to get to tbc_cpl_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x2c; // dru_rspec[]
        offset += 0x28; // to get to status
        break;
      case kTbcFmDr:
        offset += 0x400; // to get to tbc_fm_dr
        assert(index_dru_rspec < 8);
        offset += index_dru_rspec * 0x2c; // dru_rspec[]
        offset += 0x28; // to get to status
        break;
      case kTbcRxDr:
        offset += 0x600; // to get to tbc_rx_dr
        assert(index_dru_rspec < 8);
        offset += index_dru_rspec * 0x2c; // dru_rspec[]
        offset += 0x28; // to get to status
        break;
      case kTbcTxDr:
        offset += 0x100; // to get to tbc_tx_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x2c; // dru_rspec[]
        offset += 0x28; // to get to status
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_DR_STATUS_H__
