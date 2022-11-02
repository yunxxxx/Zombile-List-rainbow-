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

#pragma once
#ifndef BO_LINKEDLIST_H
#define BO_LINKEDLIST_H

using namespace std;

//call the zombie and node class on the top so c++ knows what I'm talking about.
class node;

class zombie;

//linkedList class
class linkedList {
private:
    node *head;

public:
    linkedList();

    linkedList(char color, int action);

    void addZombieToHead(char color, int action);

    void addZombieToEnd(char color, int action);

    void addZombieToIndex(char color, int action, int index);

    char removeHead();

    char removeEnd();

    void removeData(zombie sameZombie);

    void removeAllOf(zombie sameZombie);

    bool ElementExists(zombie sameZombie);

    node *find(zombie sameZombie);

    int indexOf(zombie sameZombie);

    char retrieveFront();

    char retrieveEnd();

    char retrieveIndex(int index);

    void printList();

    void empty();

    int length();

    bool isEmpty();

};

//node class
class node {
private:
    zombie *thisZombie;
    node *nextZombie;
public:
    node();

    node(zombie *newZombie);

    ~node();

    zombie *getZombie();

    node *getNext();

    void setZombie(zombie *newZombie);

    void setNextZombie(node *nextZombie);
};

//zombie class
class zombie {
private:
    char color;
    int action;
public:
    char getColor();

    int getAction();

    zombie(char color, int action);

    bool operator==(const zombie &other);
};

#endif
