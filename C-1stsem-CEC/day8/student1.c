#include <stdio.h>
#include <string.h>

#define MAX 100   // maximum number of students

// Structure to store student details
struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: addStudent(); break;
        case 2: displayStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateStudent(); break;
        case 5: deleteStudent(); break;
        case 6: 
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// ======================= ADD STUDENT =======================
void addStudent() {
    if (count >= MAX) {
        printf("Cannot add more students. List is full.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n");
}

// ======================= DISPLAY STUDENTS =======================
void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               students[i].roll, students[i].name, students[i].marks);
    }
}

// ======================= SEARCH STUDENT =======================
void searchStudent() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Student Found:\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n",
                   students[i].roll, students[i].name, students[i].marks);
            return;
        }
    }

    printf("Student with roll %d not found.\n", roll);
}

// ======================= UPDATE STUDENT =======================
void updateStudent() {
    int roll;
    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter New Name: ");
            scanf("%s", students[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("Student details updated successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}

// ======================= DELETE STUDENT =======================
void deleteStudent() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];  // shift left
            }
            count--;
            printf("Student deleted successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}
