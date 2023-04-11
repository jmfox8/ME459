#include "alloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "record.h"


// allocate memory using malloc and populate the array of Record
void initializeStudentData(Record **ptr, int numStudents){
    *ptr = (struct StudRecord *)malloc(sizeof(struct StudRecord) * numStudents);
    char firstnameoptions[15][20] = {               //Array Defining the potential First Names
        "Marius",
        "Mihaela",
        "Simona",
        "Dan",
        "Vlad",
        "Stefan",
        "Claudiu",
        "Laurentiu",
        "Horatiu",
        "Andrei",
        "Cristina",
        "Ioana",
        "Nicolae",
        "Maria",
        "Clement",
    };
    char lastnameoptions[10][20] = {                //Array Defining the potential Last Names
        "Popescu",
        "Ionescu",
        "Vasilescu",
        "Dumitrescu",
        "Ceausescu",
        "Vornicu",
        "Patrascu",
        "Mateescu",
        "Balan",
        "Popovici",
    };
    char mid;
    float gpaval;
    uint8_t doby;
    uint8_t dobm;
    uint8_t dobd;
    for (int i = 0; i < numStudents; i++){              //for loop to populate the array of Records
        for (int jfirst = 0; jfirst < 20; jfirst++){
        *ptr[i].fname[jfirst] -> firstnameoptions[rand()/RAND_MAX * 15][jfirst];
        }
         for (int jlast = 0; jlast < 20; jlast++){
        *ptr[i][1].lname[jlast] = lastnameoptions[rand()/RAND_MAX * 10][jlast];
        }
        mid = (rand()/RAND_MAX)*(90-65) + 65;
        //ptr[i]->mid = mid;
        gpaval = 3.23;
        gpaval = (rand()/RAND_MAX) * 4;
        *ptr+i->gpa = gpaval;
        doby = (rand()/RAND_MAX)*(2010 - 1900) + 1900;
        dobm = (rand()/RAND_MAX)*12;
        if(dobm == 1 || dobm == (int)3 || dobm == (int)5 || dobm == (int)7 || dobm == (int)8 || dobm == (int)10 || dobm == (int)12){
            dobd = (rand()/RAND_MAX)*31;
            }        
        else if (dobm == 2){
            dobd = (rand()/RAND_MAX)*31;
            }
        else {
            dobd = (rand()/RAND_MAX)*30;
            } 
        ptr[i]->dob[0] = dobm;
        ptr[i]->dob[1] = dobd;
        ptr[i]->dob[2] = doby;
    } 
        
 }   
