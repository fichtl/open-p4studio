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
#ifndef __REGISTER_INCLUDES_IPB_RSPEC_MUTABLE_H__
#define __REGISTER_INCLUDES_IPB_RSPEC_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "glb_group_mutable.h"
#include "ipb_rspec_chan0_group_mutable.h"
#include "ipb_rspec_chan1_group_mutable.h"
#include "ipb_rspec_chan2_group_mutable.h"
#include "ipb_rspec_chan3_group_mutable.h"
#include "ipb_rspec_chan4_group_mutable.h"
#include "ipb_rspec_chan5_group_mutable.h"
#include "ipb_rspec_chan6_group_mutable.h"
#include "ipb_rspec_chan7_group_mutable.h"
#include "ipb_rspec_debug_bus_ctrl_mutable.h"

namespace jbay {
  namespace register_classes {

class IpbRspecMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  IpbRspecMutable(
      int chipNumber, int index_pipe_addrmap, int index_ipb_prsr4_reg, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_ipb_prsr4_reg), 4096, true, write_callback, read_callback, std::string("IpbRspecMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_ipb_prsr4_reg))
    {
    }
  IpbRspecMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "IpbRspecMutable")
    {
    }
public:





  IpbRspecDebugBusCtrlMutable &debug_bus_ctrl() { return debug_bus_ctrl_; }





  GlbGroupMutable &glb_group() { return glb_group_; }





  IpbRspecChan0GroupMutable &chan0_group() { return chan0_group_; }





  IpbRspecChan1GroupMutable &chan1_group() { return chan1_group_; }





  IpbRspecChan2GroupMutable &chan2_group() { return chan2_group_; }





  IpbRspecChan3GroupMutable &chan3_group() { return chan3_group_; }





  IpbRspecChan4GroupMutable &chan4_group() { return chan4_group_; }





  IpbRspecChan5GroupMutable &chan5_group() { return chan5_group_; }





  IpbRspecChan6GroupMutable &chan6_group() { return chan6_group_; }





  IpbRspecChan7GroupMutable &chan7_group() { return chan7_group_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0xfd8 && offset < 0xfdc) {
      offset -= 0xfd8;
      if (read_callback_) read_callback_();
      debug_bus_ctrl_.read( offset, data );
    }
    else if (offset < 0x1e4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      glb_group_.read( offset, data );
    }
    else if (offset >= 0x800 && offset < 0x8d8) {
      offset -= 0x800;
      if (read_callback_) read_callback_();
      chan0_group_.read( offset, data );
    }
    else if (offset >= 0x900 && offset < 0x9d8) {
      offset -= 0x900;
      if (read_callback_) read_callback_();
      chan1_group_.read( offset, data );
    }
    else if (offset >= 0xa00 && offset < 0xad8) {
      offset -= 0xa00;
      if (read_callback_) read_callback_();
      chan2_group_.read( offset, data );
    }
    else if (offset >= 0xb00 && offset < 0xbd8) {
      offset -= 0xb00;
      if (read_callback_) read_callback_();
      chan3_group_.read( offset, data );
    }
    else if (offset >= 0xc00 && offset < 0xcd8) {
      offset -= 0xc00;
      if (read_callback_) read_callback_();
      chan4_group_.read( offset, data );
    }
    else if (offset >= 0xd00 && offset < 0xdd8) {
      offset -= 0xd00;
      if (read_callback_) read_callback_();
      chan5_group_.read( offset, data );
    }
    else if (offset >= 0xe00 && offset < 0xed8) {
      offset -= 0xe00;
      if (read_callback_) read_callback_();
      chan6_group_.read( offset, data );
    }
    else if (offset >= 0xf00 && offset < 0xfd8) {
      offset -= 0xf00;
      if (read_callback_) read_callback_();
      chan7_group_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0xfd8 && offset < 0xfdc) {
      offset -= 0xfd8;
      debug_bus_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset < 0x1e4) {
      offset -= 0x0;
      glb_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x800 && offset < 0x8d8) {
      offset -= 0x800;
      chan0_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x900 && offset < 0x9d8) {
      offset -= 0x900;
      chan1_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa00 && offset < 0xad8) {
      offset -= 0xa00;
      chan2_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb00 && offset < 0xbd8) {
      offset -= 0xb00;
      chan3_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc00 && offset < 0xcd8) {
      offset -= 0xc00;
      chan4_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xd00 && offset < 0xdd8) {
      offset -= 0xd00;
      chan5_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xe00 && offset < 0xed8) {
      offset -= 0xe00;
      chan6_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xf00 && offset < 0xfd8) {
      offset -= 0xf00;
      chan7_group_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    debug_bus_ctrl_.reset();
    glb_group_.reset();
    chan0_group_.reset();
    chan1_group_.reset();
    chan2_group_.reset();
    chan3_group_.reset();
    chan4_group_.reset();
    chan5_group_.reset();
    chan6_group_.reset();
    chan7_group_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0xfd8 && offset < 0xfdc) {
      offset -= 0xfd8;
      r += debug_bus_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset < 0x1e4) {
      offset -= 0x0;
      r += glb_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x800 && offset < 0x8d8) {
      offset -= 0x800;
      r += chan0_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x900 && offset < 0x9d8) {
      offset -= 0x900;
      r += chan1_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa00 && offset < 0xad8) {
      offset -= 0xa00;
      r += chan2_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb00 && offset < 0xbd8) {
      offset -= 0xb00;
      r += chan3_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc00 && offset < 0xcd8) {
      offset -= 0xc00;
      r += chan4_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xd00 && offset < 0xdd8) {
      offset -= 0xd00;
      r += chan5_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xe00 && offset < 0xed8) {
      offset -= 0xe00;
      r += chan6_group_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xf00 && offset < 0xfd8) {
      offset -= 0xf00;
      r += chan7_group_.to_string(offset,print_zeros,indent_string) ;
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
    r += debug_bus_ctrl_.to_string(print_zeros,indent_string) ;
    r += glb_group_.to_string(print_zeros,indent_string) ;
    r += chan0_group_.to_string(print_zeros,indent_string) ;
    r += chan1_group_.to_string(print_zeros,indent_string) ;
    r += chan2_group_.to_string(print_zeros,indent_string) ;
    r += chan3_group_.to_string(print_zeros,indent_string) ;
    r += chan4_group_.to_string(print_zeros,indent_string) ;
    r += chan5_group_.to_string(print_zeros,indent_string) ;
    r += chan6_group_.to_string(print_zeros,indent_string) ;
    r += chan7_group_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  IpbRspecDebugBusCtrlMutable debug_bus_ctrl_;
  GlbGroupMutable glb_group_;
  IpbRspecChan0GroupMutable chan0_group_;
  IpbRspecChan1GroupMutable chan1_group_;
  IpbRspecChan2GroupMutable chan2_group_;
  IpbRspecChan3GroupMutable chan3_group_;
  IpbRspecChan4GroupMutable chan4_group_;
  IpbRspecChan5GroupMutable chan5_group_;
  IpbRspecChan6GroupMutable chan6_group_;
  IpbRspecChan7GroupMutable chan7_group_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_ipb_prsr4_reg
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    assert(index_ipb_prsr4_reg < 9);
    offset += index_ipb_prsr4_reg * 0x2000; // ipb_prsr4_reg[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_IPB_RSPEC_MUTABLE_H__
