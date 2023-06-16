#include "Matrix.h"
#include <exception>
#include "MatrixIterator.h"
using namespace std;

// overall complexity : T(n)
Matrix::Matrix(int nrLines, int nrColumns) {
	//TODO - Implementation
	if (nrLines <= 0 || nrColumns <= 0)
		throw exception();

	this->lines = nrLines;
	this->columns = nrColumns;
	this->capacity = 8;
	this->length = 0;

	this->elements = new Triplet[this->capacity];
	for (int i = 0; i < this->capacity; i++) 
	{
		this->elements[i].element = NULL_TELEM;
		this->elements[i].line = -1;
		this->elements[i].column = -1;
	}
}

// Overall complexity : T(1)
int Matrix::nrLines() const {
	//TODO - Implementation
	return this->lines;
}

// overall complexity : T(1)
int Matrix::nrColumns() const {
	//TODO - Implementation
	return this->columns;
}

// overall complexity : O(n)
TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
	if (i < 0 || i >= this->lines || j < 0 || j >= this->columns)
		throw exception();

	int pos = this->search(i, j);
	if (pos == -1)
		return NULL_TELEM;
	return this->elements[pos].element;
}

// overall complexity : O(n)
TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
	if (i < 0 || i >= this->lines || j < 0 || j >= this->columns)
		throw exception();
	
	TElem result = this->search(i, j);
	if (result == -1)
	{
		Triplet elem = { i, j, e };
		this->insert(elem);
		return NULL_TELEM;
	}
	else 
	{
		if (e == NULL_TELEM)
		{
			TElem oldElem = this->elements[result].element;
			this->elements[result].element = NULL_TELEM;
			this->elements[result].line = -1;
			this->elements[result].column = -1;
			this->length--;
			return oldElem;
		}
		TElem oldElem = this->elements[result].element;
		this->elements[result].element = e;
		return oldElem;
	}
}

// overall complexity : T(n)
void Matrix::resize()
{
	int newCapacity = this->capacity * 2;

	Triplet* newElements = new Triplet[newCapacity];
	for (int i = 0; i < newCapacity; i++)
	{
		newElements[i].element = NULL_TELEM;
		newElements[i].line = -1;
		newElements[i].column = -1;
	}

	for (int i = 0; i < this->capacity; i++)
	{
		newElements[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = newElements;
	this->capacity = newCapacity;
}

// Overall complexity: O(n)
// Worst case: T(n)
// Best case: T(1)
int Matrix::search(int line, int column) const
{
	for (int i = 0; i < this->capacity; i++)
	{
		if(this->elements[i].line == line && this->elements[i].column == column)
			return i;
	}
	return -1;
}

// overall complexity : O(n)
int Matrix::validPos(Triplet elem)
{
	for (int i = 0; i < this->capacity; i++)
	{
		if (this->elements[i].line == -1 && this->elements[i].column == -1)
			return i;
	}
	return -1;
}

// Average O(1)
// Worst case O(n)
void Matrix::insert(Triplet elem)
{
	while (this->length == this->capacity)
		this->resize();

	int pos = this->validPos(elem);
	this->elements[pos] = elem;
	this->length++;
}

// overall compexity : T(1)
MatrixIterator Matrix::iterator() const {
    return MatrixIterator(*this);
}

