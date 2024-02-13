// 01

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 4;
    if (myMap.find(key) != myMap.end()) { // fix : compare result of find with myMap.end();
        std::cout << "Key " << key << " exists." << std::endl;
    } else {
        std::cout << "Key " << key << " does not exist." << std::endl;
    }

    return 0;
}
