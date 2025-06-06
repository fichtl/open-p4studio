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
#ifndef __REGISTER_INCLUDES_DR_SIZE_MUTABLE_H__
#define __REGISTER_INCLUDES_DR_SIZE_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbayB0 {
  namespace register_classes {

class DrSizeMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum CbcRspecEnum {
    kCbcLqFmDr,
    kCbcLqRxDr,
    kCbcRb0CplDr,
    kCbcRb0TxDr,
    kCbcRb1CplDr,
    kCbcRb1TxDr,
    kCbcWl0CplDr,
    kCbcWl0TxDr,
    kCbcWl1CplDr,
    kCbcWl1TxDr
  };
  enum MbcRspecEnum {
    kMbcMac_0CplDr,
    kMbcMac_0TxDr,
    kMbcWbCplDr,
    kMbcWbTxDr
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
  DrSizeMutable(
      int chipNumber, CbcRspecEnum selector_cbc_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_cbc_rspec), 4, true, write_callback, read_callback, std::string("DrSizeMutable")+":"+boost::lexical_cast<std::string>(selector_cbc_rspec))
    {
    }
  DrSizeMutable(
      int chipNumber, MbcRspecEnum selector_mbc_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_mbc_rspec), 4, true, write_callback, read_callback, std::string("DrSizeMutable")+":"+boost::lexical_cast<std::string>(selector_mbc_rspec))
    {
    }
  DrSizeMutable(
      int chipNumber, PbcRspecEnum selector_pbc_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_pbc_rspec), 4, true, write_callback, read_callback, std::string("DrSizeMutable")+":"+boost::lexical_cast<std::string>(selector_pbc_rspec))
    {
    }
  DrSizeMutable(
      int chipNumber, PbcRspecEnum selector_pbc_rspec, int index_dru_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_pbc_rspec, index_dru_rspec), 4, true, write_callback, read_callback, std::string("DrSizeMutable")+":"+boost::lexical_cast<std::string>(selector_pbc_rspec) + "," + boost::lexical_cast<std::string>(index_dru_rspec))
    {
    }
  DrSizeMutable(
      int chipNumber, TbcRspecEnum selector_tbc_rspec, int index_dru_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_tbc_rspec, index_dru_rspec), 4, true, write_callback, read_callback, std::string("DrSizeMutable")+":"+boost::lexical_cast<std::string>(selector_tbc_rspec) + "," + boost::lexical_cast<std::string>(index_dru_rspec))
    {
    }
  DrSizeMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DrSizeMutable")
    {
    }
