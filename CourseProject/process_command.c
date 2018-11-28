#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "courses_record.h"

unsigned int process_command(char* buf, char** command) {
    unsigned int count = 0;
    char* token;

    token = strtok(buf+2, " \n");

    while (token != NULL) {
        *(command + count) = token;
        count++;
        token = strtok(NULL, " \n");
    }
    return count;
}

int do_command(Course* course, char* buf)
{
    // Allocate memory for the command
    char** command;
    command = malloc(5 * sizeof(char*));
    unsigned int count = 0;
    count = process_command(buf, command);
    // for (unsigned int i = 0; i < count; i++) {
    //     printf("%s\n", command[i]);
    // }

    // Detect the command and implement the corresponding function.
    switch ((int)buf[0]) {
        case 'A':       // Add student record
            if (count >= 3) {
                printf("Adding student %s %s ...\n", command[1], command[2]);
                add_student(course, command[0], command[1], command[2]);
            }
            else {
                printf("Not enough argument. Please try again.\n");
            }
            break;
        case 'U':       // Update point for a round
            if (count >= 3) {
                printf("Updating point of round %s for student number %s ...\n", command[1], command[0]);
                update_point(course, command[0], atoi(command[1]), atoi(command[2]));
            }
            else {
                printf("Not enough argument. Please try again.\n");
            }
            break;
        case 'L':       // Print students in descending order of total points
            printf("Print all the students in descending order of total points.\n");
            print_points(course);
            break;
        case 'W':       // Save the result to a file
            if (count >= 1) {
                printf("Save the results to file %s...\n", command[0]);
                save_results(course, command[0]);
            }
            else {
                printf("Not enough argument. Please try again.\n");
            }
            break;
        case 'O':       // Load the result from a file
            if (count >= 1) {
                printf("Load the results from file %s.\n", command[0]);
                save_results(course, command[0]);
            }
            else {
                printf("Not enough argument. Please try again.\n");
            }
            break;
        case 'Q':       // Exit the program
            printf("Quit the program...\n");
            free(command);
            command = NULL;
            exit_program(course);
            /* Note: To prevent "Invalid free" when test with valgrind
              - Set the pointer to NULL after free the memory
              - Run exit_program() either here or in main() and no need to set the pointer to NULL */
            return 0;
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    free(command);

    return 1;
}
