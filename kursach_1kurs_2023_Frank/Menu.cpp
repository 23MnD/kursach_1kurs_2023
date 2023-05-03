#pragma once
#include "Menu.h"
int choice;
void Menu:: MainMenu()
{
	List<Student> student;
	cout << "Меню\n"
		<< "(0) Добавить студента.\n"
		<< "(1) Изменить данные студента.\n"
		<< "(2) Удалить студента.\n"
		<< "(3) Вывести всех студентов.\n"
		<< "(4) Выход.";
	cin >> choice;
	while(true)
	{ 
		switch (choice)
		{
		case 0:
			EntryInformation();
			break;
		case 1:
			ChangeInformation();
			break;
		case 2:
			DeleteInformation();
			break;
		case 3:
			printStudent(student);
			break;
			
		case 4:
			break;
		
		}
		break;
	
	}
}
int Menu:: EntryInformation()
{
	Student student;
	string name,
		surName, 
		Familyname, 
		sex, 
		faculty,
		department,//кафедра
		group,
		record_book_number;//номер зачётной книжки
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
	 List<Student>  studentlst;

	while(true)
	{
		cout << "Введите Фамилию/Имя/Отчество: ";
		cin >> Familyname >> name >> surName;
		student.setChel_familyName(Familyname); student.setChel_Name(name); student.setChel_surName(surName);
		
		cout << "Введите пол студента (М-мужской или Ж-женский): ";
		cin >> sex;
		student.setChel_sex(sex);
		cout << "Ввидете дату роджения студента: ";
		cin >> birthday >> birthmonth >> birthyear;
		student.setDate_day(birthday);  student.setDate_month(birthmonth); student.setDate_year(birthyear);
		cout << "Введите факультет: ";
		cin >> faculty;
		student.setUniversity_faculty(faculty);
		cout << "Введите кафедру: ";
		cin >> department;
		student.setUniversity_department(department);
		cout << "Введите номер зачетной кижки(в формате 12А4567): ";
		cin >> record_book_number;
		student.setUniversity_record_book_number(record_book_number);
		cout << "Ввидете группу студента: ";
		cin >> group;
		student.setUniversity_group(group);
		studentlst.push_front(student);
		
	}
	WriteToFile(studentlst);
	
}

void Menu::ChangeInformation()
{
	int index;
	List<Student>  studentlst;
	List<int> sizelst;//кол-чо студентво
	Student student;
	string Newname,
		NewSurName,
		NewFamilyname,
		Newsex,
		Newfaculty,
		Newdepartment,//кафедра
		Newgroup,
		Newrecord_book_number;//номер зачётной книжки
	unsigned short Newbirthday;
	unsigned short Newbirthmonth;
	unsigned short Newbirthyear;
	cout << "Введите номер студента, которого хотите удалить: ";
	cin >> index;
	cout << "(0) Изменить Имя студента \n"
		<< "(1) Изменить Фамилию студента \n"
		<< "(2) Изменить Отчество студента \n"
		<< "(3) Изменить Пол студента \n"
		<< "(4) Изменить День рождения студента \n"
		<< "(5) Изменить Месяц рождения студента \n"
		<< "(6) Изменить Год рождения студента \n"
		<< "(7) Изменить Факультет студента \n"
		<< "(8) Изменить Кафедру студента \n"
		<< "(9) Изменить Номер зачётной книжки  студента \n"
		<< "(10) Изменить Группу студента \n";
	for (int i = 0; i < sizelst.getsizeList(); i++)
	{
		if (i == index) 
		{
			cout << "Введите цифру для того, чтобы изменить в студенте что-то из параметров: ";
			cin >> choice;
			switch (choice)
			{
			case 0:
				cout << "Введите новое Имя студента: ";
				cin >> Newname;
				student.setChel_Name(Newname);
			
				break;
			case 1:
				cout << "Введите новую Фамилию студента: ";
				cin >> NewFamilyname;
				student.setChel_familyName(NewFamilyname);
				break;
			case 2:
				cout << "Введите новое Отчество студента: ";
				cin >> NewSurName;
				student.setChel_surName(NewSurName);
				break;
			case 3:
				cout << "Введите новый Пол студента: ";
				cin >> Newsex;
				student.setChel_sex(Newsex);
				break;
			case 4:
				cout << "Введите новый День рождения студента: ";
				cin >> Newbirthday;
				student.setDate_day(Newbirthday);
				break;
			case 5:
				cout << "Введите новый Месяц рождения студента: ";
				cin >> Newbirthmonth;
				student.setDate_month(Newbirthmonth);
				break;
			case 6:
				cout << "Введите новый Год рождения студента: ";
				cin >> Newbirthyear;
				student.setDate_year(Newbirthyear);
				break;
			case 7:
				cout << "Введите новый Факультет студента: ";
				cin >> Newfaculty;
				student.setUniversity_faculty(Newfaculty);
				break;
			case 8:
				cout << "Введите новую Кафедру студента: ";
				cin >> Newdepartment;
				student.setUniversity_department(Newdepartment);
				break;
			case 9:
				cout << "Введите новый Номер зачётной книжки студента: ";
				cin >> Newrecord_book_number;
				student.setUniversity_record_book_number(Newrecord_book_number);
				break;
			case 10:
				cout << "Введите новую Группу студента: ";
				cin >> Newgroup;
				student.setUniversity_group(Newgroup);
				break;
			}
		}
	}
	WriteToFile(studentlst);


}

