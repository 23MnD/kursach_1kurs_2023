#include "Studetnt.h"

void Student::setChel_Name(string name)
{
	string digits = "0123456789";
	for (int i=0; i < (int)size(name); i++)
	{
		for (int j=0; j < (int)size(digits); j++)
		{
			if (!(name[i] == digits[j]))
			{
				chel->name = name;
			}
			else
			{
				cout << "Не правильный ввод имени";
			}
		}
	}
}
void Student::setChel_surName(string surName)
{
	string digits = "0123456789";
	for (int i=0; i < (int)size(surName); i++)
	{
		for (int j=0; j < (int)size(digits); j++)
		{
			if (!(surName[i] == digits[j]))
			{
				chel->surName = surName;
			}
			else
			{
				cout << "Не правильный ввод отчества";
			}
		}
	}
}
void Student::setChel_familyName(string familyName)
{
	string digits = "0123456789";
	for (int i=0; i < (int)size(familyName); i++)
	{
		for (int j=0; j < (int)size(digits); j++)
		{
			if (!(familyName[i] == digits[j]))
			{
				chel->familyName = familyName;
			}
			else
			{
				cout << "Не правильный ввод фамилии";
			}
		}
	}
}
void Student::setChel_sex(string sex)
{
	if (!(sex == "М" || sex == "Ж"))
	{
		cout << "Пол введен неверно";
	}
	else
	{
		chel->sex = sex;
	}
}
string Student::getChel_name()
{
	return chel->name;
}
string Student::getChel_surName()
{
	return chel->surName;
}

string Student::getChel_familyName()
{
	return chel->familyName;
}
string Student::getChel_sex()
{
	return chel->sex;
}

void Student::setDate_day(unsigned short birthday)
{
	if (birthday > 31 && birthday < 1)
	{
		cout << "День рождения введен неверно";
	}
	else
	{
		data->birthday = birthday;
	}
}
void Student::setDate_month(unsigned short birthmonth)
{
	if (birthmonth > 12 && birthmonth < 1)
	{
		cout << "Месяц рождения введён неверно";
	}
	else
	{
		data->birthmonth = birthmonth;
	}
}
void Student::setDate_year(unsigned short birthyear)
{
	data->birthyear = birthyear;
}
unsigned short Student::getDate_day()
{
	return data->birthday;
}
unsigned short Student::getDate_month()
{
	return data->birthmonth;
}
unsigned short Student::getDate_year()
{
	return data->birthyear;
}
void Student::setUniversity_faculty(string faculty)
{
	univer->faculty = faculty;
	
}
void Student::setUniversity_department(string department)
{
	univer->department = department;
}
void Student::setUniversity_group(string group)
{
	univer->group = group;
}
void Student::setUniversity_record_book_number(string record_book_number)
{
	univer->record_book_number = record_book_number;
}
string Student::getUniversity_faculty()
{
	return univer->faculty;
}
string Student::getUniversity_department()
{
	return univer->department;
}
string Student::getUniversity_group()
{
	return univer->group;
}
string Student::getUniversity_record_book_number()
{
	return univer->record_book_number;
}
void Student::setMark(int semestr, int pos, int mark)
{
	if (mark >= 2 && mark <= 5)
	{
		exam_marks[semestr][pos].mark = mark; 
	}
}

int Student:: getMark(int semestr, int number_mark)
{
	return exam_marks[semestr][number_mark].mark;
}
void Student::setNameSubject(int semestr, int number_mark, string name)
{
	string digits = "0123456789";
	for (int i = 0; i < (int)size(name); i++)
	{
		for (int j = 0; j < (int)size(digits); j++)
		{
			if (!(name[i] == digits[j]))
			{
				exam_marks[semestr][number_mark].nameExam = name;
			}
			else
			{
				cout << "Не правильный ввод предмета";
			}
		}
	}
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
	if (this->data->birthday > 9) {
		std::cout << this->data->birthday;
	}
	else {
			cout << "0" << this->data->birthday;
	}
	cout << ".";
	if (this->data->birthmonth > 9) {
		cout << this->data->birthmonth;
	}
	else {
		cout << "0" << this->data->birthmonth;
	}
	cout << ".";
	cout << this->data->birthyear;
	cout.width(delta); cout << " ";
}