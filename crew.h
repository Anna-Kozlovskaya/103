#ifndef CREW_H
#define CREW_H
#include <string>
#include <iostream>

using namespace std;

class crew
{
private:
    string doctor; //фамилия врача
    string paramedic; //фамилия фельдшера
    string driver; //фамилия водителя
    int duty_status; //статус дежурства: число часов на дежурстве (если  0 - то НЕ на дежурстве)
    int call_status; //статус вызова: когда освободится с текущего вызова
    bool duty_bool;//	

    friend ostream& operator<< (ostream& os, const crew& crew);
    friend istream& operator>> (istream& is, crew& crew);

    friend int print_crew(char * file_call, char * file_crew);
    friend int add_crew(char * file_call, char * file_crew);
    friend int deletes_crew(char * file_call, char * file_crew);
    friend int set_crew(char * file_call, char * file_crew);
    friend int add_call(char * file_call, char * file_crew);
    friend int set_time(char * file_call, char * file_crew);
};

#endif // CREW_H
