#include<iostream>
#include<fstream>
#include<math.h>
#include<list>
#include<algorithm>
using namespace std;
bool Is_exp_of_2(int n);
void DNF(int I, int x);
void CNF(int I, int x);
int main()
{
	ifstream File("FUNCTIONS.txt");
	int amount = 0, func_res, amount_of_one = 0, amount_of_zero = 0, current_zero = 0, current_one = 0;
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
	//подсчет 1 и 0
	for (int i = 0; i < amount; i++)
	{
		if (Function[i] == 0)
		{
			amount_of_zero++;
		}
		else
		{
			amount_of_one++;
		}
	}
	//посторйка КНФ
	cout << "CNF:" << endl;
	for (int i = 0; i < amount; i++)
	{
		if (Function[i]==0)
		{
			CNF(i, log2(amount));
			current_zero++;
			if (current_zero!=amount_of_zero)
			{
				cout << "&";
			}
		}
	}
	cout << endl;
	cout << "DNF:" << endl;
	//посторйка ДНФ
	for (int i = 0; i < amount; i++)
	{
		if (Function[i] == 1)
		{
			DNF(i, log2(amount));
			current_one++;
			if (current_one != amount_of_one)
			{
				cout << "|";
			}
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
void DNF(int I, int size)
{
	//массив переменных которые будем использовать для построение ДНФ
	char* variables = new char[size];
	int* Bin = new int[size];
	int now = 0 ;
	for (int i = 0; i < size; i++)
	{
		variables[i] = 97 + i;
	}
	while (I != 0)
	{
		Bin[now] = I % 2;
		I /= 2;
		now++;// позиция последнего добавленого элемента
	}
	if (now != size - 1)
	{
		for (int i = 0; i < now + 1; i++)
		{
			swap(Bin[now - i], Bin[size - i]);
		}
	}
	int k = 0;
	cout << "(";
	for (int i = size - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			if (Bin[i] != 1)
			{
				cout << "!" << variables[size - 1]<<")";
			}
			else
			{
				cout << variables[size - 1] << ")";
			}
		}
		else
		{
			if (Bin[i] != 1)
			{
				cout << "!" << variables[k] << "&";
			}
			else
			{
				cout << variables[k] << "&";
			}
		}
		k++;
	}
		
}
void CNF(int I, int size)
{
	//массив переменных которые будем использовать для построение ДНФ
	char* variables = new char[size];
	int* Bin = new int[size];
	int now = 0;
	for (int i = 0; i < size; i++)
	{
		variables[i] = 97 + i;
	}
	while (I != 0)
	{
		Bin[now] = I % 2;
		I /= 2;
		now++;// позиция последнего добавленого элемента
	}
	if (now != size - 1)
	{
		for (int i = 0; i < now + 1; i++)
		{
			swap(Bin[now - i], Bin[size - i]);
		}
	}
	int k = 0;
	cout << "(";
	for (int i = size - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			if (Bin[i] != 1)
			{
				cout << variables[size - 1]<<")";
			}
			else
			{
				cout <<"!"<< variables[size - 1]<<")";
			}
		}
		else
		{
			if (Bin[i] != 1)
			{
				cout << variables[k] << "|";
			}
			else
			{
				cout << "!" << variables[k] << "|";
			}
		}
		k++;
	}

}