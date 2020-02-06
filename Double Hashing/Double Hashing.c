#include<stdio.h>
#define max 13


int hash_table[max]={0};

void insert(int x){
	int h1=hash_func1(x);
	
	if(hash_table[h1]==0){
		hash_table[h1]=x;
	}else{
		int h2=hash_func2(x);
		int i,h;
		for(i=1;i<max;i++){
			h=(h1+(i*h2))%max;
			if(hash_table[h]==0){
				hash_table[h]=x;
				break;
			}
		}
	}	
}

int hash_func1(int x){
	return x%max;
}

int hash_func2(int x){
	return (8-(x%8));
}
int search(int x){
	int h1=hash_func1(x);
	if(hash_table[h1]==x){
		return h1;
	}else{
		int i;
		int h2=hash_func2(x);
		for(i=1;i<max;i++){
			int h=(h1+(i*h2))%max;
			if(hash_table[h]==x){
				return h;
				break;
			}
		}
		return -1;
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
	printf("%d\n",search(10));
	printf("%d\n",search(18));
	printf("%d\n",search(41));
	printf("%d\n",search(22));
	printf("%d\n",search(44));
	printf("%d\n",search(59));
	printf("%d\n",search(32));
	printf("%d\n",search(31));
	printf("%d\n",search(73));
	printf("%d\n",search(90));
}
