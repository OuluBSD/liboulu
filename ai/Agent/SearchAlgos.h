#ifndef _Agent_SearchAlgos_h_
#define _Agent_SearchAlgos_h_


NAMESPACE_OULU_BEGIN

template <class T>	inline double GetSearcherUtility(Node<T>& n) {return n.T::GetUtility();}
template <>			inline double GetSearcherUtility<Object>(NodeValue& n) {
	Object& o = n.GetData();
	ObjectArray& arr = o.GetArray();
	ASSERT(arr.GetCount());
	Object& ov = arr[1];
	double value = ov.ToDouble();
	return value;
}
template <class T>	inline double GetSearcherEstimate(Node<T>& n) {return n.T::GetEstimate();}
template <class T>	inline double GetSearcherDistance(Node<T>& n, Node<T>& dest) {return n.T::GetDistance(dest);}
template <class T>	inline bool TerminalTest(Node<T>& n) {return n.GetTotalCount() == 0;}



template <class T>
class Searcher {
	
public:
	typedef Node<T> NodeT;
	
	Searcher() {}
	
	inline bool TerminalTest(NodeT& n) {return Oulu::TerminalTest(n);}
	inline double Utility(NodeT& n) {return Oulu::GetSearcherUtility(n);}
	inline double Estimate(NodeT& n) {return Oulu::GetSearcherEstimate(n);}
	inline double Distance(NodeT& n, NodeT& dest) {return Oulu::GetSearcherDistance(n, dest);}
	
	virtual Vector<T*> Search(NodeT& src) = 0;
	
	
};


template <class T>
class MiniMax : public Searcher<T> {
	typedef Node<T> NodeT;
	
public:
	MiniMax() {}
	
	double MaxValue(NodeT& n, int* decision_pos=0) {
		if (TerminalTest(n))
			return this->Utility(n);
		double v = -DBL_MAX;
		int pos = -1;
		for(int i = 0; i < n.GetTotalCount(); i++) {
			// Find minimum...
			double d = MinValue(n.AtTotal(i));
			// ..but use maximum
			if (d > v) {
				v = d;
				pos = i;
			}
		}
		if (decision_pos) *decision_pos = pos;
		return v;
	}
	
	double MinValue(NodeT& n, int* decision_pos=0) {
		if (TerminalTest(n))
			return Searcher<T>::Utility(n);
		double v = DBL_MAX;
		int pos = -1;
		for(int i = 0; i < n.GetTotalCount(); i++) {
			double d = MaxValue(n.AtTotal(i));
			if (d < v) {
				v = d;
				pos = i;
			}
		}
		if (decision_pos) *decision_pos = pos;
		return v;
	}
	
	virtual Vector<T*> Search(NodeT& src) {
		Vector<T*> out;
		NodeT* ptr = &src;
		while (1) {
			T& t = *out.Add((T*)ptr);
			if (TerminalTest(*ptr)) break;
			int type = out.GetCount() % 2;
			int pos = -1;
			double v;
			if (type == 1)
				v = MinValue(*ptr, &pos);
			else
				v = MaxValue(*ptr, &pos);
			if (pos == -1) break;
			ptr = &(*ptr).AtTotal(pos);
			//LOG(pos << " " << v);
		}
		return out;
	}
};


template <class T>
class AlphaBeta : public Searcher<T> {
	typedef Node<T> NodeT;
	
public:
	AlphaBeta() {}
	
	
	double MaxValue(NodeT& n, double alpha, double beta, int* decision_pos=0) {
		if (TerminalTest(n))
			return this->Utility(n);
		int pos = -1;
		double v = -DBL_MAX;
		for(int i = 0; i < n.GetTotalCount(); i++) {
			// Find minimum...
			double d = MinValue(n.AtTotal(i), alpha, beta);
			// ..but use maximum
			if (d > v) {
				v = d;
				pos = i;
			}
			if (v > alpha)
				alpha = v;
			if (beta <= alpha)
				break;
		}
		if (decision_pos) *decision_pos = pos;
		return v;
	}
	
