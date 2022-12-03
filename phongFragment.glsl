#version 400
in vec4 worldPos;
in vec4 worldNorm;
in vec3 objectColor;
out vec4 out_color;
uniform vec3 viewPos;

void main(void)
{
    float specularStrength = 1.0;
    vec3 lightPosition = vec3(0.0,0.0,0.0);
    vec3 lightColor = vec3(0.4, 0.6, 0.8);
    float h = 1;

    vec4 lightDir = normalize(vec4(lightPosition, 1) - worldPos);  
    float dot_product = max(dot(worldNorm, lightDir ), 0.0);

    vec4 diffuse = dot_product * vec4(lightColor,1);

    vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);
    
    vec4 viewDir = normalize(vec4(viewPos, 1) - worldPos);
    vec4 reflectDir = reflect(-lightDir, worldNorm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), h);

    //reflection component

    vec4 specular;
    /*if ( dot ( worldNorm , lightDir ) < 0.0) {
    specular = vec4 (0.0 , 0.0 , 0.0 , 0.0);
    }else{
        specular = specularStrength * spec * vec4(lightColor,1); 
    }*/

    specular = specularStrength * spec * vec4(lightColor,1); 

    out_color = (ambient + diffuse + specular);
}