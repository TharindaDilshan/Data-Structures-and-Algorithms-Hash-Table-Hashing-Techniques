#include<iostream>
#define max 100

using namespace std;

int size;

class hashmapping{
	private:
		int hashtable1[max];
		int hashtable2[max];
		int hashfunc(int f,int k){
			if(f==1){
				return k%size;
			}else if(f==2){
				return((k/11)%11);
			}
		}
	public:
		hashmapping(){
			for(int i=0;i<size;i++){
				hashtable1[i]=0;
				hashtable2[i]=0;
			}
		}
		int insert(int);
		int search(int);
		int remove(int);
		int display();
};
int hashmapping::insert(int x){
	int y,z,m;
	int count=0;
	while(count<size){
		if(hashtable1[hashfunc(1,x)]==0){
			hashtable1[hashfunc(1,x)]=x;
			cout<<"Element Inserted"<<endl;
			return 1;
		}else{
			m=hashtable1[hashfunc(1,x)];
			hashtable1[hashfunc(1,x)]=x;
			if(hashtable2[hashfunc(2,m)]==0){
				hashtable2[hashfunc(2,m)]=m;
				cout<<"Element Inserted"<<endl;
				return 1;
			}else{
				x=hashtable2[hashfunc(2,m)];
				hashtable2[hashfunc(2,m)]=m;
				count++;
			}
		}
	}
}


int hashmapping::search(int x){
	int y=hashfunc(1,x);
	int z=hashfunc(2,x);
	if(hashtable1[y]==x){
		cout<<"Element found at index "<<y<<" of hashtable 1"<<endl;
	}else if(hashtable2[z]==x){
		cout<<"Element found at index "<<z<<" of hashtable 2"<<endl;
	}else{
		cout<<"Element not found"<<endl;
	}
}

int hashmapping::remove(int x){
	int y=hashfunc(1,x);
	int z=hashfunc(2,x);
	if(hashtable1[y]==x){
		hashtable1[y]=0;
		cout<<"Element deleted at index "<<y<<" of hashtable 1"<<endl;
	}else if(hashtable2[z]==x){
		hashtable2[y]=0;
		cout<<"Element deleted at index "<<z<<" of hashtable 2"<<endl;
	}else{
		cout<<"Element not found"<<endl;
	}
}
int hashmapping::display(){
	for(int i=0;i<size;i++){
		cout<<hashtable1[i]<<"\t";
	}
	cout<<endl;
	for(int i=0;i<size;i++){
		cout<<hashtable2[i]<<"\t";
	}
	cout<<endl;
}

int main(){
	size=10;
	hashmapping obj;
	obj.insert(20);
	obj.insert(50);
	obj.insert(53);
	obj.insert(75);
	obj.insert(100);
	obj.insert(67);
	obj.insert(105);
	obj.insert(3);
	obj.insert(36);
	obj.insert(39);
	obj.display();
	obj.search(100);
	obj.search(75);
	obj.search(36);
	obj.search(39);
	obj.remove(36);
	obj.display();
	obj.insert(47);
	obj.display();
	
}









