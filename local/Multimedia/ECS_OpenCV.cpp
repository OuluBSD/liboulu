#include "System.h"
#if HAVE_OPENCV

NAMESPACE_OULU_BEGIN


bool OpenCVComponent::LoadFileAny(String path) {
	vi.Stop();
	
	if (path.Left(6) == "<input" && path.Right(1) == ">") {
		String numstr = path.Mid(6, path.GetCount() - 7);
		int id = StrInt(numstr);
		return LoadInput(id);
	}
	
	return false;
}

bool OpenCVComponent::LoadInput(int id) {
	if (id < 0 || id >= devmgr.GetNativeCount()) {
		last_error = "invalid input id: " + IntStr(id);
		return false;
	}
	
	V4L2_Device& dev = devmgr.GetNative(id);
	for(int l = 0; l < dev.GetCaptureCount() && !vi.IsCap(); l++) {
		OpenCVCaptureDevice& cap = dev.GetCapture(l);
		int fmt, res;
		if (cap.FindClosestFormat(def_cap_sz, def_cap_fps, 0.5, 1.5, fmt, res)) {
			if (cap.OpenDevice(fmt, res)) {
				vi.SetCap(cap.AsRef<MediaSourceStream>());
				vi.Start(true);
				
				return true;
			}
			else {
				last_error = "couldn't open webcam " + cap.GetPath();
			}
		}
		else {
			last_error =
				"couldn't find expected format " + def_cap_sz.ToString() +
				", " + IntStr(def_cap_fps) +
				"fps from webcam "+ cap.GetPath();
		}
	}
	
	return false;
}


NAMESPACE_OULU_END

#endif