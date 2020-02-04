#include<iostream>
#define max 100;
using namespace std;

int size;

class hashnode{
	private:	
		friend class hashmappig;
	public:
		int data;
		int next;
		hashnode(){
			data=0;
			next=0;
		}
		hashnode(int x){
			data=x;
		}
};

class hashmapping{
	private:
		hashnode hashtable[100];
		int hashfunc(int x){
			return x%size;
		}
	public:
		void insert(int);
		int search(int);
		int remove(int);
		void display();
};
void hashmapping::insert(int x){
	int y=hashfunc(x);
	if(hashtable[y].data==0||hashtable[y].data==-1){
		hashtable[y].data=x;
	}else{
		if(hashtable[y].next==0){
			int i=y+1;
			while(hashtable[i].data!=0&&hashtable[i].data!=-1&&i!=y){
				i=(i+1)%size;
			}
			if(i==y){
				cout<<"Hashtable Full"<<endl;
			}else{
				hashtable[i]=x;
				hashtable[y].next=i;
			}
		}else{
			int j;
			int i=hashtable[y].next;
			int count=0;
			while(i!=0&&count<size){
				j=i;
				i=hashtable[i].next;
				count++;
			}
			int m=(j+1)%size;
			while(hashtable[m].data!=0&&hashtable[m].data!=-1&&m!=j){
				m=(m+1)%size;
			}
			if(m==j){
				cout<<"Hashtable Full"<<endl;
			}else{
				hashtable[m]=x;
				hashtable[j].next=m;
			}
			
		}
	}
}
int hashmapping::search(int x){
	int y=hashfunc(x);
	if(hashtable[y].data==x){
		cout<<"Element Found at Index "<<y<<endl;
	}else{
		if(hashtable[y].next==0){
			cout<<"Element not Found"<<endl;
		}else{
			int i=hashtable[y].next;
			int count=0;
			while(i!=0&&count<size){
				if(hashtable[i].data==x){
					cout<<"Element Found at Index "<<i<<endl;
					return 0;
				}
				i=hashtable[i].next;
				count++;
			}
			cout<<"Element not Found"<<endl;		
		}
	}
}
int hashmapping::remove(int x){
	int y=hashfunc(x);
	if(hashtable[y].data==x&&hashtable[y].next==0){
		hashtable[y]=0;
		cout<<"Element Deleted Successfully"<<endl;
	}else{
		if(hashtable[y].data==x){
			hashtable[y].data=hashtable[hashtable[y].next].data;
			int i=hashtable[y].next;
			int m;
			while(hashtable[i].next!=0){
				hashtable[i].data=hashtable[hashtable[i].next].data;
				m=i;
				i=hashtable[i].next;
			}
			hashtable[i].data=0;
			hashtable[m].next=0;
			cout<<"Element Deleted Successfully"<<endl;
			return 0;
		}else{
			int m;
			int i=hashtable[y].next;
			if(hashtable[i].data==x){
				hashtable[y].next=hashtable[i].next;
				hashtable[i].data=0;
				hashtable[i].next=0;
				cout<<"Element Deleted Successfully"<<endl;
				return 0;
			}
			while(hashtable[i].data!=x){
				m=i;
				i=hashtable[i].next;
			}
			hashtable[m].next=hashtable[i].next;
			hashtable[i].data=0;
			hashtable[i].next=0;
			cout<<"Element Deleted Successfully"<<endl;
			return 0;
		}
		cout<<"Element Not Found"<<endl;
	}
}
void hashmapping::display(){
	for(int i=0;i<size;i++){
		cout<<hashtable[i].data<<"\t"<<hashtable[i].next<<endl;
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
	obj.search(65);
	obj.search(35);
	obj.search(30);
	obj.search(66);
	obj.remove(65);
	obj.remove(35);
	obj.remove(30);
	obj.display();
}





