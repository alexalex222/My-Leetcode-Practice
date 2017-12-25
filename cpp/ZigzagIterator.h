#include<vector>
#include<queue>
using namespace std;
class ZigzagIterator {
private:
	vector<queue<int>> v;
	queue<int> q1;
	queue<int> q2;
	int p;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		for(int i : v1) q1.push(i);
		for(int i : v2) q2.push(i);
		v.push_back(q1);
		v.push_back(q2);
		p = 0;
    }

    int next() {
		while(v[p].empty()) {
			p = (p+1)%(static_cast<int>(v.size()));
		}
		int result = v[p].front();
		v[p].pop();
		p = (p+1)%(static_cast<int>(v.size()));
		return result;
		
    }

    bool hasNext() {
		for(queue<int> t : v) {
			if(!t.empty()) return true;
		}
		return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