void Menu::DeleteInformation()
{
	cout << "Введите номер студента, которого хотите удалить: ";
	int index;
	List<Student>  studentlst;
	List<int> sizelst;//кол-чо студентво
	cin >> index;
	for (int i = 0; i < sizelst.getsizeList(); i++)
	{
		if (i == index)
		{
			studentlst.remove(index);
		}
	}
	WriteToFile(studentlst);

}

void Menu::printStudent(List<Student>& student)
{
	for (int i = 0; i < student.getsizeList(); i++)
	{
		cout << student[i].getChel_name() << " " << student[i].getChel_surName() << " " << student[i].getChel_familyName() << " " << student[i].getUniversity_group() << endl;
	}
}

void Menu::AddExamStudent()
{
	Student subject_student;
	string name_subject;
	int semestr, number_mark, mark;

	while (true)
	{
		cout << "Введите семестр ";
		cin >> semestr;
		cout << "Введите номер оценки ";
		cin >> number_mark;
		cout << "Введите предмет ";
		cin >> name_subject;
		subject_student.setNameSubject(semestr,number_mark,name_subject);
		cout << "Введите оценку по этому предмету ";
		cin >> mark;
		subject_student.setMark(semestr, number_mark, mark);
	}

}
void Menu::ChangeExamStudent()
{
	cout <<"(0) Изменить название экзамена.\n"
		<< "(1) Изменить оценку за экзамен.\n"
		<< "(2) Выход.";
	int choice;
	Student subject_student;
	string newname_subject;
	int semestr, number_mark, newmark;
	cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "Введите семестр ";
		cin >> semestr;//семестр в котором хотим изменить
		cout << "Введите номер предмета ";
		cin >> number_mark;//номер предмета, который надо изменить
		for (int i = 0; i < 9; i++)
		{
			if (i == semestr)
			{
				for (int j = 0; j < 10; j++)
				{
					if (j == number_mark)
					{
						cout << "Ввыедите новое название экзамена ";
						cin >> newname_subject;
						subject_student.setNameSubject(semestr, number_mark, newname_subject);
					}
				}
			}

		}
		break;


	case 1:
		cout << "Введите семестр ";
		cin >> semestr;//семестр в котором хотим изменить
		cout << "Введите номер предмета ";
		cin >> number_mark;//номер предмета, который надо изменить
		for (int i = 0; i < 9; i++)
		{
			if (i == semestr)
			{
				for (int j = 0; j < 10; j++)
				{
					if (j == number_mark)
					{
						cout << "Введите новую оценку ";
						cin >> newmark;
						subject_student.setMark(semestr, number_mark, newmark);
					}
				}
			}
		}
		break;

	case 2:
		break;
		
	}
}

void Menu::WriteToFile(List<Student>& student)
{
	ofstream file;
	file.open("Student.txt");
	if (file.is_open()) {
		for (int i = 0; i < student.getsizeList(); i++)
		{
			file <<":" << student[i].getChel_name() << " " << student[i].getChel_surName() << " " << student[i].getChel_familyName() << " " << student[i].getUniversity_group() << endl;
		}
		file << "!";
	}
	else
	{
		cout << "Ошибка открытия файла";
	}
	file.close();
}

void Menu::WriteFromFile(List<Student>& student)
{
	ifstream file;
	file.open("Student.txt");
	char simvol;
	Student newstudent;
	string name,
		surName,
		Familyname,
		sex,
		faculty,
		department,//кафедра
		group,
		record_book_number;//номер зачётной книжки
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
	if (file.is_open()) {
		file >> simvol;
		if (simvol == ':') {

			file >> name >> surName >> Familyname >> sex >> birthday >> birthmonth >> birthyear >> faculty >> department >> record_book_number >> group;
			newstudent.setChel_Name(name); newstudent.setChel_familyName(surName); newstudent.setChel_surName(Familyname); newstudent.setDate_day(birthday);  newstudent.setDate_month(birthmonth); newstudent.setDate_year(birthyear);
			newstudent.setUniversity_faculty(faculty); newstudent.setUniversity_department(department); newstudent.setUniversity_record_book_number(record_book_number); newstudent.setUniversity_group(group);
			student.push_front(newstudent);
		}
		else
		{
			cout << "end";
		}
	}
	else
	{
		cout << "Ошибка открытия файла";
	}
	file.close();
}












































