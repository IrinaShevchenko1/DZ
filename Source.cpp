#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAX 100
#define MIN -100
template<typename T>
T retRand(T min, T max, int order = 1);//прототип шаблона фун-ии заполнения случайными числами 
template<typename T>
T retRand1(T min, T max, int order = 1);//прототип шаблона фун-ии заполнения случайными числами включая границу 
template<typename T>
void fillArr(T arr[], const int SIZE, const T min, const T max, const int order = 1);//прототип шаблона фн-ии заполнения массива
template<typename T>
void fillArr1(T arr[], const int SIZE, const T min, const T max, const int order = 1);//прототип шаблона фн-ии заполнения массива включая границу 
template<typename T>
void showArr(const T arr[], const int SIZE);//прототип шаблона фн-ии вывода массива
template<typename T>
void bubbleSort(T arr[], const int SIZE, int min = 0);//прототип шаблона фн-ии пузырьковой сортировки  по убыванию
template<typename T>
void selectSort(T arr[], const int SIZE, int min = 0);//прототип шаблона фн-ии сортировки выбором по возрастанию
template<typename T>
void insertSort(T arr[], const int SIZE, int min = 0);//прототип шаблона фн-ии сортировки вставками по убыванию
template<typename T>
void bubbleSort1(T arr[], const int SIZE, int min = 0);//прототип шаблона фн-ии пузырьковой сортировки по возрастанию

