

void mainVertex(out vec4 pos_out)
{
	vec3 pos = iPos.xyz;
	vec4 view_pos = iView * vec4(pos, 1.0);
	pos_out = normalize(view_pos);
	vTexCoord[0] = vTexCoord[0]/view_pos[3];
	vTexCoord[1] = vTexCoord[1]/view_pos[3];
	vTexCoord[2] = 1.0/view_pos[3];
}
