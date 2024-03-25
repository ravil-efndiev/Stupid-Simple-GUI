#include "Image.hpp"

#include <glad/glad.h>
#include <stb_image/stb_image.h>

namespace ssgui {
    Image::Image() {}

    Image::Image(i32 width, i32 height) : width(width), height(height) {
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        setTextureParams();

        dataFormat = GL_RGB8;
        internalFormat = GL_RGB8;

        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, nullptr);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Image::Image(const std::string &path)
        : path(path) {       
        loadFromFile(path);
    }

    Image::~Image() {
        glDeleteTextures(1, &textureId);
    }

    void Image::loadFromFile(const std::string& path) {
        stbi_set_flip_vertically_on_load(true);

        u8* textureData = stbi_load(path.c_str(), &width, &height, &channels, 0);
        SS_ASSERT(textureData, "Image: unable to load texture from file")

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        SS_ASSERT(channels == 3 || channels == 4, "Image: unsupported texture format");

        dataFormat = channels == 3 ? GL_RGB : GL_RGBA;
        internalFormat = channels == 3 ? GL_RGB8 : GL_RGBA8;

        setTextureParams();

        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(textureData);
    }

    void Image::setData(u8* data, i32 channels) {
        SS_ASSERT(channels == 4 || channels == 3, "Image: number of channels in texture can be only 4 or 3");

        this->channels = channels;
        dataFormat = channels == 4 ? GL_RGBA : GL_RGB;

        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, dataFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    i32 Image::getWidth() const { return width; }

    i32 Image::getHeight() const { return height; }

    GLuint Image::getId() const { return textureId; }

    std::string Image::getPath() const { return path; }

    bool Image::operator==(const Image& tex) const {
        return path == "" ? textureId == tex.textureId : path == tex.path;
    }

    void Image::setTextureParams() {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
}
