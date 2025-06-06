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
#ifndef __REGISTER_INCLUDES_PGR_CFG_APP_RECIRC_PORT_SRC_H__
#define __REGISTER_INCLUDES_PGR_CFG_APP_RECIRC_PORT_SRC_H__


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

class PgrCfgAppRecircPortSrc : public model_core::RegisterBlock<RegisterCallback> {
public:
  PgrCfgAppRecircPortSrc(
      int chipNumber, int index_pipe_addrmap, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap), 4, false, write_callback, read_callback, std::string("PgrCfgAppRecircPortSrc")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap))
    {
    }
  PgrCfgAppRecircPortSrc(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "PgrCfgAppRecircPortSrc")
    {
    }
public:








  uint8_t &app_recirc_src(int j0) { return app_recirc_src_[j0]; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (app_recirc_src_[0] & 0x3);
    *data |= ((app_recirc_src_[1] & 0x3) << 2);
    *data |= ((app_recirc_src_[2] & 0x3) << 4);
    *data |= ((app_recirc_src_[3] & 0x3) << 6);
    *data |= ((app_recirc_src_[4] & 0x3) << 8);
    *data |= ((app_recirc_src_[5] & 0x3) << 10);
    *data |= ((app_recirc_src_[6] & 0x3) << 12);
    *data |= ((app_recirc_src_[7] & 0x3) << 14);
    *data |= ((app_recirc_src_[8] & 0x3) << 16);
    *data |= ((app_recirc_src_[9] & 0x3) << 18);
    *data |= ((app_recirc_src_[10] & 0x3) << 20);
    *data |= ((app_recirc_src_[11] & 0x3) << 22);
    *data |= ((app_recirc_src_[12] & 0x3) << 24);
    *data |= ((app_recirc_src_[13] & 0x3) << 26);
    *data |= ((app_recirc_src_[14] & 0x3) << 28);
    *data |= ((app_recirc_src_[15] & 0x3) << 30);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    app_recirc_src_[0] = (data & 0x3);
    app_recirc_src_[1] = ((data >> 2) & 0x3);
    app_recirc_src_[2] = ((data >> 4) & 0x3);
    app_recirc_src_[3] = ((data >> 6) & 0x3);
    app_recirc_src_[4] = ((data >> 8) & 0x3);
    app_recirc_src_[5] = ((data >> 10) & 0x3);
    app_recirc_src_[6] = ((data >> 12) & 0x3);
    app_recirc_src_[7] = ((data >> 14) & 0x3);
    app_recirc_src_[8] = ((data >> 16) & 0x3);
    app_recirc_src_[9] = ((data >> 18) & 0x3);
    app_recirc_src_[10] = ((data >> 20) & 0x3);
    app_recirc_src_[11] = ((data >> 22) & 0x3);
    app_recirc_src_[12] = ((data >> 24) & 0x3);
    app_recirc_src_[13] = ((data >> 26) & 0x3);
    app_recirc_src_[14] = ((data >> 28) & 0x3);
    app_recirc_src_[15] = ((data >> 30) & 0x3);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    app_recirc_src_[0] = 0x0;
    app_recirc_src_[1] = 0x0;
    app_recirc_src_[2] = 0x0;
    app_recirc_src_[3] = 0x0;
    app_recirc_src_[4] = 0x0;
    app_recirc_src_[5] = 0x0;
    app_recirc_src_[6] = 0x0;
    app_recirc_src_[7] = 0x0;
    app_recirc_src_[8] = 0x0;
    app_recirc_src_[9] = 0x0;
    app_recirc_src_[10] = 0x0;
    app_recirc_src_[11] = 0x0;
    app_recirc_src_[12] = 0x0;
    app_recirc_src_[13] = 0x0;
    app_recirc_src_[14] = 0x0;
    app_recirc_src_[15] = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PgrCfgAppRecircPortSrc") + ":\n";
    for (uint32_t f=0;f<16;++f) {
      r += indent_string + "  " + std::string("app_recirc_src") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(app_recirc_src_[f]) ) + "\n";
      all_zeros &= (0 == app_recirc_src_[f]);
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
    r += indent_string + std::string("PgrCfgAppRecircPortSrc") + ":\n";
    for (uint32_t f=0;f<16;++f) {
      r += indent_string + "  " + std::string("app_recirc_src") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(app_recirc_src_[f]) ) + "\n";
      all_zeros &= (0 == app_recirc_src_[f]);
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< uint8_t, 16 > app_recirc_src_;
private:
  static int StartOffset(
      int index_pipe_addrmap
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x34000; // to get to pgrreg
    offset += 0x2000; // to get to pgr_common
    offset += 0x22c; // to get to cfg_app_recirc_src
    return offset;
  }

};













  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PGR_CFG_APP_RECIRC_PORT_SRC_H__
