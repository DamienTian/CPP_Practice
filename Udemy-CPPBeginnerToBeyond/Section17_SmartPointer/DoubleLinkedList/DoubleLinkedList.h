#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#pragma once

#include "Node.h"

class DoubleLinkedList  
{
	private:
		std::shared_ptr<Node> begin;
		std::shared_ptr<Node> end;
	public:

		DoubleLinkedList();
		~DoubleLinkedList();

		std::weak_ptr<Node> getBegin() { return begin; }
		//void setBegin(std::weak_ptr<Node> p){ begin = p; }
		void setBegin(std::shared_ptr<Node> p){ begin = p; }

		std::weak_ptr<Node> getEnd() { return end; }
		//void setEnd(std::weak_ptr<Node> p){ end = p; }
		void setEnd(std::shared_ptr<Node> p){ end = p; }

		void addFront(int val);
		void addAfter(std::shared_ptr<Node>, int val);
		void addBefore(std::shared_ptr<Node>, int val);
		void addEnd(int val);
		void deleteNode(std::shared_ptr<Node> node);
		void forwardTraverse();
		void backwardTraverse();

};
#endif