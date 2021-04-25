#include "Comb.h"
#include <iostream>

using namespace std;


int main()
{

	
	
	init();
	string command;
	while(getline(cin,command))
	{
		try
		{
			auto res = parse_command(command);
			if (res == QUIT)
				return 0;
			cout << res << endl << endl;
		}
		catch (exception& exc) {
			cout << exc.what() << endl << endl;
		}
	}
	return 0;
}