	double MinValue(NodeT& n, double alpha, double beta, int* decision_pos=0) {
		if (TerminalTest(n))
			return this->Utility(n);
		int pos = -1;
		double v = DBL_MAX;
		for(int i = 0; i < n.GetTotalCount(); i++) {
			double d = MaxValue(n.AtTotal(i), alpha, beta);
			if (d < v) {
				v = d;
				pos = i;
			}
			if (v < beta)
				beta = v;
			if (beta <= alpha)
				break;
		}
		if (decision_pos) *decision_pos = pos;
		return v;
	}
	
	virtual Vector<T*> Search(NodeT& src) {
		Vector<T*> out;
		NodeT* ptr = &src;
		while (1) {
			T& t = *out.Add((T*)ptr);
			if (TerminalTest(*ptr)) break;
			int type = out.GetCount() % 2;
			int pos = -1;
			double v;
			double alpha = -DBL_MAX;
			double beta = DBL_MAX;
			if (type == 1)
				v = MinValue(*ptr, alpha, beta, &pos);
			else
				v = MaxValue(*ptr, alpha, beta, &pos);
			if (pos == -1) break;
			ptr = &(*ptr).AtTotal(pos);
		}
		return out;
	}
};


// UNINFORMED SEARCH STRATEGIES

template <class T>
class BreadthFirst : public Searcher<T> {
	typedef Node<T> NodeT;
	
public:
	BreadthFirst() {}
	
	virtual Vector<T*> Search(NodeT& src) {
		Vector<T*> out;
		Vector<NodeT*> queue, next_queue;
		next_queue.Add(&src);
		double v = DBL_MAX;
		NodeT* ptr = 0;
		while (1) {
			queue <<= next_queue;
			next_queue.Clear();
			
			bool all_terminals = true;
			for(int i = 0; i < queue.GetCount(); i++) {
				NodeT& t = *queue[i];
				
				if (TerminalTest(t)) {
					ptr = &t;
					all_terminals = true;
					break;
				}
				else all_terminals = false;
				
				for(int j = 0; j < t.GetCount(); j++) {
					next_queue.Add(&t.AtTotal(j));
				}
			}
			if (all_terminals) break;
		}
		
		while (ptr) {
			out.Insert(0, ptr);
			ptr = ptr->GetParent();
		}
		return out;
	}
};


template <class T>
class UniformCost : public Searcher<T> {
	typedef Node<T> NodeT;
	
public:
	UniformCost() {}
	
	virtual Vector<T*> Search(NodeT& src) {
		Vector<T*> out;
		Vector<NodeT*> frontier;
		frontier.Add(&src);
		double v = DBL_MAX;
		NodeT* ptr = 0;
		
		
		for(; frontier.GetCount();) {
			bool all_terminals = true;
			NodeT& t = *frontier[0];
			if (TerminalTest(t)) {
				ptr = &t;
				all_terminals = true;
				break;
			}
			else all_terminals = false;
			
			frontier.Remove(0);
			
			//TODO: change this to search like in AStar, because it is faster than insert, which moves huge block of memory always. Or do something completely different and better.
			for(int j = 0; j < t.GetTotalCount(); j++) {
				NodeT& sub = t.AtTotal(j);
				double utility = this->Utility(sub);
				bool inserted = false;
				for(int k = 0; k < frontier.GetCount(); k++) {
					double f_utility = this->Utility(*frontier[k]);
					if (utility <= f_utility) {
						frontier.Insert(k, &sub);
						inserted = true;
						break;
					}
				}
				// Worst utility
				if (!inserted) {
					frontier.Add(&sub);
				}
			}
			if (all_terminals) break;
		}
		
		while (ptr) {
			out.Insert(0, ptr);
			ptr = ptr->GetParent();
		}
		return out;
	}
};

template <class T>
class DepthFirst : public Searcher<T> {
	typedef Node<T> NodeT;
	
public:
	DepthFirst() {}
	
