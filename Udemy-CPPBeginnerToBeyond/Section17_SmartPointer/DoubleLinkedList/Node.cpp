#include <type_traits>
#include <string>
#include "Node.h"  

Node::Node(){
    value = 0;
    std::cout << "Node Constructor called on 0" << std::endl;
}

Node::Node(int val){
    value = val;
    std::cout << "Node Constructor called on: " << value << std::endl;
}
	
Node::~Node()
{	
    // previous->next = this->next;
    // next->previous = this->previous;
    // delete this;
    std::cout << "Node Destructor called on: " << value << std::endl;
}