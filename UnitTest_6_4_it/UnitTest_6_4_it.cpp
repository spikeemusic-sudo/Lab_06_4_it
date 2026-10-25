#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4_it/Lab_06_4_it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab064it
{
    TEST_CLASS(UnitTestLab064it)
    {
    public:

        // 1. Тестування пошуку індексу мінімального елемента
        TEST_METHOD(TestMinElementIndex)
        {
            // Arrange
            double a[] = { 2.5, -1.0, 3.0, -4.5, 1.0 };
            int n = 5;
            int expected = 3; // Індекс елемента -4.5

            // Act
            int actual = MinElementIndex(a, n);

            // Assert
            Assert::AreEqual(expected, actual);
        }

        // 2. Тестування суми між першим і другим від'ємними (коли між ними є елементи)
        TEST_METHOD(TestSumBetweenNegative_WithElements)
        {
            // Arrange
            double a[] = { 1.0, -2.0, 3.5, 4.5, -1.0, 2.0 };
            int n = 6;
            double expected = 8.0; // 3.5 + 4.5 = 8.0

            // Act
            double actual = SumBetweenFirstAndSecondNegative(a, n);

            // Assert
            Assert::AreEqual(expected, actual, 0.0001);
        }

        // 3. Тестування суми між від'ємними (коли вони поруч, як на твоєму скріншоті)
        TEST_METHOD(TestSumBetweenNegative_Adjacent)
        {
            // Arrange
            double a[] = { -1.40, -4.19, 3.11 };
            int n = 3;
            double expected = 0.00; // Між індексами 0 та 1 немає елементів

            // Act
            double actual = SumBetweenFirstAndSecondNegative(a, n);

            // Assert
            Assert::AreEqual(expected, actual, 0.0001);
        }

        // 4. Тестування перетворення масиву (|x| <= 1 спочатку)
        TEST_METHOD(TestTransformArray)
        {
            // Arrange
            double a[] = { -1.5, 0.5, 2.0, -0.8, 3.0 };
            int n = 5;

            // Act
            TransformArray(a, n);

            // Assert
            // Спочатку мають йти 0.5 та -0.8 (бо їхній модуль <= 1)
            Assert::AreEqual(0.5, a[0], 0.0001);
            Assert::AreEqual(-0.8, a[1], 0.0001);

            // Далі всі інші зі збереженням порядку: -1.5, 2.0, 3.0
            Assert::AreEqual(-1.5, a[2], 0.0001);
            Assert::AreEqual(2.0, a[3], 0.0001);
            Assert::AreEqual(3.0, a[4], 0.0001);
        }
    };
}