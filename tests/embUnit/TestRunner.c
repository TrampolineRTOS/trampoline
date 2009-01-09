/*
 * COPYRIGHT AND PERMISSION NOTICE
 * 
 * Copyright (c) 2003 Embedded Unit Project
 * 
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, and/or sell copies of the Software, and to permit persons 
 * to whom the Software is furnished to do so, provided that the above 
 * copyright notice(s) and this permission notice appear in all copies 
 * of the Software and that both the above copyright notice(s) and this 
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT 
 * OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY 
 * SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER 
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF 
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 * Except as contained in this notice, the name of a copyright holder 
 * shall not be used in advertising or otherwise to promote the sale, 
 * use or other dealings in this Software without prior written 
 * authorization of the copyright holder.
 *
 * $Id: TestRunner.c,v 1.1.1.1 2008/01/17 08:47:19 LaurentMenard Exp $
 */
#include "config.h"
#include "stdImpl.h"
#include "Test.h"
#include "TestListener.h"
#include "TestResult.h"
#include "TestRunner.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"

static TestResult result_;
static Test* root_;

static void TestRunner_startTest(TestListner* self,Test* test)
{
	stdimpl_print(".");
}

static void TestRunner_endTest(TestListner* self,Test* test)
{
}

static void TestRunner_addFailure(TestListner* self,Test* test,char* msg,int line,char* file)
{
	UART_envoyer_chaine("\n");
	UART_envoyer_chaine(Test_name(root_));
	UART_envoyer_chaine(".");
	UART_envoyer_chaine(Test_name(test));
	{
		char buf[16];
		UART_envoyer_chaine(" (");
		UART_envoyer_chaine(file);
		UART_envoyer_chaine(" ");
		stdimpl_itoa(line, buf, 10);
		UART_envoyer_chaine(buf);
		UART_envoyer_chaine(") ");
	}
	UART_envoyer_chaine(msg);
	UART_envoyer_chaine("\n");
}

static const TestListnerImplement TestRunnerImplement = {
	(TestListnerStartTestCallBack)	TestRunner_startTest,
	(TestListnerEndTestCallBack)	TestRunner_endTest,
	(TestListnerAddFailureCallBack)	TestRunner_addFailure,
};

static const TestListner testrunner_ = {
	(TestListnerImplement*)&TestRunnerImplement,
};

void TestRunner_start(void)
{
	TestResult_init(&result_, (TestListner*)&testrunner_);
}

void TestRunner_runTest(Test* test)
{
	root_ = test;
	Test_run(test, &result_);
}

void TestRunner_end(void)
{
	char buf[16];
	if (result_.failureCount) {
		UART_envoyer_chaine("\nrun ");
		stdimpl_itoa(result_.runCount, buf, 10);
		UART_envoyer_chaine(buf);
		UART_envoyer_chaine(" failures ");
		stdimpl_itoa(result_.failureCount, buf, 10);
		UART_envoyer_chaine(buf);
		UART_envoyer_chaine("\n");
	} else {
		UART_envoyer_chaine("\nOK (");
		stdimpl_itoa(result_.runCount, buf, 10);
		UART_envoyer_chaine(buf);
		UART_envoyer_chaine(" tests)\n");
	}
}
