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
#ifndef __REGISTER_INCLUDES_PARDE_GLUE_REG_RSPEC_CSR_RING1INTR_STATUS1_H__
#define __REGISTER_INCLUDES_PARDE_GLUE_REG_RSPEC_CSR_RING1INTR_STATUS1_H__


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

class PardeGlueRegRspecCsrRing1intrStatus1 : public model_core::RegisterBlock<RegisterCallback> {
public:
  PardeGlueRegRspecCsrRing1intrStatus1(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("PardeGlueRegRspecCsrRing1intrStatus1")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PardeGlueRegRspecCsrRing1intrStatus1(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PardeGlueRegRspecCsrRing1intrStatus1")
    {
    }
public:





  uint8_t &csr_ring1sid_0() { return csr_ring1sid_0_; }





  uint8_t &csr_ring1sid_1() { return csr_ring1sid_1_; }





  uint8_t &csr_ring1sid_2() { return csr_ring1sid_2_; }





  uint8_t &csr_ring1sid_3() { return csr_ring1sid_3_; }





  uint8_t &csr_ring1sid_4() { return csr_ring1sid_4_; }





  uint8_t &csr_ring1sid_5() { return csr_ring1sid_5_; }





  uint8_t &csr_ring1sid_6() { return csr_ring1sid_6_; }





  uint8_t &csr_ring1sid_7() { return csr_ring1sid_7_; }





  uint8_t &csr_ring1sid_8() { return csr_ring1sid_8_; }





  uint8_t &csr_ring1sid_9() { return csr_ring1sid_9_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (csr_ring1sid_0_ & 0x1);
    *data |= ((csr_ring1sid_1_ & 0x1) << 1);
    *data |= ((csr_ring1sid_2_ & 0x1) << 2);
    *data |= ((csr_ring1sid_3_ & 0x1) << 3);
    *data |= ((csr_ring1sid_4_ & 0x1) << 4);
    *data |= ((csr_ring1sid_5_ & 0x1) << 5);
    *data |= ((csr_ring1sid_6_ & 0x1) << 6);
    *data |= ((csr_ring1sid_7_ & 0x1) << 7);
    *data |= ((csr_ring1sid_8_ & 0x1) << 8);
    *data |= ((csr_ring1sid_9_ & 0x1) << 9);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    csr_ring1sid_0_ = (data & 0x1);
    csr_ring1sid_1_ = ((data >> 1) & 0x1);
    csr_ring1sid_2_ = ((data >> 2) & 0x1);
    csr_ring1sid_3_ = ((data >> 3) & 0x1);
    csr_ring1sid_4_ = ((data >> 4) & 0x1);
    csr_ring1sid_5_ = ((data >> 5) & 0x1);
    csr_ring1sid_6_ = ((data >> 6) & 0x1);
    csr_ring1sid_7_ = ((data >> 7) & 0x1);
    csr_ring1sid_8_ = ((data >> 8) & 0x1);
    csr_ring1sid_9_ = ((data >> 9) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    csr_ring1sid_0_ = 0;
    csr_ring1sid_1_ = 0;
    csr_ring1sid_2_ = 0;
    csr_ring1sid_3_ = 0;
    csr_ring1sid_4_ = 0;
    csr_ring1sid_5_ = 0;
    csr_ring1sid_6_ = 0;
    csr_ring1sid_7_ = 0;
    csr_ring1sid_8_ = 0;
    csr_ring1sid_9_ = 0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PardeGlueRegRspecCsrRing1intrStatus1") + ":\n";
    r += indent_string + "  " + std::string("csr_ring1sid_0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_0_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_0_);
    r += indent_string + "  " + std::string("csr_ring1sid_1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_1_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_1_);
    r += indent_string + "  " + std::string("csr_ring1sid_2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_2_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_2_);
    r += indent_string + "  " + std::string("csr_ring1sid_3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_3_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_3_);
    r += indent_string + "  " + std::string("csr_ring1sid_4") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_4_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_4_);
    r += indent_string + "  " + std::string("csr_ring1sid_5") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_5_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_5_);
    r += indent_string + "  " + std::string("csr_ring1sid_6") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_6_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_6_);
    r += indent_string + "  " + std::string("csr_ring1sid_7") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_7_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_7_);
    r += indent_string + "  " + std::string("csr_ring1sid_8") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_8_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_8_);
    r += indent_string + "  " + std::string("csr_ring1sid_9") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_9_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_9_);
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
    r += indent_string + std::string("PardeGlueRegRspecCsrRing1intrStatus1") + ":\n";
    r += indent_string + "  " + std::string("csr_ring1sid_0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_0_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_0_);
    r += indent_string + "  " + std::string("csr_ring1sid_1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_1_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_1_);
    r += indent_string + "  " + std::string("csr_ring1sid_2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_2_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_2_);
    r += indent_string + "  " + std::string("csr_ring1sid_3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_3_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_3_);
    r += indent_string + "  " + std::string("csr_ring1sid_4") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_4_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_4_);
    r += indent_string + "  " + std::string("csr_ring1sid_5") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_5_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_5_);
    r += indent_string + "  " + std::string("csr_ring1sid_6") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_6_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_6_);
    r += indent_string + "  " + std::string("csr_ring1sid_7") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_7_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_7_);
    r += indent_string + "  " + std::string("csr_ring1sid_8") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_8_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_8_);
    r += indent_string + "  " + std::string("csr_ring1sid_9") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(csr_ring1sid_9_) ) + "\n";
    all_zeros &= (0 == csr_ring1sid_9_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t csr_ring1sid_0_;
  uint8_t csr_ring1sid_1_;
  uint8_t csr_ring1sid_2_;
  uint8_t csr_ring1sid_3_;
  uint8_t csr_ring1sid_4_;
  uint8_t csr_ring1sid_5_;
  uint8_t csr_ring1sid_6_;
  uint8_t csr_ring1sid_7_;
  uint8_t csr_ring1sid_8_;
  uint8_t csr_ring1sid_9_;
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
    offset += 0x1c; // to get to csr_ring1intr_status1
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PARDE_GLUE_REG_RSPEC_CSR_RING1INTR_STATUS1_H__
