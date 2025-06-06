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
#ifndef __REGISTER_INCLUDES_DPRSR_TPHV_CSUM_CFG_ENTRY_G_ZEROS_AS_ONES_MUTABLE_H__
#define __REGISTER_INCLUDES_DPRSR_TPHV_CSUM_CFG_ENTRY_G_ZEROS_AS_ONES_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofinoB0 {
  namespace register_classes {

class DprsrTphvCsumCfgEntryGZerosAsOnesMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum DprsrHdrEnum {
    kHem,
    kHim
  };
public:
  DprsrTphvCsumCfgEntryGZerosAsOnesMutable(
      int chipNumber, int index_pipe_addrmap, DprsrHdrEnum selector_dprsr_hdr, int index_dprsr_tphv_csum_cfg_entry_g, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_dprsr_hdr, index_dprsr_tphv_csum_cfg_entry_g), 4, true, write_callback, read_callback, std::string("DprsrTphvCsumCfgEntryGZerosAsOnesMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_dprsr_hdr) + "," + boost::lexical_cast<std::string>(index_dprsr_tphv_csum_cfg_entry_g))
    {
    }
  DprsrTphvCsumCfgEntryGZerosAsOnesMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DprsrTphvCsumCfgEntryGZerosAsOnesMutable")
    {
    }
public:




  uint8_t en() { return en_; }
  void en(const uint8_t &v) { en_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (en_ & 0x1);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    en_ = (data & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    en_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DprsrTphvCsumCfgEntryGZerosAsOnesMutable") + ":\n";
    r += indent_string + "  " + std::string("en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en_) ) + "\n";
    all_zeros &= (0 == en_);
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
    r += indent_string + std::string("DprsrTphvCsumCfgEntryGZerosAsOnesMutable") + ":\n";
    r += indent_string + "  " + std::string("en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(en_) ) + "\n";
    all_zeros &= (0 == en_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t en_;
private:
  static int StartOffset(
      int index_pipe_addrmap, DprsrHdrEnum selector_dprsr_hdr, int index_dprsr_tphv_csum_cfg_entry_g
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    offset += 0x40000; // to get to hdr
    switch (selector_dprsr_hdr) {
      case kHem:
        offset += 0x4000; // to get to hem
        assert(index_dprsr_tphv_csum_cfg_entry_g < 6);
        offset += index_dprsr_tphv_csum_cfg_entry_g * 0x400; // dprsr_tphv_csum_cfg_entry_g[]
        offset += 0x3fc; // to get to csum_cfg_zeros_as_ones
        break;
      case kHim:
        offset += 0x20000; // to get to him
        assert(index_dprsr_tphv_csum_cfg_entry_g < 6);
        offset += index_dprsr_tphv_csum_cfg_entry_g * 0x400; // dprsr_tphv_csum_cfg_entry_g[]
        offset += 0x3fc; // to get to csum_cfg_zeros_as_ones
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};











  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_DPRSR_TPHV_CSUM_CFG_ENTRY_G_ZEROS_AS_ONES_MUTABLE_H__
