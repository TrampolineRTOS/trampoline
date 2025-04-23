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
import pathlib
import Lib.test


def generate(params, args):
    """ Generate data for a number of tests and optionally create corresponding code to run the test"""

    # Filter out params from suite to pass on to each test
    def is_common(key):
        return key not in ["tests"]

    common_test_params = {key: val for key, val in params.items() if is_common(key)}

    # Create fpaths related to the test suite
    # NOTE: All paths are relative to the 'cmsis-nn/Tests/UnitTest/' folder
    fpaths = {}
    fpaths["json_template_folder"] = pathlib.Path("RefactoredTestGen") / "JsonTemplates"

    # Generate data for each test
    tests = []
    for test_params in params["tests"]:
        if (test_params["name"] in args.tests) or (args.tests == []):
            print()
            print(f"- {test_params['name']}")

            # Test params overrides common params
            test_params = common_test_params | test_params

            test = Lib.test.generate(test_params, args, fpaths)
            tests.append(test)

    return tests
