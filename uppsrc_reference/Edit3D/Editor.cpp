#include "Edit3D.h"


#define IMAGECLASS ImagesImg
#define IMAGEFILE <Edit3D/Images.iml>
#include <Draw/iml_source.h>



NAMESPACE_TOPSIDE_BEGIN




GeomProjectCtrl::GeomProjectCtrl(Edit3D* e) {
	this->e = e;
	
	time.WhenCursor << THISBACK(OnCursor);
	tree.WhenAction << THISBACK(TreeSelect);
	
	hsplit.Horz().SetPos(2000) << metasplit << vsplit,
	metasplit.Vert() << tree << props;
	vsplit.Vert().SetPos(7500) << grid << time;
	
	grid.SetGridSize(2,2);
	for(int i = 0; i < 4; i++) {
		rends[i].owner = e;
		grid.Add(rends[i]);
	}
	rends[0].SetViewMode(VIEWMODE_YZ);
	rends[1].SetViewMode(VIEWMODE_XZ);
	rends[2].SetViewMode(VIEWMODE_XY);
	rends[3].SetViewMode(VIEWMODE_PERSPECTIVE);
	rends[0].SetCameraSource(CAMSRC_FOCUS);
	rends[1].SetCameraSource(CAMSRC_FOCUS);
	rends[2].SetCameraSource(CAMSRC_FOCUS);
	rends[3].SetCameraSource(CAMSRC_PROGRAM);
	
	
}

void GeomProjectCtrl::Update(double dt) {
	GeomAnim& anim = e->anim;
	GeomVideo& video = e->video;
	bool was_playing = anim.is_playing || video.is_importing;
	
	if (video.is_importing) {
		video.Update(dt);
		TimelineData();
	}
	else {
		anim.Update(dt);
	}
	
	time.SetSelectedColumn(anim.position);
	time.Refresh();
	
	if (anim.is_playing || was_playing) {
		for(int i = 0; i < 4; i++) {
			rends[i].Refresh();
		}
	}
}

void GeomProjectCtrl::Data() {
	GeomProject& prj = e->prj;
	
	tree.SetRoot(ImagesImg::Root(), "Project");
	
	if (tree_scenes < 0)
		tree_scenes = tree.Add(0, ImagesImg::Scenes(), "Scenes");
	
	for(int i = 0; i < prj.scenes.GetCount(); i++) {
		GeomScene& scene = prj.scenes[i];
		String name = scene.name.IsEmpty() ? "Scene #" + IntStr(i) : scene.name;
		int j = tree.Add(tree_scenes, ImagesImg::Scene(), i, name);
		
		TreeDirectory(j, scene);
		
		if (i == 0 && !tree.HasFocus())
			tree.SetCursor(j);
	}
	
	/*for(int i = 0; i < prj.octrees.GetCount(); i++) {
		OctreePointModel& o = prj.octrees[i];
		String name = prj.dictionary[o.id];
		tree.Add(tree_octrees, ImagesImg::Octree(), o.id, name);
	}*/
	
	tree.Open(0);
	
	TreeSelect();
}

void GeomProjectCtrl::TreeSelect() {
	if (!tree.HasFocus())
		return;
	
	int cursor = tree.GetCursor();
	int parent = tree.GetParent(cursor);
	if (parent == tree_scenes) {
		int i = tree.Get(cursor);
		GeomScene& s = e->prj.scenes[i];
		
	}

}

void GeomProjectCtrl::OnCursor(int i) {
	e->anim.position = i;
}

void GeomProjectCtrl::TreeDirectory(int id, GeomDirectory& dir) {
	for(int i = 0; i < dir.subdir.GetCount(); i++) {
		GeomDirectory& subdir = dir.subdir[i];
		String name = dir.subdir.GetKey(i);
		int j = tree.Add(id, ImagesImg::Directory(), i, name);
		TreeDirectory(j, subdir);
	}
	for(int i = 0; i < dir.objs.GetCount(); i++) {
		GeomObject& o = dir.objs[i];
		Image img;
		switch (o.type) {
			case GeomObject::O_CAMERA: img = ImagesImg::Camera(); break;
			case GeomObject::O_MODEL:  img = ImagesImg::Model(); break;
			case GeomObject::O_OCTREE: img = ImagesImg::Octree(); break;
			default: img = ImagesImg::Object();
		}
		int j = tree.Add(id, img, i, o.name);
	}
}

