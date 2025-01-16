/*std::string difference(std::string sa, std::string sb) {
    int size_a, size_b;
    size_a = sa.length();
    size_b = sb.length();
    std::string res = ""; //результат

    std::vector <int> a(size_a), b(size_b, 0);

    for (int i = size_a - 1; i >= 0; i--) { //заполн€ем вектор цифрами первого слагаемого с конца
        a[size_a - 1 - i] = sa[i] - '0';
    }
    for (int i = size_b - 1; i >= 0; i--) { //заполн€ем массив цифрами второго слагаемого с конца
        b[size_b - 1 - i] = sb[i] - '0';
    }


    if ((size_a > size_b) || ((size_a == size_b) && (sa[0] > sb[0]))) {// если первое слагаемое больше по длине или
        for (int i = 0; i < size_a; i++) {                             // равно по длине, но больше по старшему разр€ду
            a[i] -= b[i]; // вычитаем последние разр€ды чисел
            if (a[i] < b[i]) { // исключаем отрицательную разницу, занима€ у большего разр€да
                a[i + 1] -= 1;
                a[i] += 10;
            }
        }
        while (size_a > 1 && a[size_a] == 0) //избавл€емс€ от незначимых нулей
            size_a -= 1;

        for (int i = size_a; i >= 0; i--)
            res += std::to_string(a[i]); //добавл€ем по 1 цифре к результату с конца
        return res;
    }

    else {//чтобы сделать задачу проще, вычтем из большего меньшее и домножим в конце на -1
        for (int i = 0; i < size_a; i++) {                             // равно по длине, но больше по старшему разр€ду
            b[i] -= a[i]; // вычитаем последние разр€ды чисел
            if (b[i] < a[i]) { // исключаем отрицательную разницу, занима€ у большего разр€да
                b[i + 1] -= 1;
                b[i] += 10;
            }
        }
        while (size_a > 1 && b[size_a] == 0) //избавл€емс€ от незначимых нулей
            size_a -= 1;

        for (int i = size_a; i >= 0; i--)
            res += std::to_string(b[i]); //добавл€ем по 1 цифре к результату с конца
        res = '-' + res;
        return res;
    }
}*/









/*
std::string multiply_2(std::string B) {
    int length;
    length = B.length() + 1;//единица дл€ переноса

    std::vector <int> b(length);

    for (int i = length - 1; i >= 0; i--) { //заполн€ем массив цифрами слагаемого с конца
        b[length - 1 - i] = B[i] - '0';
    }

    for (int i = 0; i < length; i++) {
        b[i] *= 2;
        b[i + 1] += (b[i] / 10); // если есть разр€д дл€ переноса, переносим его в следующий разр€д
        b[i] %= 10; // если есть разр€д дл€ переноса он отсекаетс€
    }
    if (b[length - 1] == 0) //если переноса в начало числа не было уменьшаем длину на 1
        length--;
    std::string res = ""; //результат
    for (int i = length - 1; i >= 0; i--) {
        res += std::to_string(b[i]); //добавл€ем по 1 цифре к результату с конца
    }
    return res;
}
*/