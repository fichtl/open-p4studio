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


#ifndef __REGISTER_INCLUDES_MIR_BUF_REGS_COAL_DESC_GRP_H__
#define __REGISTER_INCLUDES_MIR_BUF_REGS_COAL_DESC_GRP_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "mir_buf_regs_coal_ctrl0.h"
#include "mir_buf_regs_coal_ctrl1.h"
#include "mir_buf_regs_coal_ctrl2.h"
#include "mir_buf_regs_coal_pkt_header0.h"
#include "mir_buf_regs_coal_pkt_header1.h"
#include "mir_buf_regs_coal_pkt_header2.h"
#include "mir_buf_regs_coal_pkt_header3.h"

namespace jbayB0 {
  namespace register_classes {

class MirBufRegsCoalDescGrp : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirBufRegsCoalDescGrp(
      int chipNumber, int index_pipe_addrmap, int index_mir_buf_regs_coal_desc_grp, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mir_buf_regs_coal_desc_grp), 28, false, write_callback, read_callback, std::string("MirBufRegsCoalDescGrp")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mir_buf_regs_coal_desc_grp))
    {
    }
  MirBufRegsCoalDescGrp(

  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MirBufRegsCoalDescGrp")
    {
    }
public:





  MirBufRegsCoalCtrl0 &coal_desc_grp_coal_ctrl0() { return coal_desc_grp_coal_ctrl0_; }





  MirBufRegsCoalCtrl1 &coal_desc_grp_coal_ctrl1() { return coal_desc_grp_coal_ctrl1_; }






  MirBufRegsCoalPktHeader0 &coal_desc_grp_coal_pkt_header0() { return coal_desc_grp_coal_pkt_header0_; }






  MirBufRegsCoalPktHeader1 &coal_desc_grp_coal_pkt_header1() { return coal_desc_grp_coal_pkt_header1_; }






  MirBufRegsCoalPktHeader2 &coal_desc_grp_coal_pkt_header2() { return coal_desc_grp_coal_pkt_header2_; }






  MirBufRegsCoalPktHeader3 &coal_desc_grp_coal_pkt_header3() { return coal_desc_grp_coal_pkt_header3_; }






  MirBufRegsCoalCtrl2 &coal_desc_grp_coal_ctrl2() { return coal_desc_grp_coal_ctrl2_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x200 && offset < 0x204) {
      offset -= 0x200;
      if (read_callback_) read_callback_();
      coal_desc_grp_coal_ctrl0_.read( offset, data );
    }
    else if (offset >= 0x204 && offset < 0x208) {
      offset -= 0x204;
      if (read_callback_) read_callback_();
      coal_desc_grp_coal_ctrl1_.read( offset, data );
    }
    else if (offset >= 0x208 && offset < 0x20c) {
      offset -= 0x208;
      if (read_callback_) read_callback_();
      coal_desc_grp_coal_pkt_header0_.read( offset, data );
    }
    else if (offset >= 0x20c && offset < 0x210) {
      offset -= 0x20c;
      if (read_callback_) read_callback_();
      coal_desc_grp_coal_pkt_header1_.read( offset, data );
    }
    else if (offset >= 0x210 && offset < 0x214) {
      offset -= 0x210;
      if (read_callback_) read_callback_();
      coal_desc_grp_coal_pkt_header2_.read( offset, data );
    }
    else if (offset >= 0x214 && offset < 0x218) {
      offset -= 0x214;
      if (read_callback_) read_callback_();
      coal_desc_grp_coal_pkt_header3_.read( offset, data );
    }
    else if (offset >= 0x218 && offset < 0x21c) {
      offset -= 0x218;
      if (read_callback_) read_callback_();
      coal_desc_grp_coal_ctrl2_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x200 && offset < 0x204) {
      offset -= 0x200;
      coal_desc_grp_coal_ctrl0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x204 && offset < 0x208) {
      offset -= 0x204;
      coal_desc_grp_coal_ctrl1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x208 && offset < 0x20c) {
      offset -= 0x208;
      coal_desc_grp_coal_pkt_header0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20c && offset < 0x210) {
      offset -= 0x20c;
      coal_desc_grp_coal_pkt_header1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x210 && offset < 0x214) {
      offset -= 0x210;
      coal_desc_grp_coal_pkt_header2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x214 && offset < 0x218) {
      offset -= 0x214;
      coal_desc_grp_coal_pkt_header3_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x218 && offset < 0x21c) {
      offset -= 0x218;
      coal_desc_grp_coal_ctrl2_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(

      ) {
    coal_desc_grp_coal_ctrl0_.reset();
    coal_desc_grp_coal_ctrl1_.reset();
    coal_desc_grp_coal_pkt_header0_.reset();
    coal_desc_grp_coal_pkt_header1_.reset();
    coal_desc_grp_coal_pkt_header2_.reset();
    coal_desc_grp_coal_pkt_header3_.reset();
    coal_desc_grp_coal_ctrl2_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x200 && offset < 0x204) {
      offset -= 0x200;
      r += coal_desc_grp_coal_ctrl0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x204 && offset < 0x208) {
      offset -= 0x204;
      r += coal_desc_grp_coal_ctrl1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x208 && offset < 0x20c) {
      offset -= 0x208;
      r += coal_desc_grp_coal_pkt_header0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20c && offset < 0x210) {
      offset -= 0x20c;
      r += coal_desc_grp_coal_pkt_header1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x210 && offset < 0x214) {
      offset -= 0x210;
      r += coal_desc_grp_coal_pkt_header2_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x214 && offset < 0x218) {
      offset -= 0x214;
      r += coal_desc_grp_coal_pkt_header3_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x218 && offset < 0x21c) {
      offset -= 0x218;
      r += coal_desc_grp_coal_ctrl2_.to_string(offset,print_zeros,indent_string) ;
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
    r += coal_desc_grp_coal_ctrl0_.to_string(print_zeros,indent_string) ;
    r += coal_desc_grp_coal_ctrl1_.to_string(print_zeros,indent_string) ;
    r += coal_desc_grp_coal_pkt_header0_.to_string(print_zeros,indent_string) ;
    r += coal_desc_grp_coal_pkt_header1_.to_string(print_zeros,indent_string) ;
    r += coal_desc_grp_coal_pkt_header2_.to_string(print_zeros,indent_string) ;
    r += coal_desc_grp_coal_pkt_header3_.to_string(print_zeros,indent_string) ;
    r += coal_desc_grp_coal_ctrl2_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  MirBufRegsCoalCtrl0 coal_desc_grp_coal_ctrl0_;
  MirBufRegsCoalCtrl1 coal_desc_grp_coal_ctrl1_;
  MirBufRegsCoalPktHeader0 coal_desc_grp_coal_pkt_header0_;
  MirBufRegsCoalPktHeader1 coal_desc_grp_coal_pkt_header1_;
  MirBufRegsCoalPktHeader2 coal_desc_grp_coal_pkt_header2_;
  MirBufRegsCoalPktHeader3 coal_desc_grp_coal_pkt_header3_;
  MirBufRegsCoalCtrl2 coal_desc_grp_coal_ctrl2_;
private:
  int StartOffset(
      int index_pipe_addrmap, int index_mir_buf_regs_coal_desc_grp
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    offset += 0x20000; // to get to mirror
    offset += 0x8000; // to get to mir_buf_regs
    assert(index_mir_buf_regs_coal_desc_grp < 8);
    offset += index_mir_buf_regs_coal_desc_grp * 0x1c; // mir_buf_regs_coal_desc_grp[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MIR_BUF_REGS_COAL_DESC_GRP_H__
