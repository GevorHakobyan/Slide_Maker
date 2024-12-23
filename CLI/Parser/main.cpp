#include <QApplication>
#include <iostream>
#include "Controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    cli::Controller st;
    st.start(std::cin); 

    return app.exec();
}
/*
#include <iostream>
#include "Controller.h"

int main() {
    cli::Controller st;
    st.start(std::cin);
    return 0;
}*/