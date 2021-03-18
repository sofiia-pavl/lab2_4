#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2_4a/Matrix.h"
#include "C:\Users\Софія\source\repos\lab2_4a\lab2_4a\Matrix.cpp"
#include "../lab2_4a/Array.h"
#include "C:\Users\Софія\source\repos\lab2_4a\lab2_4a\Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest4
{
	TEST_CLASS(UnitTest4)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix a(2),c(2);
			Assert::AreEqual(a == c, true);
		}
	};
}
