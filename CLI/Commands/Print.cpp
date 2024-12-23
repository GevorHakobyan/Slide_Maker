#include "Print.h"

cli::I_Command::Arguments cli::Print::m_Valid_Info{};
cli::Print::Map cli::Print::m_Validators{};

cli::Print::Print(const Arguments& arguments) 
: I_Command{arguments} {};


bool cli::Print::Execute() {
    auto StoreManagerPtr = edition::StoreManager::getInstance();
    m_Arguments["isMutuable"] = false;
    StoreManagerPtr->push(std::move(m_Arguments), "Print");
    return true;
}

cli::I_Command::CommandPtr cli::Print::create(const Arguments& collectedArguments) {
    validateInfo(collectedArguments, m_Valid_Info);
    return std::move(std::make_unique<cli::Print>(collectedArguments));
}

void cli::Print::validateInfo(const Arguments& args, const Arguments& m_Valid_Info) const {
    isInofAcceptable(args);
    isInfoComplete(args);
}

void cli::Print::addValue(const cli::option opt, const cli::argument arg) {
    m_Valid_Info[opt] = arg;
}

void cli::Print::setValidators() {
    m_Validators["slide"] = std::move(std::make_shared<SlidePrintValidator>());
    m_Validators["help"] = std::move(std::make_shared<HelpPrintValidator>());
}

void cli::Print::isInofAcceptable(const Arguments& args) const {
    I_Command::validateInfo(args, m_Valid_Info);
}

void cli::Print::isInfoComplete(const Arguments& args) const {
    const auto validatorItr = args.begin();
    if (validatorItr == args.end()) {
        throw InvalidCommand_Cerr("Invalid Command", "Unknown Command", std::source_location::current());
    }

    const auto concretValidator = m_Validators.find((validatorItr->first));
    if (concretValidator == m_Validators.end()) {
        throw InvalidCommand_Cerr("Invalid Command", "Unknown Command", std::source_location::current());
    }

    (*concretValidator->second).Validate(args);
}