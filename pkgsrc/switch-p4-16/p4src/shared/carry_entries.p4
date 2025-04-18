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

0x1FFFE &&& 0xFFFFF : update_carry(1);
0x1FFFF &&& 0xFFFFF : update_carry(2);
0x10000 &&& 0xF0000 : update_carry(1);

0x2FFFC &&& 0xFFFFF : update_carry(2);
0x2FFFD &&& 0xFFFFF : update_carry(2);
0x2FFFE &&& 0xFFFFF : update_carry(3);
0x2FFFF &&& 0xFFFFF : update_carry(3);
0x20000 &&& 0xF0000 : update_carry(2);

0x3FFFC &&& 0xFFFFF : update_carry(3);
0x3FFFD &&& 0xFFFFF : update_carry(4);
0x3FFFE &&& 0xFFFFF : update_carry(4);
0x3FFFF &&& 0xFFFFF : update_carry(4);
0x30000 &&& 0xF0000 : update_carry(3);

0x4FFF8 &&& 0xFFFFF : update_carry(4);
0x4FFF9 &&& 0xFFFFF : update_carry(4);
0x4FFFA &&& 0xFFFFF : update_carry(4);
0x4FFFB &&& 0xFFFFF : update_carry(4);
0x4FFFC &&& 0xFFFFF : update_carry(5);
0x4FFFD &&& 0xFFFFF : update_carry(5);
0x4FFFE &&& 0xFFFFF : update_carry(5);
0x4FFFF &&& 0xFFFFF : update_carry(5);
0x40000 &&& 0xF0000 : update_carry(4);

0x5FFF8 &&& 0xFFFFF : update_carry(5);
0x5FFF9 &&& 0xFFFFF : update_carry(5);
0x5FFFA &&& 0xFFFFF : update_carry(5);
0x5FFFB &&& 0xFFFFF : update_carry(6);
0x5FFFC &&& 0xFFFFF : update_carry(6);
0x5FFFD &&& 0xFFFFF : update_carry(6);
0x5FFFE &&& 0xFFFFF : update_carry(6);
0x5FFFF &&& 0xFFFFF : update_carry(6);
0x50000 &&& 0xF0000 : update_carry(5);

0x6FFF8 &&& 0xFFFFF : update_carry(6);
0x6FFF9 &&& 0xFFFFF : update_carry(6);
0x6FFFA &&& 0xFFFFF : update_carry(7);
0x6FFFB &&& 0xFFFFF : update_carry(7);
0x6FFFC &&& 0xFFFFF : update_carry(7);
0x6FFFD &&& 0xFFFFF : update_carry(7);
0x6FFFE &&& 0xFFFFF : update_carry(7);
0x6FFFF &&& 0xFFFFF : update_carry(7);
0x60000 &&& 0xF0000 : update_carry(6);

0x7FFF8 &&& 0xFFFFF : update_carry(7);
0x7FFF9 &&& 0xFFFFF : update_carry(8);
0x7FFFA &&& 0xFFFFF : update_carry(8);
0x7FFFB &&& 0xFFFFF : update_carry(8);
0x7FFFC &&& 0xFFFFF : update_carry(8);
0x7FFFD &&& 0xFFFFF : update_carry(8);
0x7FFFE &&& 0xFFFFF : update_carry(8);
0x7FFFF &&& 0xFFFFF : update_carry(8);
0x70000 &&& 0xF0000 : update_carry(7);

0x8FFF0 &&& 0xFFFFF : update_carry(8);
0x8FFF1 &&& 0xFFFFF : update_carry(8);
0x8FFF2 &&& 0xFFFFF : update_carry(8);
0x8FFF3 &&& 0xFFFFF : update_carry(8);
0x8FFF4 &&& 0xFFFFF : update_carry(8);
0x8FFF5 &&& 0xFFFFF : update_carry(8);
0x8FFF6 &&& 0xFFFFF : update_carry(8);
0x8FFF7 &&& 0xFFFFF : update_carry(8);
0x8FFF8 &&& 0xFFFFF : update_carry(9);
0x8FFF9 &&& 0xFFFFF : update_carry(9);
0x8FFFA &&& 0xFFFFF : update_carry(9);
0x8FFFB &&& 0xFFFFF : update_carry(9);
0x8FFFC &&& 0xFFFFF : update_carry(9);
0x8FFFD &&& 0xFFFFF : update_carry(9);
0x8FFFE &&& 0xFFFFF : update_carry(9);
0x8FFFF &&& 0xFFFFF : update_carry(9);
0x80000 &&& 0xF0000 : update_carry(8);

0x9FFF0 &&& 0xFFFFF : update_carry(9);
0x9FFF1 &&& 0xFFFFF : update_carry(9);
0x9FFF2 &&& 0xFFFFF : update_carry(9);
0x9FFF3 &&& 0xFFFFF : update_carry(9);
0x9FFF4 &&& 0xFFFFF : update_carry(9);
0x9FFF5 &&& 0xFFFFF : update_carry(9);
0x9FFF6 &&& 0xFFFFF : update_carry(9);
0x9FFF7 &&& 0xFFFFF : update_carry(10);
0x9FFF8 &&& 0xFFFFF : update_carry(10);
0x9FFF9 &&& 0xFFFFF : update_carry(10);
0x9FFFA &&& 0xFFFFF : update_carry(10);
0x9FFFB &&& 0xFFFFF : update_carry(10);
0x9FFFC &&& 0xFFFFF : update_carry(10);
0x9FFFD &&& 0xFFFFF : update_carry(10);
0x9FFFE &&& 0xFFFFF : update_carry(10);
0x9FFFF &&& 0xFFFFF : update_carry(10);
0x90000 &&& 0xF0000 : update_carry(9);
