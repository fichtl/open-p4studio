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
#ifndef __REGISTER_INCLUDES_TCAM_TABLE_MAP_H__
#define __REGISTER_INCLUDES_TCAM_TABLE_MAP_H__


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

class TcamTableMap : public model_core::RegisterBlock<RegisterCallback> {
public:
  TcamTableMap(
      int chipNumber, int index_pipe_addrmap, int index_mau_addrmap, int index_mau_tcam_column_addrmap, int index_tcam_table_map, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_mau_addrmap, index_mau_tcam_column_addrmap, index_tcam_table_map), 4, false, write_callback, read_callback, std::string("TcamTableMap")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_addrmap) + "," + boost::lexical_cast<std::string>(index_mau_tcam_column_addrmap) + "," + boost::lexical_cast<std::string>(index_tcam_table_map))
    {
    }
  TcamTableMap(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "TcamTableMap")
    {
    }
public:
  uint16_t &tcam_table_map() { return tcam_table_map_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = tcam_table_map_;
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    tcam_table_map_ = data;
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    tcam_table_map_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("TcamTableMap") + ":\n";
    r += indent_string + "  " + std::string("tcam_table_map") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_table_map_) ) + "\n";
    all_zeros &= (0 == tcam_table_map_);
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
    r += indent_string + std::string("TcamTableMap") + ":\n";
    r += indent_string + "  " + std::string("tcam_table_map") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(tcam_table_map_) ) + "\n";
    all_zeros &= (0 == tcam_table_map_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint16_t tcam_table_map_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_mau_addrmap, int index_mau_tcam_column_addrmap, int index_tcam_table_map
      ) {
    int offset=0;
    offset += 0x2000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x800000; // pipe_addrmap[]
    assert(index_mau_addrmap < 12);
    offset += index_mau_addrmap * 0x80000; // mau_addrmap[]
    offset += 0x40800; // to get to tcams
    assert(index_mau_tcam_column_addrmap < 2);
    offset += index_mau_tcam_column_addrmap * 0x80; // mau_tcam_column_addrmap[]
    assert(index_tcam_table_map < 8);
    offset += index_tcam_table_map * 0x4; // tcam_table_map[]
    return offset;
  }

};


















  }; // namespace register_classes
}; // namespace tofinoB0

#endif // __REGISTER_INCLUDES_TCAM_TABLE_MAP_H__
