#include <stdio.h>
#include <stdlib.h>

    /*1. Adding Employee details
        -ID
        -NAME
        -SALARY
        -DEPERTMENT
      2. Display Employee details
        -all at time
      3. Edite if need
        - which one like to edite id,name,salary,-depertment, or all
      4. exit 
        - Before exit save all data in .txt
      */
      
typedef struct Employee_Detail{
    int EMP_ID;
    char EMP_NAME[50];
    float EMP_SALARY;
    char EMP_DEPARTMENT[50];
}Employee;

    //declare the struct name;
    Employee *Employess = NULL; 
    int count  = 0;

void addemployee()
{
    Employess = realloc(Employess , (count + 1) * sizeof(Employee));
    
    printf("EMP_ID : ");
    scanf("%d",&Employess[count].EMP_ID);
    printf("EMP_NAME : ");
    scanf("%s",Employess[count].EMP_NAME);
    printf("EMP_SALARY : ");
    scanf("%f",&Employess[count].EMP_SALARY);
    printf("EMP_DEPARTMENT : ");
    scanf("%s",Employess[count].EMP_DEPARTMENT);
    
    count++;
}
void DisplayEmployess()
{
    for(int i =0;i< count; i++)
    printf("EMP_ID : %d,EMP_NAME : %s,EMP_SALARY : %f,EMP_DEPARTMENT : %s\n",Employess[i].EMP_ID,
    Employess[i].EMP_NAME,Employess[i].EMP_SALARY,Employess[i].EMP_DEPARTMENT);
}

int findEmployeeById(int empId) {
    for (int i = 0; i < count; i++) {
        if (Employess[i].EMP_ID == empId) {
            return i; // Return index if found
        }
    }
    return -1; // Not found
}

void editEmployee() {
    int empId, index;
    int editing_choice;
    printf("Enter Employee ID to edit: ");
    scanf("%d", &empId);

    index = findEmployeeById(empId);
    if (index == -1) {
        printf("Employee with ID %d not found!\n", empId);
        return;
    }
    
    printf("Edit to\n1. NAME\n2. SALARY\n3.DEPARTMENT\n4. ALL\n");
    printf("Editing_choice : ");
    scanf("%d",&editing_choice);
    switch(editing_choice){
        case 1:   
                printf("Editing Employee ID %d:\n", empId);
                printf("New Name (current: %s): ", Employess[index].EMP_NAME);
                scanf("%s", Employess[index].EMP_NAME);break;
        case 2: 
                printf("Editing Employee ID %d:\n", empId);
                printf("New Salary (current: %.2f): ", Employess[index].EMP_SALARY);
                scanf("%f", &Employess[index].EMP_SALARY);break;
        case 3: 
                printf("Editing Employee ID %d:\n", empId);
                printf("New Department (current: %s): ", Employess[index].EMP_DEPARTMENT);
                scanf("%s", Employess[index].EMP_DEPARTMENT);break;
        case 4:
                printf("Editing Employee ID %d:\n", empId);
                printf("New Name (current: %s): ", Employess[index].EMP_NAME);
                scanf("%s", Employess[index].EMP_NAME);
                printf("New Salary (current: %.2f): ", Employess[index].EMP_SALARY);
                scanf("%f", &Employess[index].EMP_SALARY);
                printf("New Department (current: %s): ", Employess[index].EMP_DEPARTMENT);
                scanf("%s", Employess[index].EMP_DEPARTMENT);break;
        default:
                printf("Invalid choice\n");break;
    }

    printf("Employee record updated!\n");
}

void saveFile()
{
   FILE *file = fopen("employees.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "ID:%d, NAME:%s, SALARY:%.2f, DEPARTMENT:%s\n",
                Employess[i].EMP_ID,
                Employess[i].EMP_NAME,
                Employess[i].EMP_SALARY,
                Employess[i].EMP_DEPARTMENT);
    }

    fclose(file);
    printf("Data saved to employees.txt!\n"); 
}

int main()
{

    int choice;
    while(1)
    {
        printf("1. Add Employee\n2. DisplayEmployess\n3. editEmployee\n4. Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: addemployee(); break;
            case 2: DisplayEmployess(); break;
            case 3: editEmployee();break;
            case 4: saveFile();free(Employess);exit(0);
            default: printf("Invalid choice\n");
        }
    }


    return 0;
}