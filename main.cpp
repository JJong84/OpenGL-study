// To initialize stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "utils/stb_image.h"

#include "7_camera/ex1.h"

using camera_ex1::render;

int main() {
    int result = render();
    return result;
}