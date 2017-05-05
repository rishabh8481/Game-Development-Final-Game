uniform float Scale;

void main(void){

    vec4 a = gl_Vertex;

    a.x = a.x * cos(Scale) - a.y*sin(Scale); // Scale x
    a.y = a.y * 2.0; // Scale y

    gl_Position = gl_ModelViewProjectionMatrix * a;

    // same as fTransform();

}
// I came to vertex shader

