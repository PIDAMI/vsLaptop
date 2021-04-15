#include "Set.h"

using namespace std;


void Append(node<std::string>** head, node<std::string>** tail, std::string new_data) {
	node<std::string>* new_elem = new node<std::string>(new_data, nullptr);
	if (*head == nullptr) {
		*head = new_elem;
	}
	else {
		(*tail)->next = new_elem;
	}
	*tail = new_elem;
}

node<std::string>* merge_lists(node<std::string>* a, node<std::string>* b, size_t& resulting_size) {
	node<std::string>* res_head = nullptr;
	node<std::string>* res_tail = nullptr;
	node<std::string>* a_i = a;
	node<std::string>* b_i = b;
	std::string nxt_data;
	size_t count = 0;
	while (a_i && b_i) {
		if (a_i->data < b_i->data) {
			nxt_data = a_i->data;
			a_i = a_i->next;
		}
		else if (a_i->data > b_i->data) {
			nxt_data = b_i->data;
			b_i = b_i->next;
		}
		else {
			nxt_data = a_i->data;
			b_i = b_i->next;
			a_i = a_i->next;
		}
		Append(&res_head, &res_tail, nxt_data);
		count++;
	}
	node<std::string>* left_set = (a_i == nullptr ? b_i : a_i);
	while (left_set) {

		Append(&res_head, &res_tail, left_set->data);
		left_set = left_set->next;
		count++;
	}

	resulting_size = count;
	return res_head;
}


void init_() {
	cout << "Programm executes operations on sets of strings\n\n"
		"Type help to see available commands and their short explanation\n"
		"Type help [command] for more details on a particular command\n"
		"Type exit to shut down the programm\n\n";
}

void help(const string& command) {
	if (command == "") {
		cout << "Available commands:\n"
			"create <set>\t\t\t\t\tCreates an empty set named <set>\n"
			"remove <set>\t\t\t\t\tDelets the set named <set>\n"
			"add <set> \"<elem1>\" \"<elem2>\" ...\t\tAdds <elem> enclosed in quotes to set <set>\n"
			"del <set> \"<elem1>\" \"<elem2>\" ...\t\tDeletes <elem> enclosed in quotes from <set>\n"
			"rename <set> <new_name>\t\t\t\tChange set's name from <set> to <new_name>\n"
			"check <set> \"<elem>\"\t\t\t\tCheck if <set> contains <elem>\n"
			"power <set>\t\t\t\t\tSee the power of set <set>\n\n"
			"union <union_set> <set1> <set2>\t\t\tCalculate union of sets <set1> and <set2> and name it <union_set>\n"
			"intersection <intersection_set> <set1> <set2>\t"
			"Calculate intersection of sets <set1> and <set2> and name it <intersection_set>\n"

			"includes <set1> <set2>\t\t\t\tCheck if <set2> is a subset of <set1>\n"
			"xor <xor_set> <set1> <set2>\t\t\tCalculate exclusive intersection of <set1> and <set2> and name it <xor_set>\n"
			"diff <diff_set> <set1> <set2>\t\t\tCalculate difference of <set1> and <set2> and name it <dif_set>\n"
			"print <set>\t\t\t\t\tPrint elements of set <set>\n"
			"list\t\t\t\t\t\tPrint names of all created sets";
	}
	else if (command == "create") {
		cout << "create <set>\nCreates an empty set named <set>.\n"
			"Names cannot contain whitespaces.\n"
			"Creating a set with no name or with the name of an existing set will cause an error message";
	}
	else if (command == "remove") {
		cout << "remove <set>\nDeletes the set named <set>.\n"
			"To use a set with the same name later on, make a new one with the command create.\n"
			"An attempt to delete non-existing set will cause an error message";
	}
	else if (command == "del") {
		cout << "del <set> \"<element1>\" \"<element2>\"...\nDeletes elements named <element1>, <element2> ..."
			"from the set <set>.\nElements must be enclosed in quotes and separated by whitespaces.\n"
			"An attempt to delete non-existing element will cause an error message"
			" as well as deleting from non-existing set.\n"
			"If the command is valid, set's elements will be printed after executing the request";
	}
	else if (command == "check") {
		cout << "check <set> \"<element>\"\nCheck if set <set> contains <element>."
			" Element must be enclosed in quotes. "
			"An attempt to call command using the name of non-existing set will cause an error message";
	}
	else if (command == "add") {
		cout << "add <set> \"<element1>\" \"<element2>\" ...\n"
			"Adds <element1>, <element2> ... to set <set>.\n"
			"Elements must be enclosed in quotes, separated by whitespaces and "
			"have length of not more than 80 characters.\n"
			"An attempt to add an invalid arguement as well as adding to non-existing set will cause an error message\n"
			"If the command is valid, set's elements will be printed after executing the request";
	}
	else if (command == "power") {
		cout << "power <set>\nSee the power of the set <set>.\n"
			"An attempt to call command for non-existing set will cause an error-message";
	}
	else if (command == "includes") {
		cout << "includes <set1> <set2>\tCheck if <set2> is a subset of <set1>\n"
			"An attempt to call command for non-existing set will cause an error-message";
	}
	else if (command == "rename") {
		cout << "rename <set> <new_name>\nChange set's name from <set> to <new_name>.\n"
			"An attempt to rename non-existing set will cause an error-message as well as "
			"using name of already exising set for set's new name";

	}
	else if (command == "union") {
		cout << "union <union_set> <set1> <set2>\n"
			"Calculate union of sets <set1> and <set2> and name it <union_set>"
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set";
	}
	else if (command == "intersection") {
		cout << "intersection <intersection_set> <set1> <set2>\n"
			"Calculate intersection of sets <set1> and <set2> and name it <intersection_set>\n"
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set";
	}
	else if (command == "xor") {
		cout << "xor <xor_set> <set1> <set2>\n"
			"Calculate exclusive intersection of <set1> and <set2> and name it <xor_set>."
			"An attempt to call command for non-existing set will cause an error-message "
			"as well as using name of already exising set for resulting set";
	}
	else if (command == "diff") {
		cout << "diff <diff_set> <set1> <set2>\n"
			"Calculate difference of <set1> and <set2> and name it <dif_set>. "
			"An attempt to call command for non-existing set will cause an error-message\n"
			"as well as using name of already exising set for resulting set";
	}
	else if (command == "list") {
		cout << "list\nPrint names of all existing sets, one set per line."
				"\nPrints \"Empty set\" if there are no existing sets at the moment";
	}
	else if (command == "print") {
		cout << "print <set>\nPrints elements of <set> if there are any"
				" and \"Empty set\" if set currently has no elements.\n"
				"An attempt to call command for non-existing set will cause an error-message";
	}
	else {
		throw invalid_argument("No help on this command");
	}
}
bool has_one_operand(const string& command) {
	return command == "create" || command == "remove" || command == "power" || command == "print";
}

