/* Author: Yuan Bo
 * Date: 4/22 2021
 * Description:
 * This assignment have Linked List Class and a Node Class
 * The Linked List should contain : Constructor, Destructor, AddToFront, AddToEnd, AddAtIndex, RemoveFromFront, RemoveFromEnd,
 * RemoveTheFirst, RemoveAllOf, ElementExists, Find, IndexOf, RetrieveFront , RetrieveEnd , Retrieve, PrintList, Empty, Length.
 *
 * There are about 3~5 methods list above did not been use in main and the linkedList class. However, author has tested all of them
 * Include Extra Credit: Color your Zombies
 * */

#include "bo_linkedList.h"
#include <iostream>
#include <fstream>

using namespace std;


//Linked List
linkedList::linkedList() {
    this->head = NULL;
}

//linkedList will able to get a char for color and a action number to crate the head zombie node.
linkedList::linkedList(char color, int action) {
    zombie *newZombie = new zombie(color, action);
    this->head = new node(newZombie);
}

//this method will add a zombie to head
void linkedList::addZombieToHead(char color, int action) {
    node *newNode = new node();
    zombie *newZombie = new zombie(color, action);
    newNode->setZombie(newZombie);
    newNode->setNextZombie(head);
    head = newNode;
}

//this method will add a zombie to end
void linkedList::addZombieToEnd(char color, int action) {
    node *newNode = new node();
    newNode->setZombie(new zombie(color, action));
    if (head == NULL) {
        head = newNode;
    } else {
        node *nodeChecker = head;
        while (nodeChecker->getNext() != NULL) {
            nodeChecker = nodeChecker->getNext();
        }
        nodeChecker->setNextZombie(newNode);
    }
}

//this method will add a zombie to a user pick position
void linkedList::addZombieToIndex(char color, int action, int index) {
    if (index == 0) {
        addZombieToHead(color, action);
    } else {
        node *newNode = new node();
        newNode->setZombie(new zombie(color, action));
        node *nodeChecker = head;
        for (int i = 0; i < index - 1; i++) {
            nodeChecker = nodeChecker->getNext();
        }
        newNode->setNextZombie(nodeChecker->getNext());
        nodeChecker->setNextZombie(newNode);
    }
}

//this method will remove the first element and use pointer delete first data (It will return the zombie color after delete this zombie)
char linkedList::removeHead() {
    if (head == NULL) {
        return 'x';
    }
    char zombieColor;
    zombieColor = head->getZombie()->getColor();
    node *newNode = head;
    this->head = head->getNext();
    delete newNode;
    return zombieColor;
}

//this method will remove the last element and use pointer delete last data (It will return the zombie color after delete this zombie)
char linkedList::removeEnd() {
    if (this->head == NULL) {
        return 'x';
    }
    if (head->getNext() == NULL) {
        return removeHead();
    }

    char zombieColor;
    node *newNode = head;
    while (newNode->getNext()->getNext() != NULL) {
        newNode = newNode->getNext();
    }
    zombieColor = newNode->getNext()->getZombie()->getColor();
    delete newNode->getNext();
    newNode->setNextZombie(NULL);
    return zombieColor;
}

//this method will take a zombie and check is there a zombie have the same color with it. Then use pointer to delete the first one.
void linkedList::removeData(zombie sameZombie) {
    bool deletedChecker = false;
    char zombieColor = head->getZombie()->getColor();
    zombie compareHeadZombie(zombieColor, 0);
    if (compareHeadZombie == sameZombie) {
        removeHead();
        zombieColor = head->getZombie()->getColor();
        compareHeadZombie = zombie(zombieColor, 0);
        deletedChecker = true;
    }
    node *nodeChecker = head;
    while (!deletedChecker && nodeChecker->getNext() != NULL) {
        zombieColor = nodeChecker->getNext()->getZombie()->getColor();
        zombie compareZombie(zombieColor, 0);
        if (compareZombie == sameZombie) {
            deletedChecker = true;
            delete nodeChecker->getNext();
            nodeChecker->setNextZombie(nodeChecker->getNext()->getNext());
        } else {
            nodeChecker = nodeChecker->getNext();
        }
    }
}

//this method will take a zombie and check is there any zombie have the same color with it. Then use pointer to delete the all of them.
void linkedList::removeAllOf(zombie sameZombie) {
    char zombieColor = head->getZombie()->getColor();
    zombie compareHeadZombie(zombieColor, 0);
    while (compareHeadZombie == sameZombie) {
        removeHead();
        zombieColor = head->getZombie()->getColor();
        compareHeadZombie = zombie(zombieColor, 0);
    }
    node *nodeChecker = head;
    while (nodeChecker->getNext() != NULL) {
        zombieColor = nodeChecker->getNext()->getZombie()->getColor();
        zombie compareZombie(zombieColor, 0);
        if (compareZombie == sameZombie) {
            delete nodeChecker->getNext();
            nodeChecker->setNextZombie(nodeChecker->getNext()->getNext());
        } else {
            nodeChecker = nodeChecker->getNext();
        }
    }
}

//this method will get take a zombie to see if there is any zombie have same color with it and then return a boolean.
bool linkedList::ElementExists(zombie sameZombie) {
    node *nodeChecker = head;
    char zombieColor;
    while (nodeChecker->getNext() != NULL) {
        zombieColor = nodeChecker->getZombie()->getColor();
        zombie compareHeadZombie(zombieColor, 0);
        if (compareHeadZombie == sameZombie) {
            return true;
        }
        nodeChecker = nodeChecker->getNext();
    }
    zombieColor = nodeChecker->getZombie()->getColor();
    zombie compareHeadZombie(zombieColor, 0);
    if (compareHeadZombie == sameZombie) {
        return true;
    }
    return false;
}

