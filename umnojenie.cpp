/*std::string difference(std::string sa, std::string sb) {
    int size_a, size_b;
    size_a = sa.length();
    size_b = sb.length();
    std::string res = ""; //���������

    std::vector <int> a(size_a), b(size_b, 0);

    for (int i = size_a - 1; i >= 0; i--) { //��������� ������ ������� ������� ���������� � �����
        a[size_a - 1 - i] = sa[i] - '0';
    }
    for (int i = size_b - 1; i >= 0; i--) { //��������� ������ ������� ������� ���������� � �����
        b[size_b - 1 - i] = sb[i] - '0';
    }


    if ((size_a > size_b) || ((size_a == size_b) && (sa[0] > sb[0]))) {// ���� ������ ��������� ������ �� ����� ���
        for (int i = 0; i < size_a; i++) {                             // ����� �� �����, �� ������ �� �������� �������
            a[i] -= b[i]; // �������� ��������� ������� �����
            if (a[i] < b[i]) { // ��������� ������������� �������, ������� � �������� �������
                a[i + 1] -= 1;
                a[i] += 10;
            }
        }
        while (size_a > 1 && a[size_a] == 0) //����������� �� ���������� �����
            size_a -= 1;

        for (int i = size_a; i >= 0; i--)
            res += std::to_string(a[i]); //��������� �� 1 ����� � ���������� � �����
        return res;
    }

    else {//����� ������� ������ �����, ������ �� �������� ������� � �������� � ����� �� -1
        for (int i = 0; i < size_a; i++) {                             // ����� �� �����, �� ������ �� �������� �������
            b[i] -= a[i]; // �������� ��������� ������� �����
            if (b[i] < a[i]) { // ��������� ������������� �������, ������� � �������� �������
                b[i + 1] -= 1;
                b[i] += 10;
            }
        }
        while (size_a > 1 && b[size_a] == 0) //����������� �� ���������� �����
            size_a -= 1;

        for (int i = size_a; i >= 0; i--)
            res += std::to_string(b[i]); //��������� �� 1 ����� � ���������� � �����
        res = '-' + res;
        return res;
    }
}*/









/*
std::string multiply_2(std::string B) {
    int length;
    length = B.length() + 1;//������� ��� ��������

    std::vector <int> b(length);

    for (int i = length - 1; i >= 0; i--) { //��������� ������ ������� ���������� � �����
        b[length - 1 - i] = B[i] - '0';
    }

    for (int i = 0; i < length; i++) {
        b[i] *= 2;
        b[i + 1] += (b[i] / 10); // ���� ���� ������ ��� ��������, ��������� ��� � ��������� ������
        b[i] %= 10; // ���� ���� ������ ��� �������� �� ����������
    }
    if (b[length - 1] == 0) //���� �������� � ������ ����� �� ���� ��������� ����� �� 1
        length--;
    std::string res = ""; //���������
    for (int i = length - 1; i >= 0; i--) {
        res += std::to_string(b[i]); //��������� �� 1 ����� � ���������� � �����
    }
    return res;
}
*/