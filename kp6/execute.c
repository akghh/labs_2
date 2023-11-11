#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "io.h"

//Найти классы, выпускники которых либо поступили в вузы, либо
//призваны на военную службу

void sort(int arr[], int length)
{
    int tmp;
    for (int i = 1; i < length; ++i) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
}

int main()
{
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.bin", "wb+");
    
    if (!in || !out) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    
    Student s;
    
    while (student_read_txt(&s, in)) {
        student_write_bin(&s, out);
        student_print(&s);
    }
    
    student_write_bin(&s, out);
    student_print(&s);
    
    int res_classes[200];
    int cnt_classes = 0;
    
    rewind(out);
    
    while (student_read_bin(&s, out)) {
        if  ( (strcmp(s.university, "н.д.")) || (strcmp(s.regiment, "н.д.")) ) {
            res_classes[cnt_classes] = s.class_letter - 65;
            cnt_classes++;
        }
    }
    
    fclose(in);
    fclose(out);
    
    if (cnt_classes == 0) {
        printf("Отсутсвуют классы, выпускники котрых поступили в ВУЗ / были призваны на военную службу\n");
        return 0;
    }
    
    sort(res_classes, cnt_classes);

    int prev = res_classes[0];
    
    printf("Классы, выпускники котрых поступили в ВУЗ / были призваны на военную службу:\n");

    printf("11 %c класс\n", prev + 65);
    for (int i = 1; i < cnt_classes; ++i) {
        if (res_classes[i] != prev) {
            printf("11 %c класс\n", (res_classes[i] + 65));
        }
        prev = res_classes[i];
    }
    
    return 0;
}
