#version 400 core

layout(location = 0) in vec3 position;
layout(location = 5) in vec2 texCoord;

uniform mat4 model, view, projection;

out vec2 uv;

void main() {

    gl_Position = projection * view * model * vec4(position, 1.0);
    uv = texCoord;
    //gl_Position = vec4(position, 1.0);
}
