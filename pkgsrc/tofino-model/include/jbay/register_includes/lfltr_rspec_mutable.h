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
#ifndef __REGISTER_INCLUDES_LFLTR_RSPEC_MUTABLE_H__
#define __REGISTER_INCLUDES_LFLTR_RSPEC_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "lfltr_ctrl_rspec_mutable.h"
#include "lfltr_hash_rspec_mutable.h"

namespace jbay {
  namespace register_classes {

class LfltrRspecMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  LfltrRspecMutable(
      int chipNumber, int index_lfltr_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_lfltr_rspec), 524288, true, write_callback, read_callback, std::string("LfltrRspecMutable")+":"+boost::lexical_cast<std::string>(index_lfltr_rspec))
    {
    }
  LfltrRspecMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "LfltrRspecMutable")
    {
    }
public:







  LfltrHashRspecMutable &hash(int j0) { return hash_[j0]; }





  LfltrCtrlRspecMutable &ctrl() { return ctrl_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x20000) {
      offset -= 0x0;
      int i0 = offset / 0x8000;
      offset  -= i0 * 0x8000;
      if (read_callback_) read_callback_();
      hash_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x20000 && offset < 0x28000) {
      offset -= 0x20000;
      if (read_callback_) read_callback_();
      ctrl_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x20000) {
      offset -= 0x0;
      int i0 = offset / 0x8000;
      offset  -= i0 * 0x8000;
      hash_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20000 && offset < 0x28000) {
      offset -= 0x20000;
      ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    for (auto &f0 : hash_) {
      f0.reset();
    }
    ctrl_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x20000) {
      offset -= 0x0;
      int i0 = offset / 0x8000;
      offset  -= i0 * 0x8000;
      r += hash_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20000 && offset < 0x28000) {
      offset -= 0x20000;
      r += ctrl_.to_string(offset,print_zeros,indent_string) ;
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
    for (uint32_t a0=0;a0<4;++a0) {
      r += hash_[a0].to_string(print_zeros,indent_string) ;
    }
    r += ctrl_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< LfltrHashRspecMutable, 4 > hash_;
  LfltrCtrlRspecMutable ctrl_;
private:
  static int StartOffset(
      int index_lfltr_rspec
      ) {
    int offset=0;
    offset += 0x400000; // to get to lfltr
    assert(index_lfltr_rspec < 4);
    offset += index_lfltr_rspec * 0x80000; // lfltr_rspec[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_LFLTR_RSPEC_MUTABLE_H__
