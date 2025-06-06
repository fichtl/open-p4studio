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

// XXXb -> test_dv67.cpp - back to back packets with color - tests the color write queueing
#include <utests/test_util.h>
#include <iostream>
#include <string>
#include <array>
#include <cassert>

#include "gtest.h"

#include <bitvector.h>
#include <rmt-object-manager.h>
#include <model_core/model.h>
#include <mau.h>

extern std::unique_ptr<model_core::Model> GLOBAL_MODEL;


namespace MODEL_CHIP_TEST_NAMESPACE {

  bool dv67_print = false;

  using namespace std;
  using namespace MODEL_CHIP_NAMESPACE;


TEST(BFN_TEST_NAME(Dv67Test),Packet1) {
    GLOBAL_MODEL->Reset();
    if (dv67_print) RMT_UT_LOG_INFO("test_dv67_packet1()\n");
    
    // Create our TestUtil class
    uint64_t pipes, stages, types, rows_tabs, cols, flags;
    pipes = ALL; stages = FEW; types = NON; rows_tabs = TOP;
    pipes = ALL; stages = ALL; types = ALL; rows_tabs = ALL; cols = ALL; flags = ALL;

    int chip = 202;
    int pipe = 0;
    int stage = 0;
    TestUtil tu(GLOBAL_MODEL.get(), chip, pipe, stage);
    tu.set_debug(false);
    tu.set_evaluate_all(true, false); // Don't test evaluateAll
    tu.set_free_on_exit(true);
    tu.set_dv_test(67);
    // Added next line 10/04/2015 - DV tests derived from this file
    // from now on, will be assumed to set PerFlowEnables in addresses.
    tu.set_pfe_mode(true); 

    // Just to stop compiler complaining about unused vars
    flags = FEW; // Just FatalErrorWarn
    // Uncomment below to up the debug output
    //flags = ALL;
    tu.update_log_flags(pipes, stages, types, rows_tabs, cols, flags, ALL);
    
    
    // Setup a port on pipe 0
    // This also sets up basic config ingress parser and deparser
    (void)tu.port_get(16);

    RmtObjectManager *om = tu.get_objmgr();
    (void)om->mau_lookup(pipe, stage);

#define DELAY_IS_13
    
#ifdef DELAY_IS_14
        ASSERT_TRUE(tu.read_test_file("extracted_tests/test_dv67_delay_14.test"));
#else
  #ifdef DELAY_IS_13
        ASSERT_TRUE(tu.read_test_file("extracted_tests/test_dv67_delay_13.test"));
  #else
    #error "Must define the delay"
  #endif
#endif

    

        
    tu.finish_test();
    tu.quieten_log_flags();
}


}