void main() //главная фн-ия 
{//начало блока main
	srand(time(NULL));//интервал для действительно случайных чисел
	char choise{};//объявление переменной для выбора
	while (true || choise != '0')//условие входа в блок while
	{//начало блока while
		system("cls");//очистка экрана
		cout << "Good day!Choose task:\n";//просит сделать выбор
		cout << "1 - Bubble sorting\n";
		cout << "2 - Selection and insertion sorting\n";
		cout << "3- Sort 2/3 or 1/3 of an array \n";
		cout << "4 - Academic performance\n";
		cout << "0 - Exit\n";
		cin >> choise;//ввод выбора
		if (choise == '0')break;//условие выхода из while
		switch (choise)//множественный выбор
		{//начало блока switch
		case '1':
		{//начало блока case '1'
			cout << endl;
			cout << "\tBubble sorting\n";
			cout << endl;
			int min = -20;//переменная для min диапазона
			int max = 20;//переменная для max диапазонa
			const int SIZE = 15;//переменная размерности массива
			int arr[SIZE] = { 0 };//переменная для массива
			fillArr(arr, SIZE, min, max);//вызов фн-ии по заполнению массива
			int num1 = 0;//переменная порядкового номера крайнего левого элемента
			int num2 = 0;//переменная порядкового номера крайнего правого элемента
			for (int i = 0; i < SIZE; i++)//нахождение крайнего левого элемента
			{
				num1 = i+1;//запись порядкового номера
				if (arr[i] < 0)break;//условие выхода,т.к. нашли левый крайний элемент
			}
			for (int i = SIZE - 1; i >= 0; i--)//нахождение крайнего правого элемента
			{
				num2 = i+1;//запись порядкового номера
				if (arr[i] < 0)break;//условие выхода,т.к. нашли левый правый элемент
			}
			cout << num1-1;
			cout << num2-1;
			cout << endl;
			cout << "Initial array:\n";//начальный массив
			cout << endl;
			showArr(arr, SIZE);//вызов фн-ии вывода массива
			bubbleSort(arr, num2, num1);//вызов фн-ии пузырьковой сортировки
			cout << endl;
			cout << "Sorted array:\n";//отсортированный массив
			cout << endl;
			showArr(arr, SIZE);//вызов фн-ии вывода массива
		}//конец блока case '1'
		break;

		case '2':
		{//начало блока case '2'
			cout << endl;
			cout << "\tSelection and insertion sorting\n";
			cout << endl;
			float min = 10.00f;//переменная для min диапазона
			float max = 99.99f;//переменная для max диапазонa
			const int SIZE = 20;//переменная размерности массива
			float arr[SIZE] = { 0 };//переменная для массива
			int order = 100;//переменная для делителя
			fillArr1(arr, SIZE, min, max, order);//вызов фн-ии по заполнению массива
			int num = SIZE / 2;//переменная для границы сортировки
			cout << endl;
			cout << "Initial array:\n";//начальный массив
			cout << endl;
			showArr(arr, SIZE);//вызов фн-ии вывода массива
			selectSort(arr, num);//вызов фн-ии сортировки выбором
			insertSort(arr, SIZE, num);//вызов фн-ии сортировки вставками
			cout << endl;
			cout << "Sorted array:\n";//отсортированный массив
			cout << endl;
			showArr(arr, SIZE);//вызов фн-ии вывода массива
		}//конец блока case '2'
		break;

		case '3':
		{//начало блока case '3'
			cout << endl;
			cout << "\tSort 2/3 or 1/3 of an array\n";
			cout << endl;
			const int SIZE = 9;//переменная размерности массива
			int arr[SIZE] = { 0 };//переменная для массива
			fillArr(arr, SIZE, MIN, MAX);//вызов фн-ии по заполнению массива
			cout << "Initial array:\n";//начальный массив
			cout << endl;
			showArr(arr, SIZE);//вызов фн-ии вывода массива
			float aver = 0;//переменная для сред.арифм.
			int sum = 0;//переменная для суммы
			for (int i = 0; i < SIZE; i++)
			{
				sum += arr[i];//нахождение суммы всех элементов
			}
			aver = (float)sum / SIZE;//нахождение сред.арифм. всех элементов
			int sizeSort = 0;//переменная для границы сортировки
			if ((aver - (int)aver%1) > 0)//проверка на положительность
			{//если да,то:
				sizeSort = (SIZE / 3) * 2;//нахождение границы сортировки
			}
			else
			{//иначе
				sizeSort = SIZE / 3;//нахождение границы сортировки
			}
			bubbleSort1(arr, sizeSort);//вызов фн-ии пузырьковой сортировки
			cout << endl;
			cout << "Sorted array:\n";//отсортированный массив
			cout << endl;
				for (int j = 0; j < sizeSort; j++)
				{
					cout << arr[j] << ' ';//вывод массива
				}
				int t = 0;
				for (int k = sizeSort ; k < SIZE; k++)
				{
					cout << arr[SIZE- 1 - t] << ' ';//вывод массива
					t++;
				}
			
		}//конец блока case '3'
		break;

		case '4':
		{//начало блока case '4'
			cout << endl;
			cout << "\tAcademic performance\n";
			cout << endl;
			int min = 1;//переменная для min диапазона
			int max = 12;//переменная для max диапазонa
			const int SIZE = 10;//переменная размерности массива
			int arr[SIZE] = { 0 };//переменная для массива
			fillArr1(arr, SIZE, min, max);//вызов фн-ии по заполнению массива
			cout << endl;
			cout << "Student grades output:\n";//вывод оценок
			cout << endl;
			showArr(arr, SIZE);//вызов фн-ии вывода массива
			cout << endl;
			cout << "Retake exam:\n";//пересдача экзамена
			cout << "Enter serial number:\n";//просит ввести порядковый номер оценки
			int num = 0;//переменная для порядкового номера
			cin >> num;//ввод поряд.номера
			cout << "Enter a new grade:\n";//просит ввести новую оценку
			int grade = 0;//переменная для оценки
			cin >> grade;//ввод новой оценки
			for (int i = 0; i < SIZE; i++)
			{
				if (i == num)//проверка порядкового номера
				{//есди да,то:
					arr[i] = grade;//запись новой оценки
				}
			}
			float aver = 0;//переменная для сред.арифм.
			int sum = 0;//переменная для суммы
			for (int i = 0; i < SIZE; i++)
			{
				sum += arr[i];//нахождение суммы всех элементов
			}
			aver = (float)sum / SIZE;//нахождение сред.арифм. всех элементов
			float minG = 10.7f;//min сред.бал
			cout << endl;
			if (aver - minG >= 0)//сравнение условия выхода на стипендию
			{//есди да,то:
				cout << "Student went on a scholarship, because average grade " << aver << endl;//выводит,что студент вышел на стипендию
			}
			else
			{//иначе
				cout << "Student did not enter a scholarship, because average grade " << aver << endl;//выводит,что студент не вышел на стипендию
			}
			cout << endl;
			cout << "Sort grades:\n";//сортировка оценок
			cout << "Select sort type: 1 - ascending, 2 - descending\n";//просит сделать выбор сортировки
			int sel = 0;//переменная для выбора
			cin >> sel; //ввод выбора
			if (sel == 1) //сравнение выбора по возрастанию
			{//есди да,то:
				cout << "Ascending:\n";//по возрастанию
				bubbleSort1(arr, SIZE);//вызов фн-ии пузырьковой сортировки 
				cout << endl;
				showArr(arr, SIZE);//вызов фн-ии вывода массива
				cout << endl;
			}
			else if (sel == 2) //сравнение выбора по убыванию
			{//есди да,то:
				cout << "Descending:\n";//по убыванию
				bubbleSort(arr, SIZE);//вызов фн-ии пузырьковой сортировки 
				cout << endl;
				showArr(arr, SIZE);//вызов фн-ии вывода массива
				cout << endl;
			}
			else
			{//иначе
				cout << "Error! Of such type not found!\n "  << endl;//выводит,что такого типа нет
			}
		}//конец блока case '4'
		break;

		default:
			cout << "Error!Function not found\n";
			cout << endl;
			break;
		}
		system("pause");//задержка
	}//конец блока while
	cout << endl;
	cout << "Thanks for Your attention, goodbay\n";
	cout << endl;
}//конец блока main

