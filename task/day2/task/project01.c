// Student_Registration_form
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure to store student information
struct Student {
    int roll;
    char name[50];
    float marks;
};


// Function prototypes
void addStudent(struct Student *s, int *count);
void displayStudents(struct Student *s, int count);
void searchStudent(struct Student *s, int count);
void saveToFile(struct Student *s, int count);
void loadFromFile(struct Student *s, int *count);


int main() {
    struct Student students[100]; // array of structure
    int count = 0;
    int choice;


    // Load records from file when program starts
    loadFromFile(students, &count);


    while (1) {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Save Records to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline


        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                saveToFile(students, count);
                break;
            case 5:
                saveToFile(students, count);
                printf("\nExiting program... Records saved successfully.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }


    return 0;
}


// Function to add a new student
// Function to add a new student
// Function to add a new student
void addStudent(struct Student *s, int *count) {
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*count].roll);


    // Clear the input buffer before using fgets
    while (getchar() != '\n'); // flush remaining newline


    printf("\nEnter Name: ");
    fgets(s[*count].name, sizeof(s[*count].name), stdin);
    s[*count].name[strcspn(s[*count].name, "\n")] = '\0'; // remove newline


    printf("\nEnter Marks: ");
    scanf("%f", &s[*count].marks);


    (*count)++;
    printf("\nStudent added successfully!\n");
}






// Function to display all students
// Function to display all students
void displayStudents(struct Student *s, int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }


    printf("\n===== STUDENT LIST =====\n");


    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("----------------------\n");
        printf("Roll Number : %d\n", s[i].roll);
        printf("Name        : %s\n", s[i].name);
        printf("Marks       : %.2f\n", s[i].marks);
    }


    printf("\n----------------------\nTotal Students: %d\n", count);
}






// Function to search student by roll number
// Function to search student by roll number
void searchStudent(struct Student *s, int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }


    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);


    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("\n===== STUDENT DETAILS =====\n");
            printf("Roll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            printf("Marks   : %.2f\n", s[i].marks);
            return;
        }
    }


    printf("No student found with Roll Number %d\n", roll);
}




// Function to save data to file
// Function to save data to file
void saveToFile(struct Student *s, int count) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("\nError opening file for writing!\n");
        return;
    }


    for (int i = 0; i < count; i++) {
        // Write each student record to file in CSV format
        fprintf(fp, "%d,%s,%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }


    fclose(fp);
    printf("\nRecords saved successfully to file.\n");
}




// Function to load data from file
// Function to load data from file
void loadFromFile(struct Student *s, int *count) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("\nNo previous records found. Starting fresh.\n");
        return;
    }


    *count = 0; // reset count before loading


    while (fscanf(fp, "%d,%49[^,],%f\n", &s[*count].roll, s[*count].name, &s[*count].marks) == 3) {
        (*count)++;
    }


    fclose(fp);
    printf("\n%d student record(s) loaded from file.\n", *count);
}
