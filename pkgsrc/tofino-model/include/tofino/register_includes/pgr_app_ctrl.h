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
#ifndef __REGISTER_INCLUDES_PGR_APP_CTRL_H__
#define __REGISTER_INCLUDES_PGR_APP_CTRL_H__


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

class PgrAppCtrl : public model_core::RegisterBlock<RegisterCallback> {
public:
  PgrAppCtrl(
      int chipNumber, int index_pipe_addrmap, int index_party_pgr_app_reg_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_party_pgr_app_reg_rspec), 4, false, write_callback, read_callback, std::string("PgrAppCtrl")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_party_pgr_app_reg_rspec))
    {
    }
  PgrAppCtrl(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PgrAppCtrl")
    {
    }
public:






  uint8_t &app_en() { return app_en_; }





  uint8_t &app_type() { return app_type_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (app_en_ & 0x1);
    *data |= ((app_type_ & 0x3) << 1);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    app_en_ = (data & 0x1);
    app_type_ = ((data >> 1) & 0x3);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    app_en_ = 0x0;
    app_type_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PgrAppCtrl") + ":\n";
    r += indent_string + "  " + std::string("app_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(app_en_) ) + "\n";
    all_zeros &= (0 == app_en_);
    r += indent_string + "  " + std::string("app_type") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(app_type_) ) + "\n";
    all_zeros &= (0 == app_type_);
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
    r += indent_string + std::string("PgrAppCtrl") + ":\n";
    r += indent_string + "  " + std::string("app_en") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(app_en_) ) + "\n";
    all_zeros &= (0 == app_en_);
    r += indent_string + "  " + std::string("app_type") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(app_type_) ) + "\n";
    all_zeros &= (0 == app_type_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint8_t app_en_;
  uint8_t app_type_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_party_pgr_app_reg_rspec
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    offset += 0x700000; // to get to pmarb
    offset += 0x3c000; // to get to pgr_reg
    assert(index_party_pgr_app_reg_rspec < 8);
    offset += index_party_pgr_app_reg_rspec * 0x200; // party_pgr_app_reg_rspec[]
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace tofino

#endif // __REGISTER_INCLUDES_PGR_APP_CTRL_H__
