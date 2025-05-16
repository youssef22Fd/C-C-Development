/*
 * Simple File Management Program
 *
 * This program provides a menu-driven interface to perform basic file operations:
 * creating, reading, and deleting text files. It allows users to interact with the
 * filesystem in a simple and intuitive way using standard C file I/O functions.
 *
 * Features:
 * - Create a file with custom content entered by the user
 * - Read and display the contents of an existing file
 * - Delete a file by specifying its name
 * - Menu-based system for selecting operations
 *
 * Functions:
 * - displayMenu() : Displays the available file operations
 * - createFile()  : Prompts user to create and write to a new file
 * - readFile()    : Reads and displays contents from a specified file
 * - deleteFile()  : Deletes a specified file from the system
 *
 * Constants:
 * - MAX_FILENAME : Maximum allowed characters for the filename
 * - MAX_CONTENT  : Maximum allowed characters for file content
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_CONTENT 1024



void createFile();
void readFile();
void deleteFile();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {

    printf("*******************************************\n");
    printf("   Create File click on         :        1\n");
    printf("   Read a File click on         :        2\n");
    printf("   Delete a File click on       :        3\n");
    printf("   Exit the application click on:        4\n");
    printf("*******************************************\n");
    printf("Enter your application here: ");
}

void createFile() {
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];

    printf("\nEnter the filename to create: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; 

    printf("Enter the content to write in the file: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = 0;

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file\n");
        return;
    }

    fprintf(file, "%s\n", content);
    fclose(file);
    printf("\nFile %s created successfully.\n", filename);
}

void readFile() {
    char filename[MAX_FILENAME];
    char content[MAX_CONTENT];

    printf("\nEnter the filename to read: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; 

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error reading file\n");
        return;
    }

    printf("Contents of %s :\n", filename);
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }
    fclose(file);
}

void deleteFile() {
    char filename[MAX_FILENAME];

    printf("\nEnter the filename to delete: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    if (remove(filename) == 0) {
        printf("\nFile %s deleted successfully.\n", filename);
    } else {
        perror("Error deleting file\n");
    }
}
