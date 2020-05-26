#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAX 100
#define MIN -100
template<typename T>
T retRand(T min, T max, int order = 1);//�������� ������� ���-�� ���������� ���������� ������� 
template<typename T>
T retRand1(T min, T max, int order = 1);//�������� ������� ���-�� ���������� ���������� ������� ������� ������� 
template<typename T>
void fillArr(T arr[], const int SIZE, const T min, const T max, const int order = 1);//�������� ������� ��-�� ���������� �������
template<typename T>
void fillArr1(T arr[], const int SIZE, const T min, const T max, const int order = 1);//�������� ������� ��-�� ���������� ������� ������� ������� 
template<typename T>
void showArr(const T arr[], const int SIZE);//�������� ������� ��-�� ������ �������
template<typename T>
void bubbleSort(T arr[], const int SIZE, int min = 0);//�������� ������� ��-�� ����������� ����������  �� ��������
template<typename T>
void selectSort(T arr[], const int SIZE, int min = 0);//�������� ������� ��-�� ���������� ������� �� �����������
template<typename T>
void insertSort(T arr[], const int SIZE, int min = 0);//�������� ������� ��-�� ���������� ��������� �� ��������
template<typename T>
void bubbleSort1(T arr[], const int SIZE, int min = 0);//�������� ������� ��-�� ����������� ���������� �� �����������

