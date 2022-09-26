#include "header.hpp"
#include <cstring>
#include <iostream>

int encodeOrDecode()
{
    int choice{};
    do
    {
        if (std::cin.fail())
        {
            std::cout << "Error: Invalid Input\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Choose to encode [1] or decode [2]: ";
        std::cin >> choice;
    } while (choice <= 0 || std::cin.fail());
    
    return choice;
}

std::string getTextInput()
{
    std::cout << "Enter Input: ";
    std::string input{};
    std::getline(std::cin >> std::ws, input);
    
    return input;
}

int getSecretKey(std::string previousInput)
{
    int key{};
    do
    {
        if (std::cin.fail())
        {
            std::cout << "Error: Not a Non-Negative Integer\n\n";
            std::cout << "Enter Input: " << previousInput << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Secret Key: ";
        std::cin >> key;
    } while (key <= 0 || std::cin.fail());
    
    key = key % 26;
    
    return key;
}

std::string cipherOrDecipherText(std::string text, int secretKey)
{
    std::string cipheredText = "";
    for (int i = 0; i < text.length(); i++)
    {
        int asciiConversion = static_cast<int>(text[i]);
        if (asciiConversion < 65 || asciiConversion > 122 || (asciiConversion > 90 && asciiConversion < 97))
        {
            cipheredText += text[i];
        }
        else if (isupper(text[i]))
        {
            int convertedUppercaseLetterAsInt = int(asciiConversion + secretKey - 65) % 26 + 65;
            char convertedUppercaseLetter = static_cast<char>(convertedUppercaseLetterAsInt);
            cipheredText += convertedUppercaseLetter;
        }
        else if (islower(text[i]))
        {
            int convertedLowercaseLetterAsInt = int(asciiConversion + secretKey - 97) % 26 + 97;
            char convertedLowercaseLetter = static_cast<char>(convertedLowercaseLetterAsInt);
            cipheredText += convertedLowercaseLetter;
        }
    }

    return cipheredText;
}

void printOutput(int choice, std::string plainText, int secretKey)
{
    if (choice == 1)
    {
        std::string encodedText = cipherOrDecipherText(plainText, secretKey);
        std::cout << "Encoded Text: " << encodedText << '\n';
    }
    else if (choice == 2)
    {
        std::string decodedText = cipherOrDecipherText(plainText, constants::decoderConstant - secretKey);
        std::cout << "Decoded Text: " << decodedText << '\n';
    }
}
