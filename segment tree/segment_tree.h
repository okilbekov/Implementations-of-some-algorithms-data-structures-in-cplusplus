#include <iostream>
#include <vector>

using namespace std;

struct Item {
	int64_t sum;
};

class SegTree {
public:
	SegTree(const vector<int>& data) {
		build(data);
	}

	void build(const vector<int>& data) {
		num_of_elements = data.size();
		for(adjusted_size = 1; adjusted_size < data.size(); adjusted_size *= 2);
		tree.assign(2 * adjusted_size, blank);
		_build(data, 0, 0, adjusted_size);
	}

	void update(int idx, int val) {
		_update(idx, val, 0, 0, adjusted_size);
	}

	Item get(int l, int r) { // [l, r)
		return _get(l, r, 0, 0, adjusted_size);
	}
private:
	vector<Item> tree;
	Item blank = {0};
	int adjusted_size, num_of_elements;

	Item merge(const Item& lhs, const Item& rhs) {
		Item res = {lhs.sum + rhs.sum};
		return res;
	}

	void _build(const vector<int>& data, int x, int l, int r) {
		if(r - l == 1) {
			if(l < num_of_elements)
				tree[x] = {data[l]};
			else
				tree[x] = blank;
		}
		else {
			int m = (r + l) / 2;
			_build(data, 2 * x + 1, l, m);
			_build(data, 2 * x + 2, m, r);
			tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
		}
	}

	void _update(int idx, int val, int x, int lx, int rx) {
		if(rx - lx == 1)
			tree[x] = {val};
		else {
			int m = (lx + rx) / 2;
			if(idx < m)
				_update(idx, val, 2 * x + 1, lx, m);
			else
				_update(idx, val, 2 * x + 2, m, rx);
			tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
		}
	}

	Item _get(int l, int r, int x, int lx, int rx) {
		if(lx >= l && rx <= r)
			return tree[x];
		if(lx >= r || rx <= l)
			return blank;
		int m = (lx + rx) / 2;
		Item lhs = _get(l, r, 2 * x + 1, lx, m);
		Item rhs = _get(l, r, 2 * x + 2, m, rx);
		return merge(lhs, rhs);
	}
};