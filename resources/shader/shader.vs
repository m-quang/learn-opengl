#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexture;

out vec2 Texture;

uniform mat4 transform;

void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * transform;
   Texture = vec2(aTexture.x, aTexture.y);
}