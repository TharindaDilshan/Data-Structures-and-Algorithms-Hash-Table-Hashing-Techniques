#include<stdio.h>
#define max 13

int hash_table[max];

int hash_func(int x){
	return x%13;
}

void insert(int x){
	int h=hash_func(x);
	if(hash_table[h]==0){
		hash_table[h]=x;
	}else{
		int i,n,flag=0;
		for(i=1;i<=max/2;i++){
			n=(h+(i*i))%max;
			if(hash_table[n]==0){
				hash_table[n]=x;
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("Function Failure");
		}
	}
}

void search(int x){
	int h=hash_func(x);
	if(hash_table[h]==x){
		printf("Element found at index %d\n",h);
	}else{
		int i,n,flag=0;
		for(i=1;i<=max/2;i++){
			n=(h+(i*i))%max;
			if(hash_table[n]==x){
				printf("Element found at index %d\n",n);
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("Element not found\n");
		}
	}
}

int main(){
	int array[]={18,41,22,44,59,32,31,73};
	int i,j;
	for(i=0;i<sizeof(array)/sizeof(int);i++){
		insert(array[i]);
	}
	for(j=0;j<max;j++){
		printf("%d\t",hash_table[j]);
	}
	printf("\n\n");
	search(59);
	search(41);
	search(32);
	search(13);
	search(14);
	
	
}
