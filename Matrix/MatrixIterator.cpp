#include "MatrixIterator.h"
#include <exception>

MatrixIterator::MatrixIterator(const Matrix& m) : matrix(m) {
    //TODO - Implementation
    this->line = 0;
    this->column = 0;
    int index = this->matrix.search(0,0);
    if(index != -1)
        this->current = this->matrix.elements[index].element;
    else
        this->current = 0;
}

void MatrixIterator::first() {
    //TODO - Implementation
    this->line = 0;
    this->column = 0;
    int index = this->matrix.search(0,0);
    if(index != -1)
        this->current = this->matrix.elements[index].element;
    else
        this->current = 0;
}

void MatrixIterator::next() {
    //TODO - Implementation
    if(valid())
    {
        if(this->column < this->matrix.columns - 1)
        {
            this->column++;
            int index = this->matrix.search(this->line, this->column);
            if(index != -1)
                this->current = this->matrix.elements[index].element;
            else
                this->current = 0;
        }
        else
        {
            this->line++;
            this->column = 0;
            int index = this->matrix.search(this->line, this->column);
            if(index != -1)
                this->current = this->matrix.elements[index].element;
            else
                this->current = 0;
        }
    }
}

bool MatrixIterator::valid() const {
    //TODO - Implementation
    if(this->line < this->matrix.lines && this->column < this->matrix.columns)
        return true;
    return false;
}

TElem MatrixIterator::getCurrent() const {
    //TODO - Implementation
    if(this->valid())
        return this->current;
    else
        throw std::exception();
}