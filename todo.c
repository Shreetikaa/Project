#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    char description[100];
    int completed;
} Task;

void displayMenu();
void addTask(Task tasks[], int *numTasks);
void markCompleted(Task tasks[], int numTasks);
void deleteTask(Task tasks[], int *numTasks);
void listTasks(Task tasks[], int numTasks);

int main() {
    Task tasks[MAX_TASKS];
    int numTasks = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &numTasks);
                break;
            case 2:
                markCompleted(tasks, numTasks);
                break;
            case 3:
                deleteTask(tasks, &numTasks);
                break;
            case 4:
                listTasks(tasks, numTasks);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\nTo-Do List Application Menu\n");
    printf("1. Add Task\n");
    printf("2. Mark Task as Completed\n");
    printf("3. Delete Task\n");
    printf("4. List Tasks\n");
    printf("5. Exit\n");
}

void addTask(Task tasks[], int *numTasks) {
    if (*numTasks < MAX_TASKS) {
        printf("Enter task description: ");
        getchar(); 
        fgets(tasks[*numTasks].description, sizeof(tasks[*numTasks].description), stdin);
        tasks[*numTasks].description[strcspn(tasks[*numTasks].description, "\n")] = '\0'; // Remove newline
        tasks[*numTasks].completed = 0; 
        (*numTasks)++;
        printf("Task added successfully.\n");
    } else {
        printf("Maximum number of tasks reached. Cannot add more tasks.\n");
    }
}

void markCompleted(Task tasks[], int numTasks) {
    int index;
    printf("Enter the index of the task you want to mark as completed: ");
    scanf("%d", &index);

    if (index >= 0 && index < numTasks) {
        tasks[index].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void deleteTask(Task tasks[], int *numTasks) {
    int index;
    printf("Enter the index of the task you want to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < *numTasks) {
        for (int i = index; i < *numTasks - 1; i++) {
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }
        (*numTasks)--;
        printf("Task deleted successfully.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

void listTasks(Task tasks[], int numTasks) {
    printf("Tasks Left to Do:\n");
    for (int i = 0; i < numTasks; i++) {
        if (!tasks[i].completed) {
            printf("%d. %s\n", i + 1, tasks[i].description);
        }
    }
}
