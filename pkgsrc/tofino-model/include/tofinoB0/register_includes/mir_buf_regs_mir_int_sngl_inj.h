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
#ifndef __REGISTER_INCLUDES_MIR_BUF_REGS_MIR_INT_SNGL_INJ_H__
#define __REGISTER_INCLUDES_MIR_BUF_REGS_MIR_INT_SNGL_INJ_H__


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

class MirBufRegsMirIntSnglInj : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirBufRegsMirIntSnglInj(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("MirBufRegsMirIntSnglInj")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  MirBufRegsMirIntSnglInj(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MirBufRegsMirIntSnglInj")
    {
    }
public:

















  uint32_t &mir_sngl_err_inj() { return mir_sngl_err_inj_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (mir_sngl_err_inj_ & 0xffffff);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    mir_sngl_err_inj_ = (data & 0xffffff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    mir_sngl_err_inj_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MirBufRegsMirIntSnglInj") + ":\n";
    r += indent_string + "  " + std::string("mir_sngl_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mir_sngl_err_inj_) ) + "\n";
    all_zeros &= (0 == mir_sngl_err_inj_);
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
    r += indent_string + std::string("MirBufRegsMirIntSnglInj") + ":\n";
    r += indent_string + "  " + std::string("mir_sngl_err_inj") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(mir_sngl_err_inj_) ) + "\n";
    all_zeros &= (0 == mir_sngl_err_inj_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t mir_sngl_err_inj_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x780000; // to get to deparser
    offset += 0x20000; // to get to mirror
    offset += 0x8000; // to get to mir_buf_regs
    offset += 0x34; // to get to mir_glb_group_mir_int_sngl_inj
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_MIR_BUF_REGS_MIR_INT_SNGL_INJ_H__
