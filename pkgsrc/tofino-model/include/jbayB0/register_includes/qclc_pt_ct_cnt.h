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
#ifndef __REGISTER_INCLUDES_QCLC_PT_CT_CNT_H__
#define __REGISTER_INCLUDES_QCLC_PT_CT_CNT_H__


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

class QclcPtCtCnt : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum TmClcCommonRspecEnum {
    kQclcPtCtCntPipe0,
    kQclcPtCtCntPipe1,
    kQclcPtCtCntPipe2,
    kQclcPtCtCntPipe3
  };
public:
  QclcPtCtCnt(
      int chipNumber, TmClcCommonRspecEnum selector_tm_clc_common_rspec, int index_qclc_pt_ct_cnt, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_tm_clc_common_rspec, index_qclc_pt_ct_cnt), 4, false, write_callback, read_callback, std::string("QclcPtCtCnt")+":"+boost::lexical_cast<std::string>(selector_tm_clc_common_rspec) + "," + boost::lexical_cast<std::string>(index_qclc_pt_ct_cnt))
    {
    }
  QclcPtCtCnt(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "QclcPtCtCnt")
    {
    }
public:





  uint8_t &cnt0() { return cnt0_; }





  uint8_t &cnt1() { return cnt1_; }





  uint8_t &cnt2() { return cnt2_; }





  uint8_t &cnt3() { return cnt3_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = cnt0_;
    *data |= (cnt1_ << 8);
    *data |= (cnt2_ << 16);
    *data |= (cnt3_ << 24);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    cnt0_ = data;
    cnt1_ = (data >> 8);
    cnt2_ = (data >> 16);
    cnt3_ = (data >> 24);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    cnt0_ = 0x0;
    cnt1_ = 0x0;
    cnt2_ = 0x0;
    cnt3_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("QclcPtCtCnt") + ":\n";
    r += indent_string + "  " + std::string("cnt0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt0_) ) + "\n";
    all_zeros &= (0 == cnt0_);
    r += indent_string + "  " + std::string("cnt1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt1_) ) + "\n";
    all_zeros &= (0 == cnt1_);
    r += indent_string + "  " + std::string("cnt2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt2_) ) + "\n";
    all_zeros &= (0 == cnt2_);
    r += indent_string + "  " + std::string("cnt3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt3_) ) + "\n";
    all_zeros &= (0 == cnt3_);
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
    r += indent_string + std::string("QclcPtCtCnt") + ":\n";
    r += indent_string + "  " + std::string("cnt0") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt0_) ) + "\n";
    all_zeros &= (0 == cnt0_);
    r += indent_string + "  " + std::string("cnt1") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt1_) ) + "\n";
    all_zeros &= (0 == cnt1_);
    r += indent_string + "  " + std::string("cnt2") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt2_) ) + "\n";
    all_zeros &= (0 == cnt2_);
    r += indent_string + "  " + std::string("cnt3") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt3_) ) + "\n";
    all_zeros &= (0 == cnt3_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t cnt0_;
  uint8_t cnt1_;
  uint8_t cnt2_;
  uint8_t cnt3_;
private:
  static int StartOffset(
      TmClcCommonRspecEnum selector_tm_clc_common_rspec, int index_qclc_pt_ct_cnt
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x280000; // to get to tm_clc_top
    offset += 0x20000; // to get to clc_common
    switch (selector_tm_clc_common_rspec) {
      case kQclcPtCtCntPipe0:
        offset += 0x80; // to get to qclc_pt_ct_cnt_pipe0
        assert(index_qclc_pt_ct_cnt < 18);
        offset += index_qclc_pt_ct_cnt * 0x4; // qclc_pt_ct_cnt[]
        break;
      case kQclcPtCtCntPipe1:
        offset += 0x100; // to get to qclc_pt_ct_cnt_pipe1
        assert(index_qclc_pt_ct_cnt < 18);
        offset += index_qclc_pt_ct_cnt * 0x4; // qclc_pt_ct_cnt[]
        break;
      case kQclcPtCtCntPipe2:
        offset += 0x180; // to get to qclc_pt_ct_cnt_pipe2
        assert(index_qclc_pt_ct_cnt < 18);
        offset += index_qclc_pt_ct_cnt * 0x4; // qclc_pt_ct_cnt[]
        break;
      case kQclcPtCtCntPipe3:
        offset += 0x200; // to get to qclc_pt_ct_cnt_pipe3
        assert(index_qclc_pt_ct_cnt < 18);
        offset += index_qclc_pt_ct_cnt * 0x4; // qclc_pt_ct_cnt[]
        break;
      default:
        assert(0);
        break;
    }
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_QCLC_PT_CT_CNT_H__
