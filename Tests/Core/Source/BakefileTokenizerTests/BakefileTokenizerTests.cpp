/*
    Copyright (c) 2017-2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "BakefileTokenizerTests.h"
#include "CodeSmithy/Bakefile/Core/BakefileTokenizer.h"
#include <fstream>

using namespace Ishiko::Tests;

BakefileTokenizerTests::BakefileTokenizerTests(const TestNumber& number, const TestEnvironment& environment)
	: TestSequence(number, "BakefileTokenizer tests", environment)
{
	append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
	append<HeapAllocationErrorsTest>("getNextToken test 1", GetNextToken);
}

void BakefileTokenizerTests::CreationTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileTokenizer tokenizer(input);

	ISHTF_PASS();
}

void BakefileTokenizerTests::GetNextToken(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileTokenizer tokenizer(input);
    CodeSmithy::BakefileToken token;

	ISHTF_FAIL_UNLESS(tokenizer.getNextToken(token) == CodeSmithy::BakefileTokenizer::eEnd);
	ISHTF_PASS();
}
