#include<fstream>
#include<iostream>
#include<string>
#include "all.h"
#include "crew.h"
#include "call.h"

int print_duty_crew(char * file_call, char * file_crew) {
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
						
	for (int i = 0; i < line_count; i++) 
    	{
        	fin >> crew_1[i];
		if (crew_1[i].duty_bool == true){
			cout << "Экипаж № "<< i+1 << endl;
        		cout <<"Доктор :" << crew_1[i].doctor << " Санитар : " << crew_1[i].paramedic << " Водитель : " << crew_1[i].driver <<" Часов на дежурстве : "<< crew_1[i].duty_status<<" Освободится с вызова через : "<<crew_1[i].call_status<< endl;
		}
    	}
	fin.close();
	delete [] crew_1;

    
    return 0;
}
