#version 410 core

in vec4 pass_Color;

layout(location = 0) out vec4 out_Color;

void main(void) {
    out_Color = pass_Color;
}