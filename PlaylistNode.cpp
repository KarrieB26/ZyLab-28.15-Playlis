#include "PlaylistNode.h"

// Constructors
PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int length) {
    uniqueID = ID;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
}

// Accessors
string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

// Mutators
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* tmpNext = nextNodePtr;
    nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tmpNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

// Output
void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

// Default constructor implementation
Playlist::Playlist(){
   head = tail = 0;
}

// AddSong function implementation
void Playlist::AddSong(string id, string songname, string artistname, int length){
   PlaylistNode* n = new PlaylistNode(id, songname, artistname, length);
   if (head == 0){
       head = tail = n;
   }
   else{
       n->InsertAfter(tail);
       tail = n;
      }
   }


// RemoveSong function implementation
bool Playlist::RemoveSong(string id){
   if (head == nullptr){
       cout << "\nPlaylist is empty." << endl;
       return false;
   }

   PlaylistNode* curr = head;
   PlaylistNode* prev = nullptr;

   while (curr != nullptr){
       if (curr->GetID() == id){
           break;
       }
       prev = curr;
       curr = curr->GetNext();
   }

   if (curr == nullptr){
       cout << "Song not found." << endl;
       return false;
   }
   else{
       cout << "\"" << curr->GetSongName() << "\" removed." << endl;

       if (prev != nullptr)
           prev->SetNext(curr->GetNext());
       else
           head = curr->GetNext();

       if (tail == curr)
           tail = prev;

       delete curr;
       return true;
   }
}


// ChangePosition function implementation
bool Playlist::ChangePosition(int oldPos, int newPos){
   if (head == NULL){
       cout << "\nPlaylist is empty." << endl;
       return false;
   }


   PlaylistNode* prev = NULL;
   PlaylistNode* curr = head;

   int pos;
   if (head == NULL || head == tail)
       return false;

   //first locate the node that is to be move
   for (pos = 1; curr != NULL && pos < oldPos; pos++){
       prev = curr;
       curr = curr->GetNext();
   }
   if (curr != NULL){
       string currentSong = curr->GetSongName();

       if (prev == NULL)
           head = curr->GetNext();
       else{
           prev->SetNext(curr->GetNext());
       }

       if (curr == tail) //if we removed the tail node
           tail = prev;

       PlaylistNode* curr1 = curr;
       prev = NULL;
       curr = head;
       //now locate the new position
       for (pos = 1; curr != NULL && pos < newPos; pos++){
           prev = curr;
           curr = curr->GetNext();
       }

       //insert in located position

       if (prev == NULL){
           curr1->SetNext(head);
           head = curr1;
       }
       else
           curr1->InsertAfter(prev);

       if (curr == NULL)
           tail = curr1;


       cout << "\"" << currentSong << "\" moved to position " << newPos << endl;
       return true;

   }
   else{
       cout << "Song's current position is invalid" << endl;
       return false;
   }
}
// SongsByArtist function implementation
void Playlist::SongsByArtist(string artist){
   if (head == NULL)
       cout << "\nPlaylist is empty" << endl;
   else{
       PlaylistNode* curr = head;
       int i = 1;
       while (curr != NULL){
          
           if (curr->GetArtistName() == artist){
              
               cout << endl << i << "." << endl;
               curr->PrintPlaylistNode();              
           }
           curr = curr->GetNext();
           i++;
       }
   }
}

// TotalTime function implementation
int Playlist::TotalTime(){
   int total = 0;
   PlaylistNode* curr = head;

   while (curr != NULL){
      
       total += curr->GetSongLength();
       curr = curr->GetNext();
   }

   return total;
}


// PrintList function implementation
void Playlist::PrintList(){
   
   if (head == NULL)
       cout << "\nPlaylist is empty" << endl;
   else{
      
       PlaylistNode* curr = head;
       int i = 1;
       while (curr != NULL){
          
           cout << endl << i++ << "." << endl;
           curr->PrintPlaylistNode();          
           curr = curr->GetNext();
           
       }
   }
}


