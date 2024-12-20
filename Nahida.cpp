#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Point3{
	double x, y, z;
	Point3(double x = 0, double y = 0, double z = 0)
		:x(x), y(y), z(z){}
	Point3 operator + (const Point3& m)const{
		return Point3(x + m.x, y + m.y, z + m.z);
	}
	Point3 operator - (const Point3& m)const{
		return Point3(x - m.x, y - m.y, z - m.z);
	}
	Point3 operator * (const double& m)const{
		return Point3(x * m, y * m, z * m);
	}
	Point3 operator * (const Point3& m)const{
		return Point3(x * m.x, y * m.y, z * m.z);
	}
	Point3 operator / (const double& m)const{
		return Point3(x / m, y / m, z / m);
	}
	double len(){
		return sqrt(x * x + y * y + z * z);
	}
	double len2(){
		return x * x + y * y + z * z;
	}
	Point3 normal(){
		double l = len();
		return Point3(x / l, y / l, z / l);
	}
	bool operator == (const Point3& p)const{
		return x == p.x && y == p.y && z == p.z;
	}
};
typedef Point3 Color;
int dcmp(double x){
	return (fabs(x) <= 1e-6) ? 0 : (x > 0 ? 1 : -1);
}
struct Triangle{
	Point3 a, b, c;
	Triangle(Point3 a = Point3(), Point3 b = Point3(), Point3 c = Point3())
		:a(a), b(b), c(c){}
	bool operator == (const Triangle& t)const{
		return a == t.a && b == t.b && c == t.c;
	}
};
struct Ray{
	Point3 s, d;
	Ray(Point3 s = Point3(), Point3 d = Point3())
		:s(s), d(d){}
	Point3 at(const double& D)const{
		return s + d * D;
	}
};

Point3 planeNormal(const Point3& a, const Point3& b, const Point3& c){
	double na = (b.y - a.y)*(c.z - a.z) - (b.z - a.z)*(c.y - a.y);
	double nb = (b.z - a.z)*(c.x - a.x) - (b.x - a.x)*(c.z - a.z);
	double nc = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	return Point3(na, nb, nc);
}
double Dot(const Point3& x, const Point3& y){
	return x.x * y.x + x.y * y.y + x.z * y.z;
}
Point3 Cross(const Point3& x, const Point3& y){
	return Point3(x.y * y.z - x.z * y.y, x.z * y.x - x.x * y.z, x.x * y.y - x.y * y.x);
}
double Area2(const Point3& x, const Point3& y, const Point3& z){
	return Cross(y-x, z-x).len();
}
bool PointInTriangle(const Point3& p, const Triangle& t){
	double a = Area2(p, t.a, t.b);
	double b = Area2(p, t.b, t.c);
	double c = Area2(p, t.a, t.c);
	return dcmp(a + b + c - Area2(t.a, t.b, t.c)) == 0;
}
bool TriangleIntersectionSeg(const Triangle& t, const Point3& a, const Point3& b){
	Point3 n = Cross(t.b - t.a, t.c - t.a);
	if(dcmp(Dot(n, b - a)) == 0)
		return false;
	double T = Dot(n, t.a - a) / Dot(n, b - a);
	if(dcmp(T) <= 0 || dcmp(T-1) >= 0)
		return false;
	Point3 p = a + (b - a) * T;
	return PointInTriangle(p, t);
}
bool TriangleIntersectionRay(const Triangle& t, const Ray& r, Point3& p){
	Point3 n = Cross(t.b - t.a, t.c - t .a);
	if(dcmp(Dot(n, r.d)) == 0)
		return false;
	double T = Dot(n, t.a - r.s) / Dot(n, r.d);
	if(dcmp(T) <= 0)
		return false;
	p = r.at(T);
	return PointInTriangle(p, t);
}


istream & operator>> (istream &in, Point3 &A){
    in >> A.x >> A.y >> A.z;
    return in;
}

int N;
struct Object{
	vector<Triangle> triangleList;
	Color color;
	double refl, refr;
	double medIdx;
};
vector<Object> Scene;
struct Light{
	Point3 location;
	Color color;
	double ambient;
}L;
struct Camera{
	Point3 pos, targ, up;
	double ang;
	int W, H;
	Ray forw;
}Cam;

char toHex(int x){
	return x < 10 ? (x + '0') : (x + 'a' - 10);
}
string RGBTransfer(double d){
	int x = (int)floor(d * 255 + 0.5);
	return string() + toHex(x / 16) + toHex(x % 16);
}

string formatColor(Color& color){
	return RGBTransfer(color.x) + RGBTransfer(color.y) + RGBTransfer(color.z);
}

const int MAX_TRACE_DEPTH = 4;

