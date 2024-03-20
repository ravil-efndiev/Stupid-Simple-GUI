#pragma once
#include <ui/Application.hpp>

int main() {
    using namespace ssgui;

    createApp();
    Application* app = Application::Get();

    if (!app) {
        printErr("Application instance wasn't properly initialized");
        return Status_Error;
    }

    Status exitStatus = app->start();
    return exitStatus;
}
