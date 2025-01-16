#include <iostream>
#include <string>
#include <vector>
struct Pair
{
    char name;
    std::string digit;
    std::string error;
};


bool FLAG(Pair& A) { // Проверка на правильность ввода
    
    std::string alph = "0123456789"; // Возможные составляющие числа

    for (char& ch : A.digit) { // Проверяем каждый символ на вхождение в алфавит
        bool flag = false;
        for (char& alf : alph) {
            if (ch == alf) {
                flag = true; // Символ является цифрой
                break;
            }
        }
        if (!flag) { // Символ не входит в алфавит
            A.error = "Некорректный ввод! Присутствие посторонних символов. Допускается присутствие исключительно цифр.";
            return false;
        }
    }

    if (A.digit[0] == '0') { // Первая цифра не может быть 0
            A.error = "Некорректный ввод! Первая цифра не может быть 0, т.к. мы запросили натуральные числа.";
            return false;
        }

    return true; // Все проверки пройдены успешно
}


void input(Pair& A) {
    bool flag = true;
    do {
        std::cout << "Пожалуйста, введите число " << A.name << ": ";
        std::cin >> A.digit;
        flag = FLAG(A); //проверка на правильность ввода

        if (!flag)
            std::cout << A.error << std::endl;
    } while (!flag);
}


std::string sum(std::string sa, std::string sb) {
    int size_a, size_b, length;
    size_a = sa.length();
    size_b = sb.length();
    if (size_a > size_b) //ищем более длинное число и добавляем единицу для переноса 
        length = size_a + 1;
    else
        length = size_b + 1;
    std::vector <int> a(size_a), b(length, 0);

    for (int i = size_a - 1; i >= 0; i--) { //заполняем вектор цифрами первого слагаемого с конца
        a[size_a - 1 - i] = sa[i] - '0';
    }
    for (int i = size_b - 1; i >= 0; i--) { //заполняем массив цифрами второго слагаемого с конца
        b[size_b - 1 - i] = sb[i] - '0';
    }
    for (int i = 0; i < length; i++) {
        if (i < size_a) //если не дошли до конца вектора a
        {
            b[i] += a[i]; // суммируем последние разряды чисел
            b[i + 1] += (b[i] / 10); // если есть разряд для переноса, переносим его в следующий разряд
            b[i] %= 10; // если есть разряд для переноса он отсекается
        }
    }
    if (b[length - 1] == 0) //если переноса в начало числа не было уменьшаем длину на 1
        length--;
    sb = ""; //результат
    for (int i = length - 1; i >= 0; i--) {
        sb += std::to_string(b[i]); //добавляем по 1 цифре к результату с конца
    }
    return sb;
}


std::string difference(std::string sa, std::string sb) {
    int size_a = sa.length();
    int size_b = sb.length();
    std::string res = ""; // результат

    std::vector<int> a(size_a), b(size_b + 1, 0); // добавляем +1 для b

    // Заполняем вектор цифрами первого числа с конца
    for (int i = size_a - 1; i >= 0; i--) {
        a[size_a - 1 - i] = sa[i] - '0';
    }

    // Заполняем массив цифрами второго числа с конца
    for (int i = size_b - 1; i >= 0; i--) {
        b[size_b - 1 - i] = sb[i] - '0';
    }

    // Проверяем, какое число больше
    bool negative_result = false;
    if ((size_a > size_b) || ((size_a == size_b) && (sa >= sb))) {
        // Первое число больше
        for (int i = 0; i < size_a; i++) {
            a[i] -= (i < size_b ? b[i] : 0); // вычитаем только если есть цифры во втором числе
            if (a[i] < 0) { // если меньше нуля, занимаем у следующего разряда
                a[i] += 10;
                a[i + 1] -= 1;
            }
        }
        while (size_a > 1 && a[size_a - 1] == 0) // избавляемся от незначимых нулей
            size_a--;

        for (int i = size_a - 1; i >= 0; i--)
            res += std::to_string(a[i]); // добавляем по одной цифре к результату с конца
    }
    else {
        // Второе число больше или равно первому
        negative_result = true;
        for (int i = 0; i < size_b; i++) {
            b[i] -= (i < size_a ? a[i] : 0); // вычитаем только если есть цифры в первом числе
            if (b[i] < 0) { // если меньше нуля, занимаем у следующего разряда
                b[i] += 10;
                b[i + 1] -= 1;
            }
        }
        while (size_b > 1 && b[size_b - 1] == 0) // избавляемся от незначимых нулей
            size_b--;

        for (int i = size_b - 1; i >= 0; i--)
            res += std::to_string(b[i]); // добавляем по одной цифре к результату с конца
        res = '-' + res;
    }

    return res;
}

//функция для умножения на 2
std::string multiply_2(const std::string& number) {
    std::string res;
    int carry = 0; //перенос

    // Проходим по строке справа налево
    for (int i = number.length() - 1; i >= 0; --i) {
        int digit = (number[i] - '0') * 2 + carry; // Умножаем цифру на 2 и добавляем перенос
        carry = digit / 10; // Вычисляем новый перенос
        res.push_back((digit % 10) + '0'); // Добавляем текущую цифру в результат
    }

    // Если после цикла остался перенос, добавляем его в результат
    if (carry > 0) {
        res.push_back(carry + '0');
    }

    // Разворачиваем результат, так как добавляли цифры в обратном порядке
    std::reverse(res.begin(), res.end());

    return res;
}


int main()
{
    setlocale(LC_ALL, "ru");
    Pair A, B, C;
    A.name = 'A';
    B.name = 'B';
    C.name = 'C';

    std::cout << "Здравствуйте! Вы используете программу вычисляющую выражение A+2*B-C\n";
    std::cout << "для трех натуральных многозначных чисел A, B и С с количеством знаков более 20.\n";

    input(A);
    input(B);
    input(C);

    std::string B2 = multiply_2(B.digit); // 2*B
    std::string AB2 = sum(A.digit, B2); // A+2*B
    std::string res = difference(AB2, C.digit); //A+2*B-C
    std::cout << std::endl << "Ответ: " << A.digit << " + 2 * " << B.digit << " - " << C.digit << " = " << res << std::endl;
    return 0;
}
