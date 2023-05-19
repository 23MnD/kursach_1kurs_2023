#include "Studetnt.h"

bool Student::setChel_Name(string name)
{
	
	for (int i=0; i < (int)size(name); i++)
	{
		if (name[i] >= '0' && name[i] <= '9')
		{
			return false;
		}

	}
	chel.name = name;
	return true;
}
bool Student::setChel_surName(string surName)
{
	
	for (int i=0; i < (int)size(surName); i++)
	{
		if (surName[i] >= '0' && surName[i] <= '9')
		{
			return false;
		}

	}
	chel.surName = surName;
	return true;
		
}
bool Student::setChel_familyName(string familyName)
{
	
	
	for (int i=0; i < (int)size(familyName); i++)
	{
		if (familyName[i] >= '0' && familyName[i] <= '9')
		{
			return false;
		}
		
	}
	chel.familyName = familyName;
	return true;
}
bool Student::setChel_sex(char sex)
{
	if (sex != 'Ì' && sex != 'Æ')
	{
		return false;
	}
	chel.sex = sex;
	return true;
}
string Student::getChel_name()
{
	return chel.name;
}
string Student::getChel_surName()
{
	return chel.surName;
}

string Student::getChel_familyName()
{
	return chel.familyName;
}
char Student::getChel_sex()
{
	return chel.sex;
}

bool Student::setDate_day(unsigned short birthday)
{
	if (birthday <= 31 && birthday >= 1)
	{
		
		data.birthday = birthday;
		return true;
	}
	else
	{
		return false;
	}
}
bool Student::setDate_month(unsigned short birthmonth)
{
	if (birthmonth <= 12 && birthmonth >= 1)
	{
		data.birthmonth = birthmonth;
		return true;
	}
	else
	{
		return false;
	}
}
void Student::setDate_year(unsigned short birthyear)
{
	data.birthyear = birthyear;
}
unsigned short Student::getDate_day()
{
	return data.birthday;
}
unsigned short Student::getDate_month()
{
	return data.birthmonth;
}
unsigned short Student::getDate_year()
{
	return data.birthyear;
}
void Student::setUniversity_faculty(string faculty)
{
	univer.faculty = faculty;
	
}
void Student::setUniversity_department(string department)
{
	univer.department = department;
}
void Student::setUniversity_group(string group)
{
	univer.group = group;
}
void Student::setUniversity_record_book_number(int record_book_number)
{
	univer.record_book_number = record_book_number;
}
string Student::getUniversity_faculty()
{
	return univer.faculty;
}
string Student::getUniversity_department()
{
	return univer.department;
}
string Student::getUniversity_group()
{
	return univer.group;
}
int Student::getUniversity_record_book_number()
{
	return univer.record_book_number;
}
void Student::setMark(int semestr, int pos, int mark)
{
	
	
		exam_marks[semestr][pos].mark = mark; 
	
}

int Student:: getMark(int semestr, int number_mark)
{
	return exam_marks[semestr][number_mark].mark;
}
bool Student::setNameSubject(int semestr, int number_mark, string name)
{
	for (int i = 0; i < (int)size(name); i++)
	{
		if (name[i] >= '0' && name[i] <= '9')
		{
			return false;
		}
	}
	exam_marks[semestr][number_mark].nameExam = name;
	return true;
}
string Student::getNameSubject(int semestr, int number_mark)
{
	return exam_marks[semestr][number_mark].nameExam;
}

void Student::printDate() {
	int wLine = 15;
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout.width(delta); std::cout << " ";
	if (data.birthday > 9) {
		std::cout << data.birthday;
	}
	else {
			cout << "0" << data.birthday;
	}
	cout << ".";
	if (data.birthmonth > 9) {
		cout << data.birthmonth;
	}
	else {
		cout << "0" << data.birthmonth;
	}
	cout << ".";
	cout << data.birthyear;
	cout.width(delta); cout << " " << endl;
}
