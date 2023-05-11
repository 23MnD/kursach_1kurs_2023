
#include <iostream>
#include <string.h>
#include "Studetnt.h"
#include "List.h"
#include "Menu.h"
#include <Windows.h>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu menu;
	List<Student> student;
	menu.ReadFromFile(student);
	menu.WriteToFile(student);
	menu.MainMenu(student);
	
}



