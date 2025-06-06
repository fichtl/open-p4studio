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

// MacFactory - Tofino/TofinoB0
// In shared/ because identical across these chips

#include <port.h>
#include <rmt-object-manager.h>
#include <mac-factory.h>
#include <comira-umac3.h>

namespace MODEL_CHIP_NAMESPACE {

// Port->MAC configs from bf-drivers/src/lld/lld_sku.c
// SKU indices from model/runner/main.cpp
//
const uint8_t MacFactory::kSkuPipePortToMac[37][4][17] = {

  { // BFN_77110, 64-full, SKU=0
    { 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  64 },
    { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 255 },
    { 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 255 },
    { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 255 }
  },

  { // BFN_77120, 32Q, SKU=1
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },

  { // BFN_77121_even_02, 32-half-even, SKU=2
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77121_even_03, 32-half-even, SKU=3
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77121_even_12, 32-half-even, SKU=4
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77121_even_13, 32-half-even, SKU=5
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77121_odd_02, 32-half-odd, SKU=6
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77121_odd_03, 32-half-odd, SKU=7
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77121_odd_12, 32-half-odd, SKU=8
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77121_odd_13, 32-half-odd, SKU=9
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },

  { // Unused, SKU=10
    { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 },
    { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
  },

  { // BFN_77131_even_02, 32-half-even, SKU=11
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77131_even_03, 32-half-even, SKU=12
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77131_even_12, 32-half-even, SKU=13
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77131_even_13, 32-half-even, SKU=14
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77131_odd_02, 32-half-odd, SKU=15
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77131_odd_03, 32-half-odd, SKU=16
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77131_odd_12, 32-half-odd, SKU=17
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77131_odd_13, 32-half-odd, SKU=18
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },

  { // BFN_77140_even_02, 32-half-even, SKU=19
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77140_even_03, 32-half-even, SKU=20
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77140_even_12, 32-half-even, SKU=21
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77140_even_13, 32-half-even, SKU=22
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_77140_odd_02, 32-half-odd, SKU=23
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77140_odd_03, 32-half-odd, SKU=24
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77140_odd_12, 32-half-odd, SKU=25
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_77140_odd_13, 32-half-odd, SKU=26
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },

  { // BFN_32d12_even_02, 32-half-even, SKU=27
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_32d12_even_03, 32-half-even, SKU28
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_32d12_even_12, 32-half-even, SKU=29
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_32d12_even_13, 32-half-even, SKU=30
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 }
  },
  { // BFN_32d12_odd_02, 32-half-odd, SKU=31
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_32d12_odd_03, 32-half-odd, SKU=32
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_32d12_odd_12, 32-half-odd, SKU=33
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },
  { // BFN_32d12_odd_13, 32-half-odd, SKU=34
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 }
  },

  { // BFN_77130 (same as BFN_77120)(NOTE *not* used by runner), 32-full-even, SKU=35
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0,  64 },
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
  },
  { // BFN_77130 (NOTE *not* used by runner), 32-full-odd, SKU=36
    { 15, 17, 13, 19, 11, 21,  9, 23,  7, 25,  5, 27,  3, 29,  1, 31,  64 },
    { 16, 14, 18, 12, 20, 10, 22,  8, 24,  6, 26,  4, 28,  2, 30,  0, 255 },
    { 47, 49, 45, 51, 43, 53, 41, 55, 39, 57, 37, 59, 35, 61, 33, 63, 255 },
    { 48, 46, 50, 44, 52, 42, 54, 40, 56, 38, 58, 36, 60, 34, 62, 32, 255 },
  }

};



MacFactory::MacFactory(RmtObjectManager *om)
    : MacFactoryCommon(om) {
}
MacFactory::~MacFactory() {
}

bool MacFactory::get_mac_info(int port_index, int sku, int *mac_index, int *mac_chan) {
  RMT_ASSERT((sku >= RmtDefs::kSkuMin) && (sku <= RmtDefs::kSkuMax));
  RMT_ASSERT((mac_index != nullptr) && (mac_chan != nullptr));
  int  pipe = Port::get_pipe_num(port_index);
  int  per_pipe_mac_unmapped = Port::get_mac_num(port_index);
  int  chan = Port::get_mac_chan(port_index);
  int  mac = -1;
  RMT_ASSERT( get_object_manager()->is_pipe_valid(pipe) && "Invalid Pipe for Port");
  if (per_pipe_mac_unmapped < 17) {
    int lookup_mac = kSkuPipePortToMac[sku][pipe][per_pipe_mac_unmapped];
    if (lookup_mac != 255) {
      mac = lookup_mac; *mac_index = mac; *mac_chan = chan;
    }
  }
  return (mac >= 0);
}

Mac *MacFactory::mac_create(int mac_index) {
  if (mac_index < 0) return nullptr;
  // On Tofino ALL macs are ComiraUmac3
  uint32_t base_addr = mac_base_addr(mac_index);
  return new VmacC3(chip_index(), mac_index, base_addr);
}
void MacFactory::mac_delete(Mac *mac) {
  RMT_ASSERT(mac != nullptr);
  delete mac;
}


}
