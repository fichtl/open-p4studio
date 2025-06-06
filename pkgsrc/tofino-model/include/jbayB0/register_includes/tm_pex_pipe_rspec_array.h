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
#ifndef __REGISTER_INCLUDES_TM_PEX_PIPE_RSPEC_ARRAY_H__
#define __REGISTER_INCLUDES_TM_PEX_PIPE_RSPEC_ARRAY_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "cfg_ct_timer.h"
#include "pex_cnt.h"
#include "pex_debug_register.h"
#include "pex_epb_credit_probe.h"
#include "pex_eport_tx_cnt.h"
#include "pex_pfc_map_table.h"
#include "pex_tx_cnt_timer.h"
#include "qpex_epb_cred_cnt.h"
#include "qpex_pipe_ctrl.h"
#include "qpex_port_tdm_enb_map.h"
#include "qpex_pt_gap_wm.h"
#include "qpex_pt_state.h"
#include "qpex_q_empty.h"
#include "tm_pex_pipe_rspec.h"
#include "tm_pex_pipe_rspec_debug_bus_ctrl.h"
#include "tm_pex_pipe_rspec_discard_ph_fifo0_mbe_err_log.h"
#include "tm_pex_pipe_rspec_discard_ph_fifo0_sbe_err_log.h"
#include "tm_pex_pipe_rspec_discard_ph_fifo1_mbe_err_log.h"
#include "tm_pex_pipe_rspec_discard_ph_fifo1_sbe_err_log.h"
#include "tm_pex_pipe_rspec_dq_meta_fifo_mbe_err_log.h"
#include "tm_pex_pipe_rspec_dq_meta_fifo_sbe_err_log.h"
#include "tm_pex_pipe_rspec_dq_ph_fifo_mbe_err_log.h"
#include "tm_pex_pipe_rspec_dq_ph_fifo_sbe_err_log.h"
#include "tm_pex_pipe_rspec_ecc.h"
#include "tm_pex_pipe_rspec_intr.h"
#include "tm_pex_pipe_rspec_linkmem_mbe_err_log.h"
#include "tm_pex_pipe_rspec_linkmem_sbe_err_log.h"
#include "tm_pex_pipe_rspec_ph_afifo_mbe_err_log.h"
#include "tm_pex_pipe_rspec_ph_afifo_sbe_err_log.h"

namespace jbayB0 {
  namespace register_classes {

class TmPexPipeRspecArray : public model_core::RegisterBlock<RegisterArrayCallback> {
public:
  TmPexPipeRspecArray(
      int chipNumber, RegisterArrayCallback& write_callback = 0, RegisterArrayCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(), 16384 * ArraySize(-1), false, write_callback, read_callback, std::string("TmPexPipeRspecArray")),
    array(RealArraySize(-1)),
    size0_(ArraySize(0)),
    real_size0_(RealArraySize(0))
    {
    }
public:





  QpexPipeCtrl &pipe_ctrl(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pipe_ctrl();
  }








  TmPexPipeRspecEcc &ecc(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].ecc();
  }





  TmPexPipeRspecLinkmemMbeErrLog &linkmem_mbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].linkmem_mbe_err_log();
  }





  TmPexPipeRspecLinkmemSbeErrLog &linkmem_sbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].linkmem_sbe_err_log();
  }





  TmPexPipeRspecDqPhFifoSbeErrLog &dq_ph_fifo_sbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].dq_ph_fifo_sbe_err_log();
  }





  TmPexPipeRspecDqPhFifoMbeErrLog &dq_ph_fifo_mbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].dq_ph_fifo_mbe_err_log();
  }





  TmPexPipeRspecDqMetaFifoSbeErrLog &dq_meta_fifo_sbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].dq_meta_fifo_sbe_err_log();
  }





  TmPexPipeRspecDqMetaFifoMbeErrLog &dq_meta_fifo_mbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].dq_meta_fifo_mbe_err_log();
  }





  TmPexPipeRspecPhAfifoSbeErrLog &ph_afifo_sbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].ph_afifo_sbe_err_log();
  }





  TmPexPipeRspecPhAfifoMbeErrLog &ph_afifo_mbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].ph_afifo_mbe_err_log();
  }





  TmPexPipeRspecDiscardPhFifo0SbeErrLog &discard_ph_fifo0_sbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].discard_ph_fifo0_sbe_err_log();
  }





  TmPexPipeRspecDiscardPhFifo0MbeErrLog &discard_ph_fifo0_mbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].discard_ph_fifo0_mbe_err_log();
  }





  TmPexPipeRspecDiscardPhFifo1SbeErrLog &discard_ph_fifo1_sbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].discard_ph_fifo1_sbe_err_log();
  }





  TmPexPipeRspecDiscardPhFifo1MbeErrLog &discard_ph_fifo1_mbe_err_log(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].discard_ph_fifo1_mbe_err_log();
  }






  QpexPortTdmEnbMap &port_tdm_enb_map(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].port_tdm_enb_map();
  }







  QpexPtState &pt_state(uint32_t a0,int j0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pt_state(j0);
  }







  QpexEpbCredCnt &pt_epb_cred(uint32_t a0,int j0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pt_epb_cred(j0);
  }







  QpexQEmpty &q_empty(uint32_t a0,int j0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].q_empty(j0);
  }







  QpexPtGapWm &pt_gap_wm(uint32_t a0,int j0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pt_gap_wm(j0);
  }





  CfgCtTimer &cfg_ct_timer(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].cfg_ct_timer();
  }








  PexPfcMapTable &pex_pfc_map_table(uint32_t a0,int j0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pex_pfc_map_table(j0);
  }








  PexEportTxCnt &pex_eport_tx_cnt(uint32_t a0,int j0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pex_eport_tx_cnt(j0);
  }





  PexDebugRegister &pex_debug_register(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pex_debug_register();
  }






  PexTxCntTimer &pex_tx_cnt_timer(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pex_tx_cnt_timer();
  }






  PexEpbCreditProbe &pex_epb_credit_probe(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].pex_epb_credit_probe();
  }





  PexCnt &tot_byte_cnt(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].tot_byte_cnt();
  }





  PexCnt &tot_pkt_cnt(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].tot_pkt_cnt();
  }





  PexCnt &dis_cell_cnt(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].dis_cell_cnt();
  }





  TmPexPipeRspecDebugBusCtrl &debug_bus_ctrl(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].debug_bus_ctrl();
  }
  TmPexPipeRspecIntr &intr(uint32_t a0)
  {
    CheckArrayBounds(a0,real_size0_,size0_,0,0,false);
    return array[a0].intr();
  }
  bool calculate_index(
      uint32_t* offset, uint32_t* a0
      ) const {
    int i = (*offset)/16384;
    (*offset) -= (i*16384);
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
      r += indent_string + std::string("TmPexPipeRspecArray") + "["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
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
        r += indent_string + std::string("TmPexPipeRspecArray") + "["+boost::lexical_cast<std::string>(a0)+"]"+ ":\n" + r_s ;
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
  std::vector<TmPexPipeRspec> array;
  uint32_t size0_;
  uint32_t real_size0_;
private:
  static int StartOffset(
      
      ) {
    int offset=0;
    offset += 0x800000; // to get to tm_top
    offset += 0x300000; // to get to tm_pex_top
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
}; // namespace jbayB0

#endif // __REGISTER_INCLUDES_TM_PEX_PIPE_RSPEC_ARRAY_H__
