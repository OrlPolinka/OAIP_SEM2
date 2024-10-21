//ДОП Вариант 3 Задание 1

#include <iostream>
using namespace std;

//уравнение 1
double f1(double x)
{
    return cos(x) + x - 7;
}

//уравнение 2
double f2(double x)
{
    return exp(x) - 1 / x;
}

//Функция нахождения корней методом дихотомии
double function(double (*f)(double), double a, double b, double e, int maxIterations)
{
    double c;
    int iteration = 0;
    while (b - a >= 2 * e && iteration < maxIterations)//пока условие верно, выполняем
    {
        c = (a + b) / 2;//находим среднее значение
        if (f(c) == 0)
        {
            return c;
        }
        else
        {
            if (f(a) * f(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
        iteration++;
    }
    cout << "a = " << a << " b = " << b << endl;//выводим значения на экран
    return c;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int maxIterations;
    double a, b, c;
    const double e = 0.001;

    //Вводим значения переменных
    cout << "Введите начальное значение a: ";
    cin >> a;
    cout << "Введите начальное значение b: ";
    cin >> b;
    cout << "Введите максимальное количество итераций n: ";
    cin >> maxIterations;

    //находим корни уравнений
    double root1 = function(f1, a, b, e, maxIterations);
    double root2 = function(f2, a, b, e, maxIterations);

    //выводим результат на экран
    cout << "Корень уравнения cos(x) + x - 7 = 0: " << root1 << endl;
    cout << "Корень уравнения exp(x) - 1 / x: " << root2 << endl;
    return 0;
}