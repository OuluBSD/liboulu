#include "Tutorial5b.h"

#if 0
vec3 Tutorial5b::Barycentric(vec3 pts[3], vec2 P) {
	vec3 u = cross(
		vec3(	pts[2][0] - pts[0][0],
				pts[1][0] - pts[0][0],
				pts[0][0] - P[0]),
		vec3(	pts[2][1] - pts[0][1],
				pts[1][1] - pts[0][1],
				pts[0][1] - P[1]));
	/* `pts` and `P` has integer value as coordinates
	   so `abs(u[2])` < 1 means `u[2]` is 0, that means
	   triangle is degenerate, in this case return something with negative coordinates */
	if (std::abs(u[2]) < 1)
		return vec3(-1, 1, 1);
	return vec3(
		1.0 - (u[0] + u[1]) / u[2],
		              u[1]  / u[2],
		              u[0]  / u[2]);
}

void Tutorial5b::Triangle4(Draw& fb, vec3 pts[3], vec2 tex[3], Texture* tex_img, float intensity, bool have_noise) {
	int w = width;
	int h = height;
	vec2 bboxmin(w - 1,  h - 1);
	vec2 bboxmax(0, 0);
	vec2 clamp(w - 1, h - 1);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			bboxmin[j] = std::max<float>(0.0,      std::min<float>(bboxmin[j], pts[i][j]));
			bboxmax[j] = std::min<float>(clamp[j], std::max<float>(bboxmax[j], pts[i][j]));
		}
	}
	
	vec2 P;
	for (P[0] = bboxmin[0]; P[0] <= bboxmax[0]; P[0]++) {
		for (P[1] = bboxmin[1]; P[1] <= bboxmax[1]; P[1]++) {
			vec3 bc_screen = Barycentric(pts, P);
			if (bc_screen[0] < 0 || bc_screen[1] < 0 || bc_screen[2] < 0)
				continue;
			
			// calculate z-value
			float z = 0;
			for (int i = 0; i < 3; i++)
				z += pts[i][2] * bc_screen[i];
			
			int pos = (int)P[0] + (int)P[1] * width;
			float& zmem = zbuffer[pos];
			if (zmem < z) {
				zmem = z;

				RGBA used_clr;
				used_clr.a = 0;
				if (tex_img) {
					float tex_x = 0, tex_y = 0, bary_sum = 0;
					for(int i = 0; i < 3; i++) {
						tex_x += tex[i][0] * bc_screen[i];
						tex_y += tex[i][1] * bc_screen[i];
					}
					int tex_xi = tex_x * tex_img->GetWidth();
					int tex_yi = tex_y * tex_img->GetHeight();
					tex_xi = std::max(0, std::min(tex_img->GetWidth() - 1, tex_xi));
					tex_yi = std::max(0, std::min(tex_img->GetHeight() - 1, tex_yi));
					const byte* b = tex_img->GetIter(tex_xi, tex_yi);
					used_clr.r = b[2] * intensity;
					used_clr.g = b[1] * intensity;
					used_clr.b = b[0] * intensity;
				}
				else {
					used_clr.r = used_clr.g = used_clr.b = 255 * intensity;
				}
				
				fb.DrawLine(P[0], P[1], P[0], P[1], 1, used_clr);
			}
		}
	}
}
#endif

