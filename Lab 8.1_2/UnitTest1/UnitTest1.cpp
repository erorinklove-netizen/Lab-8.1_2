#define _CRT_SECURE_NO_WARNINGS
#include "pch.h" // Для Visual Studio Unit Test
#include "CppUnitTest.h"
#include "D:\education\Lab 8.1_2\Lab 8.1_2.cpp" // Шлях до вашого файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Lab812Tests)
	{
	public:

		TEST_METHOD(TestCountWhile)
		{
			// Arrange
			const char* testStr = "while hello while";

			// Act
			int count = CountWhileRec(testStr, 0);

			// Assert
			Assert::AreEqual(2, count);
		}

		TEST_METHOD(TestChangeWhile)
		{
			// Arrange
			const char* testStr = "abc while xyz";
			char res[100] = "";

			// Act
			ChangeWhileRec(testStr, res, 0, 0);

			// Assert
			Assert::AreEqual("abc ***** xyz", res);
		}

		TEST_METHOD(TestNoWhile)
		{
			const char* testStr = "normal string";
			char res[100] = "";

			Assert::AreEqual(0, CountWhileRec(testStr, 0));
			ChangeWhileRec(testStr, res, 0, 0);
			Assert::AreEqual("normal string", res);
		}
	};
}