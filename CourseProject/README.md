Implement a system that tracks the exercise points for a course. The course has six exercise rounds, for which points are tracked separately. For each student, the system will store a student number, first name and last name, and the points for six exercise rounds as integers. For strings the system should store at least 20 characters, but you can decide  yourself how to handle longer strings. You can assume that the student number is at most 6 characters long. The program should support arbitrarily large number of students.

System has the following functions:

* *A number lastname firstname* : **Add student** : Adds a student by given student number to the database. Initially the student
has 0 points. For example: `A 234567 Opiskelija Osmo`
* *U number round points *: Update points : Sets the points for exercise round "round". You can assume that there are at most 6 exercise rounds. The points will be integers. If the given student number does not exist, an error message should be given.
* *L* : **Print points** : Prints the stored students, with their student number, last name and first name, along with points of each exercise round and total points. The students should be printed in the order of total points such that the student with most total points will be printed first.
* W filename : Save results : Writes the results to a file with given filename.
* O filename : Load results : Loads the results from file, and replaces the existing results in memory.
* Q : Exit program: Exits program and releases all allocated memory. This operation must be implemented so that you can find all possible memory leaks.

In addition to the above commands, there should be a working main function that repeatedly asks commands from user and acts accordingly. The commands start with one captial letter and may be followed by some number of parameters, separated by space, depending on the command. Below is an example of possible input sequence:

```
A 234567 Opiskelija Osmo
A 111111 Ahkera Antti
U 234567 1 7
U 111111 1 14
U 111111 2 12
L
W pisteet
Q
```
As a result, Osmo Opiskelija will have altogether 7 points, and Antti Ahkera a total of 26 points. In the results table Antti Ahkera will be output first, and the the score database will be stored to file "pisteet".

The program is compiled using `gcc -Wvla -Wall -g -std=c99`

### Note
* Remember to allocate memory for string with an extra for '\0' character.
* When free a pointer, the pointer is still valid, so if you need to compare it, change the pointer to NULL. Pay attention when the error "Invalid free()" is yielded by valgrind.
* Remember to initialize the values.
* Remember to check the consistency of data type.
* `fscanf(f, "%*[^\n]\n", NULL);`is useful to ignore lines in a stream  [(http://www.cplusplus.com/reference/cstdio/fscanf/)](http://www.cplusplus.com/reference/cstdio/fscanf/)
