// To initialize stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "utils/stb_image.h"

#include "textures/ex4.h"

using textures_ex4::render;

int main() {
    int result = render();
    return result;
}