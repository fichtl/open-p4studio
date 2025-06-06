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
#ifndef __REGISTER_INCLUDES_MATCH_TO_LOGICAL_TABLE_IXBAR_OUTPUTMAP_ARRAY2_H__
#define __REGISTER_INCLUDES_MATCH_TO_LOGICAL_TABLE_IXBAR_OUTPUTMAP_ARRAY2_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "match_to_logical_table_ixbar_outputmap.h"

namespace jbay {
  namespace register_classes {

class MatchToLogicalTableIxbarOutputmapArray2 : public model_core::RegisterBlock<RegisterArrayCallback2> {
public:
  MatchToLogicalTableIxbarOutputmapArray2(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, RegisterArrayCallback2& write_callback = 0, RegisterArrayCallback2& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap), 4 * ArraySize(index_pipe_addrmap, index_mau_addrmap, -1), false, write_callback, read_callback, std::string("MatchToLogicalTableIxbarOutputmapArray2")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap)),
    array(RealArraySize(index_pipe_addrmap, index_mau_addrmap, -1)),
    size0_(ArraySize(index_pipe_addrmap, index_mau_addrmap, 0)),
    real_size0_(RealArraySize(index_pipe_addrmap, index_mau_addrmap, 0)),
    size1_(ArraySize(index_pipe_addrmap, index_mau_addrmap, 1)),
    real_size1_(RealArraySize(index_pipe_addrmap, index_mau_addrmap, 1))
    {
    }
public:
  uint8_t &enabled_4bit_muxctl_select(uint32_t a1,uint32_t a0)
  {
    CheckArrayBounds(a1,real_size1_,size1_,0,1,false);
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[(a1 * real_size0_) + a0].enabled_4bit_muxctl_select();
  }
  uint8_t &enabled_4bit_muxctl_enable(uint32_t a1,uint32_t a0)
  {
    CheckArrayBounds(a1,real_size1_,size1_,0,1,false);
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[(a1 * real_size0_) + a0].enabled_4bit_muxctl_enable();
  }
  bool calculate_index(
      uint32_t* offset, uint32_t* a1, uint32_t* a0
      ) const {
    int i = (*offset)/4;
    (*offset) -= (i*4);
    uint32_t t = i;
    *a1 = t / size0_;
    t -= ((*a1)*size0_);
    *a0 = t;
    bool in_bounds = true;
    in_bounds &= CheckArrayBounds(*a1,real_size1_,size1_,*offset,1,true);
    in_bounds &= CheckArrayBounds(*a0,real_size0_,size0_,*offset,0,true);
    return in_bounds;
  }


  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    uint32_t a1,a0;
     if (!calculate_index(&offset,&a1,&a0)) return true;
    if (read_callback_) read_callback_(a1,a0);
    array[(a1 * real_size0_) + a0].read(offset,data);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    uint32_t a1,a0;
     if (!calculate_index(&offset,&a1,&a0)) return true;
    array[(a1 * real_size0_) + a0].write(offset,data);
    if (write_callback_) write_callback_(a1,a0);
    return true;
  }

  void reset(
      
      ) {
    for (uint32_t i=0;i<array.size();++i) {
      array[i].reset();
      int t = i;
      int a1 = t / real_size0_;
      t -= (a1*real_size0_);
      int a0 = t;
      if (write_callback_) write_callback_(a1,a0);
    }
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    uint32_t a1,a0;
     if (!calculate_index(&offset,&a1,&a0)) return "OUT_OF_BOUNDS";
    std::string r_s = array[(a1 * real_size0_) + a0].to_string(print_zeros,indent_string+"  ");
    if (! r_s.empty()) {
      r += indent_string + std::string("MatchToLogicalTableIxbarOutputmapArray2") + "["+boost::lexical_cast<std::string>(a1)+"]"+"["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
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
    for (uint32_t a1=0;a1<real_size1_;++a1) {
      for (uint32_t a0=0;a0<real_size0_;++a0) {
        std::string r_s = array[(a1 * real_size0_) + a0].to_string(print_zeros,indent_string+"  ");
        if (! r_s.empty()) {
          r += indent_string + std::string("MatchToLogicalTableIxbarOutputmapArray2") + "["+boost::lexical_cast<std::string>(a1)+"]"+"["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
        }
      }
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::vector<MatchToLogicalTableIxbarOutputmap> array;
  uint32_t size0_;
  uint32_t real_size0_;
  uint32_t size1_;
  uint32_t real_size1_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    assert(index_mau_addrmap < 20);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x60000; // to get to rams
    offset += 0x18000; // to get to match
    offset += 0x4000; // to get to merge
    offset += 0x2800; // to get to match_to_logical_table_ixbar_outputmap
    return offset;
  }

  static int ArraySize(
      int index_pipe_addrmap, int index_mau_addrmap, int dimension
      ) {
    switch (dimension) {
      case -1:
        return 16 * 4;
        break;
      case 0:
        return 16;
        break;
      case 1:
        return 4;
        break;
      default:
        assert(0);
        break;
    }
  }

  static int RealArraySize(
      int index_pipe_addrmap, int index_mau_addrmap, int dimension
      ) {
    switch (dimension) {
      case -1:
        return 16 * 4;
        break;
      case 0:
        return 16;
        break;
      case 1:
        return 4;
        break;
      default:
        assert(0);
        break;
    }
  }

};





























  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_MATCH_TO_LOGICAL_TABLE_IXBAR_OUTPUTMAP_ARRAY2_H__
