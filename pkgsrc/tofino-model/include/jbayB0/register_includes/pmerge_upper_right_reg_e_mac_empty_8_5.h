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
#ifndef __REGISTER_INCLUDES_PMERGE_UPPER_RIGHT_REG_E_MAC_EMPTY_8_5_H__
#define __REGISTER_INCLUDES_PMERGE_UPPER_RIGHT_REG_E_MAC_EMPTY_8_5_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbayB0 {
  namespace register_classes {

class PmergeUpperRightRegEMacEmpty_8_5 : public model_core::RegisterBlock<RegisterCallback> {
public:
  PmergeUpperRightRegEMacEmpty_8_5(
      int chipNumber, int index_pipe_addrmap, int index_pmerge_upper_right_reg_e_mac_empty_8_5, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_pmerge_upper_right_reg_e_mac_empty_8_5), 4, false, write_callback, read_callback, std::string("PmergeUpperRightRegEMacEmpty_8_5")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_pmerge_upper_right_reg_e_mac_empty_8_5))
    {
    }
  PmergeUpperRightRegEMacEmpty_8_5(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PmergeUpperRightRegEMacEmpty_8_5")
    {
    }
public:



  uint8_t &chan(int j0) { return chan_[j0]; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (chan_[0] & 0x1);
    *data |= ((chan_[1] & 0x1) << 1);
    *data |= ((chan_[2] & 0x1) << 2);
    *data |= ((chan_[3] & 0x1) << 3);
    *data |= ((chan_[4] & 0x1) << 4);
    *data |= ((chan_[5] & 0x1) << 5);
    *data |= ((chan_[6] & 0x1) << 6);
    *data |= ((chan_[7] & 0x1) << 7);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    chan_[0] = (data & 0x1);
    chan_[1] = ((data >> 1) & 0x1);
    chan_[2] = ((data >> 2) & 0x1);
    chan_[3] = ((data >> 3) & 0x1);
    chan_[4] = ((data >> 4) & 0x1);
    chan_[5] = ((data >> 5) & 0x1);
    chan_[6] = ((data >> 6) & 0x1);
    chan_[7] = ((data >> 7) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    chan_[0] = 0;
    chan_[1] = 0;
    chan_[2] = 0;
    chan_[3] = 0;
    chan_[4] = 0;
    chan_[5] = 0;
    chan_[6] = 0;
    chan_[7] = 0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PmergeUpperRightRegEMacEmpty_8_5") + ":\n";
    for (uint32_t f=0;f<8;++f) {
      r += indent_string + "  " + std::string("chan") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(chan_[f]) ) + "\n";
      all_zeros &= (0 == chan_[f]);
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
    r += indent_string + std::string("PmergeUpperRightRegEMacEmpty_8_5") + ":\n";
    for (uint32_t f=0;f<8;++f) {
      r += indent_string + "  " + std::string("chan") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(chan_[f]) ) + "\n";
      all_zeros &= (0 == chan_[f]);
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< uint8_t, 8 > chan_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_pmerge_upper_right_reg_e_mac_empty_8_5
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x12000; // to get to pmergereg
    offset += 0x1200; // to get to ur
    offset += 0x40; // to get to e_mac_empty_8_5
    assert(index_pmerge_upper_right_reg_e_mac_empty_8_5 < 4);
    offset += index_pmerge_upper_right_reg_e_mac_empty_8_5 * 0x4; // pmerge_upper_right_reg_e_mac_empty_8_5[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PMERGE_UPPER_RIGHT_REG_E_MAC_EMPTY_8_5_H__
