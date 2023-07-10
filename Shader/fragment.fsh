#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 TexCoord;

uniform sampler2D aTexture;

void main()
{
//    FragColor = 0.5 * texture(aTexture, TexCoord) + 0.5 * vertexColor;
    FragColor = texture(aTexture, TexCoord) * vertexColor;
}
