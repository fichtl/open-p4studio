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
#ifndef __REGISTER_INCLUDES_TM_SCH_PIPE_RSPEC_INTR_MUTABLE_H__
#define __REGISTER_INCLUDES_TM_SCH_PIPE_RSPEC_INTR_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "tm_sch_pipe_rspec_intr_en0_mutable.h"
#include "tm_sch_pipe_rspec_intr_en1_mutable.h"
#include "tm_sch_pipe_rspec_intr_freeze_enable_mutable.h"
#include "tm_sch_pipe_rspec_intr_inj_mutable.h"
#include "tm_sch_pipe_rspec_intr_stat_mutable.h"

namespace jbay {
  namespace register_classes {

class TmSchPipeRspecIntrMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum TmTopRspecEnum {
    kTmSchaTop,
    kTmSchbTop
  };
public:
  TmSchPipeRspecIntrMutable(
      int chipNumber, TmTopRspecEnum selector_tm_top_rspec, int index_tm_sch_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_tm_top_rspec, index_tm_sch_pipe_rspec), 20, true, write_callback, read_callback, std::string("TmSchPipeRspecIntrMutable")+":"+boost::lexical_cast<std::string>(selector_tm_top_rspec) + "," + boost::lexical_cast<std::string>(index_tm_sch_pipe_rspec))
    {
    }
  TmSchPipeRspecIntrMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "TmSchPipeRspecIntrMutable")
    {
    }
public:






  TmSchPipeRspecIntrStatMutable &intr_stat() { return intr_stat_; }







  TmSchPipeRspecIntrEn0Mutable &intr_en0() { return intr_en0_; }







  TmSchPipeRspecIntrEn1Mutable &intr_en1() { return intr_en1_; }








  TmSchPipeRspecIntrInjMutable &intr_inj() { return intr_inj_; }





  TmSchPipeRspecIntrFreezeEnableMutable &intr_freeze_enable() { return intr_freeze_enable_; }

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
  TmSchPipeRspecIntrStatMutable intr_stat_;
  TmSchPipeRspecIntrEn0Mutable intr_en0_;
  TmSchPipeRspecIntrEn1Mutable intr_en1_;
  TmSchPipeRspecIntrInjMutable intr_inj_;
  TmSchPipeRspecIntrFreezeEnableMutable intr_freeze_enable_;
private:
  static int StartOffset(
      TmTopRspecEnum selector_tm_top_rspec, int index_tm_sch_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    switch (selector_tm_top_rspec) {
      case kTmSchaTop:
        offset += 0x180000; // to get to tm_scha_top
        assert(index_tm_sch_pipe_rspec < 2);
        offset += index_tm_sch_pipe_rspec * 0x8000; // tm_sch_pipe_rspec[]
        offset += 0x40; // to get to intr
        break;
      case kTmSchbTop:
        offset += 0x200000; // to get to tm_schb_top
        assert(index_tm_sch_pipe_rspec < 2);
        offset += index_tm_sch_pipe_rspec * 0x8000; // tm_sch_pipe_rspec[]
        offset += 0x40; // to get to intr
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

#endif // __REGISTER_INCLUDES_TM_SCH_PIPE_RSPEC_INTR_MUTABLE_H__
