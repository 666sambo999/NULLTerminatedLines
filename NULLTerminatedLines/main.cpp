#include <iostream>
#include <Windows.h> 
using namespace std;

int StringLength(const char* str);
char* to_upper(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	/*char str[] = { 'H','e','l','l','o',0 };
	cout << str << endl; 
	str[3] = 0;*/
	//char ASCII[256];
	//for (int i = 0; i < 256; i++)
	//{
	//	ASCII[i] = i;
	//	cout << "\t" << i << " = " << ASCII[i];
	//	//if ((i + 1) % 5 == 0) 97-65 =32
	//	cout << "\n";
	//} 
	//cout << (int) 'a' << "\t" << (int) 'A' << endl; // сравнить 
	//cout <<  'a' -  'A' << endl; // сравнить 
	
	/*char str[] = "Hello";
	cout << str << endl; 
	cout << sizeof(str) << endl;*/
	
	const int n = 256; 
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, n);  
	SetConsoleCP(866);
	cout << str << endl; 
	cout << "Размер строки: " << StringLength(str) << endl; 
	cout << to_upper(str) << endl; 
}
int StringLength(const char* str) // размер строки 
{
	int i = 0;
	for (; str[i]; i++);
	return i; 
}
char* to_upper(char str[])// перевод в верхний регистор 
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
		if (str[i] >= 'а' && str[i] <= 'я') str[i] -= ' ';
	}
	return str;
}