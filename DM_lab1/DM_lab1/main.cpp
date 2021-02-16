#pragma warning(disable:4996)
#include "Set.h"
using namespace std;




Set<Set<string>>* init() {
	cout << "Programm executes operations on sets of strings\n"
		"Type help to see available commands and their short explanation\n"
		"Type help [command] for more details on a particular command\n";
	Set<Set<string>>* main = new Set<Set<string>>("main");
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
			"list\t\t\t\t\t\tPrint names of all created sets\n\n";
	}
	else if (command == "create") {
		cout << "\tcreate <set>\nCreates an empty set named <set>.\n"
			"Names cannot contain whitespaces.\n"
			"Creating a set with no name or with the name of an existing set will cause and error message";
	}
	else if (command == "remove") {
		cout << "\tremove <set>\nDeletes the set named <set>.\n"
			"To use a set with the same name later on, make a new one with the command create.\n"
			"An attempt to delete non-existing set will cause an error message.\n";
	}
	else if (command == "delete") {
		cout << "\tdelete <set> \"<element1>\" \"<element2>\"...\nDeletes elements named <element1>, <element2> ..."
			"from the set <set>.\nElements must be enclosed in quotes and separated by whitespaces. "
			"An attempt to delete non-existing element will cause an error message"
			" as well as deleting from non-existing set.\n";
	}
	else if (command == "check") {
		cout << "\tcheck <set> \"<element>\"\nCheck if set <set> contains <element>."
			" Element must be enclosed in quotes. "
			"An attempt to call command using the name of non-existing set will cause an error message.\n";
	}
	else if (command == "add") {
		cout << "\tadd <set> \"<element1>\" \"<element2>\" ...\n"
			"Adds <element1>, <element2> ... to set <set>. "
			"Elements must be enclosed in quotes, separated by whitespaces and "
			"have length of not more than 80 characters. "
			"An attempt to add an invalid arguement as well as adding to non-existing set will cause an error message.\n";
	}
	else if (command == "power") {
		cout << "\tpower <set>\nSee the power of the set <set>. "
			"An attempt to call command for non-existing set will cause an error-message.\n";
	}
	else if (command == "includes") {
		cout << "\tincludes <set1> <set2>\tCheck if <set2> is a subset of <set1>\n"
			"An attempt to call command for non-existing set will cause an error-message.\n";
	}
	else if (command == "rename") {
		cout << "\trename <set> <new_name>\nChange set's name from <set> to <new_name>.\n"
			"An attempt to rename non-existing set will cause an error-message as well as "
			"using name of already exising set for set's new name.\n";

	}
	else if (command == "union") {
		cout << "union <union_set> <set1> <set2>\t"
			"Calculate union of sets <set1> and <set2> and name it <union_set>"
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set.\n";
	}
	else if (command == "intersection") {
		cout << "intersection <intersection_set> <set1> <set2>\t"
			"Calculate intersection of sets <set1> and <set2> and name it <intersection_set>\n"
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set.\n";
	}
	else if (command == "xor") {
		cout << "xor <xor_set> <set1> <set2>\t"
			"Calculate exclusive intersection of <set1> and <set2> and name it <xor_set>."
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set.\n";
	}
	else if (command == "diff") {
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
	return command == "create" || command == "remove" || command == "power" || command == "print";
}

bool has_two_operands(string command) {
	return command == "rename" || command == "check" || command == "includes";
}

bool has_three_operands(string command) {
	return command == "union" || command == "intersection" || command == "diff" || command == "xor";
}
// made into separate function cuz of possible # of params
bool add_or_del(string command) {
	return command == "add" || command == "del";
}

bool valid_name(Set<Set<string>>& main, const string& name) {
	if (name.size() > 81 || main.Check(name))
		return false;
	return true;

}


void one_operand_action(Set<Set<string>>& main, string& command,const string& set_name) {
	if (command == "add") {
		main.Add(set_name);
	}
	else if (command == "remove") {
		main.Del(set_name);
	}
	else if (command == "power") {
		main.FindByName(set_name)->Power();
	}
	else if (command == "print") {
		main.FindByName(set_name)->Print();
	}
	else {
		throw invalid_argument("Invalid command");
	}
}

void two_operand_action(Set<Set<string>>& main, string command, string set_name) {
	//	return command == "rename" || command == "check" || command == "includes";
	
}

