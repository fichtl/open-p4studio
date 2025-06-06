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
#ifndef __REGISTER_INCLUDES_MISC_REGS_SBM_IND_RSLT_H__
#define __REGISTER_INCLUDES_MISC_REGS_SBM_IND_RSLT_H__


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

class MiscRegsSbmIndRslt : public model_core::RegisterBlock<RegisterCallback> {
public:
  MiscRegsSbmIndRslt(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, false, write_callback, read_callback, std::string("MiscRegsSbmIndRslt"))
    {
    }
  MiscRegsSbmIndRslt(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MiscRegsSbmIndRslt")
    {
    }
public:





  uint8_t &sbm_ind_rslt() { return sbm_ind_rslt_; }





  uint8_t &sbm_ind_timeout() { return sbm_ind_timeout_; }





  uint8_t &sbm_ind_busy() { return sbm_ind_busy_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (sbm_ind_rslt_ & 0x7);
    *data |= ((sbm_ind_timeout_ & 0x1) << 3);
    *data |= ((sbm_ind_busy_ & 0x1) << 4);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    sbm_ind_rslt_ = (data & 0x7);
    sbm_ind_timeout_ = ((data >> 3) & 0x1);
    sbm_ind_busy_ = ((data >> 4) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    sbm_ind_rslt_ = 0x0;
    sbm_ind_timeout_ = 0x0;
    sbm_ind_busy_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MiscRegsSbmIndRslt") + ":\n";
    r += indent_string + "  " + std::string("sbm_ind_rslt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm_ind_rslt_) ) + "\n";
    all_zeros &= (0 == sbm_ind_rslt_);
    r += indent_string + "  " + std::string("sbm_ind_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm_ind_timeout_) ) + "\n";
    all_zeros &= (0 == sbm_ind_timeout_);
    r += indent_string + "  " + std::string("sbm_ind_busy") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm_ind_busy_) ) + "\n";
    all_zeros &= (0 == sbm_ind_busy_);
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
    r += indent_string + std::string("MiscRegsSbmIndRslt") + ":\n";
    r += indent_string + "  " + std::string("sbm_ind_rslt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm_ind_rslt_) ) + "\n";
    all_zeros &= (0 == sbm_ind_rslt_);
    r += indent_string + "  " + std::string("sbm_ind_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm_ind_timeout_) ) + "\n";
    all_zeros &= (0 == sbm_ind_timeout_);
    r += indent_string + "  " + std::string("sbm_ind_busy") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm_ind_busy_) ) + "\n";
    all_zeros &= (0 == sbm_ind_busy_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t sbm_ind_rslt_;
  uint8_t sbm_ind_timeout_;
  uint8_t sbm_ind_busy_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x40000; // to get to misc_regs
    offset += 0xc0; // to get to sbm_ind_rslt
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_MISC_REGS_SBM_IND_RSLT_H__
