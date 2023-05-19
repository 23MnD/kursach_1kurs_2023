#pragma once
#include "Menu.h"
#include<iostream>
#include <algorithm>
using namespace std;
int choice;
void Menu:: MainMenu(List<Student>& student)
{
	while (true)
	{
	cout << "Меню\n"
		<< "(0) Добавить студента.\n"
		<< "(1) Изменить данные студента.\n"
		<< "(2) Удалить студента.\n"
		<< "(3) Вывести всех студентов.\n"
		<< "(4) Выполнить вариант 96.\n"
		<< "(5) Выход.\n";
	cin >> choice; 
			switch (choice)
		{
		case 0:
			EntryInformation(student);
		
			WriteToFile(student);
			break;
		case 1:
			ChangeInformation(student);
			WriteToFile(student);
			break;
		case 2:
			DeleteInformation(student);
			WriteToFile(student);
			break;
		case 3:
			printStudent(student);
			break;
			
		case 4:
			Variant_96(student);
			break;
		case 5:
			WriteToFile(student);
			return;
		
		}
	}
	
}

void Menu::EntryInformation(List<Student>&  studentlst)
{
	Student student;
	string name,
		surName,
		Familyname,
		faculty,
		department,//кафедра
		group;
		int record_book_number;//номер зачётной книжки
	char sex[1];
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
	
	int number_of_student;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	cout << "Введите количество студентов, которое хотите добавить:";
	cin >> number_of_student;
	for (int i = 0; i < number_of_student; i++)
	{
		while (true)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Введите Фамилию: ";
			getline(cin, Familyname);
			

			if (student.setChel_familyName(Familyname)) break;
			else cout << "Введите заново: " << endl;
		}
		while (true)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Введите Имя: ";
			getline(cin, name);
			student.setChel_Name(name);
			if (student.setChel_Name(name)) break;
			else cout << "Введите заново: " << endl;
		}
		while (true)
		{
			cout << "Введите Отчество: ";
			getline(cin, surName);
			student.setChel_surName(surName);
			if (student.setChel_surName(surName)) break;
			else cout << "Введите заново: " << endl;
		}
		while (true)
		{
			cout << "Введите пол студента (М-мужской или Ж-женский): ";
			scanf_s("%c", sex);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			student.setChel_sex(*sex);
			if (student.setChel_sex(*sex)) break;
			else cout << "Введите заново: " << endl;
		}
		while (true)
		{
			cout << "Ввидете день рождения студента: ";
			cin >> birthday;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			student.setDate_day(birthday);
			if (student.setDate_day(birthday)) break;
			else cout << "Введите заново: " << endl;
		}
		while (true)
		{
			cout << "Ввидете месяц рождения студента: ";
			cin >> birthmonth;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			student.setDate_month(birthmonth);
			if (student.setDate_month(birthmonth)) break;
			else cout << "Введите заново: " << endl;
		}
		cout << "Ввидете год рождения студента: ";
		cin >> birthyear;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		student.setDate_year(birthyear);
		cout << "Введите факультет: ";
		getline(cin, faculty);
		student.setUniversity_faculty(faculty);
		cout << "Введите кафедру: ";
		getline(cin, department);
		student.setUniversity_department(department);
		cout << "Введите номер зачетной книжки: ";
		cin>>record_book_number;
		student.setUniversity_record_book_number(record_book_number);
		cout << "Введите группу студента: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, group);
		student.setUniversity_group(group);
		studentlst.push_front(student);
		
	}
	WriteToFile(studentlst);
}

