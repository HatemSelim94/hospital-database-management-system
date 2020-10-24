#include "declaration.h"

//function to get patient data
void get_data(database *ptr,node *head)
{
    int counter=0;
    char *time_ptr=NULL;
    char num_buff[20];
    printf("enter id\n");
    fflush(stdout);
    //scanf("%d*[^\n]",&(ptr->id));
    fgets(num_buff, sizeof(num_buff), stdin);
    sscanf(num_buff, "%d", &(ptr->id));
    while((is_id_exist(head,ptr->id)))
    {
        printf("\nerror,this id exist please enter another one\n");
        printf("\nenter id\n");
        fflush(stdout);
        //scanf("%d*[^\n]",&(ptr->id));
        fgets(num_buff, sizeof(num_buff), stdin);
        sscanf(num_buff, "%d", &(ptr->id));
    }
    printf("enter patient name\n");
    fgets(ptr->name, sizeof(ptr->name), stdin);
    printf("enter age\n");
    //fflush(stdin);
    fflush(stdout);
    fgets(num_buff, sizeof(num_buff), stdin);
    sscanf(num_buff, "%d", &(ptr->age));
    //scanf("%d*[^\n]",&(ptr->age));
    //fflush(stdin);
    printf("enter patient medical history\n");
    fgets(ptr->medical_history, sizeof(ptr->medical_history), stdin);
    printf("\n");
    //get registration time in database.date_and_time
    time_t t;
    time(&t);
    time_ptr=ctime(&t);
    while(*(time_ptr+1)!='\0')
    {
        (ptr->date_and_time[counter++])=*(time_ptr++);
    }
    ptr->date_and_time[24]=0;
}

//print data by pointer
void print_data(node *ptr)
{
    printf("\npatient(%d)data:\n",ptr->data.id);
    printf("id  : %d\n",ptr->data.id);
    printf("name: %s\n",ptr->data.name);
    printf("age : %d\n",ptr->data.age);
    printf("medical history: %s\n",ptr->data.medical_history);
    printf("registration date: %s\n\n",ptr->data.date_and_time);
}

//a function to check if the node exist (by id) (get head pointer and id)(return enum state)
state is_exist(node **ptr,int id)
{
    if(*ptr==NULL)
    {
        return not_ok;
    }
    while((((*ptr)->data.id)!=id)&&((*ptr)!=NULL))
    {
        *ptr=(*ptr)->next_ptr;
        if(*ptr==NULL)
        {
            break;
        }
    }
    if(*ptr==NULL)
    {
        return not_ok;
    }
    else
    {
        return ok;
    }
}

//create a new node
node * create_node()
{
    node * ptr=malloc(sizeof(node));
    ptr->next_ptr=NULL;
    return ptr;
}

//add patient
void add_patient(node** head_ptr)
{
    if(*head_ptr==NULL)
    {
        *head_ptr=create_node();
        get_data(&((*head_ptr)->data),*head_ptr);
    }
    else
    {
        node* curr_ptr=*head_ptr;
        while(curr_ptr->next_ptr!=NULL)
        {
            curr_ptr=curr_ptr->next_ptr;
        }
        curr_ptr->next_ptr=create_node();
        get_data(&(curr_ptr->next_ptr->data),*head_ptr);
    }
}

//print all
void print_all(node* ptr)
{
    if(ptr==NULL)
      {
          printf("\nsystem empty\n\n");
      }
    else
    {
     do{
        print_data(ptr);
        ptr=ptr->next_ptr;
     }while(ptr!=NULL);
    }
}

node* delete_data(node* ptr)
{
    node* temp=ptr->next_ptr;
    free(ptr);
 return temp;
}
//delete all
void delete_all(node** ptr)
{
    if(*ptr==NULL)
      {
          printf("\nsystem is empty\n\n");
      }
       else
    {
        node* temp=*ptr;
        while(temp!=NULL)
       {
           temp=delete_data(temp);
       }
       *ptr=temp;
    printf("sys-data has been deleted\n");
    }
}
//print by id
void print_by_id(node *ptr,int id)
{
    if(ptr==NULL)
        printf("\nsystem is empty\n\n");
    else
    {
    if(is_exist(&ptr,id))
    {
        print_data(ptr);
    }
    else
    {
        printf("\nthis id (%d) does not exist in the system\n\n",id);
    }
    }
}
//delete by id
void delete_by_id(node **ptr,int id)
{
    if(*ptr==NULL)
    {
        printf("\nsystem is empty\n\n");
    }
    else
    {
        node *prev=*ptr,*curr=*ptr;
        if(is_exist(&curr,id))
      {
         if(prev==curr)
         {
             if((curr->next_ptr)==NULL)
             *ptr=delete_data(*ptr);
             else
             {
                 *ptr=(*ptr)->next_ptr;
                 free(curr);
             }
         }
         else
         {
             while(prev->next_ptr!=curr)
            {
             prev=prev->next_ptr;
            }
            prev->next_ptr=delete_data(curr);
         }

       }
    else
      {
        printf("\nthis id (%d) does not exist in the system\n\n",id);
       }

    }
}
//reverse list
void reverse_list(node **ptr)
{
    node *prev_ptr=NULL,*curr_ptr=*ptr,*next_ptr;
    while(curr_ptr!=NULL)
    {
        next_ptr=curr_ptr->next_ptr;
        curr_ptr->next_ptr=prev_ptr;
        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;
    }
    *ptr=prev_ptr;
}
//sort by id descending or ascending
void sort_all_by_id(node **ptr,int num)
{
    if(*ptr==NULL)
    {
        printf("\nsystem is empty\n\n");
    }
    else if((*ptr)->next_ptr==NULL)
    {
        return;
    }
    else
    {
    node *curr_ptr,*prev_ptr=NULL,*counter=*ptr;
    database temp;
    while(counter!=NULL)
    {
        curr_ptr=*ptr;
        while(curr_ptr->next_ptr!=NULL)
      {
        prev_ptr=curr_ptr;
       curr_ptr=curr_ptr->next_ptr;
       if((curr_ptr->data.id)>(prev_ptr->data.id))
       {
           temp=curr_ptr->data;
           curr_ptr->data=prev_ptr->data;
           prev_ptr->data=temp;
       }

      }
      counter=counter->next_ptr;
    }

    if(num==1)
    {
        reverse_list(ptr);
    }
  }
}

