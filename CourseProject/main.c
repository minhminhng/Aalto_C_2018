#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courses_record.h"

int main(void) {
    Course new_course;
    char* name = "Programming";
    new_course.name = malloc((sizeof(char) + 1) * strlen(name));
    strcpy(new_course.name, name);

    new_course.students = malloc(sizeof(Student));
    new_course.num_students = 0;

    int in_course = 1;

    while (in_course) {
        char buffer[80];
        printf("command > ");
        fgets(buffer, sizeof(buffer), stdin);
        in_course = do_command(&new_course, buffer);
    }

    exit_program(&new_course);

    return EXIT_SUCCESS;
}
