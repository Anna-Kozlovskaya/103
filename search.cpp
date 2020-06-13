#include "all.h"
#include "crew.h"
#include <string>
#include<fstream>
#include <iostream>

using namespace std;

int search(char * file_call, char * file_crew){

	ifstream fin;
	fin.open(file_crew);
	if (!(fin.is_open()))
	{
		cout << "Ошибка! Не удалось открыть файл!!"<< endl;
	}
	int line_count=0;
	string str;
	while (getline(fin,str))    //подсчет количества строк в файле сrew 
	{
		line_count++;
	}
	fin.close();
	fin.open(file_crew);

	crew crew_2;
	crew crew_3;
	
	cout << "Введите экипаж который хотите найти: "<< endl;
	cin >> crew_2.doctor >> crew_2.paramedic >> crew_2.driver;

	for (int i = 0; i < line_count ; i++) {
		fin >> crew_3;
			if ((crew_3.doctor == crew_2.doctor) && (crew_3.paramedic == crew_2.paramedic) && (crew_3.driver == crew_2.driver)){
				cout << "Экипаж найден :" << endl;	
				cout << crew_3;
			}	
			
    	}
	fin.close();	
	return 0;
}
