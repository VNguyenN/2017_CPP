// Vuong Nguyen
// 12/5/17

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <cmath>


using namespace std;

void Prog7_8(); 
int average(const int array[], int size);
double average(const double array[], int size);

void Prog7_16();
void printList(double list[], int size);
void selectionSort(double list[], int size);

void Prog7_32();
void prefix(const char s1[], const char s2[], char commonPrefix[]);

//void Prog7_37();
//void count(const char s[], int counts[]);

void Prog7_41();
string dec2Bin(int value);

int main()
{
	while (true)
	{
		system("cls");
		cout << "\nMain Menu - Chapter 7\n";
		cout << "=================================\n";
		cout << "    8: Programming Exercise 7.8\n";
		cout << "   16: Programming Exercise 7.16\n";
		cout << "   32: Programming Exercise 7.32\n";
		cout << "   37: Programming Exercise 7.37\n";
		cout << "   41: Programming Exercise 7.41\n";
		cout << "other: Exit\n";
		cout << "=================================\n";
		cout << "Enter an exercise: ";
		char exercise[2];
		cin >> exercise;
		cout << endl;
		switch (atoi(exercise))
		{
		case 8: Prog7_8(); break;
		case 16: Prog7_16(); break;
		case 32: Prog7_32(); break;
	//	case 37: Prog7_37(); break;
		case 41: Prog7_41(); break;
		default: exit(0);
		}
		cout << endl;
		system("pause");
		cin.clear();
	}

	return 0;
}

int average(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];
	return sum / size;
}
double average(double array[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];
	return sum / size;
}
void Prog7_8()
{
	cout << "Enter ten double values: ";
	double list[10];
	for (int i = 0; i < 10; i++)
		cin >> list[i];

	cout << "Average is " << average(list, 10) << endl;
}

void printList(double list[], int size)
{
	for (int i = 0; i < size; i++)
		cout << list[i] << "  ";
}
void selectionSort(double list[], int size)
{
	double currentMax;
	int currentMaxIndex;

	for (int i = size - 1; i >= 1; i--)
	{
		currentMax = list[0];
		currentMaxIndex = 0;

		for (int j = 1; j <= i; j++)
		{
			if (currentMax < list[j])
			{
				currentMax = list[j];
				currentMaxIndex = j;
			}
		}

		if (currentMaxIndex != i)
		{
			list[currentMaxIndex] = list[i];
			list[i] = currentMax;
		}
	}
}
void Prog7_16()
{
	const int SIZE = 10;
	double myList[SIZE];
	cout << "Enter ten numbers: ";
	for (int i = 0; i < SIZE; i++)
		cin >> myList[i];


	cout << "My list before sort is: ";
	printList(myList, SIZE);

	selectionSort(myList, SIZE);

	cout << "\nMy list after sort is: "; printList(myList, SIZE);
	cout << endl;
}

void prefix(const char s1[], const char s2[], char commonPrefix[])
{
	int len = strlen(s1);

	int i = 0;
	for (; i < len; i++)
	{
		if (s1[i] == s2[i])
		{
			commonPrefix[i] = s1[i];
		}
		else break;
	}
	commonPrefix[i] = '\0';
}
void Prog7_32()
{
		cout << "Enter a string s1: ";
		char s1[80];
		cin.ignore();
		cin.getline(s1, 80);

		cout << "Enter a string s2: ";
		char s2[80];
		cin.getline(s2, 80);

		char s3[80];
		int size = 0;
		prefix(s1, s2, s3);
		if (strlen(s3) == 0)
			cout << "No common prefix" << endl;
		else
			cout << "The common prefix is " << s3 << endl;	
}

//void count(const char s[], int counts[])
//{
//	int a, b, c;
//	char ch = 'a';
//
//	for (int i = 0; i <= strlen(s); i++)
//	{
//		for (a = 97, b = 65; a <= 122, b <= 90; a++, b++)
//		{
//			if ((s[i] == a) || (s[i] == b))
//			{
//				counts[a - 97] ++;
//			}
//		}
//	}
//}
//void Prog7_37()
//{
//	const int size = 50;
//	char s[size]; int counts[26] = {};
//	cout << "Enter a string: ";
//	cin.getline(s, 50, 'n');
//
//	count(s, counts);
//}

void Prog7_41()
{
	int value;
	cout << "Ente a dec value: ";
	cin >> value;

	

	if ((value) > 0)
	{
		cout << "The binary is " << dec2Bin((value)) << endl;
	}
	else cout << "Invalid Decimal Input!" << endl;
	
}
string dec2Bin(int value)
{
	int ab = value;
	if (ab == 0) return "0";
	if (ab == 1) return "1";

	if (ab % 2 == 0)
		return dec2Bin(ab / 2) + "0";
	else
		return dec2Bin(ab / 2) + "1";
}