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
#ifndef __REGISTER_INCLUDES_DPRSR_IC_REGS_INTR_MUTABLE_H__
#define __REGISTER_INCLUDES_DPRSR_IC_REGS_INTR_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "dprsr_ic_regs_intr_en0_mutable.h"
#include "dprsr_ic_regs_intr_en1_mutable.h"
#include "dprsr_ic_regs_intr_freeze_enable_mutable.h"
#include "dprsr_ic_regs_intr_inj_mutable.h"
#include "dprsr_ic_regs_intr_stat_mutable.h"

namespace jbay {
  namespace register_classes {

class DprsrIcRegsIntrMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  DprsrIcRegsIntrMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 20, true, write_callback, read_callback, std::string("DprsrIcRegsIntrMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  DprsrIcRegsIntrMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DprsrIcRegsIntrMutable")
    {
    }
public:






  DprsrIcRegsIntrStatMutable &intr_stat() { return intr_stat_; }







  DprsrIcRegsIntrEn0Mutable &intr_en0() { return intr_en0_; }







  DprsrIcRegsIntrEn1Mutable &intr_en1() { return intr_en1_; }








  DprsrIcRegsIntrInjMutable &intr_inj() { return intr_inj_; }





  DprsrIcRegsIntrFreezeEnableMutable &intr_freeze_enable() { return intr_freeze_enable_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      intr_stat_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      intr_en0_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      intr_en1_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      intr_inj_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      intr_freeze_enable_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      intr_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      intr_en0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      intr_en1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      intr_inj_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      intr_freeze_enable_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    intr_stat_.reset();
    intr_en0_.reset();
    intr_en1_.reset();
    intr_inj_.reset();
    intr_freeze_enable_.reset();
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
      r += intr_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += intr_en0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += intr_en1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += intr_inj_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += intr_freeze_enable_.to_string(offset,print_zeros,indent_string) ;
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
    r += intr_stat_.to_string(print_zeros,indent_string) ;
    r += intr_en0_.to_string(print_zeros,indent_string) ;
    r += intr_en1_.to_string(print_zeros,indent_string) ;
    r += intr_inj_.to_string(print_zeros,indent_string) ;
    r += intr_freeze_enable_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  DprsrIcRegsIntrStatMutable intr_stat_;
  DprsrIcRegsIntrEn0Mutable intr_en0_;
  DprsrIcRegsIntrEn1Mutable intr_en1_;
  DprsrIcRegsIntrInjMutable intr_inj_;
  DprsrIcRegsIntrFreezeEnableMutable intr_freeze_enable_;
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
    offset += 0x28000; // to get to icr
    offset += 0x2b80; // to get to intr
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_DPRSR_IC_REGS_INTR_MUTABLE_H__
