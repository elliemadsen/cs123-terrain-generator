#version 400 core

layout(location = 0) in vec3 OS_position;
layout(location = 1) in vec3 OS_normal;
layout(location = 6) in vec3 textCoord; // uv coord of terrain

uniform mat4 model, view, projection;

out vec3 WS_position; // world-space position
out vec3 WS_normal;   // world-space normal
out vec2 uv;
out vec4 WS_camera;
out float useNormalMap;

void main() {
    WS_position = (model * vec4(OS_position, 1.0)).xyz;
    WS_normal = (model * vec4(OS_normal, 0.0)).xyz;

    uv = vec2(textCoord);
    useNormalMap = textCoord.z; // indicator of whether or not normal mapping is selected was stored in z component of textCoord

    gl_Position = projection * view * vec4(WS_position, 1.0);

    WS_camera = inverse(view) * vec4(0, 0, 0, 1.0);

}
