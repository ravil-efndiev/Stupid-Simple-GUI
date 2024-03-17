#pragma once
#include "Application.hpp"

int main() {
    using namespace ssg;

    std::unique_ptr<Application> app = createApp();
    Status exitStatus = app->start();
    return static_cast<i32>(exitStatus);
}
