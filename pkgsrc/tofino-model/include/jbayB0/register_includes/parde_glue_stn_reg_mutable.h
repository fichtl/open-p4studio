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
#ifndef __REGISTER_INCLUDES_PARDE_GLUE_STN_REG_MUTABLE_H__
#define __REGISTER_INCLUDES_PARDE_GLUE_STN_REG_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "ebuf900_reg_mutable.h"
#include "epb_prsr4_reg_mutable.h"
#include "ipb_prsr4_reg_mutable.h"
#include "p2s_reg_mutable.h"
#include "parb_reg_mutable.h"
#include "parde_glue_reg_rspec_mutable.h"
#include "pbus_station_regs_rspec_mutable.h"
#include "pgr_reg_rspec_mutable.h"
#include "pmerge_reg_mutable.h"
#include "s2p_reg_mutable.h"

namespace jbayB0 {
  namespace register_classes {

class PardeGlueStnRegMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PardeGlueStnRegMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 524288, true, write_callback, read_callback, std::string("PardeGlueStnRegMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PardeGlueStnRegMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PardeGlueStnRegMutable")
    {
    }
public:







  IpbPrsr4RegMutable &ipbprsr4reg(int j0) { return ipbprsr4reg_[j0]; }






  PmergeRegMutable &pmergereg() { return pmergereg_; }





  ParbRegMutable &parbreg() { return parbreg_; }





  S2pRegMutable &s2preg() { return s2preg_; }





  P2sRegMutable &p2sreg() { return p2sreg_; }





  PardeGlueRegRspecMutable &pgluereg() { return pgluereg_; }







  EpbPrsr4RegMutable &epbprsr4reg(int j0) { return epbprsr4reg_[j0]; }





  PbusStationRegsRspecMutable &pbusreg() { return pbusreg_; }





  PgrRegRspecMutable &pgrreg() { return pgrreg_; }







  Ebuf900RegMutable &ebuf900reg(int j0) { return ebuf900reg_[j0]; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x12000) {
      offset -= 0x0;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      if (read_callback_) read_callback_();
      ipbprsr4reg_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x12000 && offset < 0x14000) {
      offset -= 0x12000;
      if (read_callback_) read_callback_();
      pmergereg_.read( offset, data );
    }
    else if (offset >= 0x14000 && offset < 0x14f74) {
      offset -= 0x14000;
      if (read_callback_) read_callback_();
      parbreg_.read( offset, data );
    }
    else if (offset >= 0x1a000 && offset < 0x1ab78) {
      offset -= 0x1a000;
      if (read_callback_) read_callback_();
      s2preg_.read( offset, data );
    }
    else if (offset >= 0x1c000 && offset < 0x1cbc8) {
      offset -= 0x1c000;
      if (read_callback_) read_callback_();
      p2sreg_.read( offset, data );
    }
    else if (offset >= 0x1e000 && offset < 0x1e100) {
      offset -= 0x1e000;
      if (read_callback_) read_callback_();
      pgluereg_.read( offset, data );
    }
    else if (offset >= 0x20000 && offset < 0x32000) {
      offset -= 0x20000;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      if (read_callback_) read_callback_();
      epbprsr4reg_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x32000 && offset < 0x32028) {
      offset -= 0x32000;
      if (read_callback_) read_callback_();
      pbusreg_.read( offset, data );
    }
    else if (offset >= 0x34000 && offset < 0x38000) {
      offset -= 0x34000;
      if (read_callback_) read_callback_();
      pgrreg_.read( offset, data );
    }
    else if (offset >= 0x40000 && offset < 0x48000) {
      offset -= 0x40000;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      if (read_callback_) read_callback_();
      ebuf900reg_[ i0 ].read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x12000) {
      offset -= 0x0;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      ipbprsr4reg_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x12000 && offset < 0x14000) {
      offset -= 0x12000;
      pmergereg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14000 && offset < 0x14f74) {
      offset -= 0x14000;
      parbreg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1a000 && offset < 0x1ab78) {
      offset -= 0x1a000;
      s2preg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c000 && offset < 0x1cbc8) {
      offset -= 0x1c000;
      p2sreg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1e000 && offset < 0x1e100) {
      offset -= 0x1e000;
      pgluereg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20000 && offset < 0x32000) {
      offset -= 0x20000;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      epbprsr4reg_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x32000 && offset < 0x32028) {
      offset -= 0x32000;
      pbusreg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x34000 && offset < 0x38000) {
      offset -= 0x34000;
      pgrreg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40000 && offset < 0x48000) {
      offset -= 0x40000;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      ebuf900reg_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    for (auto &f0 : ipbprsr4reg_) {
      f0.reset();
    }
    pmergereg_.reset();
    parbreg_.reset();
    s2preg_.reset();
    p2sreg_.reset();
    pgluereg_.reset();
    for (auto &f0 : epbprsr4reg_) {
      f0.reset();
    }
    pbusreg_.reset();
    pgrreg_.reset();
    for (auto &f0 : ebuf900reg_) {
      f0.reset();
    }
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x12000) {
      offset -= 0x0;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      r += ipbprsr4reg_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x12000 && offset < 0x14000) {
      offset -= 0x12000;
      r += pmergereg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14000 && offset < 0x14f74) {
      offset -= 0x14000;
      r += parbreg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1a000 && offset < 0x1ab78) {
      offset -= 0x1a000;
      r += s2preg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c000 && offset < 0x1cbc8) {
      offset -= 0x1c000;
      r += p2sreg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1e000 && offset < 0x1e100) {
      offset -= 0x1e000;
      r += pgluereg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20000 && offset < 0x32000) {
      offset -= 0x20000;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      r += epbprsr4reg_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x32000 && offset < 0x32028) {
      offset -= 0x32000;
      r += pbusreg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x34000 && offset < 0x38000) {
      offset -= 0x34000;
      r += pgrreg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40000 && offset < 0x48000) {
      offset -= 0x40000;
      int i0 = offset / 0x2000;
      offset  -= i0 * 0x2000;
      r += ebuf900reg_[ i0 ].to_string(offset,print_zeros,indent_string) ;
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
    for (uint32_t a0=0;a0<9;++a0) {
      r += ipbprsr4reg_[a0].to_string(print_zeros,indent_string) ;
    }
    r += pmergereg_.to_string(print_zeros,indent_string) ;
    r += parbreg_.to_string(print_zeros,indent_string) ;
    r += s2preg_.to_string(print_zeros,indent_string) ;
    r += p2sreg_.to_string(print_zeros,indent_string) ;
    r += pgluereg_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<9;++a0) {
      r += epbprsr4reg_[a0].to_string(print_zeros,indent_string) ;
    }
    r += pbusreg_.to_string(print_zeros,indent_string) ;
    r += pgrreg_.to_string(print_zeros,indent_string) ;
    for (uint32_t a0=0;a0<4;++a0) {
      r += ebuf900reg_[a0].to_string(print_zeros,indent_string) ;
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< IpbPrsr4RegMutable, 9 > ipbprsr4reg_;
  PmergeRegMutable pmergereg_;
  ParbRegMutable parbreg_;
  S2pRegMutable s2preg_;
  P2sRegMutable p2sreg_;
  PardeGlueRegRspecMutable pgluereg_;
  std::array< EpbPrsr4RegMutable, 9 > epbprsr4reg_;
  PbusStationRegsRspecMutable pbusreg_;
  PgrRegRspecMutable pgrreg_;
  std::array< Ebuf900RegMutable, 4 > ebuf900reg_;
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
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PARDE_GLUE_STN_REG_MUTABLE_H__
