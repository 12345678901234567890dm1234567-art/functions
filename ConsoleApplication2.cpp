#include<iostream>
#include<Windows.h>

void Detekt(int*arr,int size)
{
	int plus = 0, minus = 0, nol = 0;
	for (int i = 0; i < size; i++)
	{
		if(arr[i] > 0)
		{
			plus += 1;
		}
		else if(arr[i] < 0)
		{
			minus += 1;
		}
		else
		{
			nol += 1;
		}
	}
	std::cout << "\nПоложительных:" << plus;
	std::cout << "\nОтрицательных" << minus;
	std::cout << "\nНолей" << nol;
}
int SrArifm(int *arr,int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	sum / size;
	return sum;
}
int ProwVis(int god)
{
	int sumday=0;
	if (god % 4 == 0)
	{
		sumday = 366;
		if (god % 100 == 0 )
		{
			if( god % 400 != 0)
			{
				sumday = 365;
			}
			else
			{
				sumday = 366;

			}
		}
	}
	else
	{
	 sumday = 365;
	}
	return sumday;
}

int SrokDay(int day1, int mon1, int god1, int day2, int mon2, int god2)
{
	int vsedni = 0, dni1 = 0, dni2 = 0;
	int year[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int visyear[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < mon1-1; i++)
	{
		if (ProwVis(god1) == 365)
		{
			dni1 += year[i];
		}
		else
		{
			dni1 += visyear[i];
		}
	}
	for (int i = god1; i < god2; i++)
	{
		vsedni += ProwVis(i);
	}
	for (int i = 0; i < mon2 - 1; i++)
	{
		if (ProwVis(god2) == 365)
		{
			dni2 += year[i];
		}
		else
		{
			dni2 += visyear[i];
		}
	}
	dni1 += day1;
	dni2 += day2;
	vsedni -= dni1;
	vsedni += dni2;
	return vsedni + 1;
}
int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	system("chcp 1251");
	int proverka[10];
	for (int i = 0;i < 10;i++)
	{
		proverka[i] = rand()% 101 - 51;
		std::cout << proverka[i] << "\t";
	}
	Detekt(proverka, 10);
	int dated1, datem1, datey1, dated2, datem2, datey2;
	std::cout << "\nВведите первую дату";
	std::cout << "\nДень:";
	std::cin >> dated1;
	std::cout << "\nМесяц:";
	std::cin >> datem1;
	std::cout << "\nГод:";
	std::cin >> datey1;
	std::cout << "\nВведите вторую дату";
	std::cout << "\nДень:";
	std::cin >> dated2;
	std::cout << "\nМесяц:";
	std::cin >> datem2;
	std::cout << "\nГод:";
	std::cin >> datey2;

	int a = SrokDay(15, 1, 2002, 20, 10, 2026);
	int b = SrokDay(dated1, datem1, datey1, dated2, datem2, datey2);
	
	std::cout << b << "\n\n\t" << a;
	return 0;
}
