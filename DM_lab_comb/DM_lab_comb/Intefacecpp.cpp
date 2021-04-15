#include <iostream>
#include <sstream>
#include "Comb.h"

using namespace std;


void init() {
	cout << "Programm calculates basic combinatorial numbers\n\n"
		"Type H to see available commands and their short explanation\n"
		"Type H [command] for more details on a particular command\n"
		"Type Q to shut down the programm\n\n";
}

void help(const string& command)
{
	if (command.empty())
	{
		cout << "U <m> <n>\t\tCalculate m permutations of n with repetition. U(m,n) = m^n\n"
			"C <m> <n>\t\tCalculate number of combinations(m choose n) without repetition. C(m,n) = n!/(m!(n-m)!)\n"
			"A <m> <n>\t\tCalculate m permutations of n without repetition. A(m,n) = n!/(n-m)!\n"
			"P <n>\t\t\tCalculate number of n permutations without repetition. P(n) = n!\n"
			"S <m> <n>\t\tCalculate Stirling number of second kind. S(m,n) = S(m-1,n) + nS(m-1,n)\n"
			"B <n>\t\t\tCalculate Bell number. B(n) = sum(S(m,n)) for m = 0..n";
	}
	else if (command == " U")
	{
		cout << "U <m> <n>\nCalculate m permutations of n with repetition.\nFormula - U(m,n)=m^n\n"
		"An attempt to enter parameters with negative values will cause an error message";
	}
	else if (command == " C")
	{
		cout << "C <m> <n>\nCalculate number of combinations(m choose n) without repetition.\n"
		"Formula - C(m,n)=n!/(m!(n-m)!)\n"
		"C(m,n) = 0 if n > m\n"
		"An attempt to enter parameters with negative values will cause an error message";
	}
	else if (command == " A")
	{
		cout << "A <m> <n>\nCalculate m permutations of n without repetition.\n"
			"Formula - A(m,n) = n!/(n-m)!\n"
			"A(m,n) = 0 if n > m\n"
			"An attempt to enter parameters with negative values will cause an error message";
	}
	else if (command == " P")
	{
		cout << "P <n>\nCalculate number of n permutations without repetition.\n"
			"Formula - P(n) = n!\n"
			"An attempt to enter parameters with negative values will cause an error message";
	}
	else if (command == " S")
	{
		cout << "S <m> <n>\nCalculate Stirling number of second kind.\n"
			"Formula - S(m,n) = S(m,n) = S(m-1,n) + nS(m-1,n), S(m,0) = 0, S(0,n) = 0, S(n,n) = 1\n"
			"S(m,n) = 0 if n > m\n"
			"An attempt to enter parameters with negative values will cause an error message";
	}
	else if (command == " B")
	{
		cout << "B <n>\nCalculate Bell number.\nFormula - B(n) = sum(S(m,n)) for m = 0..n\n"
			"An attempt to enter parameters with negative values will cause an error message";
	}
	else
	{
		throw invalid_argument("No help on this command");
	}
	
}

bool has_two_param(const string& N)
{
	if (N == "C" || N == "A" || N == "U" || N == "S")
		return true;
	return false;
}



bool has_one_param(const string& N)
{
	if (N == "P" || N == "B")
		return true;
	return false;
}


unsigned one_param_action(char c,unsigned int n)
{
	Calculator calc;
	if (c == 'P')
		return calc.P(n);
	else if (c == 'B')
		return calc.B(n);
	else
		throw invalid_argument("Unknown command");
}

unsigned two_param_action(const char c,unsigned int n,unsigned int m)
{
	Calculator calc;
	if (c == 'C')
		return calc.C(m, n);
	else if (c == 'A')
		return calc.A(m, n);
	else if (c == 'S')
		return calc.S(m, n);
	else if (c == 'U')
		return calc.U(m, n);
	else
		throw invalid_argument("Unknown command");
}


unsigned parse_command(const string& command)
{
	if (command == "Q")
		return QUIT;
	if (command[0] == 'H')
	{
		string param = command.substr(1);
		help(param);
	}
	stringstream stream(command);
	string action;
	stream >> action;
	/*if (has_one_param(action))
	{
		string rest = command.substr(1);
		stringstream stream(rest);
		int n;
		if (!(stream >> n))
		{
			string message = "Unknown parameters: " + rest;
			throw invalid_argument(message);
		}
		return one_param_action(command[0],n);
	}*/
	if (has_one_param(action))
	{

		unsigned n;
		if (stream.peek()==' ')
			stream.ignore(1);
		char sign = stream.peek();
		if (sign == '-')
			throw invalid_argument("Parameter must be a non negative integer");
		if (!(stream >> n) || !stream.eof())
		{
			string message = "Invalid parameters";
			throw invalid_argument(message);
		}
		return one_param_action(command[0], n);
	}
	else if (has_two_param(action))
	{
		
		unsigned n, m;
		if (stream.peek() == ' ')
			stream.ignore(1);
		if (stream.peek() == '-')
			throw invalid_argument("Parameter must be a non negative integer");
		if (!(stream >> m))
			throw invalid_argument("Invalid parameters");
		if (stream.peek() == ' ')
			stream.ignore(1);
		if (stream.peek() == '-')
			throw invalid_argument("Parameter must be a non negative integer");
		if (!(stream >> n) || !stream.eof())
		{
			string message = "Invalid parameters";
			throw invalid_argument(message);
		}
		return two_param_action(command[0], m, n);
	}
	else
		throw invalid_argument("Invalid command");
}


