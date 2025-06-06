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
#ifndef __REGISTER_INCLUDES_DPRSR_OI_REGS_MIRR_HDR_I_SBE_ERR_MUTABLE_H__
#define __REGISTER_INCLUDES_DPRSR_OI_REGS_MIRR_HDR_I_SBE_ERR_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofinoB0 {
  namespace register_classes {

class DprsrOiRegsMirrHdrISbeErrMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  DprsrOiRegsMirrHdrISbeErrMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, true, write_callback, read_callback, std::string("DprsrOiRegsMirrHdrISbeErrMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  DprsrOiRegsMirrHdrISbeErrMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "DprsrOiRegsMirrHdrISbeErrMutable")
    {
    }
public:





  uint32_t ctr32() { return ctr32_; }
  void ctr32(const uint32_t &v) { ctr32_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = ctr32_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    ctr32_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    ctr32_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("DprsrOiRegsMirrHdrISbeErrMutable") + ":\n";
    r += indent_string + "  " + std::string("ctr32") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ctr32_) ) + "\n";
    all_zeros &= (0 == ctr32_);
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
    r += indent_string + std::string("DprsrOiRegsMirrHdrISbeErrMutable") + ":\n";
    r += indent_string + "  " + std::string("ctr32") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ctr32_) ) + "\n";
    all_zeros &= (0 == ctr32_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t ctr32_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    offset += 0x10000; // to get to out_ingr
    offset += 0x660; // to get to mirr_hdr_i_sbe_err
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_DPRSR_OI_REGS_MIRR_HDR_I_SBE_ERR_MUTABLE_H__
