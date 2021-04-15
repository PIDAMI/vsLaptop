#include "Comb.h"

using namespace std;
unsigned int dpow(unsigned int x,unsigned int y)
{
	swap(x, y);
	unsigned int res = 1;
	while (y) {
		if (y & 1)
			res *= x;
		x *= x;
		y >>= 1;
	}
	return res;
}

unsigned  Calculator::U(unsigned m, unsigned n) const
{
	if (m > pow(UINT32_MAX,1.0/n))	throw invalid_argument("Result exceeds limit for 32 bits numbers");
	auto res = dpow(m, n);
	return res;
}



unsigned  Calculator::A(unsigned m, unsigned n) const
{
	if (m < 0 || n < 0) throw invalid_argument("Parameters must be non-negative integers");
	if (n > m) return 0;
	if (!n) return 1;
	unsigned int res = 1;
	for (auto i = m - n + 1; i < m + 1; i++) {
		if (UINT32_MAX/i <= res) throw invalid_argument("Result exceeds limit for 32 bits numbers");
		res *= i;
	}
	return res;
}

unsigned  Calculator::P(unsigned n) const
{
	if (n < 0) throw invalid_argument("Parameter must be a non-negative integer");
	if (!n) return 1;
	if (n > 12) throw invalid_argument("Result exceeds limit for 32 bits numbers");
	unsigned res = 1;
	for (unsigned i = 1; i <= n; i++)
		res *= i;
	return res;
}

unsigned  Calculator::C(unsigned m, unsigned n) const
{
	if (n > m) return 0;
	if (n == 1 || n + 1 == m) return m;
	if (n == m || !n) return 1;
	if (n > m - n) n = m - n;
	vector<unsigned> paskal_triang;
	for (unsigned i = 0; i <= n; i++)
	{
		paskal_triang.push_back(1);
	}
	for (unsigned i = 1; i <= m-n;i++)
	{
		for (unsigned j = 1; j <= n; j++) {
			if (j == n && paskal_triang[j] >= UINT32_MAX - paskal_triang[j - 1])
				throw invalid_argument("Result exceeds limit for 32 bits numbers");
			paskal_triang[j] += paskal_triang[j - 1];
		}
	}
	
	//if (paskal_triang[n] > UINT32_MAX)
	//	throw invalid_argument("Result exceeds limit for 32 bits numbers");
	return paskal_triang[n];

}


unsigned  Calculator::S(unsigned m, unsigned n) const
{
	//if (m < 0 || n < 0) throw invalid_argument("Parameters must be non-negative integers");
	if (n > m) return 0;
	if (n == 1 ) return 1;
	if (n == m ) return 1;
	if (!n) return 0;
	unsigned d = min(n, m - n + 1);
	vector<unsigned int> D;
	unsigned s = max(n, m - n + 1);
	for (unsigned i = 1; i <= d; i++)
		D.push_back(1);
	for (unsigned int i = 2; i <= s; i++)
	{
		for (unsigned int j = 1; j < d; j++) {
			if (d == n) {
				if (D[j] >= (UINT32_MAX  - D[j - 1]) / (j + 1))
					throw invalid_argument("Result exceeds limit for 32 bits numbers");
				D[j] = D[j - 1] + (j + 1) * D[j];
			}
			else {
				if (D[j-1] >= (UINT32_MAX - D[j]) / i)//
					throw invalid_argument("Result exceeds limit for 32 bits numbers");
				D[j] = D[j] + i * D[j - 1];
			}
		}
			
			//D[j] = d == n ? D[j - 1] + (j + 1) * D[j] : D[j] + i * D[j - 1];
	}
	//if (D[d-1] > UINT32_MAX)
	//	throw invalid_argument("Result exceeds limit for 32 bits numbers");

	return D[d-1];
}


unsigned  Calculator::B(unsigned n) const
{
	if (!n) return 1;
	//if (n < 0) throw invalid_argument("Parameters must be non-negative integers");
	if (n > 15) throw invalid_argument("Result exceeds limit for 32 bits numbers");

	unsigned int res = 0;
	for (unsigned m = 0; m <= n; m++)
	{
		res += S(n, m);
	}
	
	return res;
}
