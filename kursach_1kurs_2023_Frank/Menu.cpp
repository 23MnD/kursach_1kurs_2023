#pragma once
//�������� �������� ������ � ��������.
#include "Menu.h"
#include<iostream>
#include <algorithm>
using namespace std;
int choice;
void Menu:: MainMenu(List<Student>& student)
{
	while (true)
	{
	cout << "����\n"
		<< "(0) �������� ��������.\n"
		<< "(1) �������� ������ ��������.\n"
		<< "(2) ������� ��������.\n"
		<< "(3) ������� ���� ���������.\n"
		<< "(4) ��������� ������� 96.\n"
		<< "(5) �����.\n";
	cin >> choice; 
			switch (choice)
		{
		case 0:
			EntryInformation(student);
			ChangeExamStudent(student);
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
		department,//�������
		group;
		int record_book_number;//����� �������� ������
	char sex[1];
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
	
	int number_of_student;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	cout << "������� ���������� ���������, ������� ������ ��������:";
	cin >> number_of_student;
	for (int i = 0; i < number_of_student; i++)
	{
		while (true)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "������� �������: ";
			getline(cin, Familyname);
			

			if (student.setChel_familyName(Familyname)) break;
			else cout << "������� ������: " << endl;
		}
		while (true)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "������� ���: ";
			/*std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
			getline(cin, name);
			
			student.setChel_Name(name);
			if (student.setChel_Name(name)) break;
			else cout << "������� ������: " << endl;
		}
		while (true)
		{
			cout << "������� ��������: ";
			/*std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
			getline(cin, surName);
			student.setChel_surName(surName);
			if (student.setChel_surName(surName)) break;
			else cout << "������� ������: " << endl;
		}
		while (true)
		{
			cout << "������� ��� �������� (�-������� ��� �-�������): ";
			scanf_s("%c", sex);
			/*std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
			student.setChel_sex(*sex);
			if (student.setChel_sex(*sex)) break;
			else cout << "������� ������: " << endl;
		}
		while (true)
		{
			cout << "������� ���� �������� ��������: ";
			cin >> birthday;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			student.setDate_day(birthday);
			if (student.setDate_day(birthday)) break;
			else cout << "������� ������: " << endl;
		}
		while (true)
		{
			cout << "������� ����� �������� ��������: ";
			cin >> birthmonth;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			student.setDate_month(birthmonth);
			if (student.setDate_month(birthmonth)) break;
			else cout << "������� ������: " << endl;
		}
		cout << "������� ��� �������� ��������: ";
		cin >> birthyear;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		student.setDate_year(birthyear);
		cout << "������� ���������: ";
		getline(cin, faculty);
		/*std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
		student.setUniversity_faculty(faculty);
		cout << "������� �������: ";
		getline(cin, department);
		/*std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
		student.setUniversity_department(department);
		cout << "������� ����� �������� �����: ";
		cin>>record_book_number;
		/*std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
		student.setUniversity_record_book_number(record_book_number);
		cout << "������� ������ ��������: ";
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
		Newdepartment,//�������
		Newgroup;
		int Newrecord_book_number;//����� �������� ������
	char Newsex[1];
	unsigned short Newbirthday;
	unsigned short Newbirthmonth;
	unsigned short Newbirthyear;
	cout << "������� ����� ��������, �������� ������ ��������: ";
	cin >> index;
	index--;
	cout << "(0) �������� ��� �������� \n"
		<< "(1) �������� ������� �������� \n"
		<< "(2) �������� �������� �������� \n"
		<< "(3) �������� ��� �������� \n"
		<< "(4) �������� ���� �������� �������� \n"
		<< "(5) �������� ����� �������� �������� \n"
		<< "(6) �������� ��� �������� �������� \n"
		<< "(7) �������� ��������� �������� \n"
		<< "(8) �������� ������� �������� \n"
		<< "(9) �������� ����� �������� ������  �������� \n"
		<< "(10) �������� ������ �������� \n"
		<<"(11) �������� ������ �� ���������\n"
		<< "(12) �����\n";
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
					cout << "������� ����� ��� ��������: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					getline(cin, Newname);
					studentlst[index].setChel_Name(Newname);
					if (studentlst[index].setChel_Name(Newname))break;
					else cout << "������� ������: " << endl;
				}
				
				break;
			case 1:
				while (true)
				{
					cout << "������� ����� ������� ��������: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					getline(cin, NewFamilyname);
					studentlst[index].setChel_familyName(NewFamilyname);
					if (studentlst[index].setChel_familyName(NewFamilyname))break;
					else cout << "������� ������: " << endl;
				}
				
				break;
			case 2:
				while (true)
				{
					cout << "������� ����� �������� ��������: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					getline(cin, NewSurName);
					studentlst[index].setChel_surName(NewSurName);
					if (studentlst[index].setChel_surName(NewSurName)) break;
					else cout << "������� ������: " << endl;
				}
				
				break;
			case 3:
				while (true)
				{
					cout << "������� ����� ��� ��������: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					scanf_s("%c", Newsex);
					studentlst[index].setChel_sex(*Newsex);
					if (studentlst[index].setChel_sex(*Newsex)) break;
					else cout << "������� ������: " << endl;
				}
				
				break;
			case 4:
				while (true)
				{
					cout << "������� ����� ���� �������� ��������: ";
					cin >> Newbirthday;
					studentlst[index].setDate_day(Newbirthday);
					if (studentlst[index].setDate_day(Newbirthday)) break;
					else cout << "������� ������: " << endl;
				}
				
				break;
			case 5:
				while (true)
				{
					cout << "������� ����� ����� �������� ��������: ";
					cin >> Newbirthmonth;
					studentlst[index].setDate_month(Newbirthmonth);
					if (studentlst[index].setDate_month(Newbirthmonth)) break;
					else cout << "������� ������: " << endl;
				}
				
				break;
			case 6:
				cout << "������� ����� ��� �������� ��������: ";
				cin >> Newbirthyear;
				studentlst[index].setDate_year(Newbirthyear);
				
				break;
			case 7:
				cout << "������� ����� ��������� ��������: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, Newfaculty);
				studentlst[index].setUniversity_faculty(Newfaculty);
				
				break;
			case 8:
				cout << "������� ����� ������� ��������: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, Newdepartment);
				studentlst[index].setUniversity_department(Newdepartment);
			
				break;
			case 9:
				cout << "������� ����� ����� �������� ������ ��������: ";
				cin>> Newrecord_book_number;
				studentlst[index].setUniversity_record_book_number(Newrecord_book_number);
				
				break;
			case 10:
				cout << "������� ����� ������ ��������: ";
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
	cout << "������� ����� ��������, �������� ������ �������: ";
	int index;;
	//���-�� ���������
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
		cout << student[i].getChel_name() << " " << student[i].getChel_surName() << " " << student[i].getChel_familyName() << " " << student[i].getUniversity_group() << endl;
	}
}

//void Menu::AddExamStudent()
//{
//	Student subject_student;
//	string name_subject;
//	int semestr, number_mark, mark;
//
//		cout << "������� ������� ";
//		cin >> semestr;
//		cout << "������� ����� ������ ";
//		cin >> number_mark;
//		while (true)
//		{
//			cout << "������� ������� ";
//			getline(cin, name_subject);
//			subject_student.setNameSubject(semestr, number_mark, name_subject);
//			if (subject_student.setNameSubject(semestr, number_mark, name_subject)) break;
//			else cout << "������� ������: " << endl;
//		}
//		
//		cout << "������� ������ �� ����� �������� ";
//		cin >> mark;
//		subject_student.setMark(semestr, number_mark, mark);
//	
//
//}

bool Menu::ChangeExamStudent(List<Student>& studentlst)
{
	int id;
	while (true) 
	{
		
		cout << "������� ����� ��������, �������� ������ ��������/�������� ������: ";
		cin >> id;
		id--;
		if (studentlst.getsizeList() < id) continue; 
		break;
		
	}
	while(true)
	{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout <<"(0) �������� �������� ��������.\n"
		<< "(1) �������� ������ �� �������.\n"
		<< "(2) �����.\n";
	
	string newname_subject;

	int semestr, number_mark, newmark;
	cin >> choice;
		switch (choice)
		{
		case 0:
			
			cout << "������� �������: ";
			cin >> semestr;//������� � ������� ����� ��������
			semestr--;
			cout << "������� ����� ��������: ";
			cin >> number_mark;//����� ��������, ������� ���� ��������
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
								cout << "�������� �������� ��������: ";
								getline(cin, newname_subject);
								

								studentlst[id].setNameSubject(semestr, number_mark, newname_subject);
								if (studentlst[id].setNameSubject(semestr, number_mark, newname_subject)) break;
								else cout << "������� ������: " << endl;
							}

						}
					}
				}

			}
			break; 


		case 1:
			cout << "������� ������� ";
			cin >> semestr;//������� � ������� ����� ��������
			semestr--;
			cout << "������� ����� �������� ";
			cin >> number_mark;//����� ��������, ������� ���� ��������
			number_mark--;
			for (int i = 0; i < 9; i++)
			{
				if (i == semestr)
				{
					for (int j = 0; j < 10; j++)
					{
						if (j == number_mark)
						{
							cout << "������� ������: ";
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
	file.open("Student.txt");
	if (file.is_open()) {
		for (size_t i = 0; i < student.getsizeList(); i++)
		{
			file<< ":" << student[i].getChel_familyName() << " " <<student[i].getChel_name() << " " << student[i].getChel_surName()  << " " << student[i].getChel_sex() << " " << student[i].getDate_day() << " " << student[i].getDate_month() << " " << student[i].getDate_year() << " " << student[i].getUniversity_group() << " " << student[i].getUniversity_department() << " " << student[i].getUniversity_faculty() << " " << student[i].getUniversity_record_book_number() << "\n";
			for (size_t j = 0; j < 9; j++)
			{
				for (size_t k = 0; k < 10; k++)
				{
					file<< student[i].getNameSubject(j,k) << " " << student[i].getMark(j,k) << "\n";

				}

			}
		}

		file << "!";
	}
	else
	{
		cout << "������ �������� �����";
	}
	file.close();
}

void Menu::ReadFromFile(List<Student>& student)
{
	ifstream file;
	file.open("Student.txt");
	char simvol;
	Student newstudent;
	string name,
		surName,
		Familyname,
		faculty,
		department,//�������
		name_subject,
		group;
	string sex;
	int mark,record_book_number;//����� �������� ������
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
	if (file.is_open()) {
		while (file >> simvol)
		{
			cout << simvol;
			if (simvol == ':')
			{
				file >> Familyname >> name >> surName >> sex >> birthday >> birthmonth >> birthyear >> group >> department >> faculty >>record_book_number;
				newstudent.setChel_Name(name); newstudent.setChel_familyName(surName); newstudent.setChel_surName(Familyname); newstudent.setDate_day(birthday);  newstudent.setDate_month(birthmonth); newstudent.setDate_year(birthyear);
				newstudent.setUniversity_faculty(faculty); newstudent.setUniversity_department(department); newstudent.setUniversity_record_book_number(record_book_number); newstudent.setUniversity_group(group);
				for (int semsetr = 0; semsetr < 9; semsetr++)
				{
					for (int number = 0; number < 10; number++)
					{
						file >> name_subject >> mark;
						newstudent.setNameSubject(semsetr, number, name_subject); newstudent.setMark(semsetr, number, mark);
					}
				}

				student.push_back(newstudent);
			}
			else
			{
				cout << "end";
			}
		}
	}
	else
	{
		cout << "������ �������� �����";
	}
	file.close();
}


void  Menu::Variant_96(List<Student>& student)
{
	List<Student> group_of_excellent_students; //������ ���������� � ����������
	List<Student> group_of_threes_students; //������ ����������
	int data1, data2;
	cout << "������� �������� ���� �������� ���������:\n";
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
					if (student[index].getMark(semestr, number_subject) == 3)
					{
						group_of_threes_students.push_front(student[index]);
						flag = false; break;
					}

				}
				if (!flag)break;
			}
			if (flag) group_of_excellent_students.push_back(student[index]);
		}
	}
	// ���������� �������
	sortlst(group_of_excellent_students);
	sortlst(group_of_threes_students);
	cout << "�������� ��������\n";
	printStudent(group_of_excellent_students);
	cout << "\n";
	cout << "�������� ���������\n";
	printStudent(group_of_threes_students);

}

void  Menu::sortlst(List<Student>& student)
{

	for (int index = 0; index < (int)student.getsizeList()-1; index++)
	{
		if (student[index].getUniversity_record_book_number() > student[index + 1].getUniversity_record_book_number())
		{
			student.movement(index, index + 1);
		}
	}

}






































