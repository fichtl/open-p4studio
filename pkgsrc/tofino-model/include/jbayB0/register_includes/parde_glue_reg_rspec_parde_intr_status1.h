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
#ifndef __REGISTER_INCLUDES_PARDE_GLUE_REG_RSPEC_PARDE_INTR_STATUS1_H__
#define __REGISTER_INCLUDES_PARDE_GLUE_REG_RSPEC_PARDE_INTR_STATUS1_H__


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

class PardeGlueRegRspecPardeIntrStatus1 : public model_core::RegisterBlock<RegisterCallback> {
public:
  PardeGlueRegRspecPardeIntrStatus1(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("PardeGlueRegRspecPardeIntrStatus1")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PardeGlueRegRspecPardeIntrStatus1(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PardeGlueRegRspecPardeIntrStatus1")
    {
    }
public:





  uint8_t &pbusstat() { return pbusstat_; }





  uint8_t &parde_glue() { return parde_glue_; }





  uint8_t &csr_ring0() { return csr_ring0_; }





  uint8_t &csr_ring1() { return csr_ring1_; }





  uint8_t &csr_ring2() { return csr_ring2_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (pbusstat_ & 0x1);
    *data |= ((parde_glue_ & 0x1) << 1);
    *data |= ((csr_ring0_ & 0x1) << 2);
    *data |= ((csr_ring1_ & 0x1) << 3);
    *data |= ((csr_ring2_ & 0x1) << 4);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    pbusstat_ = (data & 0x1);
    parde_glue_ = ((data >> 1) & 0x1);
    csr_ring0_ = ((data >> 2) & 0x1);
    csr_ring1_ = ((data >> 3) & 0x1);
    csr_ring2_ = ((data >> 4) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    pbusstat_ = 0;
    parde_glue_ = 0;
    csr_ring0_ = 0;
    csr_ring1_ = 0;
    csr_ring2_ = 0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PardeGlueRegRspecPardeIntrStatus1") + ":\n";
    r += indent_string + "  " + std::string("pbusstat") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pbusstat_) ) + "\n";
    all_zeros &= (0 == pbusstat_);
    r += indent_string + "  " + std::string("parde_glue") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(parde_glue_) ) + "\n";
    all_zeros &= (0 == parde_glue_);
    r += indent_string + "  " + std::string("csr_ring0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring0_) ) + "\n";
    all_zeros &= (0 == csr_ring0_);
    r += indent_string + "  " + std::string("csr_ring1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1_) ) + "\n";
    all_zeros &= (0 == csr_ring1_);
    r += indent_string + "  " + std::string("csr_ring2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring2_) ) + "\n";
    all_zeros &= (0 == csr_ring2_);
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
    r += indent_string + std::string("PardeGlueRegRspecPardeIntrStatus1") + ":\n";
    r += indent_string + "  " + std::string("pbusstat") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pbusstat_) ) + "\n";
    all_zeros &= (0 == pbusstat_);
    r += indent_string + "  " + std::string("parde_glue") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(parde_glue_) ) + "\n";
    all_zeros &= (0 == parde_glue_);
    r += indent_string + "  " + std::string("csr_ring0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring0_) ) + "\n";
    all_zeros &= (0 == csr_ring0_);
    r += indent_string + "  " + std::string("csr_ring1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1_) ) + "\n";
    all_zeros &= (0 == csr_ring1_);
    r += indent_string + "  " + std::string("csr_ring2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring2_) ) + "\n";
    all_zeros &= (0 == csr_ring2_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t pbusstat_;
  uint8_t parde_glue_;
  uint8_t csr_ring0_;
  uint8_t csr_ring1_;
  uint8_t csr_ring2_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x1e000; // to get to pgluereg
    offset += 0x2c; // to get to parde_intr_status1
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PARDE_GLUE_REG_RSPEC_PARDE_INTR_STATUS1_H__
