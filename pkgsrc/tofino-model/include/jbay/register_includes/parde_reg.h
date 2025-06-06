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
#ifndef __REGISTER_INCLUDES_PARDE_REG_H__
#define __REGISTER_INCLUDES_PARDE_REG_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "dprsr_reg.h"
#include "mirr_reg.h"
#include "parde_glue_stn_reg.h"

namespace jbay {
  namespace register_classes {

class PardeReg : public model_core::RegisterBlock<RegisterCallback> {
public:
  PardeReg(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 1572864, false, write_callback, read_callback, std::string("PardeReg")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PardeReg(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PardeReg")
    {
    }
public:





  PardeGlueStnReg &pgstnreg() { return pgstnreg_; }





  MirrReg &mirreg() { return mirreg_; }





  DprsrReg &dprsrreg() { return dprsrreg_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x80000) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      pgstnreg_.read( offset, data );
    }
    else if (offset >= 0x80000 && offset < 0x100000) {
      offset -= 0x80000;
      if (read_callback_) read_callback_();
      mirreg_.read( offset, data );
    }
    else if (offset >= 0x100000 && offset < 0x180000) {
      offset -= 0x100000;
      if (read_callback_) read_callback_();
      dprsrreg_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x80000) {
      offset -= 0x0;
      pgstnreg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80000 && offset < 0x100000) {
      offset -= 0x80000;
      mirreg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x100000 && offset < 0x180000) {
      offset -= 0x100000;
      dprsrreg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    pgstnreg_.reset();
    mirreg_.reset();
    dprsrreg_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x80000) {
      offset -= 0x0;
      r += pgstnreg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80000 && offset < 0x100000) {
      offset -= 0x80000;
      r += mirreg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x100000 && offset < 0x180000) {
      offset -= 0x100000;
      r += dprsrreg_.to_string(offset,print_zeros,indent_string) ;
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
    r += pgstnreg_.to_string(print_zeros,indent_string) ;
    r += mirreg_.to_string(print_zeros,indent_string) ;
    r += dprsrreg_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  PardeGlueStnReg pgstnreg_;
  MirrReg mirreg_;
  DprsrReg dprsrreg_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PARDE_REG_H__
