#include <iostream>
#include <ctime>

using namespace std;

class UK1
{
	int size;
	int* ukaz = new int[size];

public:
	UK1(int &size)
	{
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			*ukaz = rand() % 10;
			cout << *ukaz << '\t'; //������� ��� �������� �������
		}
	}
	~UK1()
	{
		delete[]ukaz;//������� ������
		ukaz = nullptr;//������� �������� ���������
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size;
	cin >> size;

	UK1 uk1(size);

	/*
	int* ukaz = new int[size];
	for (int i = 0; i < size; i++)
	{
		*ukaz = rand() % 10;
		cout << *ukaz << '\t'; //������� ��� �������� �������
	}
	*/
	

	//cout << endl << *ukaz << '\t';//������� ������ ��������� �������
	cout << endl;
	cout << endl;
	cout << endl;

	int** uk2 = new int* [size];//������ ���. ������ ����������
	for (int i = 0; i < size; i++)
	{
		uk2[i] = new int[size];//������� ��������� ������������� ���. ������
	}
	for (int i = 0; i < size; i++)//������ �������� ���. ��������
	{
		for (int j = 0; j < size; j++)
		{
			**uk2 = rand() % 10;
			cout << **uk2 << '\t';
		}
		cout << endl;
	}

	/*
	int* uk3 = &size;
	*uk3 = size - 1;
	cout << "\n" << *uk3;
	*uk3 = size + 1;
	*/

	/*
	int& ss = size;
	ss = ss - 1;
	cout << "\n" << ss;
	ss = size + 1;
	*/

	//delete[]ukaz;//������� ������
	//ukaz = nullptr;//������� �������� ���������

	for (int i = 0; i < size; i++)
	{
		delete[]uk2[size];//������� ���. �������
	}
	delete[]uk2;//������� ���. ������ ����������
	uk2 = nullptr;
}