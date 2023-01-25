#include "ParallelLib.h"


NAMESPACE_TOPSIDE_BEGIN

void DebugMainLoop();

NAMESPACE_TOPSIDE_END



NAMESPACE_PARALLEL_BEGIN


template <class Dim>
HandleT<Dim>::HandleT() :
	decor(this)
{
	maximized = false;
	id = -1;
	
	this->Add(decor);
	
	Box box = Dim::GetDefaultHandleDimensions(40);
	this->SetFrameBox(box);
	
}

template <class Dim>
typename Dim::TopContainer* HandleT<Dim>::GetTopContainer() {
	auto* proxy = this->GetLinkedProxy();
	if (!proxy)
		return 0;
	return CastPtr<typename Dim::TopContainer>(proxy);
}

template <class Dim>
void HandleT<Dim>::SetInterface(InterfaceProxy& iface) {
	if (this->GetLinkedProxy()) {
		TODO // clear old
	}
	
	iface.SetTarget(*this);
	
	typename Dim::Interaction* iact = CastPtr<typename Dim::Interaction>(&iface);
	if (iact)
		Dim::Interaction::Add(*iact);
	// --> GetLinkedProxy()
}

template <class Dim>
void HandleT<Dim>::Paint(DrawT& draw) {
	TODO // permanent
}

template <>
void HandleT<Ctx2D>::Paint(DrawT& draw) {
	Color bg = GrayColor(128+64);
	Sz handle_sz(this->GetFrameBox().GetSize());
	draw.DrawRect(handle_sz, bg);
}

template <class Dim>
void HandleT<Dim>::Layout() {
	int title_h = 28;
	Box handle_box(this->GetFrameBox().GetSize());
	Sz handle_sz = handle_box.GetSize();
	ASSERT(!handle_sz.IsEmpty());
	Box decor_box = handle_box;
	decor_box.bottom = decor_box.top + title_h;
	decor.SetFrameBox(decor_box);
	
	typename Dim::Interaction* iact = CastPtr<typename Dim::Interaction>(this->GetLinkedProxy());
	if (iact) {
		Box content_box = handle_box;
		content_box.top = content_box.top + title_h;
		#if 0
		content_box.top += 5;
		content_box.bottom -= 5;
		content_box.left += 5;
		content_box.right -= 5;
		#endif
		iact->SetFrameBox(content_box);
	}
}

template <class Dim>
void HandleT<Dim>::Title(const String& title) {
	decor.SetLabel(title);
}

template <class Dim>
typename Dim::Interface& HandleT<Dim>::Sizeable(bool b) {
	TODO
}

template <class Dim>
typename Dim::Interface& HandleT<Dim>::MaximizeBox(bool b) {
	TODO
}

template <class Dim>
typename Dim::Interface& HandleT<Dim>::MinimizeBox(bool b) {
	TODO
}

template <class Dim>
int HandleT<Dim>::Run(bool appmodal) {
	DebugMainLoop();
	return 0;
}

template <class Dim>
String HandleT<Dim>::GetTitle() const {
	return decor.GetLabel();
}

template <class Dim>
void HandleT<Dim>::SetPendingPartialRedraw() {
	pending_partial_redraw = true;
}

template <class Dim>
GeomInteraction* HandleT<Dim>::GetDynamicallyLinked() const {
	auto* abs_proxy = this->GetLinkedProxy();
	if (abs_proxy)
		return abs_proxy->GetInteraction();
	return 0;
}

template <class Dim>
ScopeT<Dim>& HandleT<Dim>::GetScope() const {
	ScopeT<Dim>* owner = this->GetParent().Get();
	ASSERT(owner);
	return *owner;
}

template <class Dim>
HandleSystemT<Dim>& HandleT<Dim>::GetHandleSystem() const {
	ScopeT<Dim>* owner0 = this->GetParent().Get();
	ASSERT(owner0);
	HandleSystemT<Dim>* owner1 = owner0->GetParent().Get();
	ASSERT(owner1);
	return *owner1;
}

template <class Dim>
void HandleT<Dim>::Close() {
	Scope& scope = GetScope();
	scope.QueueCloseHandle(id);
}

template <class Dim>
void HandleT<Dim>::Maximize() {
	Scope& scope = GetScope();
	scope.FocusHandlePos(id);
	scope.MaximizeHandle(id);
	maximized = true;
}

