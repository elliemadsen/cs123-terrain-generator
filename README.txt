Final Project README


HOW TO USE PROGRAM:
We built our project using QT Creator, so you should be able to build and run the project as an app. Our program showcases a mountainscape created using procedurally generated terrain. Users are able to change certain features of the terrain in order to create different scenes. For example, you can display plains, hills, and mountains; change the scale of the terrain; change the number of octaves in the terrain noise functions; toggle normal mapping, texture mapping, and fog; and change the background and lighting of the scene. You can also export the terrain base geometry as an obj file, which can be imported into other more advanced programs, like Maya.


---------------------------------------------

OVERVIEW:
The primary functionality of our project lies in the terrain.cpp class and in the shader.frag file. A brief description of the functionality of each class is as follows:


glwidget.cpp —  makes shader programs, draws the terrain and sky, updates terrain and sky when UI settings have been changed
settings.cpp — updates setting values based on the UI
terrain.cpp — determines which biomes to use in the terrain, sets scale of terrain, blends biome heights together, binds normal and texture maps for grass and rock to the shaders
biomes.cpp — parent class for specific biome types, contains valueNoise function
mountains.cpp — determines height of mountain biome at specific location
hills.cpp — determines height of hills biome at specific location
plains.cpp — determines height of plains biome at specific location
sky.cpp — models environment mapping by making a sphere, binding it to a texture map, and drawing the sphere 
shader.vert — sets vertex positions for the terrain
shader.frag — linearly interpolates normal mapping and texture mapping for the grass and rock, alters the light color based on the sky, adds fog
texture.vert — sets vertex positions for the sky
texture.frag — texture maps the sky

---------------------------------------------

DESIGN DECISIONS:


Terrain Generation:
The terrain is generated from 9 individual chunks. For each chunk, a value noise function is used to determine which biome (plains, hills, mountains) should be at each point in the terrain segment. This is referred to as the biomeValue. A smooth interpolation between biomes is achieved by weighing the height of each biome at a certain point and updating the total output height. The biome value noise function is scaled up or down depending on user input, which in turn scales up and down the amount each biome appears on the terrain. Each biome (plains, hills, mountains) has its own class with a heightAt function. The heightAt functions combines various octaves of value noise into a final height. For Mountains and Hills, the number of octaves is determined by user input, and the frequency and amplitude becomes increasingly smaller for each octave; for Plains, a fixed number of two low amplitude, low frequency octaves are combined. For all biomes, the frequency and amplitude is based on the scale of the biome value noise function. This is done so that higher frequency, lower amplitude mountains/features are created at small scales and lowers frequency, higher amplitudes mountains/features are created at larger scales.

We also added an export function to the terrain. That is, you can export the terrain geometry (without normal mapping or texture mapping) to the terrain.obj file. This is done by iterating through each chunk of the terrain and writing the vertex positions, normals, and face definitions to the terrain.obj file in a specific way. This means we are able to use our terrain generator elsewhere, for example as a tool to generate compelling sets and scenes for an animation created in something like Autodesk Maya.


Normal Mapping:
To implement normal mapping, we made a custom vertex shader, shader.vert, and fragment shader, shader.frag. We created the normal maps by using GIMP to apply a normal mapping filter to the texture images. In terrain.cpp, uv coordinates are calculated and the normal map images are bound to the shader. In the fragment shader, we set the normal vector to the value sampled at (u,v) on the normal map. We interpolate the normal between the rock normal map and grass normal map depending on the height of the position vector. Finally, we calculate the fragment color as usual using the new normal vector. 

Our implementation of normal mapping is also adaptive based on the camera view. That is, things closest to the camera will have the most normal mapping, while things further away will have little to no normal mapping. This is done because the details modeled by normal mapping are typical only seen at close range and trying to normal map distant objects can cause unpleasant visual noise.


Texture Mapping:
Our project uses five different texture maps: day sky, night sky, sunset sky, grass, and rock. Grass and rock are texture mapped in shader.frag, while the skies are texture mapped in texture.frag. In terrain.cpp, uv coordinates of the terrain are calculated and the grass and rock texture maps are bound to the shader. In sky.cpp, uv coordinates of the sphere are calculated and the currently-selected sky texture map (either day, night, or sunset) is bound to the shader.  In the fragment shaders, we sample the texture maps at (u,v) and apply this vector to the fragment color output. For the terrain, in shader.frag we interpolate between the rock texture and grass texture depending on the height of the position vector, just like we do for normal mapping.


Fog and Lighting:
The fog and lighting effects are created entirely in the fragment shader, shader.frag. The color of both is determined by whichever image is currently being used as the sky. The light color is then directly used in the phong lighting model. For the fog, we used a linear equation for fog that uses a fogStart and fogEnd distance, as well as the distance from a point in the scene to the camera. A fogFactor is calculated by (fogEnd - dist) / (fogEnd - fogStart), and this fogFactor is used to linearly interpolate between the fog color and the terrain color. A user can toggle the fog in the UI, and we decided to include fog to add to the realism of the scene. 

---------------------------------------------

KNOWN ISSUES/BUGS:
Exporting the terrain requires writing to a pre-existing obj file, which is called terrain.obj in this project. Currently this file is referenced with an absolute path in the terrain::toObj function, because a local path was not causing the function to write to the file. We tried using QCoreApplication::applicationDirPath().toStdString() + "/terrain.obj" but that didn’t work. So, as it stands, in order to properly export, you must change this file path (around line 315 in terrain.cpp) to the absolute path where a terrain.obj file already exists.