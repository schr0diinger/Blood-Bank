/*****************************************************
 * @author   : Rashik Shahriar Akash (202-15-3825)   *                                                   * 
 * @file     : main.c                                *
 * @created  : Monday Mar 29, 2021 19:14:33 +06      *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct donor
{
    int id;
    char name[50];
    int group;
    bool rh;
    char address[200];
    int contact;
    int lastDonation;   
    struct donor *prev;
    struct donor *next;
};


void bloodGroup(int group, bool rh)
{
    switch (group)
    {
        case 1:
            printf("A");
            break;
        
        case 2:
            printf("B");
            break;
        
        case 3:
            printf("AB");
            break;
        
        case 4:
            printf("O");
            break;
        
        default:
            break;
    }
    
    if(rh)
        printf("+(ve)");
    else
        printf("-(ve)");
}

struct donor *head = NULL;

int defaultPrompt()
{
    int c;

    system("clear");
    printf("\n\n");
    printf("\t/---------------------------------------------------------------\\\n");
    printf("\t|                                                               |\n");
    printf("\t|     Alpha Blood Bank Blood Donation Portal (v1.0 stable)      |\n");
    printf("\t|                                                               |\n");
    printf("\t|---------------------------------------------------------------|\n");
    printf("\t| Available Commands:                                           |\n");
    printf("\t|---------------------------------------------------------------|\n");
    printf("\t|                                                               |\n");
    printf("\t| 1. Find Blood                                                 |\n");
    printf("\t| 2. Add new Donor to Database                                  |\n");
    printf("\t| 3. Remove Donor from Database                                 |\n");
    printf("\t| 4. List all Donors                                            |\n");
    printf("\t| 5. Update Donor Info                                          |\n");
    printf("\t| 6. Exit the program                                           |\n");
    printf("\t|                                                               |\n");
    printf("\t|---------------------------------------------------------------|\n");
    printf("\t| Example: Enter 5 to exit the program.                         |\n");
    printf("\t\\---------------------------------------------------------------/\n\n");

    printf(" --> Enter a command: ");
    scanf("%d", &c);

    return c; // <-- Pass the command to the main program
}

void findBlood()
{
    int found = 0;
    int group = 0;
    bool rh;
    int bg = 0;
    printf("\n");
    printf("Blood Group: 1. A+(ve)    2. B+(ve)    3. AB+(ve)    4. O+(ve)\n             5. A-(ve)    6. B-(ve)    7. AB-(ve)    8. O-(ve)\n");
    printf("           : ");
    scanf("%d", &bg);
    switch (bg)
    {
        case 1:
            group = 1;
            rh = true;
            break;
        
        case 2:
            group = 2;
            rh = true;
            break;
        
        case 3:
            group = 3;
            rh = true;
            break;
        
        case 4:
            group = 4;
            rh = true;
            break;
        
        case 5:
            group = 1;
            rh = false;
            break;
        
        case 6:
            group = 2;
            rh = false;
            break;
        
        case 7:
            group = 3;
            rh = false;
            break;
        
        case 8:
            group = 4;
            rh = false;
            break;
        
        default:
            break;
    }

    struct donor *list = head;

    while (list != NULL)
    {
        if (list -> group == group && ((list -> rh) == rh))
        {
            printf("\n");
            if ((list -> lastDonation) > 90)
                printf("[More than 90 days since last donation]");
            else
                printf("[Less that 90 days since last donation]");
            printf("\n");
            printf("Donor ID: %d", list -> id);
            printf("\n");
            printf("Donor Name: %s", list -> name);
            printf("\n");
            printf("Blood Group: ");
            bloodGroup(list -> group, list -> rh);
            printf("\n");
            printf("Donor Address: %s", list -> address);
            printf("\n");
            printf("Contact Number: %d", list -> contact);
            printf("\n");
            printf("Days Since Last Donation: %d days", list -> lastDonation);
            printf("\n");
            printf("\n");
            found++;
        }

        list = list -> next;
    }

    printf("\n");
    if (found == 0)
        printf("No Donors Found!\n");
    printf("Press ENTER to go back: ");
        getchar();
        getchar();
}


void listDonors(int p)
{
    system("clear");
    struct donor *temp = head;

    while (temp != NULL)
    {
        printf("Donor ID: %d", temp -> id);
        printf("\n");
        printf("Donor Name: %s", temp -> name);
        printf("\n");
        printf("Blood Group: ");
        bloodGroup(temp -> group, temp -> rh);
        printf("\n");
        printf("Donor Address: %s", temp -> address);
        printf("\n");
        printf("Contact Number: %d", temp -> contact);
        printf("\n");
        printf("Days Since Last Donation: %d days", temp -> lastDonation);
        printf("\n");
        printf("\n");

        temp = temp -> next;
    }

    if (p)
    {
        printf("Press ENTER to go back: ");
        getchar();
        getchar();
    }
}

int didglobal = 19201;
void addDonor()
{
    struct donor *temp = (struct donor *) malloc(sizeof(struct donor));
    system("clear");
    printf("\n\n\t\t     >--> Adding New Donor to the Database <--< \n");
    printf("\n");
    printf("\n");
    printf("Name of the Donor: ");
    getchar();
    gets(temp -> name);
    temp -> id = didglobal;
    didglobal++;
    printf("\n");
    printf("Address of Donor: ");
    gets(temp -> address);
    int bg;
    printf("\n");
    printf("Blood Group: 1. A+(ve)    2. B+(ve)    3. AB+(ve)    4. O+(ve)\n             5. A-(ve)    6. B-(ve)    7. AB-(ve)    8. O-(ve)\n");
    printf("           : ");
    scanf("%d", &bg);
    switch (bg)
    {
        case 1:
            temp -> group = 1;
            temp -> rh = true;
            break;
        
        case 2:
            temp -> group = 2;
            temp -> rh = true;
            break;
        
        case 3:
            temp -> group = 3;
            temp -> rh = true;
            break;
        
        case 4:
            temp -> group = 4;
            temp -> rh = true;
            break;
        
        case 5:
            temp -> group = 1;
            temp -> rh = false;
            break;
        
        case 6:
            temp -> group = 2;
            temp -> rh = false;
            break;
        
        case 7:
            temp -> group = 3;
            temp -> rh = false;
            break;
        
        case 8:
            temp -> group = 4;
            temp -> rh = false;
            break;
        
        default:
            break;
    }

    printf("\n");
    printf("Contact Number: ");
    scanf("%d", &temp -> contact);
    printf("\n");
    printf("Days Since Last Donation: ");
    scanf("%d", &temp -> lastDonation);

    temp -> next = NULL;


    if (head == NULL)
    {
        head = temp;
        head -> prev = NULL;
    }
    else
    {
        struct donor *temp2 = head;
        while(temp2 -> next != NULL)
        {
            temp2 = temp2 -> next;
        }
        temp -> prev = temp2;
        temp2 -> next = temp;
    }

    printf("\n");
    printf("--> Added Entry for %s with ID %d", temp -> name, temp -> id);
    printf("\n");
    printf("\n\t\t           >--> Press ENTER to go back <--< ");
    getchar();
    getchar();
}

void removeDonor()
{
    char name[50];
    int id;
    listDonors(0);
    printf("Enter the ID of Donor to be removed: ");
    scanf("%d", &id);

    struct donor *temp = head;

    while (temp != NULL)
    {
        if (temp -> id == id)
        {
            strcpy(name, temp -> name);
            if (temp -> prev == NULL && temp -> next == NULL)
            {
                temp = NULL;
            }

            else if (temp -> prev != NULL && temp -> next == NULL)
            {
                (temp -> prev) -> next = NULL;
            }

            else if (temp -> prev == NULL && temp -> next != NULL)
            {
                (temp -> next) -> prev = NULL;
            }

            else
            {
                (temp -> prev) -> next = temp -> next;
                (temp -> next) -> prev = temp -> prev;
            }

            printf("Deleted Entry for %s with ID %d\n", name, id);
            printf("Press ENTER to go back: ");
            getchar();
            getchar();

            break;
        }
        temp = temp -> next;
    }
}

void updateDonor()
{
    char name[50];
    int id;
    listDonors(0);
    printf("Enter the ID of Donor to be Updated: ");
    scanf("%d", &id);

    struct donor *temp = head;

    while (temp != NULL)
    {
        if (temp -> id == id)
        {
            strcpy(name, temp -> name);

            printf("Press 1 to Update Address or 2 to Update Contact. Press 0 to go back.\n");

            int l;
            char la[200];
            int lc;
            scanf("%d", &l);

            switch (l)
            {
                case 1:
                    {
                        printf(" --> Previous Address: %s\n", temp -> address);
                        printf(" --> New Address: ");
                        getchar();
                        gets(la);
                        strcpy(temp -> address, la);
                        break;
                    }
                
                case 2:
                    {
                        printf(" --> Previous Contact: %d\n", temp -> contact);
                        printf(" --> New Address: ");
                        scanf("%d", &lc);
                        temp -> contact = lc;
                    }

                case 0:
                    break;
                
                default:
                    break;
            }

            printf("Updated Entry for %s with ID %d\n", name, id);
            printf("Press ENTER to go back: ");
            getchar();
            getchar();

            break;
        }
        temp = temp -> next;
    }


    
}

int main()
{

    while(1)
    {
        int c = 0;
        c = defaultPrompt();
        switch (c)
        {
            case 1:
                findBlood();
                break;

            case 2:
                addDonor();
                break;
            
            case 3:
                removeDonor();
                break;

            case 4:
                listDonors(1);
                break;

            case 5:
                updateDonor();
                break;
            
            case 6:
                return 0;

            default:
                c = 0;
                printf("Invalid Command!");
        }
    }
    
    return 0;
}