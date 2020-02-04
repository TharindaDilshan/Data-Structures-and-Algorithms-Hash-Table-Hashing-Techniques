#include<iostream>
#include<string>
#include<string.h>
#define max 100
int size;

using namespace std;

class node{
	private:
		friend class hashmapping;
		string data;
	public:
		node *nextnode;
		node(){
			data="0";
			nextnode=NULL;
		}
		node(string x){
			data=x;
			nextnode=NULL;
		}
		
};

class hashmapping{
	private:
		node hashtable[max];
		int summation(string s){
			int sum=0;
			for(int i=0;i<s.length();i++){
				sum=sum+s[i];
			}
			return sum;
		}
		int hashfunc(int x){
			return x%size;
		}
	public:
		int insert(string);
		int search(string);
		void remove(string);
		void display();
};

int hashmapping::insert(string x){
	int y=hashfunc(summation(x));
	if(hashtable[y].data=="0"||hashtable[y].data=="-1"){
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
int hashmapping::search(string x){
	int y=hashfunc(summation(x));
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
void hashmapping::remove(string x){
	int y=hashfunc(summation(x));
	if(hashtable[y].data==x){
		hashtable[y].data="-1";
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
			cout<<"\t"<<p->data;
			p=p->nextnode;
		}
		cout<<endl;
	}
}
int main(){
	size=13;
	hashmapping obj;
	obj.insert("Chocolate");
	obj.insert("note");
	obj.insert("tone");
	obj.insert("post");
	obj.insert("stop");
	obj.insert("post");
	obj.insert("tops");
	obj.insert("lol");
	obj.display();
	obj.search("tops");
	obj.search("note");
	obj.search("haha");
	obj.search("stop");
	obj.remove("tops");
	obj.remove("lol");
	obj.display();
}









