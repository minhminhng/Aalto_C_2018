# File basics

Objective: Practice basic file reading.

The first simple task is to open a file and print it to the standard output. Other task is to implement a basic diff-tool that tells the first line is different within two files.

* Implement function `int print_file(const char *filename)` that prints the file into the standard output. Function should return the number of characters printed. If file opening fails, function should return -1.

* Implement function `char *difference(const char* file1, const char* file2)` that compares two files. The function should return the first lines that differ in the two files, concatenated together, separated by four dashes, see example below. If the files are equal, NULL is returned. Function stops immediately, if either one of the files end and returns NULL.
