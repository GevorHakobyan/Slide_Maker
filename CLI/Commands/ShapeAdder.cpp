#include "ShapeAdder.h"

cli::I_Command::Arguments cli::ShapeAdder::m_Valid_Info{};
cli::ShapeAdder::Map cli::ShapeAdder::m_Validators{};

cli::ShapeAdder::ShapeAdder(const Arguments& arguments) 
: I_Command{arguments} {};


bool cli::ShapeAdder::Execute() {
    auto StoreManagerPtr = edition::StoreManager::getInstance();
    StoreManagerPtr->push(std::move(m_Arguments), "AddItem");
    return true;
}

cli::I_Command::CommandPtr cli::ShapeAdder::create(const Arguments& collectedArguments) {
    validateInfo(collectedArguments, m_Valid_Info);
    return std::move(std::make_unique<cli::ShapeAdder>(collectedArguments));
}

void cli::ShapeAdder::validateInfo(const Arguments& args, const Arguments& m_Valid_Info) const {
    isInofAcceptable(args);
    isInfoComplete(args);
}

void cli::ShapeAdder::addValue(const cli::option opt, const cli::argument arg) {
    m_Valid_Info[opt] = arg;
}

void cli::ShapeAdder::setValidators() {
    m_Validators["rec"] = std::move(std::make_shared<RectValidator>());
    m_Validators["crc"] = std::move(std::make_shared<CircleValidator>());
    m_Validators["trg"] = std::move(std::make_shared<TriangleValidator>());
    m_Validators["tbx"] = std::move(std::make_shared<TextBoxValidator>());
}

void cli::ShapeAdder::isInofAcceptable(const Arguments& args) const {
    I_Command::validateInfo(args, m_Valid_Info);
}

void cli::ShapeAdder::isInfoComplete(const Arguments& args) const {
    const auto type = args.find("t");
    const auto ownerID = args.find("oid");

    if (args.end() == type) {
        throw cli::InvalidCommand_Cerr("Type is missing", "shape adder", std::source_location::current());
    }

    if (args.end() == ownerID) {
        throw cli::InvalidCommand_Cerr("Owner Id is missing", "shape adder", std::source_location::current());
    }

    const auto typeName = std::get<std::string>((*type).second);
    const auto concretValidator = (m_Validators.find(typeName));
    if (concretValidator == m_Validators.end()) {
        throw InvalidArgument_Cerr("Unknown type", typeName, std::source_location::current());
    }
    (*concretValidator).second->Validate(args);
}