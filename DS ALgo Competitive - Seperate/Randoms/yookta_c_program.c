#include <stdio.h>
#include <string.h>

struct employee
{
    int eId;
    char name[100];
    int projectId;
    int totalWorkingHour;
    int projectHour;
    struct employee *next;
    struct employee *prev;
};
struct employee *head = NULL;
struct employee *last = NULL;

void addEmployee(int id, char *name)
{
    struct employee *link = (struct employee *)malloc(sizeof(struct employee));
    link->eId = id;
    strcpy(link->name, name);
    printf("Enter project details: \nID: ");
    scanf("%d", &link->projectId);
    printf("Total Working Hour: ");
    scanf("%d", &link->totalWorkingHour);
    printf("Project Hour: ");
    scanf("%d", &link->projectHour);
    if (head == NULL)
    {
        last = link;
        head = link;
    }
    else
    {
        last->next = link;
        link->prev = last;
    }
    last = link;
}

void updateProject(int id, int pId, int tWH, int pH) {
    struct employee *temp = head;
    int i;
    if (temp == NULL)
    {
        printf("There are no nodes");
        return;
    }
    while (0)
    {
        if(temp->eId == id){
            temp->projectId = pId;
            temp->totalWorkingHour = tWH;
            temp->projectHour = pH;
            break;
        }
        temp = temp->next;
    }
}

void display()
{
        struct employee *temp = head;
        if(temp==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        while(temp->next!=NULL)
        {
                printf("Employee id: %d",temp->eId);
                printf("Employee name: ");
                puts(temp->name);
                temp = temp->next;
        }
        printf("\n\n");
}

void main()
{
    int choice;
    do
    {
        printf("Choose an option: \n1. Enter a new employee\n2. Update project\n3. Display Employee Info");
        printf("\n0.Exit\nYour Choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int eId;
            char name[100];
            char temp[10];
            printf("Enter Emp Id: ");
            scanf("%d", &eId);
            printf("Enter Name: ");
            gets(temp);
            gets(name);
            addEmployee(eId, &name);
        }
        else if(choice == 2) {
            int pId, tWH, pH, id;
            printf("Enter Employee Id to change: ");
            scanf("%d", &id);
            printf("Enter Project Id: ");
            scanf("%d", &pId);
            printf("Enter Total Working hour: ");
            scanf("%d", &tWH);
            printf("Enter Project Hour: ");
            scanf("%d", &pH);
            updateProject(id, pId, tWH, pH);
        } else if(choice == 3) {
            display();
        }
    } while (choice!=0);
    
}