
#include <iomanip>
#include "spline.h"

using namespace std;

//// argv[1] - number of nodes,
//// argv[2] - action: 1 - print points + spline vals, 2 - print points + error in points, 3 - max error
//// argv[3] - function: 1 - tan(0.5 x + 0.2) - x^2, 2 - (tan(0.5 x + 0.2) - x^2) |x - 6|
//int main(int argc, char** argv) {
//	
//	
//	double df_a;
//	double df_b;
//	double a = 3;
//	double b = 8;
//	size_t n = 3;
//	int action = 1;
//	int func = 1;
//	if (argc > 1)
//		n = static_cast<int>(atoi(argv[1]));
//	if (argc > 2)
//		action = atoi(argv[2]);
//	if (argc > 3)
//		func = atoi(argv[3]);
//
//
//	
//	ofstream file("d.txt");
//
//	vector <double> x = node(n, a, b);
//
//	
//	vector <double> h = dx(x);
//	vector <double> y;
//
//	if (func == 2) {
//		y = Y_mod(x);
//		df_a = 3 * (a * a - 4 * a) - 0.5 * (a - 6) * pow(cos(a / 2 + 0.2), -2) - tan(a / 2 + 0.2);
//		df_b = -3 * (b * b - 4 * b) + 0.5 * (b - 6) * pow(cos(b / 2 + 0.2), -2) + tan(b / 2 + 0.2);
//	}
//	else {
//		y = Y(x);
//		df_a = 0.5 * pow(cos(a / 2 + 0.2), -2) - 2 * a;
//		df_b = 0.5 * pow(cos(b / 2 + 0.2), -2) - 2 * b;
//	}
//
//	
//
//	vector <vector<double>> coef = get_coef(x, y, df_a, df_b);
//
//
//	vector <double> x_eval = linspace(a, b, STEP);
//	vector <double> y_eval = inter(coef[0], coef[1], coef[2], x, x_eval, h);
//
//	vector <double> y_eval_nodes = inter(coef[0], coef[1], coef[2], x, x, h);//spline val in nodes
//
//	vector <double> zeros;
//	for (size_t i = 0; i < y_eval_nodes.size(); i++)
//		zeros.push_back(0);
//
//
//	vector <double> y_ex;//exact values in points 3:0.01:8
//	if (func == 2)
//		y_ex = Y_mod(x_eval);
//	else
//		y_ex = Y(x_eval);
//
//	//// printing coefficients of splines & nodes + steps
//	//for (auto kef : coef) {
//	//	for (auto c : kef) {
//	//		file << c << ' ';
//	//	}
//	//}
//	//for (auto c : h) {
//	//	file << c << ' ';
//	//}
//	//for (auto c : x) {
//	//	file << c << ' ';
//	//}
//	//file.close();
//	//return 0;
//	////
//
//
//
//	if (action == 1) { // initial fun + nodes
//		print_init(file, x_eval, y_eval);
//		print_nodes(file, x, y, zeros);
//	}
//
//	else if (action == 2) { // error + nodes
//		print_error(file, x_eval, y_eval, y_ex);
//		print_nodes(file, x, y, y_eval_nodes);
//	}
//	else if (action == 3) { // max_error	
//		file.setf(ios::scientific);
//		print_max(file, y_ex, y_eval);
//	}
//
//	file.close();
//	return 0;
//
//}


// for derivative val task
int main(int argc, char** argv) {
	

	double mx = 0;
	double a = 3;
	double b = 8;
	size_t n = 5;
	int action = 1;
	int grid = 1;
	if (argc > 1)
		n = static_cast<int>(atoi(argv[1]));
	if (argc > 2)
		action = atoi(argv[2]);
	if (argc > 3)
		grid = atoi(argv[3]);


	fstream file("d.txt");

	vector <double> x = node(n, a, b);

	vector <double> h = dx(x);
	vector <double> y;
	vector <double> x_eval = linspace(a, b, STEP);
	double df_a, df_b;


	vector <double> mx_er;
	vector <double> dfs_a;
	vector <double> dfs_b;
	int num_of_tests = 90;

	for (int i = 0; i <= num_of_tests; i++) {
		
		action = 3;
		if (grid == 1) {
			y = Y(x);
			df_a = unmod_lim((0.5 * pow(cos(a / 2 + 0.2), -2) - 2 * a), i, num_of_tests);
			df_b = unmod_lim(0.5 * pow(cos(b / 2 + 0.2), -2) - 2 * b, i, num_of_tests);
		}
		else {
			y = Y_mod(x);
			df_a = mod_lim(3 * (a * a - 4 * a) - 0.5 * (a - 6) * pow(cos(a / 2 + 0.2), -2) - tan(a / 2 + 0.2)
							, i, num_of_tests);
			df_b = mod_lim(- 3 * (b * b - 4 * b) + 0.5 * (b - 6) * pow(cos(b / 2 + 0.2), -2) + tan(b / 2 + 0.2)
							, i, num_of_tests);
		}
		dfs_a.push_back(df_a);
		dfs_b.push_back(df_b);

		
		auto coef = get_coef(x, y, df_a, df_b);


		vector <double> y_eval = inter(coef[0], coef[1], coef[2], x, x_eval, h);


		vector <double> y_ex;//exact values in points 3:0.01:8
		if (grid == 2)
			y_ex = Y_mod(x_eval);
		else
			y_ex = Y(x_eval);

			
		for (size_t j = 0; j < y_ex.size(); j++) {
			if (mx < fabs(y_ex[j] - y_eval[j]))
				mx = fabs(y_ex[j] - y_eval[j]);
		}

		mx_er.push_back(mx);
		mx = 0;

	}
	file << num_of_tests << endl;
	for (auto& val : mx_er) {
		file << val << ' ';
	}
	for (auto& val : dfs_a) {
		file << val << ' ';
	}
	for (auto& val : dfs_b) {
		file << val << ' ';
	}


	
	file.close();
	return 0;
}