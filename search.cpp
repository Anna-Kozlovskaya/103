#include "all.h"
#include "crew.h"
#include <string>
#include <iostream>

using namespace std;

void search(char * file_call, char * file_crew)

{

	cout<<"Enter crew you want us to find ('doctor surename')"<<endl; //я так поняла, у нас номер экипажа привязывается к фамилии врача, так что сделала поиск по фамилии врача

	int tmp = -1;

	string surename;

	cin.getline(surename,99);

	for (int i = 0; i<Number; i++)

	{

		if ((strcmp(mass[i].surename, surename) == 0) && (strcmp(mass[i].name, name) == 0))

		{

			cout<<mass[i].number<<" "<<mass[i].surename<<" "<<mass[i].surename<<" "<<mass[i].surename<<" "<<mass[i]. duty_status r<< " "<< mass[i]. call_status << endl;

			tmp = 1;

			break;

		}

	}

	if (tmp == -1)

	{

		cout<<"Sorry, we can't find it"<<endl;

	}

}
