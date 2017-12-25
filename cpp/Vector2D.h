#include<vector>
using namespace std;
class Vector2D {
private:
	vector<int> v;
	int i = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
		for (auto a : vec2d) {
			v.insert(v.end(), a.begin(), a.end());
		}
    }

    int next() {
		return v[i++];
    }

    bool hasNext() {
		return i < v.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
