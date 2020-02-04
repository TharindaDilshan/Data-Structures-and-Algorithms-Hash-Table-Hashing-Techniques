#include<iostream>
#include<string>
#define max 100
int size;

using namespace std;

class node{
	private:
		friend class hashmapping;
		int data;
	public:
		node *nextnode;
		node(){
			data=0;
			nextnode=NULL;
		}
		node(int x){
			data=x;
			nextnode=NULL;
		}
		
};

class hashmapping{
	private:
		node hashtable[max];
		int hashfunc(int x){
			return x%size;
		}
	public:
		int insert(int);
		int search(int);
		void remove(int);
		void display();
};

int hashmapping::insert(int x){
	int y=hashfunc(x);
	if(hashtable[y].data==0||hashtable[y].data==-1){
		hashtable[y].data=x;
	}else{
		if(hashtable[y].nextnode==NULL){
			hashtable[y].nextnode=new node(x);
		}else{
			node *p=hashtable[y].nextnode;
			while(p->nextnode!=NULL){
				p=p->nextnode;
			}
			p->nextnode=new node(x);
		}
	}
}
int hashmapping::search(int x){
	int y=hashfunc(x);
	if(hashtable[y].data==x){
		cout<<"Element Found at Index "<<y<<endl;
	}else{
		if(hashtable[y].nextnode==NULL){
			cout<<"Element not found"<<endl;
		}else{
			node *p=hashtable[y].nextnode;
			while(p->nextnode!=NULL&&p->data!=x){
				p=p->nextnode;
			}
			if(p->data==x){
				cout<<"Element Found at Index "<<y<<endl;
			}else{
				cout<<"Element not found"<<endl;
			}
		}
	}
}
void hashmapping::remove(int x){
	int y=hashfunc(x);
	if(hashtable[y].data==x){
		hashtable[y].data=-1;
		cout<<"Element Deleted Successfully"<<endl;
	}else{
		if(hashtable[y].nextnode==NULL){
			cout<<"Invalid Element"<<endl;
		}else{
			if(hashtable[y].nextnode->data==x){
				hashtable[y].nextnode=hashtable[y].nextnode->nextnode;
				cout<<"Element Deleted Successfully"<<endl;
			}else{
				node *p=hashtable[y].nextnode;
				node *preptr;
				while(p->nextnode!=NULL&&p->data!=x){
					preptr=p;
					p=p->nextnode;
				}
				if(p->data==x){
					preptr->nextnode=p->nextnode;
					delete(p);
					cout<<"Element Deleted Successfully"<<endl;
				}else{
					cout<<"Invalid Element"<<endl;
				}
			}
		}
	}
}
void hashmapping::display(){
	for(int i=0;i<size;i++){
		cout<<hashtable[i].data;
		node *p=hashtable[i].nextnode;
		//cout<<" "<<p->data;
		while(p!=NULL){
			cout<<" "<<p->data;
			p=p->nextnode;
		}
		cout<<endl;
	}
}
int main(){
	size=13;
	hashmapping obj;
	obj.insert(18);
	obj.insert(41);
	obj.insert(22);
	obj.insert(44);
	obj.insert(59);
	obj.insert(32);
	obj.insert(31);
	obj.insert(73);
	obj.display();
	obj.search(41);
	obj.search(73);
	obj.search(59);
	obj.search(44);
	obj.search(31);
	obj.search(18);
	obj.search(20);
	obj.remove(18);
	obj.remove(31);
	obj.display();
}









