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
#ifndef __REGISTER_INCLUDES_DPRSR_INP_SLICE_H__
#define __REGISTER_INCLUDES_DPRSR_INP_SLICE_H__


#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <model_core/register_block.h>
#include <shared/bitvector.h>









#include "dprsr_inp_slice_cred_fifo.h"
#include "dprsr_inp_slice_e_fdinfo_ecc_ctrl.h"
#include "dprsr_inp_slice_e_fdinfo_mbe_err_log.h"
#include "dprsr_inp_slice_e_fdinfo_sbe_err_log.h"
#include "dprsr_inp_slice_e_meta_ecc_ctrl.h"
#include "dprsr_inp_slice_e_meta_mbe_err_log.h"
#include "dprsr_inp_slice_e_meta_sbe_err_log.h"
#include "dprsr_inp_slice_e_volts_ecc_ctrl.h"
#include "dprsr_inp_slice_e_volts_mbe_err_log.h"
#include "dprsr_inp_slice_e_volts_sbe_err_log.h"
#include "dprsr_inp_slice_i_fdinfo_ecc_ctrl.h"
#include "dprsr_inp_slice_i_fdinfo_mbe_err_log.h"
#include "dprsr_inp_slice_i_fdinfo_sbe_err_log.h"
#include "dprsr_inp_slice_i_meta_ecc_ctrl.h"
#include "dprsr_inp_slice_i_meta_mbe_err_log.h"
#include "dprsr_inp_slice_i_meta_sbe_err_log.h"
#include "dprsr_inp_slice_i_volts_ecc_ctrl.h"
#include "dprsr_inp_slice_i_volts_mbe_err_log.h"
#include "dprsr_inp_slice_i_volts_sbe_err_log.h"
#include "dprsr_inp_slice_intr.h"
#include "dprsr_inp_slice_phv16_ecc_ctrl.h"
#include "dprsr_inp_slice_phv16_mbe_err_log.h"
#include "dprsr_inp_slice_phv16_sbe_err_log.h"
#include "dprsr_inp_slice_phv32_ecc_ctrl.h"
#include "dprsr_inp_slice_phv32_mbe_err_log.h"
#include "dprsr_inp_slice_phv32_sbe_err_log.h"
#include "dprsr_inp_slice_phv8_ecc_ctrl.h"
#include "dprsr_inp_slice_phv8_mbe_err_log.h"
#include "dprsr_inp_slice_phv8_sbe_err_log.h"

namespace jbay {
  namespace register_classes {

class DprsrInpSlice : public model_core::RegisterBlock<RegisterCallback> {
public:
  DprsrInpSlice(
      int chipNumber, int index_pipe_addrmap, int index_dprsr_inp_slice, RegisterCallback& write_callback = 0, RegisterCallback& read_callback = 0
  )
    : RegisterBlock(chipNumber, StartOffset(index_pipe_addrmap, index_dprsr_inp_slice), 256, false, write_callback, read_callback, std::string("DprsrInpSlice")+":"+boost::lexical_cast<std::string>(index_pipe_addrmap) + "," + boost::lexical_cast<std::string>(index_dprsr_inp_slice))
    {
    }
  DprsrInpSlice(
      
  )
    : RegisterBlock(0, 0, 0, false, 0, 0, "DprsrInpSlice")
    {
    }
public:





  DprsrInpSliceIMetaSbeErrLog &i_meta_sbe_err_log() { return i_meta_sbe_err_log_; }





  DprsrInpSliceIMetaMbeErrLog &i_meta_mbe_err_log() { return i_meta_mbe_err_log_; }





  DprsrInpSliceEMetaSbeErrLog &e_meta_sbe_err_log() { return e_meta_sbe_err_log_; }





  DprsrInpSliceEMetaMbeErrLog &e_meta_mbe_err_log() { return e_meta_mbe_err_log_; }





  DprsrInpSlicePhv32SbeErrLog &phv32_sbe_err_log() { return phv32_sbe_err_log_; }





  DprsrInpSlicePhv32MbeErrLog &phv32_mbe_err_log() { return phv32_mbe_err_log_; }





  DprsrInpSlicePhv16SbeErrLog &phv16_sbe_err_log() { return phv16_sbe_err_log_; }





