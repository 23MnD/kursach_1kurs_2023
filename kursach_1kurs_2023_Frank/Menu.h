#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "Studetnt.h"
#include "List.h"

class Menu
{
	Student studetn;
	List<Student> lst;




public:

	int EntryInformation();
	void ChangeInformation();
	void DeleteInformation();
	void printStudent(List<Student>& student);
	void AddExamStudent();
	void ChangeExamStudent();
	void WriteToFile(List<Student>& student);
	void WriteFromFile(List<Student>& student);
	void MainMenu();
};

