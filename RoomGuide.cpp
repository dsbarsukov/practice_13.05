#include "RoomGuide.h"
#include <iostream>

using namespace std;

// ===== Room =====

Room::Room(string roomName, string roomType, int roomCapacity) {
    name = roomName;
    type = roomType;
    capacity = roomCapacity;
    visitCount = 0;
}

void Room::printInfo() {
    cout << "Название: " << name << endl;
    cout << "Тип: " << type << endl;
    cout << "Вместимость: " << capacity << endl;
    cout << "Количество посещений: " << visitCount << endl;
}

void Room::visit() {
    visitCount++;
}

int Room::getVisitCount() {
    return visitCount;
}

int Room::getCapacity() {
    return capacity;
}

string Room::getName() {
    return name;
}

string Room::getType() {
    return type;
}

// ===== Guide =====

Guide::Guide(string guideName) {
    name = guideName;
    currentRoom = nullptr;
}

void Guide::goToRoom(Room* room) {
    currentRoom = room;
    currentRoom->visit();

    cout << "Гид " << name << " провёл группу в комнату: " << currentRoom->getName() << endl;
}

void Guide::printCurrentRoomInfo() {
    if (currentRoom == nullptr) {
        cout << "Группа пока не находится ни в одной комнате." << endl;
    }
    else {
        cout << "Текущая комната:" << endl;
        currentRoom->printInfo();
    }
}

void Guide::printGuideAndCurrentRoomInfo() {
    cout << "Гид: " << name << endl;

    if (currentRoom == nullptr) {
        cout << "Группа пока не находится ни в одной комнате." << endl;
    }
    else {
        cout << "Текущая комната:" << endl;
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() {
    return currentRoom;
}