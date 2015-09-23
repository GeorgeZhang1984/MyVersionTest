#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
	string zip = "gzip ";
	string file = "Exercise1.pdf";
	string command = zip + file;
	int rev = system(command.c_str());
	if (rev == 0)
		cout<<"File has been compressed!"<<endl;
	else
		cout<<"Error!"<<endl;
	command = zip + "-d " + file + ".gz";
	rev = system(command.c_str());
	if (rev == 0)
		cout<<"File has been uncompressed!"<<endl;
	else
		cout<<"Error Uncompress!"<<endl;	
	return 0;
}


