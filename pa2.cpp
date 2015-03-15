#include <iostream>
#include "LinkedList.cpp"
#include <string>

using namespace std;

//initializing the Linked List
LinkedList memorySpace;

//assigning false value and blank name for all 30 spaces


int kBtoPages(int kB){
	if(kB % 4 == 0){
		return kB/4;
	}
	return (kB/4) + 1;
}

void add(){
	cout<<"Program name - ";
	string name;
	cin>>name;
	int sizeKB;
	cout<<endl<<"Program size (KB) - ";
	cin>>sizeKB;
	int sizePG = kBtoPages(sizeKB);
	
	bool success = memorySpace.addProgram(name, sizePG);
	
	if(memorySpace.search(name)){
		cout<<"Error, there is already a program with the name "<<name; 
	}
	
	if(success){
		cout<<"Program "<<name<< " added successfully: "<<sizePG<<" page(s) used."<<endl;
	}
	else {
		cout<<"Error, Not enough memory for Program "<<name;
	}
	
}

void print(){
	
}

void kill(){
	cout<<"Which program would you like to kill?"<<endl;
	cout<<"Program name - ";
	string proName;
	cin>>proName;
	
	int success = memorySpace.searchRemove(proName);
	
	if(success > 0){
		cout<<"Program "<<proName<< " successfully killed, "<<success<<" page(s) reclaimed."<<endl;
	}
	else cout<<"Program "<<proName<<" does not exist";
	
}

void frag(){
	int fragments = memorySpace.fragCount();
	cout<<"There are "<<fragments<<" fragment(s).";
}

void exit(){
	memorySpace.clear();
}

int main(int argc, char *argv[]){
	
	for(int i = 0; i < 32; i++){
	memorySpace.insert();
}
	int decide = 0;
	do{
		cout<<"1. Add program"<<endl;
		cout<<"2. Kill program"<<endl;
		cout<<"3. Fragmentation"<<endl;
		cout<<"4. Print memory"<<endl;
		cout<<"5. Exit"<<endl;
		
		int choice;
		cin>>choice;
		decide = choice;
		
		switch(choice){
			case 1: add(); break;
			case 2: kill(); break;
			case 3: frag(); break;
			case 4: memorySpace.print(); break;
			case 5: exit(); break;
		}
	} while(decide != 5);
	
	
	return 0;
} 
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

