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
    std::shared_ptr ptr = std::make_shared<document::TextBox>(location, attr, content);
    std::vector<std::shared_ptr<document::A_Item>> vec{};
    vec.push_back(std::move(ptr));
    document::Slide sl1{vec};

    auto Slide_iter = sl1.cbegin();
    const auto ptr2 = *Slide_iter;
    std::cout << ptr2->getGeometry().first << " ";
    std::cout << ptr2->getGeometry().second << " ";
    std::cout << "\n";
    return 0;
}