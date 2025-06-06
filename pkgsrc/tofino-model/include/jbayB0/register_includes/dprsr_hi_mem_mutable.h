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
#ifndef __REGISTER_INCLUDES_DPRSR_HI_MEM_MUTABLE_H__
#define __REGISTER_INCLUDES_DPRSR_HI_MEM_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "dprsr_h_fd_compress_map_mutable.h"
#include "dprsr_h_mirror_tbl_map_mutable.h"

namespace jbayB0 {
  namespace register_classes {

class DprsrHiMemMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum DprsrRegRspecEnum {
    kHoE,
    kHoI
  };
public:
  DprsrHiMemMutable(
      int chipNumber, int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec, int index_dprsr_ho_e, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, selector_dprsr_reg_rspec, index_dprsr_ho_e), 3072, true, write_callback, read_callback, std::string("DprsrHiMemMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(selector_dprsr_reg_rspec) + "," + boost::lexical_cast<std::string>(index_dprsr_ho_e))
    {
    }
  DprsrHiMemMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DprsrHiMemMutable")
    {
    }
public:
  DprsrHFdCompressMapMutable &fd_compress() { return fd_compress_; }
  DprsrHMirrorTblMapMutable &mirr_hdr_tbl() { return mirr_hdr_tbl_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x800) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      fd_compress_.read( offset, data );
    }
    else if (offset >= 0x800 && offset < 0xc00) {
      offset -= 0x800;
      if (read_callback_) read_callback_();
      mirr_hdr_tbl_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x800) {
      offset -= 0x0;
      fd_compress_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x800 && offset < 0xc00) {
      offset -= 0x800;
      mirr_hdr_tbl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    fd_compress_.reset();
    mirr_hdr_tbl_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x800) {
      offset -= 0x0;
      r += fd_compress_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x800 && offset < 0xc00) {
      offset -= 0x800;
      r += mirr_hdr_tbl_.to_string(offset,print_zeros,indent_string) ;
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
    r += fd_compress_.to_string(print_zeros,indent_string) ;
    r += mirr_hdr_tbl_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  DprsrHFdCompressMapMutable fd_compress_;
  DprsrHMirrorTblMapMutable mirr_hdr_tbl_;
private:
  static int StartOffset(
      int index_pipe_addrmap, DprsrRegRspecEnum selector_dprsr_reg_rspec, int index_dprsr_ho_e
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
        break;
      case kHoI:
        offset += 0x30000; // to get to ho_i
        assert(index_dprsr_ho_e < 4);
        offset += index_dprsr_ho_e * 0x2000; // dprsr_ho_i[]
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

#endif // __REGISTER_INCLUDES_DPRSR_HI_MEM_MUTABLE_H__
