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
#ifndef __REGISTER_INCLUDES_WAC_COMMON_BLOCK_DROP_ST_H__
#define __REGISTER_INCLUDES_WAC_COMMON_BLOCK_DROP_ST_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "wac_ap_drop_state_cell.h"

namespace jbayB0 {
  namespace register_classes {

class WacCommonBlockDropSt : public model_core::RegisterBlock<RegisterCallback> {
public:
  WacCommonBlockDropSt(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 16, false, write_callback, read_callback, std::string("WacCommonBlockDropSt"))
    {
    }
  WacCommonBlockDropSt(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "WacCommonBlockDropSt")
    {
    }
public:







  WacApDropStateCell &wac_common_block_drop_st_drop_state_cell(int j0) { return wac_common_block_drop_st_drop_state_cell_[j0]; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x210 && offset < 0x220) {
      offset -= 0x210;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      if (read_callback_) read_callback_();
      wac_common_block_drop_st_drop_state_cell_[ i0 ].read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x210 && offset < 0x220) {
      offset -= 0x210;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      wac_common_block_drop_st_drop_state_cell_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    for (auto &f0 : wac_common_block_drop_st_drop_state_cell_) {
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
    if (offset >= 0x210 && offset < 0x220) {
      offset -= 0x210;
      int i0 = offset / 0x4;
      offset  -= i0 * 0x4;
      r += wac_common_block_drop_st_drop_state_cell_[ i0 ].to_string(offset,print_zeros,indent_string) ;
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
    for (uint32_t a0=0;a0<4;++a0) {
      r += wac_common_block_drop_st_drop_state_cell_[a0].to_string(print_zeros,indent_string) ;
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< WacApDropStateCell, 4 > wac_common_block_drop_st_drop_state_cell_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x20000; // to get to wac_common
    return offset;
  }

};





  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_WAC_COMMON_BLOCK_DROP_ST_H__
