// Section 20
// Challenge 2
//  Lists

#include <list>
#include <cctype>
#include <limits>

#include "Song.h"

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout << "Playing: " << song.get_name() << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    std::cout << std::endl;
    for(auto it = playlist.begin(); it != playlist.end(); ++it){
        std::cout << *it << std::endl;
    }
    
    play_current_song(current_song);
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    bool quit = false;
    do{
        // Show playlist and option list
        display_playlist(playlist, *current_song);
        display_menu();
        
        // Take user's choice
        char input;
        std::cin >> input;
        input = std::toupper(input);
        // NOTE: clean cin buffer to avoid skipping the "Enter song name: " input stream
        std::cin.ignore(1, '\n');
        
        switch(input){
            case 'F':
                current_song = playlist.begin();
                //play_current_song(*current_song);
                break;
            
            case 'N':
                if(*current_song == playlist.back()){
                    current_song = playlist.begin();
                }
                else{
                    ++current_song;                    
                }
                break;
            
            case 'P':
                if(current_song == playlist.begin()){
                    std::advance(current_song, playlist.size() - 1);
                }
                else{
                    --current_song;
                }
                break;
            
            case 'A':
                // Note:
                /* When declaring local variables in switch statement, use {} to wrap the code 
                 * that uses the local variables to avoid Error: Jump to case label
                 */
                {
                    std::string name, artist;
                    int rate;
                    std::cout << "Enter song name: ";
                    getline(std::cin, name);
                    std::cout << "Enter song artist: ";
                    getline(std::cin, artist);
                    std::cout << "Enter your rating: ";
                    std::cin >> rate;
                
                    playlist.emplace(current_song, name, artist, rate);
                }
                
                break;
            
            case 'L':
                display_playlist(playlist, *current_song);
                break;
                
            case 'Q':
                std::cout << "Quit confirmed" << std::endl;
                quit = true;
                break;
                
            default:
                std::cout << "WTF did you typy!!! Do it again with valid input!!!" << std::endl;
                break;
        }
        
    }while(!quit);

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}