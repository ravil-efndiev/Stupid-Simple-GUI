#pragma once
#include "Core.hpp"

namespace ssgui {
    /**
     * @brief Image class to load OpenGL textures
     */
    class Image {
    public:
        /**
         * @brief default constructor, doesn't do anything
         */
        Image();
        /**
         * @brief Crates empty texture with specified size
         * @param width width of texture (pixels)
         * @param height height of texture (pixels)
         */
        Image(i32 width, i32 height);
        /**
         * @brief Creates and loads texture from file
         * @param path path to image file (with 3 or 4 channels)
         * @note grayscale textures are not supported
         */
        Image(const std::string& path);
        Image(const Image& tex) = delete;
        ~Image();

        /**
         * @brief loads texture from file (use instead of deleted copy constructor)
         * @param path path to image file
         */
        void loadFromFile(const std::string& path);
        /**
         * @brief sets image data in bytes (use after width, height constructor)
         * @param data texture data (byte array)
         * @param channels number of channels (3 - RGB, 4 - RGBA)
         */
        void setData(u8* data, i32 channels);

        i32 getWidth() const;
        i32 getHeight() const;

        /**
         * @brief Get OpenGL texture ID
         * @return Texture ID (GLuint)
         */
        GLuint getId() const;
        /**
         * @brief Get texture path if loaded from file
         * @return path to the texture
         */
        std::string getPath() const;

        bool operator== (const Image& tex) const;

    private:
        void setTextureParams();

    private:
        GLuint textureId;
        GLenum dataFormat, internalFormat;
        
        i32 width, height, channels;   
        std::string path = "";
    };
}
