#ifndef RECORD_H
#define RECORD_H
#include <stdint.h>

typedef struct StudRecord{
    char fname[20];
    char lname[20];
    char mid[1];
    float gpa;
    uint8_t dob[3];
} Record;

#endif
