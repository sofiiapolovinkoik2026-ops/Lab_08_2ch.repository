#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_2ch/Lab_08_2ch.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82C
{
	TEST_CLASS(UnitTest82C)
	{
	public:
		TEST_METHOD(TestRemoveSpaces)
		{
			char str[100] = "Hello  , world   !";
			char dest[100];
			RemoveSpaces(dest, str);
			Assert::AreEqual("Hello, world!", dest);
		}
	};
}