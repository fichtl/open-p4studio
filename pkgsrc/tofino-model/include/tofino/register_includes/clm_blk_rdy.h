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
#ifndef __REGISTER_INCLUDES_CLM_BLK_RDY_H__
#define __REGISTER_INCLUDES_CLM_BLK_RDY_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofino {
  namespace register_classes {

class ClmBlkRdy : public model_core::RegisterBlock<RegisterCallback> {
public:
  ClmBlkRdy(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, false, write_callback, read_callback, std::string("ClmBlkRdy"))
    {
    }
  ClmBlkRdy(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "ClmBlkRdy")
    {
    }
public:




  uint32_t &blk_rdy() { return blk_rdy_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (blk_rdy_ & 0xfffffff);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    blk_rdy_ = (data & 0xfffffff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    blk_rdy_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("ClmBlkRdy") + ":\n";
    r += indent_string + "  " + std::string("blk_rdy") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(blk_rdy_) ) + "\n";
    all_zeros &= (0 == blk_rdy_);
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
    r += indent_string + std::string("ClmBlkRdy") + ":\n";
    r += indent_string + "  " + std::string("blk_rdy") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(blk_rdy_) ) + "\n";
    all_zeros &= (0 == blk_rdy_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t blk_rdy_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0x100000; // to get to tm_clc_top
    offset += 0x20000; // to get to clc_common
    offset += 0x190; // to get to clm_blk_rdy
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_CLM_BLK_RDY_H__
