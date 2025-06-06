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
#ifndef __REGISTER_INCLUDES_TM_CLC_TOP_RSPEC_H__
#define __REGISTER_INCLUDES_TM_CLC_TOP_RSPEC_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "tm_clc_common_rspec.h"
#include "tm_clc_pipe_rspec.h"
#include "tm_pex_pipe_rspec.h"

namespace tofino {
  namespace register_classes {

class TmClcTopRspec : public model_core::RegisterBlock<RegisterCallback> {
public:
  TmClcTopRspec(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 147456, false, write_callback, read_callback, std::string("TmClcTopRspec"))
    {
    }
  TmClcTopRspec(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "TmClcTopRspec")
    {
    }
public:







  TmClcPipeRspec &clc(int j0) { return clc_[j0]; }







  TmPexPipeRspec &pex(int j0) { return pex_[j0]; }





  TmClcCommonRspec &clc_common() { return clc_common_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x10000) {
      offset -= 0x0;
      int i0 = offset / 0x4000;
      offset  -= i0 * 0x4000;
      if (read_callback_) read_callback_();
      clc_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x10000 && offset < 0x20000) {
      offset -= 0x10000;
      int i0 = offset / 0x4000;
      offset  -= i0 * 0x4000;
      if (read_callback_) read_callback_();
      pex_[ i0 ].read( offset, data );
    }
    else if (offset >= 0x20000 && offset < 0x24000) {
      offset -= 0x20000;
      if (read_callback_) read_callback_();
      clc_common_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x10000) {
      offset -= 0x0;
      int i0 = offset / 0x4000;
      offset  -= i0 * 0x4000;
      clc_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x10000 && offset < 0x20000) {
      offset -= 0x10000;
      int i0 = offset / 0x4000;
      offset  -= i0 * 0x4000;
      pex_[ i0 ].write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20000 && offset < 0x24000) {
      offset -= 0x20000;
      clc_common_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    for (auto &f0 : clc_) {
      f0.reset();
    }
    for (auto &f0 : pex_) {
      f0.reset();
    }
    clc_common_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x10000) {
      offset -= 0x0;
      int i0 = offset / 0x4000;
      offset  -= i0 * 0x4000;
      r += clc_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x10000 && offset < 0x20000) {
      offset -= 0x10000;
      int i0 = offset / 0x4000;
      offset  -= i0 * 0x4000;
      r += pex_[ i0 ].to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20000 && offset < 0x24000) {
      offset -= 0x20000;
      r += clc_common_.to_string(offset,print_zeros,indent_string) ;
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
      r += clc_[a0].to_string(print_zeros,indent_string) ;
    }
    for (uint32_t a0=0;a0<4;++a0) {
      r += pex_[a0].to_string(print_zeros,indent_string) ;
    }
    r += clc_common_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< TmClcPipeRspec, 4 > clc_;
  std::array< TmPexPipeRspec, 4 > pex_;
  TmClcCommonRspec clc_common_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0x100000; // to get to tm_clc_top
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_TM_CLC_TOP_RSPEC_H__