public:











  uint16_t size() { return size_; }
  void size(const uint16_t &v) { size_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = ((size_ & 0x3fff) << 6);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    size_ = ((data >> 6) & 0x3fff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    size_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DrSizeMutable") + ":\n";
    r += indent_string + "  " + std::string("size") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(size_) ) + "\n";
    all_zeros &= (0 == size_);
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
    r += indent_string + std::string("DrSizeMutable") + ":\n";
    r += indent_string + "  " + std::string("size") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(size_) ) + "\n";
    all_zeros &= (0 == size_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t size_;
private:
  static int StartOffset(
      CbcRspecEnum selector_cbc_rspec
      ) {
    int offset=0;
    offset += 0x280000; // to get to cbc
    switch (selector_cbc_rspec) {
      case kCbcLqFmDr:
        offset += 0x600; // to get to cbc_lq_fm_dr
        offset += 0x14; // to get to size
        break;
      case kCbcLqRxDr:
        offset += 0x640; // to get to cbc_lq_rx_dr
        offset += 0x14; // to get to size
        break;
      case kCbcRb0CplDr:
        offset += 0x540; // to get to cbc_rb0_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kCbcRb0TxDr:
        offset += 0x500; // to get to cbc_rb0_tx_dr
        offset += 0x14; // to get to size
        break;
      case kCbcRb1CplDr:
        offset += 0x5c0; // to get to cbc_rb1_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kCbcRb1TxDr:
        offset += 0x580; // to get to cbc_rb1_tx_dr
        offset += 0x14; // to get to size
        break;
      case kCbcWl0CplDr:
        offset += 0x440; // to get to cbc_wl0_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kCbcWl0TxDr:
        offset += 0x400; // to get to cbc_wl0_tx_dr
        offset += 0x14; // to get to size
        break;
      case kCbcWl1CplDr:
        offset += 0x4c0; // to get to cbc_wl1_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kCbcWl1TxDr:
        offset += 0x480; // to get to cbc_wl1_tx_dr
        offset += 0x14; // to get to size
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
    offset += 0x180000; // to get to mbc
    switch (selector_mbc_rspec) {
      case kMbcMac_0CplDr:
        offset += 0x240; // to get to mbc_mac_0_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kMbcMac_0TxDr:
        offset += 0x200; // to get to mbc_mac_0_tx_dr
        offset += 0x14; // to get to size
        break;
      case kMbcWbCplDr:
        offset += 0x2c0; // to get to mbc_wb_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kMbcWbTxDr:
        offset += 0x280; // to get to mbc_wb_tx_dr
        offset += 0x14; // to get to size
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
    offset += 0x200000; // to get to pbc
    switch (selector_pbc_rspec) {
      case kPbcDiagFmDr:
        offset += 0xa00; // to get to pbc_diag_fm_dr
        offset += 0x14; // to get to size
        break;
      case kPbcDiagRxDr:
        offset += 0xa40; // to get to pbc_diag_rx_dr
        offset += 0x14; // to get to size
        break;
      case kPbcIdleFmDr:
        offset += 0x980; // to get to pbc_idle_fm_dr
        offset += 0x14; // to get to size
        break;
      case kPbcIdleRxDr:
        offset += 0x9c0; // to get to pbc_idle_rx_dr
        offset += 0x14; // to get to size
        break;
      case kPbcRbCplDr:
        offset += 0x8c0; // to get to pbc_rb_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kPbcRbTxDr:
        offset += 0x880; // to get to pbc_rb_tx_dr
        offset += 0x14; // to get to size
        break;
      case kPbcStatFmDr:
        offset += 0x900; // to get to pbc_stat_fm_dr
        offset += 0x14; // to get to size
        break;
      case kPbcStatRxDr:
        offset += 0x940; // to get to pbc_stat_rx_dr
        offset += 0x14; // to get to size
        break;
      case kPbcWbCplDr:
        offset += 0x840; // to get to pbc_wb_cpl_dr
        offset += 0x14; // to get to size
        break;
      case kPbcWbTxDr:
        offset += 0x800; // to get to pbc_wb_tx_dr
        offset += 0x14; // to get to size
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
    offset += 0x200000; // to get to pbc
    switch (selector_pbc_rspec) {
      case kPbcIlCplDr:
        offset += 0x700; // to get to pbc_il_cpl_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x34; // dru_rspec[]
        offset += 0x14; // to get to size
        break;
      case kPbcIlTxDr:
        offset += 0x600; // to get to pbc_il_tx_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x34; // dru_rspec[]
        offset += 0x14; // to get to size
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
    offset += 0x300000; // to get to tbc
    switch (selector_tbc_rspec) {
      case kTbcCplDr:
        offset += 0x200; // to get to tbc_cpl_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x34; // dru_rspec[]
        offset += 0x14; // to get to size
        break;
      case kTbcFmDr:
        offset += 0x400; // to get to tbc_fm_dr
        assert(index_dru_rspec < 8);
        offset += index_dru_rspec * 0x34; // dru_rspec[]
        offset += 0x14; // to get to size
        break;
      case kTbcRxDr:
        offset += 0x600; // to get to tbc_rx_dr
        assert(index_dru_rspec < 8);
        offset += index_dru_rspec * 0x34; // dru_rspec[]
        offset += 0x14; // to get to size
        break;
      case kTbcTxDr:
        offset += 0x100; // to get to tbc_tx_dr
        assert(index_dru_rspec < 4);
        offset += index_dru_rspec * 0x34; // dru_rspec[]
        offset += 0x14; // to get to size
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

#endif // __REGISTER_INCLUDES_DR_SIZE_MUTABLE_H__
