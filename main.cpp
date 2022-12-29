// To initialize stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "utils/stb_image.h"

#include "transformations/ex2.h"

using transformations_ex2::render;

int main() {
    int result = render();
    return result;
}