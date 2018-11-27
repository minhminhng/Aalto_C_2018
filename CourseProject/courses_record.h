#ifndef COURSES
#define COURSES

typedef struct {
    char* student_ID[7];
    char* first_name;
    char* last_name;
    unsigned int points[6];
} Student;

// Add a student by given student number to the database.
Student* add_student(Student* student);

// Sets the point for exercise rounds.
void update_point(char* ID, unsigned int round, unsigned int point);

// Print the stored students with their student number, last name,
// first name, points of each exercise round and the total points,
void print_points(Student* students);

#endif
