#ifndef ALL_H
#define ALL_H


//Здесь объявлены все функции.

int menu(char * file_call, char * file_crew); //меню
int print_crew(char * file_call, char * file_crew); //вывести список экипажей
int print_call(char * file_call, char * file_crew); //вывести историю вызовов
int edit_crew(char * file_call, char * file_crew); //редактировать базу экипажей (включает 3 ф-и: удаление, добавление, редактирование)
int set_crew(char * file_call, char * file_crew); //установить дежурные экипажи
int print_duty_crew(char * file_call, char * file_crew); //вывести дежурные экипажи
int add_call(char * file_call, char * file_crew); //принять вызов
int set_time(char * file_call, char * file_crew); //добавить N часов
#endif // ALL_H
