#include <iostream>
#include "LinkedList.cpp"
#include <string>
#include <limits>

using namespace std;

//initializing the Linked List
LinkedList memorySpace;

//converts kB to pages through modulus and division
int kBtoPages(int kB){
	if(kB % 4 == 0){
		return kB/4;
	}
	return (kB/4) + 1;
}

void add(bool worst){
	cout<<"Program name - ";
	string name;
	cin>>name;
	int sizeKB;
	cout<<"Program size (KB) - ";
	cin>>sizeKB;
	int sizePG = kBtoPages(sizeKB);  //convert kB to number of pages
	bool error = false;  //error boolean to check redundant name
	bool success = false;  //see if program successfully added
	
	//search if program already exists
	if(memorySpace.search(name)){
		cout<<endl;
		cout<<"Error, there is already a program with the name "<<name;
		error = true;
	}
	
	//adds program
	else{
		if(worst){
			success = memorySpace.addWorstProgram(name, sizePG);  }
		else success = memorySpace.addBestProgram(name, sizePG);  }
	
	
	
	//making sure error has not already occurred
	if(!error){
		cout<<endl;
		if(success){
			cout<<"Program "<<name<< " added successfully: "<<sizePG<<" page(s) used.";
		}
		else {
			cout<<"Error, Not enough memory for Program "<<name;
		}
	}
}

void kill(){
	cout<<"Which program would you like to kill?"<<endl;
	cout<<"Program name - ";
	string proName;
	cin>>proName;
	
	//checks pages reclaimed and removes program
	int success = memorySpace.searchRemove(proName);
	cout<<endl;
	
	//sees if pages reclaimed are greater than 0 / did removal occur
	if(success > 0){
		cout<<"Program "<<proName<< " successfully killed, "<<success<<" page(s) reclaimed.";
	}
	else cout<<"Program "<<proName<<" does not exist";
	
}

void frag(){
	int fragments = memorySpace.fragCount();
	cout<<endl<<"There are "<<fragments<<" fragment(s).";
}

void exit(){
	memorySpace.clear();
}

int main(int argc, char *argv[]){
	
	/*instead of making two seperate files, I have decided 
	to allow user input to decide for which algorithm to use */
	string worstOBest = "";
	bool worst = false;
	cout<<"Welcome to Memory Fragmentation"<<endl<<"Would you like to use the \"worst\" or \"best\" addition algorithm?"<<endl;
	while(true){
		cin>>worstOBest;
		if(worstOBest.compare("worst") == 0){
			worst = true;
			cout<<"Now using worst fit algorithm"<<endl;
			break;
		}
		else if(worstOBest.compare("best") == 0){
			worst = false;
			cout<<"Now using best fit algorithm"<<endl;
			break;
		}
		else cout<<"Sorry. Please type \"worst\" or \"best\""<<endl;
	}	
	
	//assigning false value and blank name for all 30 spaces
	for(int i = 0; i < 32; i++){
	memorySpace.insert();
}
	
	//determine user choice
	int decide = 0;
	do{
		cout<<endl;
		cout<<"1. Add program"<<endl;
		cout<<"2. Kill program"<<endl;
		cout<<"3. Fragmentation"<<endl;
		cout<<"4. Print memory"<<endl;
		cout<<"5. Exit"<<endl<<endl;
		
		int choice;
		cout<<"Choice - ";
		while(!(cin >> choice)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Sorry, that is not a choice. Please try again"<<endl;
			cout<<"Choice - ";
		}
		
		decide = choice;
		
		
		if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
			cout<<"Sorry, that is not a choice. Please try again";
			continue;
		}
		switch(choice){
			case 1: add(worst); break;
			case 2: kill(); break;
			case 3: frag(); break;
			case 4: memorySpace.print(); break;
			case 5: exit(); break;
		}
		cout<<endl;
	} while(decide != 5);
	
	
	return 0;
} 
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

