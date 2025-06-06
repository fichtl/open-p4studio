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
#ifndef __REGISTER_INCLUDES_GFM_PARITY_ERROR_CTL_MUTABLE_H__
#define __REGISTER_INCLUDES_GFM_PARITY_ERROR_CTL_MUTABLE_H__


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

class GfmParityErrorCtlMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  GfmParityErrorCtlMutable(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_gfm_parity_error_ctl, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_gfm_parity_error_ctl), 4, true, write_callback, read_callback, std::string("GfmParityErrorCtlMutable")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_gfm_parity_error_ctl))
    {
    }
  GfmParityErrorCtlMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "GfmParityErrorCtlMutable")
    {
    }
public:



  uint8_t gfm_parity_error_ctl_o_err_en() { return gfm_parity_error_ctl_o_err_en_; }
  void gfm_parity_error_ctl_o_err_en(const uint8_t &v) { gfm_parity_error_ctl_o_err_en_=v; }



  uint8_t gfm_parity_error_ctl_idata_ovr() { return gfm_parity_error_ctl_idata_ovr_; }
  void gfm_parity_error_ctl_idata_ovr(const uint8_t &v) { gfm_parity_error_ctl_idata_ovr_=v; }



  uint8_t gfm_parity_error_ctl_dis_pred() { return gfm_parity_error_ctl_dis_pred_; }
  void gfm_parity_error_ctl_dis_pred(const uint8_t &v) { gfm_parity_error_ctl_dis_pred_=v; }


  uint8_t gfm_parity_error_ctl_delay() { return gfm_parity_error_ctl_delay_; }
  void gfm_parity_error_ctl_delay(const uint8_t &v) { gfm_parity_error_ctl_delay_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (gfm_parity_error_ctl_o_err_en_ & 0x1);
    *data |= ((gfm_parity_error_ctl_idata_ovr_ & 0x1) << 1);
    *data |= ((gfm_parity_error_ctl_dis_pred_ & 0x1) << 2);
    *data |= ((gfm_parity_error_ctl_delay_ & 0x1) << 3);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    gfm_parity_error_ctl_o_err_en_ = (data & 0x1);
    gfm_parity_error_ctl_idata_ovr_ = ((data >> 1) & 0x1);
    gfm_parity_error_ctl_dis_pred_ = ((data >> 2) & 0x1);
    gfm_parity_error_ctl_delay_ = ((data >> 3) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    gfm_parity_error_ctl_o_err_en_ = 0x0;
    gfm_parity_error_ctl_idata_ovr_ = 0x0;
    gfm_parity_error_ctl_dis_pred_ = 0x0;
    gfm_parity_error_ctl_delay_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("GfmParityErrorCtlMutable") + ":\n";
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_o_err_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_o_err_en_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_o_err_en_);
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_idata_ovr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_idata_ovr_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_idata_ovr_);
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_dis_pred") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_dis_pred_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_dis_pred_);
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_delay") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_delay_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_delay_);
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
    r += indent_string + std::string("GfmParityErrorCtlMutable") + ":\n";
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_o_err_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_o_err_en_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_o_err_en_);
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_idata_ovr") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_idata_ovr_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_idata_ovr_);
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_dis_pred") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_dis_pred_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_dis_pred_);
    r += indent_string + "  " + std::string("gfm_parity_error_ctl_delay") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gfm_parity_error_ctl_delay_) ) + "\n";
    all_zeros &= (0 == gfm_parity_error_ctl_delay_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t gfm_parity_error_ctl_o_err_en_;
  uint8_t gfm_parity_error_ctl_idata_ovr_;
  uint8_t gfm_parity_error_ctl_dis_pred_;
  uint8_t gfm_parity_error_ctl_delay_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_gfm_parity_error_ctl
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x18000; // to get to match
    offset += 0x4000; // to get to merge
    offset += 0x3218; // to get to gfm_parity_error_ctl
    assert(index_gfm_parity_error_ctl < 2);
    offset += index_gfm_parity_error_ctl * 0x4; // gfm_parity_error_ctl[]
    return offset;
  }

};










  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_GFM_PARITY_ERROR_CTL_MUTABLE_H__
