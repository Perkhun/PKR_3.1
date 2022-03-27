#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR_3.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s[0].prizv = "Sydorenko";
			s[0].kurs = 1;
			s[0].specialty = ²Ò;
			s[0].physics = 5;
			s[0].math = 4;
			s[0].informatics = 5;

			int lf = CountFour(s, N);
			Assert::AreEqual(lf, 1);

		}
	};
}
