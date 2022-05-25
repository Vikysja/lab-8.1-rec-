#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
	TEST_CLASS(UnitTest81rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            char str[] = "BASIC AND Delphi";
            char letters[] = "BASIC";

            const int count = CountIncludes(str, letters);

            Assert::AreEqual(6, count);
        };

        TEST_METHOD(TestChange)
        {
            char str[] = "BASIC, Python and BASIC";
            char letters[] = "BASIC";

            char* dest = new char[30];
            dest = Change(str, "BASIC", "Delphi");

            Assert::AreEqual("Delphi, Python and Delphi", dest);
        };
    };
}
