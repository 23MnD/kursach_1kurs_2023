#pragma once
#if defined(max)
#undef max
#endif
#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
using namespace std;
struct Chel
{
	string name="";
	string surName="";
	string familyName="";
	 char sex[1];
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
	int record_book_number; //номер зачётной книжки
};
struct Exam {
	string nameExam;
	int mark;
};


class Student
{
private:
	Chel chel;
	Date data;
	University univer;
	Exam exam_marks[9][10]; //9 - семестров и 10 - предметов


public:
	Student()
	{
		chel.name = "default";
		chel.surName = "default";
		chel.familyName= "default";
		*chel.sex=*"d";
		data.birthday = 1;
		data.birthmonth = 1;
		data.birthyear = 2000;       
		univer.department = "default";;
		univer.faculty = "default";;
		univer.group= "default";
		univer.record_book_number=12345;
		for (size_t j = 0; j < 9; j++)
		{
			for (size_t k = 0; k < 10; k++)
			{
				exam_marks[j][k].nameExam = "bebra";
				exam_marks[j][k].mark = -1;
			}
		}
	}
	bool setChel_Name(string name);
	
	bool setChel_surName(string surName); 
	
	bool setChel_familyName(string familyName);
	
	bool setChel_sex(char sex);
	
	string getChel_name();

	string getChel_surName();

	string getChel_familyName();

	string getChel_sex();


	bool setDate_day(unsigned short birthday);
	
	bool setDate_month(unsigned short birthmonth);

	void setDate_year(unsigned short birthyear);

	unsigned short getDate_day();

	unsigned short getDate_month();
	
	unsigned short getDate_year();
	
	void setUniversity_faculty(string faculty);
	
	void setUniversity_department(string department);

	void setUniversity_group(string group);

	void setUniversity_record_book_number(int record_book_number);

	string getUniversity_faculty();

	string getUniversity_department();

	string getUniversity_group();

	int getUniversity_record_book_number();

	void setMark(int semestr, int pos, int mark);

	int getMark(int semestr, int pos);

	bool setNameSubject(int semestr, int pos, string name);
	
	string getNameSubject(int semestr, int pos);

	void printDate();
	
	






	

};

