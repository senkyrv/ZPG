#version 400
in vec4 worldPos;
in vec4 worldNorm;
in vec3 objectColor;
out vec4 outColor;
void main(void)
{
    vec3 lightPosition = vec3(0.0,0.0,0.0);
    vec4 lightColor = vec4(0.385 ,0.647 ,0.812 ,1.0);
    vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

    vec4 lightDir = normalize(vec4(lightPosition, 1) - worldPos);  

    float dot_product = max(dot(normalize(worldNorm), lightDir ), 0.0);
    vec4 diffuse = dot_product * lightColor;

    outColor = (ambient + diffuse) * vec4(objectColor, 1);

}