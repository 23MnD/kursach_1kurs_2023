#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
using namespace std;
struct Chel
{
	string name;
	string surName;
	string familyName;
	string sex;
};
struct Date
{
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
};
struct University
{
	string faculty;
	string department; //кафедра
	string group;
	string record_book_number; //номер зачётной книжки
};
struct Exam {
	string nameExam;
	int mark;
};


class Student
{
private:
	Chel* chel;
	Date* data;
	University* univer;
	Exam exam_marks[9][10]; //9 - семестров и 10 - предметов
	List<string> lst;

public:
	void setChel_Name(string name);
	
	void setChel_surName(string surName);
	
	void setChel_familyName(string familyName);
	
	void setChel_sex(string sex);
	
	string getChel_name();

	string getChel_surName();

	string getChel_familyName();

	string getChel_sex();


	void setDate_day(unsigned short birthday);
	
	void setDate_month(unsigned short birthmonth);

	void setDate_year(unsigned short birthyear);

	unsigned short getDate_day();

	unsigned short getDate_month();
	
	unsigned short getDate_year();
	
	void setUniversity_faculty(string faculty);
	
	void setUniversity_department(string department);

	void setUniversity_group(string group);

	void setUniversity_record_book_number(string record_book_number);

	string getUniversity_faculty();

	string getUniversity_department();

	string getUniversity_group();

	string getUniversity_record_book_number();

	void setMark(int semestr, int pos, int mark);

	int getMark(int semestr, int pos);

	void setNameSubject(int semestr, int pos, string name);
	
	string getNameSubject(int semestr, int pos);

	
	void printDate();
	







	

};

