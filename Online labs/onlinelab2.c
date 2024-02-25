#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[1000];
    int age;
}student; //21
    


void change_int(int *p_int){
    *p_int = 49; //5
}
void change_int2(int **p_p_int){
    **p_p_int = 46; //10
}
void change_int_ptr(int **p_p_int){
    *p_p_int = malloc(sizeof(int)); //11
}
void change_arr(int *p_arr){
p_arr[2] = 8; //16
}

void change_name(student *p_s){
    strcpy(p_s->name, "Jenny"); //27
}
void change_age(student *p_s){
    p_s->age = 20; //28
}


int main () {
    int a = 42; //1
    int *p_a = &a; //2
    *p_a = 43; //3
    int b = 44; p_a = &b; //4
    change_int(&a); //6
    change_int(p_a); //7
    int **p_p_a; //8
    p_p_a = &p_a; //9
    change_int2(&p_a); change_int2(p_p_a); //12
    change_int_ptr(&p_a); //13
    change_int_ptr(p_p_a); //14
    int arr[3] = {5, 6, 7}; //15
    change_arr(arr); //17
    int *p_block = malloc(3 * sizeof(int));//18
    change_arr(p_block); //18
    change_int(p_block); //19
    change_int_ptr(&p_block); //20
    student s = {"Jenny", 20}; //21
    strcpy(s.name, "Jennifer"); //22
    s.age = 21; //23
    student *p_s = &s; //24
    strcpy(p_s->name, "Jenny");  //25
    (*p_s).age = 20; //26
    change_name(p_s); //29
    change_age(&s); //30
    student arr_s[5];//31
    change_name(&(arr_s[2]));  //32
    change_age(arr_s + 2);  //32


    return 0;
}