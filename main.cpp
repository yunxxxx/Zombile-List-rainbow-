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

using namespace std;

//call all the class at first so c++ know what i'm talking about
char getRandomColor(int colorNum);

int getRandomAction();

void printColor(char color);

//main
int main(int argc, char **argv) {
    //make sure the random in the function is all reamdom
    srand(time(0));
    // the variable will be use in the method
    char color;
    int action, userPickRound, roundNum = 0;
    int colorNum = rand() % 5;

    color = getRandomColor(colorNum);
    action = getRandomAction();
    linkedList *zombieList = new linkedList(color, action);
    cout << "Zombies Part Start!" << endl;
    //At the game begin, put 10 different zombie in order before game start.
    for (int i = 0; i < 9; i++) {
        colorNum = rand() % 5;
        action = rand() % 6;
        color = getRandomColor(colorNum);
        action = getRandomAction();
        zombieList->addZombieToEnd(color, action);
    }
    //ask user how make round they want play first
    cout << "How may round of zombie party do you want start with? (enter 0 to end the game)" << endl;
    cout << ">> ";
    cin >> userPickRound;

    //if there is more than 0 round left, keep play the zombie party
    while (!(zombieList->isEmpty()) && userPickRound > 0) {
        cout << "Round" << roundNum << endl;
        cout << "The Zombie Party keeps on groaning!" << endl;
        cout << "Size: " << zombieList->length() << " :: ";
        zombieList->printList();
        cout << endl;
        colorNum = rand() % 5;
        color = getRandomColor(colorNum);
        action = rand() % 7;
        //use switch to give different action to the party.
        switch (action) {
            case (0): {
                zombieList->addZombieToHead(color, action);
                printColor(color);
                cout << "zombie jumps in the front of the line! (ENGINE)" << endl;
                break;
            }
            case (1): {
                zombieList->addZombieToEnd(color, action);
                printColor(color);
                cout << "zombie pulls up the rear! (CABOOSE) " << endl;
                break;
            }
            case (2): {
                int index = rand() % (zombieList->length());
                zombieList->addZombieToIndex(color, action, index);
                printColor(color);
                cout << "zombie jumps in to " << index + 1 << " of the team! (Jump in the Line!)" << endl;
                break;
            }
            case (3): {
                zombie newZombie(color, action);
                if (zombieList->ElementExists(newZombie)) {
                    zombieList->removeAllOf(newZombie);
                    cout << "Every ";
                    printColor(color);
                    cout << "zombie is out!(Everyone Out!)" << endl;
                } else {
                    cout << "No ";
                    printColor(color);
                    cout << "Zombie could be Out! (Everyone Out! when no same zombie exist)" << endl;
                }
                break;
            }
            case (4): {
                zombie newZombie(color, action);
                if (zombieList->ElementExists(newZombie)) {
                    zombieList->removeData(newZombie);
                    cout << "First ";
                    printColor(color);
                    cout << "Zombie Got Killed!(You’re done!)" << endl;
                } else {
                    cout << "No ";
                    printColor(color);
                    cout << "Zombie got killed (You’re done! when no same zombie exist)" << endl;
                }
                break;
            }
            case (5): {
                zombieList->addZombieToHead(color, action);
                zombieList->addZombieToEnd(color, action);
                printColor(color);
                cout << "zombie brings its friends to the party (BRAINS!)" << endl;
                break;
            }
            case (6): {
                zombieList->addZombieToHead(color, action);
                zombieList->addZombieToEnd('R', action);
                zombieList->addZombieToEnd('Y', action);
                zombieList->addZombieToEnd('G', action);
                zombieList->addZombieToEnd('B', action);
                zombieList->addZombieToEnd('M', action);
                zombieList->addZombieToEnd('C', action);
                printColor(color);
                cout << "zombie brought a whole party itself! (RAINBOW BRAINS!)" << endl;
                break;
            }
        }
        //print the all the zombie after the action over again
        cout << "The conga line is now:  " << endl;
        cout << "Size: " << zombieList->length() << " :: ";
        zombieList->printList();
        cout << endl;
        cout << endl;
        roundNum++;
        //let the round number decrease 1 after one round is over.
        userPickRound--;
        //if the round number get to 0, ask the use if the want play more.
        if (userPickRound == 0) {
            cout << "All round is over" << endl;
            cout << "Enter how many round more you want play! (0 to end the party!)" << endl;
            cin >> userPickRound;
            cout << endl;
        }
    }
    //after the round over, print our the over message and delete the linked list
    cout << "Party is Over!" << endl;
    zombieList->empty();
    delete zombieList;

}

//this method will return a random color of zombie to put in to linked list
char getRandomColor(int colorNum) {
    switch (colorNum) {
        case (0):
            return 'R';
        case (1):
            return 'Y';
        case (2):
            return 'G';
        case (3):
            return 'B';
        case (4):
            return 'M';
        case (5):
            return 'C';
    }
    return 'x';
}

//this method will return a random action number to zombie
int getRandomAction() {
    int actionNum = rand() % 6;
    return actionNum;
}

//this method will print out the color tex when pass the color char for it.
void printColor(char color) {
    switch (color) {
        case ('R'):
            cout << "\x1B[31m[R]\033[0m ";
            break;
        case ('Y'):
            cout << "\x1B[33m[Y]\033[0m ";
            break;
        case ('G'):
            cout << "\x1B[32m[G]\033[0m ";
            break;
        case ('B'):
            cout << "\x1B[34m[B]\033[0m ";
            break;
        case ('M'):
            cout << "\x1B[35m[M]\033[0m ";
            break;
        case ('C'):
            cout << "\x1B[36m[C]\033[0m  ";
            break;
    }
}