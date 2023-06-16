#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

#include "SortedIteratedList.h"
#include "ListIterator.h"

int main(){
    // create a SortedIteratedList with the relation: <
    Relation r = [](TComp e1, TComp e2) { return e1 <= e2; };
    SortedIteratedList list = SortedIteratedList(r);

    // add a few elements
    list.add(5);
    list.add(3);
    list.add(10);
    list.add(1);
    list.add(2);
    list.add(1);
    list.add(20);

    // create an iterator for the list
    ListIterator it = list.first();

    // print the elements using the iterator
    list.print();

    // remove the first element of the list
    it.first();
    list.remove(it);

    // print the elements using the iterator
    list.print();

    // remove the last element of the list
    for(int i=0; i<list.size()-1; i++)
        it.next();
    list.remove(it);

    // print the elements using the iterator
    list.print();

    // remove the middle element of the list
    it.first();
    it.next();
    list.remove(it);

    // print the elements using the iterator
    list.print();

    it.first();
    it.next();
    list.remove(it);

    list.print();

    // clear the list with destructor
    list.~SortedIteratedList();

    testAll();
    testAllExtended();
    std::cout<<"Finished IL Tests!"<<std::endl;
	system("pause");
}