#include "General.hpp"
#include <nfd.h>

namespace ssgui {
    std::vector<std::string> splitStr(const std::string& str, char sep) {
        std::vector<std::string> strings;

        u32 startIndex = 0, endIndex = 0;
        
        for (u32 i = 0; i <= str.size(); i++)  {
            if (str[i] == sep || i == str.size()) {
                endIndex = i;
                std::string temp;
                temp.append(str, startIndex, endIndex - startIndex);
                strings.push_back(temp);
                startIndex = endIndex + 1;
            }
        }
        
        return strings;
    }

    std::string getTextFromFile(const std::string& path) {
        std::ifstream file (path, std::ios::in);

        SS_ASSERT(file.is_open(), "Cannot open file for read")        

        std::string source;
        std::string line;

        while (std::getline(file, line)) {
            line.push_back('\n');
            source.append(line);
        }

        return source;
    }

    void saveTextToFile(const std::string& path, const std::string& text) {
        std::ofstream file (path, std::ios::out);
        SS_ASSERT(file.is_open(), "Cannot save data to file");

        file << text;
    }

    void deleteLineFromFile(const std::string& path, u32 n) {
        std::string text = getTextFromFile(path);
        auto lines = splitStr(text, '\n');

        std::fstream file (path, std::ios::out | std::ios::trunc);
        SS_ASSERT(file.is_open(), "Cannot delete line from file");

        std::string source;

        for (u32 i = 0; i < lines.size(); i++) {
            if (i == n)
                continue;

            source.append(lines[i] + "\n");
        }

        source.pop_back();
        file << source;
    }

    bool fileExists(const std::string& path) {
        std::ifstream file (path.c_str());
        return file.is_open();
    }

    std::string openFileDialog(const char* extFilter, const char* startPath) {
        nfdchar_t* openPath = nullptr;
        nfdresult_t result = NFD_OpenDialog(extFilter, startPath, &openPath);
        std::string str;

        switch (result) {
            case NFD_ERROR:
                printErr("Error while using save file dialog");
                exit(Status_Error);
                break;
            case NFD_OKAY:
                str = openPath;
                free(openPath);
                return str;
            case NFD_CANCEL:
                break;
        }
        return str;
    }

    std::string saveFileDialog(const char* extFilter, const char* startPath) {
        nfdchar_t* savePath = nullptr;
        nfdresult_t result = NFD_SaveDialog(extFilter, startPath, &savePath);
        std::string str;

        switch (result) {
            case NFD_ERROR:
                printErr("Error while using save file dialog");
                exit(Status_Error);
                break;
            case NFD_OKAY:
                str = savePath;
                free(savePath);
                return str;
            case NFD_CANCEL:
                break;
        }
        return str;
    }
}
