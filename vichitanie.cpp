#include <iostream>
#include <vector>
#include <string>  
using namespace std;

// функция разделения строки на подстроки по 9 цифр и занесение их 
// в массив в виде чисел (с конца)
void massiv(vector <long int>& a, string s, int len, int part)
{
	string sub;
	// j - номер элемента в массиве, k - номер подстроки, 
	// i -позиция первого символа в подстроке
	int k = 1, i = len - 9, j = 0;
	while (k <= part)
	{
		// выделяем подстроку из 9 цифр, двигаясь с конца
		// если последняя подстрока содержит меньше 9 символов,то
		// берем с 0-го символа все оставшиеся
		sub = i >= 0 ? s.substr(i, 9) : s.substr(0, 9 + i);
		a[j] = atoi(sub.c_str()); // преобразование в число
		j++; k++;
		i -= 9;
	}
}

void difference(vector <long int> x, vector <long int> y, vector <long int>& z, int part)
{
	for (int i = 0; i < part; i++) // проход по всем разрядам числа, начиная с последнего
	{
		z[i] = x[i] - y[i];

		if (z[i] < 0)
		{
			z[i] += 1000000000;
			x[i + 1]--;//занимаем разряд
		}

	}

}


// функция преобразования числа в строку с добавлением нулей
// до 9 разрядов
string to_str(long int m)
{
	string s = to_string(m);
	s.insert(0, 9 - s.length(), '0');
	return s;
}
int nemain()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	// добавляем нули слева к меньшей подстроке
	int k = 3; //если числа равны 
	if (len1 < len2)
	{
		s1.insert(0, len2 - len1, '0');
		k = 2; // второе число больше
	}
	else
		if (len1 > len2)
		{
			s2.insert(0, len1 - len2, '0');
			k = 1; // первое число больше
		}
		else // длины чисел равны
		{
			for (int i = 0; i < len1; i++) // поразрядное сравнение весов чисел
			{
				if (s1[i] > s2[i]) // если разряд первого числа больше
				{
					k = 1; // значит первое число длиннее второго
					break; // выход из цикла for
				}

				if (s2[i] > s1[i]) // если разряд второго числа больше
				{
					k = 2; // значит второе число длиннее первого
					break; // выход из цикла for
				}
			} // конец for

		}

	if (k == 3) // ни разу не попали в if в предыдущем цикле
		cout << 0;
	else
	{
		int len = s1.length();	// итоговая длина строки (длины строк уже уравняли)

		// делим строку на части по 9 символов	
		int part = len % 9 == 0 ? len / 9 : len / 9 + 1;
		// выделяем память и заполняем 0
		vector <long int> a(part, 0);
		vector <long int> b(part, 0);
		vector <long int> c(part, 0);


		// вызываем функцию занесения строк в массивы
		massiv(a, s1, len, part);
		massiv(b, s2, len, part);

		if (k == 1)
			difference(a, b, c, part);
		else
			difference(b, a, c, part);


		if (k == 2)
			cout << "-";
		for (int i = part - 1; i >= 0; i--)
		{

			cout << to_str(c[i]); // вывод с конца с ведущими нулями!!
		}
	}
	return 0;
}

