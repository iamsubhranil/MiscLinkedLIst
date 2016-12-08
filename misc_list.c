#include<stdio.h>
#include<stdlib.h>
struct node_type_int {
	int flag;
	int data;
	long nextaddress;
};

struct node_type_real {
	int flag;
	float data;
	long nextaddress;
};

void main(){
	int conti = 1,ntype,lastused = 0,*flag;
	long *start=NULL,prevaddress = 0, *nextaddress;
	struct node_type_int *intnode;
	struct node_type_real *realnode;
	printf("\nInitializing pointers..\n");
	nextaddress = (long *)malloc(sizeof(long));
	while(conti){
		printf("Which type of node do you want to insert ?\nEnter 1 for integer\n2 for real : ");
		scanf("%d",&ntype);
		if(ntype==1){
			intnode = (struct node_type_int *)malloc(sizeof(struct node_type_int));
			if(lastused>0){
				*nextaddress = (long)intnode;
			}
			if(start==NULL){
				start = (long *)intnode;
			}
			intnode->flag = 1;
			printf("Enter int data to store : ");
			scanf("%d",&intnode->data);
			intnode->nextaddress = 0;
			lastused = 1;
			nextaddress = &intnode->nextaddress;
		}
		else if(ntype==2){
			realnode = (struct node_type_real *)malloc(sizeof(struct node_type_real));
			if(lastused>0){
				*nextaddress = (long)realnode;
			}		
			if(start==NULL){
				start = (long *)realnode;
			}
			realnode->flag = 2;
			printf("Enter real data to store : ");
			scanf("%f",&realnode->data);
			realnode->nextaddress = 0;
			lastused = 2;
			nextaddress = &realnode->nextaddress;
		}
		else{
			break;
		}	
	}
	nextaddress = start;
	printf("\nStarting traversal from address %ld\n",(long)nextaddress);
	while(nextaddress!=0){
		flag = (int *)nextaddress;
		if((*flag)==1){
			printf("\nNode is int\n");
			intnode = (struct node_type_int *)nextaddress;
			printf("Data : %d",intnode->data);
			nextaddress = (long *)intnode->nextaddress;
			printf("\nNext address : %ld\n",intnode->nextaddress);
		}
		else if((*flag)==2){
			printf("\nNode is real\n");
			realnode = (struct node_type_real *)nextaddress;
			printf("Data : %g",realnode->data);
			nextaddress = (long *)realnode->nextaddress;
			printf("\nNext address : %ld\n",realnode->nextaddress);
		}
		else{
			printf("Unknown flag %d!\n",*flag);
			break;
		}
	}
	
}
