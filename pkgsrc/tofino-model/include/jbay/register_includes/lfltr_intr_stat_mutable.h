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
#ifndef __REGISTER_INCLUDES_LFLTR_INTR_STAT_MUTABLE_H__
#define __REGISTER_INCLUDES_LFLTR_INTR_STAT_MUTABLE_H__


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

class LfltrIntrStatMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  LfltrIntrStatMutable(
      int chipNumber, int index_lfltr_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_lfltr_rspec), 4, true, write_callback, read_callback, std::string("LfltrIntrStatMutable")+":"+boost::lexical_cast<std::string>(index_lfltr_rspec))
    {
    }
  LfltrIntrStatMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "LfltrIntrStatMutable")
    {
    }
public:





  uint8_t bft_clear_done() { return bft_clear_done_; }
  void bft_clear_done(const uint8_t &v) { bft_clear_done_=v; }







  uint8_t filter_unavail() { return filter_unavail_; }
  void filter_unavail(const uint8_t &v) { filter_unavail_=v; }





  uint8_t bft0_0_pbe() { return bft0_0_pbe_; }
  void bft0_0_pbe(const uint8_t &v) { bft0_0_pbe_=v; }





  uint8_t bft0_1_pbe() { return bft0_1_pbe_; }
  void bft0_1_pbe(const uint8_t &v) { bft0_1_pbe_=v; }





  uint8_t bft0_2_pbe() { return bft0_2_pbe_; }
  void bft0_2_pbe(const uint8_t &v) { bft0_2_pbe_=v; }





  uint8_t bft0_3_pbe() { return bft0_3_pbe_; }
  void bft0_3_pbe(const uint8_t &v) { bft0_3_pbe_=v; }





  uint8_t bft1_0_pbe() { return bft1_0_pbe_; }
  void bft1_0_pbe(const uint8_t &v) { bft1_0_pbe_=v; }





  uint8_t bft1_1_pbe() { return bft1_1_pbe_; }
  void bft1_1_pbe(const uint8_t &v) { bft1_1_pbe_=v; }





  uint8_t bft1_2_pbe() { return bft1_2_pbe_; }
  void bft1_2_pbe(const uint8_t &v) { bft1_2_pbe_=v; }





  uint8_t bft1_3_pbe() { return bft1_3_pbe_; }
  void bft1_3_pbe(const uint8_t &v) { bft1_3_pbe_=v; }





  uint8_t lqt0_0_mbe() { return lqt0_0_mbe_; }
  void lqt0_0_mbe(const uint8_t &v) { lqt0_0_mbe_=v; }





  uint8_t lqt0_1_mbe() { return lqt0_1_mbe_; }
  void lqt0_1_mbe(const uint8_t &v) { lqt0_1_mbe_=v; }





  uint8_t lqt0_2_mbe() { return lqt0_2_mbe_; }
  void lqt0_2_mbe(const uint8_t &v) { lqt0_2_mbe_=v; }





  uint8_t lqt1_0_mbe() { return lqt1_0_mbe_; }
  void lqt1_0_mbe(const uint8_t &v) { lqt1_0_mbe_=v; }





  uint8_t lqt1_1_mbe() { return lqt1_1_mbe_; }
  void lqt1_1_mbe(const uint8_t &v) { lqt1_1_mbe_=v; }





  uint8_t lqt1_2_mbe() { return lqt1_2_mbe_; }
  void lqt1_2_mbe(const uint8_t &v) { lqt1_2_mbe_=v; }





  uint8_t lqt0_0_sbe() { return lqt0_0_sbe_; }
  void lqt0_0_sbe(const uint8_t &v) { lqt0_0_sbe_=v; }





  uint8_t lqt0_1_sbe() { return lqt0_1_sbe_; }
  void lqt0_1_sbe(const uint8_t &v) { lqt0_1_sbe_=v; }





  uint8_t lqt0_2_sbe() { return lqt0_2_sbe_; }
  void lqt0_2_sbe(const uint8_t &v) { lqt0_2_sbe_=v; }





  uint8_t lqt1_0_sbe() { return lqt1_0_sbe_; }
  void lqt1_0_sbe(const uint8_t &v) { lqt1_0_sbe_=v; }





  uint8_t lqt1_1_sbe() { return lqt1_1_sbe_; }
  void lqt1_1_sbe(const uint8_t &v) { lqt1_1_sbe_=v; }





  uint8_t lqt1_2_sbe() { return lqt1_2_sbe_; }
  void lqt1_2_sbe(const uint8_t &v) { lqt1_2_sbe_=v; }





  uint8_t lbuf_0_mbe() { return lbuf_0_mbe_; }
  void lbuf_0_mbe(const uint8_t &v) { lbuf_0_mbe_=v; }





  uint8_t lbuf_1_mbe() { return lbuf_1_mbe_; }
  void lbuf_1_mbe(const uint8_t &v) { lbuf_1_mbe_=v; }





  uint8_t lbuf_2_mbe() { return lbuf_2_mbe_; }
  void lbuf_2_mbe(const uint8_t &v) { lbuf_2_mbe_=v; }





  uint8_t lbuf_0_sbe() { return lbuf_0_sbe_; }
  void lbuf_0_sbe(const uint8_t &v) { lbuf_0_sbe_=v; }





  uint8_t lbuf_1_sbe() { return lbuf_1_sbe_; }
  void lbuf_1_sbe(const uint8_t &v) { lbuf_1_sbe_=v; }





  uint8_t lbuf_2_sbe() { return lbuf_2_sbe_; }
  void lbuf_2_sbe(const uint8_t &v) { lbuf_2_sbe_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (bft_clear_done_ & 0x1);
    *data |= ((filter_unavail_ & 0x1) << 1);
    *data |= ((bft0_0_pbe_ & 0x1) << 2);
    *data |= ((bft0_1_pbe_ & 0x1) << 3);
    *data |= ((bft0_2_pbe_ & 0x1) << 4);
    *data |= ((bft0_3_pbe_ & 0x1) << 5);
    *data |= ((bft1_0_pbe_ & 0x1) << 6);
    *data |= ((bft1_1_pbe_ & 0x1) << 7);
    *data |= ((bft1_2_pbe_ & 0x1) << 8);
    *data |= ((bft1_3_pbe_ & 0x1) << 9);
    *data |= ((lqt0_0_mbe_ & 0x1) << 10);
    *data |= ((lqt0_1_mbe_ & 0x1) << 11);
    *data |= ((lqt0_2_mbe_ & 0x1) << 12);
    *data |= ((lqt1_0_mbe_ & 0x1) << 13);
    *data |= ((lqt1_1_mbe_ & 0x1) << 14);
    *data |= ((lqt1_2_mbe_ & 0x1) << 15);
    *data |= ((lqt0_0_sbe_ & 0x1) << 16);
    *data |= ((lqt0_1_sbe_ & 0x1) << 17);
    *data |= ((lqt0_2_sbe_ & 0x1) << 18);
    *data |= ((lqt1_0_sbe_ & 0x1) << 19);
    *data |= ((lqt1_1_sbe_ & 0x1) << 20);
    *data |= ((lqt1_2_sbe_ & 0x1) << 21);
    *data |= ((lbuf_0_mbe_ & 0x1) << 22);
    *data |= ((lbuf_1_mbe_ & 0x1) << 23);
    *data |= ((lbuf_2_mbe_ & 0x1) << 24);
    *data |= ((lbuf_0_sbe_ & 0x1) << 25);
    *data |= ((lbuf_1_sbe_ & 0x1) << 26);
    *data |= ((lbuf_2_sbe_ & 0x1) << 27);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    bft_clear_done_ &= ~(data & 0x1);
    filter_unavail_ &= ~((data >> 1) & 0x1);
    bft0_0_pbe_ &= ~((data >> 2) & 0x1);
    bft0_1_pbe_ &= ~((data >> 3) & 0x1);
    bft0_2_pbe_ &= ~((data >> 4) & 0x1);
    bft0_3_pbe_ &= ~((data >> 5) & 0x1);
    bft1_0_pbe_ &= ~((data >> 6) & 0x1);
    bft1_1_pbe_ &= ~((data >> 7) & 0x1);
    bft1_2_pbe_ &= ~((data >> 8) & 0x1);
    bft1_3_pbe_ &= ~((data >> 9) & 0x1);
    lqt0_0_mbe_ &= ~((data >> 10) & 0x1);
    lqt0_1_mbe_ &= ~((data >> 11) & 0x1);
    lqt0_2_mbe_ &= ~((data >> 12) & 0x1);
    lqt1_0_mbe_ &= ~((data >> 13) & 0x1);
    lqt1_1_mbe_ &= ~((data >> 14) & 0x1);
    lqt1_2_mbe_ &= ~((data >> 15) & 0x1);
    lqt0_0_sbe_ &= ~((data >> 16) & 0x1);
    lqt0_1_sbe_ &= ~((data >> 17) & 0x1);
    lqt0_2_sbe_ &= ~((data >> 18) & 0x1);
    lqt1_0_sbe_ &= ~((data >> 19) & 0x1);
    lqt1_1_sbe_ &= ~((data >> 20) & 0x1);
    lqt1_2_sbe_ &= ~((data >> 21) & 0x1);
    lbuf_0_mbe_ &= ~((data >> 22) & 0x1);
    lbuf_1_mbe_ &= ~((data >> 23) & 0x1);
    lbuf_2_mbe_ &= ~((data >> 24) & 0x1);
    lbuf_0_sbe_ &= ~((data >> 25) & 0x1);
    lbuf_1_sbe_ &= ~((data >> 26) & 0x1);
    lbuf_2_sbe_ &= ~((data >> 27) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    bft_clear_done_ = 0x0;
    filter_unavail_ = 0x0;
    bft0_0_pbe_ = 0x0;
    bft0_1_pbe_ = 0x0;
    bft0_2_pbe_ = 0x0;
    bft0_3_pbe_ = 0x0;
    bft1_0_pbe_ = 0x0;
    bft1_1_pbe_ = 0x0;
    bft1_2_pbe_ = 0x0;
    bft1_3_pbe_ = 0x0;
    lqt0_0_mbe_ = 0x0;
    lqt0_1_mbe_ = 0x0;
    lqt0_2_mbe_ = 0x0;
    lqt1_0_mbe_ = 0x0;
    lqt1_1_mbe_ = 0x0;
    lqt1_2_mbe_ = 0x0;
    lqt0_0_sbe_ = 0x0;
    lqt0_1_sbe_ = 0x0;
    lqt0_2_sbe_ = 0x0;
    lqt1_0_sbe_ = 0x0;
    lqt1_1_sbe_ = 0x0;
    lqt1_2_sbe_ = 0x0;
    lbuf_0_mbe_ = 0x0;
    lbuf_1_mbe_ = 0x0;
    lbuf_2_mbe_ = 0x0;
    lbuf_0_sbe_ = 0x0;
    lbuf_1_sbe_ = 0x0;
    lbuf_2_sbe_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("LfltrIntrStatMutable") + ":\n";
    r += indent_string + "  " + std::string("bft_clear_done") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft_clear_done_) ) + "\n";
    all_zeros &= (0 == bft_clear_done_);
    r += indent_string + "  " + std::string("filter_unavail") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(filter_unavail_) ) + "\n";
    all_zeros &= (0 == filter_unavail_);
    r += indent_string + "  " + std::string("bft0_0_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_0_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_0_pbe_);
    r += indent_string + "  " + std::string("bft0_1_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_1_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_1_pbe_);
    r += indent_string + "  " + std::string("bft0_2_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_2_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_2_pbe_);
    r += indent_string + "  " + std::string("bft0_3_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_3_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_3_pbe_);
    r += indent_string + "  " + std::string("bft1_0_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_0_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_0_pbe_);
    r += indent_string + "  " + std::string("bft1_1_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_1_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_1_pbe_);
    r += indent_string + "  " + std::string("bft1_2_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_2_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_2_pbe_);
    r += indent_string + "  " + std::string("bft1_3_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_3_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_3_pbe_);
    r += indent_string + "  " + std::string("lqt0_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_0_mbe_) ) + "\n";
    all_zeros &= (0 == lqt0_0_mbe_);
    r += indent_string + "  " + std::string("lqt0_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_1_mbe_) ) + "\n";
    all_zeros &= (0 == lqt0_1_mbe_);
    r += indent_string + "  " + std::string("lqt0_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_2_mbe_) ) + "\n";
    all_zeros &= (0 == lqt0_2_mbe_);
    r += indent_string + "  " + std::string("lqt1_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_0_mbe_) ) + "\n";
    all_zeros &= (0 == lqt1_0_mbe_);
    r += indent_string + "  " + std::string("lqt1_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_1_mbe_) ) + "\n";
    all_zeros &= (0 == lqt1_1_mbe_);
    r += indent_string + "  " + std::string("lqt1_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_2_mbe_) ) + "\n";
    all_zeros &= (0 == lqt1_2_mbe_);
    r += indent_string + "  " + std::string("lqt0_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_0_sbe_) ) + "\n";
    all_zeros &= (0 == lqt0_0_sbe_);
    r += indent_string + "  " + std::string("lqt0_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_1_sbe_) ) + "\n";
    all_zeros &= (0 == lqt0_1_sbe_);
    r += indent_string + "  " + std::string("lqt0_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_2_sbe_) ) + "\n";
    all_zeros &= (0 == lqt0_2_sbe_);
    r += indent_string + "  " + std::string("lqt1_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_0_sbe_) ) + "\n";
    all_zeros &= (0 == lqt1_0_sbe_);
    r += indent_string + "  " + std::string("lqt1_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_1_sbe_) ) + "\n";
    all_zeros &= (0 == lqt1_1_sbe_);
    r += indent_string + "  " + std::string("lqt1_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_2_sbe_) ) + "\n";
    all_zeros &= (0 == lqt1_2_sbe_);
    r += indent_string + "  " + std::string("lbuf_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_0_mbe_) ) + "\n";
    all_zeros &= (0 == lbuf_0_mbe_);
    r += indent_string + "  " + std::string("lbuf_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_1_mbe_) ) + "\n";
    all_zeros &= (0 == lbuf_1_mbe_);
    r += indent_string + "  " + std::string("lbuf_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_2_mbe_) ) + "\n";
    all_zeros &= (0 == lbuf_2_mbe_);
    r += indent_string + "  " + std::string("lbuf_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_0_sbe_) ) + "\n";
    all_zeros &= (0 == lbuf_0_sbe_);
    r += indent_string + "  " + std::string("lbuf_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_1_sbe_) ) + "\n";
    all_zeros &= (0 == lbuf_1_sbe_);
    r += indent_string + "  " + std::string("lbuf_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_2_sbe_) ) + "\n";
    all_zeros &= (0 == lbuf_2_sbe_);
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
    r += indent_string + std::string("LfltrIntrStatMutable") + ":\n";
    r += indent_string + "  " + std::string("bft_clear_done") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft_clear_done_) ) + "\n";
    all_zeros &= (0 == bft_clear_done_);
    r += indent_string + "  " + std::string("filter_unavail") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(filter_unavail_) ) + "\n";
    all_zeros &= (0 == filter_unavail_);
    r += indent_string + "  " + std::string("bft0_0_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_0_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_0_pbe_);
    r += indent_string + "  " + std::string("bft0_1_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_1_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_1_pbe_);
    r += indent_string + "  " + std::string("bft0_2_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_2_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_2_pbe_);
    r += indent_string + "  " + std::string("bft0_3_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft0_3_pbe_) ) + "\n";
    all_zeros &= (0 == bft0_3_pbe_);
    r += indent_string + "  " + std::string("bft1_0_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_0_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_0_pbe_);
    r += indent_string + "  " + std::string("bft1_1_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_1_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_1_pbe_);
    r += indent_string + "  " + std::string("bft1_2_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_2_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_2_pbe_);
    r += indent_string + "  " + std::string("bft1_3_pbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(bft1_3_pbe_) ) + "\n";
    all_zeros &= (0 == bft1_3_pbe_);
    r += indent_string + "  " + std::string("lqt0_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_0_mbe_) ) + "\n";
    all_zeros &= (0 == lqt0_0_mbe_);
    r += indent_string + "  " + std::string("lqt0_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_1_mbe_) ) + "\n";
    all_zeros &= (0 == lqt0_1_mbe_);
    r += indent_string + "  " + std::string("lqt0_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_2_mbe_) ) + "\n";
    all_zeros &= (0 == lqt0_2_mbe_);
    r += indent_string + "  " + std::string("lqt1_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_0_mbe_) ) + "\n";
    all_zeros &= (0 == lqt1_0_mbe_);
    r += indent_string + "  " + std::string("lqt1_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_1_mbe_) ) + "\n";
    all_zeros &= (0 == lqt1_1_mbe_);
    r += indent_string + "  " + std::string("lqt1_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_2_mbe_) ) + "\n";
    all_zeros &= (0 == lqt1_2_mbe_);
    r += indent_string + "  " + std::string("lqt0_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_0_sbe_) ) + "\n";
    all_zeros &= (0 == lqt0_0_sbe_);
    r += indent_string + "  " + std::string("lqt0_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_1_sbe_) ) + "\n";
    all_zeros &= (0 == lqt0_1_sbe_);
    r += indent_string + "  " + std::string("lqt0_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt0_2_sbe_) ) + "\n";
    all_zeros &= (0 == lqt0_2_sbe_);
    r += indent_string + "  " + std::string("lqt1_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_0_sbe_) ) + "\n";
    all_zeros &= (0 == lqt1_0_sbe_);
    r += indent_string + "  " + std::string("lqt1_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_1_sbe_) ) + "\n";
    all_zeros &= (0 == lqt1_1_sbe_);
    r += indent_string + "  " + std::string("lqt1_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lqt1_2_sbe_) ) + "\n";
    all_zeros &= (0 == lqt1_2_sbe_);
    r += indent_string + "  " + std::string("lbuf_0_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_0_mbe_) ) + "\n";
    all_zeros &= (0 == lbuf_0_mbe_);
    r += indent_string + "  " + std::string("lbuf_1_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_1_mbe_) ) + "\n";
    all_zeros &= (0 == lbuf_1_mbe_);
    r += indent_string + "  " + std::string("lbuf_2_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_2_mbe_) ) + "\n";
    all_zeros &= (0 == lbuf_2_mbe_);
    r += indent_string + "  " + std::string("lbuf_0_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_0_sbe_) ) + "\n";
    all_zeros &= (0 == lbuf_0_sbe_);
    r += indent_string + "  " + std::string("lbuf_1_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_1_sbe_) ) + "\n";
    all_zeros &= (0 == lbuf_1_sbe_);
    r += indent_string + "  " + std::string("lbuf_2_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(lbuf_2_sbe_) ) + "\n";
    all_zeros &= (0 == lbuf_2_sbe_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t bft_clear_done_;
  uint8_t filter_unavail_;
  uint8_t bft0_0_pbe_;
  uint8_t bft0_1_pbe_;
  uint8_t bft0_2_pbe_;
  uint8_t bft0_3_pbe_;
  uint8_t bft1_0_pbe_;
  uint8_t bft1_1_pbe_;
  uint8_t bft1_2_pbe_;
  uint8_t bft1_3_pbe_;
  uint8_t lqt0_0_mbe_;
  uint8_t lqt0_1_mbe_;
  uint8_t lqt0_2_mbe_;
  uint8_t lqt1_0_mbe_;
  uint8_t lqt1_1_mbe_;
  uint8_t lqt1_2_mbe_;
  uint8_t lqt0_0_sbe_;
  uint8_t lqt0_1_sbe_;
  uint8_t lqt0_2_sbe_;
  uint8_t lqt1_0_sbe_;
  uint8_t lqt1_1_sbe_;
  uint8_t lqt1_2_sbe_;
  uint8_t lbuf_0_mbe_;
  uint8_t lbuf_1_mbe_;
  uint8_t lbuf_2_mbe_;
  uint8_t lbuf_0_sbe_;
  uint8_t lbuf_1_sbe_;
  uint8_t lbuf_2_sbe_;
private:
  static int StartOffset(
      int index_lfltr_rspec
      ) {
    int offset=0;
    offset += 0x400000; // to get to lfltr
    assert(index_lfltr_rspec < 4);
    offset += index_lfltr_rspec * 0x80000; // lfltr_rspec[]
    offset += 0x20000; // to get to ctrl
    offset += 0x30; // to get to intr_stat
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_LFLTR_INTR_STAT_MUTABLE_H__
