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

struct gen_type {
	int flag;
	long nextaddress;
};
void printlist(long *nextaddress){
	struct node_type_int *intnode;
	struct node_type_real *realnode;
	struct node_type_char *charnode;
	int *flag, counter = 0;
	printf("\nStarting traversal from address %ld\n",(long)nextaddress);
	while(nextaddress!=0){
		flag = (int *)nextaddress;
		printf("\nNode : %d",++counter);
		printf("\nType : ");
		if((*flag)==1){
			printf("int\n");
			intnode = (struct node_type_int *)nextaddress;
			printf("Data : %ld",intnode->data);
			nextaddress = (long *)intnode->nextaddress;
			printf("\nNext address : %ld\n",intnode->nextaddress);
		}
		else if((*flag)==2){
			printf("real\n");
			realnode = (struct node_type_real *)nextaddress;
			printf("Data : %g",realnode->data);
			nextaddress = (long *)realnode->nextaddress;
			printf("\nNext address : %ld\n",realnode->nextaddress);
		}
		else if((*flag)==3){
			printf("character\n");
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
long *nextaddress = NULL, *start = NULL, *traversalend =  NULL;
int count = 0;
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
			count++;
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
			count++;
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
			count++;
		}
		else{
			break;
		}	
	}
}

int traverse(int upto){
	int c = 0;
	struct gen_type *generic;
	long add = *start;
	if(upto>count){
		return 2;
	}
	while(add!=0){
		generic = (struct gen_type *)add;
		add = generic->nextaddress;
		c++;
		if(c==upto){
			traversalend = (long *)add;
			return 0;
		}
	}
	return 1;
}

void menu(){
	printf("\nPress 1 to insert a node");
	printf("\nPress 2 to delete a node");
	printf("\nPress 3 to view nodes : ");
}

void main(){
	void insert();
	void menu();
	int traverse(int upto);
	void printlist(long *nextaddress);
	printf("Welcome to MiscLinkedList!");
	printf("\n=========================");	
	printf("\nBefore we proceed, please insert some nodes.");
	insert();
	menu();
}
