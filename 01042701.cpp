//������� ���� ��������, ���� ���������� ���, ������� � ������� ��� ��������.������� �����(������) �������� � ������� ���
//������ �������� � ��������� �����.� ������� ������� ������� �� ����� ��� ���������� ��������.������� std::max_element()
//������ ��������� ������� � ���� ���������� ��� ������, � �������� �� ������� ��� ������ � ����� �����������, ��� �������
//������, ���� ������ �������� ������ �� �������.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
protected:
	string firstName;
	string lastName;
	int gpa;
public:
	Student(string last, string first, int _gpa) : lastName(last), firstName(first)
	{
		if (_gpa > 100 || _gpa < 1)
		{
			cout << "����������� ������� ��� ��������!" << endl;
			cout << "�������� ������� ���� � ����� �� 1 �� 100!" << endl;
			cout << "����������� ��������� �������� �� ������������: 70" << endl;
			cout << endl;
			gpa = 70;
		}
		else gpa = _gpa;
	}
	void printStudent()
	{
		cout << "��'� ��������: " << lastName << " " << firstName << endl;
		cout << "������� ���: " << gpa << endl;
	}
	int getGPA()  { return gpa; }
	bool operator<(const Student& other) const
	{
		return gpa < other.gpa;
	}
};

int main()
{
	system("chcp 1251 > null");

	vector<Student> students;
	students.reserve(6);

	Student vasa("Vasanovich", "Vasa", 87);
	Student anton("Lukimov", "Anatoly", 79);
	Student igor("Kvasov", "Igor", 91);
	Student diana("Butusova", "Diana", 88);

	students.push_back(vasa);
	students.push_back(anton);
	students.push_back(igor);
	students.push_back(diana);

	auto maxGpa = max_element(students.begin(), students.end(),
		[]( Student& a,  Student& b) 
		{
			return a.getGPA() < b.getGPA();
		});

	cout << "����������� ������ � ��������: " << endl; ;

	maxGpa->printStudent();

	//vasa.printStudent();
	//anton.printStudent();

	return 0;
}