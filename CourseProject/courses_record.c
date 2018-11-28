#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courses_record.h"

/* Add a new student to the course with id, first_namew last_name.
 */
void add_student(Course* course, char* id, char* first_name, char* last_name) {

    course->students = realloc(course->students, (course->num_students+ 1) * sizeof(Student));

    Student* student = &course->students[course->num_students];
    course->num_students += 1;

    // Assign new id
    strcpy(student->id, id);

    // Assign first_name
    student->first_name = malloc((strlen(first_name) + 1) * sizeof(char));
    strcpy(student->first_name, first_name);

    // Assign last_name
    student->last_name = malloc((strlen(last_name) + 1) * sizeof(char));
    strcpy(student->last_name, last_name);
    for (unsigned int i = 0; i < 6; i++) {
        student->points[i] = 0;
    }
    student->total_point = 0;
}

/*
 * Check if a student ID exists otherwise yield an error message.
 */
int isExist(Course* course, char* id) {
    for (int i = 0; i < course->num_students; i++) {
        if (strcmp((&course->students[i])->id, id) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Uupdate the point of the round 'round' for student whose ID is 'id'.
 */
void update_point(Course* course, char* id, int round, int point) {
    int n;
    n = isExist(course, id);

    if (n > -1) {
        (&course->students[n])->points[round - 1] = point;
        (&course->students[n])->total_point += point;
    }
    else {
        printf("The student number does not exit.");
    }
}

int compare_points(const void* a, const void* b) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    return s2->total_point - s1->total_point;
}

void print_points(Course* course) {

    printf("Student \t | \t ID \t | \t  Round 1 2 3 4 5 6 \t | \t Total point\n");

    qsort(course->students, course->num_students, sizeof(Student), compare_points);

    for (unsigned int i = 0; i < course->num_students; i++) {
        Student* student = &course->students[i];
        printf("%s %-20s  %-20s\t",
                student->first_name, student->last_name, student->id);
        for (unsigned int j = 0; j < 6; j++) {
            printf("%d ", student->points[j]);
        }
        printf("\t \t %d\n", student->total_point);
    }
}

void save_results(Course* course, char* file) {
    FILE* f = fopen(file, "w");
    if (f == NULL) {
        printf("Cannot save the results.");
    }

    fprintf(f, "Student \t\t | \t ID \t | \t  Round 1 2 3 4 5 6 \t | \t Total point\n");
    for (unsigned int i = 0; i < course->num_students; i++) {
        Student* student = &course->students[i];
        fprintf(f, "%s %-20s  %-15s ",
                student->first_name, student->last_name, student->id);
        for (unsigned int j = 0; j < 6; j++) {
            fprintf(f, "%d ", student->points[j]);
        }
        fprintf(f, "\t \t \t%d\n", student->total_point);
    }
    fclose(f);
}

// Load the results from file, and replace the existng results in memory.
void load_results(Course* course, char* file) {
    FILE* f = fopen(file, "r");
    if (f == NULL) {
        printf("Cannot load the results.");
    }
    char first_name[20];
    char last_name[20];
    char id[7];
    int points[6];
    int total_point;
    unsigned int count = 0;
    fscanf(f, "%*[^\n]\n", NULL);

    while (fscanf(f, "%s %s %s %d %d %d %d %d %d %d", first_name, last_name, id,
                &points[0], &points[1], &points[2], &points[3], &points[4], &points[5], &total_point)) {
        add_student(course, id, first_name, last_name);
        printf("Loading student %d ", count + 1);
        memcpy((&course->students[count])->points, &points, 6 * sizeof(int));
        (&course->students[count])->total_point = total_point;
        count++;
    }
    fclose(f);
}

// Exit program and release all allocated memory.
void exit_program(Course* course) {
    if (course->name) {
        free(course->name);
        course->name = NULL;        // * Note: free does not return a NULL pointer;
    }
    if (course->students != NULL) {
        for (unsigned int i = 0; i < course->num_students; i++) {
            free((&course->students[i])->first_name);
            free((&course->students[i])->last_name);
        }
        free(course->students);
        course->students = NULL;
    }
}
