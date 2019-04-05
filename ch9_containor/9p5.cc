#include <vector>
#include <iostream>
std::vector<int>::const_iterator check_exist(std::vector<int>::const_iterator, std::vector<int>::const_iterator, int);
int main()
{
    std::vector<int> vi={1,2,3,4};
    int i=1;
    
    auto it = check_exist(vi.cbegin(), vi.cend(), i);
    if (it == vi.end())
    std::cout << "No found " << i << " in range" << std::endl;
  else
    std::cout << "Found " << *it
              << " at position " << it - vi.cbegin() << std::endl;
    return 0;
}

std::vector<int>::const_iterator check_exist(std::vector<int>::const_iterator a_begin, std::vector<int>::const_iterator a_end, int a_i)
{
    for(auto it = a_begin; it != a_end;++it)
    {
        if (*it==a_i)
            return it;
        
        
    }
    return a_end;
}