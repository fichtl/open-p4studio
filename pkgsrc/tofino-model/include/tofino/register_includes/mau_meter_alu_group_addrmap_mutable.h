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
#ifndef __REGISTER_INCLUDES_MAU_METER_ALU_GROUP_ADDRMAP_MUTABLE_H__
#define __REGISTER_INCLUDES_MAU_METER_ALU_GROUP_ADDRMAP_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "mau_meter_alu_addrmap_mutable.h"
#include "mau_selector_alu_addrmap_mutable.h"
#include "mau_stateful_alu_addrmap_mutable.h"

namespace tofino {
  namespace register_classes {

class MauMeterAluGroupAddrmapMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MauMeterAluGroupAddrmapMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_meter_alu_group_addrmap), 512, true, write_callback, read_callback, std::string("MauMeterAluGroupAddrmapMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_meter_alu_group_addrmap))
    {
    }
  MauMeterAluGroupAddrmapMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MauMeterAluGroupAddrmapMutable")
    {
    }
public:





  MauMeterAluAddrmapMutable &meter() { return meter_; }





  MauSelectorAluAddrmapMutable &selector() { return selector_; }





  MauStatefulAluAddrmapMutable &stateful() { return stateful_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x8) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      meter_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x40) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      selector_.read( offset, data );
    }
    else if (offset >= 0x100 && offset < 0x200) {
      offset -= 0x100;
      if (read_callback_) read_callback_();
      stateful_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x8) {
      offset -= 0x0;
      meter_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x40) {
      offset -= 0x20;
      selector_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x100 && offset < 0x200) {
      offset -= 0x100;
      stateful_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    meter_.reset();
    selector_.reset();
    stateful_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x8) {
      offset -= 0x0;
      r += meter_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x40) {
      offset -= 0x20;
      r += selector_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x100 && offset < 0x200) {
      offset -= 0x100;
      r += stateful_.to_string(offset,print_zeros,indent_string) ;
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
    r += meter_.to_string(print_zeros,indent_string) ;
    r += selector_.to_string(print_zeros,indent_string) ;
    r += stateful_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  MauMeterAluAddrmapMutable meter_;
  MauSelectorAluAddrmapMutable selector_;
  MauStatefulAluAddrmapMutable stateful_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_meter_alu_group_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x10000; // to get to map_alu
    offset += 0x800; // to get to meter_group
    assert(index_mau_meter_alu_group_addrmap < 4);
    offset += index_mau_meter_alu_group_addrmap * 0x200; // mau_meter_alu_group_addrmap[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_MAU_METER_ALU_GROUP_ADDRMAP_MUTABLE_H__
