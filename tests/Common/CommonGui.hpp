#ifndef TESTS_COMMON_GUI_HPP
#define TESTS_COMMON_GUI_HPP

class WidgetTest final : public RP::GuiButton {
public:
    WidgetTest() : GuiButton() {  }
    explicit WidgetTest(const int value) : GuiButton(), ValueByConstructor(value) {  }

    bool CallClickFunction = false;
    bool CallDrawFunction = false;
    int ValueByConstructor = 0;

    void Click() override {
        CallClickFunction = true;
    }

    void Draw(SDL_Renderer* renderer) override {
        CallDrawFunction = true;
    }

    bool GetHoverable() const {
        return hoverable;
    }

    bool GetHover() const {
        return hover;
    }
};

#endif // TESTS_COMMON_GUI_HPP