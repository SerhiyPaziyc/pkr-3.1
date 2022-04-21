#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec {
	COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS,
	PHYSICS_INFORMATICS, WORK_TRAINING
};

string specStr[] = { "Комп\'ютерні науки", "Інформатика",
"Математика та економіка", "Фізика та інформатика","Трудове навчання" };

struct Student
{
	string secondname;
	unsigned kurs;
	Spec spec;
	int physics;
	int math;
	union
	{
		int prog;
		int nummeth;
		int pedag;
	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Num(Student* s, const int N);
double LineSearch(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;

	cout << "Введіть N = "; cin >> N;

	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);
	Num(s, N);

	cout << "Процент студентів які вчаться на (відмінно): "
		<< LineSearch(s, N) << "%" << endl;

	system("pause");
	return 0;
}

void Create(Student* s, const int N)
{
	int spec;

	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "\tпрізвище: "; getline(cin, s[i].secondname);
		cout << "\tКурс: "; cin >> s[i].kurs;
		cout << "\tСпеціальність:\n [0]Комп\'ютерні науки\n [1]Інформатика\n"
			<< "[2]Математика та економіка\n [3]Фізика та інформатика\n"
			<< "[4]Трудове навчання\n Твій вибір: "; cin >> spec;

		s[i].spec = (Spec)spec;

		switch (s[i].spec)
		{
		case COMPUTER_SCIENCE:
			cout << "\tОцінка з фізики: "; cin >> s[i].physics;
			cout << "\tОцінка з математики: "; cin >> s[i].math;
			cout << "\tОцінка з програмування: "; cin >> s[i].prog;
			break;
		case INFORMATICS:
			cout << "\tОцінка з фізики: "; cin >> s[i].physics;
			cout << "\tОцінка з математики: "; cin >> s[i].math;
			cout << "\tОцінка з чисельних методів: "; cin >> s[i].nummeth;
			break;
		case MATH_ECONOMICS:
		case PHYSICS_INFORMATICS:
		case WORK_TRAINING:
			cout << "\tОцінка з фізики: "; cin >> s[i].physics;
			cout << "\tОцінка з математики: "; cin >> s[i].math;
			cout << "\tОцінка з педагогіки: "; cin >> s[i].pedag;
			break;
		}
		cout << endl;
	}
}

void Print(Student* s, const int N)
{
	cout << "============================================================================================================================"
		<< endl;
	cout << "| № |   Прізвище   | Курс |      Спеціальність      | Фізика | Математика | Програмування | Чисельних методів | Педагогіки |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(12) << left << s[i].secondname << " "
			<< "|   " << setw(1) << right << s[i].kurs << "  "
			<< "| " << setw(23) << left << specStr[s[i].spec] << " "
			<< "|    " << setw(1) << right << s[i].physics << "   "
			<< "|      " << setw(1) << left << s[i].math << "     ";

		switch (s[i].spec)
		{
		case COMPUTER_SCIENCE:
			cout << "|       " << setw(1) << right << s[i].prog << "       |"
				<< setw(20) << right << "|" << setw(13) << right << "|" << endl;
			break;
		case INFORMATICS:
			cout << "|" << setw(26) << right << "|          "
				<< setw(1) << left << s[i].nummeth << "        |" << setw(13) << right << "|" << endl;
			break;
		case MATH_ECONOMICS:
		case PHYSICS_INFORMATICS:
		case WORK_TRAINING:
			cout << "| " << setw(15) << right << "|"
				<< setw(26) << right << "|      " << setw(1) << right << s[i].pedag << "     |" << endl;
			break;
		}
	}
	cout << "----------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	cout << endl;
}

void Num(Student* s, const int N)
{
	int k[1]{ 0 };

	for (int i = 0; i < N; i++)
	{
		if (s[i].physics == 5)
		{
			cout << "Студенти які отримали 5 з Фізики: " << s[i].secondname << endl;
		}
	}
}

double LineSearch(Student* s, const int N)
{
	double k = 0.0, n = N;

	for (int i = 0; i < N; i++)
	{
		if (s[i].math == 5 && s[i].physics == 5 && s[i].prog && s[i].nummeth && s[i].pedag)
		{
			k++;
		}
	}

	return 100.0 * k / n;
}