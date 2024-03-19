#pragma once
#include "Core.hpp"

namespace ssgui {
    std::vector<std::string> splitStr(const std::string&, char sep);

    std::string getTextFromFile(const std::string& path);
    void saveTextToFile(const std::string& path, const std::string& text);
    void deleteLineFromFile(const std::string& path, u32 n);
    bool fileExists(const std::string& path);

    std::string openFileDialog(const char* extFilter, const char* startPath = nullptr);    
    std::string saveFileDialog(const char* extFilter, const char* startPath = nullptr);    
}
