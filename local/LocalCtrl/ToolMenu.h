#ifndef _LocalCtrl_ToolMenu_h_
#define _LocalCtrl_ToolMenu_h_

NAMESPACE_TOPSIDE_BEGIN

class ToolBackground : public Ctrl {
	bool horz;
	Color a, b;
	String label;
	
public:
	ToolBackground();
	
	virtual void Paint(Draw& d);
	void Horz(bool b=true) {horz = b;}
	
	ToolBackground& SetLabel(String l) {label = l; return *this;}
	
};


class ToolGrid : public ParentCtrl {
	ToolBackground label;
	Array<ButtonOption> buttons;
	Vector<Ctrl*> grid;
	int cols, height;
	int cursor;
	
public:
	typedef ToolGrid CLASSNAME;
	ToolGrid();
	
	virtual void Layout();
	void Select(int id);
	
	ButtonOption& AddButton(const Image& img, String text="");
	
	int GetHeight(int width);
	int GetCursor() {return cursor;}
	
	ToolGrid& SetColumns(int i) {cols = i; return *this;}
	ToolGrid& SetLabel(String l) {label.SetLabel(l); return *this;}
	ToolGrid& SetHeight(int i) {height = i; return *this;}
	
	Callback WhenSelect;
	
};

class ToolList : public ParentCtrl {
	ToolBackground bg;
	
	Array<ToolGrid> grids;
	
public:
	ToolList();
	
	ToolGrid& AddGrid(String name);
	ToolGrid& GetGrid(int i) {return grids[i];}
	
	virtual void Layout();
	
};

NAMESPACE_TOPSIDE_END

#endif
