#include <stdio.h>
#include <string.h>

int main(void)
{
    // easy to buffer overflow this way but whatever
    char str_buffer[1000];
    char *name = str_buffer;
    int age;
    float marks;

    printf("enter your name: ");
    scanf("%[^\n]%*c", name); // name

    printf("enter your age: ");
    scanf("%d%*c", &age);

    // pointer to a gender string in the same buffer
    char *gender = &name[strlen(name) + 2];
    printf("enter your gender: ");
    scanf("%[^\n]%*c", gender); // gender

    printf("enter your 12th total marks: ");
    scanf("%f", &marks);

    // displaying
    printf("\n");
    printf("name: %s\nage: %d\ngender: %s\n12th marks: %.2f\n", name, age,
           gender, marks);
}