#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <deque>
int
main(int argc, char **argv) {
    
    int input;
    std::vector<int> vi;
    
    for (int i =0; i<30; i++)
    {
        std::cout << "num: "<< i <<", capacity: " << vi.capacity() << std::endl;
    vi.push_back(i);
    }
    
    
    
    return 0;
}