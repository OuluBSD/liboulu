#ifndef _Geometry_Material_h_
#define _Geometry_Material_h_

NAMESPACE_TOPSIDE_BEGIN


class Model;

struct MaterialParameters {
    vec3 diffuse = {0.5, 0.5, 0.5};
    vec3 ambient = {0,0,0};
    vec3 specular = {0,0,0};
    float shininess = 0;
    
    // Pbr
	vec4 base_clr_factor{ 1, 1, 1, 1 };
	float metallic_factor{ 1 };
	float roughness_factor{ 1 };
	vec3 emissive_factor{ 1, 1, 1 };
	float normal_scale{ 1 };
	float occlusion_strength{ 1 };
	
	
public:
    hash_t GetHashValue() const {
        CombineHash c;
        c.Put(diffuse.GetHashValue());
        c.Put(ambient.GetHashValue());
        c.Put(specular.GetHashValue());
        c.Put(*(dword*)&shininess);
        c.Put(base_clr_factor.GetHashValue());
        c.Put(*(dword*)&metallic_factor);
        c.Put(*(dword*)&roughness_factor);
        c.Put(emissive_factor.GetHashValue());
        c.Put(*(dword*)&normal_scale);
        c.Put(*(dword*)&occlusion_strength);
        return c;
    }
    void Etherize(Ether& e);
	void Clear();
	
};

struct Material {
	Model* owner = 0;
	int id = -1;
	
	TrackChanges<MaterialParameters> params;
	
    int tex_id[TEXTYPE_COUNT];
	GVar::Filter tex_filter[TEXTYPE_COUNT];
	
	
public:
	Material();
	
    hash_t GetHashValue() const {
        CombineHash c;
        c.Put(id);
        c.Put(params->GetHashValue());
        for(int i = 0; i < TEXTYPE_COUNT; i++) {
			c.Put(tex_id[i]);
			c.Put(tex_filter[i]);
        }
        return c;
    }
    
    void Etherize(Ether& e);
    
    // Create a flat (no texture) material.
    Material& SetDiffuse(const Color& clr);
    Material& SetDiffuse(const vec3& clr);
    Material& SetDiffuse(const vec4& clr);
    void SetFlat(
        const vec4&			base_color_factor = vec4{1,1,1,1},
        float				roughness_factor = 1.0f,
        float				metallic_factor = 0.0f,
        const vec4&			emissive_factor = vec4{0,0,0,1});
    void SetTexture(TexType slot, const Image& img, String path);
    void SetDefault();

    void Clear();
    
    
    static Image CreateSolidColorTexture(vec4 clr);
    
	void operator=(const Material& src) {
		id = src.id;
		params = src.params;
        for(int i = 0; i < TEXTYPE_COUNT; i++) {
			tex_id[i] = src.tex_id[i];
			tex_filter[i] = src.tex_filter[i];
        }
	}
};

Material DefaultMaterial();


NAMESPACE_TOPSIDE_END

#endif
