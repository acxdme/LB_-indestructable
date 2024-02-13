#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    auto ptr = myMap.begin(); // fix : declare ptr

    for (auto it = myMap.begin(); it != myMap.end(); ++it) {

        if (it->first == 2) { // assign ptr to be delted.
            ptr = it;

        }
          std::cout << it->first << ": " << it->second << std::endl;
    }

    myMap.erase(ptr); // erase entry in map corresponding to the ptr.
    std::cout<<std::endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}

// official answer
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    for (auto it = myMap.begin(); it != myMap.end(); /* no increment here */) {
        std::cout << it->first << ": " << it->second << std::endl;
        if (it->first == 2) {
            it = myMap.erase(it);
        } else {
            ++it;
        }
    }

    return 0;
}