//sort by NAME descending or ascending
void sort_all_by_name(node **ptr,int num)
{
    if(*ptr==NULL)
    {
        printf("\nsystem is empty\n\n");
    }
    else if((*ptr)->next_ptr==NULL)
    {
        return;
    }
    else
    {
    node *curr_ptr,*prev_ptr=NULL,*counter=*ptr;
    database temp;
    int flag;
    while(counter!=NULL)
    {
        curr_ptr=*ptr;
        while(curr_ptr->next_ptr!=NULL)
      {
       prev_ptr=curr_ptr;
       curr_ptr=curr_ptr->next_ptr;
       flag=strcmp(curr_ptr->data.name,prev_ptr->data.name);
       if(flag>0)
       {
           temp=curr_ptr->data;
           curr_ptr->data=prev_ptr->data;
           prev_ptr->data=temp;
       }

      }
      counter=counter->next_ptr;
    }

    if(num==1)
    {
        reverse_list(ptr);
    }
  }
}

//function to convert date to number during sorting
double conv_to_num(char date[])
{
    int count,days=0,month=0,hours=0,years=0,i=1000,seconds=0,minutes=0;
    double result;
    for(count=4;count<7;count++)
    {
      month+=(int)date[count];
    }
    switch(month)
    {
        case 281://1
        month=1;
        case 269://2
        month=2;
        break;
        case 288://3
        month=3;
        break;
        case 291://4
        month=4;
        break;
        case 295://5
        month=5;
        break;
        case 301://6
        month=6;
        break;
        case 299://7
        month=7;
        break;
        case 285://8
        month=8;
        break;
        case 296://9
        month=9;
        break;
        case 294://10
        month=10;
        break;
        case 307://11
        month=11;
        break;
        case 268://12
        month=12;
        break;
    }
    days=((int)date[8]-48)*10+(int)date[9]-48;
    hours=((int)date[11]-48)*10+(int)date[12]-48;
    minutes=((int)date[14]-48)*10+(int)date[15]-48;
    seconds=((int)date[17]-48)*10+(int)date[18]-48;
    for(count=20;count<24;count++)
    {
        years+=((int)date[count]-48)*i;
        i/=10;
    }
result=years*365+(double)month*30.4167+days+(double)hours/24+(double)minutes/1440+(double)seconds/86400;
return result;
}

//sort by date

void sort_all_by_date(node **ptr,int num)
{
    if(*ptr==NULL)
    {
        printf("\nsystem is empty\n\n");
    }
    else if((*ptr)->next_ptr==NULL)
    {
        return;
    }
    else
    {
    node *curr_ptr,*prev_ptr=NULL,*counter=*ptr;
    database temp;
    double curr_val,prev_val;
    while(counter!=NULL)
    {
        curr_ptr=*ptr;
        while(curr_ptr->next_ptr!=NULL)
      {
        prev_ptr=curr_ptr;
       curr_ptr=curr_ptr->next_ptr;
       curr_val=conv_to_num(curr_ptr->data.date_and_time);
       prev_val=conv_to_num(prev_ptr->data.date_and_time);
       if((curr_val<prev_val))
       {
           temp=curr_ptr->data;
           curr_ptr->data=prev_ptr->data;
           prev_ptr->data=temp;
       }

      }
      counter=counter->next_ptr;
    }

    if(num==1)
    {
        reverse_list(ptr);
    }
  }
}

state is_id_exist(node *ptr,int id)
{
    int count=0;
    while(ptr!=NULL)
    {
        if(ptr->data.id==id)
        {
            count++;
        }
        ptr=ptr->next_ptr;

    }
    if(count==2)
    {
        return ok;
    }
    else
    {
        return not_ok;
    }
}
