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

long *nextaddress = NULL, *start = NULL, *traversalend =  NULL, dobackup = 0;
int count = 0;

void printlist(){
	struct gen_type *generic;
	int flag, counter = 0;
	long nextaddress = 0, dataaddress = 0, *longdata = NULL;
	char *chardata = NULL;
	double *doubledata = NULL;
	if(start==NULL){
		printf("\nList is empty!");
	}
	else{
		nextaddress = (long)start;
		printf("\nStarting traversal from address %ld\n",(long)nextaddress);
		while(nextaddress!=0){
			generic = (struct gen_type *)nextaddress;
			printf("\nNode : %d",++counter);
			flag = generic->flag;
			dataaddress = ((long)(&generic->nextaddress)) + sizeof(long);
			if(flag==1){
				printf("\nType : int");
				longdata = (long *)dataaddress;
				printf("\nData : %ld",*longdata);
			}
			else if(flag==2){
				printf("\nType : real");
				doubledata = (double *)dataaddress;
				printf("\nData : %g",*doubledata);
			}
			else if(flag==3){
				printf("\nType : character");
				chardata = (char *)dataaddress;
				printf("\nData : %c",*chardata);
			}
			else{
				printf("Unknown flag %d!\nFatal error!\n",flag);
				break;
			}
			nextaddress = generic->nextaddress;
			printf("\n");
		}
	}
}

void insert(){
	int conti = 1,ntype;
	long backupaddress = 0;
	struct node_type_int *intnode;
	struct node_type_real *realnode;
	struct node_type_char *charnode;
	struct gen_type *generic;
	if(nextaddress!=NULL && dobackup){
		generic = (struct gen_type *)nextaddress;
		printf("\nBacking up address..");
		backupaddress = generic->nextaddress;
		printf("\nAddress backed up %ld",backupaddress);
		nextaddress = &generic->nextaddress;
		dobackup = 0;
	}
	while(conti){
		printf("\nWhich type of node do you want to insert in the list?");
		printf("\nEnter 1 for integer\n2 for real\n3 for character");
		printf("\nPress any other key to exit : ");
		scanf("%d",&ntype);
		if(ntype==1){
			intnode = (struct node_type_int *)malloc(sizeof(struct node_type_int));
			if(nextaddress!=NULL)
				*nextaddress = (long)intnode;
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
				*nextaddress = (long)realnode;		
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
				*nextaddress = (long)charnode;
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
			if(nextaddress!=NULL)
				*nextaddress = backupaddress;
			break;
		}	
	}
}

int traverse(int upto){
	int c = 0;
	struct gen_type *generic;
	long add = -1;
	printf("\nChecking position..");
	if(upto>count || upto<1){
		return 0;
	}
	if(start==NULL){
		traversalend = NULL;
		return 0;
	}
	add = (long)start;
	printf("\nTraversing..");
	while(c<upto-1){
		generic = (struct gen_type *)add;
		add = generic->nextaddress;
		traversalend = (long *)generic;
		c++;
	}
	printf("\nTraversal ended..\nAddress on hold : %ld\n",add);
	dobackup = 1;
	return 1;
}

void delete(int choice){
	struct gen_type *generic;
	struct gen_type *nextgen;
	if(start==NULL){
		printf("Please insert some nodes first!");
	}
	else if(choice>count || choice<1){
		printf("Invalid position specified!");
	}
	else if(choice==1){
		generic = (struct gen_type *)start;
		start = (long *)generic->nextaddress;
		free(generic);
		count--;
		printf("\nDeletion successful!");
	}
	else{
		traverse(choice);
		generic = (struct gen_type *)traversalend;
		nextgen = (struct gen_type *)generic->nextaddress;
		generic->nextaddress = nextgen->nextaddress;
		free(nextgen);
		count--;
		printf("\nDeletion successful!");
	}
	if(count==0){
		start = NULL;
		nextaddress = NULL;
	}
}

void menu(){
	int cont = 1, choice = 0;
	long *backup = NULL;
	while(cont){
		printf("\nPress 1 to insert a node");
		printf("\nPress 2 to delete a node");
		printf("\nPress 3 to view nodes");
		printf("\nPress any other key to exit : ");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter the position you want to insert the node(<=%d) : ",(count+1));
			scanf("%d",&choice);
			if(choice==1){
				backup = start;
				nextaddress = NULL;
				start = NULL;
				insert();
				*nextaddress = (long)(backup==NULL?0:backup);
			}
			else if(choice==count+1){
				insert();
			}
			else if(!traverse(choice)){
				printf("\nInvalid position specified!\n");
			}
			else{
				nextaddress = traversalend;
				insert();
			}
		}
		else if(choice==2){
			printf("Enter the position of the node you want to delete(<=%d) : ",count);
			scanf("%d",&choice);
			delete(choice);
		}
		else if(choice==3){
			printlist();
		}
		else{
			break;
		}
	}
}

void main(){
	void insert();
	void menu();
	void delete();
	int traverse(int upto);
	void delete(int choice);
	void printlist();
	printf("Welcome to MiscLinkedList!");
	printf("\n=========================");	
	//while(count==0){
	//	printf("\nBefore we proceed, please insert some nodes.");
	//	insert();
	//}
	menu();
}
