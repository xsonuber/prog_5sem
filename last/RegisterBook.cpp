#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;
class Person
{
public:
    string generate_id()
    {
        string result = "";
        for (int i = 0; i < 6; i++)
        {
            result += to_string(rand() % 10);
        }
        return result;
    }
    virtual void show_info() = 0;
    virtual double count_wage() = 0;
    virtual void get_person() = 0;
    virtual string str_info() = 0;
};

class Teacher : public Person
{
private:
    string last_name;
    string first_name;
    string second_name;
    int work_hours;
    string id;
    string subject;

public:
    Teacher()
    {
        last_name = "None";
        first_name = "None";
        second_name = "None";
        work_hours = 0;
        id = "None";
        subject = "None";
    }
    Teacher(string ln, string fn, string sn, int wh, string sj)
    {
        last_name = ln;
        first_name = fn;
        second_name = sn;
        work_hours = wh;
        id = generate_id();
        subject = sj;
    }
    void get_person() override
    {
        id = generate_id();
        cout << "\nInput FIO: ";
        cin >> last_name; cin >> first_name; cin >> second_name;
        cout << "\nInput the amount of work hours: ";
        cin >> work_hours;
        cout << "\nInput subject: ";
        cin >> subject;
    }
    double count_wage() override
    {
        return work_hours * 1.35;
    }
    void show_info() override
    {
        cout << "\nInfo:\nFIO: " << last_name << " " << first_name << " " << second_name;
        cout << "\nID: " << id;
        cout << "\nSubject: " << subject;
        cout << "\nWage: " << count_wage() << endl;
    }
    string str_info() override
    {
        return "\nInfo:\nFIO: " + last_name + " " + first_name + " " + second_name + "\nID: " + id + "\nSubject: " + subject + "\nWage: " + to_string(count_wage()) + "\n";
    }
};

class Student : public Person
{
private:
    string last_name;
    string first_name;
    string second_name;
    int study_hours;
    string id;
    double mean_grade;

public:
    Student()
    {
        last_name = "None";
        first_name = "None";
        second_name = "None";
        study_hours = 0;
        id = "None";
        mean_grade = 0;
    }
    Student(string ln, string fn, string sn, int sh, double mg)
    {
        last_name = ln;
        first_name = fn;
        second_name = sn;
        study_hours = sh;
        id = generate_id();
        mean_grade = mg;
    }
    void get_person() override
    {
        cout << "\nInput FIO: ";
        cin >> last_name; cin >> first_name; cin >> second_name;
        cout << "\nInput the amount of study hours: ";
        cin >> study_hours;
        cout << "\nInput mean grade: ";
        cin >> mean_grade;
        id = generate_id();
    }

    double count_wage() override
    {
        if (mean_grade >= 4) return study_hours * 0.72;
        else return 0;
    }
    void show_info() override
    {
        cout << "\nInfo:\nFIO: " << last_name << " " << first_name << " " << second_name;
        cout << "\nID: " << id;
        cout << "\nMean grade: " << mean_grade;
        cout << "\nLoan: " << count_wage() << endl;
    }
    string str_info() override
    {
        return "\nInfo:\nFIO: " + last_name + " " + first_name + " " + second_name + "\nID: " + id + "\nMean grade: " + to_string(mean_grade) + "\nLoan: " + to_string(count_wage()) + "\n";
    }
};

class Rector : public Person
{
private:
    string last_name;
    string first_name;
    string second_name;
    int work_hours;
    string id;
public:
    Rector()
    {
        last_name = "None";
        first_name = "None";
        second_name = "None";
        work_hours = 0;
        id = "None";
    }
    Rector(string ln, string fn, string sn, int wh)
    {
        last_name = ln;
        first_name = fn;
        second_name = sn;
        work_hours = wh;
        id = generate_id();
    }
    void get_person() override
    {
        cout << "\nInput info about the rector of the University: ";
        id = generate_id();
        cout << "\nInput FIO: ";
        cin >> last_name; cin >> first_name; cin >> second_name;
        cout << "\nInput the amount of work hours: ";
        cin >> work_hours;
    }

    double count_wage() override
    {
        return work_hours * 3.17;
    }
    void show_info() override
    {
        cout << "\nInfo:\nFIO: " << last_name << " " << first_name << " " << second_name;
        cout << "\nID: " << id;
        cout << "\nWage: " << count_wage() << endl;
    }
    string str_info() override
    {
        return "\nInfo:\nFIO: " + last_name + " " + first_name + " " + second_name + "\nID: " + id + "\nWage: " + to_string(count_wage()) + "\n";
    }
};

class University
{
private:
    list <Student> students = {};
    list <Teacher> teachers = {};
    string name;
    Rector rector;
public:
    University()
    {
        name = "None";
        rector = Rector();
    }
    University(string n, string ln, string fn, string sn, int wh)
    {
        name = n;
        rector = Rector(ln, fn, sn, wh);
    }
    void get_university()
    {
        cout << "\nInput the name of the University: ";
        cin >> name;
        rector.get_person();
    }
    void addTeacher(Teacher t)
    {
        teachers.push_back(t);
    }
    void addStudent(Student s)
    {
        students.push_back(s);
    }
    void show_rector()
    {
        cout << "\nRector of " << name;
        rector.show_info();
    }
    void show_teachers()
    {
        cout << "\nTeachers of " << name;
        for (list<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++) {
            it->show_info();
        }
    }
    void show_students()
    {
        cout << "\nStudents of " << name;
        for (list<Student>::iterator it = students.begin(); it != students.end(); it++) {
            it->show_info();
        }
    }
    void show_people()
    {
        show_rector();
        show_teachers();
        show_students();
    }

    int export_uni()
    {
        ofstream out("University.txt", ios::out | ios::binary);
        if (!out) {
            cout << "Impossible to open file\n";
            return 1;
        }

        out << "Name of the University: " << name;
        out << "\nRector of " << name << ": " << rector.str_info();

        out << "\nTeachers of " << name;
        for (list<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++) {
            out << it->str_info();
        }

        out << "\nStudents of " << name;
        for (list<Student>::iterator it = students.begin(); it != students.end(); it++) {
            out << it->str_info();
        }

        out.close();
    }
};

int main()
{
    Teacher teacher01;
    teacher01.get_person();
    Student student01;
    student01.get_person();
    cout << "\nInput info about the University: \n";
    University uni;
    uni.get_university();

    Teacher teacher02("a", "a", "a", 10, "Math");
    Teacher teacher03("b", "b", "b", 20, "English");
    Teacher teacher04("c", "c", "c", 30, "OBJ");

    Student student02("a", "a", "a", 40, 3.45);
    Student student03("b", "b", "b", 50, 2.87);
    Student student04("c", "c", "c", 60, 4.24);

    uni.addStudent(student01);
    uni.addStudent(student02);
    uni.addStudent(student03);
    uni.addStudent(student04);

    uni.addTeacher(teacher01);
    uni.addTeacher(teacher02);
    uni.addTeacher(teacher03);
    uni.addTeacher(teacher04);
    uni.show_people();

    uni.export_uni();
}