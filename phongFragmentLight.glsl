#version 400

#define MAX_LIGHTS 1

struct Light {
	vec3 direction;
    vec3 position;
	float reflectionRadius;

};

uniform Light lights[MAX_LIGHTS];

in vec4 worldPos;
in vec4 worldNorm;
in vec3 objectColor;
out vec4 out_color;
uniform vec3 viewPos;

vec4 calculateDirectionalLight(Light light)
{
	vec3 lightVector = normalize(-light.direction);
	float dot_product = max(dot(worldNorm.xyz, lightVector), 0.0);

	float specularStrength = 0.8;
	vec3 viewVector = normalize(viewPos - worldPos.xyz);
	float spec = pow(max(dot(viewVector, reflect(-lightVector, worldNorm.xyz)), 0.0), 40);

	vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);
	vec4 diffuse = dot_product * vec4(0.385, 0.647, 0.812, 1.0);
	vec4 specular = specularStrength * spec * vec4(0.385, 0.647, 0.812, 1.0);

	return (ambient + diffuse + specular);
}

vec4 calculatePointLight(Light light)
{
	//light.position = vec3(0.0f, 5.0f, 0.0f);
	vec3 lightVector = normalize(light.position - worldPos.xyz);

	float dist = length(light.position - worldPos.xyz);
	float attenuation = 1.0 / (1.0 + 0.1 * dist + 0.01 * (dist * dist) );

	float dot_product = max(dot(worldNorm.xyz, lightVector), 0.0);

	float s = 0.8;
	vec3 viewVector = normalize(viewPos - worldPos.xyz);
	float spec = pow(max(dot(viewVector, reflect(-lightVector, worldNorm.xyz)), 0.0), 40);
	
	vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);
	vec4 diffuse = dot_product * vec4(0.385, 0.647, 0.812, 1.0);
	vec4 specular = s * spec * vec4(0.385, 0.647, 0.812, 1.0);

	ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

	return (ambient + diffuse + specular);
}


void main(void)
{
    /*float specularStrength = 1.0;
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
    if ( dot ( worldNorm , lightDir ) < 0.0) {
    specular = vec4 (0.0 , 0.0 , 0.0 , 0.0);
    }else{
        specular = specularStrength * spec * vec4(lightColor,1); 
    }

    //specular = specularStrength * spec * vec4(lightColor,1); 

    out_color = (ambient + diffuse + specular);*/

    vec4 result;
	for(int i = 0 ; i < MAX_LIGHTS; i++)
	{

		result += calculateDirectionalLight(lights[i]);

	}

	out_color =  result;
}