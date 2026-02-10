#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define fastIO() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, q;
vector<vector<int>> g;
vector<vector<int>> tree;

void buildX(int nodeY, int startY, int endY, int nodeX, int startX, int endX) {
	if(startX == endX) {
		if(startY == endY) tree[nodeY][nodeX] = g[startY][startX];
		else tree[nodeY][nodeX] = tree[2 * nodeY][nodeX] + tree[2 * nodeY + 1][nodeX];
		return;
	}
	
	int mid = (startX + endX) / 2;
	buildX(nodeY, startY, endY, 2 * nodeX, startX, mid);
	buildX(nodeY, startY, endY, 2 * nodeX + 1, mid + 1, endX);
	tree[nodeY][nodeX] = tree[nodeY][2 * nodeX] + tree[nodeY][2 * nodeX + 1];
	
	return;
}

void buildY(int nodeY, int startY, int endY) {
	if(startY != endY) {
		int mid = (startY + endY) / 2;
		buildY(2 * nodeY, startY, mid);	
		buildY(2 * nodeY + 1, mid + 1, endY);
	}
	
	buildX(nodeY, startY, endY, 1, 0, n - 1);
	
	return;
}

void updateX(int nodeY, int startY, int endY, int nodeX, int startX, int endX, int y, int x, int val) {
	if(startX == endX) {
		if(startY == endY) tree[nodeY][nodeX] = val;
		else tree[nodeY][nodeX] = tree[2 * nodeY][nodeX] + tree[2 * nodeY + 1][nodeX];
		return;
	}
	
	int mid = (startX + endX) / 2;
	if(x <= mid) updateX(nodeY, startY, endY, 2 * nodeX, startX, mid, y, x, val);
	else updateX(nodeY, startY, endY, 2 * nodeX + 1, mid + 1, endX, y, x, val);
	tree[nodeY][nodeX] = tree[nodeY][2 * nodeX] + tree[nodeY][2 * nodeX + 1];
	
	return;
}

void updateY(int nodeY, int startY, int endY, int y, int x, int val) {
	if(startY != endY) {
		int mid = (startY + endY) / 2;
		if(y <= mid) updateY(2 * nodeY, startY, mid, y, x, val);
		else updateY(2 * nodeY + 1, mid + 1, endY, y, x, val);
	}

	updateX(nodeY, startY, endY, 1, 0, n - 1, y, x, val);

	return;
}

int queryX(int nodeX, int startX, int endX, int lX, int rX, int nodeY) {
	if(lX > endX || rX < startX) return 0;
	if(lX <= startX && endX <= rX) return tree[nodeY][nodeX];
	
	int mid = (startX + endX) / 2;
	int p1 = queryX(2 * nodeX, startX, mid, lX, rX, nodeY);
	int p2 = queryX(2 * nodeX + 1, mid + 1, endX, lX, rX, nodeY);
	
	return p1 + p2;
}

int queryY(int nodeY, int startY, int endY, int lY, int rY, int lX, int rX) {
	if(lY > endY || rY < startY) return 0;
	if(lY <= startY && endY <= rY) return queryX(1, 0, n - 1, lX, rX, nodeY);

	int mid = (startY + endY) / 2;
	int p1 = queryY(2 * nodeY, startY, mid, lY, rY, lX, rX);
	int p2 = queryY(2 * nodeY + 1, mid + 1, endY, lY, rY, lX, rX);
	
	return p1 + p2;
}

signed main() {
	fastIO();

    cin >> n >> q;
    
	g.resize(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> g[i][j];
	}
	
	tree.resize(4 * n + 1, vi(4 * n + 1, -1));
	buildY(1, 0, n - 1);
    
    while(q--) {
		int qx;
		cin >> qx;

		if(qx == 1) {
			int x, y, z;
			cin >> x >> y >> z;
			updateY(1, 0, n - 1, x - 1, y - 1, z);
		}
		else {
			int x, y, r, s;
			cin >> x >> y >> r >> s;
			x--; y--; r--; s--;
			int ans = queryY(1, 0, n - 1, min(x, r), max(x, r), min(y, s), max(y, s));
			cout << ans << endl;
		}
	}
 
    return 0;
}