#include<fstream>
#include<iostream>
#include<string>
#include "all.h"
#include "crew.h"
#include "call.h"

/*функция вывода базы экипажей,т.е/ФИО врача/ /ФИО фельдшера/ /ФИО водителя/*/

int print_crew(char * file_call, char * file_crew) {
	ifstream fin;
	fin.open(file_crew);
	if (!(fin.is_open()))
	{
		cout << "Error file not open!!"<< endl;
	}
	int line_count=0;
	string str;
	while (getline(fin,str))    //подсчет количества строк в файле сrew 
	{
		line_count++;
	}
	fin.close();
	fin.open(file_crew);
	crew *crew_1 = new crew[line_count];
	int a,b,c;			//считываем оставшиеся числа в файле,чтобы выводились только фамилии							
	for (int i = 0; i < line_count; i++) 
    	{
        	fin >> crew_1[i].doctor >> crew_1[i].paramedic >> crew_1[i].driver >> a >> b >> c;
        	cout << crew_1[i].doctor << " " << crew_1[i].paramedic << " " << crew_1[i].driver << endl;
    	}
	fin.close();
	delete [] crew_1;

    ask(file_call, file_crew);
    return 0;
}
