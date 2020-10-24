#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//data declaration
typedef struct {
    int id;
    char name[20];
    int age;
    char medical_history[30];
    char date_and_time[25];
}database;

//node declaration
typedef struct linked_list{
    database data;
    struct linked_list* next_ptr;
}node;

//enum declaration
typedef enum state{
    not_ok,
    ok
}state;

void print_data(node *ptr);//print data by pointer
node* delete_data(node* ptr);//delete data by pointer

void get_data(database *ptr,node *head);//get data function declaration

state is_exist(node **ptr,int id);//a function to check if the node exist (by id)

node * create_node();//function that create new node

void add_patient(node** head_ptr);//add patient

void print_all(node* ptr);//print all

void delete_all(node** ptr);//delete all

void print_by_id(node *ptr,int id);//print data by id

void delete_by_id(node **ptr,int id);//delete by id

void reverse_list(node **ptr);

void sort_all_by_id(node **ptr,int num);//sort all by id (swapping :) data not pointers))

void sort_all_by_name(node **ptr,int num);

double conv_to_num(char date[]);

void sort_all_by_date(node **ptr,int num);
state is_id_exist(node *ptr,int id);
#endif // DECLARATION_H_INCLUDED
