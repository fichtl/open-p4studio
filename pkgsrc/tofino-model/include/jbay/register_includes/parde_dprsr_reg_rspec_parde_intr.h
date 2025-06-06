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
#ifndef __REGISTER_INCLUDES_PARDE_DPRSR_REG_RSPEC_PARDE_INTR_H__
#define __REGISTER_INCLUDES_PARDE_DPRSR_REG_RSPEC_PARDE_INTR_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "parde_dprsr_reg_rspec_parde_intr_status0.h"
#include "parde_dprsr_reg_rspec_parde_intr_status1.h"

namespace jbay {
  namespace register_classes {

class PardeDprsrRegRspecPardeIntr : public model_core::RegisterBlock<RegisterCallback> {
public:
  PardeDprsrRegRspecPardeIntr(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 8, false, write_callback, read_callback, std::string("PardeDprsrRegRspecPardeIntr")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PardeDprsrRegRspecPardeIntr(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PardeDprsrRegRspecPardeIntr")
    {
    }
public:





  PardeDprsrRegRspecPardeIntrStatus0 &parde_intr_status0() { return parde_intr_status0_; }





  PardeDprsrRegRspecPardeIntrStatus1 &parde_intr_status1() { return parde_intr_status1_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      parde_intr_status0_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      parde_intr_status1_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      parde_intr_status0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      parde_intr_status1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    parde_intr_status0_.reset();
    parde_intr_status1_.reset();
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
      r += parde_intr_status0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += parde_intr_status1_.to_string(offset,print_zeros,indent_string) ;
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
    r += parde_intr_status0_.to_string(print_zeros,indent_string) ;
    r += parde_intr_status1_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  PardeDprsrRegRspecPardeIntrStatus0 parde_intr_status0_;
  PardeDprsrRegRspecPardeIntrStatus1 parde_intr_status1_;
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
    offset += 0x2f800; // to get to dprsr_csr_ring
    offset += 0x30; // to get to parde_intr
    return offset;
  }

};





  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PARDE_DPRSR_REG_RSPEC_PARDE_INTR_H__
