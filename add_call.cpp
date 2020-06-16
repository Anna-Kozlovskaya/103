#include <iostream>
#include <fstream>
#include "all.h"
#include "crew.h"
#include "call.h"
using namespace std;

int add_call(char * file_call, char * file_crew){
    	int N,i;
    	N=0;	
    	call add_call;
    	fstream add;
	add.open(file_call,ios::app);

	cout<<"Заполните информацию о вызове:"<<endl;
	cout<<"Адрес : "<<endl;
	cin>>add_call.address;
	cout<<"Время пути до адреса :"<<endl;
	cin>>add_call.time_to;
	cout<<"Надобность госпитализации да/нет :"<<endl;
	cin>>add_call.need_hosp;
	if(add_call.need_hosp=="да")
	{
	    cout<<"Время пути обратно : "<<endl;
	    cin>>add_call.time_back;
	}
	else
	add_call.time_back=0;
	fstream crews;
	crews.open(file_crew,ios::in);
	if (!crews)
	{
		cout << "Error file not open!!"<< endl;
	}
	
	string str;
	while (getline(crews,str))    //подсчет количества строк в файле сrew 
	{
		N++;
	}
	crews.close();
	crew *crew_1 = new crew[N];
	crews.open(file_crew,ios::in);
	int Ncrew;
	int Ncrew_1=-1;
	int Ncrew_2=-1;
	cout<<"Выберите экипаж, который хотите назначить на вызов :"<<endl;
						
	for (int i = 0; i < N; i++) 
    	{
        	crews >> crew_1[i];
		if (crew_1[i].duty_bool == true){

			cout << "Экипаж № "<< i+1 << endl;
        		cout << crew_1[i].doctor << " " << crew_1[i].paramedic << " " << crew_1[i].driver << endl;
			if (Ncrew_1<0)
				Ncrew_1=i;
			else 
				Ncrew_2=i;
		}
    	}
	crews.close();
	cin>>Ncrew;
	
	switch (Ncrew)
	{
		case 1:
		{
			if ((crew_1[Ncrew_1].duty_status+add_call.time_to+add_call.time_back)>=24)
			{
				cout<<"Первышение возможных часов на смене. Назначьте новые экипажи."<<endl;
				return 0;
			}
			add_call.assigned_crew=crew_1[Ncrew_1].doctor;
			crew_1[Ncrew_1].call_status += add_call.time_to + add_call.time_back;
			add_call.status="выехали";
			break;
		}
		case 2:
		{
			if ((crew_1[Ncrew_2].duty_status+add_call.time_to+add_call.time_back)>=24)
			{
				cout<<"Первышение возможных часов на смене. Назначьте новые экипажи."<<endl;
				return 0;
			}
			add_call.assigned_crew=crew_1[Ncrew_2].doctor;
			crew_1[Ncrew_2].call_status += add_call.time_to + add_call.time_back;
			add_call.status="выехали";
			break;
		}
		default :
		{
			cout<<"Некорректный ввод."<<endl;
			return 0;
		}

	}
		
  	add<<add_call;
   	add.close();
	crews.open(file_crew,ios::trunc | ios::out);
	for (i = 0; i < N ; i++) {
	    	crews <<  crew_1[i];
   	 }
	crews.close();
  	delete [] crew_1;
	
	return 0;
}
