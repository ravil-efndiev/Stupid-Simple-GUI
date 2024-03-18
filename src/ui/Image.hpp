#pragma once
#include "Core.hpp"

namespace ssgui {
    class Image {
    public:
        Image();
        Image(i32 width, i32 height);
        Image(const std::string& path);
        Image(const Image& tex) = delete;
        ~Image();

        void loadTexture(const std::string& path);
        void setData(u8* data, i32 channels);

        i32 getWidth() const;
        i32 getHeight() const;

        GLuint getId() const;
        std::string getPath() const;

        bool operator== (const Image& tex) const;

    public:
        static GLuint imageFromFile(const std::string& path);

    private:
        GLuint textureId;
        GLenum dataFormat, internalFormat;
        
        i32 width, height, channels;   

        u8* textureData;

        std::string path = "";
    };
}
