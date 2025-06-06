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
#ifndef __REGISTER_INCLUDES_TM_PEX_PIPE_RSPEC_INTR_STAT_H__
#define __REGISTER_INCLUDES_TM_PEX_PIPE_RSPEC_INTR_STAT_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>










namespace jbayB0 {
  namespace register_classes {

class TmPexPipeRspecIntrStat : public model_core::RegisterBlock<RegisterCallback> {
public:
  TmPexPipeRspecIntrStat(
      int chipNumber, int index_tm_pex_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_pex_pipe_rspec), 4, false, write_callback, read_callback, std::string("TmPexPipeRspecIntrStat")+":"+boost::lexical_cast<std::string>(index_tm_pex_pipe_rspec))
    {
    }
  TmPexPipeRspecIntrStat(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "TmPexPipeRspecIntrStat")
    {
    }
public:





  uint8_t &qpex_int_stat_clm_merr() { return qpex_int_stat_clm_merr_; }





  uint8_t &qpex_int_stat_clm_serr() { return qpex_int_stat_clm_serr_; }





  uint8_t &qpex_int_stat_dq_ph_fifo_serr() { return qpex_int_stat_dq_ph_fifo_serr_; }





  uint8_t &qpex_int_stat_dq_ph_fifo_merr() { return qpex_int_stat_dq_ph_fifo_merr_; }





  uint8_t &qpex_int_stat_dq_meta_fifo_serr() { return qpex_int_stat_dq_meta_fifo_serr_; }





  uint8_t &qpex_int_stat_dq_meta_fifo_merr() { return qpex_int_stat_dq_meta_fifo_merr_; }





  uint8_t &qpex_int_stat_ph_afifo_serr() { return qpex_int_stat_ph_afifo_serr_; }





  uint8_t &qpex_int_stat_ph_afifo_merr() { return qpex_int_stat_ph_afifo_merr_; }





  uint8_t &qpex_int_stat_ph_discard_fifo_serr0() { return qpex_int_stat_ph_discard_fifo_serr0_; }





  uint8_t &qpex_int_stat_ph_discard_fifo_merr0() { return qpex_int_stat_ph_discard_fifo_merr0_; }





  uint8_t &qpex_int_stat_ph_discard_fifo_serr1() { return qpex_int_stat_ph_discard_fifo_serr1_; }





