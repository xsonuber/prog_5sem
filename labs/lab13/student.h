#pragma once
#include "human.h"
#include <string>
#include <vector>
using namespace std;

class student : public human
{
private:
	vector<int> scores;
public:
	void get_data()
	{
		human::get_data();
		string check = "y";
		cout << "Input score? (y/n)";
		cin >> check;
		while (check == "y")
		{
			int score = 0;
			cout << "Score: ";
			cin >> score;
			scores.push_back(score);
			cout << "Input score? (y/n)";
			cin >> check;
		}
	}

	float avrg_score()
	{
		double sum = 0;
		double count = scores.size();
		double avrg;
		for (int i = 0; i < count; i++) sum += scores[i];
		avrg = sum / count;

		return avrg;
	}

	void show_data()
	{
		human::show_data();
		cout << "Average score: " << this->avrg_score() << endl;
	}
};

