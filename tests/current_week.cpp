#include <iostream>
#include <ctime>

int main(){
    std::time_t result = std::time(nullptr);
    result /= 60 * 60 * 24 * 7;
    std::cout << result << std::endl;
}
