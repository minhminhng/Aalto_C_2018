# Calculator

Implementing two functions:
* void **simple_multiply**(void) - asks the user for two integers, multiplies both and prints the result in the following format:
```
1 * 2 = 2
```
* void simple_math(void) - asks three values from the user: number, operator, and another number. If some other character is used as operator, the function should print "ERR" (without quotes). The numbers should be float type. If user does not type a valid number-operator-number combination, the function should print "ERR". When valid input is given, the function performs the calculation as given, and prints the result on the screen, using the **precision of one decimal**:

```
8 - 2  (user input)
6.0  (answer)

8.3 / 5.1  (user input)
1.6  (answer)

-3.456 - 2.31  (user input)
-5.8  (answer)
```
