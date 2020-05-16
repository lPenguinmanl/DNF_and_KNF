#include<iostream>
#include<fstream>
#include"DNF_CNF.h"
using namespace std;
int main()
{
	ifstream File("FUNCTIONS.txt");
	int i = 0, func_res;
	//получаю количество ел будевой функции
	while (File>>func_res)
	{
		i++;
	}
	File.close();
	try
	{
		if (!Is_log2(i))
		{
			throw -1;
		}
	}
	catch (int i)
	{
		cout << "Error data in file" << endl;
		exit(0);
	}
	return 0;
}