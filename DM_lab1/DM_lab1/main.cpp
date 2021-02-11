#include "Set.h"
using namespace std;




void Help(string command) {
	if (command == "create") {
		cout << "create <set>\nCreates an empty set named <set>.\n"
			"Creating a s.";
	}
	else if (command == "clear") {
		cout << "clear <set>\nDeletes the set named <set>.\n"
			"To use a set with the same name later on, make a new one with the command 'create'.\n"
			"An attempt to delete non-existing set will cause an error message.";
	}
	else if (command == "delete") {
		cout << "delete <set> <element>\nDeletes an element named <element>"
			"from the <set>.\nAn attempt to delete non-existing element will cause an error message.";
	}
	else if (command == "check") {
		cout << "check <set> <element>\n";
	}
}


class tmp {
private:
	int kek;
	double lul;
public:
	int& AtKek() {
		return kek;
	};
	double& AtDouble() { return lul; };
	tmp() { kek = 0; lul = 0; };

};

int main()
{
	tmp a;
	cout << a.AtDouble();



	//Set<Set<string>> main;
	//
	//Set<string> a("first");
	//Set<string> k("second");
	//a.Add("abc");
	//a.Add("zxc");
	//k.Add("lol");




	//main.Add(a);
	//if (main.Check(a))
	//	cout << "a in main";
	//cout << main.FindByName("first")->Power();


	/*
	Set valid_commands({"create","clear","delete","check","power", "add",
						"help", "union", "intersection", "includes",
						"xor", "diff", "print", "list"});
	

	string input, i;
	cout << "Enter the commands: ";
	getline(cin, input);
	stringstream s(input);
	string action;
	s >> action;
	if (valid_commands.Check(action)) {

	}

	

	
	


	return 0;*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
