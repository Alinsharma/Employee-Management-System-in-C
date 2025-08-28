#include <stdio.h>
#include <string.h>

#define MAX 100


struct Employee {
    int id;
    char name[50];
    float salary;
};


struct Employee employees[MAX];
int count = 0;


void addEmployee() {
    if (count < MAX) {
        printf("Enter Employee ID: ");
        scanf("%d", &employees[count].id);

        printf("Enter Employee Name: ");
        getchar(); 
        fgets(employees[count].name, sizeof(employees[count].name), stdin);
        employees[count].name[strcspn(employees[count].name, "\n")] = '\0'; 

        printf("Enter Employee Salary: ");
        scanf("%f", &employees[count].salary);

        count++;
        printf("Employee added successfully!\n");
    } else {
        printf("Employee list is full!\n");
    }
}


void displayEmployees() {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}


void searchEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Employee Found: ID: %d | Name: %s | Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}


void updateEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new name: ");
            getchar();
            fgets(employees[i].name, sizeof(employees[i].name), stdin);
            employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);

            printf("Employee updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}

void deleteEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            printf("Employee deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}


int main() {
    int choice;

    do {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
