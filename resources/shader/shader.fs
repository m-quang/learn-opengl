#version 330 core

in vec2 Texture;

out vec4 FragColor;

uniform sampler2D texture1;

void main()
{
   //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
   //vec2 texture2 = vec2(1.0f, 0.4f);
   FragColor = texture(texture1, Texture);
}