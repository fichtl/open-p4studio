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
#ifndef __REGISTER_INCLUDES_MISC_REGS_INT_STAT_H__
#define __REGISTER_INCLUDES_MISC_REGS_INT_STAT_H__


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

class MiscRegsIntStat : public model_core::RegisterBlock<RegisterCallback> {
public:
  MiscRegsIntStat(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, false, write_callback, read_callback, std::string("MiscRegsIntStat"))
    {
    }
  MiscRegsIntStat(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "MiscRegsIntStat")
    {
    }
public:





  uint8_t &pciephy_lane0_dual_err() { return pciephy_lane0_dual_err_; }





  uint8_t &pciephy_lane1_dual_err() { return pciephy_lane1_dual_err_; }





  uint8_t &pciephy_lane2_dual_err() { return pciephy_lane2_dual_err_; }





  uint8_t &pciephy_lane3_dual_err() { return pciephy_lane3_dual_err_; }





  uint8_t &pciephy_lane0_sngl_err() { return pciephy_lane0_sngl_err_; }





  uint8_t &pciephy_lane1_sngl_err() { return pciephy_lane1_sngl_err_; }





  uint8_t &pciephy_lane2_sngl_err() { return pciephy_lane2_sngl_err_; }





  uint8_t &pciephy_lane3_sngl_err() { return pciephy_lane3_sngl_err_; }





  uint8_t &pciepll_lol_err() { return pciepll_lol_err_; }





  uint8_t &corepll_lol_err() { return corepll_lol_err_; }





  uint8_t &macpll_lol_err() { return macpll_lol_err_; }





  uint8_t &gts_pll_lol_err() { return gts_pll_lol_err_; }





  uint8_t &sbm0_dbe_err() { return sbm0_dbe_err_; }





  uint8_t &sbm1_dbe_err() { return sbm1_dbe_err_; }





  uint8_t &sbm0_sbe_err() { return sbm0_sbe_err_; }





  uint8_t &sbm1_sbe_err() { return sbm1_sbe_err_; }





  uint8_t &sbm0_wr_err() { return sbm0_wr_err_; }





  uint8_t &sbm1_wr_err() { return sbm1_wr_err_; }





  uint8_t &sbm0_rd_err() { return sbm0_rd_err_; }





  uint8_t &sbm1_rd_err() { return sbm1_rd_err_; }





  uint8_t &sbm0_timeout() { return sbm0_timeout_; }





