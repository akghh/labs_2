#include <stdio.h>
#include <stdlib.h>

#include "student.h"
#include "io.h"

/* Student IO */
int student_read_txt(Student *s, FILE *in)
{
    fscanf(in, "%s", s->surname);
    fscanf(in, "%s", s->initials);
    fscanf(in, " %c", &(s->gender));
    fscanf(in, "%d", &(s->class_number));
    fscanf(in, " %c", &(s->class_letter));
    fscanf(in, "%s", s->university);
    fscanf(in, "%s", s->job);
    fscanf(in, "%s", s->regiment);

    return !feof(in);
}

int student_read_bin(Student *s, FILE *in)
{
    fread(s->surname,  sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), STR_SIZE, in);
    fread(&(s->gender), sizeof(char), 1, in);
    fread(&(s->class_number), sizeof(int), 1, in);
    fread(&(s->class_letter), sizeof(char), 1, in);
    fread(s->university, sizeof(char), STR_SIZE, in);
    fread(s->job, sizeof(char), STR_SIZE, in);
    fread(s->regiment, sizeof(char), STR_SIZE, in);

    return !feof(in);
}

void student_write_bin(Student *s, FILE *out)
{
    fwrite(s->surname,  sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), STR_SIZE, out);
    fwrite(&(s->gender), sizeof(char), 1, out);
    fwrite(&(s->class_number), sizeof(int), 1, out);
    fwrite(&(s->class_letter), sizeof(char), 1, out);
    fwrite(s->university, sizeof(char), STR_SIZE, out);
    fwrite(s->job, sizeof(char), STR_SIZE, out);
    fwrite(s->regiment, sizeof(char), STR_SIZE, out);
}

void student_print(Student *s)
{
    printf("Имя: %s %s\n", s->surname, s->initials);
    printf("Пол: %c\n", s->gender);
    printf("Номер класса: %d\n", s->class_number);
    printf("Буква класса: %c\n", s->class_letter);
    printf("ВУЗ: %s\n", s->university);
    printf("Работа: %s\n", s->job);
    printf("Полк: %s\n", s->regiment);

    printf("\n");
}
