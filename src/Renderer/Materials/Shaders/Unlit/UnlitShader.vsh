#version 410 core

uniform mat4 MATRIX_MVP;

in vec3 in_Position;
in vec4 in_Color;

out vec4 pass_Color;


void main(void) {
    pass_Color = in_Color;
    gl_Position = MATRIX_MVP * vec4(in_Position, 1.0);
}