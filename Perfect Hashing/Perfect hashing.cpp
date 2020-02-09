#include<iostream>
#define max 100
using namespace std;
static int size;

class node{
	private:
		friend class hashmapping;
		int array[max];
		int innerhashfunc(int x){
			return (((array[1]*x)+array[2])%size)%array[0];
		}
	public:
		int data;
		
};

class hashmapping{
	private:
		int outerhashfunc(int x){
			return(x%13)%size;
		}
		node hashtable[max];
	public:
		hashmapping();
		void insert(int);
		void search(int);
		void remove(int);
		void display();
		
};
hashmapping::hashmapping(){
	for(int i=0;i<size;i++){
		hashtable[i].data=0;
		int s;
		cout<<"Enter second hash table size for index "<<i<<": ";
		cin>>s;
		hashtable[i].array[0]=s+3;
		cout<<"Enter a and b for index "<<i<<": ";
		cin>>hashtable[i].array[1]>>hashtable[i].array[2];
	}
}
void hashmapping::insert(int x){
	int y=outerhashfunc(x);
	if(hashtable[y].data==0){
		hashtable[y].data=x;
	}else{
		int z=hashtable[y].innerhashfunc(x);
		if(hashtable[y].array[z+3]==0){
			hashtable[y].array[z+3]=x;
		}else{
			cout<<"Slot Occupied"<<endl;
		}
	}	
}
void hashmapping::search(int x){
	int y=outerhashfunc(x);
	if(hashtable[y].data==x){
		cout<<"Element found at index "<<y;
	}else{
		int z=hashtable[y].innerhashfunc(x);
		if(hashtable[y].array[z+3]==x){
			cout<<"Element found at index "<<y<<" "<<z;
		}else{
			cout<<"Element not found"<<endl;
		}
	}
}
void hashmapping::remove(int x){
	int y=outerhashfunc(x);
	if(hashtable[y].data==x){
		hashtable[y].data=0;
		cout<<"Element Deleted"<<endl;
	}else{
		int z=hashtable[y].innerhashfunc(x);
		if(hashtable[y].array[z+3]==x){
			hashtable[y].array[z+3]==0;
			cout<<"Element Deleted"<<endl;
		}else{
			cout<<"Element not found"<<endl;
		}
	}
}
void hashmapping::display(){
	for(int i=0;i<size;i++){
		cout<<hashtable[i].data;
		for(int j=3;j<hashtable[i].array[0]+3;j++){
			cout<<"\t"<<hashtable[i].array[j];
		}
		cout<<endl;
	}
}
int main(){
	size=10;
	hashmapping obj;
	obj.insert(10);
	obj.insert(15);
	obj.insert(26);
	obj.insert(30);
	obj.insert(25);
	obj.insert(35);
	obj.insert(28);
	obj.insert(65);
	obj.display();
}




