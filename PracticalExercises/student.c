#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;  // name of student
    char ID[7];  // student ID (nul terminated)
} Student;

typedef struct {
    char* name;                 // name of the course
    Student* students;          // list of students
    unsigned int num_students;  // total number of student attending the course
} Course;

/* 'add_student' adds student by name 'name' and student number 'ID' to the student database that
 * is indicated by 'Course' structure c;
 */
void add_student(Course* c, const char* name, const char* ID) {
    Student* new_list = realloc(c->students, (c->num_students + 1) * sizeof(Student));
    int num = c->num_students;
    Student* new_student = &new_list[num];
    new_student->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(new_student->name, name);
    printf("%s ", ID);
    strcpy(new_student->ID, ID);
    printf("new_student ID %s", new_student->ID);
    c->students = new_list;
    printf("new_student ID %s\n", (&c->students[c->num_students])->ID);
    c->num_students += 1;
}

/*
 * 'remove_student' remoes the given student 'ID' from Student list 'c'.
 */
void remove_student(Course* c, const char* ID) {
    int num = c->num_students;
    unsigned int exist = 0;

    for (unsigned int i = 0; i < num; i++) {
        Student* student = &c->students[i];
        if (!strcmp(student->ID, ID)) {
            exist = i;
            free(student->name);
        }
    }

    // if (exist) {
    //     Student* new_list = calloc((num - 1), sizeof(Student));
    //     unsigned int count = 0;
    //     for (unsigned int i = 0; i < num - 1; i++) {
    //         Student* student = &c->students[i];
    //         Student* new = &new_list[count];
    //         if (i != exist) {
    //             //memcpy(new, student, sizeof(Student));
    //             new->name = malloc((strlen(student->name) + 1) * sizeof(char));
    //             strcpy(new->name, student->name);
    //             strcpy((&new_list[count])->ID, ID);
    //             count++;
    //             free(student->name);
    //             // free(student);
    //         }
    //     }
    //     free(c->students);
    //     c->students = new_list;
    //     if (c->num_students > 0) {
    //         c->num_students -= 1;
    //     }
    //     new_list = NULL;
    // }
}

int main(void) {

    // Receive input from user for the name of the course.
    char course[20];
    printf("Which course do you want to choose? (Press q to exit) ");
    while (!scanf("%s", course)) { }
    // Exit the program if the user press 'q'.
    if (!strcmp(course, "q")) {
        return EXIT_SUCCESS;
    }

    // Initialize a course.
    Course* c = malloc(sizeof(Course));
    if (c == NULL) {
        printf("Failed to initialize course record. Exit.");
    }

    // Assign name to the course
    c->name = malloc((strlen(course) + 1) * sizeof(char));
    strcpy(c->name, course);
    c->num_students = 0;
    c->students = malloc(sizeof(Student));

    // Receive students' names and IDs from the user.
    while (1) {
        char name[30];
        char ID[7];
        char action[1];
        printf("What is the student's name? ");
        while (!scanf("%s", name)) { }
        if (!strcmp(name, "q")) {
            break;
        }

        printf("What is the student's ID? ");
        while (!scanf("%s", ID)) { }
        // printf("Student %s, ", name);
        // printf("ID %s.\n", ID);

        // Check what the user wants to do.
        printf("Do you want to add or remove the student? (a or r) ");
        while (!scanf("%s", action)) { }
        if (!strcmp(action, "a")) {
            add_student(c, name, ID);
        }
        else if (!strcmp(action, "r")) {
            remove_student(c, ID);
        }
        else {
            printf("Action %s not found. Add student as default...", action);
            add_student(c, name, ID);
        }
    }

    printf("The course %s has %d students.\n", c->name, c->num_students);
    printf("Student name \t | \t Student ID\n");

    for (unsigned int i = 0; i < c->num_students; i++) {
        Student* student = &c->students[i];
        printf("%s \t \t %s\n", student->name, student->ID);
    }

    for (unsigned int i = 0; i < c->num_students; i++) {
        Student* student = &c->students[i];
        free(student->name);
    }

    free(c->students);
    free(c->name);
    free(c);

    return EXIT_SUCCESS;
}
