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
#ifndef __REGISTER_INCLUDES_FD_BYTESEL_CHUNK_INFO_R_MUTABLE_H__
#define __REGISTER_INCLUDES_FD_BYTESEL_CHUNK_INFO_R_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbay {
  namespace register_classes {

class FdByteselChunkInfoRMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum DprsrRegRspecEnum {
    kHoE,
    kHoI
  };
public:
  FdByteselChunkInfoRMutable(
      int chipNumber, int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec, int index_dprsr_ho_e, int index_dprsr_h_fd_full_chunk_g, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_dprsr_reg_rspec, index_dprsr_ho_e, index_dprsr_h_fd_full_chunk_g), 4, true, write_callback, read_callback, std::string("FdByteselChunkInfoRMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_dprsr_reg_rspec) + "," + boost::lexical_cast<std::string>(index_dprsr_ho_e) + "," + boost::lexical_cast<std::string>(index_dprsr_h_fd_full_chunk_g))
    {
    }
  FdByteselChunkInfoRMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "FdByteselChunkInfoRMutable")
    {
    }
public:






  uint8_t seg_vld() { return seg_vld_; }
  void seg_vld(const uint8_t &v) { seg_vld_=v; }






  uint8_t seg_sel() { return seg_sel_; }
  void seg_sel(const uint8_t &v) { seg_sel_=v; }








  uint8_t seg_slice() { return seg_slice_; }
  void seg_slice(const uint8_t &v) { seg_slice_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (seg_vld_ & 0x1);
    *data |= ((seg_sel_ & 0x3) << 1);
    *data |= ((seg_slice_ & 0x7) << 3);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    seg_vld_ = (data & 0x1);
    seg_sel_ = ((data >> 1) & 0x3);
    seg_slice_ = ((data >> 3) & 0x7);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    seg_vld_ = 0x0;
    seg_sel_ = 0x0;
    seg_slice_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("FdByteselChunkInfoRMutable") + ":\n";
    r += indent_string + "  " + std::string("seg_vld") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(seg_vld_) ) + "\n";
    all_zeros &= (0 == seg_vld_);
    r += indent_string + "  " + std::string("seg_sel") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(seg_sel_) ) + "\n";
    all_zeros &= (0 == seg_sel_);
    r += indent_string + "  " + std::string("seg_slice") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(seg_slice_) ) + "\n";
    all_zeros &= (0 == seg_slice_);
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
    r += indent_string + std::string("FdByteselChunkInfoRMutable") + ":\n";
    r += indent_string + "  " + std::string("seg_vld") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(seg_vld_) ) + "\n";
    all_zeros &= (0 == seg_vld_);
    r += indent_string + "  " + std::string("seg_sel") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(seg_sel_) ) + "\n";
    all_zeros &= (0 == seg_sel_);
    r += indent_string + "  " + std::string("seg_slice") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(seg_slice_) ) + "\n";
    all_zeros &= (0 == seg_slice_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t seg_vld_;
  uint8_t seg_sel_;
  uint8_t seg_slice_;
private:
  static int StartOffset(
      int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec, int index_dprsr_ho_e, int index_dprsr_h_fd_full_chunk_g
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    switch (selector_dprsr_reg_rspec) {
      case kHoE:
        offset += 0x38000; // to get to ho_e
        assert(index_dprsr_ho_e < 4);
        offset += index_dprsr_ho_e * 0x2000; // dprsr_ho_e[]
        assert(index_dprsr_h_fd_full_chunk_g < 128);
        offset += index_dprsr_h_fd_full_chunk_g * 0x10; // dprsr_h_fd_full_chunk_g[]
        break;
      case kHoI:
        offset += 0x30000; // to get to ho_i
        assert(index_dprsr_ho_e < 4);
        offset += index_dprsr_ho_e * 0x2000; // dprsr_ho_i[]
        assert(index_dprsr_h_fd_full_chunk_g < 128);
        offset += index_dprsr_h_fd_full_chunk_g * 0x10; // dprsr_h_fd_full_chunk_g[]
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};











  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_FD_BYTESEL_CHUNK_INFO_R_MUTABLE_H__
