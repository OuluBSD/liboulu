#ifndef _EcsCore_Common_h_
#define _EcsCore_Common_h_


NAMESPACE_OULU_BEGIN


struct PerceptionTimestamp {
	double ts = 0;
};

struct HolographicFramePrediction {
	PerceptionTimestamp ts;
	
	
	PerceptionTimestamp Timestamp() const {
		return ts;
	}
};

struct HolographicFrame {
	HolographicFramePrediction pred;
	
	HolographicFramePrediction CurrentPrediction() const {
		return pred;
	}
	
	
};

struct SpatialCoordinateSystem {

};

class IPredictionUpdateListener {

public:
	enum PredictionUpdateReason {
		HolographicSpaceCreateNextFrame,
		HolographicFrameUpdatePrediction,
	};
	
	virtual void OnPredictionUpdated(
		PredictionUpdateReason reason,
		const HolographicFramePrediction& prediction) const = 0;
};

struct HolographicSpace {

};



#define PREFAB_BEGIN(x) \
struct x : \
	EntityPrefab<

#define PREFAB_END \
> { \
    static ComponentMap Make(ComponentStore& store) \
    { \
        auto components = EntityPrefab::Make(store); \
		return components; \
    } \
};





NAMESPACE_OULU_END

#endif
