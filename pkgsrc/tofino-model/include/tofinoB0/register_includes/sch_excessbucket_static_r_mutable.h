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
#ifndef __REGISTER_INCLUDES_SCH_EXCESSBUCKET_STATIC_R_MUTABLE_H__
#define __REGISTER_INCLUDES_SCH_EXCESSBUCKET_STATIC_R_MUTABLE_H__


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

class SchExcessbucketStaticRMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  SchExcessbucketStaticRMutable(
      int chipNumber, int index_tm_sch_pipe_rspec, int index_sch_excessbucket_static_r, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_sch_pipe_rspec, index_sch_excessbucket_static_r), 4, true, write_callback, read_callback, std::string("SchExcessbucketStaticRMutable")+":"+boost::lexical_cast<std::string>(index_tm_sch_pipe_rspec) + "," + boost::lexical_cast<std::string>(index_sch_excessbucket_static_r))
    {
    }
  SchExcessbucketStaticRMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "SchExcessbucketStaticRMutable")
    {
    }
public:





  uint8_t pps() { return pps_; }
  void pps(const uint8_t &v) { pps_=v; }






  uint16_t wt() { return wt_; }
  void wt(const uint16_t &v) { wt_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (pps_ & 0x1);
    *data |= ((wt_ & 0x3ff) << 1);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    pps_ = (data & 0x1);
    wt_ = ((data >> 1) & 0x3ff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    pps_ = 0x0;
    wt_ = 0x1;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("SchExcessbucketStaticRMutable") + ":\n";
    r += indent_string + "  " + std::string("pps") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pps_) ) + "\n";
    all_zeros &= (0 == pps_);
    r += indent_string + "  " + std::string("wt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wt_) ) + "\n";
    all_zeros &= (0 == wt_);
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
    r += indent_string + std::string("SchExcessbucketStaticRMutable") + ":\n";
    r += indent_string + "  " + std::string("pps") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pps_) ) + "\n";
    all_zeros &= (0 == pps_);
    r += indent_string + "  " + std::string("wt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(wt_) ) + "\n";
    all_zeros &= (0 == wt_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t pps_;
  uint16_t wt_;
private:
  static int StartOffset(
      int index_tm_sch_pipe_rspec, int index_sch_excessbucket_static_r
      ) {
    int offset=0;
    offset += 0x400000; // to get to tm_top
    offset += 0xc0000; // to get to tm_sch_top
    assert(index_tm_sch_pipe_rspec < 4);
    offset += index_tm_sch_pipe_rspec * 0x10000; // tm_sch_pipe_rspec[]
    offset += 0x7000; // to get to q_exc_static_mem
    assert(index_sch_excessbucket_static_r < 576);
    offset += index_sch_excessbucket_static_r * 0x4; // sch_excessbucket_static_r[]
    return offset;
  }

};












  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_SCH_EXCESSBUCKET_STATIC_R_MUTABLE_H__
