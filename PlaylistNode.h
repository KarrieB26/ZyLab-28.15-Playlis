#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <iostream>
using namespace std;

class PlaylistNode {
public:
    // Constructors
    PlaylistNode();
    PlaylistNode(string uniqueID, string songName, string artistName, int songLength);

    // Accessors
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;

    // Mutators
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);

    // Output
    void PrintPlaylistNode() const;

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif
