// Lab_06_4_it.cpp
// Фащевський Богдан
// Лабораторна робота № 6.4
// Варіант 28
// Опрацювання та впорядкування одновимірних динамічних масивів

#include <iostream>
#include <iomanip>
#include <cmath>   // Для функції abs()
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

// 1. Функція для заповнення масиву випадковими дійсними числами
void Create(double* a, const int n, const double Low, const double High)
{
    for (int i = 0; i < n; i++)
    {
        // Генеруємо дійсне число в діапазоні [Low, High]
        a[i] = Low + (rand() / (double)RAND_MAX) * (High - Low);
    }
}

// 2. Функція для виведення масиву
void Print(double* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(9) << setprecision(2) << fixed << a[i];
    }
    cout << endl;
}

// 3. Функція пошуку номера (індексу) мінімального елемента масиву
int MinElementIndex(double* a, const int n)
{
    int min_idx = 0; // Припускаємо, що перший елемент - мінімальний
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[min_idx])
        {
            min_idx = i;
        }
    }
    return min_idx;
}

// 4. Функція обчислення суми елементів між першим і другим від'ємними
double SumBetweenFirstAndSecondNegative(double* a, const int n)
{
    int first_neg = -1;
    int second_neg = -1;

    // Шукаємо індекси першого та другого від'ємних елементів
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            if (first_neg == -1)
            {
                first_neg = i;
            }
            else if (second_neg == -1)
            {
                second_neg = i;
                break; // Знайшли обидва, виходимо з циклу
            }
        }
    }

    // Якщо від'ємних елементів менше двох, суму обчислити неможливо
    if (first_neg == -1 || second_neg == -1)
    {
        return 0;
    }

    double sum = 0;
    // Обчислюємо суму елементів між ними (не включаючи самі ці від'ємні елементи)
    for (int i = first_neg + 1; i < second_neg; i++)
    {
        sum += a[i];
    }

    return sum;
}

// 5. Функція перетворення масиву (збереження відносного порядку)
void TransformArray(double* a, const int n)
{
    // Створюємо тимчасовий динамічний масив для перегрупування
    double* temp = new double[n];
    int j = 0;

    // Перший прохід: копіюємо елементи, модуль яких не перевищує 1 (|x| <= 1)
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) <= 1.0)
        {
            temp[j++] = a[i];
        }
    }

    // Другий прохід: копіюємо всі інші елементи (|x| > 1)
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) > 1.0)
        {
            temp[j++] = a[i];
        }
    }

    // Копіюємо перетворений масив назад у вихідний
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    // Звільняємо пам'ять тимчасового масиву
    delete[] temp;
}

int main()
{
    // Налаштування консолі для виведення кирилиці (UTF-8)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand((unsigned)time(NULL));

    int n;
    cout << "Введіть кількість елементів масиву (n): ";
    cin >> n;

    if (n <= 0)
    {
        cerr << "Розмір масиву має бути більшим за 0!" << endl;
        return 1;
    }

    // Створення динамічного масиву дійсних чисел
    double* a = new double[n];

    // Діапазон підібрано [-5.0, 5.0], щоб генерувались числа і в межах [-1, 1], і поза ними
    double Low = -5.0;
    double High = 5.0;

    // 1. Формування масиву
    Create(a, n, Low, High);

    // 2. Виведення початкового масиву
    cout << "Початковий масив:" << endl;
    Print(a, n);

    // 3. Пункт 1.1: Номер (індекс) мінімального елемента
    int minIndex = MinElementIndex(a, n);
    cout << "\nІндекс мінімального елемента: " << minIndex << " (значення: " << a[minIndex] << ")" << endl;

    // 4. Пункт 1.2: Сума елементів між першим і другим від'ємними
    double sum = SumBetweenFirstAndSecondNegative(a, n);
    cout << "Сума елементів між першим і другим від'ємними: " << sum << endl;

    // 5. Пункт 2: Перетворення масиву
    TransformArray(a, n);

    // 6. Виведення модифікованого масиву
    cout << "\nМодифікований масив (|x| <= 1 спочатку):" << endl;
    Print(a, n);

    // Знищення динамічного масиву та звільнення пам'яті
    delete[] a;

    return 0;
}