# Macros
Implement two macros:
1. `EQ3(a,b,c)` takes three parameters and evaluates their equality. Evaluates to 1 if all parameters are equal (==) to each other. Evaluates to 0 otherwise. May evaluate any parameter more than once.

2. `MIN3(a,b,c)` that evaluates which one of the parameters is smallest. Returns the smallest one.

# Printer: variable length argument lists
Implement function **myprint** that prints a variable number of integers to standard output stream following the format indicated by a given format string. The function can take variable number of arguments: ***the first argument is always a*** (constant) ***format string*** (as in printf), but the number of other arguments depends on the format string. Our output function is a simpler version of printf: it can only print integers. myprint differs from traditional printf by using character & as the format specifier that should be substituted by the integer indicated at the respective position in the argument list. Because we only output integers, this simple format specifier will suffice.

For example, this is one valid way of calling the function: `myprint("Number one: &, number two: &\n", 120, 1345);`

The function should return an integer, that indicates how many format specifiers (and integer arguments) were included in the given format string.

# Function pointers
Practise the use of two standard function pointers: `qsort` and `bsearch`. As a help we use the same scheme as in last round's task "Shop". This time the shopkeeper should implement a system, which allows them to sort their products alphabetically or sort them in descending order depending on how many products are in stock. The product structure is implemented so that the last element's name's first character is the terminating null character (\0).

Implement two comparing functions: `compareAlpha` and `compareNum`, which compare products according to their name and availability (in_stock), respectively. `compareAlpha` returns the return value of `strcmp`. `compareNum` returns a negative value if the product b should come before a, and vice versa. If the in_stock-values of the products are equal, the order is determined according to `compareAlpha`.

Implement the search function `findProduct`, which searches for a product in a Product-array using the `bsearch`-function. It returns the return value of `bsearch`. Note that the parameter `searchkey` is the name of a product to be found, and it shouldn't be given directly to `bsearch` because the key has to be of the same data type as the elements in the list. The interfaces of these functions are explained in the header file. A small testing program is given with `main.c` and the function declarations and the interfaces explained in the `shopfunctions.h` header file.
