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
#ifndef __REGISTER_INCLUDES_PCIE_BAR01_REGS_SRAM_ECC_MUTABLE_H__
#define __REGISTER_INCLUDES_PCIE_BAR01_REGS_SRAM_ECC_MUTABLE_H__


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

class PcieBar01RegsSramEccMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PcieBar01RegsSramEccMutable(
      int chipNumber, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 4, true, write_callback, read_callback, std::string("PcieBar01RegsSramEccMutable"))
    {
    }
  PcieBar01RegsSramEccMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PcieBar01RegsSramEccMutable")
    {
    }
public:




  uint8_t rxreqbuf_disable_check() { return rxreqbuf_disable_check_; }
  void rxreqbuf_disable_check(const uint8_t &v) { rxreqbuf_disable_check_=v; }




  uint8_t rxreqbuf_inject_sbe() { return rxreqbuf_inject_sbe_; }
  void rxreqbuf_inject_sbe(const uint8_t &v) { rxreqbuf_inject_sbe_=v; }




  uint8_t rxreqbuf_inject_mbe() { return rxreqbuf_inject_mbe_; }
  void rxreqbuf_inject_mbe(const uint8_t &v) { rxreqbuf_inject_mbe_=v; }




  uint8_t rxcplbuf_disable_check() { return rxcplbuf_disable_check_; }
  void rxcplbuf_disable_check(const uint8_t &v) { rxcplbuf_disable_check_=v; }




  uint8_t rxcplbuf_inject_sbe() { return rxcplbuf_inject_sbe_; }
  void rxcplbuf_inject_sbe(const uint8_t &v) { rxcplbuf_inject_sbe_=v; }




  uint8_t rxcplbuf_inject_mbe() { return rxcplbuf_inject_mbe_; }
  void rxcplbuf_inject_mbe(const uint8_t &v) { rxcplbuf_inject_mbe_=v; }




  uint8_t txbuf_disable_check() { return txbuf_disable_check_; }
  void txbuf_disable_check(const uint8_t &v) { txbuf_disable_check_=v; }




  uint8_t txbuf_inject_sbe() { return txbuf_inject_sbe_; }
  void txbuf_inject_sbe(const uint8_t &v) { txbuf_inject_sbe_=v; }




  uint8_t txbuf_inject_mbe() { return txbuf_inject_mbe_; }
  void txbuf_inject_mbe(const uint8_t &v) { txbuf_inject_mbe_=v; }




  uint8_t msix_disable_check() { return msix_disable_check_; }
  void msix_disable_check(const uint8_t &v) { msix_disable_check_=v; }




  uint8_t msix_inject_sbe() { return msix_inject_sbe_; }
  void msix_inject_sbe(const uint8_t &v) { msix_inject_sbe_=v; }




  uint8_t msix_inject_mbe() { return msix_inject_mbe_; }
  void msix_inject_mbe(const uint8_t &v) { msix_inject_mbe_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (rxreqbuf_disable_check_ & 0x1);
    *data |= ((rxreqbuf_inject_sbe_ & 0x1) << 1);
    *data |= ((rxreqbuf_inject_mbe_ & 0x1) << 2);
    *data |= ((rxcplbuf_disable_check_ & 0x1) << 4);
    *data |= ((rxcplbuf_inject_sbe_ & 0x1) << 5);
    *data |= ((rxcplbuf_inject_mbe_ & 0x1) << 6);
    *data |= ((txbuf_disable_check_ & 0x1) << 8);
    *data |= ((txbuf_inject_sbe_ & 0x1) << 9);
    *data |= ((txbuf_inject_mbe_ & 0x1) << 10);
    *data |= ((msix_disable_check_ & 0x1) << 12);
    *data |= ((msix_inject_sbe_ & 0x1) << 13);
    *data |= ((msix_inject_mbe_ & 0x1) << 14);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    rxreqbuf_disable_check_ = (data & 0x1);
    rxreqbuf_inject_sbe_ = ((data >> 1) & 0x1);
    rxreqbuf_inject_mbe_ = ((data >> 2) & 0x1);
    rxcplbuf_disable_check_ = ((data >> 4) & 0x1);
    rxcplbuf_inject_sbe_ = ((data >> 5) & 0x1);
    rxcplbuf_inject_mbe_ = ((data >> 6) & 0x1);
    txbuf_disable_check_ = ((data >> 8) & 0x1);
    txbuf_inject_sbe_ = ((data >> 9) & 0x1);
    txbuf_inject_mbe_ = ((data >> 10) & 0x1);
    msix_disable_check_ = ((data >> 12) & 0x1);
    msix_inject_sbe_ = ((data >> 13) & 0x1);
    msix_inject_mbe_ = ((data >> 14) & 0x1);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    rxreqbuf_disable_check_ = 0x0;
    rxreqbuf_inject_sbe_ = 0x0;
    rxreqbuf_inject_mbe_ = 0x0;
    rxcplbuf_disable_check_ = 0x0;
    rxcplbuf_inject_sbe_ = 0x0;
    rxcplbuf_inject_mbe_ = 0x0;
    txbuf_disable_check_ = 0x0;
    txbuf_inject_sbe_ = 0x0;
    txbuf_inject_mbe_ = 0x0;
    msix_disable_check_ = 0x0;
    msix_inject_sbe_ = 0x0;
    msix_inject_mbe_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PcieBar01RegsSramEccMutable") + ":\n";
    r += indent_string + "  " + std::string("rxreqbuf_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxreqbuf_disable_check_) ) + "\n";
    all_zeros &= (0 == rxreqbuf_disable_check_);
    r += indent_string + "  " + std::string("rxreqbuf_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxreqbuf_inject_sbe_) ) + "\n";
    all_zeros &= (0 == rxreqbuf_inject_sbe_);
    r += indent_string + "  " + std::string("rxreqbuf_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxreqbuf_inject_mbe_) ) + "\n";
    all_zeros &= (0 == rxreqbuf_inject_mbe_);
    r += indent_string + "  " + std::string("rxcplbuf_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxcplbuf_disable_check_) ) + "\n";
    all_zeros &= (0 == rxcplbuf_disable_check_);
    r += indent_string + "  " + std::string("rxcplbuf_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxcplbuf_inject_sbe_) ) + "\n";
    all_zeros &= (0 == rxcplbuf_inject_sbe_);
    r += indent_string + "  " + std::string("rxcplbuf_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxcplbuf_inject_mbe_) ) + "\n";
    all_zeros &= (0 == rxcplbuf_inject_mbe_);
    r += indent_string + "  " + std::string("txbuf_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(txbuf_disable_check_) ) + "\n";
    all_zeros &= (0 == txbuf_disable_check_);
    r += indent_string + "  " + std::string("txbuf_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(txbuf_inject_sbe_) ) + "\n";
    all_zeros &= (0 == txbuf_inject_sbe_);
    r += indent_string + "  " + std::string("txbuf_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(txbuf_inject_mbe_) ) + "\n";
    all_zeros &= (0 == txbuf_inject_mbe_);
    r += indent_string + "  " + std::string("msix_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(msix_disable_check_) ) + "\n";
    all_zeros &= (0 == msix_disable_check_);
    r += indent_string + "  " + std::string("msix_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(msix_inject_sbe_) ) + "\n";
    all_zeros &= (0 == msix_inject_sbe_);
    r += indent_string + "  " + std::string("msix_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(msix_inject_mbe_) ) + "\n";
    all_zeros &= (0 == msix_inject_mbe_);
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
    r += indent_string + std::string("PcieBar01RegsSramEccMutable") + ":\n";
    r += indent_string + "  " + std::string("rxreqbuf_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxreqbuf_disable_check_) ) + "\n";
    all_zeros &= (0 == rxreqbuf_disable_check_);
    r += indent_string + "  " + std::string("rxreqbuf_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxreqbuf_inject_sbe_) ) + "\n";
    all_zeros &= (0 == rxreqbuf_inject_sbe_);
    r += indent_string + "  " + std::string("rxreqbuf_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxreqbuf_inject_mbe_) ) + "\n";
    all_zeros &= (0 == rxreqbuf_inject_mbe_);
    r += indent_string + "  " + std::string("rxcplbuf_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxcplbuf_disable_check_) ) + "\n";
    all_zeros &= (0 == rxcplbuf_disable_check_);
    r += indent_string + "  " + std::string("rxcplbuf_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxcplbuf_inject_sbe_) ) + "\n";
    all_zeros &= (0 == rxcplbuf_inject_sbe_);
    r += indent_string + "  " + std::string("rxcplbuf_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(rxcplbuf_inject_mbe_) ) + "\n";
    all_zeros &= (0 == rxcplbuf_inject_mbe_);
    r += indent_string + "  " + std::string("txbuf_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(txbuf_disable_check_) ) + "\n";
    all_zeros &= (0 == txbuf_disable_check_);
    r += indent_string + "  " + std::string("txbuf_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(txbuf_inject_sbe_) ) + "\n";
    all_zeros &= (0 == txbuf_inject_sbe_);
    r += indent_string + "  " + std::string("txbuf_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(txbuf_inject_mbe_) ) + "\n";
    all_zeros &= (0 == txbuf_inject_mbe_);
    r += indent_string + "  " + std::string("msix_disable_check") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(msix_disable_check_) ) + "\n";
    all_zeros &= (0 == msix_disable_check_);
    r += indent_string + "  " + std::string("msix_inject_sbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(msix_inject_sbe_) ) + "\n";
    all_zeros &= (0 == msix_inject_sbe_);
    r += indent_string + "  " + std::string("msix_inject_mbe") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(msix_inject_mbe_) ) + "\n";
    all_zeros &= (0 == msix_inject_mbe_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t rxreqbuf_disable_check_;
  uint8_t rxreqbuf_inject_sbe_;
  uint8_t rxreqbuf_inject_mbe_;
  uint8_t rxcplbuf_disable_check_;
  uint8_t rxcplbuf_inject_sbe_;
  uint8_t rxcplbuf_inject_mbe_;
  uint8_t txbuf_disable_check_;
  uint8_t txbuf_inject_sbe_;
  uint8_t txbuf_inject_mbe_;
  uint8_t msix_disable_check_;
  uint8_t msix_inject_sbe_;
  uint8_t msix_inject_mbe_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x154; // to get to sram_ecc
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_PCIE_BAR01_REGS_SRAM_ECC_MUTABLE_H__