  uint8_t &qpex_int_stat_ph_discard_fifo_merr1() { return qpex_int_stat_ph_discard_fifo_merr1_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (qpex_int_stat_clm_merr_ & 0x1);
    *data |= ((qpex_int_stat_clm_serr_ & 0x1) << 1);
    *data |= ((qpex_int_stat_dq_ph_fifo_serr_ & 0x1) << 2);
    *data |= ((qpex_int_stat_dq_ph_fifo_merr_ & 0x1) << 3);
    *data |= ((qpex_int_stat_dq_meta_fifo_serr_ & 0x1) << 4);
    *data |= ((qpex_int_stat_dq_meta_fifo_merr_ & 0x1) << 5);
    *data |= ((qpex_int_stat_ph_afifo_serr_ & 0x1) << 6);
    *data |= ((qpex_int_stat_ph_afifo_merr_ & 0x1) << 7);
    *data |= ((qpex_int_stat_ph_discard_fifo_serr0_ & 0x1) << 8);
    *data |= ((qpex_int_stat_ph_discard_fifo_merr0_ & 0x1) << 9);
    *data |= ((qpex_int_stat_ph_discard_fifo_serr1_ & 0x1) << 10);
    *data |= ((qpex_int_stat_ph_discard_fifo_merr1_ & 0x1) << 11);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    qpex_int_stat_clm_merr_ &= ~(data & 0x1);
    qpex_int_stat_clm_serr_ &= ~((data >> 1) & 0x1);
    qpex_int_stat_dq_ph_fifo_serr_ &= ~((data >> 2) & 0x1);
    qpex_int_stat_dq_ph_fifo_merr_ &= ~((data >> 3) & 0x1);
    qpex_int_stat_dq_meta_fifo_serr_ &= ~((data >> 4) & 0x1);
    qpex_int_stat_dq_meta_fifo_merr_ &= ~((data >> 5) & 0x1);
    qpex_int_stat_ph_afifo_serr_ &= ~((data >> 6) & 0x1);
    qpex_int_stat_ph_afifo_merr_ &= ~((data >> 7) & 0x1);
    qpex_int_stat_ph_discard_fifo_serr0_ &= ~((data >> 8) & 0x1);
    qpex_int_stat_ph_discard_fifo_merr0_ &= ~((data >> 9) & 0x1);
    qpex_int_stat_ph_discard_fifo_serr1_ &= ~((data >> 10) & 0x1);
    qpex_int_stat_ph_discard_fifo_merr1_ &= ~((data >> 11) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    qpex_int_stat_clm_merr_ = 0x0;
    qpex_int_stat_clm_serr_ = 0x0;
    qpex_int_stat_dq_ph_fifo_serr_ = 0x0;
    qpex_int_stat_dq_ph_fifo_merr_ = 0x0;
    qpex_int_stat_dq_meta_fifo_serr_ = 0x0;
    qpex_int_stat_dq_meta_fifo_merr_ = 0x0;
    qpex_int_stat_ph_afifo_serr_ = 0x0;
    qpex_int_stat_ph_afifo_merr_ = 0x0;
    qpex_int_stat_ph_discard_fifo_serr0_ = 0x0;
    qpex_int_stat_ph_discard_fifo_merr0_ = 0x0;
    qpex_int_stat_ph_discard_fifo_serr1_ = 0x0;
    qpex_int_stat_ph_discard_fifo_merr1_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("TmPexPipeRspecIntrStat") + ":\n";
    r += indent_string + "  " + std::string("qpex_int_stat_clm_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_clm_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_clm_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_clm_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_clm_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_clm_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_ph_fifo_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_ph_fifo_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_ph_fifo_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_ph_fifo_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_ph_fifo_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_ph_fifo_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_meta_fifo_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_meta_fifo_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_meta_fifo_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_meta_fifo_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_meta_fifo_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_meta_fifo_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_afifo_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_afifo_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_afifo_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_afifo_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_afifo_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_afifo_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_serr0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_serr0_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_serr0_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_merr0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_merr0_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_merr0_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_serr1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_serr1_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_serr1_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_merr1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_merr1_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_merr1_);
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
    r += indent_string + std::string("TmPexPipeRspecIntrStat") + ":\n";
    r += indent_string + "  " + std::string("qpex_int_stat_clm_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_clm_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_clm_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_clm_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_clm_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_clm_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_ph_fifo_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_ph_fifo_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_ph_fifo_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_ph_fifo_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_ph_fifo_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_ph_fifo_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_meta_fifo_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_meta_fifo_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_meta_fifo_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_dq_meta_fifo_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_dq_meta_fifo_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_dq_meta_fifo_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_afifo_serr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_afifo_serr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_afifo_serr_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_afifo_merr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_afifo_merr_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_afifo_merr_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_serr0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_serr0_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_serr0_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_merr0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_merr0_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_merr0_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_serr1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_serr1_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_serr1_);
    r += indent_string + "  " + std::string("qpex_int_stat_ph_discard_fifo_merr1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(qpex_int_stat_ph_discard_fifo_merr1_) ) + "\n";
    all_zeros &= (0 == qpex_int_stat_ph_discard_fifo_merr1_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t qpex_int_stat_clm_merr_;
  uint8_t qpex_int_stat_clm_serr_;
  uint8_t qpex_int_stat_dq_ph_fifo_serr_;
  uint8_t qpex_int_stat_dq_ph_fifo_merr_;
  uint8_t qpex_int_stat_dq_meta_fifo_serr_;
  uint8_t qpex_int_stat_dq_meta_fifo_merr_;
  uint8_t qpex_int_stat_ph_afifo_serr_;
  uint8_t qpex_int_stat_ph_afifo_merr_;
  uint8_t qpex_int_stat_ph_discard_fifo_serr0_;
  uint8_t qpex_int_stat_ph_discard_fifo_merr0_;
  uint8_t qpex_int_stat_ph_discard_fifo_serr1_;
  uint8_t qpex_int_stat_ph_discard_fifo_merr1_;
private:
  static int StartOffset(
      int index_tm_pex_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x300000; // to get to tm_pex_top
    assert(index_tm_pex_pipe_rspec < 4);
    offset += index_tm_pex_pipe_rspec * 0x4000; // tm_pex_pipe_rspec[]
    offset += 0x20; // to get to intr_stat
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_TM_PEX_PIPE_RSPEC_INTR_STAT_H__
