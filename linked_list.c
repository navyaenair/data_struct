#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *FIRST;  
 
void InsertBegin();  
void InsertLast();  
void InsertRandom();  
void DeleteBegin();  
void DeleteLast();
void DeleteRandom();
void Display();  

void main ()  
{  
    int choice =0;  
    while(choice != 8)  
    {  
        printf("\n----Choose an Option----\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit\n");  
        printf("\nEnter your choice?\n");        
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            InsertBegin();      
            break;  
            case 2:  
            InsertLast();        
            break;  
            case 3:  
            InsertRandom();      
            break;  
            case 4:  
            DeleteBegin();      
            break;  
            case 5:  
            DeleteLast();      
            break;  
            case 6:  
            DeleteRandom();          
            break;  
           
            case 7:  
            Display();        
            break;  
            case 8:
            break;  
            default:  
            printf("Please enter valid choice..");  
        }
    }  
}  
void InsertBegin()
{  
    struct node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->next = FIRST;  
        FIRST = ptr;  
        printf("\nNode inserted");  
    }  
     
}  
void InsertLast()
{  
    struct node *ptr,*temp;  
    int item;    
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");    
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(FIRST == NULL)  
        {  
            ptr -> next = NULL;  
            FIRST = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = FIRST;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted");  
         
        }  
    }  
}  
void InsertRandom()
{  
    int i,loc,item;  
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=FIRST;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
         
        }  
        ptr ->next = temp ->next;  
        temp ->next = ptr;  
        printf("\nNode inserted");  
    }  
}  
void DeleteBegin()
{  
    struct node *ptr;  
    if(FIRST == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else  
    {  
        ptr = FIRST;  
        FIRST = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}  
void DeleteLast()
{  
    struct node *ptr,*ptr1;  
    if(FIRST == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(FIRST -> next == NULL)  
    {  
        FIRST = NULL;  
        free(FIRST);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
         
    else  
    {  
        ptr = FIRST;  
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last ...\n");  
    }    
}  
void DeleteRandom()
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=FIRST;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;      
        ptr = ptr->next;  
             
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  

void Display()  
{  
    struct node *ptr;  
    ptr = FIRST;  
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");  
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}  