//this method will take a zombie and return a node with the first zombie have the same color. Return NULL if couldn't find any.
node *linkedList::find(zombie sameZombie) {
    node *nodeChecker = head;
    char zombieColor;
    while (nodeChecker->getNext() != NULL) {
        zombieColor = nodeChecker->getZombie()->getColor();
        zombie compareHeadZombie(zombieColor, 0);
        if (compareHeadZombie == sameZombie) {
            return nodeChecker;
        }
        nodeChecker = nodeChecker->getNext();
    }
    zombieColor = nodeChecker->getZombie()->getColor();
    zombie compareHeadZombie(zombieColor, 0);
    if (compareHeadZombie == sameZombie) {
        return nodeChecker;
    }
    return NULL;
}

//This method will take a zombie and looking for the first zombie have the same color and return the index. It will return -1 if couldn't find any
//Suggest to use this method with ElementExists method.
int linkedList::indexOf(zombie sameZombie) {
    int index = 0;
    node *nodeChecker = head;
    char zombieColor;
    while (nodeChecker->getNext() != NULL) {
        zombieColor = nodeChecker->getZombie()->getColor();
        zombie compareHeadZombie(zombieColor, 0);
        if (compareHeadZombie == sameZombie) {
            return index;
        }
        nodeChecker = nodeChecker->getNext();
        index++;
    }
    zombieColor = nodeChecker->getZombie()->getColor();
    zombie compareHeadZombie(zombieColor, 0);
    if (compareHeadZombie == sameZombie) {
        return index;
    }
    return -1;
}

//This method will return the first zombie's color
char linkedList::retrieveFront() {
    return head->getZombie()->getColor();
}

//This method will return the last zombie's color
char linkedList::retrieveEnd() {
    if (head->getNext() == NULL) {
        return retrieveFront();
    }
    node *newNode = head;
    while (newNode->getNext() != NULL) {
        newNode = newNode->getNext();
    }
    return newNode->getZombie()->getColor();
}

//This method will return a zombie's color with user pick index. Return X if user picked some index greater than the length of the list
char linkedList::retrieveIndex(int index) {
    if (index < length()) {
        if (index == 0) {
            return retrieveFront();
        }
        node *newNode = head;
        for (int i = 0; i < index; i++) {
            newNode = newNode->getNext();
        }
        return newNode->getZombie()->getColor();
    } else {
        return 'x';
    }
}

//this method will print out the list with colored zombie
void linkedList::printList() {
    node *newNode = head;
    char color;
    while (newNode->getNext() != NULL) {
        color = newNode->getZombie()->getColor();
        switch (color) {
            case ('R'):
                cout << "\x1B[31m[R]\033[0m  ";
                break;
            case ('Y'):
                cout << "\x1B[33m[Y]\033[0m  ";
                break;
            case ('G'):
                cout << "\x1B[32m[G]\033[0m  ";
                break;
            case ('B'):
                cout << "\x1B[34m[B]\033[0m  ";
                break;
            case ('M'):
                cout << "\x1B[35m[M]\033[0m  ";
                break;
            case ('C'):
                cout << "\x1B[36m[C]\033[0m  ";
                break;
        }
        newNode = newNode->getNext();
    }
    color = newNode->getZombie()->getColor();
    switch (color) {
        case ('R'):
            cout << "\x1B[31m[R]\033[0m  ";
            break;
        case ('Y'):
            cout << "\x1B[33m[Y]\033[0m  ";
            break;
        case ('G'):
            cout << "\x1B[32m[G]\033[0m  ";
            break;
        case ('B'):
            cout << "\x1B[34m[B]\033[0m  ";
            break;
        case ('M'):
            cout << "\x1B[35m[M]\033[0m  ";
            break;
        case ('C'):
            cout << "\x1B[36m[C]\033[0m  ";
            break;
    }
}

//this method will empty the list by use pointer delete every element of the linkedList
void linkedList::empty() {
    while (head->getNext() != NULL) {
        delete head;
        head = head->getNext();
    }
    delete head;
    cout << "list deleted" << endl;
}

//this method will return the length of the linkedList start from 1
int linkedList::length() {
    int length = 1;
    node *nodeChecker = head;
    while (nodeChecker->getNext() != NULL) {
        nodeChecker = nodeChecker->getNext();
        length++;
    }
    return length;
}

//this method will return a boolean to tell the user if the linkedList is empty
bool linkedList::isEmpty() {
    if (this->head == NULL) {
        return true;
    }
    return false;
}

//node
node::node() {
    thisZombie = NULL;
    nextZombie = NULL;
}

node::node(zombie *newZombie) {
    thisZombie = newZombie;
    nextZombie = NULL;
}

//because the node user pointer as element, so only delete this element and keep the next on the memory.
node::~node() {
    delete thisZombie;
}

//this method will set the element in this node
void node::setZombie(zombie *newZombie) {
    this->thisZombie = newZombie;
}

//this method will set the next element in this node
void node::setNextZombie(node *nextZombie) {
    this->nextZombie = nextZombie;
}

//this method will return next node of this node
node *node::getNext() {
    return this->nextZombie;
}

//this method will return the element in this node
zombie *node::getZombie() {
    return this->thisZombie;
}

//zombie
//zombie will have the color of the zombie of the action
zombie::zombie(char color, int action) {
    this->color = color;
    this->action = action;
}

//can get the color of the zombie
char zombie::getColor() {
    return this->color;
}

//can get the action number of the zombie
int zombie::getAction() {
    return this->action;
}

//override the operator '=='
//only check if two zombie have the same color.
bool zombie::operator==(const zombie &other) {
    return (this->color == other.color);
}