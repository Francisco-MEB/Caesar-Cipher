#include "header.hpp"
#include <cstring>
#include <iostream>

int main()
{
    int choice = encodeOrDecode();
    
    std::string plainText = getTextInput();
    int secretKey = getSecretKey(plainText);
    
    printOutput(choice, plainText, secretKey);
    
    return 0;
}
