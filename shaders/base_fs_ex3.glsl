#version 330 core
out vec4 FragColor;
in vec3 pos;

void main()
{
    FragColor = vec4(pos, 1.0f);
}

// The bottom-left side of the triangle is black because the negative values are clamped to zero.