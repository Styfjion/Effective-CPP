//
// Created by yangf on 2022/3/15.
//

#ifndef EFFECTIVE_CPP_TEXTBLOCK_HPP
#define EFFECTIVE_CPP_TEXTBLOCK_HPP


#include <cstddef>
#include <climits>
#include <string>

namespace EffectiveCpp {
    class TextBlock {
    public:
        TextBlock();
        explicit TextBlock(const std::string& inputStr);
        ~TextBlock();
        std::size_t length() const;
        const char& operator[](std::size_t position) const;
        char& operator[](std::size_t position);
        const char* show() const;
        void clear();
    private:
        char* pText;
        mutable std::size_t textLength; // 这些变量成员，即使在const
        mutable bool lengthIsValid;     // 函数中也会被更改
    };
}


#endif //EFFECTIVE_CPP_TEXTBLOCK_HPP
