#include "Set.h"
using namespace std;

int main()
{


	
	init_();

	Set<Set<string>> main("main");
	Set<string> valid_commands({ "exit","help", "create", "remove", "add", "del",
								"rename", "check", "power", "union", "intersection",
								"includes", "xor", "diff", "print", "list" });

	string input;


	while (getline(cin, input)) {
		try {
			if (input == "exit")
				break;
			parse_command(input, main, valid_commands);
		}
		catch (invalid_argument& exc) {
			cout << exc.what();
		}
		cout << endl << endl;
	}

	return 0;
}