template <class Dim>
void HandleT<Dim>::Minimize() {
	Scope& scope = GetScope();
	scope.MinimizeHandle(id);
}

template <class Dim>
void HandleT<Dim>::CloseOthers() {
	Scope& scope = GetScope();
	scope.CloseOthers(id);
}

template <class Dim>
void HandleT<Dim>::SetMaximized(bool b) {
	maximized = b;
}

template <class Dim>
bool HandleT<Dim>::IsMaximized() const {
	return maximized;
}

template <class Dim>
bool HandleT<Dim>::IsActive() const {
	Scope& scope = this->GetScope();
	return scope.IsActiveHandle(id);
}

template <class Dim>
void HandleT<Dim>::StoreRect() {
	stored_box = this->GetFrameBox();
}

template <class Dim>
void HandleT<Dim>::LoadRect() {
	ASSERT(stored_box.bottom && stored_box.right);
	SetFrameBox(stored_box);
}

template <class Dim>
void HandleT<Dim>::SetFrameBox(const Box& b) {
	#if 0
	TopContainer* tc = GetTopContainer();
	if (tc)
		tc->SetFrameBox(b);
	#else
	Dim::Interaction::SetFrameBox(b);
	#endif
}

template <class Dim>
bool HandleT<Dim>::IsPendingPartialRedraw() const {
	return pending_partial_redraw;
}















template <class Dim>
GeomDecorationT<Dim>::GeomDecorationT(Handle* h) {
	handle = h;
	
}

template <class Dim>
void GeomDecorationT<Dim>::Paint(DrawT& draw) {
	TODO // permanent
}

template <>
void GeomDecorationT<Ctx2D>::Paint(DrawT& id) {
	Color border_tl = GrayColor(128+64);
	Color border_br = GrayColor(128);
	
	Size sz(GetFrameSize());
	ASSERT(!sz.IsEmpty());
	
	id.DrawRect(sz, White());
	id.DrawLine(0,0, 0, sz.cy-1, 1, border_tl);
	id.DrawLine(0,0, sz.cx-1, 0, 1, border_tl);
	id.DrawLine(sz.cx-1,0, sz.cx-1, sz.cy-1, 1, border_br);
	id.DrawLine(0,sz.cy-1, sz.cx-1, sz.cy-1, 1, border_br);
	
	Color left, right;
	ASSERT(handle);
	if (!handle) return;
	if (handle->IsActive()) {
		left = Color(0, 64, 128);
		right = Color(57, 141, 195);
	} else {
		left = GrayColor();
		right = GrayColor(195);
	}
	id.DrawRect(0, 0, sz.cx, sz.cy, left);
	id.DrawText(7, 4, label, StdFont(15), Black());
	id.DrawText(6, 3, label, StdFont(15), White());
	
	Color tl = GrayColor(128+64+32);
	Color br = GrayColor(128-64-32);
	
	id.DrawLine(0,0, sz.cx-1, 0, 1, tl);
	id.DrawLine(0,0, 0, sz.cy-1, 1, tl);
	id.DrawLine(sz.cx-1, sz.cy-1, sz.cx-1, 0, 1, br);
	id.DrawLine(sz.cx-1, sz.cy-1, 0, sz.cy-1, 1, br);
	
}

template <class Dim>
void GeomDecorationT<Dim>::LeftDown(Pt p, dword keyflags) {
	TODO
}

template <class Dim>
void GeomDecorationT<Dim>::LeftDouble(Pt p, dword keyflags) {
	TODO
}

template <class Dim>
void GeomDecorationT<Dim>::LeftUp(Pt p, dword keyflags) {
	TODO
}

template <class Dim>
void GeomDecorationT<Dim>::MouseMove(Pt p, dword keyflags) {
	TODO
}

template <class Dim>
void GeomDecorationT<Dim>::RightDown(Pt p, dword keyflags) {
	TODO
}

template <class Dim>
void GeomDecorationT<Dim>::LocalMenu(Bar& bar) {
	TODO
}


HANDLETYPE_EXCPLICIT_INITIALIZE_CLASS(HandleT)
HANDLETYPE_EXCPLICIT_INITIALIZE_CLASS(GeomDecorationT)

NAMESPACE_PARALLEL_END
