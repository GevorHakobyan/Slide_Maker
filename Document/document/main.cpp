#include <iostream>
#include "Slide.h"
#include "TextBox.h"
#include "TextBox_Attr.h"

int main() {
    document::TextBox_Attr::Color color = document::TextBox_Attr::Color::Black;
    std::string title = "Slide Name";

    document::TextBox_Attr attr{color, 5, 4, 5, title};
    std::pair<float, float> location = {5.5, 4.5};
    std::string content = "Empty!\n";

    ///document::TextBox box{location, attr, content};
    return 0;
}