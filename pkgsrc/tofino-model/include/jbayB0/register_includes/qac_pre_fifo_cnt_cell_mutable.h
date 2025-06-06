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
#ifndef __REGISTER_INCLUDES_QAC_PRE_FIFO_CNT_CELL_MUTABLE_H__
#define __REGISTER_INCLUDES_QAC_PRE_FIFO_CNT_CELL_MUTABLE_H__


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

class QacPreFifoCntCellMutable : public model_core::RegisterBlock<RegisterCallback> {
public:
  enum QacCommonBlockEnum {
    kQacCommonQacPreFifoCntCellPipe0,
    kQacCommonQacPreFifoCntCellPipe1,
    kQacCommonQacPreFifoCntCellPipe2,
    kQacCommonQacPreFifoCntCellPipe3
  };
public:
  QacPreFifoCntCellMutable(
      int chipNumber, QacCommonBlockEnum selector_qac_common_block, int index_qac_pre_fifo_cnt_cell, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(selector_qac_common_block, index_qac_pre_fifo_cnt_cell), 4, true, write_callback, read_callback, std::string("QacPreFifoCntCellMutable")+":"+boost::lexical_cast<std::string>(selector_qac_common_block) + "," + boost::lexical_cast<std::string>(index_qac_pre_fifo_cnt_cell))
    {
    }
  QacPreFifoCntCellMutable(
      
  )
    : RegisterBlock(0, 0, 0, true, 0, 0, "QacPreFifoCntCellMutable")
    {
    }
public:





  uint32_t cnt_pkt() { return cnt_pkt_; }
  void cnt_pkt(const uint32_t &v) { cnt_pkt_=v; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (read_callback_) read_callback_();
    *data = (cnt_pkt_ & 0x7ffff);
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    cnt_pkt_ = (data & 0x7ffff);
    if (write_callback_) write_callback_();
    return true;
  }

  void reset(
      
      ) {
    cnt_pkt_ = 0x0;
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    r += indent_string + std::string("QacPreFifoCntCellMutable") + ":\n";
    r += indent_string + "  " + std::string("cnt_pkt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt_pkt_) ) + "\n";
    all_zeros &= (0 == cnt_pkt_);
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
    r += indent_string + std::string("QacPreFifoCntCellMutable") + ":\n";
    r += indent_string + "  " + std::string("cnt_pkt") +  ": 0x" + boost::str( boost::format("%x") % static_cast<uint>(cnt_pkt_) ) + "\n";
    all_zeros &= (0 == cnt_pkt_);
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  uint32_t cnt_pkt_;
private:
  static int StartOffset(
      QacCommonBlockEnum selector_qac_common_block, int index_qac_pre_fifo_cnt_cell
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x100000; // to get to tm_qac_top
    switch (selector_qac_common_block) {
      case kQacCommonQacPreFifoCntCellPipe0:
        offset += 0x120; // to get to qac_common_qac_pre_fifo_cnt_cell_pipe0
        assert(index_qac_pre_fifo_cnt_cell < 4);
        offset += index_qac_pre_fifo_cnt_cell * 0x4; // qac_pre_fifo_cnt_cell[]
        break;
      case kQacCommonQacPreFifoCntCellPipe1:
        offset += 0x140; // to get to qac_common_qac_pre_fifo_cnt_cell_pipe1
        assert(index_qac_pre_fifo_cnt_cell < 4);
        offset += index_qac_pre_fifo_cnt_cell * 0x4; // qac_pre_fifo_cnt_cell[]
        break;
      case kQacCommonQacPreFifoCntCellPipe2:
        offset += 0x160; // to get to qac_common_qac_pre_fifo_cnt_cell_pipe2
        assert(index_qac_pre_fifo_cnt_cell < 4);
        offset += index_qac_pre_fifo_cnt_cell * 0x4; // qac_pre_fifo_cnt_cell[]
        break;
      case kQacCommonQacPreFifoCntCellPipe3:
        offset += 0x180; // to get to qac_common_qac_pre_fifo_cnt_cell_pipe3
        assert(index_qac_pre_fifo_cnt_cell < 4);
        offset += index_qac_pre_fifo_cnt_cell * 0x4; // qac_pre_fifo_cnt_cell[]
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

#endif // __REGISTER_INCLUDES_QAC_PRE_FIFO_CNT_CELL_MUTABLE_H__
