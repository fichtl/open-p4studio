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
#ifndef __REGISTER_INCLUDES_EBUF100_GLB_GROUP_H__
#define __REGISTER_INCLUDES_EBUF100_GLB_GROUP_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "ebuf100_ecc_dis.h"
#include "ebuf100_ecc_inj.h"
#include "ebuf100_freeze.h"
#include "ebuf100_glb_ctrl.h"
#include "ebuf100_glb_group_port_en_dprsr.h"
#include "ebuf100_glb_group_port_en_warp.h"
#include "ebuf100_int_en0.h"
#include "ebuf100_int_en1.h"
#include "ebuf100_int_log_group.h"
#include "ebuf100_int_stat.h"

namespace jbayB0 {
  namespace register_classes {

class Ebuf100GlbGroup : public model_core::RegisterBlock<RegisterCallback> {
public:
  Ebuf100GlbGroup(
      int chipNumber, int index_pipe_addrmap, int index_ebuf900_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ebuf900_reg), 152, false, write_callback, read_callback, std::string("Ebuf100GlbGroup")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ebuf900_reg))
    {
    }
  Ebuf100GlbGroup(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "Ebuf100GlbGroup")
    {
    }
public:





  Ebuf100GlbGroupPortEnDprsr &glb_group_port_en_dprsr() { return glb_group_port_en_dprsr_; }





  Ebuf100GlbGroupPortEnWarp &glb_group_port_en_warp() { return glb_group_port_en_warp_; }





  Ebuf100GlbCtrl &glb_group_glb_ctrl() { return glb_group_glb_ctrl_; }





  Ebuf100IntStat &glb_group_intr_stat() { return glb_group_intr_stat_; }





  Ebuf100IntEn0 &glb_group_intr_en0() { return glb_group_intr_en0_; }





  Ebuf100IntEn1 &glb_group_intr_en1() { return glb_group_intr_en1_; }





  Ebuf100Freeze &glb_group_freeze_en() { return glb_group_freeze_en_; }






  Ebuf100EccInj &glb_group_ecc_inj() { return glb_group_ecc_inj_; }






  Ebuf100EccDis &glb_group_ecc_dis() { return glb_group_ecc_dis_; }
  Ebuf100IntLogGroup &glb_group_intr_log_group() { return glb_group_intr_log_group_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      glb_group_port_en_dprsr_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      glb_group_port_en_warp_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0x10) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      glb_group_glb_ctrl_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      glb_group_intr_stat_.read( offset, data );
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      if (read_callback_) read_callback_();
      glb_group_intr_en0_.read( offset, data );
    }
    else if (offset >= 0x84 && offset < 0x88) {
      offset -= 0x84;
      if (read_callback_) read_callback_();
      glb_group_intr_en1_.read( offset, data );
    }
    else if (offset >= 0x88 && offset < 0x8c) {
      offset -= 0x88;
      if (read_callback_) read_callback_();
      glb_group_freeze_en_.read( offset, data );
    }
    else if (offset >= 0x8c && offset < 0x90) {
      offset -= 0x8c;
      if (read_callback_) read_callback_();
      glb_group_ecc_inj_.read( offset, data );
    }
    else if (offset >= 0x90 && offset < 0x94) {
      offset -= 0x90;
      if (read_callback_) read_callback_();
      glb_group_ecc_dis_.read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x80) {
      offset -= 0x40;
      if (read_callback_) read_callback_();
      glb_group_intr_log_group_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      glb_group_port_en_dprsr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      glb_group_port_en_warp_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0x10) {
      offset -= 0x8;
      glb_group_glb_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      glb_group_intr_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      glb_group_intr_en0_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x84 && offset < 0x88) {
      offset -= 0x84;
      glb_group_intr_en1_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x88 && offset < 0x8c) {
      offset -= 0x88;
      glb_group_freeze_en_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8c && offset < 0x90) {
      offset -= 0x8c;
      glb_group_ecc_inj_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x90 && offset < 0x94) {
      offset -= 0x90;
      glb_group_ecc_dis_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x80) {
      offset -= 0x40;
      glb_group_intr_log_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    glb_group_port_en_dprsr_.reset();
    glb_group_port_en_warp_.reset();
    glb_group_glb_ctrl_.reset();
    glb_group_intr_stat_.reset();
    glb_group_intr_en0_.reset();
    glb_group_intr_en1_.reset();
    glb_group_freeze_en_.reset();
    glb_group_ecc_inj_.reset();
    glb_group_ecc_dis_.reset();
    glb_group_intr_log_group_.reset();
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
      r += glb_group_port_en_dprsr_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += glb_group_port_en_warp_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0x10) {
      offset -= 0x8;
      r += glb_group_glb_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += glb_group_intr_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      r += glb_group_intr_en0_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x84 && offset < 0x88) {
      offset -= 0x84;
      r += glb_group_intr_en1_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x88 && offset < 0x8c) {
      offset -= 0x88;
      r += glb_group_freeze_en_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8c && offset < 0x90) {
      offset -= 0x8c;
      r += glb_group_ecc_inj_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x90 && offset < 0x94) {
      offset -= 0x90;
      r += glb_group_ecc_dis_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x80) {
      offset -= 0x40;
      r += glb_group_intr_log_group_.to_string(offset,print_zeros,indent_string) ;
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
    r += glb_group_port_en_dprsr_.to_string(print_zeros,indent_string) ;
    r += glb_group_port_en_warp_.to_string(print_zeros,indent_string) ;
    r += glb_group_glb_ctrl_.to_string(print_zeros,indent_string) ;
    r += glb_group_intr_stat_.to_string(print_zeros,indent_string) ;
    r += glb_group_intr_en0_.to_string(print_zeros,indent_string) ;
    r += glb_group_intr_en1_.to_string(print_zeros,indent_string) ;
    r += glb_group_freeze_en_.to_string(print_zeros,indent_string) ;
    r += glb_group_ecc_inj_.to_string(print_zeros,indent_string) ;
    r += glb_group_ecc_dis_.to_string(print_zeros,indent_string) ;
    r += glb_group_intr_log_group_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  Ebuf100GlbGroupPortEnDprsr glb_group_port_en_dprsr_;
  Ebuf100GlbGroupPortEnWarp glb_group_port_en_warp_;
  Ebuf100GlbCtrl glb_group_glb_ctrl_;
  Ebuf100IntStat glb_group_intr_stat_;
  Ebuf100IntEn0 glb_group_intr_en0_;
  Ebuf100IntEn1 glb_group_intr_en1_;
  Ebuf100Freeze glb_group_freeze_en_;
  Ebuf100EccInj glb_group_ecc_inj_;
  Ebuf100EccDis glb_group_ecc_dis_;
  Ebuf100IntLogGroup glb_group_intr_log_group_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ebuf900_reg
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x40000; // to get to ebuf900reg
    assert(index_ebuf900_reg < 4);
    offset += index_ebuf900_reg * 0x2000; // ebuf900_reg[]
    offset += 0x1000; // to get to ebuf100reg
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_EBUF100_GLB_GROUP_H__