	virtual Vector<T*> Search(NodeT& src) {
		Vector<T*> out;
		
		typename NodeT::IteratorDeep it = src.BeginDeep();
		NodeT* ptr = 0;
		double v = DBL_MAX;
		
		while (!it.IsEnd()) {
			if (TerminalTest(*it)) {
				ptr = it;
				break;
			}
			it++;
		}
		
		while (ptr) {
			out.Insert(0, ptr);
			ptr = ptr->GetParent();
		}
		
		return out;
	}
};

template <class T>
class DepthLimited : public Searcher<T> {
	typedef Node<T> NodeT;
	int limit;
public:
	DepthLimited() : limit(-1) {}
	
	void SetLimit(int lim) {limit = lim;}
	
	virtual Vector<T*> Search(NodeT& src) {
		Vector<T*> out;
		
		typename NodeT::IteratorDeep it = src.BeginDeep();
		NodeT* ptr = 0;
		double v = DBL_MAX;
		
		while (!it.IsEnd()) {
			if (TerminalTest(*it)) {
				ptr = it;
				break;
			}
			int depth = it.GetDepth();
			if (depth >= limit)
				it.IncNotDeep();
			else
				it++;
		}
		
		while (ptr) {
			out.Insert(0, ptr);
			ptr = ptr->GetParent();
		}
		
		return out;
	}
};




// INFORMED (HEURISTIC) SEARCH STRATEGIES


template <class T>
class BestFirst : public Searcher<T> {
	typedef Node<T> NodeT;
	
public:
	BestFirst() {}
	
	virtual Vector<T*> Search(NodeT& src) {
		Vector<T*> out;
		NodeT* ptr = &src;
		while (1) {
			out.Add((T*)ptr);
			NodeT& t = *ptr;
			if (TerminalTest(*ptr))
				break;
			int pos = -1;
			double v = DBL_MAX;
			for(int i = 0; i < t.GetTotalCount(); i++) {
				NodeT& sub = t.AtTotal(i);
				double estimate = this->Estimate(sub);
				if (estimate < v) {
					v = estimate;
					pos = i;
					if (v <= 0)
						break;
				}
			}
			if (pos == -1)
				break;
			ptr = &(*ptr).AtTotal(pos);
		}
		return out;
	}
};


    
template <class T>
class AStar : public Searcher<T> {
	typedef Node<T> NodeT;
	
	struct NodePtr : public Moveable<NodePtr> {
		NodeT* ptr;
		NodePtr() : ptr(0), g_score(0), f_score(0), came_from(0) {g_score = DBL_MAX; f_score = DBL_MAX;}
		NodePtr(NodeT* ptr) : ptr(ptr), g_score(0), f_score(0), came_from(0) {g_score = DBL_MAX; f_score = DBL_MAX;}
		NodePtr(const NodePtr& src) : ptr(src.ptr), g_score(src.g_score), f_score(src.f_score), came_from(src.came_from) {}
		long GetHashValue() const {return (long)ptr;}
		bool operator == (const NodePtr& np) const {return np.ptr == ptr;}
		// For each node, the cost of getting from the start node to that node.
		double g_score;
		// For each node, the total cost of getting from the start node to the goal
		// by passing by that node. That value is partly known, partly heuristic.
		double f_score;
		// For each node, which node it can most efficiently be reached from.
		// If a node can be reached from many nodes, cameFrom will eventually contain the
		// most efficient previous step.
		NodeT* came_from;
	};
	
	int max_worst;
	bool do_search;
	int limit;
public:
	AStar() : max_worst(0), limit(0) {}
	
	void SetLimit(int i) {limit = i;}
	void Stop() {do_search = false;}
	
	void TrimWorst(int count) {max_worst = count; ASSERT(count >= 0);}
	
	Vector<T*> ReconstructPath(NodeT& current, Index<NodePtr>& closed_set, Index<NodePtr>& open_set) {
		Vector<T*> path;
		NodeT* ptr = &current;
		while (1) {
			path.Add(ptr);
			NodePtr nptr(ptr);
			int i = open_set.Find(nptr);
			if (i == -1) {
				i = closed_set.Find(nptr);
				if (i == -1) break;
				else ptr = closed_set[i].came_from;
			}
			else ptr = open_set[i].came_from;
			if (!ptr) break;
		}
		Vector<T*> out;
		out.SetCount(path.GetCount());
		for(int i = 0; i < path.GetCount(); i++) {
			out[path.GetCount()-1-i] = path[i];
		}
		return out;
	}
	
