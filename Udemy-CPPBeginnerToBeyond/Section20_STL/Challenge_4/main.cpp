// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.
    std::stack<char> stack;
    std::queue<char> queue;
    for(const char& c : s){
        if(std::isalpha(c)){
            stack.push(c);
            queue.push(c);
        }
    }
    
    for(size_t i {0}; i < stack.size(); ++i){
        char stack_c = stack.top();
        char queue_c = queue.front();
        if(stack_c != queue_c){
            return false;
        }
        else{
            stack.pop();
            queue.pop();
        }
    }
    
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
    
//    std::vector<std::string> test_strings{"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
//        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
//   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}