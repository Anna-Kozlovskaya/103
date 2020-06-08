#ifndef ALL_H
#define ALL_H


//Здесь объявлены все функции.

int menu(char * file_call, char * file_crew); //меню
int print_crew(char * file_call, char * file_crew); //вывести список экипажей
int print_call(char * file_call, char * file_crew); //вывести историю вызовов
int add_crew(char * file_call, char * file_crew); //добавить экипаж
int deletes_crew(char * file_call, char * file_crew); // удалить экипаж
int set_crew(char * file_call, char * file_crew); //установить дежурные экипажи
int print_duty_crew(char * file_call, char * file_crew); //вывести дежурные экипажи
int add_call(char * file_call, char * file_crew); //принять вызов
int set_time(char * file_call, char * file_crew); //добавить N часов
void search(char * file_call, char * file_crew); //найти экипаж
#endif // ALL_H
