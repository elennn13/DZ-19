#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

//1
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//2
int mirror_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

//3
int findAndSort(int arr[], int length, int N) {
    int position = -1;

    // Поиск первой позиции числа N
    for (int i = 0; i < length; i++) {
        if (arr[i] == N) {
            position = i;
            break;
        }
    }

    if (position != -1) {
        // Сортировка элементов справа от N
        std::sort(arr + position + 1, arr + length);
    }

    return position;
}

//4
void fillArrayWithRandom(int arr[], int length, int A, int B) {
    srand(time(0)); // инициализация генератора случайных чисел

    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % (B - A + 1) + A; // генерация случайного числа в диапазоне от A до B
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    
    // Задача 1
    // Создайте функцию, которая принимает два числа и
    // возвращает их наибольший общий делитель.
    int num1, num2;
    std::cout << "Введите два числа: ";
    std::cin >> num1 >> num2;

    int result = gcd(num1, num2);
    std::cout << "Наибольший общий делитель: " << result << std::endl;

   // Задача 2
   // Напишите функцию mirror_number, которая
   // принимает число и возвращает его в отражённом виде.
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;

    int mirrored_num = mirror_number(num);

    std::cout << "Отраженное число: " << mirrored_num << std::endl;

    // Задача 3
    // Создайте функцию, которая принимает массив, его
    // длину и число N.Функция возвращает первую позицию
    // числа N в массиве, а также сортирует все элементы,
    // которые находятся справа от N.
    int arr[] = { 5, 3, 2, 8, 6, 4 };
    int length = sizeof(arr) / sizeof(arr[0]);
    int N = 8;

    int result = findAndSort(arr, length, N);

    std::cout << "Position of " << N << ": " << result << std::endl;
    std::cout << "Sorted array: ";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
   
    // Задача 4
    // Создайте функцию, которая принимает пустой
    // массив, его длину и два числа A и B, которые являются
    // началом и концом диапазона.Функция должна
    // заполнять массив случайными числами из указанного
    // диапазона.
    const int length = 10;
    int myArray[length];

    int A = 1; // начало диапазона
    int B = 100; // конец диапазона

    fillArrayWithRandom(myArray, length, A, B);

    // Выводим заполненный массив
    std::cout << "Массив случайных чисел из диапазона [" << A << ", " << B << "]: ";
    for (int i = 0; i < length; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
   
    return 0;
}
