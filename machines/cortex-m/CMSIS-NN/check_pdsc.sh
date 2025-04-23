#!/usr/bin/env bash
#
# SPDX-FileCopyrightText: Copyright 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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
# Version: 1.0
# Date: 2024-03-27
# This bash script checks that ARM.CMSIS-NN.pdsc is up to date.
#
# Pre-requisites:
# - bash shell (for Windows: install git for Windows)


LISTED_SOURCE_FILES=$(mktemp -d)/listed_src_files
ACTUAL_SOURCE_FILES=$(mktemp -d)/actual_src_files

cat ARM.CMSIS-NN.pdsc | grep 'file category="source" ' | sed -r -E 's/.*name="(.*)".*/\1/g' | sort > \
                                                                                                   $LISTED_SOURCE_FILES
git ls-files  ':(glob)Source/' | grep "\.c" | sort > $ACTUAL_SOURCE_FILES

diff $LISTED_SOURCE_FILES $ACTUAL_SOURCE_FILES
