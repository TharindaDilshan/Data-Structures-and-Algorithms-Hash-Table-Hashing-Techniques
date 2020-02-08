#include<iostream>
#define max 100
using namespace std;

int size,s;

struct node{
	int data;
	int key;
};

class hashmapping{
	private:
		int hashfunc(int x){
			return x%size;
		}
		node *hashtable;
	public:
		hashmapping(){
//			int p,s;
			cout<<"Size of hashtable and overflow area: ";
			cin>>size>>s;
			hashtable=new node[size+s];
			for(int i=0;i<(size+s);i++){
				hashtable[i].data=0;
				hashtable[i].key=-1;
			}
		}
		void insert(int);
		int search(int);
		void remove(int);
		void display();
};
void hashmapping::insert(int x){
	if(hashtable[hashfunc(x)].data==0 && hashtable[hashfunc(x)].key==-1){
		hashtable[hashfunc(x)].data=x;
	}else{
		if(hashtable[hashfunc(x)].key==-1){
			for(int i=size;i<size+s;i++){
				if(hashtable[i].data==0){
					hashtable[i].data=x;
					hashtable[hashfunc(x)].key=i;
					break;
				}
			}
		}else{
			int y;
			int k=hashtable[hashfunc(x)].key;
			while(k!=-1){
				y=k;
				k=hashtable[k].key;
			}
			for(int i=size;i<size+s;i++){
				if(hashtable[i].data==0){
					hashtable[i].data=x;
					hashtable[y].key=i;
					break;
				}
			}
			
		}
	}
}
int hashmapping::search(int x){
	if(hashtable[hashfunc(x)].data==x){
		cout<<"Element found at index "<<hashfunc(x)<<endl;
		return 0;
	}else{
		if(hashtable[hashfunc(x)].key==0){
			cout<<"ELement not found"<<endl;
		}else{
			int k=hashtable[hashfunc(x)].key;
			while(k!=0){
				if(hashtable[k].data==x){
					cout<<"Element found at index "<<k<<endl;
					return 0;
				}
				k=hashtable[k].key;
			}
		}
		cout<<"ELement not found"<<endl;
	}
}
void hashmapping::remove(int x){
	if(hashtable[hashfunc(x)].data==x && hashtable[hashfunc(x)].key==-1){
		hashtable[hashfunc(x)].data=0;
		cout<<"Element Deleted"<<endl;
	}else{
		if(hashtable[hashfunc(x)].data==x){
			int m;
			int k=hashfunc(x);
			while(hashtable[k].key!=-1){
				hashtable[k].data=hashtable[hashtable[k].key].data;
				m=k;
				k=hashtable[k].key;
			}
			hashtable[m].key=-1;
			hashtable[k].data=0;
			cout<<"Element Deleted"<<endl;
		}else{
			int m;
			int k=hashfunc(x);
			while(hashtable[k].key!=-1){
				m=k;
				k=hashtable[k].key;
				if(hashtable[k].data==x){
					hashtable[m].key=hashtable[k].key;
					hashtable[k].data=0;
					hashtable[k].key=-1;
					cout<<"Element Deleted"<<endl;
					break;
				}
			}
		}
	}
}
void hashmapping::display(){
	for(int i=0;i<size;i++){
		cout<<hashtable[i].data<<"\t";
	}
	cout<<"\n";
	for(int j=size;j<size+s;j++){
		cout<<hashtable[j].data<<"\t";
	}
	cout<<endl;
}
int main(){
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
	obj.search(35);
	obj.search(26);
	obj.search(30);
	obj.search(65);
	obj.remove(15);
//	obj.insert(85);
	obj.display();
}








