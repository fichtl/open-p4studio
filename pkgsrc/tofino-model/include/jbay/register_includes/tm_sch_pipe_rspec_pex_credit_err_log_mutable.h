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
#ifndef __REGISTER_INCLUDES_TM_SCH_PIPE_RSPEC_PEX_CREDIT_ERR_LOG_MUTABLE_H__
#define __REGISTER_INCLUDES_TM_SCH_PIPE_RSPEC_PEX_CREDIT_ERR_LOG_MUTABLE_H__


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

class TmSchPipeRspecPexCreditErrLogMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum TmTopRspecEnum {
    kTmSchaTop,
    kTmSchbTop
  };
public:
  TmSchPipeRspecPexCreditErrLogMutable(
      int chipNumber, TmTopRspecEnum selector_tm_top_rspec, int index_tm_sch_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_tm_top_rspec, index_tm_sch_pipe_rspec), 4, true, write_callback, read_callback, std::string("TmSchPipeRspecPexCreditErrLogMutable")+":"+boost::lexical_cast<std::string>(selector_tm_top_rspec) + "," + boost::lexical_cast<std::string>(index_tm_sch_pipe_rspec))
    {
    }
  TmSchPipeRspecPexCreditErrLogMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "TmSchPipeRspecPexCreditErrLogMutable")
    {
    }
public:
  uint8_t port() { return port_; }
  void port(const uint8_t &v) { port_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (port_ & 0x7f);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    port_ = (data & 0x7f);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    port_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("TmSchPipeRspecPexCreditErrLogMutable") + ":\n";
    r += indent_string + "  " + std::string("port") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(port_) ) + "\n";
    all_zeros &= (0 == port_);
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
    r += indent_string + std::string("TmSchPipeRspecPexCreditErrLogMutable") + ":\n";
    r += indent_string + "  " + std::string("port") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(port_) ) + "\n";
    all_zeros &= (0 == port_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t port_;
private:
  static int StartOffset(
      TmTopRspecEnum selector_tm_top_rspec, int index_tm_sch_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    switch (selector_tm_top_rspec) {
      case kTmSchaTop:
        offset += 0x180000; // to get to tm_scha_top
        assert(index_tm_sch_pipe_rspec < 2);
        offset += index_tm_sch_pipe_rspec * 0x8000; // tm_sch_pipe_rspec[]
        offset += 0xbc; // to get to pex_credit_err_log
        break;
      case kTmSchbTop:
        offset += 0x200000; // to get to tm_schb_top
        assert(index_tm_sch_pipe_rspec < 2);
        offset += index_tm_sch_pipe_rspec * 0x8000; // tm_sch_pipe_rspec[]
        offset += 0xbc; // to get to pex_credit_err_log
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};
















  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_TM_SCH_PIPE_RSPEC_PEX_CREDIT_ERR_LOG_MUTABLE_H__
