#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Init two vectors
    vector<int> vector1 (0);
    vector<int> vector2 (0);
    
    vector1.push_back(10);
    vector1.push_back(20);
    cout << "Elements in vector1: " << endl;
    cout << vector1.at(0) << "\t" << vector1.at(vector1.size() - 1) << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    cout << "Elements in vector2: " << endl;
    cout << vector2.at(0) << "\t" << vector2.at(vector2.size() - 1) << endl;
    
    vector<vector<int> > vector_2d (0);
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "Elements in vector_2d:  " << endl;
    for(int i = 0; i < vector_2d.size(); ++i){
        for(int j = 0; j < vector_2d.at(i).size(); ++j){
            cout << vector_2d.at(i).at(j) << "\t";
        }
        cout << endl;
    }
    
    cout << "Change vector1[0] to 1000 " << endl;
    vector1.at(0) = 1000;
    cout << "Elements in vector_2d after vector1 changed:  " << endl;
    for(int i = 0; i < vector_2d.size(); ++i){
        for(int j = 0; j < vector_2d.at(i).size(); ++j){
            cout << vector_2d.at(i).at(j) << "\t";
        }
        cout << endl;
    }
    cout << "Elements in vector1 after vector1 changed:  " << endl;
    cout << vector1.at(0) << "\t" << vector1.at(vector1.size() - 1) << endl;
    
    return 0;
}