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
#ifndef __REGISTER_INCLUDES_EBUF_DISP_REGS_MUTABLE_H__
#define __REGISTER_INCLUDES_EBUF_DISP_REGS_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "ebuf_disp_regs_cred_ctrl_mutable.h"
#include "ebuf_disp_regs_dbg_ctrl_mutable.h"
#include "ebuf_disp_regs_dprs_ctrl_mutable.h"
#include "ebuf_disp_regs_ebuf_disp_fifo_avail_mutable.h"
#include "ebuf_disp_regs_int_en_mutable.h"
#include "ebuf_disp_regs_int_freeze_mutable.h"
#include "ebuf_disp_regs_int_inj_mutable.h"
#include "ebuf_disp_regs_int_pri_mutable.h"
#include "ebuf_disp_regs_int_stat_mutable.h"
#include "ebuf_disp_regs_port_mode_mutable.h"

namespace tofinoB0 {
  namespace register_classes {

class EbufDispRegsMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  EbufDispRegsMutable(
      int chipNumber, int index_pipe_addrmap, int index_egrNx_regs, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_egrNx_regs), 60, true, write_callback, read_callback, std::string("EbufDispRegsMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_egrNx_regs))
    {
    }
  EbufDispRegsMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "EbufDispRegsMutable")
    {
    }
public:





  EbufDispRegsPortModeMutable &port_mode() { return port_mode_; }





  EbufDispRegsCredCtrlMutable &cred_ctrl() { return cred_ctrl_; }







  EbufDispRegsDprsCtrlMutable &chnl_ctrl(int j0) { return chnl_ctrl_[j0]; }





  EbufDispRegsIntStatMutable &int_stat() { return int_stat_; }





  EbufDispRegsIntEnMutable &int_en() { return int_en_; }





  EbufDispRegsIntPriMutable &int_pri() { return int_pri_; }






  EbufDispRegsIntInjMutable &int_inj() { return int_inj_; }





  EbufDispRegsEbufDispFifoAvailMutable &ebuf_disp_fifo_avail() { return ebuf_disp_fifo_avail_; }





  EbufDispRegsIntFreezeMutable &int_freeze() { return int_freeze_; }





  EbufDispRegsDbgCtrlMutable &dbg_ctrl() { return dbg_ctrl_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      port_mode_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      cred_ctrl_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      chnl_ctrl_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      int_stat_.read( offset, data );
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      if (read_callback_) read_callback_();
      int_en_.read( offset, data );
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      if (read_callback_) read_callback_();
      int_pri_.read( offset, data );
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      if (read_callback_) read_callback_();
      int_inj_.read( offset, data );
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      if (read_callback_) read_callback_();
      ebuf_disp_fifo_avail_.read( offset, data );
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      if (read_callback_) read_callback_();
      int_freeze_.read( offset, data );
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      if (read_callback_) read_callback_();
      dbg_ctrl_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      port_mode_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      cred_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      chnl_ctrl_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      int_stat_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      int_en_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      int_pri_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      int_inj_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      ebuf_disp_fifo_avail_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      int_freeze_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      dbg_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    port_mode_.reset();
    cred_ctrl_.reset();
    for (auto &f0 : chnl_ctrl_) {
      f0.reset();
    }
    int_stat_.reset();
    int_en_.reset();
    int_pri_.reset();
    int_inj_.reset();
    ebuf_disp_fifo_avail_.reset();
    int_freeze_.reset();
    dbg_ctrl_.reset();
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
      r += port_mode_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += cred_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x20) {
      offset -= 0x10;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += chnl_ctrl_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x24) {
      offset -= 0x20;
      r += int_stat_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x24 && offset < 0x28) {
      offset -= 0x24;
      r += int_en_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x28 && offset < 0x2c) {
      offset -= 0x28;
      r += int_pri_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x2c && offset < 0x30) {
      offset -= 0x2c;
      r += int_inj_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x30 && offset < 0x34) {
      offset -= 0x30;
      r += ebuf_disp_fifo_avail_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      r += int_freeze_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      r += dbg_ctrl_.to_string(offset,print_zeros,indent_string) ;
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
    r += port_mode_.to_string(print_zeros,indent_string) ;
    r += cred_ctrl_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<4;++a0) {
      r += chnl_ctrl_[a0].to_string(print_zeros,indent_string) ;
    }
    r += int_stat_.to_string(print_zeros,indent_string) ;
    r += int_en_.to_string(print_zeros,indent_string) ;
    r += int_pri_.to_string(print_zeros,indent_string) ;
    r += int_inj_.to_string(print_zeros,indent_string) ;
    r += ebuf_disp_fifo_avail_.to_string(print_zeros,indent_string) ;
    r += int_freeze_.to_string(print_zeros,indent_string) ;
    r += dbg_ctrl_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  EbufDispRegsPortModeMutable port_mode_;
  EbufDispRegsCredCtrlMutable cred_ctrl_;
  std::array< EbufDispRegsDprsCtrlMutable, 4 > chnl_ctrl_;
  EbufDispRegsIntStatMutable int_stat_;
  EbufDispRegsIntEnMutable int_en_;
  EbufDispRegsIntPriMutable int_pri_;
  EbufDispRegsIntInjMutable int_inj_;
  EbufDispRegsEbufDispFifoAvailMutable ebuf_disp_fifo_avail_;
  EbufDispRegsIntFreezeMutable int_freeze_;
  EbufDispRegsDbgCtrlMutable dbg_ctrl_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_egrNx_regs
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    offset += 0x40000; // to get to ebp18_reg
    offset += 0x30000; // to get to egrNx_reg
    assert(index_egrNx_regs < 18);
    offset += index_egrNx_regs * 0x200; // egrNx_regs[]
    return offset;
  }

};





  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_EBUF_DISP_REGS_MUTABLE_H__
