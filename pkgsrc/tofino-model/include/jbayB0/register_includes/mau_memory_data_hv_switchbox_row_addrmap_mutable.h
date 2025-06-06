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
#ifndef __REGISTER_INCLUDES_MAU_MEMORY_DATA_HV_SWITCHBOX_ROW_ADDRMAP_MUTABLE_H__
#define __REGISTER_INCLUDES_MAU_MEMORY_DATA_HV_SWITCHBOX_ROW_ADDRMAP_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "mau_memory_data_hv_switchbox_row_control_addrmap_mutable.h"

namespace jbayB0 {
  namespace register_classes {

class MauMemoryDataHvSwitchboxRowAddrmapMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MauMemoryDataHvSwitchboxRowAddrmapMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_memory_data_hv_switchbox_row_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_memory_data_hv_switchbox_row_addrmap), 64, true, write_callback, read_callback, std::string("MauMemoryDataHvSwitchboxRowAddrmapMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_memory_data_hv_switchbox_row_addrmap))
    {
    }
  MauMemoryDataHvSwitchboxRowAddrmapMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MauMemoryDataHvSwitchboxRowAddrmapMutable")
    {
    }
public:





  MauMemoryDataHvSwitchboxRowControlAddrmapMutable &ctl() { return ctl_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x40) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      ctl_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x40) {
      offset -= 0x0;
      ctl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    ctl_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x40) {
      offset -= 0x0;
      r += ctl_.to_string(offset,print_zeros,indent_string) ;
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
    r += ctl_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  MauMemoryDataHvSwitchboxRowControlAddrmapMutable ctl_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_memory_data_hv_switchbox_row_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    assert(index_mau_memory_data_hv_switchbox_row_addrmap < 8);
    offset += index_mau_memory_data_hv_switchbox_row_addrmap * 0x40; // mau_memory_data_hv_switchbox_row_addrmap[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_MAU_MEMORY_DATA_HV_SWITCHBOX_ROW_ADDRMAP_MUTABLE_H__
