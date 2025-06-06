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
#ifndef __REGISTER_INCLUDES_TM_PEX_COMMON_RSPEC_MUTABLE_H__
#define __REGISTER_INCLUDES_TM_PEX_COMMON_RSPEC_MUTABLE_H__


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

class TmPexCommonRspecMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  TmPexCommonRspecMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 16384, true, write_callback, read_callback, std::string("TmPexCommonRspecMutable"))
    {
    }
  TmPexCommonRspecMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "TmPexCommonRspecMutable")
    {
    }
public:

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    return true;
  }

  void reset(
      
      ) {
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
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
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x300000; // to get to tm_pex_top
    offset += 0x20000; // to get to pex_common
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_TM_PEX_COMMON_RSPEC_MUTABLE_H__
