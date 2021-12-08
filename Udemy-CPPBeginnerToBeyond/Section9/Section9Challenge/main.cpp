#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

void selectionHandler(char selection, vector<int>& collections){
    switch(selection){
        case 'p':
        case 'P':   // print vector
            cout << "[ ";
            for (auto c : collections){
                cout << c << " ";
            }
            cout << "]";
            
            if(collections.empty()){
                cout << " - the list is empty" << endl;
            }
            else{
                cout << endl;
            }
            break;
            
        case 'a':
        case 'A':   // Add element
            int newElement;
            cout << "Enter the element you want to add: ";
            cin >> newElement;
            // Handle if the input is not integer
            while(cin.fail()){
                cout << "Not an integer, pleaer enter an integer: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> newElement;
            }
            collections.push_back(newElement);
            break;
        
        case 'm':
        case 'M':  // Display mean of numbers
            if(collections.empty()){
                cout << "Unable to calculate mean, because the collection vector is empty." << endl;
            }
            else{
                float mean = static_cast<float>(accumulate(collections.begin(), collections.end(), 0)) / collections.size();
                cout << "The mean is " << mean << endl;
            }
            break;
        
        case 's':
        case 'S':   // Display smallest
            if(collections.empty()){
                cout << "Unable to find min, because the collections is empty" << endl;
            }
            else{
                cout <<  "The min value in vector is " << *min_element(collections.begin(), collections.end()) << endl;
            }
            break;
        
        case 'l':
        case 'L':   // Display largest
            if(collections.empty()){
               cout << "Unable to find max, because the collections is empty" << endl;
            }
            else{
                cout <<  "The max value in vector is " << *max_element(collections.begin(), collections.end()) << endl;
            }
            break;
        
        case 'q':
        case 'Q':   //Quit
            cout << "Quit" << endl;
            break;
        
        default:    // Handle unknown input
            cout << "Unknown input, Please try again" << endl;
            break;
    }
}

int main(){
    vector<int> collections {};
    char selection;
    
    do {
        cout << "Options (accept low/upper cases):\n \
                        P - Print numbers in vector\n \
                        A - Add a number into vector\n \
                        M - Display mean of the numbers\n \
                        S - Display the smallest number\n \
                        L - Display the smallest number\n \
                        Q - Quit the program" <<endl;
        cout << "\nEnter your choice: ";
        cin >> selection;
        
        selectionHandler(selection, collections);
        
    }while(selection != 'q' && selection != 'Q');
    
    return 0;
}