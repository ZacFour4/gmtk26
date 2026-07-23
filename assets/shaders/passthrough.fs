#version 330 compatibility

in fData
{
    vec3 normal;
    vec4 color;
}frag_in;

void main()
{
    gl_FragColor = frag_in.color;
}