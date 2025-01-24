#include <stdio.h>

// Define a structure for a student
struct Student
{
    int id;
    char name[50];
    float marks;
};

int main()
{
    struct Student s1 = {1, "John Doe", 85.5}; // Initialize the structure

    printf("Student Details:\n");
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}