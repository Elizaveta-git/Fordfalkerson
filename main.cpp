#include "FordFalkersonAlg.h"

int main()
{
	FordFalkerson Alg;
	string Begin, End;
	string file = "graph.txt";
	cout << "Enter the city of departure: ";
	cin >> Begin;
	cout << "Enter the city of arrival: ";
	cin >> End;
	ofstream out;
	out.open(file);
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
	Alg.ReadFromFile(file);
	cout << "Result: "<<Alg.alg(Begin, End);
}