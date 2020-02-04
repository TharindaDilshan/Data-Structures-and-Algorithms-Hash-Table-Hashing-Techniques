#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#define max 13

struct node{
	int data;
	struct node *next;
};

//struct node *init(){
//	struct node *hash_table=(struct node*)malloc(max*sizeof(struct node));
//	return hash_table;
//}

struct node hash_table[max];

void insert(int x){
	int h=hash_func(x);
	if(hash_table[h].data==0){
		hash_table[h].data=x;
	}else{
		struct node *ptr=hash_table[h].next;
		if(ptr==NULL){
			struct node *n=(struct node*)malloc(sizeof(struct node));
			n->data=x;
			hash_table[h].next=n;
			n->next=NULL;
		}else{
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			struct node *n=(struct node*)malloc(sizeof(struct node));
			n->data=x;
			ptr->next=n;
			n->next=NULL;
		}
	}
}


void search(int x){
	int h=hash_func(x);
	if(hash_table[h].data==x){
		printf("Element found at index %d\n",h);
	}else{
		int flag=0;
		struct node *ptr=hash_table[h].next;
		while(ptr!=NULL){
			if(ptr->data==x){
				printf("Element found at index %d\n",h);
				flag=1;
				break;
			}
			ptr=ptr->next;	
		}
		if(flag==0){
			printf("Element not found\n");
		}
	}
}


int hash_func(int x){
	return x%max;
}

int main(){
//	printf("%d",sizeof(struct node));
	int array[]={18,41,22,44,59,32,31,73};
	int i,j;
	for(i=0;i<sizeof(array)/sizeof(int);i++){
		insert(array[i]);
	}
	for(j=0;j<max;j++){
		printf("%d\t",hash_table[j].data);
		struct node *ptr=hash_table[j].next;
		while(ptr!=NULL){
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
	search(41);
	search(73);
	search(59);
	search(44);
	search(31);
	search(18);
//	if(hash_table[2].next==NULL){
//		printf("meow\n");
//	}
	
	
	
}
