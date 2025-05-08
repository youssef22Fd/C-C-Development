/*
 * Student Records Management System
 *
 * This program allows the user to manage a set of student records through a text-based interface.
 * The features are :
 * - View all student records
 * - Add a new student record with duplicate ID checking
 * - Delete a student record by setting their ID to 0.
 * - Load student records from a file at startup
 * - Save records to a file on exit
 * Each student record includes:
 * - ID (unique identifier)
 * - Name
 * - Date of birth
 * - Branch (field of study)
 * - Grade 
 * Functions:
 * - display_menu(): Displays user options
 * - read_menu(): Reads the user's choice
 * - menu_bar(): Executes logic based on menu selection
 * - Display_records(): Prints all non-empty student records
 * - check_student_ID(): Checks for duplicate student ID
 * - Add_new_record(): Prompts and adds a new record
 * - Delete_record(): Removes a record by resetting its fields
 * - Save_records_to_file(): Saves records to "students.txt"
 * - Load_records_from_file(): Loads existing records from "students.txt"
 *
 */



#include <stdio.h>
#include <string.h>

typedef struct
{
    int ID;
    char name[50];
    char date_of_birth[11];
    char branch[50];
    float grade;
}student_record_t;

int number_of_records = 50;
student_record_t students[50];

void display_menu();
int read_menu();
void menu_bar();
void Display_records(student_record_t *record, int number_of_records);
int check_student_ID(int student_ID, student_record_t *record, int number_of_records);
int Add_new_record(student_record_t *record, int number_of_records);
int Delete_record(student_record_t *record, int number_of_records);
void Load_records_from_file(student_record_t *record, int *number_of_records);
void Save_records_to_file(student_record_t *record, int number_of_records);

int main()
{
    int menu_code;
    int continue_record = 0;

    Load_records_from_file(students, &number_of_records);

    while (!continue_record)
    {
        display_menu();
        menu_code = read_menu();
        if (menu_code != 4)
            menu_bar(menu_code);
        else 
        {
            continue_record = 1;
            printf("Saving records and exiting application...\n");
            Save_records_to_file(students, number_of_records);
        }
    }
    return 0;
}



void display_menu()
{
    printf("Display all records click on:    1\n");
    printf("Add a new record click on:       2\n");
    printf("Delete a record click on:        3\n");
    printf("Exit the application click on:   4\n");
    printf("Enter your application here: ");
}

void Display_records(student_record_t *record, int number_of_records)
{
    int record_valid  = 0;
    for(int i=0; i<number_of_records; i++)
    {
        if(record[i].ID)
        {
            record_valid = 1;
            printf("***********************************\n");
            printf("  student ID              : %u\n",record[i].ID);
            printf("  student Name            : %s\n",record[i].name);
            printf("  student Date of birth   : %s\n",record[i].date_of_birth);
            printf("  student Branch          : %s\n",record[i].branch);
            printf("  student grade           : %0.2f\n",record[i].grade);
            printf("***********************************\n\n");
        }
    }
    if(!record_valid)
       printf("No records found\n\n");
}


int check_student_ID(int student_ID, student_record_t *record, int number_of_records)
{
    for(int i=0; i<number_of_records; i++)
    {
        if(record[i].ID == student_ID)
        {
          return 1;
          break;
        }  
    }
    return 0;
}


int Add_new_record(student_record_t *record, int number_of_records)
{   
    int add_status = 0;
    int student_ID;

    for (int i = 0; i < number_of_records; i++)
    {   
        printf("Enter the student ID: ");
        scanf("%d", &student_ID);
        getchar(); 

        if (!check_student_ID(student_ID, record, number_of_records))
        {
            add_status = 1;
            record[i].ID = student_ID;
            
            printf("***********************************\n");
            printf("Enter the student Name: ");
            scanf(" %49[^\n]", record[i].name);

            printf("***********************************\n");
            printf("Enter the student date of birthday: ");
            scanf(" %10s", record[i].date_of_birth);

            printf("***********************************\n");
            printf("Enter the student Branch: ");
            getchar();
            scanf(" %49[^\n]", record[i].branch);

            printf("***********************************\n");
            printf("Enter the student grade: ");
            scanf("%f", &record[i].grade);

        }
        else
            printf("Student ID already exists\n\n");
            
        break;
    }

    return add_status;
}



int Delete_record(student_record_t *record, int number_of_records)
{
    int delet_status = 0;
    int student_ID;
    
    printf("Enter the student ID: ");
    scanf("%d", &student_ID);
    
    for(int i=0; i<number_of_records; i++)
    {
        if(student_ID == record[i].ID)
        {
            delet_status = 1;
            record[i].ID = 0;
            record[i].grade = 0;
            strcpy(record[i].name, "");
            strcpy(record[i].branch, "");
            strcpy(record[i].date_of_birth, "");
            break;
        }
    }
    return delet_status;
}


int read_menu()
{
    int code;
    scanf("%d", &code);
    return code;
}

void menu_bar(int menu_code)
{
    int status;
    switch(menu_code)
    {
        case 1:
            printf("\nDisplaying all students record\n");
            Display_records(students, number_of_records);
            break;
        
        case 2:
            printf("\nAdd new record\n");
            status = Add_new_record(students, number_of_records);
            status ? printf("Record added successfully\n\n"):printf("Record added unsuccessfully\n\n");
            break;
            
        case 3:
            printf("\nDelet a record\n");
            status = Delete_record(students, number_of_records);
            status ? printf("Record deleted successfully\n\n"):printf("Record deleted unsuccessfully\n\n");
            break;
                       
        default:
            printf("input invalid\n\n");
        
    }
}


void Save_records_to_file(student_record_t *record, int number_of_records)
{
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < number_of_records; i++) {
        if (record[i].ID != 0) {
            fprintf(file, "%d,%s,%.2f,%s,%s\n",
                record[i].ID,
                record[i].name,
                record[i].grade,
                record[i].date_of_birth,
                record[i].branch);
        }
    }

    fclose(file);
    printf("Records saved to file.\n");
}


void Load_records_from_file(student_record_t *record, int *number_of_records)
{
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("No saved records found\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%d,%49[^,],%f,%10[^,],%49[^\n]",
                  &record[i].ID,
                  record[i].name,
                  &record[i].grade,
                  record[i].date_of_birth,
                  record[i].branch) == 5)
    {
        i++;
        if (i >= *number_of_records)
           break;
    }

    *number_of_records = i;
    fclose(file);
    printf("Records loaded from file.\n");
}
