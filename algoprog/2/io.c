#include "stdio.h"

/* 
 * Asks the user for their age and then prints it back.
 * @var {int} age - The age of the user.
 * @func printf - Write formatted output to stdout.
 * @func scanf - Read formatted input from stdin.
 */
int main() {
    int age;
    printf("Your age: ");
    scanf("%d", &age);
    printf("%d years old\n", age);
}
