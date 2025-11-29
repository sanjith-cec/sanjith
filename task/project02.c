#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100   // Maximum number of vehicles

// Structure definition for Vehicle
typedef struct {
    char regNumber[20];
    char vehicleType[20];
    char ownerName[50];
    int slotNumber;
} Vehicle;

// Function prototypes
void loadFromFile(Vehicle *v, int *count);
void saveToFile(Vehicle *v, int count);
void addVehicle(Vehicle *v, int *count);
void removeVehicle(Vehicle *v, int *count);
void displayVehicles(Vehicle *v, int count);
int searchVehicle(Vehicle *v, int count, char *regNumber);

int main() {
    Vehicle vehicles[MAX];
    int count = 0;
    int choice;

    loadFromFile(vehicles, &count);

    while (1) {
        printf("\n===== PARKING MANAGEMENT SYSTEM =====\n");
        printf("1. Add Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display All Vehicles\n");
        printf("4. Search Vehicle by Registration Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline

        switch (choice) {
            case 1:
                addVehicle(vehicles, &count);
                break;
            case 2:
                removeVehicle(vehicles, &count);
                break;
            case 3:
                displayVehicles(vehicles, count);
                break;
            case 4: {
                char reg[20];
                printf("Enter Registration Number to search: ");
                fgets(reg, sizeof(reg), stdin);
                reg[strcspn(reg, "\n")] = '\0';
                int index = searchVehicle(vehicles, count, reg);
                if (index != -1) {
                    printf("\nVehicle Found:\n");
                    printf("Slot: %d | Reg: %s | Type: %s | Owner: %s\n",
                           vehicles[index].slotNumber, vehicles[index].regNumber,
                           vehicles[index].vehicleType, vehicles[index].ownerName);
                } else {
                    printf("\nVehicle not found!\n");
                }
                break;
            }
            case 5:
                saveToFile(vehicles, count);
                printf("\nData saved. Exiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

// ================== FUNCTION DEFINITIONS ==================

void addVehicle(Vehicle *v, int *count) {
    if (*count >= MAX) {
        printf("\nParking Full! Cannot add more vehicles.\n");
        return;
    }

    Vehicle newV;
    printf("Enter Registration Number: ");
    fgets(newV.regNumber, sizeof(newV.regNumber), stdin);
    newV.regNumber[strcspn(newV.regNumber, "\n")] = '\0';

    printf("Enter Vehicle Type (Car/Bike/Bus): ");
    fgets(newV.vehicleType, sizeof(newV.vehicleType), stdin);
    newV.vehicleType[strcspn(newV.vehicleType, "\n")] = '\0';

    printf("Enter Owner Name: ");
    fgets(newV.ownerName, sizeof(newV.ownerName), stdin);
    newV.ownerName[strcspn(newV.ownerName, "\n")] = '\0';

    newV.slotNumber = *count + 1; // Assign next available slot

    v[*count] = newV;
    (*count)++;

    printf("\nVehicle added successfully! Assigned Slot: %d\n", newV.slotNumber);
    saveToFile(v, *count);
}

void removeVehicle(Vehicle *v, int *count) {
    if (*count == 0) {
        printf("\nNo vehicles parked.\n");
        return;
    }

    char reg[20];
    printf("Enter Registration Number to remove: ");
    fgets(reg, sizeof(reg), stdin);
    reg[strcspn(reg, "\n")] = '\0';

    int index = searchVehicle(v, *count, reg);
    if (index == -1) {
        printf("\nVehicle not found.\n");
        return;
    }

    // Shift remaining records
    for (int i = index; i < *count - 1; i++) {
        v[i] = v[i + 1];
    }
    (*count)--;

    printf("\nVehicle removed successfully.\n");
    saveToFile(v, *count);
}

void displayVehicles(Vehicle *v, int count) {
    if (count == 0) {
        printf("\nNo vehicles parked currently.\n");
        return;
    }

    // Proper column widths (same in header and data rows)
    printf("\n%-5s %-15s %-10s %-20s\n", "Slot", "Reg.Number", "Type", "Owner");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s %-10s %-20s\n",
               v[i].slotNumber,
               v[i].regNumber,
               v[i].vehicleType,
               v[i].ownerName);
    }
}


int searchVehicle(Vehicle *v, int count, char *regNumber) {
    for (int i = 0; i < count; i++) {
        if (strcmp(v[i].regNumber, regNumber) == 0)
            return i;
    }
    return -1;
}

void saveToFile(Vehicle *v, int count) {
    FILE *fp = fopen("parking_data.txt", "w");
    if (!fp) {
        printf("\nError opening file for saving!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%s,%s\n", v[i].slotNumber, v[i].regNumber, v[i].vehicleType, v[i].ownerName);
    }

    fclose(fp);
}

void loadFromFile(Vehicle *v, int *count) {
    FILE *fp = fopen("parking_data.txt", "r");
    if (!fp) {
        // File may not exist initially, so no error
        return;
    }

    while (fscanf(fp, "%d,%19[^,],%19[^,],%49[^\n]\n", 
                  &v[*count].slotNumber, v[*count].regNumber, 
                  v[*count].vehicleType, v[*count].ownerName) != EOF) {
        (*count)++;
    }

    fclose(fp);
}
