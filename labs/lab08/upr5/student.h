#pragma once /* ������ �� �������� ����������� ������������� ����� */
#include <string>
#include <fstream>
using namespace std;
class Student {
public:
	// ������ ������ � �������� � ����
	void save();
	// ���������� ������ Student
	~Student();
	// ����������� ������ Student
	Student(string, string);
	// ��������� ����� ��������
	void set_name(string);
	// ��������� ����� ��������
	string get_name();
	// ��������� ������� ��������
	void set_last_name(string);
	// ��������� ������� ��������
	string get_last_name();
	// ��������� ������������� ������
	void set_scores(int[]);
	// ��������� �������� �����
	void set_average_score(double);
	// ��������� �������� �����
	double get_average_score();
private:
	// ������������� ������
	int scores[5];
	// ������� ����
	double average_score;
	// ���
	string name;
	// �������
	string last_name;
};