void Menu::ChangeInformation(List<Student> & studentlst)
{
	int index;
	Student student;
	string Newname,
		NewSurName,
		NewFamilyname,
		Newfaculty,
		Newdepartment,//кафедра
		Newgroup;
		int Newrecord_book_number;//номер зачётной книжки
	char Newsex[1];
	unsigned short Newbirthday;
	unsigned short Newbirthmonth;
	unsigned short Newbirthyear;
	cout << "Введите номер студента, которого хотите изменить: ";
	cin >> index;
	index--;
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
		<< "(10) Изменить Группу студента \n"
		<<"(11) Изменить данные об экзаменах\n"
		<< "(12) Выход\n";
	for (int i = 0; i < (int)studentlst.getsizeList(); i++)
	{
		if (i == index) 
		{
			cin >> choice;	
			switch (choice)
			{
			case 0:
				while (true)
				{
					cout << "Введите новое Имя студента: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					getline(cin, Newname);
					studentlst[index].setChel_Name(Newname);
					if (studentlst[index].setChel_Name(Newname))break;
					else cout << "Введите заново: " << endl;
				}
				
				break;
			case 1:
				while (true)
				{
					cout << "Введите новую Фамилию студента: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					getline(cin, NewFamilyname);
					studentlst[index].setChel_familyName(NewFamilyname);
					if (studentlst[index].setChel_familyName(NewFamilyname))break;
					else cout << "Введите заново: " << endl;
				}
				
				break;
			case 2:
				while (true)
				{
					cout << "Введите новое Отчество студента: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					getline(cin, NewSurName);
					studentlst[index].setChel_surName(NewSurName);
					if (studentlst[index].setChel_surName(NewSurName)) break;
					else cout << "Введите заново: " << endl;
				}
				
				break;
			case 3:
				while (true)
				{
					cout << "Введите новый Пол студента: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					scanf_s("%c", Newsex);
					studentlst[index].setChel_sex(*Newsex);
					if (studentlst[index].setChel_sex(*Newsex)) break;
					else cout << "Введите заново: " << endl;
				}
				
				break;
			case 4:
				while (true)
				{
					cout << "Введите новый День рождения студента: ";
					cin >> Newbirthday;
					studentlst[index].setDate_day(Newbirthday);
					if (studentlst[index].setDate_day(Newbirthday)) break;
					else cout << "Введите заново: " << endl;
				}
				
				break;
			case 5:
				while (true)
				{
					cout << "Введите новый Месяц рождения студента: ";
					cin >> Newbirthmonth;
					studentlst[index].setDate_month(Newbirthmonth);
					if (studentlst[index].setDate_month(Newbirthmonth)) break;
					else cout << "Введите заново: " << endl;
				}
				
				break;
			case 6:
				cout << "Введите новый Год рождения студента: ";
				cin >> Newbirthyear;
				studentlst[index].setDate_year(Newbirthyear);
				
				break;
			case 7:
				cout << "Введите новый Факультет студента: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, Newfaculty);
				studentlst[index].setUniversity_faculty(Newfaculty);
				
				break;
			case 8:
				cout << "Введите новую Кафедру студента: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, Newdepartment);
				studentlst[index].setUniversity_department(Newdepartment);
			
				break;
			case 9:
				cout << "Введите новый Номер зачётной книжки студента: ";
				cin>> Newrecord_book_number;
				studentlst[index].setUniversity_record_book_number(Newrecord_book_number);
				
				break;
			case 10:
				cout << "Введите новую Группу студента: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, Newgroup);
				studentlst[index].setUniversity_group(Newgroup);
			
				break;
			case 11:
				ChangeExamStudent(studentlst);
				
				break;
			case 12:
				return;

			}

		}
		
	}
	WriteToFile(studentlst);
}

void Menu::DeleteInformation(List<Student>& studentlst)
{
	cout << "Введите номер студента, которого хотите удалить: ";
	int index;
	cin >> index;
	index--;
	for (int i = 0; i < (int)studentlst.getsizeList(); i++)
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
		cout << student[i].getChel_familyName() << " " << student[i].getChel_name() << " " << student[i].getChel_surName() << " " << student[i].getUniversity_group();
		student[i].printDate(); 
	}
}

