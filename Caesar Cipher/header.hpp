#ifndef HEADER_HPP
#define HEADER_HPP

#include <cstring>
#include <iostream>

int encodeOrDecode();
std::string getTextInput();
int getSecretKey(std::string previousInput);
std::string cipherOrDecipherText(std::string text, int secretKey);
void printOutput(int choice, std::string plainText, int secretKey);

namespace constants
{
const int decoderConstant = 26;
}

#endif
