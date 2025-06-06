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
#ifndef __REGISTER_INCLUDES_MISC_REGS_PCIEPHY_SIDE_CNTL_ARRAY_MUTABLE_H__
#define __REGISTER_INCLUDES_MISC_REGS_PCIEPHY_SIDE_CNTL_ARRAY_MUTABLE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>











#include "misc_regs_pciephy_side_cntl_mutable.h"

namespace tofinoB0 {
  namespace register_classes {

class MiscRegsPciephySideCntlArrayMutable : public model_core::RegisterBlock<RegisterArrayCallback> {
public:
  MiscRegsPciephySideCntlArrayMutable(
      int chipNumber, RegisterArrayCallback& write_callback = 0, RegisterArrayCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4 * ArraySize(-1), true, write_callback, read_callback, std::string("MiscRegsPciephySideCntlArrayMutable")),
    array(RealArraySize(-1)),
    size0_(ArraySize(0)),
    real_size0_(RealArraySize(0))
    {
    }
public:





  uint16_t core_to_cntl(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].core_to_cntl();
  }
  void core_to_cntl(uint32_t a0,const uint16_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].core_to_cntl(v);
  }





  uint8_t fts_align_en(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].fts_align_en();
  }
  void fts_align_en(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].fts_align_en(v);
  }





  uint8_t rx_8b10b_realign_en(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].rx_8b10b_realign_en();
  }
  void rx_8b10b_realign_en(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].rx_8b10b_realign_en(v);
  }





  uint8_t sris_enable(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].sris_enable();
  }
  void sris_enable(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].sris_enable(v);
  }





  uint8_t tx_refclk_sync_in(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].tx_refclk_sync_in();
  }
  void tx_refclk_sync_in(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].tx_refclk_sync_in(v);
  }





  uint8_t bypass(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].bypass();
  }
  void bypass(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].bypass(v);
  }





  uint8_t pcie_tx_elec_idle(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pcie_tx_elec_idle();
  }
  void pcie_tx_elec_idle(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].pcie_tx_elec_idle(v);
  }





  uint8_t pcie_tx_override_in(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pcie_tx_override_in();
  }
  void pcie_tx_override_in(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].pcie_tx_override_in(v);
  }





  uint8_t pcie_tx_phase_beacon(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pcie_tx_phase_beacon();
  }
  void pcie_tx_phase_beacon(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].pcie_tx_phase_beacon(v);
  }








  uint8_t pcie_rev_lpbk_auto(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pcie_rev_lpbk_auto();
  }
  void pcie_rev_lpbk_auto(uint32_t a0,const uint8_t &v) 
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    array[a0].pcie_rev_lpbk_auto(v);
  }
  bool calculate_index(
      uint32_t* offset, uint32_t* a0
      ) const {
    int i = (*offset)/4;
    (*offset) -= (i*4);
    uint32_t t = i;
    *a0 = t;
    bool in_bounds = true;
    in_bounds &= CheckArrayBounds(*a0,real_size0_,size0_,*offset,0,true);
    return in_bounds;
  }


  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    uint32_t a0;
     if (!calculate_index(&offset,&a0)) return true;
    if (read_callback_) read_callback_(a0);
    array[a0].read(offset,data);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    uint32_t a0;
     if (!calculate_index(&offset,&a0)) return true;
    array[a0].write(offset,data);
    if (write_callback_) write_callback_(a0);
    return true;
  }

  void reset(
      
      ) {
    for (uint32_t i=0;i<array.size();++i) {
      array[i].reset();
      int t = i;
      int a0 = t;
      if (write_callback_) write_callback_(a0);
    }
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    uint32_t a0;
     if (!calculate_index(&offset,&a0)) return "OUT_OF_BOUNDS";
    std::string r_s = array[a0].to_string(print_zeros,indent_string+"  ");
    if (! r_s.empty()) {
      r += indent_string + std::string("MiscRegsPciephySideCntlArrayMutable") + "["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
    }
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
    all_zeros=false;
    for (uint32_t a0=0;a0<real_size0_;++a0) {
      std::string r_s = array[a0].to_string(print_zeros,indent_string+"  ");
      if (! r_s.empty()) {
        r += indent_string + std::string("MiscRegsPciephySideCntlArrayMutable") + "["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
      }
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::vector<MiscRegsPciephySideCntlMutable> array;
  uint32_t size0_;
  uint32_t real_size0_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x40000; // to get to misc_regs
    offset += 0x70; // to get to pciephy_side_cntl
    return offset;
  }

  static int ArraySize(
      int dimension
      ) {
    switch (dimension) {
      case -1:
        return 4;
        break;
      case 0:
        return 4;
        break;
      default:
        assert(0);
        break;
    }
  }

  static int RealArraySize(
      int dimension
      ) {
    switch (dimension) {
      case -1:
        return 4;
        break;
      case 0:
        return 4;
        break;
      default:
        assert(0);
        break;
    }
  }

};










  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_MISC_REGS_PCIEPHY_SIDE_CNTL_ARRAY_MUTABLE_H__