bool Menu::ChangeExamStudent(List<Student>& studentlst)
{
	int id;
	while (true) 
	{
		
		cout << "Введите номер студента, которому хотите добавить/изменить оценку: ";
		cin >> id;
		id--;
		if (studentlst.getsizeList() < id) continue; 
		break;
		
	}
	while(true)
	{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout <<"(0) Изменить название экзамена.\n"
		<< "(1) Изменить оценку за экзамен.\n"
		<< "(2) Выход.\n";
	
	string newname_subject;

	int semestr, number_mark, newmark;
	cin >> choice;
		switch (choice)
		{
		case 0:
		
			cout << "Введите семестр: ";
			cin >> semestr;//семестр в котором хотим изменить
			semestr--;
			cout << "Введите номер предмета: ";
			cin >> number_mark;//номер предмета, который надо изменить
			number_mark--;
			for (int i = 0; i < 9; i++)
			{
				if (i == semestr)
				{
					for (int j = 0; j < 10; j++)
					{
						if (j == number_mark)
						{
							while (true)
							{
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								cout << "Ввыедите название экзамена: ";
								getline(cin, newname_subject);
								

								studentlst[id].setNameSubject(semestr, number_mark, newname_subject);
								if (studentlst[id].setNameSubject(semestr, number_mark, newname_subject)) break;
								else cout << "Введите заново: " << endl;
							}

						}
					}
				}

			}
			break; 
		case 1:

			cout << "Введите семестр: ";
			cin >> semestr;//семестр в котором хотим изменить
			semestr--;
			cout << "Введите номер предмета: ";
			cin >> number_mark;//номер предмета, который надо изменить
			number_mark--;
			for (int i = 0; i < 9; i++)
			{
				if (i == semestr)
				{
					for (int j = 0; j < 10; j++)
					{
						if (j == number_mark)
						{
							cout <<"Введите оценку:\n "
								<< "0 - НЕЗАЧЁТ\n"
								<< " 1 - ЗАЧЁТ\n"
								<< " 2 - ОЦЕНКА 2\n"
								<< " 3 - ОЦЕНКА 3\n"
								<< " 4 - ОЦЕНКА 4\n"
								<< " 5 - ОЦЕНКА 5\n";
							cin >> newmark;
							studentlst[id].setMark(semestr, number_mark, newmark);
						}
					}
				}
			}
			break;

		case 2:

			return false;
			break;

		}
	}
}

void Menu::WriteToFile(List<Student>& student)
{
	ofstream file;
	string filename = "Student.txt";
	file.open(filename);
	if (file.is_open()) {
		for (size_t i = 0; i < student.getsizeList(); i++)
		{
			file<< ":" << student[i].getChel_familyName() << " " <<student[i].getChel_name() << " " << student[i].getChel_surName()  << " " << student[i].getChel_sex() << " " << student[i].getDate_day() << " " << student[i].getDate_month() << " " << student[i].getDate_year() << " " << student[i].getUniversity_group() << " " << student[i].getUniversity_department() << " " << student[i].getUniversity_faculty() << " " << student[i].getUniversity_record_book_number() << "\n";
			for (size_t j = 0; j < 9; j++)
			{
				for (size_t k = 0; k < 10; k++)
				{
					file << student[i].getNameSubject(j, k) << " " << student[i].getMark(j, k) << "\n";
				}
			}
		}
		file << "!";
	}
	else
	{
		cout << "Ошибка открытия файла";
	}
	
	file.close();
	Crypt(filename);
}

