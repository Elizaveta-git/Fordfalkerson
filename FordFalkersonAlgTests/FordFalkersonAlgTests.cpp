#include "pch.h"
#include "CppUnitTest.h"
#include "..//FordFalkersonAlg/FordFalkersonAlg.h"
#include "..//FordFalkersonAlg/FordFalkersonAlg.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FordFalkersonAlgTests
{
	TEST_CLASS(FordFalkersonAlgTests)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			FordFalkerson a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "S B 6";
				out << endl;
				out << "S A 10";
				out << endl;
				out << "A B 4";
				out << endl;
				out << "A E 7";
				out << endl;
				out << "B C 11";
				out << endl;
				out << "B D 8";
				out << endl;
				out << "C T 8";
				out << endl;
				out << "D T 5";
				out << endl;
				out << "E T 8";
				out << endl;
				out << "E D 4";
			}
			out.close();
			a.ReadFromFile("graph.txt");
			Assert::AreEqual(a.alg("S", "T"), 16);
		}
		TEST_METHOD(Test2)
		{
			FordFalkerson a;
			ofstream out;
			out.open("graph.txt");
			if (out.is_open())
			{
				out << "S O 3";
				out << endl;
				out << "S P 3";
				out << endl;
				out << "O Q 3";
				out << endl;
				out << "O P 2";
				out << endl;
				out << "P R 2";
				out << endl;
				out << "Q R 4";
				out << endl;
				out << "Q T 2";
				out << endl;
				out << "R T 3";
			}
			out.close();
			a.ReadFromFile("graph.txt");
			Assert::AreEqual(a.alg("S", "T"), 5);
		}
	};
}
