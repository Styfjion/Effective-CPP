//
// Created by yangf on 2022/3/15.
//

#include <cstring>
#include <iostream>
#include "TextBlock.hpp"

namespace EffectiveCpp {
    constexpr int MAX_LEN = 1e4;
    TextBlock::TextBlock() : pText(new char[MAX_LEN]), textLength(0), lengthIsValid(false) {
        memset(pText, 0, sizeof(char) * MAX_LEN);
    }

    TextBlock::~TextBlock() {
        delete[] pText;
    }

    std::size_t TextBlock::length() const {
        textLength = std::strlen(pText);
        if (textLength > 0) {
            lengthIsValid = true;
        }
        return textLength;
    }

    TextBlock::TextBlock(const std::string &inputStr) : pText(new char[MAX_LEN]),
        textLength(inputStr.length()), lengthIsValid(true) {
        memset(pText, 0, sizeof(char) * MAX_LEN);
        memcpy(pText, inputStr.c_str(), textLength + 1);
    }

    const char &TextBlock::operator[](std::size_t position) const {
        if (position >= MAX_LEN) {
            throw std::out_of_range("position is out of range");
        }
        return pText[position];
    }

    char &TextBlock::operator[](std::size_t position) { // 现在只调用const op[]
        return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
    }

    const char *TextBlock::show() const{
        if (lengthIsValid) {
            return pText;
        }
        return nullptr;
    }

    void TextBlock::clear() {
        memset(pText, 0, this->length());
    }
}

int main()
{
    EffectiveCpp::TextBlock textBlock1;
    std::cout << "textBlock1 length is " << textBlock1.length() << std::endl;

    std::string inputStr{"Hello, world."};
    const EffectiveCpp::TextBlock textBlock2(inputStr);
    std::cout << "textBlock2 length is " << textBlock2.length() << std::endl;
    std::cout << "textBlock2 position 10 is " << textBlock2[10] << std::endl;
    std::cout << textBlock2.show() << std::endl;

    textBlock1[0] = 'a';
    textBlock1[1] = 'b';
    std::cout << "textBlock1 length is " << textBlock1.length() << std::endl;
    std::cout << textBlock1.show() << std::endl;
    textBlock1.clear();
    textBlock1[0] = 'c';
    textBlock1[1] = 'd';
    textBlock1[2] = 'e';
    std::cout << "textBlock1 length is " << textBlock1.length() << std::endl;
    std::cout << textBlock1.show() << std::endl;

    try {
        std::cout << textBlock1[EffectiveCpp::MAX_LEN + 1];
    } catch(const std::exception& ex) {
        std::cout << "exception is: " << ex.what() << std::endl;
    }
    return 0;
}