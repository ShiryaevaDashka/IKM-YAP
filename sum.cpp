#include <iostream>
#include <vector>
#include <string>
using namespace std;
int sum()
{
	int size_a, size_b, length;
	string sa, sb;
	cin >> sa;
	cin >> sb;
	size_a = sa.length();//длина первого слагаемого
	size_b = sb.length();//длина второго слагаемого
	if (size_a > size_b) //ищем более длинное число и добавляем единицу для переноса 
		length = size_a + 1;
	else
		length = size_b + 1;
	vector <int> a(size_a), b(length, 0);

	for (int i = size_a - 1; i >= 0; i--) //заполняем вектор цифрами первого слагаемого с конца
	{
		a[size_a - 1 - i] = sa[i] - '0';
	}
	for (int i = size_b - 1; i >= 0; i--) //заполняем массив цифрами второго слагаемого с конца
	{
		b[size_b - 1 - i] = sb[i] - '0';
	}
	for (int i = 0; i < length; i++) //вычисления
	{
		if (i < size_a) //не дошли до конца вектора a
		{
			b[i] += a[i]; // суммируем последние разряды чисел
			b[i + 1] += (b[i] / 10); // если есть разряд для переноса, переносим его в следующий разряд
			b[i] %= 10; // если есть разряд для переноса он отсекается
		}
	}
	if (b[length - 1] == 0) //если переноса в начало числа не было уменьшаем длину на 1
		length--;
	sb = ""; //результирующая строка
	for (int i = length - 1; i >= 0; i--)
	{
		sb += to_string(b[i]); //добавляем по 1 цифре к результату с конца
	}
	cout << sb;
	return 0;
}