void Menu::ReadFromFile(List<Student>& student)
{
	ifstream file;
	string filename = "Student.txt";
	Decrypt(filename);
	file.open(filename,ios::in);
	char simvol;
	Student newstudent;
	string name,
		surName,
		Familyname,
		faculty,
		department,
		name_subject,
		group;
	char sex;
	int mark, record_book_number;
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
	if (file.is_open()) {
		while (file >> simvol)
		{
			if (simvol == ':')
			{
				file >> Familyname >> name >> surName >> sex >> birthday >> birthmonth >> birthyear >> group >> department >> faculty >> record_book_number;
				newstudent.setChel_Name(name); newstudent.setChel_familyName(Familyname); newstudent.setChel_surName(surName); newstudent.setDate_day(birthday);  newstudent.setDate_month(birthmonth); newstudent.setDate_year(birthyear);
				newstudent.setUniversity_faculty(faculty); newstudent.setUniversity_department(department); newstudent.setUniversity_record_book_number(record_book_number); newstudent.setUniversity_group(group);
				for (int semsetr = 0; semsetr < 9; semsetr++)
				{
					for (int number = 0; number < 10; number++)
					{
						file >> name_subject >> mark;
						newstudent.setNameSubject(semsetr, number, name_subject); newstudent.setMark(semsetr, number, mark);
					}
				}

				student.push_front(newstudent);
			}
		}
	}
	else
	{
		cout << "Ошибка чтения файла";
	}
	file.close();
	Crypt(filename);
}
void Menu::printStudentVar_96(List<Student>& student)
{
	for (int i = 0; i < student.getsizeList(); i++)
	{
		cout << student[i].getChel_familyName() << " " << student[i].getChel_name() << " " << student[i].getChel_surName() << " " << student[i].getUniversity_group();
		student[i].printDate();
		for (int semestr = 0; semestr < 9; semestr++)
		{
			semestr++;
			cout << semestr << " семестр" << endl;
			semestr--;
			for (int number_subject = 0; number_subject < 10; number_subject++)
			{
				if (student[i].getNameSubject(semestr, number_subject) == "default");
				else cout << student[i].getNameSubject(semestr, number_subject) << " " << student[i].getMark(semestr, number_subject) << endl;
			}
		}
	}
}
void  Menu::Variant_96(List<Student>& student)
{
	List<Student> group_of_excellent_students; //группа отличников и хорошиство
	List<Student> group_of_threes_students; //группа троечников
	int data1, data2;
	int counter=0;
	cout << "Введите интервал года рождения студентов:\n";
	cin >> data1 >> data2;
	for (int index = 0; index < (int)student.getsizeList(); index++)
	{
		if (student[index].getDate_year() >= data1 && student[index].getDate_year() <= data2)
		{
			bool flag = true;
			for (int semestr = 0; semestr < 9; semestr++)
			{
				for (int number_subject = 0; number_subject < 10; number_subject++)
				{
					if (student[index].getMark(semestr, number_subject) == 3 || student[index].getMark(semestr, number_subject) == 0 || student[index].getMark(semestr, number_subject) == 2)
					{
						group_of_threes_students.push_front(student[index]);
						flag = false; break;
					}
					if (student[index].getMark(semestr, number_subject) != -1)
					{
						counter++;
					}

				}
				if (!flag)break;
			}
			if (counter == 0) group_of_threes_students.push_front(student[index]);
			else if (flag) group_of_excellent_students.push_back(student[index]);
		}
	}
	// сортировка списков
	sortlst(group_of_excellent_students);
	sortlst(group_of_threes_students);
	cout << "Студенты отличнки\n";
	printStudentVar_96(group_of_excellent_students);
	cout << "Студенты троечники\n";
	printStudentVar_96(group_of_threes_students);

}

void  Menu::sortlst(List<Student>& student)
{
	for (int index = 0; index < (int)student.getsizeList() - 1; index++)
	{
		if (student[index].getUniversity_record_book_number() > student[index + 1].getUniversity_record_book_number())
		{
			student.movement(index, index + 1);
		}
	}
}

void Menu::Crypt(string fileName)
{
	srand(time(NULL));
	string fileNAME = fileName.substr(0, fileName.find_last_of('.'));
	char pass[65];
	for (int i = 0; i < 64; ++i) 
	{
		switch (rand() % 3) 
		{
		case 0:
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}
	pass[64] = '\0';
	string command = "OpenSSL\\bin\\openssl.exe enc -pbkdf2 -aes-256-cbc -salt -in " + fileName + " -out " + fileName + ".enc -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove(fileName.c_str()) != 0) 
	{
		cout << "[ERROR] - deleting file" <<endl;
	}
	ofstream file;
	file.open(fileNAME + "_key.txt", ios::binary);
	file.write(pass, 64);
	file.close();
	command = "OpenSSL\\bin\\openssl.exe pkeyutl -encrypt -inkey rsa.public -pubin -in " + fileNAME + "_key.txt -out " + fileNAME + "_key.txt.enc";
	system(command.c_str());
	if (remove((fileNAME + "_key.txt").c_str()) != 0)
	{
		cout << "[ERROR] - deleting file" << endl;
	}
}

void Menu::Decrypt(string fileName)
{
	string fileNAME = fileName.substr(0, fileName.find_last_of('.'));
	string command = "OpenSSL\\bin\\openssl.exe pkeyutl -decrypt -inkey rsa.private -in " + fileNAME + "_key.txt.enc -out key.txt";
	system(command.c_str());
	if (remove((fileNAME + "_key.txt.enc").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	char pass[65];
	std::ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 65);
	file.close();
	pass[64] = '\0';
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	command = "OpenSSL\\bin\\openssl.exe enc -pbkdf2 -aes-256-cbc -d -in " + fileName + ".enc -out " + fileName + " -pass pass:";
	command += pass;
	const char* a = command.c_str();
	system(a);
	if (remove((fileName + ".enc").c_str()) != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
}
