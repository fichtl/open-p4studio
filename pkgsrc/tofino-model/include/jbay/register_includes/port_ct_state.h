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
#ifndef __REGISTER_INCLUDES_PORT_CT_STATE_H__
#define __REGISTER_INCLUDES_PORT_CT_STATE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbay {
  namespace register_classes {

class PortCtState : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum TmClcPipeRspecEnum {
    kEgressPortCtState,
    kIngressPortCtState
  };
public:
  PortCtState(
      int chipNumber, int index_tm_clc_pipe_rspec, TmClcPipeRspecEnum selector_tm_clc_pipe_rspec, int index_port_ct_state, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_clc_pipe_rspec, selector_tm_clc_pipe_rspec, index_port_ct_state), 4, false, write_callback, read_callback, std::string("PortCtState")+":"+boost::lexical_cast<std::string>(index_tm_clc_pipe_rspec) + "," + boost::lexical_cast<std::string>(selector_tm_clc_pipe_rspec) + "," + boost::lexical_cast<std::string>(index_port_ct_state))
    {
    }
  PortCtState(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PortCtState")
    {
    }
public:




  uint32_t &ct_state() { return ct_state_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = ct_state_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    ct_state_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    ct_state_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PortCtState") + ":\n";
    r += indent_string + "  " + std::string("ct_state") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_state_) ) + "\n";
    all_zeros &= (0 == ct_state_);
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
    r += indent_string + std::string("PortCtState") + ":\n";
    r += indent_string + "  " + std::string("ct_state") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ct_state_) ) + "\n";
    all_zeros &= (0 == ct_state_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t ct_state_;
private:
  static int StartOffset(
      int index_tm_clc_pipe_rspec, TmClcPipeRspecEnum selector_tm_clc_pipe_rspec, int index_port_ct_state
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x280000; // to get to tm_clc_top
    assert(index_tm_clc_pipe_rspec < 4);
    offset += index_tm_clc_pipe_rspec * 0x4000; // tm_clc_pipe_rspec[]
    switch (selector_tm_clc_pipe_rspec) {
      case kEgressPortCtState:
        offset += 0x340; // to get to egress_port_ct_state
        assert(index_port_ct_state < 3);
        offset += index_port_ct_state * 0x4; // port_ct_state[]
        break;
      case kIngressPortCtState:
        offset += 0x330; // to get to ingress_port_ct_state
        assert(index_port_ct_state < 3);
        offset += index_port_ct_state * 0x4; // port_ct_state[]
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PORT_CT_STATE_H__
