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
#ifndef __REGISTER_INCLUDES_SERDES_ADDRMAP_H__
#define __REGISTER_INCLUDES_SERDES_ADDRMAP_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "serdes_addrmap_dummy_register.h"

namespace tofinoB0 {
  namespace register_classes {

class SerdesAddrmap : public model_core::RegisterBlock<RegisterCallback> {
public:
  SerdesAddrmap(
      int chipNumber, int index_serdes_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_serdes_addrmap), 4, false, write_callback, read_callback, std::string("SerdesAddrmap")+":"+boost::lexical_cast<std::string>(index_serdes_addrmap))
    {
    }
  SerdesAddrmap(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "SerdesAddrmap")
    {
    }
public:
  SerdesAddrmapDummyRegister &dummy_register() { return dummy_register_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      dummy_register_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      offset -= 0x0;
      dummy_register_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    dummy_register_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x4) {
      offset -= 0x0;
      r += dummy_register_.to_string(offset,print_zeros,indent_string) ;
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
    r += dummy_register_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  SerdesAddrmapDummyRegister dummy_register_;
private:
  static int StartOffset(
      int index_serdes_addrmap
      ) {
    int offset=0;
    offset += 0x800000; // to get to serdes
    assert(index_serdes_addrmap < 2);
    offset += index_serdes_addrmap * 0x400000; // serdes_addrmap[]
    return offset;
  }

};








  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_SERDES_ADDRMAP_H__
