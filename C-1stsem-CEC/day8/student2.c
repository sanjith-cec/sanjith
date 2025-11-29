#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50

/* Student structure */
struct Student {
    int roll;
    char name[NAME_LEN];
    float marks;
};

/* Dynamic array variables */
struct Student *students = NULL;
int count = 0;      // number of students currently stored
int capacity = 0;   // allocated capacity of the students array

/* Helpers */
void safe_readline(char *buf, int len) {
    if (fgets(buf, len, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0'; // remove newline
}

void ensure_capacity() {
    if (capacity == 0) {
        capacity = 2;
        students = (struct Student *)malloc(capacity * sizeof(struct Student));
        if (students == NULL) {
            printf("Memory allocation failed. Exiting.\n");
            exit(1);
        }
    } else if (count >= capacity) {
        capacity *= 2;
        struct Student *tmp = (struct Student *)realloc(students, capacity * sizeof(struct Student));
        if (tmp == NULL) {
            printf("Memory reallocation failed. Exiting.\n");
            free(students);
            exit(1);
        }
        students = tmp;
    }
}

int findIndexByRoll(int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) return i;
    }
    return -1;
}

/* Operations */
void addStudent() {
    ensure_capacity();

    struct Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    while (getchar() != '\n') {} // clear newline

    if (findIndexByRoll(s.roll) != -1) {
        printf("A student with roll %d already exists.\n", s.roll);
        return;
    }

    printf("Enter Name: ");
    safe_readline(s.name, NAME_LEN);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    while (getchar() != '\n') {} // clear newline

    students[count++] = s;
    printf("Student added successfully. (Total: %d)\n", count);
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List (Total: %d) ---\n", count);
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               students[i].roll, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    while (getchar() != '\n') {}

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        printf("Student with roll %d not found.\n", roll);
    } else {
        printf("Found -> Roll: %d | Name: %s | Marks: %.2f\n",
               students[idx].roll, students[idx].name, students[idx].marks);
    }
}

void updateStudent() {
    int roll;
    printf("Enter roll number to update: ");
    scanf("%d", &roll);
    while (getchar() != '\n') {}

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter New Name (leave blank to keep \"%s\"): ", students[idx].name);
    char buffer[NAME_LEN];
    safe_readline(buffer, NAME_LEN);
    if (buffer[0] != '\0') {
        strncpy(students[idx].name, buffer, NAME_LEN - 1);
        students[idx].name[NAME_LEN - 1] = '\0';
    }

    printf("Enter New Marks (enter -1 to keep %.2f): ", students[idx].marks);
    float m;
    if (scanf("%f", &m) == 1) {
        if (m >= 0.0f) students[idx].marks = m;
    }
    while (getchar() != '\n') {}

    printf("Student details updated successfully!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    while (getchar() != '\n') {}

    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int j = idx; j < count - 1; j++) {
        students[j] = students[j + 1];
    }
    count--;
    printf("Student deleted successfully! (Total now: %d)\n", count);

    // Optional: shrink capacity if too large (kept simple, not required)
}

int main() {
    int choice;
    while (1) {
        printf("\n===== Student Management (Dynamic) =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n') {} // clear bad input
            printf("Invalid input. Try again.\n");
            continue;
        }
        while (getchar() != '\n') {} // clear newline

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6:
                printf("Exiting...\n");
                free(students);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
