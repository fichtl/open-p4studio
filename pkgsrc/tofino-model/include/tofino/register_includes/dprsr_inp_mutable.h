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
#ifndef __REGISTER_INCLUDES_DPRSR_INP_MUTABLE_H__
#define __REGISTER_INCLUDES_DPRSR_INP_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "dprsr_ic_regs_mutable.h"
#include "dprsr_ie_mem_mutable.h"
#include "dprsr_ie_regs_mutable.h"
#include "dprsr_ii_mem_mutable.h"
#include "dprsr_ii_regs_mutable.h"

namespace tofino {
  namespace register_classes {

class DprsrInpMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  DprsrInpMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 39424, true, write_callback, read_callback, std::string("DprsrInpMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  DprsrInpMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DprsrInpMutable")
    {
    }
public:





  DprsrIiMemMutable &iim() { return iim_; }





  DprsrIeMemMutable &iem() { return iem_; }





  DprsrIiRegsMutable &iir() { return iir_; }





  DprsrIeRegsMutable &ier() { return ier_; }





  DprsrIcRegsMutable &icr() { return icr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x3304) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      iim_.read( offset, data );
    }
    else if (offset >= 0x4000 && offset < 0x7304) {
      offset -= 0x4000;
      if (read_callback_) read_callback_();
      iem_.read( offset, data );
    }
    else if (offset >= 0x8000 && offset < 0x87f4) {
      offset -= 0x8000;
      if (read_callback_) read_callback_();
      iir_.read( offset, data );
    }
    else if (offset >= 0x9000 && offset < 0x9074) {
      offset -= 0x9000;
      if (read_callback_) read_callback_();
      ier_.read( offset, data );
    }
    else if (offset >= 0x9800 && offset < 0x9a00) {
      offset -= 0x9800;
      if (read_callback_) read_callback_();
      icr_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x3304) {
      offset -= 0x0;
      iim_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4000 && offset < 0x7304) {
      offset -= 0x4000;
      iem_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8000 && offset < 0x87f4) {
      offset -= 0x8000;
      iir_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x9000 && offset < 0x9074) {
      offset -= 0x9000;
      ier_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x9800 && offset < 0x9a00) {
      offset -= 0x9800;
      icr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    iim_.reset();
    iem_.reset();
    iir_.reset();
    ier_.reset();
    icr_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x3304) {
      offset -= 0x0;
      r += iim_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4000 && offset < 0x7304) {
      offset -= 0x4000;
      r += iem_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8000 && offset < 0x87f4) {
      offset -= 0x8000;
      r += iir_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x9000 && offset < 0x9074) {
      offset -= 0x9000;
      r += ier_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x9800 && offset < 0x9a00) {
      offset -= 0x9800;
      r += icr_.to_string(offset,print_zeros,indent_string) ;
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
    r += iim_.to_string(print_zeros,indent_string) ;
    r += iem_.to_string(print_zeros,indent_string) ;
    r += iir_.to_string(print_zeros,indent_string) ;
    r += ier_.to_string(print_zeros,indent_string) ;
    r += icr_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  DprsrIiMemMutable iim_;
  DprsrIeMemMutable iem_;
  DprsrIiRegsMutable iir_;
  DprsrIeRegsMutable ier_;
  DprsrIcRegsMutable icr_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_DPRSR_INP_MUTABLE_H__
