// To initialize stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "utils/stb_image.h"

#include "6_coordinate-systems/base.h"

using coordinate_systems::render;

int main() {
    int result = render();
    return result;
}