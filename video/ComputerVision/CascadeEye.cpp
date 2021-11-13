#include "ComputerVision.h"


NAMESPACE_TOPSIDE_BEGIN

void LoadCascadeEye(Cascade& c) {
	c.classifiers.SetCount(24);
	auto sc_iter = c.classifiers.Begin();
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(6);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 20 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 20 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 1 << 4 << 15 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 6 << 4 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 10 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 3 << 10 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 2 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 8 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 9 << 8 << 3 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(12);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 17 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 6 << 17 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 10 << 1 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 14 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 10 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 10 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 1 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 3 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 1 << 15 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 15 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 3 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 5 << 9 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 9 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 10 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 6 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 2 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 17 << 2 << 3 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(9);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 5 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 5 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 9 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 3 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 6 << 6 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 6 << 2 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 9 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 3 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 3 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 4 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 6 << 4 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 1 << 1 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(16);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 20 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 20 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 9 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 6 << 3 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 3 << 12 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 12 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 16 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 10 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 10 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 8 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 7 << 6 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 7 << 2 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 14 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 15 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 7 << 2 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 7 << 1 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 12 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 12 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 1 << 6 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(23);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 9 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 3 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 11 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 11 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 12 << 5 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 16 << 5 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 7 << 6 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 2 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 19 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 7 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 6 << 6 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 6 << 2 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 12 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 14 << 12 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 9 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 9 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 8 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 11 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 4 << 11 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 1 << 14 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 14 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 9 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 13 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 14 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 5 << 3 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 5 << 1 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 4 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 19 << 4 << 1 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(27);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 12 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 4 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 11 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 12 << 11 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 9 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 9 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 7 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 3 << 8 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 11 << 12 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 11 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 16 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 4 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 2 << 5 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 14 << 2 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 2 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 8 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 4 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 4 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 0 << 2 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 7 << 2 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 18 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 6 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 6 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 2 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 13 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 2 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 9 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 9 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 11 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 11 << 2 << 4 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(28);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 9 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 9 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 12 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 12 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 10 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 10 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 16 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 16 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 9 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 3 << 9 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 10 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 14 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 14 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 15 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 14 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 14 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 15 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 19 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 19 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 9 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 3 << 14 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 5 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 19 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 9 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 9 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 13 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 11 << 13 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 1 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 11 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 2 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 1 << 6 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 14 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 6 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 16 << 1 << 1 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(36);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 15 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 13 << 15 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 1 << 5 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 3 << 5 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 17 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 18 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 19 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 3 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 5 << 1 << 14 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 16 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 16 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 4 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 7 << 4 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 1 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 1 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 3 << 8 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 8 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 9 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 9 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 4 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 17 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 18 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 1 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 10 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 1 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 13 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 3 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 1 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 6 << 9 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 3 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 9 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 19 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 10 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 3 << 5 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(47);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 9 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 9 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 2 << 10 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 10 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 9 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 7 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 12 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 14 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 15 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 7 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 0 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 0 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 3 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 6 << 1 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 11 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 12 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 6 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 2 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 18 << 9 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 18 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 11 << 4 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 4 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 17 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 9 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 9 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 2 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 1 << 7 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 7 << 1 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 5 << 11 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 11 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 3 << 5 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 5 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 9 << 5 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 14 << 5 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 10 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 10 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 8 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 11 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 4 << 11 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 3 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 4 << 9 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 7 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 1 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 1 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 11 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 11 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 8 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 4 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 4 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 7 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 0 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 17 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 15 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 12 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 12 << 1 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(48);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 3 << 10 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 10 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 9 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 7 << 3 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 8 << 3 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 7 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 13 << 7 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 7 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 7 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 10 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 6 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 18 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 18 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 5 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 8 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 19 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 19 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 9 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 10 << 6 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 1 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 1 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 1 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 10 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 1 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 1 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 5 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 5 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 2 << 7 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 4 << 7 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 14 << 15 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 14 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 16 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 16 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 18 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 13 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 13 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 3 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 3 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 17 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 18 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 16 << 5 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 3 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 3 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 4 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 4 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 13 << 1 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 8 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 8 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 11 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 3 << 11 << 2 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(55);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 1 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 14 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 5 << 5 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 14 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 15 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 6 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 2 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 7 << 1 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 9 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 5 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 5 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 11 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 16 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 16 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 18 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 1 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 2 << 9 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 9 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 9 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 10 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 10 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 3 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 3 << 2 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 1 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 1 << 5 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 5 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 0 << 8 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 6 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 2 << 1 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 4 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 6 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 7 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 7 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 7 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 6 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 6 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 1 << 5 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 13 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 18 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 9 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 19 << 9 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 7 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 7 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 3 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 3 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 9 << 2 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 9 << 1 << 4 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 13 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 7 << 1 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 9 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 3 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 1 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 4 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 5 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 8 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 2 << 4 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 14 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 16 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 1 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 7 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 6 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 1 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 19 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 19 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 17 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 17 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 12 << 3 << 3 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(32);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 5 << 18 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 6 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 15 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 6 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 10 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 6 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 2 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 17 << 7 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 18 << 7 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 1 << 3 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 2 << 6 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 2 << 3 << 7 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 3 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 5 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 5 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 6 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 10 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 9 << 12 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 4 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 10 << 12 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 10 << 4 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 13 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 14 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 11 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 12 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 4 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 9 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 9 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 4 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 0 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 12 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 12 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 2 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 2 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 16 << 18 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 19 << 8 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 19 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 13 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 14 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 10 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 5 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 18 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 9 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 9 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 11 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 11 << 1 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 14 << 1 << 3 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(30);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 14 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 13 << 14 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 13 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 15 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 17 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 5 << 18 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 6 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 16 << 5 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 5 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 6 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 14 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 15 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 10 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 5 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 3 << 5 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 2 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 2 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 5 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 5 << 7 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 6 << 7 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 13 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 14 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 12 << 4 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 12 << 2 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 9 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 10 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 7 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 7 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 1 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 0 << 6 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 2 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 2 << 10 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 2 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 12 << 8 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 12 << 4 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 14 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 7 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 7 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 14 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 14 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 3 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 2 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 1 << 7 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(44);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 16 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 18 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 12 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 12 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 17 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 9 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 3 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 8 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 3 << 8 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 2 << 3 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 7 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 0 << 10 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 0 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 0 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 19 << 10 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 19 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 7 << 16 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 7 << 8 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 12 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 4 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 9 << 6 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 9 << 2 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 17 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 17 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 1 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 1 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 4 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 18 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 15 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 15 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 3 << 8 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 8 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 3 << 8 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 19 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 19 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 11 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 11 << 1 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 4 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 19 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 11 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 11 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 2 << 4 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 4 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 19 << 10 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 19 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 17 << 8 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 17 << 4 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 19 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 19 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 0 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 0 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 7 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 12 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 14 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 12 << 2 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 8 << 6 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 8 << 2 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 4 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 2 << 5 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(53);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 5 << 18 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 6 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 15 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 16 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 6 << 2 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 6 << 1 << 11 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 5 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 3 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 4 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 14 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 12 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 4 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 7 << 2 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 7 << 1 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 8 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 0 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 2 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 20 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 20 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 14 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 15 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 5 << 10 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 10 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 5 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 5 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 14 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 2 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 12 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 4 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 3 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 2 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 4 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 10 << 9 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 16 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 15 << 8 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 4 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 5 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 6 << 20 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 2 << 20 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 5 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 5 << 2 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 16 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 17 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 17 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 17 << 15 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 5 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 0 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 1 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 7 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 3 << 7 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 6 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 6 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 6 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 8 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 9 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 9 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 19 << 8 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 19 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 3 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 15 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 5 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 9 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 9 << 3 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 1 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 12 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 0 << 6 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 10 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 0 << 5 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 2 << 9 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 3 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 6 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 4 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 5 << 2 << 1 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(51);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 2 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 3 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 10 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 4 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 4 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 4 << 4 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 5 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 1 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 10 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 17 << 11 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 18 << 11 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 16 << 20 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 16 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 4 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 4 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 3 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 6 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 2 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 14 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 7 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 18 << 7 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 1 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 3 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 3 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 9 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 9 << 3 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 9 << 1 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 8 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 1 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 3 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 18 << 16 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 19 << 16 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 3 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 1 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 18 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 9 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 2 << 12 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 2 << 6 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 4 << 6 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 3 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 3 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 0 << 8 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 3 << 12 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 3 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 7 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 7 << 3 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 4 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 6 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 6 << 6 << 13 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 6 << 2 << 13 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 12 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 12 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 9 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 12 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 2 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 2 << 1 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 2 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 11 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 2 << 12 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 6 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 14 << 16 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 14 << 8 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 19 << 10 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 19 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 14 << 10 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 15 << 10 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 12 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 12 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 2 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 5 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 5 << 1 << 2 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(44);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 13 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 14 << 6 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 13 << 5 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 14 << 5 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 2 << 1 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 11 << 1 << 9 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 7 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 7 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 15 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 9 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 12 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 13 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 1 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 14 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 15 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 9 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 10 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 8 << 1 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 14 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 8 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 4 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 4 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 4 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 5 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 2 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 8 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 15 << 20 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 10 << 15 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 11 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 11 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 13 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 16 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 16 << 13 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 13 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 1 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 8 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 7 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 7 << 2 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 14 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 7 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 4 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 4 << 4 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 5 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 2 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 2 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 11 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 12 << 6 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 5 << 1 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 1 << 1 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 13 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 14 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 12 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 6 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 10 << 2 << 2 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(72);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 8 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 5 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 13 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 6 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 5 << 1 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 6 << 13 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 2 << 13 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 8 << 1 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 13 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 18 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 18 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 7 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 7 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 11 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 12 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 6 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 6 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 15 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 15 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 17 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 18 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 11 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 11 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 7 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 9 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 10 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 5 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 5 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 18 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 3 << 4 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 3 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 3 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 1 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 7 << 7 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 7 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 3 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 3 << 5 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 4 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 5 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 12 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 10 << 4 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 5 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 3 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 7 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 6 << 15 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 2 << 15 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 1 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 1 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 2 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 8 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 4 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 6 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 8 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 6 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 3 << 6 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 1 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 3 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 4 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 9 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 6 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 6 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 18 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 19 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 1 << 6 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 2 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 6 << 2 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 6 << 1 << 4 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 11 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 11 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 13 << 20 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 13 << 10 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 13 << 16 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 13 << 8 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 4 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 4 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 6 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 4 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 2 << 6 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 6 << 2 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 15 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 15 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 12 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 12 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 4 << 2 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 4 << 1 << 7 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 11 << 1 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 2 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 3 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 18 << 20 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 9 << 10 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 9 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 11 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 12 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 10 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 10 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 12 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 4 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 4 << 3 << 6 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(66);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 9 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 9 << 3 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 5 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 2 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 11 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 11 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 4 << 2 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 1 << 14 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 6 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 4 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 4 << 1 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 20 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 20 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 16 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 19 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 9 << 15 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 3 << 15 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 5 << 3 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 5 << 1 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 15 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 5 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 6 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 6 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 18 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 6 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 7 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 7 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 5 << 7 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 7 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 1 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 1 << 1 << 5 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 6 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 4 << 1 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 8 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 17 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 0 << 1 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 6 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 12 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 4 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 4 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 0 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 4 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 5 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 5 << 1 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 4 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 5 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 1 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 3 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 12 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 9 << 4 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 14 << 15 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 16 << 15 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 3 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 4 << 1 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 1 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 10 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 3 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 9 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 3 << 6 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 1 << 5 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 15 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 16 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 16 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 2 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 2 << 1 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 7 << 1 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 9 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 11 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 11 << 3 << 4 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 3 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 12 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 12 << 2 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 15 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 3 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 3 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 10 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 10 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 7 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 13 << 7 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 10 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 5 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 4 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 2 << 4 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 11 << 2 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 6 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 6 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 2 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 6 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 1 << 6 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(69);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 4 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 4 << 1 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 3 << 1 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 18 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 6 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 0 << 10 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 0 << 5 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 3 << 5 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 2 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 7 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 19 << 15 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 19 << 5 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 13 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 14 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 12 << 8 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 12 << 4 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 14 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 2 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 0 << 2 << 17 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 0 << 1 << 17 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 10 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 11 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 1 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 12 << 9 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 12 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 6 << 1 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 9 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 4 << 6 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 2 << 14 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 5 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 5 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 7 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 9 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 6 << 2 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 1 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 4 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 4 << 3 << 8 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 2 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 11 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 7 << 5 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 5 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 7 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 2 << 7 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 2 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 3 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 10 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 7 << 5 << 11 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 19 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 19 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 12 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 12 << 12 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 12 << 4 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 13 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 14 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 14 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 15 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 14 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 15 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 12 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 10 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 10 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 11 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 4 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 5 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 12 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 11 << 13 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 13 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 3 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 1 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 4 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 8 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 14 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 7 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 19 << 7 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 7 << 1 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 11 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 5 << 10 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 10 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 14 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 16 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 12 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 4 << 14 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 1 << 6 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 1 << 2 << 14 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 17 << 2 << 1 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(59);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 2 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 9 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 5 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 6 << 6 << 13 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 6 << 2 << 13 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 9 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 7 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 16 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 8 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 8 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 2 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 19 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 6 << 6 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 2 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 8 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 4 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 8 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 0 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 8 << 16 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 4 << 8 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 10 << 4 << 8 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 1 << 5 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 15 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 11 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 12 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 3 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 1 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 0 << 6 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 3 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 11 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 6 << 11 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 6 << 6 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 6 << 2 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 0 << 3 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 0 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 7 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 8 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 3 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 0 << 1 << 9 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 7 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 14 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 7 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 7 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 1 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 15 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 5 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 4 << 6 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 4 << 2 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 16 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 9 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 9 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 1 << 5 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 11 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 11 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 15 << 4 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 15 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 6 << 20 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 2 << 20 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 12 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 15 << 7 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 7 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 1 << 3 << 16 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 1 << 1 << 16 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 16 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 16 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 14 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 15 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 16 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 4 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 1 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 1 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 3 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 9 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 7 << 9 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 1 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 1 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 11 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 6 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 6 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 11 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 11 << 1 << 1 << 2;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(88);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 11 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 11 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 10 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 10 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 11 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 6 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 13 << 6 << 7 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 7 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 7 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 11 << 12 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 11 << 4 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 5 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 6 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 7 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 4 << 4 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 4 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 3 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 3 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 18 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 10 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 2 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 11 << 9 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 11 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 11 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 13 << 11 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 2 << 3 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 2 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 7 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 11 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 11 << 1 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 14 << 1 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 5 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 5 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 1 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 15 << 13 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 7 << 5 << 13 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 9 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 12 << 9 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 3 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 1 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 2 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 2 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 3 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 1 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 1 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 8 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 8 << 2 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 8 << 1 << 6 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 14 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 1 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 3 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 3 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 9 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 1 << 3 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 13 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 15 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 14 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 15 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 12 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 15 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 2 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 13 << 5 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 15 << 5 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 17 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 19 << 4 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 19 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 16 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 2 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 8 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 9 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 9 << 1 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 11 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 8 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 3 << 4 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 4 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 1 << 8 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 8 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 4 << 9 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 18 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 1 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 8 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 13 << 1 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 15 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 8 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 9 << 17 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 3 << 17 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 9 << 6 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 9 << 2 << 8 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 8 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 1 << 8 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 6 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 6 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 8 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 4 << 2 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 4 << 1 << 4 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 8 << 1 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 1 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 9 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 3 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 2 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 9 << 15 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 10 << 15 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 16 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 10 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 5 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 17 << 5 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 17 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 15 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 15 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 17 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 5 << 15 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 5 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 13 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 14 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 13 << 7 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 14 << 7 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 12 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 13 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 19 << 18 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 19 << 6 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 17 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 3 << 1 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 9 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 11 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 4 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 6 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 2 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 7 << 3 << 2 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(58);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 11 << 9 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 11 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 10 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 2 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 10 << 1 << 5 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 15 << 1 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 3 << 3 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 3 << 1 << 12 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 3 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 3 << 2 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 6 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 8 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 8 << 1 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 14 << 2 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 16 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 1 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 1 << 1 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 4 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 2 << 2 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 12 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 17 << 4 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 16 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 16 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 6 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 3 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 12 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 5 << 12 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 14 << 20 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 7 << 10 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 10 << 7 << 10 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 8 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 9 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 4 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 5 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 4 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 5 << 1 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 7 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 2 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 4 << 8 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 4 << 4 << 4 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 4 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 2 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 2 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 3 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 8 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 0 << 4 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 3 << 4 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 3 << 4 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 4 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 0 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 1 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 7 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 2 << 7 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 6 << 12 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 4 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 16 << 9 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 16 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 15 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 15 << 2 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 15 << 12 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 15 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 15 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 13 << 3 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 14 << 3 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 14 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 7 << 8 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 12 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 0 << 4 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 0 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 2 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 1 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 2 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 2 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 3 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 1 << 2 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 1 << 1 << 14 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 7 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 1 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 1 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 17 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 17 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 6 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 10 << 2 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 17 << 2 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 5 << 2 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 10 << 2 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 12 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 13 << 6 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 2 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 15 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 5 << 3 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 5 << 1 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 5 << 7 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 7 << 1 << 3;
		}
	}
	{
		ComplexCascadeClassifier& sc = *sc_iter++;
		sc.classifiers.SetCount(93);
		auto cf_iter = sc.classifiers.Begin();
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 9 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 9 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 7 << 8 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 11 << 8 << 4 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 9 << 1 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 12 << 1 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 11 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 11 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 6 << 6 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 2 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 18 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 12 << 12 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 12 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 17 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 18 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 17 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 17 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 1 << 14 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 3 << 14 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 2 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 8 << 2 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 13 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 14 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 1 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 1 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 6 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 6 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 19 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 16 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 17 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 11 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 11 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 5 << 1 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 8 << 1 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 8 << 4 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 9 << 4 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 4 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 8 << 2 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 10 << 2 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 6 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 3 << 2 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 7 << 3 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 3 << 8 << 16 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 3 << 4 << 8 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 11 << 4 << 8 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 2 << 8 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 4 << 11 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 3 << 6 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 3 << 3 << 14 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 18 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 6 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 14 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 11 << 14 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 9 << 9 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 9 << 3 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 5 << 2 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 7 << 3 << 7 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 7 << 1 << 7 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 8 << 11 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 10 << 11 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 9 << 6 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 6 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 3 << 3 << 11 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 3 << 1 << 11 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 6 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 19 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 12 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 6 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 3 << 6 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 5 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 6 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 8 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 8 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 11 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 11 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 6 << 15 << 13 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 5 << 13 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 3 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 3 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 18 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 8 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 8 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 0 << 6 << 19 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 0 << 2 << 19 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 1 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 1 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 14 << 3 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 3 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 13 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 13 << 1 << 6 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 14 << 9 << 4 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 14 << 3 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 8 << 2 << 3 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 11 << 2 << 3 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 16 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 0 << 3 << 14 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 0 << 1 << 14 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 0 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 9 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 9 << 3 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 5 << 4 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 5 << 2 << 9 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 0 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 0 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 15 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 15 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 16 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 2 << 2 << 18 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 11 << 2 << 9 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 4 << 8 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 9 << 8 << 5 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 3 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 4 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 1 << 6 << 9 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 4 << 6 << 3 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 4 << 5 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 6 << 5 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 18 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 19 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 19 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 10 << 6 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 10 << 2 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 2 << 6 << 5 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 2 << 2 << 5 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 5 << 2 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 15 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 15 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 17 << 1 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 14 << 4 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 16 << 4 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 7 << 3 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 7 << 1 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 9 << 3 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 10 << 3 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 2 << 1 << 12 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 6 << 1 << 4 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 0 << 15 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 5 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 8 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 9 << 0 << 4 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 1 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 12 << 2 << 8 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 2 << 4 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 1 << 10 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 3 << 10 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 6 << 2 << 3 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 7 << 2 << 1 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(3);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 12 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 4 << 12 << 1 << 1 << 2;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 5 << 13 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 6 << 6 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 8 << 6 << 2 << 2 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 0 << 9 << 9 << 6 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 3 << 9 << 3 << 6 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 18 << 2 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 18 << 18 << 1 << 2 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 11 << 2 << 6 << 16 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 13 << 2 << 2 << 16 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 4 << 15 << 13 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 4 << 5 << 13 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 16 << 2 << 3 << 10 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 17 << 2 << 1 << 10 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 6 << 10 << 2 << 1 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 7 << 10 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 1 << 1 << 18 << 16 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 10 << 1 << 9 << 16 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 14 << 4 << 3 << 15 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 15 << 4 << 1 << 15 << 3;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 13 << 1 << 2 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 19 << 14 << 1 << 1 << 2;
		}
		{
			SimpleCascadeClassifier& cf = *cf_iter++;
			cf.threshold = 2.78100360429512e180;
			cf.left_val = 2.78100360429512e180;
			cf.right_val = 2.78100360429512e180;
			cf.features.SetCount(2);
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 6 << 5 << 8 << -1;
			Vector<int>& v = cf.features[i];
			v.Reserve(5);
			v  << 2 << 10 << 5 << 4 << 2;
		}
	}
}

NAMESPACE_TOPSIDE_END

