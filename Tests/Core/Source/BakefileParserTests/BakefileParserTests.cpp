/*
    Copyright (c) 2017 Xavier Leclercq

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

#include "BakefileParserTests.h"
#include "CodeSmithy/Bakefile/Core/BakefileParser.h"
#include <fstream>

void AddBakefileParserTests(TestHarness& theTestHarness)
{
    TestSequence& bakefileParserTestSequence = theTestHarness.appendTestSequence("BakefileParser tests");

    new HeapAllocationErrorsTest("Creation test 1", BakefileParserCreationTest1, bakefileParserTestSequence);

    new HeapAllocationErrorsTest("parse test 1", BakefileParserParseTest1, bakefileParserTestSequence);
    new HeapAllocationErrorsTest("parse test 2", BakefileParserParseTest2, bakefileParserTestSequence);
}

TestResult::EOutcome BakefileParserCreationTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileParser parser(input);
    input.close();

    return TestResult::ePassed;
}

TestResult::EOutcome BakefileParserParseTest1(Test& test)
{
    TestResult::EOutcome result = TestResult::eFailed;

    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileParser parser(input);
    std::shared_ptr<CodeSmithy::Bakefile> bakefile = parser.parse();
    input.close();

    if (bakefile->targets().empty())
    {
        result = TestResult::ePassed;
    }

    return result;
}

TestResult::EOutcome BakefileParserParseTest2(Test& test)
{
    TestResult::EOutcome result = TestResult::eFailed;

    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "EmptyTargetBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileParser parser(input);
    std::shared_ptr<CodeSmithy::Bakefile> bakefile = parser.parse();
    input.close();

    if (bakefile->targets().size() == 1)
    {
        result = TestResult::ePassed;
    }

    return result;
}
