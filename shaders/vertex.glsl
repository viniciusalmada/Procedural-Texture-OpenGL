#version 430

layout (location = 0) in vec4 inVertex;
layout (location = 1) in vec4 inColor;

out vec4 color;

void main() {
    color = inColor;
    gl_Position = inVertex;
}
