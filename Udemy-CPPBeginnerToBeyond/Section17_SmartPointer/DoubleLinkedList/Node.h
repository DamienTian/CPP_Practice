#ifndef NODE_H
#define NODE_H
#pragma once

#include <iostream>
#include <memory>

// Node for double linked list implemented by smart pointer
// template <class T>
class Node  
{
		std::weak_ptr<Node> previous;
		int value;
		std::shared_ptr<Node> next;

	public:
		Node();
		Node(int val);
		~Node();

		std::weak_ptr<Node>& getPrevious(){ return previous; }
		void setPrevious(std::weak_ptr<Node>& p){ previous = p; }
		void setPrevious(std::shared_ptr<Node>& p){ previous = p; }

		int getValue(){ return value; }
		void setValue(int val){ value = val; }

		std::shared_ptr<Node>& getNext(){ return next; }
		//void setNext(std::weak_ptr<Node> n){ next = n; }
		void setNext(std::shared_ptr<Node>& n){ next = n; }
};
#endif