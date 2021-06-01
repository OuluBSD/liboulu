#ifndef _TemplatesLib_DevContext_h_
#define _TemplatesLib_DevContext_h_

NAMESPACE_TOPSIDE_BEGIN


template <class DevCtx>
struct ContextDevLibT {
	
	
	static const char* TypeStringT(const char* t) {
		thread_local static String s;
		s.Clear();
		s << DevCtx::GetName() << t;
		return s;
	}
	
	
	class ContextComponent :
		public Component<ContextComponent>
	{
		RTTI_COMP0(ContextComponent)
		VIS_COMP_0_0
		COPY_PANIC(ContextComponent)
		void Visit(RuntimeVisitor& vis) override {}
		
	private:
		static int id_counter;
		
	public:
		
		ContextComponent();
		
		void PostLoadFileAny(String s);
		
		
		Callback WhenError;
		
	};
	
	
};


NAMESPACE_TOPSIDE_END

#endif
