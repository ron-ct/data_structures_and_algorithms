#include <stdio.h>
#include <string.h>

// Define structures
struct Course {
    char course_code[10];
    char course_name[30];
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    char reg_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grades;
    int grades_calculated; // Flag to check if grades are calculated
};

// Function declarations
void addStudent(struct Student students[], int *num_students);
void editStudent(struct Student students[], int num_students);
void addMarksAndCalculateGrades(struct Student students[], int num_students);
void displayStudents(struct Student students[], int num_students);

int main() {
    struct Student students[40];
    int num_students = 0;
    int choice;

    do {
        printf("\n1. Add Student\n2. Edit Student\n3. Add Marks and Calculate Grades\n4. Display Students\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                editStudent(students, num_students);
                break;
            case 3:
                addMarksAndCalculateGrades(students, num_students);
                break;
            case 4:
                displayStudents(students, num_students);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void addStudent(struct Student students[], int *num_students) {
    if (*num_students < 40) {
        printf("Enter registration number: ");
        scanf("%s", students[*num_students].reg_number);

        printf("Enter name: ");
        scanf("%s", students[*num_students].name);

        printf("Enter age: ");
        scanf("%d", &students[*num_students].age);

        printf("Enter course code: ");
        scanf("%s", students[*num_students].course.course_code);

        printf("Enter course name: ");
        scanf("%s", students[*num_students].course.course_name);

        (*num_students)++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void editStudent(struct Student students[], int num_students) {
    char reg_number[20];
    int found = 0;

    printf("Enter registration number of the student to edit: ");
    scanf("%s", reg_number);

    for (int i = 0; i < num_students; i++) {
        if (strcmp(reg_number, students[i].reg_number) == 0) {
            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new course code: ");
            scanf("%s", students[i].course.course_code);

            printf("Enter new course name: ");
            scanf("%s", students[i].course.course_name);

            printf("Student details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void addMarksAndCalculateGrades(struct Student students[], int num_students) {
    char reg_number[20];
    int found = 0;

    printf("Enter registration number of the student: ");
    scanf("%s", reg_number);

    for (int i = 0; i < num_students; i++) {
        if (strcmp(reg_number, students[i].reg_number) == 0) {
            if (!students[i].grades_calculated) {
                printf("Enter marks: ");
                scanf("%d", &students[i].grades.mark);

                if (students[i].grades.mark > 69) {
                    students[i].grades.the_grade = 'A';
                } else if (students[i].grades.mark > 59) {
                    students[i].grades.the_grade = 'B';
                } else if (students[i].grades.mark > 49) {
                    students[i].grades.the_grade = 'C';
                } else if (students[i].grades.mark > 39) {
                    students[i].grades.the_grade = 'D';
                } else {
                    students[i].grades.the_grade = 'E';
                }

                students[i].grades_calculated = 1;
                printf("Grades calculated and added successfully!\n");
            } else {
                printf("Grades already calculated for this student.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void displayStudents(struct Student students[], int num_students) {
    printf("Registered Students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Registration Number: %s\n", students[i].reg_number);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Course Code: %s\n", students[i].course.course_code);
        printf("Course Name: %s\n", students[i].course.course_name);
        printf("Marks: %d\n", students[i].grades.mark);
        printf("Grade: %c\n", students[i].grades.the_grade);
    }
}