  DprsrInpSlicePhv16MbeErrLog &phv16_mbe_err_log() { return phv16_mbe_err_log_; }





  DprsrInpSlicePhv8SbeErrLog &phv8_sbe_err_log() { return phv8_sbe_err_log_; }





  DprsrInpSlicePhv8MbeErrLog &phv8_mbe_err_log() { return phv8_mbe_err_log_; }





  DprsrInpSliceIVoltsSbeErrLog &i_volts_sbe_err_log() { return i_volts_sbe_err_log_; }





  DprsrInpSliceIVoltsMbeErrLog &i_volts_mbe_err_log() { return i_volts_mbe_err_log_; }





  DprsrInpSliceEVoltsSbeErrLog &e_volts_sbe_err_log() { return e_volts_sbe_err_log_; }





  DprsrInpSliceEVoltsMbeErrLog &e_volts_mbe_err_log() { return e_volts_mbe_err_log_; }





  DprsrInpSliceIFdinfoSbeErrLog &i_fdinfo_sbe_err_log() { return i_fdinfo_sbe_err_log_; }





  DprsrInpSliceIFdinfoMbeErrLog &i_fdinfo_mbe_err_log() { return i_fdinfo_mbe_err_log_; }





  DprsrInpSliceEFdinfoSbeErrLog &e_fdinfo_sbe_err_log() { return e_fdinfo_sbe_err_log_; }





  DprsrInpSliceEFdinfoMbeErrLog &e_fdinfo_mbe_err_log() { return e_fdinfo_mbe_err_log_; }





  DprsrInpSliceIMetaEccCtrl &i_meta_ecc_ctrl() { return i_meta_ecc_ctrl_; }





  DprsrInpSliceEMetaEccCtrl &e_meta_ecc_ctrl() { return e_meta_ecc_ctrl_; }





  DprsrInpSlicePhv32EccCtrl &phv32_ecc_ctrl() { return phv32_ecc_ctrl_; }





  DprsrInpSlicePhv16EccCtrl &phv16_ecc_ctrl() { return phv16_ecc_ctrl_; }





  DprsrInpSlicePhv8EccCtrl &phv8_ecc_ctrl() { return phv8_ecc_ctrl_; }





  DprsrInpSliceIVoltsEccCtrl &i_volts_ecc_ctrl() { return i_volts_ecc_ctrl_; }





  DprsrInpSliceEVoltsEccCtrl &e_volts_ecc_ctrl() { return e_volts_ecc_ctrl_; }





  DprsrInpSliceIFdinfoEccCtrl &i_fdinfo_ecc_ctrl() { return i_fdinfo_ecc_ctrl_; }





  DprsrInpSliceEFdinfoEccCtrl &e_fdinfo_ecc_ctrl() { return e_fdinfo_ecc_ctrl_; }






  DprsrInpSliceCredFifo &cred_fifo() { return cred_fifo_; }
  DprsrInpSliceIntr &intr() { return intr_; }

