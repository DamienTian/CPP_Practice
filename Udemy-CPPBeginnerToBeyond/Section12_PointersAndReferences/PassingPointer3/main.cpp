#include <iostream>

using namespace std;

void display(int* array, int sentinel); 

void display(int* array, int sentinel){
    while(*array != sentinel){
        cout << *array++ << endl;
    }
}

int main(){
    
    int arr[5] {1,2,3,4,-1};
    display(arr, -1);
    
    
    return 0;
}