void GeomProjectCtrl::TimelineData() {
	GeomProject& prj = e->prj;
	GeomScene& scene = e->state.GetActiveScene();
	
	time.SetCount(scene.objs.GetCount());
	time.SetKeypointRate(prj.kps);
	time.SetLength(scene.length);
	time.SetKeypointColumnWidth(13);
	
	for(int i = 0; i < scene.objs.GetCount(); i++) {
		GeomObject& o = scene.objs[i];
		/*int j = prj.list[i];
		int id = j / GeomProject::O_COUNT;
		int type = j % GeomProject::O_COUNT;*/
		
		String name = o.name.IsEmpty() ? IntStr(i) : o.name;
		
		TimelineRowCtrl& row = time.GetRowIndex(i);
		row.SetTitle(name);
		
		row.SetKeypoints(o.timeline.keypoints.GetKeys());
		
		row.Refresh();
	}
	
	time.Refresh();
}









Edit3D::Edit3D() :
	v0(this),
	v1(this)
{
	state.prj = &prj;
	anim.state = &state;
	video.anim = &anim;
	
	anim.WhenSceneEnd << THISBACK(OnSceneEnd);
	
	Sizeable().MaximizeBox();
	Title("Edit3D");
	
	SetView(VIEW_GEOMPROJECT);
	Add(v0.hsplit.SizePos());
	
	AddFrame(menu);
	menu.Set([this](Bar& bar) {
		bar.Sub(t_("File"), [this](Bar& bar) {
			bar.Add(t_("Exit"), THISBACK(Exit));
		});
		
	});
	
	AddFrame(tool);
	RefrehToolbar();
	
	
	tc.Set(-1000/60, THISBACK(Update));
	
}

void Edit3D::SetView(ViewType view) {
	
	if (this->view == VIEW_GEOMPROJECT)
		RemoveChild(&v0.hsplit);
	else if (this->view == VIEW_VIDEOIMPORT)
		RemoveChild(&v1);
	
	this->view = view;
	
	if (this->view == VIEW_GEOMPROJECT)
		Add(v0.hsplit.SizePos());
	else if (this->view == VIEW_VIDEOIMPORT)
		Add(v1.SizePos());
	
}

void Edit3D::RefrehToolbar() {
	tool.Set(THISBACK(Toolbar));
}

void Edit3D::Toolbar(Bar& bar) {
	bar.Add(true,  t_("Stop"),  ImagesImg::Stop(),  THISBACK(Stop)).Key(K_F6);
	
	if (anim.is_playing)
		bar.Add(true, t_("Pause"), ImagesImg::Pause(), THISBACK(Pause)).Key(K_F5);
	else
		bar.Add(true,  t_("Play"),  ImagesImg::Play(),  THISBACK(Play)).Key(K_F5);
	
}

GeomScene& Edit3D::GetActiveScene() {
	return state.GetActiveScene();
}

void Edit3D::Exit() {
	Close();
}

void Edit3D::RefreshData() {
	PostCallback(THISBACK(Data));
}

void Edit3D::Stop() {
	anim.Reset();
	RefrehToolbar();
}

void Edit3D::Pause() {
	anim.Pause();
	RefrehToolbar();
}

void Edit3D::Play() {
	anim.Play();
	RefrehToolbar();
}

void Edit3D::OnSceneEnd() {
	RefrehToolbar();
}

void Edit3D::RefrehRenderers() {
	if (view == VIEW_GEOMPROJECT) {
		for(int i = 0; i < 4; i++)
			v0.rends[i].Refresh();
	}
	else if (view == VIEW_VIDEOIMPORT) {
		v1.RefreshRenderers();
	}
}

