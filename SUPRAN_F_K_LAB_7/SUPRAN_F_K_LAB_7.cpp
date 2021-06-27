#include <iostream>
#include <string>
#include <vector>
#include <functional>
/*
* Седьмая лабораторная работа
* Автор: Супран Федор Константинович
* Группа: ПИ2-2
*/

/*
* Среднее гармоническое значение двух чисел получается путем инвертирования 
* этих чисел, вычисления среднего значения инверсий и получения инверсии результата.
* Напишите функцию, которая принимает два аргумента double и возвращает среднее
* гармоническое значение этих двух чисел
*/
double harmonicMean(double a, double b)
{
	return 2 / ((1 / a) + (1 / b));
}
void func1()
{
	system("cls");
	double a, b;
	std::cout << "Введите первое число: ";
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Среднее гармоническое чисел: " << harmonicMean(a, b) << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Напишите и протестируйте функцию, которая принимает в качестве аргументов 
* адреса трех переменных double и помещает наименьшее значение в первую переменную,
* среднее значение — во вторую, а наибольшее значение — в третью.
*/
bool testFunc(double min, double avg, double max)
{
	if (min == std::min(min, std::min(avg, max)) &&
		max == std::max(min, std::max(avg, max)))
		return true;
	else
		return false;
}
void sortNumbers(double* a, double* b, double* c)
{
	double min, avg, max;
	min = std::min(*a, std::min(*b, *c));
	max = std::max(*a, std::max(*b, *c));
	avg = *a + *b + *c - min - max;
	*a = min; *b = avg; *c = max;
}
void func2()
{
	system("cls");
	double a, b, c;
	std::cout << "Введите 1-ю переменную: ";
	std::cin >> a;
	std::cout << "Введите 2-ю переменную: ";
	std::cin >> b;
	std::cout << "Введите 3-ю переменную: ";
	std::cin >> c;
	sortNumbers(&a, &b, &c);
	std::cout << "1-я переменная: " << a << std::endl;
	std::cout << "2-я переменная: " << b << std::endl;
	std::cout << "3-я переменная: " << c << std::endl;
	if (testFunc(a, b, c))
		std::cout << "Функция sortNumbers работает исправно\n";
	else
		std::cout << "Функция sortNumbers работает неисправно\n";

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Меню для выбора функций
*/
void showMenu(std::vector<std::string> titleVector, std::vector<std::function<void()>> fVector)
{
	while (true)
	{
		system("cls");
		int choice = 0;
		std::cout << "============================\n";
		std::cout << "============Меню============\n";
		std::cout << "============================\n";
		for (size_t i = 0; i < titleVector.size(); i++)
			std::cout << i + 1 << ") " << titleVector[i] << std::endl;
		std::cout << "Введите номер выбранной задачи: ";
		std::cin >> choice;
		if (choice - 1 < 0 || choice - 1 >= titleVector.size())
			break;
		else
			fVector[choice - 1]();
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<std::string> titleVector =
	{
		"Среднее гармоническое значение двух чисел.",
		"Наименьшее значение в первую переменную, среднее значение — во вторую, а наибольшее значение — в третью.",
	};
	std::vector<std::function<void()>> fVector = { func1, func2 };
	showMenu(titleVector, fVector);
	return 0;
}