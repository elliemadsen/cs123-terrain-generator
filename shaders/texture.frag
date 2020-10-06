#version 400 core
in vec2 uv;
out vec3 color;

uniform sampler2D sky_tex;
uniform int useTextureMap;

void main(){
    vec3 gbr = vec3(texture(sky_tex,uv));

    if (useTextureMap > 0) { // if using texture mapping, use sky image
        color = vec3(gbr.z, gbr.y, gbr.x);
    } else {
        color = vec3(0.8, 0.8, 0.8); // otherwise render in gray
    }
}
