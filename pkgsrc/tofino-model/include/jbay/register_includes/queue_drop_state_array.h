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
#ifndef __REGISTER_INCLUDES_QUEUE_DROP_STATE_ARRAY_H__
#define __REGISTER_INCLUDES_QUEUE_DROP_STATE_ARRAY_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "queue_drop_state.h"

namespace jbay {
  namespace register_classes {

class QueueDropStateArray : public model_core::RegisterBlock<RegisterArrayCallback> {
public:
  enum PipeBlockRegEnum {
    kQacRegQueueDropRedState,
    kQacRegQueueDropState,
    kQacRegQueueDropYelState
  };
public:
  QueueDropStateArray(
      int chipNumber, int index_tm_qac_pipe_rspec, PipeBlockRegEnum selector_pipe_block_reg, RegisterArrayCallback& write_callback = 0, RegisterArrayCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_qac_pipe_rspec, selector_pipe_block_reg), 4 * ArraySize(index_tm_qac_pipe_rspec, selector_pipe_block_reg, -1), false, write_callback, read_callback, std::string("QueueDropStateArray")+":"+boost::lexical_cast<std::string>(index_tm_qac_pipe_rspec) + "," + boost::lexical_cast<std::string>(selector_pipe_block_reg)),
    array(RealArraySize(index_tm_qac_pipe_rspec, selector_pipe_block_reg, -1)),
    size0_(ArraySize(index_tm_qac_pipe_rspec, selector_pipe_block_reg, 0)),
    real_size0_(RealArraySize(index_tm_qac_pipe_rspec, selector_pipe_block_reg, 0))
    {
    }
public:








  uint32_t &st(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].st();
  }
  bool calculate_index(
      uint32_t* offset, uint32_t* a0
      ) const {
    int i = (*offset)/4;
    (*offset) -= (i*4);
    uint32_t t = i;
    *a0 = t;
    bool in_bounds = true;
    in_bounds &= CheckArrayBounds(*a0,real_size0_,size0_,*offset,0,true);
    return in_bounds;
  }


  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    uint32_t a0;
     if (!calculate_index(&offset,&a0)) return true;
    if (read_callback_) read_callback_(a0);
    array[a0].read(offset,data);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    uint32_t a0;
     if (!calculate_index(&offset,&a0)) return true;
    array[a0].write(offset,data);
    if (write_callback_) write_callback_(a0);
    return true;
  }

  void reset(
      
      ) {
    for (uint32_t i=0;i<array.size();++i) {
      array[i].reset();
      int t = i;
      int a0 = t;
      if (write_callback_) write_callback_(a0);
    }
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    uint32_t a0;
     if (!calculate_index(&offset,&a0)) return "OUT_OF_BOUNDS";
    std::string r_s = array[a0].to_string(print_zeros,indent_string+"  ");
    if (! r_s.empty()) {
      r += indent_string + std::string("QueueDropStateArray") + "["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
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
    for (uint32_t a0=0;a0<real_size0_;++a0) {
      std::string r_s = array[a0].to_string(print_zeros,indent_string+"  ");
      if (! r_s.empty()) {
        r += indent_string + std::string("QueueDropStateArray") + "["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
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
  std::vector<QueueDropState> array;
  uint32_t size0_;
  uint32_t real_size0_;
private:
  static int StartOffset(
      int index_tm_qac_pipe_rspec, PipeBlockRegEnum selector_pipe_block_reg
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x100000; // to get to tm_qac_top
    offset += 0x20000; // to get to qac_pipe
    assert(index_tm_qac_pipe_rspec < 4);
    offset += index_tm_qac_pipe_rspec * 0x8000; // tm_qac_pipe_rspec[]
    switch (selector_pipe_block_reg) {
      case kQacRegQueueDropRedState:
        offset += 0x400; // to get to qac_reg_queue_drop_red_state
        break;
      case kQacRegQueueDropState:
        offset += 0x200; // to get to qac_reg_queue_drop_state
        break;
      case kQacRegQueueDropYelState:
        offset += 0x300; // to get to qac_reg_queue_drop_yel_state
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

  static int ArraySize(
      int index_tm_qac_pipe_rspec, PipeBlockRegEnum selector_pipe_block_reg, int dimension
      ) {
    switch (selector_pipe_block_reg) {
      case kQacRegQueueDropRedState:
        switch (dimension) {
          case -1:
            return 36;
            break;
          case 0:
            return 36;
            break;
          default:
            assert(0);
            break;
        }
        break;
      case kQacRegQueueDropState:
        switch (dimension) {
          case -1:
            return 36;
            break;
          case 0:
            return 36;
            break;
          default:
            assert(0);
            break;
        }
        break;
      case kQacRegQueueDropYelState:
        switch (dimension) {
          case -1:
            return 36;
            break;
          case 0:
            return 36;
            break;
          default:
            assert(0);
            break;
        }
        break;
      default:
        assert(0);
        break;
    }
  }

  static int RealArraySize(
      int index_tm_qac_pipe_rspec, PipeBlockRegEnum selector_pipe_block_reg, int dimension
      ) {
    switch (selector_pipe_block_reg) {
      case kQacRegQueueDropRedState:
        switch (dimension) {
          case -1:
            return 36;
            break;
          case 0:
            return 36;
            break;
          default:
            assert(0);
            break;
        }
        break;
      case kQacRegQueueDropState:
        switch (dimension) {
          case -1:
            return 36;
            break;
          case 0:
            return 36;
            break;
          default:
            assert(0);
            break;
        }
        break;
      case kQacRegQueueDropYelState:
        switch (dimension) {
          case -1:
            return 36;
            break;
          case 0:
            return 36;
            break;
          default:
            assert(0);
            break;
        }
        break;
      default:
        assert(0);
        break;
    }
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_QUEUE_DROP_STATE_ARRAY_H__