// "abc" "qwe" ...
vector <string> parse_elements(const string& rest_of_command) {
	vector <string> res;
	size_t opening_delim_pos = 0;
	size_t closing_delim_pos = 0;
	while (opening_delim_pos <= closing_delim_pos) {
		opening_delim_pos = rest_of_command.find(" \"", closing_delim_pos);
		cout << "opening_delim_pos " << opening_delim_pos << endl;
		//if (opening_delim_pos == string::npos) {
		//	string message = "Invalid format: " + rest_of_command;
		//	throw invalid_argument(message);
		//}
		closing_delim_pos = rest_of_command.find("\"", opening_delim_pos + 2);
		cout << "closing_delim_pos " << closing_delim_pos << endl;
		if (closing_delim_pos > opening_delim_pos) {
			string word = rest_of_command.substr(opening_delim_pos + 2, closing_delim_pos - opening_delim_pos - 2);
			res.push_back(word);
		}
	}

	return res;

}
//todo

// "q" "zxc qwe" "z w" ->  ,q, ,zxc qwe,
vector<string> tokenize(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t p0 = 0, p1 = string::npos;

	/*p1 = str.find_first_of("\"", p0);
	if (p1 != string::npos) {
		string token = str.substr(p0, p1 - p0);
		tokens.push_back(token);
	}
	p0 = str.find_first_not_of("\"", p1);*/
	while (p0 != string::npos)
	{
		p1 = str.find_first_of(delim, p0);
		if (p1 != p0)
		{
			string token = str.substr(p0, p1 - p0);
			tokens.push_back(token);
		}
		p0 = str.find_first_not_of(delim, p1);
	}
	return tokens;

}



void add_or_del_action(Set<Set<string>>& main, string command, string set_name, string words) {

	//todo: words parses 

}




void parse_command(string input, Set<Set<string>> main, Set<string>& valid_commands) {
	stringstream stream(input);
	string command;
	stream >> command;
	if (!valid_commands.Check(command)) {
		throw invalid_argument("Invalid command");
	}

	string operands;
	stream >> operands;
	if (command == "help") {
		help(operands);
	}
	else if (command == "list") {
		main.Print();
	}
	else {
		string set_name = operands;
		//stream >> set_name;
		if (!valid_name(main, set_name))
			throw invalid_argument("Invalid set name");
		string rest_of_command; //check if set_name was the last word in command
		getline(stream, rest_of_command);
		if (add_or_del(command)) {
			if (rest_of_command.size() == 0) {
				string message = "No elements found to " + command;
				throw invalid_argument(message);
			}
			// "..." "..."
			else {
				vector <string> words = parse_elements(rest_of_command);
				add_or_del_action(main, command, set_name, rest_of_command);
			}				
		}
		else if (has_one_operand(command)) {
			if (rest_of_command.size() == 0) {
				one_operand_action(main, command, set_name);
			}
			else {
				string message = "Unknown parameters: " + rest_of_command;
				throw invalid_argument(message);
			}
		}
		else if (has_two_operands(command)) {// command + name + rest_of_command
		
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
	string str("\"a w\" \"a\"");
	try {
		vector <string> q = parse_elements(str);
		for (auto c : q) {
			cout << c << endl;
		}
	}
	catch (exception& exc) {
		cout << exc.what() << endl;
	}

	return 0;
	
	
	
	try {








		/*vector <string> commands = { "help", "create", "remove", "add", "del",
									"rename", "check", "power", "union", "intersection",
									"includes", "xor", "diff", "print", "list" };
		Set<string> valid_commands(commands);*/



		Set<Set<string>>* main = init();//sets are sotred by names, which are given when initialized
		
		/*Set<string> z("set1");
		z.Add("qwe");
		main->Add(z);
		cout << main->FindByName("set1")->Power();*/

		string s = "set2";
		main->Add(s);
		main->FindByName(s)->Add("zzz");
		cout << main->FindByName(s)->Power();

		/*string input("help");
		try {
			parse_command(input, main, valid_commands);
		}
		catch (invalid_argument& exc) {
			cout << exc.what() << endl;
		}*/




		delete main;
	}
	catch(invalid_argument& exc) {
		cout << exc.what() << endl;
	}
	return 0;
}
