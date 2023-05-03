#pragma once
#include "Menu.h"
int choice;
void Menu:: MainMenu()
{
	List<Student> student;
	cout << "����\n"
		<< "(0) �������� ��������.\n"
		<< "(1) �������� ������ ��������.\n"
		<< "(2) ������� ��������.\n"
		<< "(3) ������� ���� ���������.\n"
		<< "(4) �����.";
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
		department,//�������
		group,
		record_book_number;//����� �������� ������
	unsigned short birthday;
	unsigned short birthmonth;
	unsigned short birthyear;
	 List<Student>  studentlst;

	while(true)
	{
		cout << "������� �������/���/��������: ";
		cin >> Familyname >> name >> surName;
		student.setChel_familyName(Familyname); student.setChel_Name(name); student.setChel_surName(surName);
		
		cout << "������� ��� �������� (�-������� ��� �-�������): ";
		cin >> sex;
		student.setChel_sex(sex);
		cout << "������� ���� �������� ��������: ";
		cin >> birthday >> birthmonth >> birthyear;
		student.setDate_day(birthday);  student.setDate_month(birthmonth); student.setDate_year(birthyear);
		cout << "������� ���������: ";
		cin >> faculty;
		student.setUniversity_faculty(faculty);
		cout << "������� �������: ";
		cin >> department;
		student.setUniversity_department(department);
		cout << "������� ����� �������� �����(� ������� 12�4567): ";
		cin >> record_book_number;
		student.setUniversity_record_book_number(record_book_number);
		cout << "������� ������ ��������: ";
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
	List<int> sizelst;//���-�� ���������
	Student student;
	string Newname,
		NewSurName,
		NewFamilyname,
		Newsex,
		Newfaculty,
		Newdepartment,//�������
		Newgroup,
		Newrecord_book_number;//����� �������� ������
	unsigned short Newbirthday;
	unsigned short Newbirthmonth;
	unsigned short Newbirthyear;
	cout << "������� ����� ��������, �������� ������ �������: ";
	cin >> index;
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
		<< "(10) �������� ������ �������� \n";
	for (int i = 0; i < sizelst.getsizeList(); i++)
	{
		if (i == index) 
		{
			cout << "������� ����� ��� ����, ����� �������� � �������� ���-�� �� ����������: ";
			cin >> choice;
			switch (choice)
			{
			case 0:
				cout << "������� ����� ��� ��������: ";
				cin >> Newname;
				student.setChel_Name(Newname);
			
				break;
			case 1:
				cout << "������� ����� ������� ��������: ";
				cin >> NewFamilyname;
				student.setChel_familyName(NewFamilyname);
				break;
			case 2:
				cout << "������� ����� �������� ��������: ";
				cin >> NewSurName;
				student.setChel_surName(NewSurName);
				break;
			case 3:
				cout << "������� ����� ��� ��������: ";
				cin >> Newsex;
				student.setChel_sex(Newsex);
				break;
			case 4:
				cout << "������� ����� ���� �������� ��������: ";
				cin >> Newbirthday;
				student.setDate_day(Newbirthday);
				break;
			case 5:
				cout << "������� ����� ����� �������� ��������: ";
				cin >> Newbirthmonth;
				student.setDate_month(Newbirthmonth);
				break;
			case 6:
				cout << "������� ����� ��� �������� ��������: ";
				cin >> Newbirthyear;
				student.setDate_year(Newbirthyear);
				break;
			case 7:
				cout << "������� ����� ��������� ��������: ";
				cin >> Newfaculty;
				student.setUniversity_faculty(Newfaculty);
				break;
			case 8:
				cout << "������� ����� ������� ��������: ";
				cin >> Newdepartment;
				student.setUniversity_department(Newdepartment);
				break;
			case 9:
				cout << "������� ����� ����� �������� ������ ��������: ";
				cin >> Newrecord_book_number;
				student.setUniversity_record_book_number(Newrecord_book_number);
				break;
			case 10:
				cout << "������� ����� ������ ��������: ";
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
	cout << "������� ����� ��������, �������� ������ �������: ";
	int index;
	List<Student>  studentlst;
	List<int> sizelst;//���-�� ���������
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
		cout << "������� ������� ";
		cin >> semestr;
		cout << "������� ����� ������ ";
		cin >> number_mark;
		cout << "������� ������� ";
		cin >> name_subject;
		subject_student.setNameSubject(semestr,number_mark,name_subject);
		cout << "������� ������ �� ����� �������� ";
		cin >> mark;
		subject_student.setMark(semestr, number_mark, mark);
	}

}
void Menu::ChangeExamStudent()
{
	cout <<"(0) �������� �������� ��������.\n"
		<< "(1) �������� ������ �� �������.\n"
		<< "(2) �����.";
	int choice;
	Student subject_student;
	string newname_subject;
	int semestr, number_mark, newmark;
	cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "������� ������� ";
		cin >> semestr;//������� � ������� ����� ��������
		cout << "������� ����� �������� ";
		cin >> number_mark;//����� ��������, ������� ���� ��������
		for (int i = 0; i < 9; i++)
		{
			if (i == semestr)
			{
				for (int j = 0; j < 10; j++)
				{
					if (j == number_mark)
					{
						cout << "�������� ����� �������� �������� ";
						cin >> newname_subject;
						subject_student.setNameSubject(semestr, number_mark, newname_subject);
					}
				}
			}

		}
		break;


	case 1:
		cout << "������� ������� ";
		cin >> semestr;//������� � ������� ����� ��������
		cout << "������� ����� �������� ";
		cin >> number_mark;//����� ��������, ������� ���� ��������
		for (int i = 0; i < 9; i++)
		{
			if (i == semestr)
			{
				for (int j = 0; j < 10; j++)
				{
					if (j == number_mark)
					{
						cout << "������� ����� ������ ";
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
		cout << "������ �������� �����";
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
		department,//�������
		group,
		record_book_number;//����� �������� ������
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
		cout << "������ �������� �����";
	}
	file.close();
}












































