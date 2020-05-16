#include<iostream>
#include<fstream>
#include<math.h>
#include<list>
using namespace std;
bool Is_exp_of_2(int n);
void DNF(int I, int x);
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
	/*
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
	*/
	DNF(3,4);
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
void DNF(int I, int x)
{
	//массив переменных которые будем использовать для построение ДНФ
	char* variables = new char[x];
	int* Bin = new int[x];
	int now =0 ;
	for (int i = 0; i < x; i++)
	{
		variables[i] = 97 + i;
	}
	while (I!=0)
	{ 
		Bin[now] = I % 2;
		I /= 2;
		now++;
	}
	for (int i = 0; i < x; i++)
	{
		cout << Bin[i];
	}
}