// ConsoleApplication33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
unsigned long ROL(unsigned long a)
{
	return (a << 4 | a >> 28);
}
int ascii_cod(unsigned char a)
{

	int c;

	c = a;
	return c;
}
char Obr_cyclicheskiy_sdvig(int a)
{
	char maska = (a >> 4) & 0b00001111;
	char a__ = a << 4;
	char a_pre_gamm = maska | a__;
	return a_pre_gamm;
}

	
	char Cyclicheskiy_sdvig(int a)
	{
		char maska = a << 4;
		char a_ = (a >> 4) & 0b00001111;
		char a_result = a_ | maska;
		return a_result;
	}
	unsigned char ascii_sym(int a)
	{

		char c;

		c = a;

		return c;
	}
	
	

	const int FIRST_SYMBOL = ' '; // первый символ
	const int SYMBOL_NUMBER = 95; // для простоты кодируем только английский алфавит 

	void GammaCoding(char *input, char *gamma, char *result)
	{
		for (char *i = input, *j = gamma; *i; i++, j++)
		{
			if (!(*j)) j = gamma;
			int Ti = *i - FIRST_SYMBOL;
			int Gi = *j - FIRST_SYMBOL;
			*(result++) = FIRST_SYMBOL + (Ti + Gi) % SYMBOL_NUMBER;
		}
		*result = '\0';
	}

	void GammaDecoding(char *input, char *gamma, char *result)
	{
		for (char *i = input, *j = gamma; *i; i++, j++)
		{
			if (!(*j)) j = gamma;
			int Ci = *i - FIRST_SYMBOL;
			int Gi = *j - FIRST_SYMBOL;
			*(result++) = FIRST_SYMBOL + (Ci - Gi + SYMBOL_NUMBER) % SYMBOL_NUMBER;
		}
		*result = '\0';
	}

	int main()
	{
		char   gamma[256], rez[256];
		char str1[] = "Name";
	
		
		cout << "Enter gamma: ";
		cin >> gamma;

		GammaCoding(str1, gamma, rez);
		cout << "Encrypted message: ";
		cout << rez << endl;

		for (int i = 0; i < 4; i++)
		{
		char let;
		let = rez[i];
		cout << "Number of symbol after cyclic shift:  " << (ROL(ascii_cod(rez[i]))) << endl;
		cout << "The original gamma:  " << ascii_sym(Obr_cyclicheskiy_sdvig(Cyclicheskiy_sdvig(ascii_cod(rez[i])))) << endl;
		
	}
		
		GammaDecoding(rez, gamma, str1);
		cout << "Original message: ";
		cout << str1 << endl;

	
	system("pause");
    return 0;
}

