#include<stdio.h>
#include<stdlib.h>
struct node_type_int {
	int flag;
	long nextaddress;
	long data;
};

struct node_type_real {
	int flag;
	long nextaddress;
	double data;
};

struct node_type_char {
	int flag;
	long nextaddress;
	char data;
};

void printlist(long *nextaddress){
	struct node_type_int *intnode;
	struct node_type_real *realnode;
	struct node_type_char *charnode;
	int *flag;
	printf("\nStarting traversal from address %ld\n",(long)nextaddress);
	while(nextaddress!=0){
		flag = (int *)nextaddress;
		if((*flag)==1){
			printf("\nNode is int\n");
			intnode = (struct node_type_int *)nextaddress;
			printf("Data : %ld",intnode->data);
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
		else if((*flag)==3){
			printf("\nNode is character\n");
			charnode = (struct node_type_char *)nextaddress;
			printf("Data : %c",charnode->data);
			nextaddress = (long *)charnode->nextaddress;
			printf("\nNext address : %ld\n",charnode->nextaddress);
		}
		else{
			printf("Unknown flag %d!\n",*flag);
			break;
		}
	}
}
long *nextaddress = NULL, *start = NULL;
void insert(){
	int conti = 1,ntype;
	struct node_type_int *intnode;
	struct node_type_real *realnode;
	struct node_type_char *charnode;
	while(conti){
		printf("\nWhich type of node do you want to insert in the list?");
		printf("\nEnter 1 for integer\n2 for real\n3 for character");
		printf("\nPress any other key to exit : ");
		scanf("%d",&ntype);
		if(ntype==1){
			intnode = (struct node_type_int *)malloc(sizeof(struct node_type_int));
			if(nextaddress!=NULL)
				(*nextaddress = (long)intnode);
			if(start==NULL)
				start = (long *)intnode;
			intnode->flag = 1;
			printf("Enter int data to store : ");
			scanf("%ld",&intnode->data);
			intnode->nextaddress = 0;
			nextaddress = &intnode->nextaddress;
		}
		else if(ntype==2){
			realnode = (struct node_type_real *)malloc(sizeof(struct node_type_real));
			if(nextaddress!=NULL)
				(*nextaddress = (long)realnode);		
			if(start==NULL)
				start = (long *)realnode;
			realnode->flag = 2;
			printf("Enter real data to store : ");
			scanf("%lf",&realnode->data);
			realnode->nextaddress = 0;
			nextaddress = &realnode->nextaddress;
		}
		else if(ntype==3){
			charnode = (struct node_type_char *)malloc(sizeof(struct node_type_char));
			if(nextaddress!=NULL)
				(*nextaddress = (long)charnode);
			if(start==NULL)
				start = (long *)charnode;
			charnode->flag = 3;
			printf("Enter character data to store : ");
			scanf(" %c",&charnode->data);
			charnode->nextaddress = 0;
			nextaddress = &charnode->nextaddress;
		}
		else{
			break;
		}	
	}
}

void main(){
	void insert();
	void printlist(long *nextaddress);
	printf("Welcome to MiscLinkedList!");
	printf("\n=========================");	
	printf("\nBefore we proceed, please insert some nodes.");
	insert();
	printlist(start);
	insert();
	printlist(start);
}