void main() //������� ��-�� 
{//������ ����� main
	srand(time(NULL));//�������� ��� ������������� ��������� �����
	char choise{};//���������� ���������� ��� ������
	while (true || choise != '0')//������� ����� � ���� while
	{//������ ����� while
		system("cls");//������� ������
		cout << "Good day!Choose task:\n";//������ ������� �����
		cout << "1 - Bubble sorting\n";
		cout << "2 - Selection and insertion sorting\n";
		cout << "3- Sort 2/3 or 1/3 of an array \n";
		cout << "4 - Academic performance\n";
		cout << "0 - Exit\n";
		cin >> choise;//���� ������
		if (choise == '0')break;//������� ������ �� while
		switch (choise)//������������� �����
		{//������ ����� switch
		case '1':
		{//������ ����� case '1'
			cout << endl;
			cout << "\tBubble sorting\n";
			cout << endl;
			int min = -20;//���������� ��� min ���������
			int max = 20;//���������� ��� max ��������a
			const int SIZE = 15;//���������� ����������� �������
			int arr[SIZE] = { 0 };//���������� ��� �������
			fillArr(arr, SIZE, min, max);//����� ��-�� �� ���������� �������
			int num1 = 0;//���������� ����������� ������ �������� ������ ��������
			int num2 = 0;//���������� ����������� ������ �������� ������� ��������
			for (int i = 0; i < SIZE; i++)//���������� �������� ������ ��������
			{
				num1 = i+1;//������ ����������� ������
				if (arr[i] < 0)break;//������� ������,�.�. ����� ����� ������� �������
			}
			for (int i = SIZE - 1; i >= 0; i--)//���������� �������� ������� ��������
			{
				num2 = i+1;//������ ����������� ������
				if (arr[i] < 0)break;//������� ������,�.�. ����� ����� ������ �������
			}
			cout << num1-1;
			cout << num2-1;
			cout << endl;
			cout << "Initial array:\n";//��������� ������
			cout << endl;
			showArr(arr, SIZE);//����� ��-�� ������ �������
			bubbleSort(arr, num2, num1);//����� ��-�� ����������� ����������
			cout << endl;
			cout << "Sorted array:\n";//��������������� ������
			cout << endl;
			showArr(arr, SIZE);//����� ��-�� ������ �������
		}//����� ����� case '1'
		break;

		case '2':
		{//������ ����� case '2'
			cout << endl;
			cout << "\tSelection and insertion sorting\n";
			cout << endl;
			float min = 10.00f;//���������� ��� min ���������
			float max = 99.99f;//���������� ��� max ��������a
			const int SIZE = 20;//���������� ����������� �������
			float arr[SIZE] = { 0 };//���������� ��� �������
			int order = 100;//���������� ��� ��������
			fillArr1(arr, SIZE, min, max, order);//����� ��-�� �� ���������� �������
			int num = SIZE / 2;//���������� ��� ������� ����������
			cout << endl;
			cout << "Initial array:\n";//��������� ������
			cout << endl;
			showArr(arr, SIZE);//����� ��-�� ������ �������
			selectSort(arr, num);//����� ��-�� ���������� �������
			insertSort(arr, SIZE, num);//����� ��-�� ���������� ���������
			cout << endl;
			cout << "Sorted array:\n";//��������������� ������
			cout << endl;
			showArr(arr, SIZE);//����� ��-�� ������ �������
		}//����� ����� case '2'
		break;

		case '3':
		{//������ ����� case '3'
			cout << endl;
			cout << "\tSort 2/3 or 1/3 of an array\n";
			cout << endl;
			const int SIZE = 9;//���������� ����������� �������
			int arr[SIZE] = { 0 };//���������� ��� �������
			fillArr(arr, SIZE, MIN, MAX);//����� ��-�� �� ���������� �������
			cout << "Initial array:\n";//��������� ������
			cout << endl;
			showArr(arr, SIZE);//����� ��-�� ������ �������
			float aver = 0;//���������� ��� ����.�����.
			int sum = 0;//���������� ��� �����
			for (int i = 0; i < SIZE; i++)
			{
				sum += arr[i];//���������� ����� ���� ���������
			}
			aver = (float)sum / SIZE;//���������� ����.�����. ���� ���������
			int sizeSort = 0;//���������� ��� ������� ����������
			if ((aver - (int)aver%1) > 0)//�������� �� ���������������
			{//���� ��,��:
				sizeSort = (SIZE / 3) * 2;//���������� ������� ����������
			}
			else
			{//�����
				sizeSort = SIZE / 3;//���������� ������� ����������
			}
			bubbleSort1(arr, sizeSort);//����� ��-�� ����������� ����������
			cout << endl;
			cout << "Sorted array:\n";//��������������� ������
			cout << endl;
				for (int j = 0; j < sizeSort; j++)
				{
					cout << arr[j] << ' ';//����� �������
				}
				int t = 0;
				for (int k = sizeSort ; k < SIZE; k++)
				{
					cout << arr[SIZE- 1 - t] << ' ';//����� �������
					t++;
				}
			
		}//����� ����� case '3'
		break;

		case '4':
		{//������ ����� case '4'
			cout << endl;
			cout << "\tAcademic performance\n";
			cout << endl;
			int min = 1;//���������� ��� min ���������
			int max = 12;//���������� ��� max ��������a
			const int SIZE = 10;//���������� ����������� �������
			int arr[SIZE] = { 0 };//���������� ��� �������
			fillArr1(arr, SIZE, min, max);//����� ��-�� �� ���������� �������
			cout << endl;
			cout << "Student grades output:\n";//����� ������
			cout << endl;
			showArr(arr, SIZE);//����� ��-�� ������ �������
			cout << endl;
			cout << "Retake exam:\n";//��������� ��������
			cout << "Enter serial number:\n";//������ ������ ���������� ����� ������
			int num = 0;//���������� ��� ����������� ������
			cin >> num;//���� �����.������
			cout << "Enter a new grade:\n";//������ ������ ����� ������
			int grade = 0;//���������� ��� ������
			cin >> grade;//���� ����� ������
			for (int i = 0; i < SIZE; i++)
			{
				if (i == num)//�������� ����������� ������
				{//���� ��,��:
					arr[i] = grade;//������ ����� ������
				}
			}
			float aver = 0;//���������� ��� ����.�����.
			int sum = 0;//���������� ��� �����
			for (int i = 0; i < SIZE; i++)
			{
				sum += arr[i];//���������� ����� ���� ���������
			}
			aver = (float)sum / SIZE;//���������� ����.�����. ���� ���������
			float minG = 10.7f;//min ����.���
			cout << endl;
			if (aver - minG >= 0)//��������� ������� ������ �� ���������
			{//���� ��,��:
				cout << "Student went on a scholarship, because average grade " << aver << endl;//�������,��� ������� ����� �� ���������
			}
			else
			{//�����
				cout << "Student did not enter a scholarship, because average grade " << aver << endl;//�������,��� ������� �� ����� �� ���������
			}
			cout << endl;
			cout << "Sort grades:\n";//���������� ������
			cout << "Select sort type: 1 - ascending, 2 - descending\n";//������ ������� ����� ����������
			int sel = 0;//���������� ��� ������
			cin >> sel; //���� ������
			if (sel == 1) //��������� ������ �� �����������
			{//���� ��,��:
				cout << "Ascending:\n";//�� �����������
				bubbleSort1(arr, SIZE);//����� ��-�� ����������� ���������� 
				cout << endl;
				showArr(arr, SIZE);//����� ��-�� ������ �������
				cout << endl;
			}
			else if (sel == 2) //��������� ������ �� ��������
			{//���� ��,��:
				cout << "Descending:\n";//�� ��������
				bubbleSort(arr, SIZE);//����� ��-�� ����������� ���������� 
				cout << endl;
				showArr(arr, SIZE);//����� ��-�� ������ �������
				cout << endl;
			}
			else
			{//�����
				cout << "Error! Of such type not found!\n "  << endl;//�������,��� ������ ���� ���
			}
		}//����� ����� case '4'
		break;

		default:
			cout << "Error!Function not found\n";
			cout << endl;
			break;
		}
		system("pause");//��������
	}//����� ����� while
	cout << endl;
	cout << "Thanks for Your attention, goodbay\n";
	cout << endl;
}//����� ����� main

