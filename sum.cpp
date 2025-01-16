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
	size_a = sa.length();//����� ������� ����������
	size_b = sb.length();//����� ������� ����������
	if (size_a > size_b) //���� ����� ������� ����� � ��������� ������� ��� �������� 
		length = size_a + 1;
	else
		length = size_b + 1;
	vector <int> a(size_a), b(length, 0);

	for (int i = size_a - 1; i >= 0; i--) //��������� ������ ������� ������� ���������� � �����
	{
		a[size_a - 1 - i] = sa[i] - '0';
	}
	for (int i = size_b - 1; i >= 0; i--) //��������� ������ ������� ������� ���������� � �����
	{
		b[size_b - 1 - i] = sb[i] - '0';
	}
	for (int i = 0; i < length; i++) //����������
	{
		if (i < size_a) //�� ����� �� ����� ������� a
		{
			b[i] += a[i]; // ��������� ��������� ������� �����
			b[i + 1] += (b[i] / 10); // ���� ���� ������ ��� ��������, ��������� ��� � ��������� ������
			b[i] %= 10; // ���� ���� ������ ��� �������� �� ����������
		}
	}
	if (b[length - 1] == 0) //���� �������� � ������ ����� �� ���� ��������� ����� �� 1
		length--;
	sb = ""; //�������������� ������
	for (int i = length - 1; i >= 0; i--)
	{
		sb += to_string(b[i]); //��������� �� 1 ����� � ���������� � �����
	}
	cout << sb;
	return 0;
}

