#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string ed[] = { "", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
	string des[] = { "","", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
	string sot[] = {"","сто", "двести", "тристо", "четыресто", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };
	string r1 = "тысяча";
	string r2 = "тысяч";
	string r3 = "тысячи", pr;
	int num,digitcount=0;
	cout << "Введите неообходимое число (от 0 до 100000)" << endl;
	cin >> num;
	int k = num;
error:
 while (k > 0)
	{
		k/= 10;
		digitcount++;
	}
	if (num > 0 && num < 100000)
	{
		if (num < 20)
			cout << ed[num];
		else if (digitcount == 2)
			cout << des[num / 10] + " " + ed[num % 10];
		else if (digitcount == 3)
			cout << sot[num / 100] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
		else if (digitcount == 4)
		{
			pr = r2;
			if ((num / 1000) == 1)
				cout << "одна тысяча" << " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			else if ((num / 1000) == 2)
				cout << "две тысяча" << " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			else
			{
				if ((num / 1000) == 3 || (num / 1000) == 4)
					pr = r2;
				cout << ed[num / 1000] + " " + pr + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			}
		}
		else if (digitcount == 5)
		{
			pr = r2;
			if ((num / 1000) < 20)
				cout << ed[num / 1000] + " " + pr + " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			else
			{
				if (num / 1000 % 10 == 1)
					pr = r1;
				if (num / 1000 % 10 == 2 || num / 1000 % 10 == 3)
					pr = r3;
				cout << des[num / 10000] + " " + ed[num / 1000 %10] + " " + pr + " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			}
		}
		else if (digitcount == 5)
			cout << "Сто тысяч";
	}
	else
	{
		cout << "Некоректный ввод данных, попробуйте снова: " << endl;
		cin >> num;
		k = num;
		digitcount = 0;
		goto error;
	}
}






