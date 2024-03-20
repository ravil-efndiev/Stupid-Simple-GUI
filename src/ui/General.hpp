#pragma once
#include "Core.hpp"

namespace ssgui {
    /**
     * @brief splits std::string in list of tokens divided by character
     * @param str string to split
     * @param sep character to split with
     * @return std::vector of std::string tokens
     */
    std::vector<std::string> splitStr(const std::string& str, char sep);

    /**
     * @brief gets all contents of the file
     * @param path path to the file
     * @return all of the text in the file
     */
    std::string getTextFromFile(const std::string& path);

    /**
     * @brief saves text to the file
     * @param path path to the file
     * @param text data to save in the file
     */
    void saveTextToFile(const std::string& path, const std::string& text);

    /**
     * @brief deletes n'th line from file
     * @param path path to the file
     * @param n number of line to delete
     */
    void deleteLineFromFile(const std::string& path, u32 n);

    /**
     * @brief checks if file exists on the disk
     * @param path path to the file
     * @return true if exists, false if not
     */
    bool fileExists(const std::string& path);

    /**
     * @brief opens file dialog to open a file using nfd
     * @param extFilter filter for file extensions (txt|png)
     * @param startPath path to start at (last path selected if set to nullptr)
     * @return absolute path to selected file
     */
    std::string openFileDialog(const char* extFilter, const char* startPath = nullptr);   
     
    /**
     * @brief opens file dialog to create a file using nfd
     * @param extFilter filter for file extensions (txt|png)
     * @param startPath path to start at (last path selected if set to nullptr)
     * @return absolute path to the file
     * @note function does not create a file, only returns a path to where user wants to create it
     */
    std::string saveFileDialog(const char* extFilter, const char* startPath = nullptr);    
}