bool has_two_operands(const string& command) {
	return command == "rename" || command == "check" || command == "includes";
}

bool has_three_operands(const string& command) {
	return command == "union" || command == "intersection" || command == "diff" || command == "xor";
}
bool add_or_del(const string& command) {
	return command == "add" || command == "del";
}

bool valid_name(const string& name) {
	if (name.size() > 80)
		return false;
	for (auto character : name) {
		if (character < 32 || character > 127)
			return false;
	}
	return true;

}


void one_operand_action(Set<Set<string>>& main, const string& command, const string& set_name) {
	if (command == "create") {
		if (main.Check(set_name)) {
			cout << set_name << " already exists";
		}
		else {
			main.Add(set_name);
			cout << set_name << " created";
		}
	}
	else if (command == "remove") {
		int rez = main.Del(set_name);
		if (rez == -1) {
			cout  << set_name << " does not exist";
		}
		else
			cout << set_name << " removed";
	}
	else if (command == "power") {
		int pow = main.FindByName(set_name)->Power();
		cout << set_name << " power is " << pow;
	}
	else if (command == "print") {
		main.FindByName(set_name)->Print();
	}
	else {
		throw invalid_argument("Invalid command");
	}
}


void two_operand_action(Set<Set<string>>& main, const string& command,
	const string& set_name, const string& rest_of_command) {
	if (command == "rename") {
		string new_name = rest_of_command.substr(1);
		if (valid_name(new_name) && !main.Check(new_name)) {
			main.FindByName(set_name)->ChangeName(new_name);
			cout << "Name changed from " << set_name << " to " << new_name;
		}
		else
			throw invalid_argument("Invalid name");
	}
	else if (command == "check") {
		auto* set = main.FindByName(set_name);
		vector<string> elem = tokenize(rest_of_command);
		if (!valid_name(elem[0]))
			throw invalid_argument("Invalid name");
		bool contains = set->Check(elem[0]);
		if (contains)
			cout << elem[0] << " is in the set " << set_name;
		else
			cout << elem[0] << " is not in the set " << set_name;
	}
	else if (command == "includes") {
		string second_set = rest_of_command.substr(1);
		bool include = main.FindByName(set_name)->Includes(*main.FindByName(second_set));
		if (include == true)
			cout << second_set << " is a subset of " << set_name;
		else
			cout << second_set << " is not a subset of " << set_name;
	}
}


