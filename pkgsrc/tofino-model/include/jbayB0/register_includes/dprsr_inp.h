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
#ifndef __REGISTER_INCLUDES_DPRSR_INP_H__
#define __REGISTER_INCLUDES_DPRSR_INP_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "dprsr_ic_regs.h"
#include "dprsr_ii_mem.h"
#include "dprsr_ipp_mem.h"
#include "dprsr_ipp_regs.h"

namespace jbayB0 {
  namespace register_classes {

class DprsrInp : public model_core::RegisterBlock<RegisterCallback> {
public:
  DprsrInp(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 176128, false, write_callback, read_callback, std::string("DprsrInp")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  DprsrInp(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "DprsrInp")
    {
    }
public:





  DprsrIiMem &iim() { return iim_; }






  DprsrIppRegs &ipp() { return ipp_; }






  DprsrIppMem &ipp_m() { return ipp_m_; }





  DprsrIcRegs &icr() { return icr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x20000) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      iim_.read( offset, data );
    }
    else if (offset >= 0x20000 && offset < 0x20748) {
      offset -= 0x20000;
      if (read_callback_) read_callback_();
      ipp_.read( offset, data );
    }
    else if (offset >= 0x24000 && offset < 0x28000) {
      offset -= 0x24000;
      if (read_callback_) read_callback_();
      ipp_m_.read( offset, data );
    }
    else if (offset >= 0x28000 && offset < 0x2b000) {
      offset -= 0x28000;
      if (read_callback_) read_callback_();
      icr_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x20000) {
      offset -= 0x0;
      iim_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20000 && offset < 0x20748) {
      offset -= 0x20000;
      ipp_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x24000 && offset < 0x28000) {
      offset -= 0x24000;
      ipp_m_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28000 && offset < 0x2b000) {
      offset -= 0x28000;
      icr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    iim_.reset();
    ipp_.reset();
    ipp_m_.reset();
    icr_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x20000) {
      offset -= 0x0;
      r += iim_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20000 && offset < 0x20748) {
      offset -= 0x20000;
      r += ipp_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x24000 && offset < 0x28000) {
      offset -= 0x24000;
      r += ipp_m_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28000 && offset < 0x2b000) {
      offset -= 0x28000;
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
    r += ipp_.to_string(print_zeros,indent_string) ;
    r += ipp_m_.to_string(print_zeros,indent_string) ;
    r += icr_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  DprsrIiMem iim_;
  DprsrIppRegs ipp_;
  DprsrIppMem ipp_m_;
  DprsrIcRegs icr_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_DPRSR_INP_H__
