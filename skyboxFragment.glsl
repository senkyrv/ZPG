#version 400

out vec4 fColor;
in vec3 uv;
uniform samplerCube textureUnitID;

void main () {

  //fColor = vec4(1, 0, 0, 1);
  fColor = texture(textureUnitID, uv);

};