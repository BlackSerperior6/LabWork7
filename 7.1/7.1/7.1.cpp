﻿#include <iostream>
#include <string>

using namespace std;

int findAmount(int* arr, int size) //Перегрузка для нахождения кол-ва четных элементов массива
{
	int counter = 0; //Инициализируем счетчик

	for (int i = 0; i < size; i++) //Проходим по всему массиву
	{
		if (arr[i] % 2 == 0) //Если элемент четный, увеличиваем счетчик
			counter++;
	}

	return counter; //Возвращаем значение счетчика
}

int findAmount(string String) //Перегрузка для нахождения кол-ва слов, начинающихся на а
{
	int size = String.size(); //Получаем размер строки
	int counter = 0; //Инициализируем счетчик
	string ArrOfStrings[500]; //Инициализируем массив строк
	int ArrOfStringsCounter = 0; //Инициализируем его размер
	string buffer = ""; //Инициализируем буффер

	for (int i = 0; i < size + 1; i++) //Проходим по всей строке
	{
		if (String[i] == ' ' || i == size) //Если текущий элемент - пробел или же достигнут последний элемент
		{
			ArrOfStrings[ArrOfStringsCounter] = buffer; //Заносим в массив строк значение буффера
			buffer = ""; //Опустошаем буффер
			ArrOfStringsCounter++; //Увеличиваем счетчик кол-ва элементов массива
		}
		else
			buffer += String[i]; //Иначе заносим в буффер текущий символ
	}

	for (int i = 0; i < ArrOfStringsCounter; i++) //Проходим по раннее сгенерированному массиву строк (к этому момент массив из себя будет представлять набор слов введеной строки)
	{
		int element = (int) ArrOfStrings[i][0]; //Получаем код первой буквы слова

		if (ArrOfStrings[i].length() >= 2 && (element == -128 || element == -96 || element == 97 || element == 65)) //Если слово имеет больше одного символа (если меньше, то это не слово) и при этом его первая буква = загалавная или строчная а,
			counter++; //то увеличиваем счетчик
	}

	return counter; //Возвращаем значение счетчика
}

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "Введите строку, в которой нужно посчитать кол-во слово, начинающихся на заглавную или строчную а" << endl;

	string s;
	getline(cin, s); //Получаем строку, введенную пользователем

	if (s.size() == 0) //Проверка строки на то, что она не пустая
	{
		cout << "Строка должна содержать хотя бы один символ!" << endl;
		return 0;
	}

	cout << "Число слов, начинающихся на а: " << findAmount(s) << endl << endl; //Выводим результат

	cout << "Введите размер массива" << endl;

	srand(time(0));
	int arr[500];
	int size;

	cin >> size; //Вводим размер массива

	if (size < 1) //Проверяем размер массива
	{
		cout << "Размер массива должен быть больше или равен 1!" << endl;
		return 0;
	}

	cout << "Ваш массив:" << endl;

	//Генерируем и выводим массив
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}

	cout << endl << endl << "Число четных элементов массива: " << findAmount(&arr[0], size) << endl; //Выводим результат
}