  uint8_t &sbm1_timeout() { return sbm1_timeout_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (pciephy_lane0_dual_err_ & 0x1);
    *data |= ((pciephy_lane1_dual_err_ & 0x1) << 1);
    *data |= ((pciephy_lane2_dual_err_ & 0x1) << 2);
    *data |= ((pciephy_lane3_dual_err_ & 0x1) << 3);
    *data |= ((pciephy_lane0_sngl_err_ & 0x1) << 4);
    *data |= ((pciephy_lane1_sngl_err_ & 0x1) << 5);
    *data |= ((pciephy_lane2_sngl_err_ & 0x1) << 6);
    *data |= ((pciephy_lane3_sngl_err_ & 0x1) << 7);
    *data |= ((pciepll_lol_err_ & 0x1) << 8);
    *data |= ((corepll_lol_err_ & 0x1) << 9);
    *data |= ((macpll_lol_err_ & 0x1) << 10);
    *data |= ((gts_pll_lol_err_ & 0x1) << 11);
    *data |= ((sbm0_dbe_err_ & 0x1) << 12);
    *data |= ((sbm1_dbe_err_ & 0x1) << 13);
    *data |= ((sbm0_sbe_err_ & 0x1) << 14);
    *data |= ((sbm1_sbe_err_ & 0x1) << 15);
    *data |= ((sbm0_wr_err_ & 0x1) << 16);
    *data |= ((sbm1_wr_err_ & 0x1) << 17);
    *data |= ((sbm0_rd_err_ & 0x1) << 18);
    *data |= ((sbm1_rd_err_ & 0x1) << 19);
    *data |= ((sbm0_timeout_ & 0x1) << 20);
    *data |= ((sbm1_timeout_ & 0x1) << 21);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    pciephy_lane0_dual_err_ &= ~(data & 0x1);
    pciephy_lane1_dual_err_ &= ~((data >> 1) & 0x1);
    pciephy_lane2_dual_err_ &= ~((data >> 2) & 0x1);
    pciephy_lane3_dual_err_ &= ~((data >> 3) & 0x1);
    pciephy_lane0_sngl_err_ &= ~((data >> 4) & 0x1);
    pciephy_lane1_sngl_err_ &= ~((data >> 5) & 0x1);
    pciephy_lane2_sngl_err_ &= ~((data >> 6) & 0x1);
    pciephy_lane3_sngl_err_ &= ~((data >> 7) & 0x1);
    pciepll_lol_err_ &= ~((data >> 8) & 0x1);
    corepll_lol_err_ &= ~((data >> 9) & 0x1);
    macpll_lol_err_ &= ~((data >> 10) & 0x1);
    gts_pll_lol_err_ &= ~((data >> 11) & 0x1);
    sbm0_dbe_err_ &= ~((data >> 12) & 0x1);
    sbm1_dbe_err_ &= ~((data >> 13) & 0x1);
    sbm0_sbe_err_ &= ~((data >> 14) & 0x1);
    sbm1_sbe_err_ &= ~((data >> 15) & 0x1);
    sbm0_wr_err_ &= ~((data >> 16) & 0x1);
    sbm1_wr_err_ &= ~((data >> 17) & 0x1);
    sbm0_rd_err_ &= ~((data >> 18) & 0x1);
    sbm1_rd_err_ &= ~((data >> 19) & 0x1);
    sbm0_timeout_ &= ~((data >> 20) & 0x1);
    sbm1_timeout_ &= ~((data >> 21) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    pciephy_lane0_dual_err_ = 0x0;
    pciephy_lane1_dual_err_ = 0x0;
    pciephy_lane2_dual_err_ = 0x0;
    pciephy_lane3_dual_err_ = 0x0;
    pciephy_lane0_sngl_err_ = 0x0;
    pciephy_lane1_sngl_err_ = 0x0;
    pciephy_lane2_sngl_err_ = 0x0;
    pciephy_lane3_sngl_err_ = 0x0;
    pciepll_lol_err_ = 0x0;
    corepll_lol_err_ = 0x0;
    macpll_lol_err_ = 0x0;
    gts_pll_lol_err_ = 0x0;
    sbm0_dbe_err_ = 0x0;
    sbm1_dbe_err_ = 0x0;
    sbm0_sbe_err_ = 0x0;
    sbm1_sbe_err_ = 0x0;
    sbm0_wr_err_ = 0x0;
    sbm1_wr_err_ = 0x0;
    sbm0_rd_err_ = 0x0;
    sbm1_rd_err_ = 0x0;
    sbm0_timeout_ = 0x0;
    sbm1_timeout_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("MiscRegsIntStat") + ":\n";
    r += indent_string + "  " + std::string("pciephy_lane0_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane0_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane0_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane1_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane1_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane1_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane2_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane2_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane2_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane3_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane3_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane3_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane0_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane0_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane0_sngl_err_);
    r += indent_string + "  " + std::string("pciephy_lane1_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane1_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane1_sngl_err_);
    r += indent_string + "  " + std::string("pciephy_lane2_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane2_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane2_sngl_err_);
    r += indent_string + "  " + std::string("pciephy_lane3_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane3_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane3_sngl_err_);
    r += indent_string + "  " + std::string("pciepll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciepll_lol_err_) ) + "\n";
    all_zeros &= (0 == pciepll_lol_err_);
    r += indent_string + "  " + std::string("corepll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(corepll_lol_err_) ) + "\n";
    all_zeros &= (0 == corepll_lol_err_);
    r += indent_string + "  " + std::string("macpll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(macpll_lol_err_) ) + "\n";
    all_zeros &= (0 == macpll_lol_err_);
    r += indent_string + "  " + std::string("gts_pll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gts_pll_lol_err_) ) + "\n";
    all_zeros &= (0 == gts_pll_lol_err_);
    r += indent_string + "  " + std::string("sbm0_dbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_dbe_err_) ) + "\n";
    all_zeros &= (0 == sbm0_dbe_err_);
    r += indent_string + "  " + std::string("sbm1_dbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_dbe_err_) ) + "\n";
    all_zeros &= (0 == sbm1_dbe_err_);
    r += indent_string + "  " + std::string("sbm0_sbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_sbe_err_) ) + "\n";
    all_zeros &= (0 == sbm0_sbe_err_);
    r += indent_string + "  " + std::string("sbm1_sbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_sbe_err_) ) + "\n";
    all_zeros &= (0 == sbm1_sbe_err_);
    r += indent_string + "  " + std::string("sbm0_wr_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_wr_err_) ) + "\n";
    all_zeros &= (0 == sbm0_wr_err_);
    r += indent_string + "  " + std::string("sbm1_wr_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_wr_err_) ) + "\n";
    all_zeros &= (0 == sbm1_wr_err_);
    r += indent_string + "  " + std::string("sbm0_rd_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_rd_err_) ) + "\n";
    all_zeros &= (0 == sbm0_rd_err_);
    r += indent_string + "  " + std::string("sbm1_rd_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_rd_err_) ) + "\n";
    all_zeros &= (0 == sbm1_rd_err_);
    r += indent_string + "  " + std::string("sbm0_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_timeout_) ) + "\n";
    all_zeros &= (0 == sbm0_timeout_);
    r += indent_string + "  " + std::string("sbm1_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_timeout_) ) + "\n";
    all_zeros &= (0 == sbm1_timeout_);
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
    r += indent_string + std::string("MiscRegsIntStat") + ":\n";
    r += indent_string + "  " + std::string("pciephy_lane0_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane0_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane0_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane1_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane1_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane1_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane2_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane2_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane2_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane3_dual_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane3_dual_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane3_dual_err_);
    r += indent_string + "  " + std::string("pciephy_lane0_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane0_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane0_sngl_err_);
    r += indent_string + "  " + std::string("pciephy_lane1_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane1_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane1_sngl_err_);
    r += indent_string + "  " + std::string("pciephy_lane2_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane2_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane2_sngl_err_);
    r += indent_string + "  " + std::string("pciephy_lane3_sngl_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciephy_lane3_sngl_err_) ) + "\n";
    all_zeros &= (0 == pciephy_lane3_sngl_err_);
    r += indent_string + "  " + std::string("pciepll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(pciepll_lol_err_) ) + "\n";
    all_zeros &= (0 == pciepll_lol_err_);
    r += indent_string + "  " + std::string("corepll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(corepll_lol_err_) ) + "\n";
    all_zeros &= (0 == corepll_lol_err_);
    r += indent_string + "  " + std::string("macpll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(macpll_lol_err_) ) + "\n";
    all_zeros &= (0 == macpll_lol_err_);
    r += indent_string + "  " + std::string("gts_pll_lol_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(gts_pll_lol_err_) ) + "\n";
    all_zeros &= (0 == gts_pll_lol_err_);
    r += indent_string + "  " + std::string("sbm0_dbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_dbe_err_) ) + "\n";
    all_zeros &= (0 == sbm0_dbe_err_);
    r += indent_string + "  " + std::string("sbm1_dbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_dbe_err_) ) + "\n";
    all_zeros &= (0 == sbm1_dbe_err_);
    r += indent_string + "  " + std::string("sbm0_sbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_sbe_err_) ) + "\n";
    all_zeros &= (0 == sbm0_sbe_err_);
    r += indent_string + "  " + std::string("sbm1_sbe_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_sbe_err_) ) + "\n";
    all_zeros &= (0 == sbm1_sbe_err_);
    r += indent_string + "  " + std::string("sbm0_wr_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_wr_err_) ) + "\n";
    all_zeros &= (0 == sbm0_wr_err_);
    r += indent_string + "  " + std::string("sbm1_wr_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_wr_err_) ) + "\n";
    all_zeros &= (0 == sbm1_wr_err_);
    r += indent_string + "  " + std::string("sbm0_rd_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_rd_err_) ) + "\n";
    all_zeros &= (0 == sbm0_rd_err_);
    r += indent_string + "  " + std::string("sbm1_rd_err") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_rd_err_) ) + "\n";
    all_zeros &= (0 == sbm1_rd_err_);
    r += indent_string + "  " + std::string("sbm0_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm0_timeout_) ) + "\n";
    all_zeros &= (0 == sbm0_timeout_);
    r += indent_string + "  " + std::string("sbm1_timeout") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(sbm1_timeout_) ) + "\n";
    all_zeros &= (0 == sbm1_timeout_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t pciephy_lane0_dual_err_;
  uint8_t pciephy_lane1_dual_err_;
  uint8_t pciephy_lane2_dual_err_;
  uint8_t pciephy_lane3_dual_err_;
  uint8_t pciephy_lane0_sngl_err_;
  uint8_t pciephy_lane1_sngl_err_;
  uint8_t pciephy_lane2_sngl_err_;
  uint8_t pciephy_lane3_sngl_err_;
  uint8_t pciepll_lol_err_;
  uint8_t corepll_lol_err_;
  uint8_t macpll_lol_err_;
  uint8_t gts_pll_lol_err_;
  uint8_t sbm0_dbe_err_;
  uint8_t sbm1_dbe_err_;
  uint8_t sbm0_sbe_err_;
  uint8_t sbm1_sbe_err_;
  uint8_t sbm0_wr_err_;
  uint8_t sbm1_wr_err_;
  uint8_t sbm0_rd_err_;
  uint8_t sbm1_rd_err_;
  uint8_t sbm0_timeout_;
  uint8_t sbm1_timeout_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x40000; // to get to misc_regs
    offset += 0xa0; // to get to int_stat
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_MISC_REGS_INT_STAT_H__
