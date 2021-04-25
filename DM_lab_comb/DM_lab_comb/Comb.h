#pragma once


#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <string>
#include <limits>
#define QUIT -13



class Calculator
{
private:

public:
	unsigned int U(unsigned m, unsigned n) const;
	unsigned int C(unsigned m, unsigned n) const;
	unsigned int A(unsigned m, unsigned n) const;
	unsigned int P(unsigned n) const;
	unsigned int S(unsigned m, unsigned n) const;
	unsigned int B(unsigned n) const;
};

void init();
void help(const std::string& command);
unsigned int dpow(unsigned int x, unsigned int y);
unsigned parse_command(const std::string& command);
unsigned two_param_action(const char c,unsigned int n,unsigned int m);
unsigned one_param_action(char c,unsigned int n);
bool has_one_param(const std::string& N);
bool has_two_param(const std::string& N);
