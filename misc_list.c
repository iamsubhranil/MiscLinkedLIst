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
	long start = 0,prevaddress = 0, nextaddress = 0;
	struct node_type_int *intnode, *previntnode=NULL;
	struct node_type_real *realnode, *prevrealnode=NULL;
	while(conti){
		printf("Which type of node do you want to enter ?\nEnter 1 for integer\n2 for real : ");
		scanf("%d",&ntype);
		if(ntype==1){
			intnode = (struct node_type_int *)malloc(sizeof(struct node_type_int));
			if(lastused==1 && previntnode!=NULL){
				previntnode->nextaddress = (long)intnode;
			}
			else if(prevrealnode!=NULL){
				prevrealnode->nextaddress = (long)intnode;
			}
			if(start==0){
				start = (long)intnode;
				printf("start is assigned to address %ld\n",start);
			}
			intnode->flag = 1;
			printf("Enter int data to store : ");
			scanf("%d",&intnode->data);
			intnode->nextaddress = 0;
			lastused = 1;
			previntnode = intnode;
		}
		else if(ntype==2){
			realnode = (struct node_type_real *)malloc(sizeof(struct node_type_real));
			if(lastused==1 && previntnode!=NULL){
				previntnode->nextaddress = (long)realnode;
			}
			else if(prevrealnode!=NULL){
				prevrealnode->nextaddress = (long)realnode;
			}			
			if(start==0){
				start = (long)realnode;
				printf("start is assigned to address %ld\n",start);
			}
			realnode->flag = 2;
			printf("Enter real data to store : ");
			scanf("%f",&realnode->data);
			realnode->nextaddress = 0;
			lastused = 2;
			prevrealnode = realnode;
		}
		else{
			break;
		}	
	}
	nextaddress = start;
	while(nextaddress!=0){
		flag = (int *)nextaddress;
		if((*flag)==1){
			printf("\nNode is int\n");
			intnode = (struct node_type_int *)nextaddress;
			printf("Data : %d\n",intnode->data);
			nextaddress = intnode->nextaddress;
		}
		else{
			printf("\nNode is real\n");
			realnode = (struct node_type_real *)nextaddress;
			printf("Data : %f\n",realnode->data);
			nextaddress = realnode->nextaddress;
		}
	}
	
}