template<typename T> // ������ ��-�� ���������� �����
T retRand(T min, T max, int order)
{
	return ((T)(rand() % (((int)max - (int)min)*order) + min*order) / order);//���������� ��������� ����� � ��������� �� min �� max
}//����� ��-�� retRand

template<typename T> // ������ ��-�� ���������� �������
void fillArr(T arr[], const int SIZE, const T min, const T max, const int order)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = retRand(min, max, order);//���������� ������� ���������� �������
	}
}//����� ��-�� fillArr

template<typename T> // ������ ��-�� ���������� ����� ������� �������
T retRand1(T minim, T maxim, int ord)
{
	return ((T)(rand() % (((int)maxim - (int)minim)*ord + 1) + minim*ord) / ord);//���������� ��������� ����� � ��������� �� min �� max
}//����� ��-�� retRand1

template<typename T> // ������ ��-�� ���������� ������� ������� �������
void fillArr1(T arr[], const int SIZE, const T minim, const T maxim, const int ord)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = retRand1(minim, maxim, ord);//���������� ������� ���������� �������
	}
}//����� ��-�� fillArr1

template<typename T> // ������ ��-�� ������ �������
void showArr(const T arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ' ';//����� ������� 
	}
	cout << endl;
}//����� ��-�� showArr

template<typename T>
void bubbleSort(T arr[], const int SIZE, int min)//�������� ������� ��-�� ����������� ����������  �� ��������
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
}//����� ��-�� bubbleSort

template<typename T>
void selectSort(T arr[], const int SIZE, int min)//�������� ������� ��-�� ���������� ������� �� �����������
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
}//����� ��-�� selectSort

template<typename T>
void insertSort(T arr[], const int SIZE, int min)//�������� ������� ��-�� ���������� ��������� �� ��������
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
}//����� ��-�� insertSort

template<typename T>
void bubbleSort1(T arr[], const int SIZE, int min)//�������� ������� ��-�� ����������� ���������� �� �����������
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
}//����� ��-�� bubbleSort1