template<typename T> // шаблон фн-ии случайного числа
T retRand(T min, T max, int order)
{
	return ((T)(rand() % (((int)max - (int)min)*order) + min*order) / order);//возвращает случайное число в диапазоне от min до max
}//конец фн-ии retRand

template<typename T> // шаблон фн-ии заполнения массива
void fillArr(T arr[], const int SIZE, const T min, const T max, const int order)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = retRand(min, max, order);//заполнение массива случайными числами
	}
}//конец фн-ии fillArr

template<typename T> // шаблон фн-ии случайного числа включая границы
T retRand1(T minim, T maxim, int ord)
{
	return ((T)(rand() % (((int)maxim - (int)minim)*ord + 1) + minim*ord) / ord);//возвращает случайное число в диапазоне от min до max
}//конец фн-ии retRand1

template<typename T> // шаблон фн-ии заполнения массива включая границы
void fillArr1(T arr[], const int SIZE, const T minim, const T maxim, const int ord)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = retRand1(minim, maxim, ord);//заполнение массива случайными числами
	}
}//конец фн-ии fillArr1

template<typename T> // шаблон фн-ии вывода массива
void showArr(const T arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ' ';//вывод массива 
	}
	cout << endl;
}//конец фн-ии showArr

template<typename T>
void bubbleSort(T arr[], const int SIZE, int min)//прототип шаблона фн-ии пузырьковой сортировки  по убыванию
{
	T temp{};
	for (int i = min; i < SIZE; i++)
	{
		for (int j = min; j < SIZE - i - 1; j++)
		{
			if (arr[j + 1] > arr[j])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}//конец фн-ии bubbleSort

template<typename T>
void selectSort(T arr[], const int SIZE, int min)//прототип шаблона фн-ии сортировки выбором по возрастанию
{
	T temp{};
	int indMin{};
	for (int i = min; i < SIZE; i++)
	{
		indMin = i;
		temp = arr[i];
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[j] < temp)
			{
				temp = arr[j];
				indMin = j;
			}
		}
		arr[indMin] = arr[i];
		arr[i] = temp;
	}
}//конец фн-ии selectSort

template<typename T>
void insertSort(T arr[], const int SIZE, int min)//прототип шаблона фн-ии сортировки вставками по убыванию
{
	T temp{};
	for (int i = min; i < SIZE; i++)
	{
		temp = arr[i];
		for (int j = i - 1; j >= 0 && arr[j] < temp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = temp;
		}
	}
}//конец фн-ии insertSort

template<typename T>
void bubbleSort1(T arr[], const int SIZE, int min)//прототип шаблона фн-ии пузырьковой сортировки по возрастанию
{
	T temp{};
	for (int i = min; i < SIZE; i++)
	{
		for (int j = min; j < SIZE - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}//конец фн-ии bubbleSort1
