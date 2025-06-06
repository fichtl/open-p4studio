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


#ifndef __REGISTER_INCLUDES_MIR_BUF_DESC_NORM_DESC_GRP_H__
#define __REGISTER_INCLUDES_MIR_BUF_DESC_NORM_DESC_GRP_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "mir_buf_desc_dummy.h"
#include "mir_buf_desc_session_ctrl.h"
#include "mir_buf_desc_session_meta0.h"
#include "mir_buf_desc_session_meta1.h"
#include "mir_buf_desc_session_meta2.h"
#include "mir_buf_desc_session_meta3.h"
#include "mir_buf_desc_session_meta4.h"

namespace jbay {
  namespace register_classes {

class MirBufDescNormDescGrp : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirBufDescNormDescGrp(
      int chipNumber, int index_pipe_addrmap, int index_mir_buf_desc_norm_desc_grp, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mir_buf_desc_norm_desc_grp), 32, false, write_callback, read_callback, std::string("MirBufDescNormDescGrp")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mir_buf_desc_norm_desc_grp))
    {
    }
  MirBufDescNormDescGrp(

  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MirBufDescNormDescGrp")
    {
    }
public:





  MirBufDescSessionMeta0 &norm_desc_grp_session_meta0() { return norm_desc_grp_session_meta0_; }





  MirBufDescSessionMeta1 &norm_desc_grp_session_meta1() { return norm_desc_grp_session_meta1_; }





  MirBufDescSessionMeta2 &norm_desc_grp_session_meta2() { return norm_desc_grp_session_meta2_; }





  MirBufDescSessionMeta3 &norm_desc_grp_session_meta3() { return norm_desc_grp_session_meta3_; }





  MirBufDescSessionMeta4 &norm_desc_grp_session_meta4() { return norm_desc_grp_session_meta4_; }






  MirBufDescSessionCtrl &norm_desc_grp_session_ctrl() { return norm_desc_grp_session_ctrl_; }





  MirBufDescDummy &norm_desc_grp_dummy1() { return norm_desc_grp_dummy1_; }





  MirBufDescDummy &norm_desc_grp_dummy2() { return norm_desc_grp_dummy2_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      norm_desc_grp_session_meta0_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      norm_desc_grp_session_meta1_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      norm_desc_grp_session_meta2_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      norm_desc_grp_session_meta3_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      norm_desc_grp_session_meta4_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      norm_desc_grp_session_ctrl_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      norm_desc_grp_dummy1_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      norm_desc_grp_dummy2_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      norm_desc_grp_session_meta0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      norm_desc_grp_session_meta1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      norm_desc_grp_session_meta2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      norm_desc_grp_session_meta3_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      norm_desc_grp_session_meta4_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      norm_desc_grp_session_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      norm_desc_grp_dummy1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      norm_desc_grp_dummy2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(

      ) {
    norm_desc_grp_session_meta0_.reset();
    norm_desc_grp_session_meta1_.reset();
    norm_desc_grp_session_meta2_.reset();
    norm_desc_grp_session_meta3_.reset();
    norm_desc_grp_session_meta4_.reset();
    norm_desc_grp_session_ctrl_.reset();
    norm_desc_grp_dummy1_.reset();
    norm_desc_grp_dummy2_.reset();
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
      r += norm_desc_grp_session_meta0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += norm_desc_grp_session_meta1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += norm_desc_grp_session_meta2_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += norm_desc_grp_session_meta3_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += norm_desc_grp_session_meta4_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += norm_desc_grp_session_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += norm_desc_grp_dummy1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += norm_desc_grp_dummy2_.to_string(offset,print_zeros,indent_string) ;
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
    r += norm_desc_grp_session_meta0_.to_string(print_zeros,indent_string) ;
    r += norm_desc_grp_session_meta1_.to_string(print_zeros,indent_string) ;
    r += norm_desc_grp_session_meta2_.to_string(print_zeros,indent_string) ;
    r += norm_desc_grp_session_meta3_.to_string(print_zeros,indent_string) ;
    r += norm_desc_grp_session_meta4_.to_string(print_zeros,indent_string) ;
    r += norm_desc_grp_session_ctrl_.to_string(print_zeros,indent_string) ;
    r += norm_desc_grp_dummy1_.to_string(print_zeros,indent_string) ;
    r += norm_desc_grp_dummy2_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  MirBufDescSessionMeta0 norm_desc_grp_session_meta0_;
  MirBufDescSessionMeta1 norm_desc_grp_session_meta1_;
  MirBufDescSessionMeta2 norm_desc_grp_session_meta2_;
  MirBufDescSessionMeta3 norm_desc_grp_session_meta3_;
  MirBufDescSessionMeta4 norm_desc_grp_session_meta4_;
  MirBufDescSessionCtrl norm_desc_grp_session_ctrl_;
  MirBufDescDummy norm_desc_grp_dummy1_;
  MirBufDescDummy norm_desc_grp_dummy2_;
private:
  int StartOffset(
      int index_pipe_addrmap, int index_mir_buf_desc_norm_desc_grp
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    offset += 0x20000; // to get to mirror
    assert(index_mir_buf_desc_norm_desc_grp < 1024);
    offset += index_mir_buf_desc_norm_desc_grp * 0x20; // mir_buf_desc_norm_desc_grp[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_MIR_BUF_DESC_NORM_DESC_GRP_H__
