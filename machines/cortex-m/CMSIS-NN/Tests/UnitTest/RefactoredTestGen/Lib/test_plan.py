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
import json
import Lib.test_suite
import sys


def generate(args):
    """Generate a number of test suites defined by a json-file test plan"""

    test_plan = args.test_plan.read_text()
    test_suite_params_list = json.loads(test_plan)

    # List available tests for convenience
    if args.list:
        for suite in test_suite_params_list:
            print(f"{suite['suite_name']}")
            for test in suite["tests"]:
                print(f"- {test['name']}")

        sys.exit()

    test_suites = []
    for s in args.test_suites:
        test_suites.append(list(filter(None, str.split(s, '/')))[-1])

    print(f"\nGenerating tests from {args.test_plan}")
    for test_suite_params in test_suite_params_list:
        if (test_suite_params["suite_name"] in test_suites) or (test_suites == []):
            test_names = [test["name"] for test in test_suite_params["tests"] if test["name"] in args.tests]
            if (len(test_names) > 0) or (args.tests == []):
                print(f"{test_suite_params['suite_name']}")
                Lib.test_suite.generate(test_suite_params, args)
