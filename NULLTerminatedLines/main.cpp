#include <iostream>
#include <Windows.h> 
using namespace std;
using std::cout;

int StringLength(const char* str);
char* to_upper(char str[]);
char* to_lower(char str[]);
char* shrink(char str[]); 
bool is_palindrome(const char str[]);
char* remove_symbol(char str[], char symbol);
bool is_int_number(const char str[]);
int  to_int_number(const char str[]);
bool is_bin_number(const char str[]);
bool is_hex_number(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	/*char str[] = { 'H','e','l','l','o',0 };
	cout << str << endl; 
	str[3] = 0;*/
	/*char ASCII[256];
	for (int i = 0; i < 256; i++)
	{
		ASCII[i] = i;
		cout << "\t" << i << " = " << ASCII[i];
		if ((i + 1) % 10 == 0)
		cout << "\n" << endl; 
	} 
	cout << endl; */
	//cout << (int) 'a' << "\t" << (int) 'A' << endl; // сравнить 97-65 =32
	//cout <<  'a' -  'A' << endl; // сравнить 
	
	/*char str[] = "Hello";
	cout << str << endl; 
	cout << sizeof(str) << endl;*/
	
	const int n = 256; 
	char str[n] = "Аргентина манит негра";
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, n);  
	SetConsoleCP(866);
	cout << str << endl; 
	cout << "Размер строки: " << StringLength(str) << endl; 
	cout << to_upper(str) << endl; 
	cout << to_lower(str) << endl; 
	cout << shrink(str) << endl;
	cout << "Строка " << (is_palindrome(str) ? "" : "не ") << "палиндром" << endl; 
	cout << "Строка " << (is_int_number(str) ? "" : "не ") << "является числом" << endl;
	cout << to_int_number(str) << endl; 
	cout << "Строка " << (is_bin_number(str) ? "" : "не ") << "является двоичным числом" << endl;
	cout << "Строка " << (is_hex_number(str) ? "" : "не ") << "является шестнадцатиричным числом" << endl;
	


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
char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я') str[i] += 32;
	}
	return str;
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == 32 && str[i + 1] == 32)
			for (int j = i+1; str[j]; j++)str[j] = str[j + 1];
	}
	return str;
}
char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool is_palindrome(const char str[])
{
	int n = StringLength(str);
	char* buffer = new char[n+1] {};
	for (int i = 0; i < n; i++)buffer[i] = str[i];
	to_lower(buffer); // имя массива является указателем
	remove_symbol(buffer, ' ');
	n = StringLength(buffer);
	for (int i = 0; i<n/2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer; 
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool is_int_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))return false;
	}
	return true; 
}
int  to_int_number(const char str[])
{
	int weight = 1; 
	int number = 0; 
	int n = StringLength(str);
	for (int i = n - 1; i >= 0; i--)
	{
		number += (str[i] - '0') * weight;
		weight *= 10;
	}
	return number;
}
bool is_bin_number(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '1'))return false;
	}
	return true;
}
bool is_hex_number(const char str[])
{
	int n = StringLength(str);
	char* buffer = new char[n + 1] {};
	for (int i = 0; i < n; i++)buffer[i] = str[i];
	to_lower(buffer);
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') ? cout << str[i] : cout << char(str[i] + 55))return false;
	}
	return true;
}
	
	
