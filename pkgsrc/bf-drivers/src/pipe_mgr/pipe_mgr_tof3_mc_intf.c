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


#include "pipe_mgr_int.h"
#include <tof3_regs/tof3_reg_drv.h>

#if 0
pipe_status_t pipe_mgr_tof3_mc_tvt_grp_addr_get(int mgid_tvt_grp,
                                                 uint32_t *tbl0_addr,
                                                 uint32_t *tbl1_addr) {
  /* The two TVT tables are each of size 16k by 32bits.  One entry holds four 4 bit wide
   * mask for 4 MGID. */
  uint32_t tbl0_base_addr = offsetof(
      tof3_reg, pipes[0].pardereg.dprsrreg.dprsrreg.inp.iim.tv_table.tbl0[0]);
  uint32_t tbl1_base_addr = offsetof(
      tof3_reg, pipes[0].pardereg.dprsrreg.dprsrreg.inp.iim.tv_table.tbl1[0]);
  *tbl0_addr = tbl0_base_addr + 4 * mgid_tvt_grp;
  *tbl1_addr = tbl1_base_addr + 4 * mgid_tvt_grp;
  return PIPE_SUCCESS;
}
#endif

pipe_status_t pipe_mgr_tof3_mc_copy_to_cpu_tvt_addr_get(bf_dev_pipe_t phy_pipe,
                                                        uint32_t *addr) {
  *addr = offsetof(
      tof3_reg,
      pipes[phy_pipe].pardereg.dprsrreg.dprsrreg.inp.ipp.ingr.copy_to_cpu_tv);
  return PIPE_SUCCESS;
}

pipe_status_t pipe_mgr_tof3_mc_tvt_table0_addr_get(bf_dev_pipe_t phy_pipe,
                                                   int mgid_tvt_grp,
                                                   uint32_t *addr) {
  *addr = offsetof(
      tof3_reg,
      pipes[phy_pipe]
          .pardereg.dprsrreg.dprsrreg.inp.iim.tv_table.tbl0[mgid_tvt_grp]);
  return PIPE_SUCCESS;
}

pipe_status_t pipe_mgr_tof3_mc_tvt_c2c_mask_addr_get(bf_dev_pipe_t phy_pipe,
                                                     uint32_t *addr) {
  *addr = offsetof(
      tof3_reg,
      pipes[phy_pipe].pardereg.dprsrreg.dprsrreg.inp.ipp.ingr.tvt_c2c_mask);
  return PIPE_SUCCESS;
}

pipe_status_t pipe_mgr_tof3_mc_yid_tbl_addr_get(uint32_t *addr0,
                                                uint32_t *addr1,
                                                uint32_t *addr2,
                                                uint32_t *addr3) {
  *addr0 = offsetof(
      tof3_reg,
      pipes[0].pardereg.dprsrreg.dprsrreg.ho_i[0].hir.meta.pre_version);
  *addr1 = offsetof(
      tof3_reg,
      pipes[0].pardereg.dprsrreg.dprsrreg.ho_i[1].hir.meta.pre_version);
  *addr2 = offsetof(
      tof3_reg,
      pipes[0].pardereg.dprsrreg.dprsrreg.ho_i[2].hir.meta.pre_version);
  *addr3 = offsetof(
      tof3_reg,
      pipes[0].pardereg.dprsrreg.dprsrreg.ho_i[3].hir.meta.pre_version);
  return PIPE_SUCCESS;
}
