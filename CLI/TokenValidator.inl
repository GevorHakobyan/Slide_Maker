#include "TokenValidator.h"

void cli::TokenValidator::setNextValidator(const nextValidator validator) {
    m_nextValidator.reset(validator.get());
}

const cli::TokenValidator::nextValidator& cli::TokenValidator::getNextValidator() const {
    return m_nextValidator;
}