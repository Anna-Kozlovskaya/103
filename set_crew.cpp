#include <iostream>
#include "all.h"
#include "crew.h"
#include <fstream>
#include <string>
using namespace std;

int set_crew(char * file_call, char * file_crew) {
	int n1,n2,N,i;
	N=0;
       
    fstream set;
	set.open(file_crew,ios::in);
    	string str;
	while (getline(set,str))    //подсчет количества строк в файле сrew 
	{
        N++;
	}
	set.close();
	set.open(file_crew,ios::in);
	crew *set_crew = new crew[N];
			//считываем оставшиеся числа в файле,чтобы выводились только фамилии							
	for ( i = 0; i <N; i++) 
    	{
        	set >> set_crew[i];
        	cout<<"Экипаж №"<<i+1<<endl;
        	cout << set_crew[i].doctor << " " << set_crew[i].paramedic << " " << set_crew[i].driver << endl;
    	}
	set.close();
    	cout<<"Выберите два экипажа на дежурство"<<endl;
    	cin>>n1;
    	cin>>n2;   
   
    	while((n1 == n2) || ((n1 < 1)||(n1 > N)) || ((n2 < 1)||(n2 > N))){
        
        	cout<<"Экипажи выбранны некорректно, повторите попытку"<<endl;
       		cin>>n1;
        	cin>>n2;   
   
    	}
	
	ofstream fout(file_crew,ios_base::trunc);
	for ( i = 0; i < N; i++) 
    	{
        	if((i + 1) == n1)
				set_crew[i].duty_bool=true;
		if((i + 1) == n2)
				set_crew[i].duty_bool=true;
        	fout << set_crew[i];
    	}
     
    	fout.close();
    	delete [] set_crew;
	return 0;
}
