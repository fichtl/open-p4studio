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

#ifndef PARDE_HARNESS_INPUT
#define PARDE_HARNESS_INPUT 1

#include <vector>
#include <model_core/model.h>

extern bool raw_mode;

int load_cfg_blob (FILE *fd, model_core::Model *intf, unsigned pipes);

const char *str_to_bytes(const char *pkt_str, std::vector<uint8_t> &pkt_bytes,
                         std::vector<uint8_t> *mask = 0);

#endif
