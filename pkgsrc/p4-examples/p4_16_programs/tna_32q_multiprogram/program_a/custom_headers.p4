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

#ifndef _CUSTOM_HEADERS_
#define _CUSTOM_HEADERS_

#if __TARGET_TOFINO__ == 2
#include <t2na.p4>
#else
#include <tna.p4>
#endif

typedef bit<48> mac_addr_t;
typedef bit<32> ipv4_addr_t;
const bit<16> ETHERTYPE_IPV4 = 16w0x0800;

header ethernet_h {
    mac_addr_t dst_addr;
    mac_addr_t src_addr;
    bit<16> ether_type;
}

header ipv4_h {
    bit<4> version;
    bit<4> ihl;
    bit<8> diffserv;
    bit<16> total_len;
    bit<16> identification;
    bit<3> flags;
    bit<13> frag_offset;
    bit<8> ttl;
    bit<8> protocol;
    bit<16> hdr_checksum;
    ipv4_addr_t src_addr;
    ipv4_addr_t dst_addr;
}

header custom_metadata_h {
// Value of the tag during pipeline processing:
//  VALUE  - PIPELINE
//   x     - set to user defined value in ingress pipeline_profile_a
//   x+1   - pipeline_profile_b egress
//   x+2   - pipeline_profile_b ingress
//   x+3   - pipeline_profile_a egress
    bit<16> custom_tag;
}

struct custom_header_t {
    ethernet_h ethernet;
    ipv4_h ipv4;

    // Add more headers here.
    custom_metadata_h custom_metadata;
}

struct digest_a_t {
    mac_addr_t dst_addr;
    mac_addr_t src_addr;
}

struct digest_b_t {
    ipv4_addr_t dip;
    ipv4_addr_t sip;
}

#endif /* _CUSTOM_HEADERS_ */
