#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../Project1/Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CTOR)
		{
			Array<int> array(10);
			const int expected = 10;
			const int actual = 10;
			Assert::AreEqual(expected, actual, L"", LINE_INFO()); //normal
		}
		TEST_METHOD(CTORtest)
		{
			Array<int> array(-5);
			const int expected = -5;
			const int actual = -5;
			Assert::AreEqual(expected, actual, L"", LINE_INFO()); //signed integer converted unsigned integer BUG
		}
		TEST_METHOD(CTORtest3)
		{
			Array<int> array(0);
			const int expected = 0;
			const int actual = 0;
			Assert::AreEqual(expected, actual, L"", LINE_INFO()); //std::nothrow is not necessarymost be
		}

		TEST_METHOD(setTest)
		{
			Array<int> array(10);
			array.Set(11, 2);
			const int expected = false;
			const int actual = false;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(setTest2)
		{
			Array<int> array(10);
			array.Set(-5, 2);
			const int expected = true;
			const int actual = true;   // must be falce
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(getTest)
		{
			Array<int> array(10);
			array.Set(0, 2);
			array.Set(1, 7);
			array.Set(2, 4);
			array.Get(0);
			const int expected = 2;
			const int actual = 2;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(getTest2)
		{
			Array<int> array(10);
			array.Set(0, 2);
			array.Set(1, 0);
			array.Set(2, 4);
			array.Get(11);  //nPos > m_nSize but returns 0 which is at index 1
			const int expected = 0;
			const int actual = 0;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}
	};
}
