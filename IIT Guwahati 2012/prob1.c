#include<stdio.h>
#include<malloc.h>
struct node{
	   int val;
	   struct node *next;	   
}*first='\0';
struct node *Node,*temp;
void insert(int value);
void find(int limit);
int main(){
	int N;
	int k,i;
	scanf("%d",&N);
	scanf("%d",&k);
	i=1;
	int val;
	while(i<=N){
				scanf("%d",&val);
				if(val==-1){
						find(k);				
				}
				else{
					 insert(val);	 
				    }
				i++;			
	}
}
void insert(int value){
	 Node=(struct node*)malloc(sizeof(struct node*));
	 Node->val=value;
	 if(first=='\0'){
	 				 first=Node;
	 			Node->next='\0';
	 }
	 else{
     	  if(first->val>value){
		  					   Node->next=first;
								 first=Node;         					   
		  }
		  else{
		  	   temp=first;
		  	   while(temp->next!='\0' && temp->next->val < value){
		       						  temp=temp->next;
			   }
			   if(temp->next=='\0'){
									temp->next=Node;
									Node->next='\0';
				}
				else{
			   		 Node->next=temp->next;
			   		 temp->next=Node;
			    }
	      }
	 }
}
void find(int limit){
	 int i=1;
	 temp=first;
	 while(i!=limit){
	 			temp=temp->next; 
	 			i++;
	 }
	 printf("%d\n",temp->val);
}
