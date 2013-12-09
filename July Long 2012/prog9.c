#include<stdio.h>
#include<malloc.h>
//#include<conio.h>
#include<stdlib.h>
long getRating(int count);
struct review
{
       long int rating;
       struct review *next;
       struct review *pre;
}*start=NULL,*last=NULL;
typedef struct review Node;
void insert(long val)
{
     Node *newnode,*temp,*prev;
     newnode=(Node*)malloc(sizeof(Node));
     newnode->rating=val;
     if(start==NULL)
     {
                   newnode->next=NULL;
                   newnode->pre=NULL;
                   start=newnode;
                   last=newnode;
     }
     else
     {
         temp=start;
         prev=temp;
         while(temp->next!=NULL)
         {
                  if(temp->rating>=val)
                  {
                       newnode->next=temp;
                       prev->next=newnode;
                       newnode->pre=prev;
                       temp->pre=newnode;
                       break;            
                  }              
                  else
                  {
                      prev=temp;
                      temp=temp->next;
                  }
         }
         if(temp->next==NULL)
         {
                   if(temp->rating>=val)
                  {
                       newnode->next=temp;
                       prev->next=newnode;
                       newnode->pre=prev;
                       temp->pre=newnode;
                  }          
                  else
                  {
                       newnode->next=NULL;
                       temp->next=newnode;
                       newnode->pre=temp;
                       last=newnode;
                  }
         }
      
     }
}
int main()
{
    int size;
    int i,j,opt,count;
    long rev;
    scanf("%d",&size);
    count=0;
    for(i=0;i<size;i++)
    {
                              scanf("%d",&opt);
                              if(opt==2)
                              {
                                        int send=count/3;
                                        if(send==0)
                                        {
                                         printf("No reviews yet\n");
                                        }
                                        else
                                        {
                                            printf("%ld\n",getRating(send));
                                        }
                                        continue;
                              }
                              else
                              {
                                  scanf("%ld",&rev);
                                  count++;        
                                  insert(rev);  
                                  
                              }
             
    }
    //getch();
    return 0;
}
long getRating(int count)
{
     Node *temp;
     int i=1;
     temp=last;
     while(i<count)
     {
               temp=temp->pre;    
                   i++;
     }
     return (temp->rating);
     
}
