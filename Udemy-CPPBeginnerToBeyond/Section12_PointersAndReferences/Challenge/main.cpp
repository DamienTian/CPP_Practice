// Section 12
// Challenge
// Answered by Hao Tian

/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes
  
  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.
  
  The function should return a pointer to the newly allocated array.
  
  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.
    
  For example,
  
  Below is the output from the following code which would be in main:
  
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,5);
    
    cout << "Array 2: " ;
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
   
   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/
  
#include <iostream>

using namespace std;

// Prototypes
void print(const int* array, size_t size);
int* apply_all(const int* array1, size_t array1_size, const int* array2, size_t array2_size);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1:\n" ;
    print(array1,array1_size);
    
    cout << "Array 2:\n" ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result:\n" ;
    print(results, results_size);
    
    //【IMPORTANT】deallocate the space
    delete [] results;
    
    cout << endl;
    return 0;
}

void print(const int* array, size_t size){
    size_t index {0};
    cout << "[ ";
    while(index < size){
        cout << *array++ << " ";
        index++;
    }
    cout <<"]\n";
}

int* apply_all(const int* array1, size_t array1_size, const int* array2, size_t array2_size){
    // 【IMPORTANT】Allocate continuous space, and use this pointer for looping
    int* result_ptr {new int[array1_size * array2_size]};
    // Point to the beginning of the result array, used for returning the result
    int* begin_of_result {result_ptr};
    // Point to the beginning of the array 1, used for inner looping
    const int* begin_of_array1 {array1};

    for(size_t a2 {0}; a2 < array2_size; ++a2){
        for(size_t a1 {0}; a1 < array1_size; ++a1){
            *result_ptr = *array2 * *array1;
            result_ptr++;
            array1++;
        }
        array1 = begin_of_array1;
        array2++;
    }

    return begin_of_result;
}