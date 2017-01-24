#include <iostream>

int main(){
    bool x=false;
    std::cout << "x=" << x << std::endl;

    x = x? false : true;

    if (x){
        std::cout << "x=" << x << std::endl;
    }

}
