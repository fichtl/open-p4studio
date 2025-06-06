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
#ifndef __REGISTER_INCLUDES_PRE_PORT_VECTOR_MUTABLE_H__
#define __REGISTER_INCLUDES_PRE_PORT_VECTOR_MUTABLE_H__


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

class PrePortVectorMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  PrePortVectorMutable(
      int chipNumber, int index_tm_pre_pipe_rspec, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_tm_pre_pipe_rspec), 12, true, write_callback, read_callback, std::string("PrePortVectorMutable")+":"+boost::lexical_cast<std::string>(index_tm_pre_pipe_rspec))
    {
    }
  PrePortVectorMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "PrePortVectorMutable")
    {
    }
public:







  uint8_t port_vec(int j0) { return port_vec_[j0]; }
  void port_vec(int j0,const uint8_t &v) { port_vec_[j0]=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset < 0x4) {
      if (read_callback_) read_callback_();
      *data = (port_vec_[0] & 0x1);
      *data |= ((port_vec_[1] & 0x1) << 1);
      *data |= ((port_vec_[2] & 0x1) << 2);
      *data |= ((port_vec_[3] & 0x1) << 3);
      *data |= ((port_vec_[4] & 0x1) << 4);
      *data |= ((port_vec_[5] & 0x1) << 5);
      *data |= ((port_vec_[6] & 0x1) << 6);
      *data |= ((port_vec_[7] & 0x1) << 7);
      *data |= ((port_vec_[8] & 0x1) << 8);
      *data |= ((port_vec_[9] & 0x1) << 9);
      *data |= ((port_vec_[10] & 0x1) << 10);
      *data |= ((port_vec_[11] & 0x1) << 11);
      *data |= ((port_vec_[12] & 0x1) << 12);
      *data |= ((port_vec_[13] & 0x1) << 13);
      *data |= ((port_vec_[14] & 0x1) << 14);
      *data |= ((port_vec_[15] & 0x1) << 15);
      *data |= ((port_vec_[16] & 0x1) << 16);
      *data |= ((port_vec_[17] & 0x1) << 17);
      *data |= ((port_vec_[18] & 0x1) << 18);
      *data |= ((port_vec_[19] & 0x1) << 19);
      *data |= ((port_vec_[20] & 0x1) << 20);
      *data |= ((port_vec_[21] & 0x1) << 21);
      *data |= ((port_vec_[22] & 0x1) << 22);
      *data |= ((port_vec_[23] & 0x1) << 23);
      *data |= ((port_vec_[24] & 0x1) << 24);
      *data |= ((port_vec_[25] & 0x1) << 25);
      *data |= ((port_vec_[26] & 0x1) << 26);
      *data |= ((port_vec_[27] & 0x1) << 27);
      *data |= ((port_vec_[28] & 0x1) << 28);
      *data |= ((port_vec_[29] & 0x1) << 29);
      *data |= ((port_vec_[30] & 0x1) << 30);
      *data |= ((port_vec_[31] & 0x1) << 31);
    }
    else if (offset >= 0x4 && offset < 0x8) {
      if (read_callback_) read_callback_();
      *data = (port_vec_[32] & 0x1);
      *data |= ((port_vec_[33] & 0x1) << 1);
      *data |= ((port_vec_[34] & 0x1) << 2);
      *data |= ((port_vec_[35] & 0x1) << 3);
      *data |= ((port_vec_[36] & 0x1) << 4);
      *data |= ((port_vec_[37] & 0x1) << 5);
      *data |= ((port_vec_[38] & 0x1) << 6);
      *data |= ((port_vec_[39] & 0x1) << 7);
      *data |= ((port_vec_[40] & 0x1) << 8);
      *data |= ((port_vec_[41] & 0x1) << 9);
      *data |= ((port_vec_[42] & 0x1) << 10);
      *data |= ((port_vec_[43] & 0x1) << 11);
      *data |= ((port_vec_[44] & 0x1) << 12);
      *data |= ((port_vec_[45] & 0x1) << 13);
      *data |= ((port_vec_[46] & 0x1) << 14);
      *data |= ((port_vec_[47] & 0x1) << 15);
      *data |= ((port_vec_[48] & 0x1) << 16);
      *data |= ((port_vec_[49] & 0x1) << 17);
      *data |= ((port_vec_[50] & 0x1) << 18);
      *data |= ((port_vec_[51] & 0x1) << 19);
      *data |= ((port_vec_[52] & 0x1) << 20);
      *data |= ((port_vec_[53] & 0x1) << 21);
      *data |= ((port_vec_[54] & 0x1) << 22);
      *data |= ((port_vec_[55] & 0x1) << 23);
      *data |= ((port_vec_[56] & 0x1) << 24);
      *data |= ((port_vec_[57] & 0x1) << 25);
      *data |= ((port_vec_[58] & 0x1) << 26);
      *data |= ((port_vec_[59] & 0x1) << 27);
      *data |= ((port_vec_[60] & 0x1) << 28);
      *data |= ((port_vec_[61] & 0x1) << 29);
      *data |= ((port_vec_[62] & 0x1) << 30);
      *data |= ((port_vec_[63] & 0x1) << 31);
    }
    else if (offset >= 0x8 && offset < 0xc) {
      if (read_callback_) read_callback_();
      *data = (port_vec_[64] & 0x1);
      *data |= ((port_vec_[65] & 0x1) << 1);
      *data |= ((port_vec_[66] & 0x1) << 2);
      *data |= ((port_vec_[67] & 0x1) << 3);
      *data |= ((port_vec_[68] & 0x1) << 4);
      *data |= ((port_vec_[69] & 0x1) << 5);
      *data |= ((port_vec_[70] & 0x1) << 6);
      *data |= ((port_vec_[71] & 0x1) << 7);
    }
    else {
      assert(0);
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset < 0x4) {
      port_vec_[0] = (data & 0x1);
      port_vec_[1] = ((data >> 1) & 0x1);
      port_vec_[2] = ((data >> 2) & 0x1);
      port_vec_[3] = ((data >> 3) & 0x1);
      port_vec_[4] = ((data >> 4) & 0x1);
      port_vec_[5] = ((data >> 5) & 0x1);
      port_vec_[6] = ((data >> 6) & 0x1);
      port_vec_[7] = ((data >> 7) & 0x1);
      port_vec_[8] = ((data >> 8) & 0x1);
      port_vec_[9] = ((data >> 9) & 0x1);
      port_vec_[10] = ((data >> 10) & 0x1);
      port_vec_[11] = ((data >> 11) & 0x1);
      port_vec_[12] = ((data >> 12) & 0x1);
      port_vec_[13] = ((data >> 13) & 0x1);
      port_vec_[14] = ((data >> 14) & 0x1);
      port_vec_[15] = ((data >> 15) & 0x1);
      port_vec_[16] = ((data >> 16) & 0x1);
      port_vec_[17] = ((data >> 17) & 0x1);
      port_vec_[18] = ((data >> 18) & 0x1);
      port_vec_[19] = ((data >> 19) & 0x1);
      port_vec_[20] = ((data >> 20) & 0x1);
      port_vec_[21] = ((data >> 21) & 0x1);
      port_vec_[22] = ((data >> 22) & 0x1);
      port_vec_[23] = ((data >> 23) & 0x1);
      port_vec_[24] = ((data >> 24) & 0x1);
      port_vec_[25] = ((data >> 25) & 0x1);
      port_vec_[26] = ((data >> 26) & 0x1);
      port_vec_[27] = ((data >> 27) & 0x1);
      port_vec_[28] = ((data >> 28) & 0x1);
      port_vec_[29] = ((data >> 29) & 0x1);
      port_vec_[30] = ((data >> 30) & 0x1);
      port_vec_[31] = ((data >> 31) & 0x1);
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4 && offset < 0x8) {
      port_vec_[32] = (data & 0x1);
      port_vec_[33] = ((data >> 1) & 0x1);
      port_vec_[34] = ((data >> 2) & 0x1);
      port_vec_[35] = ((data >> 3) & 0x1);
      port_vec_[36] = ((data >> 4) & 0x1);
      port_vec_[37] = ((data >> 5) & 0x1);
      port_vec_[38] = ((data >> 6) & 0x1);
      port_vec_[39] = ((data >> 7) & 0x1);
      port_vec_[40] = ((data >> 8) & 0x1);
      port_vec_[41] = ((data >> 9) & 0x1);
      port_vec_[42] = ((data >> 10) & 0x1);
      port_vec_[43] = ((data >> 11) & 0x1);
      port_vec_[44] = ((data >> 12) & 0x1);
      port_vec_[45] = ((data >> 13) & 0x1);
      port_vec_[46] = ((data >> 14) & 0x1);
      port_vec_[47] = ((data >> 15) & 0x1);
      port_vec_[48] = ((data >> 16) & 0x1);
      port_vec_[49] = ((data >> 17) & 0x1);
      port_vec_[50] = ((data >> 18) & 0x1);
      port_vec_[51] = ((data >> 19) & 0x1);
      port_vec_[52] = ((data >> 20) & 0x1);
      port_vec_[53] = ((data >> 21) & 0x1);
      port_vec_[54] = ((data >> 22) & 0x1);
      port_vec_[55] = ((data >> 23) & 0x1);
      port_vec_[56] = ((data >> 24) & 0x1);
      port_vec_[57] = ((data >> 25) & 0x1);
      port_vec_[58] = ((data >> 26) & 0x1);
      port_vec_[59] = ((data >> 27) & 0x1);
      port_vec_[60] = ((data >> 28) & 0x1);
      port_vec_[61] = ((data >> 29) & 0x1);
      port_vec_[62] = ((data >> 30) & 0x1);
      port_vec_[63] = ((data >> 31) & 0x1);
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x8 && offset < 0xc) {
      port_vec_[64] = (data & 0x1);
      port_vec_[65] = ((data >> 1) & 0x1);
      port_vec_[66] = ((data >> 2) & 0x1);
      port_vec_[67] = ((data >> 3) & 0x1);
      port_vec_[68] = ((data >> 4) & 0x1);
      port_vec_[69] = ((data >> 5) & 0x1);
      port_vec_[70] = ((data >> 6) & 0x1);
      port_vec_[71] = ((data >> 7) & 0x1);
      if (write_callback_) write_callback_();
    }
    else {
      assert(0);
    }
    return true;
  }

  void reset(
      
      ) {
    port_vec_[0] = 0x0;
    port_vec_[1] = 0x0;
    port_vec_[2] = 0x0;
    port_vec_[3] = 0x0;
    port_vec_[4] = 0x0;
    port_vec_[5] = 0x0;
    port_vec_[6] = 0x0;
    port_vec_[7] = 0x0;
    port_vec_[8] = 0x0;
    port_vec_[9] = 0x0;
    port_vec_[10] = 0x0;
    port_vec_[11] = 0x0;
    port_vec_[12] = 0x0;
    port_vec_[13] = 0x0;
    port_vec_[14] = 0x0;
    port_vec_[15] = 0x0;
    port_vec_[16] = 0x0;
    port_vec_[17] = 0x0;
    port_vec_[18] = 0x0;
    port_vec_[19] = 0x0;
    port_vec_[20] = 0x0;
    port_vec_[21] = 0x0;
    port_vec_[22] = 0x0;
    port_vec_[23] = 0x0;
    port_vec_[24] = 0x0;
    port_vec_[25] = 0x0;
    port_vec_[26] = 0x0;
    port_vec_[27] = 0x0;
    port_vec_[28] = 0x0;
    port_vec_[29] = 0x0;
    port_vec_[30] = 0x0;
    port_vec_[31] = 0x0;
    port_vec_[32] = 0x0;
    port_vec_[33] = 0x0;
    port_vec_[34] = 0x0;
    port_vec_[35] = 0x0;
    port_vec_[36] = 0x0;
    port_vec_[37] = 0x0;
    port_vec_[38] = 0x0;
    port_vec_[39] = 0x0;
    port_vec_[40] = 0x0;
    port_vec_[41] = 0x0;
    port_vec_[42] = 0x0;
    port_vec_[43] = 0x0;
    port_vec_[44] = 0x0;
    port_vec_[45] = 0x0;
    port_vec_[46] = 0x0;
    port_vec_[47] = 0x0;
    port_vec_[48] = 0x0;
    port_vec_[49] = 0x0;
    port_vec_[50] = 0x0;
    port_vec_[51] = 0x0;
    port_vec_[52] = 0x0;
    port_vec_[53] = 0x0;
    port_vec_[54] = 0x0;
    port_vec_[55] = 0x0;
    port_vec_[56] = 0x0;
    port_vec_[57] = 0x0;
    port_vec_[58] = 0x0;
    port_vec_[59] = 0x0;
    port_vec_[60] = 0x0;
    port_vec_[61] = 0x0;
    port_vec_[62] = 0x0;
    port_vec_[63] = 0x0;
    port_vec_[64] = 0x0;
    port_vec_[65] = 0x0;
    port_vec_[66] = 0x0;
    port_vec_[67] = 0x0;
    port_vec_[68] = 0x0;
    port_vec_[69] = 0x0;
    port_vec_[70] = 0x0;
    port_vec_[71] = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("PrePortVectorMutable") + ":\n";
    for (uint32_t f=0;f<72;++f) {
      r += indent_string + "  " + std::string("port_vec") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(port_vec_[f]) ) + "\n";
      all_zeros &= (0 == port_vec_[f]);
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
    r += indent_string + std::string("PrePortVectorMutable") + ":\n";
    for (uint32_t f=0;f<72;++f) {
      r += indent_string + "  " + std::string("port_vec") + "["+boost::lexical_cast<std::string>(f)+"]"+ ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(port_vec_[f]) ) + "\n";
      all_zeros &= (0 == port_vec_[f]);
    }
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  std::array< uint8_t, 72 > port_vec_;
private:
  static int StartOffset(
      int index_tm_pre_pipe_rspec
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x480000; // to get to tm_pre_top
    assert(index_tm_pre_pipe_rspec < 4);
    offset += index_tm_pre_pipe_rspec * 0x8000; // tm_pre_pipe_rspec[]
    offset += 0xf0; // to get to filtered_port_vector
    return offset;
  }

};









  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_PRE_PORT_VECTOR_MUTABLE_H__
