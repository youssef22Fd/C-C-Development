#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int ID;
    float grade;
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
    int continue_record = 0;
    
    while(!continue_record)
    {
        display_menu();
        menu_code = read_menu();
        if(menu_code != 4)
            menu_bar(menu_code);
        else 
        {
            continue_record = 1;
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
            printf("***********************************\n");
        }
    }
    if(!record_valid)
       printf("No records foun\n");
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
            scanf("%49[^\n]", record[i].name); 
            getchar();
            
            printf("***********************************\n");
            printf("Enter the student date of birth: ");
            scanf("%s", record[i].date_of_birth);
            getchar();
            
            printf("***********************************\n");
            printf("Enter the student Branch: ");
            scanf("%50[^\n]", record[i].branch);  
            getchar();
            
            printf("***********************************\n");
            printf("Enter the student grade: ");
            scanf("%f", &record[i].grade);
            getchar();
        }
        else
            printf("Student ID already exists\n");
            
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
