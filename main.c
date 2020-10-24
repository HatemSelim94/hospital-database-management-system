#include "declaration.h"
int main()
{
    int choice,choice2;
    char choice_buff[20];

   node* head_ptr=NULL;
    for(;;)
    {
    printf("enter 1 to add patient\nenter 2 to print all data\nenter 3 to delete all\nenter 4 to print by id\n"
           "enter 5 to delete by id\nenter 6 to sort by id\nenter 7 to sort by name\n"
           "enter 8 to sort by time\nenter 9 to exit\n\n");
    //scanf("%d",&choice);
    fflush(stdout);
    fgets(choice_buff, sizeof(choice_buff), stdin);
    sscanf(choice_buff, "%d", &(choice));
    switch(choice)
    {
    case 1:
    add_patient(&head_ptr);
    break;
    case 2:
     print_all(head_ptr);
    break;
    case 3:
        delete_all(&head_ptr);
        break;
    case 4:
        //choice 2 here is the id
        printf("please enter the id\n");
        //scanf("%d",&choice2);
        fflush(stdout);
        fgets(choice_buff, sizeof(choice_buff), stdin);
        sscanf(choice_buff, "%d", &(choice2));
        print_by_id(head_ptr,choice2);
        break;
    case 5:
        //choice 2 here is the id
        printf("please enter the id\n");
        //scanf("%d",&choice2);
        fflush(stdout);
        fgets(choice_buff, sizeof(choice_buff), stdin);
        sscanf(choice_buff, "%d", &(choice2));
        delete_by_id(&head_ptr,choice2);
        break;
    case 6:
        printf("1 for ascending sorting\n2 for descending order\n");
        fflush(stdout);
        fgets(choice_buff, sizeof(choice_buff), stdin);
        sscanf(choice_buff, "%d", &(choice2));
        while(choice2!=1&&choice2!=2)
        {
            printf("1 for ascending sorting\n2 for descending order\n");
            fflush(stdout);
            fgets(choice_buff, sizeof(choice_buff), stdin);
            sscanf(choice_buff, "%d", &(choice2));
            //scanf(choice_buff, "%d", &(choice2));
        }
        sort_all_by_id(&head_ptr,choice2);
        break;
    case 7:
        printf("1 for ascending sorting (a b c)\n2 for descending order (c b a)\n");
        fflush(stdout);
        fgets(choice_buff, sizeof(choice_buff), stdin);
        sscanf(choice_buff, "%d", &(choice2));
        //scanf("%d",&choice2);
        while(choice2!=1&&choice2!=2)
        {
            printf("1 for ascending sorting (a b c)\n2 for descending order (c b a)\n");
            fflush(stdout);
            //scanf("%d",&choice2);
            fgets(choice_buff, sizeof(choice_buff), stdin);
            sscanf(choice_buff, "%d", &(choice2));
        }
        sort_all_by_name(&head_ptr,choice2);
        break;
    case 8:
        printf("1 for ascending sorting(latest entered data)\n2 for descending order\n");
        fflush(stdout);
        //scanf("%d",&choice2);
        fgets(choice_buff, sizeof(choice_buff), stdin);
        sscanf(choice_buff, "%d", &(choice2));
        while(choice2!=1&&choice2!=2)
        {
            printf("1 for ascending sorting \n2 for descending order \n");
            fflush(stdout);
            fgets(choice_buff, sizeof(choice_buff), stdin);
            sscanf(choice_buff, "%d", &(choice2));
            //scanf("%d",&choice2);
        }
        sort_all_by_date(&head_ptr,choice2);
        break;
    case 9:
        exit(0);
        break;
    default:
        printf("\n\nerror,enter a valid number\n\n");
        break;
    }
    }
    return 0;
}
