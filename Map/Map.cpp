#include "MapIterator.h"

Map::Map() {
	this->head = nullptr;
}
//Theta(1)

Map::~Map() {
	struct Node* current = this->head;
	while (current) {
		struct Node* next = current->next;
		delete current;
		current = next;
	}
}
//Theta(n)

TValue Map::add(TKey c, TValue v){
	// if the map is empty, add the new element
	if (this->head == nullptr) {
		struct Node* newNode = new Node;
		newNode->elem.first = c;
		newNode->elem.second = v;
		newNode->next = nullptr;
		this->head = newNode;
		return NULL_TVALUE;
	}
	// if the map is not empty, search for the element
	// if the element is found, replace the value and return the old value
	struct Node* current = this->head;
	while (current != nullptr) {
		if (current->elem.first == c) {
			int value = current->elem.second;
			current->elem.second = v;
			return value;
		}
		current = current->next;
	}
	// if the element is not found, add the new element
	struct Node* newNode = new Node;
	newNode->elem.first = c;
	newNode->elem.second = v;
	newNode->next = this->head;
	this->head = newNode;
	return NULL_TVALUE;
}
//Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

TValue Map::search(TKey c) const{
	if (this->head == nullptr)
		return NULL_TVALUE;
	struct Node* current = this->head;
	while (current != nullptr) {
		if (current->elem.first == c)
			return current->elem.second;
		current = current->next;
	}
	return NULL_TVALUE;
}
//Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)


TValue Map::remove(TKey c){
	// if the map is empty, return NULL_TVALUE
	if (this->head == nullptr)
		return NULL_TVALUE;
	// if the map is not empty, search for the element
	bool flag = false;
	struct Node* current = this->head;
	while (current != nullptr) {
		if (current->elem.first == c) {
			flag = true;
			break;
		}
		current = current->next;
	}
	// if the element is found, remove it and return the value
	if (flag) {
		int value = current->elem.second;
		// if the element is the first element
		// remove the first element
		if (current == this->head) {
			this->head = current->next;
			delete current;
		}
		// if the element is not the first element
		// search for the previous element
		// and remove the current element
		else {
			struct Node* previous = this->head;
			while (previous->next != current) {
				previous = previous->next;
			}
			previous->next = current->next;
			delete current;
		}
		return value;
	}
	// if the element is not found, return NULL_TVALUE
	else
		return NULL_TVALUE;
}
//Best case: Theta(1), Worst case: Theta(n) => Total Complexity: O(n)

int Map::size() const {
	int size = 0;
	struct Node* current = this->head;
	while (current != nullptr) {
		size++;
		current = current->next;
	}
	return size;
}
//Theta(n)

bool Map::isEmpty() const{
	return (this->head == nullptr);
}
//Theta(1)

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
//Theta(1)