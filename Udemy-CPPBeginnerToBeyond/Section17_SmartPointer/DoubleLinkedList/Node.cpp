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
    std::cout << "Node Destructor called on: " << value << std::endl;
}