int getFirstIntersection(Ray r, Point3& p, Triangle& t){
	int mn = -1;
	double len = -1;
	Point3 P;
	for(int id=0; id<(int)Scene.size(); id++){
		for(Triangle& tri: Scene[id].triangleList)
			if(TriangleIntersectionRay(tri, r, P)){
				double l = (P - r.s).len2();
				if(len < 0 || len > l)
					len = l, mn = id, t = tri, p = P;
			}
	}
	return mn;
}

bool isShadowed(Point3 p){
	Triangle T; Point3 P;
	if(getFirstIntersection(Ray(p, (L.location - p).normal()), P, T) == -1)
		return false;
	return (P - p).len2() < (L.location - p).len2();
}
double getPointColor(Point3& p, Point3 dir){
	double shade = 0;
	if(!isShadowed(p))
		shade = fabs(Dot((L.location - p).normal(), dir.normal()));
	return L.ambient + (1 - L.ambient) * shade;
}
bool getRefractedRay(Ray& r, int idx, Triangle& t, bool inObj, Point3& re){
	if(Scene[idx].medIdx == 0)
		return false;
	Point3 norm = planeNormal(t.a, t.b, t.c);
	Point3 i = r.d;
	if(dcmp(Dot(i, norm)) == 1)
		norm = norm * -1;
	norm = norm.normal();
	double ri = Scene[idx].medIdx;
	if(!inObj)
		ri = 1.0 / ri;
	double idotn = Dot(i, norm);
	double k = 1.0 - ri * ri * (1 - idotn * idotn);
	double a = 0;
	if(k < 0)
		return false;
	a = ri * idotn + sqrt(k);
	re = (i * ri - norm * a);
	return true;
}
bool getReflectedRay(Ray& r, int idx, Triangle& t, Point3& re){
	Point3 norm = planeNormal(t.a, t.b, t.c);
    if(dcmp(Dot(r.d, norm)) == 1)
        norm = norm * -1;
    norm = norm.normal();
    re = (r.d - norm * Dot(r.d, norm) * 2);
    return true;
}


Color traceLight(Ray r, int dep, bool inObj = false){
	if(dep == MAX_TRACE_DEPTH + 1)
		return Color();
	Color pointColor, reflColor, refrColor;
	Point3 p; Triangle t;
	int idx = getFirstIntersection(r, p, t);
	if(idx != -1){
		double refl = Scene[idx].refl
			 , refr = Scene[idx].refr;
		pointColor = Scene[idx].color * L.color * (1 - refl - refr)
				   * getPointColor(p, planeNormal(t.a, t.b, t.c));
		Point3 re;
		if(getReflectedRay(r, idx, t, re))
			reflColor = traceLight(Ray(p, re), dep+1, inObj) * refl;
		if(getRefractedRay(r, idx, t, inObj, re))
			refrColor = traceLight(Ray(p, re), dep+1, !inObj) * refr;
	}
	return pointColor + reflColor + refrColor;
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	vector<Point3> pl;
	freopen("out2jpg.txt", "w", stdout);
    while(cin >> N && N != 0){
    	Scene.clear();
    	for(int i=1; i<=N; i++){
    		Object nO;
    		int l; cin >> l;
    		pl.clear();
    		Point3 x;
    		while(l--){
    			cin >> x;
    			pl.push_back(x);
    		}
    		cin >> l;
    		int a, b, c;
    		while(l--){
    			cin >> a >> b >> c;
    			nO.triangleList.push_back(Triangle(pl[a], pl[b], pl[c]));
    		}
    		cin >> nO.color >> nO.refl >> nO.refr >> nO.medIdx;
    		Scene.push_back(nO);
    	}
    	cin >> L.location >> L.ambient >> L.color;
    	int q; cin >> q;
    	while(q--){
    		cin >> Cam.pos >> Cam.targ >> Cam.up >> Cam.ang >> Cam.W >> Cam.H;
    		printf("%d %d\n", Cam.W, Cam.H);
    		Cam.ang = Cam.ang * 3.14159265 / 180;
    		Cam.forw = Ray(Cam.pos, (Cam.targ - Cam.pos).normal());
    		double dis = Cam.W / 2.0 / tan(Cam.ang / 2);
    		Point3 cent = Cam.forw.at(dis);
    		Point3 dwn = Cam.up * -1;
    		Point3 rig = planeNormal(cent, cent + Cam.forw.d, cent + dwn).normal() * -1;
    		for(int x=0; x<Cam.H; x++){
    			for(int y=0; y<Cam.W; y++){
    				Point3 curr = cent + dwn * (x - Cam.H / 2.0 + 0.5) + rig * (y - Cam.W / 2.0 + 0.5);
    				Color color = traceLight(Ray(Cam.pos, (curr - Cam.pos).normal()), 0);
    				printf("%s ", formatColor(color).c_str());
    			}
    			printf("\n");
    		}
    	}
    }
	return 0;
}