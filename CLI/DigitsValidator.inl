#include "DigitsValidator.h"

bool cli::DigitsValidator::validate(const Token token) {
    //if start with digits then it must contain only digits
    //can't have digits in the middle (middle == after the first character)

    const char firstCharacter = token[0];
    bool validatorResult{true};

    if(isDigit(firstCharacter)) {
        return (!hasAlphaNumeric(token)) ? m_nextValidator->validate(token) : false;
    }

    return (!doesContainDigit(token)) ? m_nextValidator->validate(token) : false;
}

bool cli::DigitsValidator::isDigit(const char character)  const {
    const char Ascii_Zero{48};
    const char Ascii_Nine{57};
    return (character >= Ascii_Zero && character <= Ascii_Nine);
}

bool cli::DigitsValidator::hasAlphaNumeric(const Token token) const {
    char Head = token[0];

    while('\0' != Head) {
        if (!isDigit(Head)) {
            return true;
        }
        ++Head;
    }
    return false;
}

bool cli::DigitsValidator::doesContainDigit(const Token token)  const {
    char Head = token[0];

    while('\0' != Head) {
        if (isDigit(Head)) {
            return true;
        }
        ++Head;
    }
    return false;
}