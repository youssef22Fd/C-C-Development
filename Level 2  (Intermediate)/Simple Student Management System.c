#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int ID;
    int grade;
    char date_of_birth[10];
    char branch[50];
    
}student_record_t;

int number_of_records = 30;
student_record_t students[30];

void display_menu();
int read_menu();
void menu_bar();
void Display_records(student_record_t *record, int number_of_records);
int check_student_ID(int student_ID, student_record_t *record, int number_of_records);
int Add_new_record(student_record_t *record, int number_of_records);
int Delete_record(student_record_t *record, int number_of_records);



int main()
{
    int menu_code;
    int continue_record = 1;
    
    while(continue_record)
    {
        display_menu();
        menu_code = read_menu();
        if(menu_code)
            menu_bar(menu_code);
        else 
        {
            continue_record = 0;
            printf("Exiting application\n");
            
        }
        
    }
    return 0;
}


void display_menu()
{
    printf("Display all records click on:    1\n");
    printf("Add a new record click on:       2\n");
    printf("Delete a record click on:        3\n");
    printf("Exit the application click on:   0\n");
    printf("Enter your application here:     ");
}

void Display_records(student_record_t *record, int number_of_records)
{
    int record_valid = 0;
    for(int i=0; i<number_of_records; i++)
    {
        if(record[i].ID)
        {
            record_valid = 1;
            printf("*****************************\n");
            printf("  student Name            : %s\n",record[i].name);
            printf("  student ID              : %u\n",record[i].ID);
            printf("  student Branch          : %s\n",record[i].branch);
            printf("  student Date of birth   : %s\n",record[i].date_of_birth);
            printf("*******************************\n");            
        }
    }
    if(!record_valid)
       printf("No records found\n");
}


int check_student_ID(int student_ID, student_record_t *record, int number_of_records)
{
    for(int i=0; i<number_of_records; i++)
    {
        if(record[i].ID == student_ID)
            return 1;
    }
    return 0;
}

int Add_new_record(student_record_t *record, int number_of_records)
{   
    int add_status = 0;
    int student_ID;
    for(int i=0; i<number_of_records; i++)
    {   
        printf("Enter the student ID: ");
        scanf("%d\n", &student_ID);
        if(check_student_ID(student_ID, record, number_of_records))
        {
            printf("Student ID already exit\n");
            return 0;
        } 
        
        add_status = 1;
        record[i].ID = student_ID;  
        
        printf("Enter the student Name: ");
        scanf("%49[^\n]s",record[i].name);
        getchar();
        
        printf("Enter the student date of birth : ");
        scanf("%[^\n]s",record[i].date_of_birth);
        getchar();
        
        printf("Enter the student Branch: ");
        scanf("%49[^\n]s",record[i].branch);
        getchar();
        break;
    }
    return add_status;
}


int Delete_record(student_record_t *record, int number_of_records)
{
    int delet_status = 0;
    int student_ID;
    
    printf("Enter the student ID: ");
    scanf("%d\n", &student_ID);
    
    for(int i=0; i<number_of_records; i++)
    {
        if(student_ID == record[i].ID)
        {
            delet_status = 1;
            record[i].ID = 0;
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
            printf("Displaying all students record\n");
            Display_records(students, number_of_records);
            break;
        
        case 2:
            printf("Add new record\n");
            status = Add_new_record(students, number_of_records);
            status ? printf("Record added successfully\n"):printf("Record added unsuccessfully\n");
            break;
            
        case 3:
            printf("Delet a record\n");
            status = Delete_record(students, number_of_records);
            status ? printf("Record deleted successfully\n"):printf("Record deleted unsuccessfully\n");
            break;
                       
        default:
            printf("input invalid\n");
        
    }
}












