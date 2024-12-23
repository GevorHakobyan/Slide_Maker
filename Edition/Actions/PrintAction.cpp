#include "PrintAction.h"

namespace edition {
    PrintAction::PrintAction(const Info& info)
    :Action(info) {};

    PrintAction::Pair PrintAction::create(Info& info) {
        Pair answer;
        ActionPtr Do = std::make_unique<PrintAction>(info);
        ActionType Undo = "NULL";

        answer.first = std::move(Do);
        answer.second = Undo;

        return std::move(answer);
    }

    void PrintAction::Do() {
        if (m_Data.find("help") != m_Data.end()) {
            m_viewManager->PrintHelp("Commands");
            return;
        }

        const auto idIter = m_Data.find("slide")->second;
        const auto id = std::get<float>((idIter));

        for (const auto& slide : *m_storage) {
            if (slide->getId() == id) {
                m_viewManager->PrintSlide(slide);
                return;
            }
        }

        throw InvalidID("Iinvalid SLide It", id, std::source_location::current());
    }

}; //namespace edition