#include "Node.h"
#include "DoubleLinkedList.h"

int main(){
    DoubleLinkedList dll;
    dll.addFront(5);
    dll.addFront(4);
    dll.addFront(3);
    dll.addFront(2);
    dll.addFront(1);

    dll.forwardTraverse();
    return 0;
}
