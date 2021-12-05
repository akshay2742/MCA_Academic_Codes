#include<stdio.h>

struct student{
    int Roll_no;
    char name[20];
    char branch[50];
    char course[50];
    int Subject;

};

struct student input(){
    struct student s;

    scanf("%d",&s.Roll_no);
    fflush(stdin);
    scanf("%s",s.name);
    fflush(stdin);
    scanf("%s",s.branch);
    fflush(stdin);
    scanf("%s",s.course);
    fflush(stdin);
    scanf("%d",&s.Subject);

    return (s);
}
void display(struct student s){
    printf("\n\nSTUDENT DETAILS\n\n");
    printf("Roll No: %d || Student Name: %s\n",s.Roll_no,s.name);
    printf("Branch: %s || Course: %s\n",s.branch,s.course);
    printf("No. of Subjects: %d",s.Subject);

}
void main(){

    struct student s1;

    printf("Enter the Details of the Student:\n1. Roll No\n2. Student Name\n3. Branch\n4. Course \n5. No. of Subjects\n");

    s1=input();

    display(s1);

    
}