#pragma once
#include <Ssgui.hpp>

namespace ssgui {
    class TestApp : public Application {
    public:
        TestApp() : Application({1020, 700, "my window"}) {}
        ~TestApp() {}

        void init() override;
        void renderUI() override;

    private:
        Image img;
    };  
}

