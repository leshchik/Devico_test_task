#include <iostream>
#include <fstream>
#include "dependencies/include/nlohmann/json.hpp"

int Calculate_legs();

int main()
{
    int x;
    x=Calculate_legs();
    std::cout <<"Count of legs =  " << x << std::endl;
}

int  Calculate_legs()
{
    nlohmann::json objJson;

    std::fstream fileInput;
    fileInput.open("animals.json");

    fileInput >> objJson;
    int chickens, cows, pigs, all_legs;
    chickens = objJson["chickens"];
    cows = objJson["cows"];
    pigs = objJson["pigs"];

    all_legs = (chickens * 2) + (cows * 4) + (pigs * 4);
    fileInput.close();
    return all_legs;
}