#include <iostream>

using namespace std;

bool checkNumbers(int a, int b, int c) //Функция для проверки на возможность трех чисел быть сторонами треугольника
{
	return a + b > c && a + c > b && b + c > a;
}

int triangle(int firstElement, ...) //Основная функция
{
	int* address = &firstElement; //Получаем адресс первого элемента
	int Arr[500]; //Инициализируем массив
	int counter = 0; //Инициализируем счетчик массива
	int successCounter = 0; //Инициализируем счетчик успешных троек

	while (*address != -1) //Пока не дошли до минус единицы
	{
		if (*address == 0) //Если значение по аддрессу = 0, то
		{
			if (counter == 3 && checkNumbers(Arr[0], Arr[1], Arr[2])) //Если до 0 было 3 элемента и при этом они могут быть сторонами треугольника,
				successCounter++; //то увеличиваем счетчика успешных троек на 1
			
			counter = 0; //Сбрасываем счетчик
		}
		else //Иначе
		{
			Arr[counter] = *address; //Добавляем в массив значение по аддрессу
			counter++; //Увеличиваем счетчик массива
		}

		address+=2; //Переходим к следующему параметру путем увеличения указателя на удвоенный битовый размер аргумента
	}

	return successCounter; //Возвращаем ответ
}

int main()
{
	cout << triangle(5, 0, -1) << endl; //3
	cout << triangle(5, 7, 6, 0, 8, 9, 10, 0, -1) << endl; //9
	cout << triangle(5, 7, 6, 0, 8, 9, 10, 0, 8, 2, -1) << endl; //11
}
