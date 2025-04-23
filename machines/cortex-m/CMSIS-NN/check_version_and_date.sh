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
# Date: 2024-05-21
# This bash script checks that files changed in the Source and Include directory have 
# modifed the Revision and Date fields below the license in each file.

SHA=$(git rev-parse origin/upstream/main)
CHANGED_FILES=$(git diff --name-only ${SHA} HEAD -- Source Include)
ANY_FAILURE=0

echo "++ Checking if version and date was updated in changed files"
echo " ------ "
for file in ${CHANGED_FILES[@]}
do
    if [[ ${file} != *"CMake"* ]]; then
        diff=$(git diff ${SHA} HEAD ${file})
        # This pattern matches "(+|-) * $DATE: Day Month Year"
        echo "$diff" | grep -E '(-|\+)\s*\*\s*\$[Date]+:\s*[0-9]+\s*[A-Za-z]+\s*[0-9]+' -vqz
        if [[ $? -eq 0 ]]; then
            echo "${file}: FAILED"
            ANY_FAILURE=1
        else
            # This pattern matches "(+|-) * $REVISION: V.X.X.X"
            echo "$diff" | grep -E '(-|\+)\s*\*\s*\$[Revision]+:\s*V\.[0-9]+\.[0-9]+\.[0-9]+' -vqz
            if [[ $? -eq 0 ]]; then
                echo "${file}: FAILED"
                ANY_FAILURE=1
            else
                echo "${file}: OK"
            fi
        fi
    fi
done

if [[ $ANY_FAILURE -eq 1 ]]; then
    echo " ------ "
    echo "At least one file did not pass the revision and date check. Exiting with failure."
    exit 1
elif [[ $ANY_FAILURE -eq 0 ]]; then
    echo " ------ "
    echo "All files passed the revision and date check. Exiting successfully."
fi