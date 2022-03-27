#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialty { ��, ��, ��, ��, �� };

string strSpecialty[] = { "��","��","��","��","��" };

struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physics;
	short unsigned math;
	short unsigned informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double MinMediumMark(Student* s, const int N);
int CountFour(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ ������� ��������: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);

	cout << "| ʳ������ ������ [�����] � ������� ��������" << char(34) << ": " << fixed << setw(6) << setprecision(2) << CountFour(s, N) << setw(23) << " | " << endl;
	cout << "| ��������� ������� ���: " << fixed << setprecision(2) << MinMediumMark(s, N) << setw(29) << "   |" << endl;
	cout << "================================================================================" << endl;
	delete[] s;
}

void Create(Student* s, const int N)
{
	int kurs, specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "������� " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  �������: "; getline(cin, s[i].prizv);
		cout << "  ����: "; cin >> s[i].kurs;
		cout << "  ������������ (0 - ��, 1 - ��, 2 - ��, 3 - ��, 4 - ��): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  ������ � ������: "; cin >> s[i].physics;
		cout << "  ������ � ����������: "; cin >> s[i].math;
		cout << "  ������ � �����������: "; cin >> s[i].informatics;
	}
}

void Print(Student* s, const int N)
{
	cout << "================================================================================"
		<< endl;
	cout << "| �  | �������     | ���� | ������������ | Գ���� | ���������� | ����������� |"
		<< endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "      "
			<< "| " << setw(6) << right << s[i].informatics << "     |" << endl;
	}
	cout << "================================================================================" << endl;
}

double MinMediumMark (Student* s, const int N) 
{
	double m = (s[0].physics + s[0].math + s[0].informatics) / 3;
	for (int i = 0; i < N; i++)
	{
		if ((s[i].physics + s[i].math + s[i].informatics) / 3 < m)
			m = (s[i].physics + s[i].math + s[i].informatics) / 3;
	}
	return m;	
}


int CountFour(Student* s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 4)
			k++;
		if (s[i].math == 4)
			k++;
		if (s[i].informatics == 4)
			k++;
	}
	return k;
}