void Edit3D::Update() {
	double dt = ts.Seconds();
	ts.Reset();
	
	if (view == VIEW_GEOMPROJECT)
		v0.Update(dt);
	else if (view == VIEW_VIDEOIMPORT)
		v1.Update(dt);
}

void Edit3D::Data() {
	if (view == VIEW_GEOMPROJECT)
		v0.Data();
}

void Edit3D::LoadTestProject(int test_i) {
	
	// Cler project
	prj.Clear();
	
	// Add scene
	GeomScene& scene = prj.AddScene();
	
	// Add camera
	GeomObject& cam = scene.GetAddCamera("camera");
	
	
	if (test_i == 0) {
		GeomObject& mdl = scene.GetAddModel("some model");
		
		ModelBuilder mb;
		mb.AddBox(0, 1, 1);
		
		mdl.mdl = mb.Detach();
		
		scene.length = prj.kps * 4 + 1;
		float step = M_PI * 2 / 4;
		float angle = 0;
		float cam_radius = 2;
		for(int i = 0; i < 5; i++) {
			GeomKeypoint& kp = cam.timeline.GetAddKeypoint(i * prj.kps);
			kp.position = vec3(sin(angle), 0, cos(angle)) * cam_radius;
			kp.orientation = AxesQuat(angle, 0, 0);
			angle += step;
		}
		
	}
	else if (test_i == 1) {
		
		// Create octree
		GeomObject& omodel = scene.GetAddOctree("octree");
		Octree& o = omodel.octree.octree;
		o.Initialize(-3, 8); // 1 << 6 = 32x32x32 meters
		
		// Create points in form of sphere
		float radius = 100;
		bool random_points = 1;
		int points = 256;
		for(int i = 0; i < points; i++) {
			float yaw, pitch;
			if (random_points) {
				yaw = Randomf() * M_PI * 2;
				float f = (Randomf() * 2 - 1);
				pitch = f * (M_PI / 2);
			}
			else {
				float f = ((float)i / (float)points);
				yaw = f * M_PI * 2;
				pitch = 0;//fmodf(f * M_PI * 40, M_PI) - M_PI/2;
			}
			
			vec3 pos = AxesDir(yaw, pitch) * radius;
			OctreeNode* n = o.GetAddNode(pos, -3);
			Pointcloud::Point& p = n->Add<Pointcloud::Point>();
			p.SetPosition(pos);
			//LOG(pos.ToString() + ": " + HexStr(n));
		}
		
		// Move camera linearly around sphere
		int seconds = 3;
		scene.length = prj.kps * seconds;
		int kp_step = 3;
		float step = M_PI * 2 / (scene.length / kp_step - 1);
		float angle = 0;
		float cam_radius = radius + 2;
		for(int i = 0; i < scene.length; i += kp_step) {
			GeomKeypoint& kp = cam.timeline.GetAddKeypoint(i);
			kp.position = vec3(sin(angle), 0, cos(angle)) * cam_radius;
			kp.orientation = AxesQuat(angle, 0, 0);
			angle += step;
		}
		
		
	}
	else TODO
	
	
	GeomKeypoint& kp = cam.timeline.keypoints.Get(0);
	state.program.position = kp.position;
	state.program.orientation = kp.orientation;
	state.active_scene = 0;
	
	Data();
	v0.TimelineData();
	v0.tree.OpenDeep(v0.tree_scenes);
}

void Edit3D::LoadWmrStereoPointcloud(String directory) {
	video.SetWmrCamera();
	video.LoadDirectory(directory, 30);
	Data();
	v0.TimelineData();
	v0.tree.OpenDeep(v0.tree_scenes);
	
	SetView(VIEW_VIDEOIMPORT);
}




EditConfiguration::EditConfiguration() {
	background_clr = Color(43, 44, 46);
	
	
}



NAMESPACE_TOPSIDE_END







