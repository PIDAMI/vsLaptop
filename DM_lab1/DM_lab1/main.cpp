#pragma warning(disable:4996)
#include "Set.h"
using namespace std;




Set<Set<string>> init() {
	cout << "Programm executes operations on sets of strings\n"
		"Type help to see available commands and their short explanation"
		" and help [command] for more details on a particular command\n";
	Set<Set<string>> main("main");
	return main;
}

void help(string command) {
	if (command == "") {
		cout << "Available commands:\n"
			"create <set>\t\t\t\t\tCreates an empty set named <set>\n"
			"remove <set>\t\t\t\t\tDelets the set named <set>\n"
			"add <set> \"<elem1>\" \"<elem2>\" ...\t\tAdds <elem> enclosed in quotes to set <set>\n"
			"del <set> \"<elem1>\" \"<elem2>\" ...\t\tDeletes <elem> enclosed in quotes from <set>\n"
			"rename <set> <new_name>\t\t\t\tChange set's name from <set> to <new_name>.\n"
			"check <set> \"<elem>\"\t\t\t\tCheck if <elem> contains in set <set>\n"
			"power <set>\t\t\t\t\tSee the power of set <set>\n\n"
			"union <union_set> <set1> <set2>\t\t\tCalculate union of sets <set1> and <set2> and name it <union_set>\n"
			"intersection <intersection_set> <set1> <set2>\t"
			"Calculate intersection of sets <set1> and <set2> and name it <intersection_set>\n"
			
			"includes <set1> <set2>\t\t\t\tCheck if <set2> is a subset of <set1>\n"
			"xor <xor_set> <set1> <set2>\t\t\tCalculate exclusive intersection of <set1> and <set2> and name it <xor_set>\n"
			"diff <diff_set> <set1> <set2>\t\t\tCalculate difference of <set1> and <set2> and name it <dif_set>\n"
			"print <set>\t\t\t\t\tPrint elements of set <set>\n"
			"list\t\t\t\t\tPrint names of all created sets\n\n";
	}
	else if (command == " create") {
		cout << "\tcreate <set>\nCreates an empty set named <set>.\n"
			"Names cannot contain whitespaces.\n"
			"Creating a set with no name or with the name of an existing set will cause and error message";
	}
	else if (command == " remove") {
		cout << "\tremove <set>\nDeletes the set named <set>.\n"
			"To use a set with the same name later on, make a new one with the command create.\n"
			"An attempt to delete non-existing set will cause an error message.\n";
	}
	else if (command == " delete") {
		cout << "\tdelete <set> \"<element1>\" \"<element2>\"...\nDeletes elements named <element1>, <element2> ..."
			"from the set <set>.\nElements must be enclosed in quotes and separated by whitespaces. "
			"An attempt to delete non-existing element will cause an error message"
			" as well as deleting from non-existing set.\n";
	}
	else if (command == " check") {
		cout << "\tcheck <set> \"<element>\"\nCheck if set <set> contains <element>."
			" Element must be enclosed in quotes. "
			"An attempt to call command using the name of non-existing set will cause an error message.\n";
	}
	else if (command == " add") {
		cout << "\tadd <set> \"<element1>\" \"<element2>\" ...\n"
			"Adds <element1>, <element2> ... to set <set>. "
			"Elements must be enclosed in quotes, separated by whitespaces and "
			"have length of not more than 80 characters. "
			"An attempt to add an invalid arguement as well as adding to non-existing set will cause an error message.\n";
	}
	else if (command == " power") {
		cout << "\tpower <set>\nSee the power of the set <set>. "
			"An attempt to call command for non-existing set will cause an error-message.\n";
	}
	else if (command == " includes") {
		cout << "\tincludes <set1> <set2>\tCheck if <set2> is a subset of <set1>\n"
			"An attempt to call command for non-existing set will cause an error-message.\n";
	}
	else if (command == " rename") {
		cout << "\trename <set> <new_name>\nChange set's name from <set> to <new_name>.\n"
			"An attempt to rename non-existing set will cause an error-message as well as "
			"using name of already exising set for set's new name.\n";

	}
	else if (command == " union") {
		cout << "union <union_set> <set1> <set2>\t"
			"Calculate union of sets <set1> and <set2> and name it <union_set>"
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set.\n";
	}
	else if (command == " intersection") {
		cout << "intersection <intersection_set> <set1> <set2>\t"
			"Calculate intersection of sets <set1> and <set2> and name it <intersection_set>\n"
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set.\n";
	}
	else if (command == " xor") {
		cout << "xor <xor_set> <set1> <set2>\t"
			"Calculate exclusive intersection of <set1> and <set2> and name it <xor_set>."
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set.\n";
	}
	else if (command == " diff") {
		cout <<"diff <diff_set> <set1> <set2>\t"
			"Calculate difference of <set1> and <set2> and name it <dif_set>. "
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set.\n";
	}
	else {
		throw invalid_argument("No help on this command");
	}
}

bool has_one_operand(string command) {
	return command == "create" || command == "remove" || command == "power";
}

bool has_two_operands(string command) {
	return command == "rename" || command == "check" || command == "includes";
}

bool has_three_operands(string command) {
	return command == "union" || command == "intersection" || command == "diff" || command == "xor";
}
bool has_many_operands(string command) {
	return command == "add" || command == "del";
}

bool valid_name(Set<Set<string>> main) {
	return false;
}

void parse_command(string input, Set<Set<string>> main, Set<string>& valid_commands) {
	stringstream stream(input);
	string command;
	stream >> command;
	if (!valid_commands.Check(command)) {
		throw invalid_argument("Invalid command");
	}

	string operands;
	getline(stream, operands);
	if (command == "help") {
		help(operands);
	}
	else if (command == "list") {
		main.Print();
	}
	else {
		
		if (has_one_operand(command)) {
			string set_name;
			stream >> set_name;
			string rest_of_command;//check if set_name was the last thing in command
			getline(stream, rest_of_command);
			if (rest_of_command.size() == 0) {

			}
		}
		else if (has_two_operands(command)) {

		}
		else if (has_three_operands(command)) {

		}
	}
	return;

}

// create s 
// add s "zxc" "qwe s" "xxc"
// del s "qwe s"
// union first s s t

int main()
{
	vector <string> commands = { "help", "create", "remove", "add", "del",
								"rename", "check", "power", "union", "intersection",
								"includes", "xor", "diff", "print", "list" };
	Set<string> valid_commands(commands);

	
	Set<Set<string>> main = init();//sets are sotred by names, which are given when initialized
	string input("");
	try {
		parse_command(input, main, valid_commands);
	}
	catch (invalid_argument& exc) {
		cout << exc.what() << endl;
	}


	//while (getline(cin,input)){ //ctrl-c to exit programm
	//	
	//}


	//Set<string> z("first");
	//main.Add(z);
	//main.FindByName("first")->Add("sus");
	//main.FindByName("first")->Add("sas");
	//main.Add({"second"});
	//cout << main.FindByName("first")->Power();
	//main.Del({"first"});



	return 0;
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
