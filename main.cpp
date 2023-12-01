#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl << "Choose an option:" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
    
    return headNode;  
}

int main() {
    string playlistTitle;
    PlaylistNode* headNode = nullptr;

    // Get playlist title
    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);

    char option;
    do {
        PrintMenu(playlistTitle);
        cin >> option;
        cin.ignore();
        headNode = ExecuteMenu(option, playlistTitle, headNode);
    } while (option != 'q');

    return 0;
}


