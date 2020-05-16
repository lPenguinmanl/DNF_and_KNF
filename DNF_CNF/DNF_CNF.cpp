#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream File("FUNCTIONS.txt");
	int i = 0, func_res;
	cout << File.gcount() << endl;
	File.close();
	return 0;
}