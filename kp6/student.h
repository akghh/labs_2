#ifndef _STUDENT_H_
#define _STUDENT_H_

#define STR_SIZE 30

typedef struct
{
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    char gender;
    int class_number;
    char class_letter;
    char university[STR_SIZE];
    char job[STR_SIZE];
    char regiment[STR_SIZE];
    
} Student;

#endif
