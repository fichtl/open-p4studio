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
#ifndef __REGISTER_INCLUDES_TM_QLC_PIPE_RSPEC_ECC_MUTABLE_H__
#define __REGISTER_INCLUDES_TM_QLC_PIPE_RSPEC_ECC_MUTABLE_H__


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

class TmQlcPipeRspecEccMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  TmQlcPipeRspecEccMutable(
      int chipNumber, int index_tm_qlc_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_qlc_pipe_rspec), 4, true, write_callback, read_callback, std::string("TmQlcPipeRspecEccMutable")+":"+boost::lexical_cast<std::string>(index_tm_qlc_pipe_rspec))
    {
    }
  TmQlcPipeRspecEccMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "TmQlcPipeRspecEccMutable")
    {
    }
public:




  uint8_t _q_l_c__q_l_m_disable_check() { return _q_l_c__q_l_m_disable_check_; }
  void _q_l_c__q_l_m_disable_check(const uint8_t &v) { _q_l_c__q_l_m_disable_check_=v; }




  uint8_t _q_l_c__q_l_m_inject_sbe() { return _q_l_c__q_l_m_inject_sbe_; }
  void _q_l_c__q_l_m_inject_sbe(const uint8_t &v) { _q_l_c__q_l_m_inject_sbe_=v; }




  uint8_t _q_l_c__q_l_m_inject_mbe() { return _q_l_c__q_l_m_inject_mbe_; }
  void _q_l_c__q_l_m_inject_mbe(const uint8_t &v) { _q_l_c__q_l_m_inject_mbe_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (_q_l_c__q_l_m_disable_check_ & 0x1);
    *data |= ((_q_l_c__q_l_m_inject_sbe_ & 0x1) << 1);
    *data |= ((_q_l_c__q_l_m_inject_mbe_ & 0x1) << 2);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    _q_l_c__q_l_m_disable_check_ = (data & 0x1);
    _q_l_c__q_l_m_inject_sbe_ = ((data >> 1) & 0x1);
    _q_l_c__q_l_m_inject_mbe_ = ((data >> 2) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    _q_l_c__q_l_m_disable_check_ = 0x0;
    _q_l_c__q_l_m_inject_sbe_ = 0x0;
    _q_l_c__q_l_m_inject_mbe_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("TmQlcPipeRspecEccMutable") + ":\n";
    r += indent_string + "  " + std::string("QLC_QLM_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(_q_l_c__q_l_m_disable_check_) ) + "\n";
    all_zeros &= (0 == _q_l_c__q_l_m_disable_check_);
    r += indent_string + "  " + std::string("QLC_QLM_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(_q_l_c__q_l_m_inject_sbe_) ) + "\n";
    all_zeros &= (0 == _q_l_c__q_l_m_inject_sbe_);
    r += indent_string + "  " + std::string("QLC_QLM_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(_q_l_c__q_l_m_inject_mbe_) ) + "\n";
    all_zeros &= (0 == _q_l_c__q_l_m_inject_mbe_);
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
    r += indent_string + std::string("TmQlcPipeRspecEccMutable") + ":\n";
    r += indent_string + "  " + std::string("QLC_QLM_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(_q_l_c__q_l_m_disable_check_) ) + "\n";
    all_zeros &= (0 == _q_l_c__q_l_m_disable_check_);
    r += indent_string + "  " + std::string("QLC_QLM_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(_q_l_c__q_l_m_inject_sbe_) ) + "\n";
    all_zeros &= (0 == _q_l_c__q_l_m_inject_sbe_);
    r += indent_string + "  " + std::string("QLC_QLM_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(_q_l_c__q_l_m_inject_mbe_) ) + "\n";
    all_zeros &= (0 == _q_l_c__q_l_m_inject_mbe_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t _q_l_c__q_l_m_disable_check_;
  uint8_t _q_l_c__q_l_m_inject_sbe_;
  uint8_t _q_l_c__q_l_m_inject_mbe_;
private:
  static int StartOffset(
      int index_tm_qlc_pipe_rspec
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0x140000; // to get to tm_qlc_top
    assert(index_tm_qlc_pipe_rspec < 4);
    offset += index_tm_qlc_pipe_rspec * 0x8000; // tm_qlc_pipe_rspec[]
    offset += 0x4; // to get to ecc
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_TM_QLC_PIPE_RSPEC_ECC_MUTABLE_H__
