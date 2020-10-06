#version 400 core
in vec3 WS_position; // world-space position
in vec3 WS_normal;   // world-space normal
in vec2 uv;
in vec4 WS_camera;
in float useNormalMap;

uniform sampler2D rock_tex;
uniform sampler2D grass_tex;
uniform sampler2D rock_normalMap;
uniform sampler2D grass_normalMap;
uniform int useTextureMap;
uniform int useFog;
uniform int sky;

out vec3 fragColor;

void main(){

    vec3 l = normalize(vec3(10.0, 5.0, 10.0)); // directional light
    vec3 lightColor = vec3(1, 1, 1);

    vec3 fogColor = vec3(0.6, 0.6, 0.6);

    if (sky == 1) {
        // night sky
        lightColor = vec3(0.41, 0.512, 0.633);
        fogColor = vec3(0.1, 0.1, 0.1);
    } else if (sky == 2) {
        // sunset sky
        lightColor = vec3(0.98, 0.839, 0.647);
        fogColor = vec3(0.38, 0.339, 0.307);
    }

    vec3 gbr;
    vec3 normal;

    // Use normal maps to create new normals for each terrain
    vec3 rock_normal = normalize(WS_normal + (2 * vec3(texture(rock_normalMap, uv / 2))) - vec3(1,1,1)); // rgb [0,1] to normal [-1,1]
    vec3 grass_normal = normalize(WS_normal + (2 * vec3(texture(grass_normalMap, uv / 2))) - vec3(1,1,1)); // rgb [0,1] to normal [-1,1]


    float texBlend;
    // if the height of the point is above one, then clamp texBlend value at 1.0
    if (WS_position.y > 1.0) {
        texBlend = 1.0;
    } else {
        // otherwise just use the height as the texBlend value
        texBlend = WS_position.y;
    }


    // if we are using the texture map
    if (useTextureMap > 0) {
        // interpolate between the grass texture and rock texture using the texBlend value
        gbr = (1-texBlend) * 0.75 * (vec3(0, 0.25, 0) + vec3(texture(grass_tex, uv))) + (texBlend) * vec3(texture(rock_tex, uv));
    } else {
        // if we are not using texture mapping, just render in a gray
        gbr = vec3(0.8, 0.8, 0.8);
    }

    // distance from the point on the terrain to the camera
    float dist = distance(WS_position, WS_camera.xyz);

    // if normal mapping is used
    if (useNormalMap > 0) {
        // interpolate between the grass normal and rock normal using the texBlend value
        normal = texBlend*rock_normal + (1-texBlend)*grass_normal;

        // if the point on the terrain is closer than 1, then just use 1.0 as the distance
        if (dist < 1.0) {
            dist = 1.0;
        }
        // use the reciprocal of the distance to linearly interopolate between original normal
        // and normal mapped normal
        // the effect is only close points are normal mapped
        normal = (1/dist) * normal + (1-(1/dist)) * WS_normal;
    } else {
        // if normal mapping is not used, use the world space normal at the point
        normal = WS_normal;
    }

    // Apply phong lighting to the terrain
    vec3 terrainColor =  vec3(gbr.z, gbr.y, gbr.x) * lightColor * max(0.0, dot(normal, l));

    // if fog is selected
    if (useFog > 0) {
        // define where fog starts and ends
        float fogEnd = 30.0;
        float fogStart = 13.0;
        // find the fogFactor using the linear fog equation suggested here: http://in2gpu.com/2014/07/22/create-fog-shader/
        float fogFactor = (fogEnd - dist) / (fogEnd - fogStart);
        fogFactor = clamp(fogFactor, 0.0, 1.0);

        // the final output is linear interpolation between terrain color and fog color using fogFactor
        fragColor = (1 - fogFactor) * fogColor + fogFactor * terrainColor;
    } else {
        // if fog is not selected, just output the terrain color
        fragColor = terrainColor;
    }
}
