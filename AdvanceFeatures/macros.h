#ifndef AALTO_MACROS
#define AALTO_MACROS

// Define a macro which takes three parameters and evaluates their equality.
#define EQ3(a, b, c)  ((a == b) && (a == c) ? 1:0)

// Define a macro which evaluates which one of the parameters is smallest.
#define MIN3(a, b, c) (((c <= a) && (c <= b)) ? c : (((b <= a) && (b <= c)) ? b : a))
#endif
