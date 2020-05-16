#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
bool Is_exp_of_2(int n);
int main()
{
	ifstream File("FUNCTIONS.txt");
	int amount = 0, func_res;
	//получаю количество ел будевой функции
	while (File>>func_res)
	{
		amount++;
	}
	File.close();
	try
	{
		if (!Is_exp_of_2(amount))
		{
			throw -1;
		}
	}
	catch (int i)
	{
		cout << "Error "<<i<<" :data in file" << endl;
		exit(0);
	}
	//считываем булевую функцию и записываем ее в нассив
	int* Function = new int [amount];
	ifstream file("FUNCTIONS.txt");
	for (int i = 0; i < amount; i++)
	{
		file>>Function[i];
	}
	//посторйка КНФ
	for (int i = 0; i < amount; i++)
	{
		if (Function[i]==0)
		{
			
		}
	}
	//посторйка ДНФ
	for (int i = 0; i < amount; i++)
	{
		if (Function[i] == 1)
		{

		}
	}
	file.close();
	return 0;
}
bool Is_exp_of_2(int n)
{
	if (n == 0) {
		return false;
	}

	for (; n % 2 == 0; n /= 2);
	return (n == 1);
}