#pragma once


NAMESPACE_ECS_BEGIN


struct PbrRenderable;


////////////////////////////////////////////////////////////////////////////////
// PbrModelCache
// Stores all of the PbrModels in the system to avoid duplication. As well as
// it allows for lazy-assignment of Model files to PbrRenderable components
// This allows you to set the ModelName on a PbrRenderable component, and the 
// PbrModelCache will automatically assign the Model field of the PbrRenderable once the model has been loaded
class PbrModelCache : public System<PbrModelCache>
{
public:
	using Base = System<PbrModelCache>;
	RTTI_DECL1(PbrModelCache, Base);
	
    PbrModelCache(Engine& core, std::shared_ptr<Pbr::Resources> pbrResources);

    void RegisterModel(std::string_view name, std::shared_ptr<Pbr::Model> model);
    bool ModelExists(std::string_view name);
    PbrRenderableRef SetModel(std::string_view name, PbrRenderableRef pbrRenderableComponent);
    PbrRenderableRef SetModel(std::string_view name, Ecs::ComponentMap& componentMap);

protected:
    void Update(double) override;
    void Uninitialize() override;

private:
    std::shared_ptr<Pbr::Resources> m_pbrResources{ nullptr };
    std::map<std::string, std::shared_ptr<Pbr::Model>> m_modelMap;
};




NAMESPACE_ECS_END
