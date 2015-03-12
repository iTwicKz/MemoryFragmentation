#include <iostream>
#include "LinkedList.h"

using namespace std;

Node::Node() {
	this->used = false;
	this->pName = "";
	this->next = NULL;
	
}

Node::Node(boolean used, string pName) {
	this->used = used;
	this->pName = pName;
	this->next = NULL;
	
}

Node::Node(boolean used, string pName, Node *next) {
	this->used = used;
	this->pName = pName;
	this->next = next;
	
}

Node::~Node(){
	this->next = NULL;
}

bool Node::getUsed(){
	return this->used;
}

void Node::setUsed(bool used){
	this->used = used;
}

string Node::getName(){
	return this->pName;
}

void Node::setName(string pName){
	this->pName = pName;
}

Node * Node::getNext() {
	return this->next;
}

void Node::setNext(Node *next){
	this->next = next;
}

//public methods for LinkedList

LinkedList::LinkedList(){
	this->head = NULL;
}

LinkedList::LinkedList(Node *head){
	this->head = head;
}

LinkedList::~LinkedList(){
	clear;
}

Node * LinkedList::getHead(){
	return this->head;
}

void LinkedList::setHead(Node *head){
	this->head = head;
}

void LinkedList::insert(bool used, string pName){
	Node * newNode = new Node(used, pName);
	if(head == NULL) {
		head = newNode;
		return;
	}
	Node * temp = head;
	while(temp->getNext() != NULL) {
		temp = temp->getNext();
	}
	temp->setNext(newNode);
}

void LinkedList::remove(bool used, string pName){
	Node * newHead = new Node(false, "", head);
	Node * prev = newHead;
	Node * curr = head;
	while(curr != NULL){
		if(curr->getName() == pName){
			prev->setNext(curr->getNext());
			delete curr;
			curr = prev->getNext();
		} else {
			curr = curr->getNext();
			prev = prev->getNext();
	}
	head = newHead->getNext();
	delete newHead;
}

void LinkedList::print(){
	if(head == NULL) {
		cout << "LinkedList is empty" <<endl;
	}
	Node * temp = head;
	int count = 0;
	while(temp != NULL){
		if(temp->getUsed() == true){
			cout<< temp->getName() << "\t";
			temp = temp->getNext();
			count++;
		}
		else { 
			cout<< "Free" << "\t";
			temp = temp->getNext();
			count++;	
		}
		if(count%8 == 0){
			cout<< endl;
		}
	}
	cout<< endl;
}

void LinkedList::clear(){
	Node * curr = head;
	Node * next = NULL;
	while(curr != NULL){
		next = curr->getNext();
		delete curr;
		curr = next;
	}
}


	
	