	virtual Vector<T*> Search(NodeT& src) {
		do_search = true;
		
		// The set of nodes already evaluated.
		Index<NodePtr> closed_set;
		
		// The set of currently discovered nodes still to be evaluated.
		// Initially, only the start node is known.
		Index<NodePtr> open_set;
		
		// For the first node, that value is completely heuristic.
		NodePtr np(&src);
		np.g_score = 0;
		np.f_score = this->Estimate(src);
		open_set.Add(np);
		
		Vector<double> worst_f_score;
		Vector<int> worst_id;
		worst_f_score.SetCount(max_worst);
		worst_id.SetCount(max_worst);
		
		// while open_set is not empty
		for(; open_set.GetCount() && do_search;) {
			
			if (limit) {
				limit--;
				if (limit <= 0)
					do_search = 0;
			}
			
			double smallest_f_score = DBL_MAX;
			int smallest_id = -1;
			
			bool rm = open_set.GetCount() > 1000;
			
			if (rm) {
				for(int i = 0; i < max_worst; i++) {
					worst_f_score[i] = -DBL_MAX;
					worst_id[i] = -1;
				}
			}
			
			for(int i = 0; i < open_set.GetCount(); i++) {
				const NodePtr& nptr = open_set[i];
				double f_score = nptr.f_score;
				if (f_score < smallest_f_score) {
					smallest_f_score = f_score;
					smallest_id = i;
				}
				
				if (rm) for(int j = 0; j < max_worst; j++) {
					if (f_score > worst_f_score[j]) {
						for(int k = max_worst-1; k > j; k--) {
							worst_f_score[k] = worst_f_score[k-1];
							worst_id[k] = worst_id[k-1];
						}
						worst_f_score[j] = f_score;
						worst_id[j] = i;
						break;
					}
				}
			}
			
			if (rm) {
				int count = 0;
				Vector<int> rm_list;
				for(int i = 0; i < max_worst; i++) {
					int id = worst_id[i];
					if (id == -1) break;
					closed_set.Add(open_set[id]);
					rm_list.Add(id);
				}
				
				if (rm_list.GetCount()) {
					if (rm_list.GetCount() > 1) {
						Sort(rm_list, StdLess<int>());
					}
					open_set.Remove(rm_list);
				}
			}
			
			
			const NodePtr& t_ptr = open_set[smallest_id];
			NodeT& t = *t_ptr.ptr;
			double current_g_score = t_ptr.g_score;
			
			if (TerminalTest(t))
				return ReconstructPath(t, closed_set, open_set);
			
			if (!do_search)
				break;
			
			closed_set.Add(t_ptr);
			open_set.Remove(smallest_id);
			
			
			for(int j = 0; j < t.GetTotalCount(); j++) {
				NodeT& sub = t.AtTotal(j);
				NodePtr subptr(&sub);
				if (closed_set.Find(subptr) != -1)
					continue; // Ignore the neighbor which is already evaluated.
				// The distance from start to a neighbor
				double sub_g_score = current_g_score + this->Distance(t, sub);
				double sub_f_score = sub_g_score + this->Estimate(sub);
				int k = open_set.Find(subptr);
				if (k == -1) {
					// Discover a new node
					k = open_set.GetCount();
					subptr.came_from = &t;
					subptr.f_score = sub_f_score;
					subptr.g_score = sub_g_score;
					ASSERT(subptr.ptr);
				}
				else if (sub_g_score >= current_g_score)
					continue; // This is not a better path.
				else {
					subptr.came_from = &t;
					subptr.f_score = sub_f_score;
					subptr.g_score = sub_g_score;
					open_set.Remove(k);
					ASSERT(subptr.ptr);
				}
			}
		}
		return Vector<T*>();
	}
};

NAMESPACE_OULU_END


#endif
