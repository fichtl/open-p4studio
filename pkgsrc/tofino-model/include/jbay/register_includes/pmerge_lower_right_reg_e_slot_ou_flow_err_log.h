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
#ifndef __REGISTER_INCLUDES_PMERGE_LOWER_RIGHT_REG_E_SLOT_OU_FLOW_ERR_LOG_H__
#define __REGISTER_INCLUDES_PMERGE_LOWER_RIGHT_REG_E_SLOT_OU_FLOW_ERR_LOG_H__


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

class PmergeLowerRightRegESlotOuFlowErrLog : public model_core::RegisterBlock<RegisterCallback> {
public:
  PmergeLowerRightRegESlotOuFlowErrLog(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("PmergeLowerRightRegESlotOuFlowErrLog")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PmergeLowerRightRegESlotOuFlowErrLog(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PmergeLowerRightRegESlotOuFlowErrLog")
    {
    }
public:
  uint8_t &mac() { return mac_; }
  uint8_t &prsr() { return prsr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (mac_ & 0xf);
    *data |= ((prsr_ & 0x3) << 4);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    mac_ = (data & 0xf);
    prsr_ = ((data >> 4) & 0x3);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    mac_ = 0x0;
    prsr_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PmergeLowerRightRegESlotOuFlowErrLog") + ":\n";
    r += indent_string + "  " + std::string("mac") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac_) ) + "\n";
    all_zeros &= (0 == mac_);
    r += indent_string + "  " + std::string("prsr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_) ) + "\n";
    all_zeros &= (0 == prsr_);
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
    r += indent_string + std::string("PmergeLowerRightRegESlotOuFlowErrLog") + ":\n";
    r += indent_string + "  " + std::string("mac") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mac_) ) + "\n";
    all_zeros &= (0 == mac_);
    r += indent_string + "  " + std::string("prsr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(prsr_) ) + "\n";
    all_zeros &= (0 == prsr_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t mac_;
  uint8_t prsr_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x12000; // to get to pmergereg
    offset += 0x1000; // to get to lr0
    offset += 0x78; // to get to e_slot_ou_flow_err_log
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PMERGE_LOWER_RIGHT_REG_E_SLOT_OU_FLOW_ERR_LOG_H__
