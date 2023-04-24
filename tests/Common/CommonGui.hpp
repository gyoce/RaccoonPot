#ifndef TESTS_COMMON_GUI_HPP
#define TESTS_COMMON_GUI_HPP

class WidgetTest: public RP::GuiButton {
public:
    WidgetTest() = default;
    WidgetTest(int value) : ValueByConstructor(value) {  }

    bool CallClickFunction = false;
    bool CallDrawFunction = false;
    int ValueByConstructor = 0;

    void Click() override {
        CallClickFunction = true;
    }

    void Draw(const RP::IGuiRenderSystemPtr& renderSystem) override {
        CallDrawFunction = true;
    }
};

class GuiRenderSystemTest final : public RP::IGuiRenderSystem {

};

#endif // TESTS_COMMON_GUI_HPP