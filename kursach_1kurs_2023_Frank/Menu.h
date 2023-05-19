#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "Studetnt.h"
#include "List.h"

class Menu
{
public:

	void EntryInformation(List<Student>& studentlst);
	void ChangeInformation(List<Student>& studentlst);
	void DeleteInformation(List<Student>& studentlst);
	void printStudent(List<Student>& student);
	bool ChangeExamStudent(List<Student>& studentlst);
	void WriteToFile(List<Student>& student);
	void ReadFromFile(List<Student>& student);
	void MainMenu(List<Student>& student);
	void sortlst(List<Student>& student);
	void Variant_96(List<Student>& student);
	void printStudentVar_96(List<Student>& student);
	void Decrypt(string name);
	void Crypt(string name);
};

