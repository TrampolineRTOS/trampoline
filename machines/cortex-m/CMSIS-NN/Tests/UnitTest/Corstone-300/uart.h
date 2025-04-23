/*
 * SPDX-FileCopyrightText: Copyright 2019-2021, 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef UART_STDOUT_H
#define UART_STDOUT_H

#if __cplusplus
extern "C" {
#endif

void uart_init(void);
unsigned char uart_putc(unsigned char my_ch);
unsigned char uart_getc(void);

#if __cplusplus
}
#endif

#endif /* UART_STDOUT_H */
