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
#ifndef __REGISTER_INCLUDES_CBUS_LINK_DOWN_H__
#define __REGISTER_INCLUDES_CBUS_LINK_DOWN_H__


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

class CbusLinkDown : public model_core::RegisterBlock<RegisterCallback> {
public:
  CbusLinkDown(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, false, write_callback, read_callback, std::string("CbusLinkDown"))
    {
    }
  CbusLinkDown(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "CbusLinkDown")
    {
    }
public:






  uint8_t &link_down() { return link_down_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (link_down_ & 0x1);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    link_down_ &= ~(data & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    link_down_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("CbusLinkDown") + ":\n";
    r += indent_string + "  " + std::string("link_down") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(link_down_) ) + "\n";
    all_zeros &= (0 == link_down_);
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
    r += indent_string + std::string("CbusLinkDown") + ":\n";
    r += indent_string + "  " + std::string("link_down") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(link_down_) ) + "\n";
    all_zeros &= (0 == link_down_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t link_down_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x280000; // to get to cbc
    offset += 0x18; // to get to link_down
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_CBUS_LINK_DOWN_H__