void three_operand_action(Set<Set<string>>& main, const string& command, const string& set_name,
	const string& set_lhs, const string& set_rhs) {

	main.FindByName(set_lhs);
	main.FindByName(set_rhs);
	int contains = main.Add(set_name);
	if (contains == -1) {
		string message = set_name + " already exists";
		throw invalid_argument(message);
	}
	if (command == "union") {
		main.Add(set_name);
		main.FindByName(set_name)->Copy(main.FindByName(set_lhs)->Union(*main.FindByName(set_rhs)));
	}
	else if (command == "xor") {
		main.Add(set_name);
		main.FindByName(set_name)->Copy(main.FindByName(set_lhs)->XOR(*main.FindByName(set_rhs)));
	}
	else if (command == "intersection") {
		main.Add(set_name);
		main.FindByName(set_name)->Copy(main.FindByName(set_lhs)->Intersection(*main.FindByName(set_rhs)));
	}
	else if (command == "diff") {
		main.Add(set_name);
		main.FindByName(set_name)->Copy(main.FindByName(set_lhs)->Subtract(*main.FindByName(set_rhs)));
	}
	cout << set_name << " created. Set's composition:\n";
	main.FindByName(set_name)->Print();
}


void add_or_del_action(Set<Set<string>>& main, const string& command, const string& set_name, const string& words) {
	vector<string> elems = tokenize(words);
	if (command == "add") {
		for (const auto& el : elems)
		{
			if (!valid_name(el))
			{
				throw invalid_argument("Element contains inappropriate symbols or its length exceeds limit of 80 char");
			}
			int contains = main.FindByName(set_name)->Add(el);
			if (contains == -1)
			{
				const string message = el + " is already in the set";
				throw invalid_argument(message);
			}
		
		}
		cout << "Elements added. " << set_name << " composition:\n";
	}
	else if (command == "del") {
		for (const auto& el : elems)
			main.FindByName(set_name)->Del(el);
		cout << "Elements deleted. " << set_name << " composition: ";
	}
	main.FindByName(set_name)->Print();
}

vector <string> tokenize(const string& str) {
	vector <string> res;
	size_t opening_delim_pos = 0;
	int opening_delim_count = 0;
	int closing_delim_count = 0;
	size_t closing_delim_pos = 0;
	if (str.find(" \"", 0) != 0) { // check if starts with whitespace AND with slash 
		throw invalid_argument("Invalid input format");
	}
	while (opening_delim_pos != string::npos && closing_delim_pos != string::npos) {
		opening_delim_pos = str.find(" \"", closing_delim_pos);
		if (opening_delim_pos != string::npos)
			opening_delim_count++;
		//cout << "opening_delim_pos " << opening_delim_pos << endl;


		closing_delim_pos = str.find("\"", opening_delim_pos + 2);
		if (closing_delim_pos != string::npos && opening_delim_pos != string::npos)
			closing_delim_count++;
		//cout << "closing_delim_pos " << closing_delim_pos << endl;

		if (closing_delim_pos > opening_delim_pos && closing_delim_pos != string::npos) {
			string word = str.substr(opening_delim_pos + 2, closing_delim_pos - opening_delim_pos - 2);
			res.push_back(word);
		}
	}
	if (opening_delim_count != closing_delim_count)
		throw invalid_argument("Invalid input format");
	return res;
}

void parse_command(const string& input, Set<Set<string>>& main, Set<string>& valid_commands) {
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
		if (!valid_name(set_name))
			throw invalid_argument("Invalid set name");
		string rest_of_command; //check if set_name was the last word in command
		getline(stream, rest_of_command);
		if (add_or_del(command)) {
			if (rest_of_command.size() == 0) {
				string message = "No elements found to " + command;
				throw invalid_argument(message);
			}
			else {
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
			two_operand_action(main, command, set_name, rest_of_command);
		}
		else if (has_three_operands(command)) {
			string set_lhs, set_rhs;
			stringstream rest_stream(rest_of_command);
			if (!(rest_stream >> set_lhs >> set_rhs))
				throw invalid_argument("Invalid set names");

			three_operand_action(main, command, set_name, set_lhs, set_rhs);
		}
	}
}




