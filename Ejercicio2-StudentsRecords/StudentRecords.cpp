#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *firstName;
    char *lastName;
    unsigned int age:7;
    unsigned int id:24;
    size_t numGrades;
    float *grades;
} Student;

Student* createStudent(const char *first, const char *last, unsigned int age, unsigned int id, float *grades, size_t numGrades) {
    Student *s = (Student *)malloc(sizeof(Student));
    if (!s) {
        fprintf(stderr, "Memory allocation failed for student\n");
        exit(EXIT_FAILURE);
    }

    s->firstName = (char *)malloc(strlen(first) + 1);
    strcpy(s->firstName, first);

    s->lastName = (char *)malloc(strlen(last) + 1);
    strcpy(s->lastName, last);

    s->age = age;
    s->id = id;

    s->numGrades = numGrades;
    s->grades = (float *)malloc(numGrades * sizeof(float));
    if (grades && numGrades > 0) {
        for (size_t i = 0; i < numGrades; i++) {
            s->grades[i] = grades[i];
        }
    }

    return s;
}

void deleteStudent(Student *s) {
    if (s) {
        free(s->firstName);
        free(s->lastName);
        free(s->grades);
        free(s);
    }
}

void printStudent(const Student *s) {
    if (!s) return;
    printf("ID: %u | Name: %s %s | Age: %u\n", s->id, s->firstName, s->lastName, s->age);
    printf("Grades: ");
    for (size_t i = 0; i < s->numGrades; i++) {
        printf("%.2f ", s->grades[i]);
    }
    printf("\n");
}

int main() {

    float grades1[] = {90.5, 85.0, 78.5};
    float grades2[] = {88.0, 92.0};

    Student *student1 = createStudent("Alice", "Johnson", 20, 1001, grades1, 3);
    Student *student2 = createStudent("Bob", "Smith", 22, 1002, grades2, 2);

    printStudent(student1);
    printStudent(student2);

    deleteStudent(student1);
    deleteStudent(student2);

    return 0;
}
