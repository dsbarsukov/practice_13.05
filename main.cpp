#include <iostream>
#include "RoomGuide.h"

using namespace std;

void printMenu() {
    cout << endl;
    cout << "===== Экскурсия по офису Яндекса =====" << endl;
    cout << "1. Посетить комнату" << endl;
    cout << "2. Информация о текущей комнате" << endl;
    cout << "3. Показать все посещённые комнаты" << endl;
    cout << "4. Самая посещаемая комната" << endl;
    cout << "5. Показать список всех комнат" << endl;
    cout << "6. Общее количество посещений" << endl;
    cout << "7. Информация о гиде и текущей комнате" << endl;
    cout << "8. Выход" << endl;
    cout << "Выберите пункт: ";
}

void printRoomsList(Room* rooms[], int size) {
    cout << endl;
    cout << "Доступные комнаты:" << endl;

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << rooms[i]->getName() << " (" << rooms[i]->getType() << ", вместимость: " << rooms[i]->getCapacity() << ")" << endl;
    }
}

void printVisitedRooms(Room* rooms[], int size) {
    bool found = false;

    cout << endl;
    cout << "Посещённые комнаты:" << endl;

    for (int i = 0; i < size; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            found = true;
            rooms[i]->printInfo();
            cout << endl;
        }
    }

    if (!found) {
        cout << "Пока не посещено ни одной комнаты." << endl;
    }
}

void printMostVisitedRoom(Room* rooms[], int size) {
    Room* mostVisitedRoom = nullptr;

    for (int i = 0; i < size; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            if (mostVisitedRoom == nullptr || rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
                mostVisitedRoom = rooms[i];
            }
        }
    }

    if (mostVisitedRoom == nullptr) {
        cout << "Пока нет посещённых комнат." << endl;
    }
    else {
        cout << "Самая посещаемая комната: " << mostVisitedRoom->getName() << endl;
        cout << "Количество посещений: " << mostVisitedRoom->getVisitCount() << endl;
    }
}

void printTotalVisits(Room* rooms[], int size) {
    int totalVisits = 0;

    for (int i = 0; i < size; i++) {
        totalVisits += rooms[i]->getVisitCount();
    }

    cout << endl;
    cout << "Общее количество посещений всех комнат: " << totalVisits << endl;
}

int main() {
    const int ROOMS_COUNT = 5;
    const int GROUP_SIZE = 10;

    Room* rooms[ROOMS_COUNT];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван");

    int choice = 0;

    while (choice != 8) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                printRoomsList(rooms, ROOMS_COUNT);

                int roomNumber;
                cout << endl;
                cout << "Введите номер комнаты: ";
                cin >> roomNumber;

                if (roomNumber >= 1 && roomNumber <= ROOMS_COUNT) {
                    Room* selectedRoom = rooms[roomNumber - 1];

                    if (selectedRoom->getName() == "Серверная" && GROUP_SIZE > selectedRoom->getCapacity()) {
                        cout << "Нельзя посетить серверную: группа слишком большая." << endl;
                        cout << "Размер группы: " << GROUP_SIZE << endl;
                        cout << "Вместимость серверной: " << selectedRoom->getCapacity() << endl;
                    }
                    else {
                        guide.goToRoom(selectedRoom);
                    }
                }
                else {
                    cout << "Некорректный номер комнаты." << endl;
                }

                break;
            }

            case 2: {
                cout << endl;
                guide.printCurrentRoomInfo();
                break;
            }

            case 3: {
                printVisitedRooms(rooms, ROOMS_COUNT);
                break;
            }

            case 4: {
                cout << endl;
                printMostVisitedRoom(rooms, ROOMS_COUNT);
                break;
            }

            case 5: {
                printRoomsList(rooms, ROOMS_COUNT);
                break;
            }

            case 6: {
                printTotalVisits(rooms, ROOMS_COUNT);
                break;
            }

            case 7: {
                cout << endl;
                guide.printGuideAndCurrentRoomInfo();
                break;
            }

            case 8: {
                cout << "Завершение программы..." << endl;
                break;
            }

            default: {
                cout << "Некорректный пункт меню." << endl;
                break;
            }
        }
    }

    for (int i = 0; i < ROOMS_COUNT; i++) {
        delete rooms[i];
    }

    return 0;
}