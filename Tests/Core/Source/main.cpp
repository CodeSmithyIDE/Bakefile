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

#include "BakefileTargetTests.h"
#include "BakefileTests/BakefileTests.h"
#include "BakefileTokenTests.h"
#include "BakefileTokenizerTests/BakefileTokenizerTests.h"
#include "BakefileParserTests/BakefileParserTests.h"
#include "Ishiko/TestFramework/TestFrameworkCore.h"

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    Ishiko::Tests::TestHarness theTestHarness("CodeSmithyBakefileCore");

	theTestHarness.environment().setTestDataDirectory("../../TestData");

	TestSequence& theTests = theTestHarness.tests();
	theTests.append<BakefileTargetTests>();
	theTests.append<BakefileTests>();
	theTests.append<BakefileTokenTests>();
	theTests.append<BakefileTokenizerTests>();
	theTests.append<BakefileParserTests>();

    return theTestHarness.run();
}
