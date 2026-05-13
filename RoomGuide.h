#ifndef ROOM_GUIDE_H
#define ROOM_GUIDE_H

#include <string>

using namespace std;

class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    Room(string roomName, string roomType, int roomCapacity);

    void printInfo();
    void visit();

    int getVisitCount();
    string getName();
};

class Guide {
private:
    string name;
    Room* currentRoom;

public:
    Guide(string guideName);

    void goToRoom(Room* room);
    void printCurrentRoomInfo();

    Room* getCurrentRoom();
};

#endif