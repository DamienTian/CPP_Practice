#include "DoubleLinkedList.h"  
	
DoubleLinkedList::DoubleLinkedList(){
    std::cout << "Double Linked List Constructor called" << std::endl;
}
	
DoubleLinkedList::~DoubleLinkedList(){
    std::cout << "Double Linked List Destructor called" << std::endl;
}

void DoubleLinkedList::addFront(int val){
    std::shared_ptr<Node> current {std::make_shared<Node>(val)};
    current->setNext(begin);
    current->getPrevious().reset();

    // if list is empty
    if(begin == nullptr){
        end = current;
    }
    else{
        begin->setPrevious(current);
    }

    begin = current;
    std::cout << "+++ add " << val << " to the front +++" << std::endl;
}

void DoubleLinkedList::forwardTraverse(){
    std::shared_ptr<Node> traversePtr {begin};
    std::cout << "--- Forward Traverse ------------------" << std::endl;
    while(traversePtr != nullptr){
        std::cout << traversePtr->getValue() << " ";
        traversePtr = traversePtr->getNext();
    }
    std::cout << std::endl << "------------------------------" << std::endl;
}

void DoubleLinkedList::backwardTraverse(){
    std::shared_ptr<Node> traversePtr {end};
    std::cout << "--- Backward Traverse -----------------" << std::endl;
    while(traversePtr != nullptr){
        std::cout << traversePtr->getValue() << " ";
        //std::cout << traversePtr->getPrevious()->value;
    }
    std::cout << std::endl << "------------------------------" << std::endl;
}