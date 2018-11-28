#ifndef COURSES_RECORD
#define COURSES_RECORD

typedef struct student Student;

struct student {
    char id[7];
    char* first_name;
    char* last_name;
    int points[6];
    int total_point;
    Student* next;
};

typedef struct {
    char* name;
    Student* students;      // Point to the allocated memory for the first student of the list
    unsigned int num_students;
} Course;

// Add a student by given student number to the database.
void add_student(Course* course, char* id, char* first_name, char* last_name);

// Sets the point for exercise rounds.
void update_point(Course* course, char* id, int round, int point);

// Print the stored students with their student number, last name,
// first name, points of each exercise round and the total points,
void print_points(Course* course);

// Write the results to a file with given filename.
void save_results(Course* course, char* file);

// Load the results from file, and replace the existng results in memory.
void load_results(Course* course, char* file);

// Exit program and release all allocated memory.
void exit_program(Course* course);

// Process the input from command line
unsigned int process_command(char* buf, char** command);

// Implement the command
int do_command(Course* course, char* buf);

#endif
