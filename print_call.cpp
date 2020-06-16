#include <iostream>
#include <fstream>
#include <string.h>
#include "all.h"
#include "crew.h"
#include "call.h"
using namespace std;

int print_call(char * file_call, char * file_crew) {
	
	int N,i;
	N=0;
	call *call_1;
	fstream print_call;
	print_call.open(file_call,ios::in);
	if (!print_call)
	{
		cout << "Error file not open!!"<< endl;
	}
	
	string str;
	while (getline(print_call,str))   
	{
		N++;
	}
	print_call.close();
	call_1 = new call[N];
	print_call.open(file_call,ios::in);
	
										
	for (i = 0; i < N; i++) 
    	{
        	print_call >> call_1[i];
        	cout <<"Адрес : "<< call_1[i].address << endl <<"Время до адреса : "<< call_1[i].time_to << endl <<"Необходимость госпитализации : "<<call_1[i].need_hosp << endl <<"Время Обратно : "<< call_1[i].time_back << endl <<"Фамилия врача : "<<call_1[i].assigned_crew << endl << "Статус вызова : "<<call_1[i].status <<endl;
		cout<<endl;
    	}
	print_call.close();
	delete [] call_1;


    
    return 0;
}