  bool read(
      uint32_t offset, uint32_t* data
      ) const {
    if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      if (read_callback_) read_callback_();
      i_meta_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      if (read_callback_) read_callback_();
      i_meta_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      if (read_callback_) read_callback_();
      e_meta_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      if (read_callback_) read_callback_();
      e_meta_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      if (read_callback_) read_callback_();
      phv32_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      if (read_callback_) read_callback_();
      phv32_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      if (read_callback_) read_callback_();
      phv16_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      if (read_callback_) read_callback_();
      phv16_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      if (read_callback_) read_callback_();
      phv8_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x58 && offset < 0x5c) {
      offset -= 0x58;
      if (read_callback_) read_callback_();
      phv8_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x5c && offset < 0x60) {
      offset -= 0x5c;
      if (read_callback_) read_callback_();
      i_volts_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x60 && offset < 0x64) {
      offset -= 0x60;
      if (read_callback_) read_callback_();
      i_volts_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x64 && offset < 0x68) {
      offset -= 0x64;
      if (read_callback_) read_callback_();
      e_volts_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x68 && offset < 0x6c) {
      offset -= 0x68;
      if (read_callback_) read_callback_();
      e_volts_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x6c && offset < 0x70) {
      offset -= 0x6c;
      if (read_callback_) read_callback_();
      i_fdinfo_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x70 && offset < 0x74) {
      offset -= 0x70;
      if (read_callback_) read_callback_();
      i_fdinfo_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x74 && offset < 0x78) {
      offset -= 0x74;
      if (read_callback_) read_callback_();
      e_fdinfo_sbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x78 && offset < 0x7c) {
      offset -= 0x78;
      if (read_callback_) read_callback_();
      e_fdinfo_mbe_err_log_.read( offset, data );
    }
    else if (offset >= 0x7c && offset < 0x80) {
      offset -= 0x7c;
      if (read_callback_) read_callback_();
      i_meta_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      if (read_callback_) read_callback_();
      e_meta_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0x90 && offset < 0x9c) {
      offset -= 0x90;
      if (read_callback_) read_callback_();
      phv32_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa0 && offset < 0xa8) {
      offset -= 0xa0;
      if (read_callback_) read_callback_();
      phv16_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      if (read_callback_) read_callback_();
      phv8_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xb0 && offset < 0xb4) {
      offset -= 0xb0;
      if (read_callback_) read_callback_();
      i_volts_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xb4 && offset < 0xb8) {
      offset -= 0xb4;
      if (read_callback_) read_callback_();
      e_volts_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xb8 && offset < 0xbc) {
      offset -= 0xb8;
      if (read_callback_) read_callback_();
      i_fdinfo_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xbc && offset < 0xc0) {
      offset -= 0xbc;
      if (read_callback_) read_callback_();
      e_fdinfo_ecc_ctrl_.read( offset, data );
    }
    else if (offset >= 0xc0 && offset < 0xc4) {
      offset -= 0xc0;
      if (read_callback_) read_callback_();
      cred_fifo_.read( offset, data );
    }
    else if (offset >= 0x20 && offset < 0x34) {
      offset -= 0x20;
      if (read_callback_) read_callback_();
      intr_.read( offset, data );
    }
    return true;
  }


  bool write(
      uint32_t offset, uint32_t data
      ) {
    if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      i_meta_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      i_meta_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      e_meta_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      e_meta_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      phv32_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      phv32_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      phv16_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      phv16_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      phv8_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x58 && offset < 0x5c) {
      offset -= 0x58;
      phv8_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x5c && offset < 0x60) {
      offset -= 0x5c;
      i_volts_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x60 && offset < 0x64) {
      offset -= 0x60;
      i_volts_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x64 && offset < 0x68) {
      offset -= 0x64;
      e_volts_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x68 && offset < 0x6c) {
      offset -= 0x68;
      e_volts_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x6c && offset < 0x70) {
      offset -= 0x6c;
      i_fdinfo_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x70 && offset < 0x74) {
      offset -= 0x70;
      i_fdinfo_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x74 && offset < 0x78) {
      offset -= 0x74;
      e_fdinfo_sbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x78 && offset < 0x7c) {
      offset -= 0x78;
      e_fdinfo_mbe_err_log_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x7c && offset < 0x80) {
      offset -= 0x7c;
      i_meta_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      e_meta_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x90 && offset < 0x9c) {
      offset -= 0x90;
      phv32_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa0 && offset < 0xa8) {
      offset -= 0xa0;
      phv16_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      phv8_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb0 && offset < 0xb4) {
      offset -= 0xb0;
      i_volts_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb4 && offset < 0xb8) {
      offset -= 0xb4;
      e_volts_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xb8 && offset < 0xbc) {
      offset -= 0xb8;
      i_fdinfo_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xbc && offset < 0xc0) {
      offset -= 0xbc;
      e_fdinfo_ecc_ctrl_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0xc0 && offset < 0xc4) {
      offset -= 0xc0;
      cred_fifo_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    else if (offset >= 0x20 && offset < 0x34) {
      offset -= 0x20;
      intr_.write( offset, data );
      if (write_callback_) write_callback_();
    }
    return true;
  }

