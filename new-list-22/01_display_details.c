#include <stdio.h>
#include <string.h>

int main(void)
{
    // easy to buffer overflow this way but whatever
    char str_buffer[1000];
    char *_name = str_buffer;
    char *_gender;
    int age;
    float marks;

    printf("enter your name: ");
    scanf("%[^\n]s%*c", _name); // name

    printf("enter your age: ");
    scanf("%d%*c", &age);

    // pointer to a gender string in buffer
    _gender = _name + strlen(_name) + 2;
    printf("enter your gender: ");
    scanf("%[^\n]s%*c", _gender); // gender

    printf("enter your 12th total marks: ");
    scanf("%f", &marks);

    // displaying
    printf("\n");
    printf("name: %s\nage: %d\ngender: %s\n12th marks: %.2f\n", _name, age,
           _gender, marks);
}