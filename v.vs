uniform float Scale;

void main(void){

    vec4 a = gl_Vertex;

    a.x = a.x * 1.5; // Scale x
    a.y = a.y * 1.5; // Scale y

    gl_Position = gl_ModelViewProjectionMatrix * a;

    // same as fTransform();

}
// I came to vertex shader
