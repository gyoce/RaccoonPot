#ifndef TESTS_COMMON_GUI_HPP
#define TESTS_COMMON_GUI_HPP

class WidgetTest: public RP::GuiButton {
public:
    WidgetTest() : RP::GuiButton(nullptr) {  }
    WidgetTest(int value) : RP::GuiButton(nullptr), ValueByConstructor(value) {  }

    bool CallClickFunction = false;
    bool CallDrawFunction = false;
    int ValueByConstructor = 0;

    void Click() override {
        CallClickFunction = true;
    }

    void Draw(SDL_Renderer* renderer) override {
        CallDrawFunction = true;
    }
};

#endif // TESTS_COMMON_GUI_HPP