  void reset(
      
      ) {
    i_meta_sbe_err_log_.reset();
    i_meta_mbe_err_log_.reset();
    e_meta_sbe_err_log_.reset();
    e_meta_mbe_err_log_.reset();
    phv32_sbe_err_log_.reset();
    phv32_mbe_err_log_.reset();
    phv16_sbe_err_log_.reset();
    phv16_mbe_err_log_.reset();
    phv8_sbe_err_log_.reset();
    phv8_mbe_err_log_.reset();
    i_volts_sbe_err_log_.reset();
    i_volts_mbe_err_log_.reset();
    e_volts_sbe_err_log_.reset();
    e_volts_mbe_err_log_.reset();
    i_fdinfo_sbe_err_log_.reset();
    i_fdinfo_mbe_err_log_.reset();
    e_fdinfo_sbe_err_log_.reset();
    e_fdinfo_mbe_err_log_.reset();
    i_meta_ecc_ctrl_.reset();
    e_meta_ecc_ctrl_.reset();
    phv32_ecc_ctrl_.reset();
    phv16_ecc_ctrl_.reset();
    phv8_ecc_ctrl_.reset();
    i_volts_ecc_ctrl_.reset();
    e_volts_ecc_ctrl_.reset();
    i_fdinfo_ecc_ctrl_.reset();
    e_fdinfo_ecc_ctrl_.reset();
    cred_fifo_.reset();
    intr_.reset();
    if (write_callback_) write_callback_();
  }

