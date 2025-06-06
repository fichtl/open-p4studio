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
#ifndef __REGISTER_INCLUDES_MAU_SELECTOR_ALU_ADDRMAP_MUTABLE_H__
#define __REGISTER_INCLUDES_MAU_SELECTOR_ALU_ADDRMAP_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "intr_enable0_mau_selector_alu_mutable.h"
#include "intr_enable1_mau_selector_alu_mutable.h"
#include "intr_inject_mau_selector_alu_mutable.h"
#include "intr_status_mau_selector_alu_mutable.h"
#include "mau_meter_alu_group_status_ctl_mutable.h"
#include "mau_meter_alu_group_status_mutable.h"
#include "mau_selector_alu_errlog_mutable.h"
#include "selector_alu_ctl_mutable.h"

namespace jbayB0 {
  namespace register_classes {

class MauSelectorAluAddrmapMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MauSelectorAluAddrmapMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_meter_alu_group_addrmap), 32, true, write_callback, read_callback, std::string("MauSelectorAluAddrmapMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_meter_alu_group_addrmap))
    {
    }
  MauSelectorAluAddrmapMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MauSelectorAluAddrmapMutable")
    {
    }
public:





  SelectorAluCtlMutable &selector_alu_ctl() { return selector_alu_ctl_; }






  IntrStatusMauSelectorAluMutable &intr_status_mau_selector_alu() { return intr_status_mau_selector_alu_; }






  IntrEnable0MauSelectorAluMutable &intr_enable0_mau_selector_alu() { return intr_enable0_mau_selector_alu_; }






  IntrEnable1MauSelectorAluMutable &intr_enable1_mau_selector_alu() { return intr_enable1_mau_selector_alu_; }







  IntrInjectMauSelectorAluMutable &intr_inject_mau_selector_alu() { return intr_inject_mau_selector_alu_; }





  MauSelectorAluErrlogMutable &mau_selector_alu_errlog() { return mau_selector_alu_errlog_; }









  MauMeterAluGroupStatusMutable &mau_meter_alu_group_status() { return mau_meter_alu_group_status_; }





  MauMeterAluGroupStatusCtlMutable &mau_meter_alu_group_status_ctl() { return mau_meter_alu_group_status_ctl_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      selector_alu_ctl_.read( offset, data );
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      if (read_callback_) read_callback_();
      intr_status_mau_selector_alu_.read( offset, data );
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      if (read_callback_) read_callback_();
      intr_enable0_mau_selector_alu_.read( offset, data );
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      if (read_callback_) read_callback_();
      intr_enable1_mau_selector_alu_.read( offset, data );
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      if (read_callback_) read_callback_();
      intr_inject_mau_selector_alu_.read( offset, data );
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      if (read_callback_) read_callback_();
      mau_selector_alu_errlog_.read( offset, data );
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      if (read_callback_) read_callback_();
      mau_meter_alu_group_status_.read( offset, data );
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      if (read_callback_) read_callback_();
      mau_meter_alu_group_status_ctl_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      selector_alu_ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      intr_status_mau_selector_alu_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      intr_enable0_mau_selector_alu_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      intr_enable1_mau_selector_alu_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      intr_inject_mau_selector_alu_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      mau_selector_alu_errlog_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      mau_meter_alu_group_status_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      mau_meter_alu_group_status_ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    selector_alu_ctl_.reset();
    intr_status_mau_selector_alu_.reset();
    intr_enable0_mau_selector_alu_.reset();
    intr_enable1_mau_selector_alu_.reset();
    intr_inject_mau_selector_alu_.reset();
    mau_selector_alu_errlog_.reset();
    mau_meter_alu_group_status_.reset();
    mau_meter_alu_group_status_ctl_.reset();
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
      r += selector_alu_ctl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4 && offset < 0x8) {
      offset -= 0x4;
      r += intr_status_mau_selector_alu_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x8 && offset < 0xc) {
      offset -= 0x8;
      r += intr_enable0_mau_selector_alu_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc && offset < 0x10) {
      offset -= 0xc;
      r += intr_enable1_mau_selector_alu_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10 && offset < 0x14) {
      offset -= 0x10;
      r += intr_inject_mau_selector_alu_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x14 && offset < 0x18) {
      offset -= 0x14;
      r += mau_selector_alu_errlog_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x18 && offset < 0x1c) {
      offset -= 0x18;
      r += mau_meter_alu_group_status_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x1c && offset < 0x20) {
      offset -= 0x1c;
      r += mau_meter_alu_group_status_ctl_.to_string(offset,print_zeros,indent_string) ;
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
    r += selector_alu_ctl_.to_string(print_zeros,indent_string) ;
    r += intr_status_mau_selector_alu_.to_string(print_zeros,indent_string) ;
    r += intr_enable0_mau_selector_alu_.to_string(print_zeros,indent_string) ;
    r += intr_enable1_mau_selector_alu_.to_string(print_zeros,indent_string) ;
    r += intr_inject_mau_selector_alu_.to_string(print_zeros,indent_string) ;
    r += mau_selector_alu_errlog_.to_string(print_zeros,indent_string) ;
    r += mau_meter_alu_group_status_.to_string(print_zeros,indent_string) ;
    r += mau_meter_alu_group_status_ctl_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  SelectorAluCtlMutable selector_alu_ctl_;
  IntrStatusMauSelectorAluMutable intr_status_mau_selector_alu_;
  IntrEnable0MauSelectorAluMutable intr_enable0_mau_selector_alu_;
  IntrEnable1MauSelectorAluMutable intr_enable1_mau_selector_alu_;
  IntrInjectMauSelectorAluMutable intr_inject_mau_selector_alu_;
  MauSelectorAluErrlogMutable mau_selector_alu_errlog_;
  MauMeterAluGroupStatusMutable mau_meter_alu_group_status_;
  MauMeterAluGroupStatusCtlMutable mau_meter_alu_group_status_ctl_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    offset += 0x10000; // to get to map_alu
    offset += 0x3000; // to get to meter_group
    assert(index_mau_meter_alu_group_addrmap < 4);
    offset += index_mau_meter_alu_group_addrmap * 0x400; // mau_meter_alu_group_addrmap[]
    offset += 0x20; // to get to selector
    return offset;
  }

};













  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MAU_SELECTOR_ALU_ADDRMAP_MUTABLE_H__
