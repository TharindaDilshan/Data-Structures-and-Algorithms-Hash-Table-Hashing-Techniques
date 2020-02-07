#include<stdio.h>
#define max 13

int hash_table[max];

void insert(int x){
	int h=hash_func(x);
	if(hash_table[h]==0){
		hash_table[h]=x;
	}else{
		int flag=0;
		int i=(h+1)%max;
		while(i!=h){
			if(hash_table[i]==0){
				hash_table[i]=x;
				flag=1;
				break;
			}
			i=(i+1)%max;
		}
		if(flag==0){
			printf("Hash Overflow\n");
		}
	}
}

void search(int x){
	int h=hash_func(x);
	if(hash_table[h]==x){
		printf("Element found at in index %d\n",h);
	}else{
		int flag=0;
		int i=(h+1)%max;
		while(i!=h && hash_table[i]!=0){
			if(hash_table[i]==x){
				flag=1;
				printf("Element found at in index %d\n",h);
				break;
			}
			i=(i+1)%max;
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
	int array[]={18,41,22,44,59,32,31,73};
	int i,j;
	for(i=0;i<sizeof(array)/sizeof(int);i++){
		insert(array[i]);
	}
	for(j=0;j<max;j++){
		printf("%d\t",hash_table[j]);
	}printf("\n");
	search(41);
	search(59);
	search(22);
	search(13);
	
}
