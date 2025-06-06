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
#ifndef __REGISTER_INCLUDES_MIR_BUF_REGS_DISABLE_MIR_ERR_MUTABLE_H__
#define __REGISTER_INCLUDES_MIR_BUF_REGS_DISABLE_MIR_ERR_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>












namespace tofino {
  namespace register_classes {

class MirBufRegsDisableMirErrMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  MirBufRegsDisableMirErrMutable(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, true, write_callback, read_callback, std::string("MirBufRegsDisableMirErrMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  MirBufRegsDisableMirErrMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "MirBufRegsDisableMirErrMutable")
    {
    }
public:





  uint16_t ingr_capt_session_id() { return ingr_capt_session_id_; }
  void ingr_capt_session_id(const uint16_t &v) { ingr_capt_session_id_=v; }





  uint16_t egr_capt_session_id() { return egr_capt_session_id_; }
  void egr_capt_session_id(const uint16_t &v) { egr_capt_session_id_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (ingr_capt_session_id_ & 0x3ff);
    *data |= ((egr_capt_session_id_ & 0x3ff) << 16);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    ingr_capt_session_id_ = (data & 0x3ff);
    egr_capt_session_id_ = ((data >> 16) & 0x3ff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    ingr_capt_session_id_ = 0x0;
    egr_capt_session_id_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MirBufRegsDisableMirErrMutable") + ":\n";
    r += indent_string + "  " + std::string("ingr_capt_session_id") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ingr_capt_session_id_) ) + "\n";
    all_zeros &= (0 == ingr_capt_session_id_);
    r += indent_string + "  " + std::string("egr_capt_session_id") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(egr_capt_session_id_) ) + "\n";
    all_zeros &= (0 == egr_capt_session_id_);
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
    r += indent_string + std::string("MirBufRegsDisableMirErrMutable") + ":\n";
    r += indent_string + "  " + std::string("ingr_capt_session_id") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(ingr_capt_session_id_) ) + "\n";
    all_zeros &= (0 == ingr_capt_session_id_);
    r += indent_string + "  " + std::string("egr_capt_session_id") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(egr_capt_session_id_) ) + "\n";
    all_zeros &= (0 == egr_capt_session_id_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t ingr_capt_session_id_;
  uint16_t egr_capt_session_id_;
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
    offset += 0x4c; // to get to mir_glb_group_disable_mir_err
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_MIR_BUF_REGS_DISABLE_MIR_ERR_MUTABLE_H__