void Tutorial5b::DrawObj(SdlCpuStateDraw& fb, bool use_texture) {
	ASSERT(fb.HasTarget());
	SdlCpuDataState& state = fb.GetState();
	
	float ratio = (float)height / (float)width;
	float f = ts.Seconds() / phase_time;
	float f2 = 1 - fabs(2 * f - 1);
	float angle = f * (2.0 * M_PI);
	float x = cos(angle);
	float y = sin(angle);
	
	if (!zbuffer) {
		int size = width * height;
		zbuffer = new float[size];
		zbuffer_empty = new float[size];
		
		float* it = zbuffer_empty;
		float* end = it + size;
		while (it != end)
			*it++ = -FLT_MAX;
	}
	memcpy(zbuffer, zbuffer_empty, width * height * 4);
	
	float eye_angle = (use_texture ? -1 : +1) * f /** 0.25*/ * M_2PI;
	float eye_x = cos(eye_angle);
	float eye_y = sin(eye_angle);
	float x_mod = 0.2 * eye_x;
	float y_mod = 0.2 * eye_y;
	mat4 perspective {
		vec4{1,		0,	    0,		0},
		vec4{0,		1,	    0,		0},
		vec4{0,		0,	    1,		0},
		vec4{0,		0, -1./5.,		1}
	};
	
	vec3 eye {0.2f * eye_x, 0.3f * eye_y, 1};
	vec3 center {0, 0, 0};
	vec3 up {0, 1, 0};
	mat4 lookat = LookAt(eye, center, up);
	mat4 port;
	
	if (phase == 0)
		port = GetViewport((-1 + x_mod) * ratio, -1 + y_mod, (2 - x_mod) * ratio, 2 + y_mod, 255);
	else
		port = GetViewport(-1 * ratio, -1, 2 * ratio, 2, 255);
	
	state.view = port * perspective * lookat;
	state.light_dir = vec3 {sin(angle), 0.0, cos(angle)};
	
	#if 0
	Ref<EntityStore> store = GetEntity()->GetEngine().Get<EntityStore>();
	vec3 light_dir {sin(angle), 0.0, cos(angle)};
	PoolRef p = store->GetRoot();
	for(EntityRef& e : p->GetEntities()) {
		auto model = loader.GetModel();
		if (model) for(const Mesh& mesh : model->GetMeshes()) {
			int tri_count = mesh.GetTriangleCount();
			Texture* tex_img = NULL;
			if (use_texture && mesh.tex_id[TEXTYPE_DIFFUSE] >= 0)
				tex_img = &model->textures[mesh.tex_id[TEXTYPE_DIFFUSE]];
			
			for(int i = 0; i < tri_count; i++) {
				ivec3 indices = mesh.GetTriangleIndices(i);
				vec3 screen_coord[3];
				vec3 world_coord[3];
				vec2 tex_coord[3];
				for(int j = 0; j < 3; j++) {
					vec3 v = mesh.GetVertCoord(indices[j]);
					
					vec4 v4 {v[0], v[1], v[2], 1.0};
					vec4 screen = view * v4;
					screen.Project();
					
					screen_coord[j][0] = (int)((screen[0] + 1.0) * width  / 2.0);
					screen_coord[j][1] = (int)((screen[1] + 1.0) * height / 2.0);
					screen_coord[j][2] = screen[2];
					world_coord[j] = v;
					tex_coord[j] = mesh.GetTexCoord(indices[j]);
				}
				
				vec3 n = (world_coord[2] - world_coord[0]) ^
						 (world_coord[1] - world_coord[0]);
				n.Normalize();
				
				float intensity = std::max(0.0f, n * light_dir);
				Triangle4(fb, screen_coord, tex_coord, tex_img, intensity, false);
			}
		}
	}
	#endif
}

void VertexShader5::Process(SdlCpuVertexShaderArgs& a) {
	/*#version 330 core
	layout (location = 0) in vec3 aPos;
	layout (location = 1) in vec3 aNormal;
	layout (location = 2) in vec2 aTexCoords;
	
	out vec2 TexCoords;
	
	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;
	
	void main()
	{
	    TexCoords = aTexCoords;
	    gl_Position = projection * view * model * vec4(aPos, 1.0);
	}*/
	
	// TODO DataObject is_global_view ????
	
	int width = a.generic->iResolution[0];
	int height = a.generic->iResolution[1];
	vec4 screen = a.va->view * a.v.position.Splice().Embed();
	screen.Project();
	a.v.position[0] = (int)((screen[0] + 1.0) * width  / 2.0);
	a.v.position[1] = (int)((screen[1] + 1.0) * height / 2.0);
	a.v.position[2] = screen[2];
	a.v.position[3] = 1.0f;
}

void FragmentShader5::Process(SdlCpuFragmentShaderArgs& args) {
	#if 0
	float w = args.generic->iResolution[0];
	float h = args.generic->iResolution[1];
	float x = args.frag_coord[0] / w;
	float y = args.frag_coord[1] / h;
	args.frag_color_out = vec4(x, y, 0, 1);
	#endif
	
	ASSERT(args.fa);
	vec3& n = args.normal;
	vec3& light_dir = args.fa->light_dir;
	float m = n * light_dir;
	float intensity = std::max(0.0f, m);
	
	vec4& used_clr = args.frag_color_out;
	used_clr[3] = 0;
	
	if (args.tex_img) {
		Texture& tex = args.tex_img->GetGeomTex();
		float tex_x = args.tex_coord[0];
		float tex_y = args.tex_coord[1];
		float bary_sum = 0;
		int tex_xi = tex_x * tex.GetWidth();
		int tex_yi = tex_y * tex.GetHeight();
		tex_xi = std::max(0, std::min(tex.GetWidth() - 1, tex_xi));
		tex_yi = std::max(0, std::min(tex.GetHeight() - 1, tex_yi));
		const byte* b = tex.GetIter(tex_xi, tex_yi);
		used_clr[0] = b[2] * intensity;
		used_clr[1] = b[1] * intensity;
		used_clr[2] = b[0] * intensity;
	}
	else {
		used_clr[0] = intensity;
		used_clr[1] = intensity;
		used_clr[2] = intensity;
	}
	
}
