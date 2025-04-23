#
# SPDX-FileCopyrightText: Copyright 2019-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the License); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

file(GLOB SRC_S4 "./*_s4*.c")
file(GLOB SRC_S8 "./*_s8*.c")
file(GLOB SRC_S16 "./*_s16*.c")
file(GLOB SRC_S32 "./*_s32*.c")
target_sources(cmsis-nn PRIVATE ${SRC_S4} ${SRC_S8} ${SRC_S16} ${SRC_S32} arm_nntables.c
  arm_q7_to_q15_with_offset.c
  arm_s8_to_s16_unordered_with_offset.c)
