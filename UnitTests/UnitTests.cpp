#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Крістіна\source\repos\Function-Calculation-App\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(checkValidPressOne_Tests)
	{
	public:
		
		TEST_METHOD(checkValidPressOne_getminus5_exceptionThrown)
		{
			std::istringstream input(-5);
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkValidPressOne(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkValidPressOne_getF_exceptionThrown)
		{
			std::istringstream input('f');
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkValidPressOne(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkValidPressOne_getsymbol_exceptionThrown)
		{
			std::istringstream input('/');
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkValidPressOne(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkValidPressOne_get1_exceptionNotThrown)
		{
			int n = 1;
			try {
				checkValidPressOne(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};

	/// 
	/// 
	/// 

	TEST_CLASS(checkInputOfN_Tests)
	{
	public:

		TEST_METHOD(checkInputOfN_getminus1_exceptionThrown)
		{
			std::istringstream input(-1);
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfN(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfN_get1_exceptionThrown)
		{
			std::istringstream input(1);
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfN(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfN_getsymbol_exceptionThrown)
		{
			std::istringstream input('<');
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfN(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfN_geta_exceptionThrown)
		{
			std::istringstream input('a');
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfN(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfN_get0point5_exceptionThrown)
		{
			std::istringstream input(0.5);
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfN(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfN_get1point5_exceptionThrown)
		{
			std::istringstream input(1.5);
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfN(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfN_get1_exceptionNotThrown)
		{
			int n = 2;
			try {
				checkInputOfN(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};

	/// 
	/// 
	/// 

	TEST_CLASS(checkInputOfA_Tests)
	{

	public:

		TEST_METHOD(checkInputOfA_geta_exceptionThrown)
		{
			std::istringstream input('a');
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfA(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfA_getsymbol2_exceptionThrown)
		{
			std::istringstream input("<");
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;    
				checkInputOfA(x);    
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfA_getminus10_exceptionNotThrown)
		{
			int n = -10;
			try {
				checkInputOfA(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	public:

		TEST_METHOD(checkInputOfA_get3point5_exceptionNotThrown)
		{
			double n = 3.5;
			try {
				checkInputOfA(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};

	/// 
	/// 
	/// 

	TEST_CLASS(checkInputOfB_Tests)
	{

	public:

		TEST_METHOD(checkInputOfB_get1and0point5_exceptionThrown)
		{
			std::istringstream input("1 0.5");
			std::cin.rdbuf(input.rdbuf());

			try {
				double a;
				double b;
				std::cin >> a >> b;
				checkInputOfB(a, b);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfB_getminus5andminus7_exceptionThrown)
		{
			std::istringstream input("-5 -7");
			std::cin.rdbuf(input.rdbuf());

			try {
				double a;
				double b;
				std::cin >> a >> b;
				checkInputOfB(a, b);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfB_get1and1point5_exceptionNotThrown)
		{
			int a = 1;
			double b = 1.5;
			try {
				checkInputOfB(a, b);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	public:

		TEST_METHOD(checkInputOfB_getminus3andminus2_exceptionNotThrown)
		{
			int a = -3;
			int b = -2;
			try {
				checkInputOfB(a, b);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};

	/// 
	/// 
	/// 

	TEST_CLASS(checkInputOfStep_Tests)
	{
	public:

		TEST_METHOD(checkInputOfStep_getminus5_exceptionThrown)
		{
			std::istringstream input(-5);
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfStep(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	public:

		TEST_METHOD(checkInputOfStep_get0_exceptionThrown)
		{
			std::istringstream input(0);
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfStep(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

	public:

		TEST_METHOD(checkInputOfStep_getletter_exceptionThrown)
		{
			std::istringstream input("s");
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfStep(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	public:

		TEST_METHOD(checkInputOfStep_getsymbol_exceptionThrown)
		{
			std::istringstream input(">");
			std::cin.rdbuf(input.rdbuf());

			try {
				double x;
				std::cin >> x;
				checkInputOfStep(x);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	public:

		TEST_METHOD(checkInputOfStep_get1_exceptionNotThrown)
		{
			int n = 1;
			try {
				checkInputOfStep(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	public:

		TEST_METHOD(checkInputOfStep_get1point5_exceptionNotThrown)
		{
			double n = 1.5;
			try {
				checkInputOfStep(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};

	/// 
	/// 
	/// 

	TEST_CLASS(functionCalculations_Tests) 
	{

	public:

		TEST_METHOD(functionCalculations_get1and2and1and2_108returned)
		{
			double a = 1.0;
			double b = 2.0;
			double step = 1.0;
			int n = 2;
			double expectedY = 108.0;

			double actual = functionCalculations(n, step, a, b);

			Assert::AreEqual(expectedY, actual);
		}

	public:

		TEST_METHOD(functionCalculations_getminus2and5and0point5and3_35767point3expected)
		{
			int a = -2;
			int b = 5;
			double step = 0.5;
			int n = 3;
			double expectedY = 35767.33;

			double actual = functionCalculations(n, step, a, b);

			Assert::AreEqual(expectedY, actual, 0.01);
		}
	};
}
