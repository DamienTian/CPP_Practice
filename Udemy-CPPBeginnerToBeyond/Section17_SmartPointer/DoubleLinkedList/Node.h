#ifndef NODE_H
#define NODE_H
#pragma once

#include <iostream>
#include <memory>

/*
TODO:
【】With the current Node struct, there is no way to by backward traverse, because the previous Node is weak_ptr
	Possible solution:
	- Change previous to strong, free the space when Node destructor is called 
		(could cause memory leak, remember to use customized destructor)
	- Stores a previous value in the Node

*/

// Node for double linked list implemented by smart pointer
// template <class T>
class Node  
{
	private:
		// std::weak_ptr<Node> previous;
		std::shared_ptr<Node> previous;
		int value;
		std::shared_ptr<Node> next;

	public:
		Node();
		Node(int val);
		~Node();

		//std::weak_ptr<Node>& getPrevious(){ return previous; }
		std::shared_ptr<Node>& getPrevious(){ return previous; }
		//void setPrevious(std::weak_ptr<Node>& p){ previous = p; }
		void setPrevious(std::shared_ptr<Node>& p){ previous = p; }

		int getValue(){ return value; }
		void setValue(int val){ value = val; }

		std::shared_ptr<Node>& getNext(){ return next; }
		//void setNext(std::weak_ptr<Node> n){ next = n; }
		void setNext(std::shared_ptr<Node>& n){ next = n; }
};
#endif