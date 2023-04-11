#include <stdio.h>
#include <stdlib.h>

#include "record.h"
#include "alloc.h"
//#include "mysort.h"


// print out an array of Record in format: firstname MI lastname, gpa, MM-DD-YY
void printRecords(Record *ptr, int numStudents){
int i;
for(i = 0; i<numStudents;i++){
    printf("%s %s %s, %f, %i-%i-%i \n", ptr[i].fname, ptr[i].mid, ptr[i].lname,ptr[i].gpa,ptr[i].dob[0],ptr[i].dob[1],ptr[i].dob[2]);
}
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("provide number of students\n");
        return 1;
    }
    int listlength = atoi(argv[1]);
    struct StudRecord *stdlist;
    initializeStudentData(&stdlist, listlength);

    printf("student info\n");

    printRecords(stdlist,listlength);

    /*********** add your code here ***********/
    
    printf("sort by last name\n");

    /*********** add your code here ***********/

    printf("sort by DOB\n");

    /*********** add your code here ***********/

    printf("sort by GPA\n");

    /*********** add your code here ***********/

    return 0;
}