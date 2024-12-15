#pragma once
#include "SlideMaker.h"
#include "Exiter.h"
#include "ShapeAdder.h"
#include "Remover.h"
#include "Undo.h"
#include "Redo.h"

namespace cli {
    class CInitializer {
        //using Types = cli::IAttributes;
        public:
        static void InitializeValidCommands();
        private:
        static void setSlideAdder();
        static void setShapeAdder();
        static void setExiter();
        static void setRemover();
        static void setUndoRedo();
    };
}; //namespace cli