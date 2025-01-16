#include <iostream>
#include <vector>
#include <string>  
using namespace std;

// ������� ���������� ������ �� ��������� �� 9 ���� � ��������� �� 
// � ������ � ���� ����� (� �����)
void massiv(vector <long int>& a, string s, int len, int part)
{
	string sub;
	// j - ����� �������� � �������, k - ����� ���������, 
	// i -������� ������� ������� � ���������
	int k = 1, i = len - 9, j = 0;
	while (k <= part)
	{
		// �������� ��������� �� 9 ����, �������� � �����
		// ���� ��������� ��������� �������� ������ 9 ��������,��
		// ����� � 0-�� ������� ��� ����������
		sub = i >= 0 ? s.substr(i, 9) : s.substr(0, 9 + i);
		a[j] = atoi(sub.c_str()); // �������������� � �����
		j++; k++;
		i -= 9;
	}
}

void difference(vector <long int> x, vector <long int> y, vector <long int>& z, int part)
{
	for (int i = 0; i < part; i++) // ������ �� ���� �������� �����, ������� � ����������
	{
		z[i] = x[i] - y[i];

		if (z[i] < 0)
		{
			z[i] += 1000000000;
			x[i + 1]--;//�������� ������
		}

	}

}


// ������� �������������� ����� � ������ � ����������� �����
// �� 9 ��������
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
	// ��������� ���� ����� � ������� ���������
	int k = 3; //���� ����� ����� 
	if (len1 < len2)
	{
		s1.insert(0, len2 - len1, '0');
		k = 2; // ������ ����� ������
	}
	else
		if (len1 > len2)
		{
			s2.insert(0, len1 - len2, '0');
			k = 1; // ������ ����� ������
		}
		else // ����� ����� �����
		{
			for (int i = 0; i < len1; i++) // ����������� ��������� ����� �����
			{
				if (s1[i] > s2[i]) // ���� ������ ������� ����� ������
				{
					k = 1; // ������ ������ ����� ������� �������
					break; // ����� �� ����� for
				}

				if (s2[i] > s1[i]) // ���� ������ ������� ����� ������
				{
					k = 2; // ������ ������ ����� ������� �������
					break; // ����� �� ����� for
				}
			} // ����� for

		}

	if (k == 3) // �� ���� �� ������ � if � ���������� �����
		cout << 0;
	else
	{
		int len = s1.length();	// �������� ����� ������ (����� ����� ��� ��������)

		// ����� ������ �� ����� �� 9 ��������	
		int part = len % 9 == 0 ? len / 9 : len / 9 + 1;
		// �������� ������ � ��������� 0
		vector <long int> a(part, 0);
		vector <long int> b(part, 0);
		vector <long int> c(part, 0);


		// �������� ������� ��������� ����� � �������
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

			cout << to_str(c[i]); // ����� � ����� � �������� ������!!
		}
	}
	return 0;
}

