#include "RK.h"
#include "fstream"


using namespace std;

void print_vec(ofstream& file, const vector<double>& v)
{
	for (const auto& val:v)
	{
		file << val << ' ';
	}

}

void print_err(ofstream& file, const vector<double>& x, const vector<double>& y, const vector<double>& y_ex)
{
	print_vec(file,x);
	auto err = y;
	for (size_t i =0;i < err.size();i++)
	{
		err[i] = fabs(y[i] - y_ex[i]);
	}
	print_vec(file, err);
}


void print_init(ofstream& file, const vector<double>& x, const vector<double>& y)
{
	print_vec(file, x);
	print_vec(file, y);

}


int main(int argc, char** argv)
{
	ofstream file("d.txt");
	if (!file.is_open())
	{
		cout << "file not found";
		exit(1);
	}
	double big_step = 0.5;
	
	
	double h = 0.2;
	if (argc > 1)
		h = strtod(argv[1],NULL);
	int action = 1; // 1 - init, 2 - error, 3 - eps, 4 - iterations, 5 - init_val err
	if (argc > 2)
		action = strtol(argv[2],NULL,10);
	if (argc > 3)
		big_step = strtod(argv[3], NULL);

	
	auto x = nodes_step(a, b, h);

	auto y_exact = Y(x);
	auto y_eval = runge_kutta(a, b, ya, h);
	elem_int(0.01, a, a + h, ya, action);

	if (action == 1)
		print_init(file, x, y_eval);
	else if (action == 2)
		print_err(file, x, y_eval, y_exact);
	else if (action == 3 )
	{
		vector<double> mx;

		auto x = nodes_step(a, b, big_step);
		auto y_exact = Y(x);
		for (int i = 1; i <= static_cast<int>(h); i++) {

			int k = 1;
			y_eval = eps_runge_kutta(a, b, ya, pow(10,-i),big_step,k);
			mx.push_back(fabs(y_eval[0]-y_exact[0]));
			for (size_t j = 1; j < y_eval.size(); j++)
			{
				double error = fabs(y_eval[j] - y_exact[j]);
				if (error > mx[i - 1])
					mx[i - 1] = error;
			}
		}
		for (auto& val : mx)
			file << val << ' ';
	}
	else if (action == 4)
	{
		vector <double> iter;
		for (int i = 1; i <= static_cast<int>(h); i++) {

			int it = 1;
			y_eval = eps_runge_kutta(a, b, ya, pow(10, -i),big_step,it);
			iter.push_back(it);

		}
		for (auto& val : iter)
			file << val << ' ';
	}
	else if (action == 5) {
		vector<double> mx;
		vector<double> init_v;

		auto x = nodes_step(a, b, big_step);
		auto y_exact = Y(x);
		int n = static_cast<int>(h);
		for (int i = 1; i <= n; i++) {

			int k = 1;
			init_v.push_back(init_val(i));
			y_eval = eps_runge_kutta(a, b, init_v[i-1], pow(10, -8), big_step, k);
			mx.push_back(fabs(y_eval[0] - y_exact[0]));
			for (size_t j = 1; j < y_eval.size(); j++)
			{
				double error = fabs(y_eval[j] - y_exact[j]);
				if (error > mx[i - 1])
					mx[i - 1] = error;
			}
		}
		for (auto& val : mx)
			file << val << ' ';
		for (auto& val : init_v)
			file << val - ya << ' ';


	}


	
	return 0;
}






//class A4
//{
//public:
//	A4() { m_x = 4; cout << "A" << endl; };
//	A4(int x) { m_x = x; cout << m_x << "->A" << endl; };
//	A4(const A4&) { m_x = 1; cout << "A->A" << endl; };
//	A4& operator=(const A4& a) { cout << "A = A" << endl; return *this; };
//	~A4() { cout << "~A" << endl; };
//	void print() { std::cout << "NVI\n"; v_print(); };
//	void do_smth() { cout << "do(A)\n"; };
//
//protected:
//	int m_x;
//	virtual void v_print() { cout << "A" << endl; };
//};
//
//
//
//class B4 :public A4
//{
//public:
//	B4(int a) :A4(a) { cout << a << "->A" << endl; };
//	B4() { cout << "B" << endl; };
//	B4& operator=(const B4& a) { cout << "B = B" << endl; return *this; };
//	virtual ~B4() { cout << "~B" << endl; };
//	void do_smth() { cout << "do(b)\n"; };
//
//protected:
//	virtual void v_print() { cout << m_x << endl; };
//};
//
//
//class C4 :public B4 {
//public:
//	C4() :m_a(10) { cout << "C" << endl; };
//	C4(const C4& b) { cout << "C->C" << endl; };
//	C4& operator=(const A4& a) { this->m_x = 44; cout << "C = A" << endl; return *this; };
//	virtual ~C4() { cout << "~C" << endl; };
//	void do_smth() { cout << "do(c)\n"; };
//protected:
//	A4 m_a;
//	virtual void v_print() { cout << "C = " << m_x << endl; *this = m_a; };
//};
//
//
//class D4 :public B4
//{
//public:
//	D4() :B4(10) { cout << "D" << endl; };
//	D4(const C4& c) :B4(c) { cout << "C->D" << endl; };
//protected:
//	virtual void v_print() { cout << "D = " << m_x << endl; A4::v_print(); };
//
//};



//int main(int argc, char** argv)
//{

	//B4 a1;
	//a1.print();
	//A4& a = a1;
	//a.print();
	//A4* a2 = new C4;
	//a2->print();
	//delete a2;
	//a2->print();

	//C4* b1 = new C4;
	//b1->do_smth();

	//A4* b2 = new C4;
	//b2->do_smth();
	//b2->print();
	//b2->print();
	//*b2 = B4();

//	return 0;
//}
