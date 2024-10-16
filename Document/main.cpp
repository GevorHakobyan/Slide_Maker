#include <iostream>
#include "Slide.h"
#include "TextBox.h"
#include "Item.h"
#include "TextBox_Attr.h"

int main() {
    document::TextBox_Attr::Color color = document::TextBox_Attr::Color::Black;
    std::string title = "Slide Name";

    document::TextBox_Attr attr(color, 5, 4, 5, title);
    std::pair<float, float> location = {5.5, 4.5};
    std::string content = "Empty!\n";

    document::TextBox box{location, attr, content};
    std::unique_ptr ptr = std::make_unique<document::TextBox>(location, attr, content);
    std::vector<std::unique_ptr<document::A_Item>> vec{};
    vec.push_back(std::move(ptr));
    document::Slide sl1{vec};

    const auto Slide_iter = sl1.getIteratorOn(0);
    const auto Atribute_iter = (*Slide_iter)->getAttributesPtr();
    std::cout << (*Atribute_iter).getLength() << "\n";
    return 0;
}