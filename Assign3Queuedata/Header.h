#pragma once
#include <iostream>
#include <string>
#include "QueueTemp.h"
using namespace std;

string menu() {
    int how_Many_Total, how_Many, new_Value;
    cout << "How big do you want the max size of the queue be? " << endl;
    cin >> how_Many_Total;

    Queue<int> q(how_Many_Total);
    cout << "How many items do you want to enter? " << endl;
    cin >> how_Many;
    for (int i = 0; i < how_Many; i++) {
        cout << "Enter a number" << endl;
        cin >> new_Value;
        q.enqueue(new_Value);
    };
    string end;
    while (end != "finished") {
        string menu_option;
        //user prompts
        cout << "Enter the option you want to perform: " << endl;
        cout << "push" << endl
            << "pop" << endl
            << "front" << endl
            << "size" << endl
            << "empty" << endl
            << "moveToRear" << endl
            << "display" << endl
            << "end" << endl;
        cin >> menu_option;
    if (menu_option == "push") {
        cout << "How many items do you want to enter? " << endl;
        cin >> how_Many;
        for (int i = 0; i < how_Many; i++) {
            cout << "Enter a number" << endl;
            cin >> new_Value;
            q.enqueue(new_Value);
        };
    }
    else if (menu_option == "pop") {
        q.dequeue();
    
    }
    else if (menu_option == "front") {
        cout << endl;
        cout << q.peek() << endl;
        cout << endl;
    }
    else if (menu_option == "size") {
        cout << endl;
        cout << q.count() << endl;
        cout << endl;
    }
    else if (menu_option == "empty") {
        if (q.isEmpty()) {
            cout << "There are no numbers in the queue." << endl;
        }
        else {
            cout << "There are "<< q.count() << " numbers in the queue." << endl;
        }

    }
    else if (menu_option == "moveToRear") {
        q.move_to_rear();
    }
    else if (menu_option == "display") {
        cout << endl;
        q.display();
        cout << endl;
    }
    else if (menu_option == "end") {
        // Ends program logic
        end = "finished";
    }
    else {
        // If the user enters something other than one of the 13 prompts
        cout << "Make sure you enter a valid option." << endl;
    }
}
return "done";
}