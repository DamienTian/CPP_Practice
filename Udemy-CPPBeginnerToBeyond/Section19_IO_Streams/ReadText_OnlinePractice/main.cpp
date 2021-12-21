#include <iostream>
#include <fstream>

void read_file(std::string file_name) {
    //---- YOU WRITE YOUR CODE BELOW THIS LINE----
    std::fstream in_file;
    in_file.open(file_name, std::fstream::in);
    if(!in_file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
    
    std::string word;
    while(in_file >> word){
        std::cout << word << std::endl;
    }
   
    //---- YOU WRITE YOUR CODE ABOVE THIS LINE----
}

int main(){
    read_file("data.txt");
    return 0;
}