  std::string to_string(
      uint32_t offset, bool print_zeros = false, std::string indent_string = ""
      ) const {
    std::string r("");
    bool all_zeros=true;
    all_zeros=false;
    if (offset >= 0x34 && offset < 0x38) {
      offset -= 0x34;
      r += i_meta_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x38 && offset < 0x3c) {
      offset -= 0x38;
      r += i_meta_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x3c && offset < 0x40) {
      offset -= 0x3c;
      r += e_meta_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x40 && offset < 0x44) {
      offset -= 0x40;
      r += e_meta_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x44 && offset < 0x48) {
      offset -= 0x44;
      r += phv32_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x48 && offset < 0x4c) {
      offset -= 0x48;
      r += phv32_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x4c && offset < 0x50) {
      offset -= 0x4c;
      r += phv16_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x50 && offset < 0x54) {
      offset -= 0x50;
      r += phv16_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x54 && offset < 0x58) {
      offset -= 0x54;
      r += phv8_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x58 && offset < 0x5c) {
      offset -= 0x58;
      r += phv8_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x5c && offset < 0x60) {
      offset -= 0x5c;
      r += i_volts_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x60 && offset < 0x64) {
      offset -= 0x60;
      r += i_volts_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x64 && offset < 0x68) {
      offset -= 0x64;
      r += e_volts_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x68 && offset < 0x6c) {
      offset -= 0x68;
      r += e_volts_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x6c && offset < 0x70) {
      offset -= 0x6c;
      r += i_fdinfo_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x70 && offset < 0x74) {
      offset -= 0x70;
      r += i_fdinfo_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x74 && offset < 0x78) {
      offset -= 0x74;
      r += e_fdinfo_sbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x78 && offset < 0x7c) {
      offset -= 0x78;
      r += e_fdinfo_mbe_err_log_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x7c && offset < 0x80) {
      offset -= 0x7c;
      r += i_meta_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x80 && offset < 0x84) {
      offset -= 0x80;
      r += e_meta_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x90 && offset < 0x9c) {
      offset -= 0x90;
      r += phv32_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa0 && offset < 0xa8) {
      offset -= 0xa0;
      r += phv16_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xa8 && offset < 0xb0) {
      offset -= 0xa8;
      r += phv8_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb0 && offset < 0xb4) {
      offset -= 0xb0;
      r += i_volts_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb4 && offset < 0xb8) {
      offset -= 0xb4;
      r += e_volts_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xb8 && offset < 0xbc) {
      offset -= 0xb8;
      r += i_fdinfo_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xbc && offset < 0xc0) {
      offset -= 0xbc;
      r += e_fdinfo_ecc_ctrl_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0xc0 && offset < 0xc4) {
      offset -= 0xc0;
      r += cred_fifo_.to_string(offset,print_zeros,indent_string) ;
    }
    else if (offset >= 0x20 && offset < 0x34) {
      offset -= 0x20;
      r += intr_.to_string(offset,print_zeros,indent_string) ;
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
    r += i_meta_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += i_meta_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += e_meta_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += e_meta_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += phv32_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += phv32_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += phv16_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += phv16_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += phv8_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += phv8_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += i_volts_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += i_volts_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += e_volts_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += e_volts_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += i_fdinfo_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += i_fdinfo_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += e_fdinfo_sbe_err_log_.to_string(print_zeros,indent_string) ;
    r += e_fdinfo_mbe_err_log_.to_string(print_zeros,indent_string) ;
    r += i_meta_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += e_meta_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += phv32_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += phv16_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += phv8_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += i_volts_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += e_volts_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += i_fdinfo_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += e_fdinfo_ecc_ctrl_.to_string(print_zeros,indent_string) ;
    r += cred_fifo_.to_string(print_zeros,indent_string) ;
    r += intr_.to_string(print_zeros,indent_string) ;
    if (all_zeros && !print_zeros) {
      return("");
    }
    else {
      return r;
    }
  }

private:
  DprsrInpSliceIMetaSbeErrLog i_meta_sbe_err_log_;
  DprsrInpSliceIMetaMbeErrLog i_meta_mbe_err_log_;
  DprsrInpSliceEMetaSbeErrLog e_meta_sbe_err_log_;
  DprsrInpSliceEMetaMbeErrLog e_meta_mbe_err_log_;
  DprsrInpSlicePhv32SbeErrLog phv32_sbe_err_log_;
  DprsrInpSlicePhv32MbeErrLog phv32_mbe_err_log_;
  DprsrInpSlicePhv16SbeErrLog phv16_sbe_err_log_;
  DprsrInpSlicePhv16MbeErrLog phv16_mbe_err_log_;
  DprsrInpSlicePhv8SbeErrLog phv8_sbe_err_log_;
  DprsrInpSlicePhv8MbeErrLog phv8_mbe_err_log_;
  DprsrInpSliceIVoltsSbeErrLog i_volts_sbe_err_log_;
  DprsrInpSliceIVoltsMbeErrLog i_volts_mbe_err_log_;
  DprsrInpSliceEVoltsSbeErrLog e_volts_sbe_err_log_;
  DprsrInpSliceEVoltsMbeErrLog e_volts_mbe_err_log_;
  DprsrInpSliceIFdinfoSbeErrLog i_fdinfo_sbe_err_log_;
  DprsrInpSliceIFdinfoMbeErrLog i_fdinfo_mbe_err_log_;
  DprsrInpSliceEFdinfoSbeErrLog e_fdinfo_sbe_err_log_;
  DprsrInpSliceEFdinfoMbeErrLog e_fdinfo_mbe_err_log_;
  DprsrInpSliceIMetaEccCtrl i_meta_ecc_ctrl_;
  DprsrInpSliceEMetaEccCtrl e_meta_ecc_ctrl_;
  DprsrInpSlicePhv32EccCtrl phv32_ecc_ctrl_;
  DprsrInpSlicePhv16EccCtrl phv16_ecc_ctrl_;
  DprsrInpSlicePhv8EccCtrl phv8_ecc_ctrl_;
  DprsrInpSliceIVoltsEccCtrl i_volts_ecc_ctrl_;
  DprsrInpSliceEVoltsEccCtrl e_volts_ecc_ctrl_;
  DprsrInpSliceIFdinfoEccCtrl i_fdinfo_ecc_ctrl_;
  DprsrInpSliceEFdinfoEccCtrl e_fdinfo_ecc_ctrl_;
  DprsrInpSliceCredFifo cred_fifo_;
  DprsrInpSliceIntr intr_;
private:
  static int StartOffset(
      int index_pipe_addrmap, int index_dprsr_inp_slice
      ) {
    int offset=0;
    offset += 0x4000000; // to get to pipes
    assert(index_pipe_addrmap < 4);
    offset += index_pipe_addrmap * 0x1000000; // pipe_addrmap[]
    offset += 0xc00000; // to get to pardereg
    offset += 0x100000; // to get to dprsrreg
    offset += 0x2b000; // to get to inpslice
    assert(index_dprsr_inp_slice < 4);
    offset += index_dprsr_inp_slice * 0x100; // dprsr_inp_slice[]
    return offset;
  }

};











  }; // namespace register_classes
}; // namespace jbay

#endif // __REGISTER_INCLUDES_DPRSR_INP_SLICE_H__
