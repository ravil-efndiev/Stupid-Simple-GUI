#include "TestApp.hpp"
#include <Entry.hpp>

namespace ssgui {
    SS_APPLICATION(TestApp)

    float lol = 0;
    std::string str;
    void TestApp::init() {
        BackgroundColor = {0.1f, 0.1f, 0.1f, 1.f};
        img.loadFromFile("assets/img/container.jpg");
    }

    void TestApp::renderUI() {
        beginMainWindow();
        ImGui::Button("lol");

        bool clicked = buttonStyled("kek", {}, (ButtonStyle) {
            .Font = getFont("default-20px"),
            .Color = Vector4(1.f, 0.f, 0.f, 1.f),
            .Alignment = ALIGN_CENTER,
        });

        if (clicked) {
            print("styled button clicked");
        }

        progressBar("lol bar", lol += 0.0001, {500, 10}, IM_COL32(40, 40, 40, 255), IM_COL32(20, 30, 200, 255));

        ImGui::Image((ImTextureID)img.getId(), ImVec2(100, 100));

        textStyled("lol kek Teaweaweaweaweaweawext", (TextStyle) {
            .Font = getFont("default-30px"),
            .Color = Vector4(0.f, 1.f, 0.f, 1.f),
            .Alignment = ALIGN_CENTER,
        });

        inputTextStyled("awdwadw", &str, (InputTextStyle) {
            .Font = getFont("default-24px"),
            .Color = Vector4(0.f, 1.f, 0.f, 1.f),
            .BackgroundColor = Vector4(0.f, 0.f, 0.f, 1.f),
            .Alignment = ALIGN_CENTER,
            .Width = 200.f,
        });

        endMainWindow();
    }
}
