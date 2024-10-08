#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 4;
    std::cout << "Value for key " << key << ": " << myMap[key] << std::endl; // fix : myMap[key] instead of myMap.at(key)

    return 0;
}

// official answer

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Orange";

    int key = 4;
    if(myMap.find(key) != myMap.end())
    std::cout << "Value for key " << key << ": " << myMap.at(key) << std::endl;

    return 0;
}
