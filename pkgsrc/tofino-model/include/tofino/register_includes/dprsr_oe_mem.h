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
#ifndef __REGISTER_INCLUDES_DPRSR_OE_MEM_H__
#define __REGISTER_INCLUDES_DPRSR_OE_MEM_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "dprsr_h_edf_cfg_map.h"
#include "dprsr_oe_cred_cfg_map.h"

namespace tofino {
  namespace register_classes {

class DprsrOeMem : public model_core::RegisterBlock<RegisterCallback> {
public:
  DprsrOeMem(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 800, false, write_callback, read_callback, std::string("DprsrOeMem")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  DprsrOeMem(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "DprsrOeMem")
    {
    }
public:
  DprsrHEdfCfgMap &edf_cfg() { return edf_cfg_; }





  DprsrOeCredCfgMap &ebuf_cred_cfg() { return ebuf_cred_cfg_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x120) {
      offset -= 0x0;
      if (read_callback_) read_callback_();
      edf_cfg_.read( offset, data );
    }
    else if (offset >= 0x200 && offset < 0x320) {
      offset -= 0x200;
      if (read_callback_) read_callback_();
      ebuf_cred_cfg_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x120) {
      offset -= 0x0;
      edf_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x200 && offset < 0x320) {
      offset -= 0x200;
      ebuf_cred_cfg_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    edf_cfg_.reset();
    ebuf_cred_cfg_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset < 0x120) {
      offset -= 0x0;
      r += edf_cfg_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x200 && offset < 0x320) {
      offset -= 0x200;
      r += ebuf_cred_cfg_.to_string(offset,print_zeros,indent_string) ;
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
    r += edf_cfg_.to_string(print_zeros,indent_string) ;
    r += ebuf_cred_cfg_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  DprsrHEdfCfgMap edf_cfg_;
  DprsrOeCredCfgMap ebuf_cred_cfg_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    offset += 0x18000; // to get to out_egr
    offset += 0x1000; // to get to mem
    return offset;
  }

};





  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_DPRSR_OE_MEM_H__
