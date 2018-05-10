#include <bits/stdc++.h>
#define EPS 1e-9
#define loop(i,a) for(int i=0; i<a; i++)

using namespace std;

struct point{
	double x,y;
	point(){ x=y=0.0; }
	point(double _x, double _y): x(_x), y(_y) {}
};

struct line{
	double a, b, c;
	point p, q;
};

vector<line> rectangle;

void pointsToLine(point p1, point p2, line &l){
	if(fabs(p1.x-p2.x)<EPS){
		l.a=1.0; l.b=0.0; l.c = -p1.x;
	}else{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b=1.0;
		l.c = -(double)(l.a*p1.x) -p1.y;
	}
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a - l2.a) <EPS) && (fabs(l1.b - l2.b)<EPS);
}

bool areSame(line l1, line l2){
	return areParallel(l1,l2) && (fabs(l1.c - l2.c)<EPS);
}

bool areIntersect(line l1, line l2, point &p){
	if(areParallel(l1,l2)) return false;
	p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b -l1.a*l2.b);
	if(fabs(l1.b)>EPS) p.y = -(l1.a*p.x +l1.c);
	else			   p.y = -(l2.a*p.x +l2.c);
	return true;
}

bool onLineSegment(point p, line l){
	double XminL=min(l.p.x, l.q.x), XmaxL=max(l.p.x, l.q.x);
	double YminL=min(l.p.y, l.q.y), YmaxL=max(l.p.y, l.q.y);
	//printf("X: %d %d\nY: %d %d\n",XmaxL,XminL, YmaxL, YminL);
	if((XminL<= p.x && p.x <= XmaxL) && (YminL<=p.y && p.y<=YmaxL)){ // esta dentro del rectangulo que forma los dos puntos
		// verificamos si las pendientes son iguales
		//puts("HEY ACA ");
		double dxL=l.p.x-l.q.x, dyL= l.p.y-l.q.y;
		double dx=l.p.x-p.x, dy = l.p.y-p.y;
		if((dxL*dy-dx*dyL)<EPS) return true; // para no hacer la division multiplicamos
	}
	return false;
}

bool intersectSegments(line l1, line l2){
	if(areSame(l1,l2)){ // dos rectas son iguales
		if((onLineSegment(l1.p, l2) || onLineSegment(l1.q, l2)) // una parte de l1 este dentro de l2
		|| (onLineSegment(l2.p, l1) || onLineSegment(l2.q, l1)) ){ // o una parte de l2 este dentro de l1
			return true;
		}
	}else{
		point p;
		//puts("HEY HPTA");
		if(areIntersect(l1, l2, p)){ // interseca dos rectas y nos da un punto p como respuesta y un booleano
			// verificamos si ese punto p este sobre los segmentos
			//printf("%3.lf %3.lf\n",p.x, p.y);
			//printf("line1 (%3.lf,%3.lf), (%3.lf,%3.lf)\n",l1.p.x, l1.p.y, l1.q.x, l1.q.y);
			//printf("line2 (%3.lf,%3.lf), (%3.lf,%3.lf)\n",l2.p.x, l2.p.y, l2.q.x, l2.q.y);
			//printf("p online l1: %d\np online l2: %d\n",onLineSegment(p, l1),onLineSegment(p,l2));
			//printf("\n\n\n");
			if(onLineSegment(p, l1) && onLineSegment(p,l2)) return true;
		}
	}
	return false;
}

bool insideRectangle(point Pleft, point Pright, point p){
	if(Pleft.x-p.x<=EPS && p.x-Pright.x<=EPS && p.y-Pleft.y<=EPS && Pright.y-p.y<=EPS) return true;
	//if(Pleft.x<=p.x && p.x<= Pright.x && Pleft.y>=p.y && p.y>=Pright.y) return true;
	return false;
}

int main(){
	//freopen("191.in","r",stdin);
	line lineInter, left, right, up, down;
	int n, sx, sy, ex, ey, lx, ly, rx, ry;
	scanf("%d",&n);
	while(n--){
		rectangle.clear();
		// line Intersect
		cin>>sx>>sy; point start(sx,sy);
		cin>>ex>>ey; point end(ex,ey);
		pointsToLine(start,end,lineInter); lineInter.p=start; lineInter.q=end;
		//printf("start: %3.lf %3.lf , end: %3.lf %3.lf\n",start.x, start.y, end.x, end.y);
		
		// rectangle points
		cin>>lx>>ly>>rx>>ry; 
		if(lx>rx) swap(lx, rx);
		if(ry>ly) swap(ry, ly);
		
		point p1(lx,ly); point p2(rx,ry);
		point p3(p1.x, p2.y); point p4(p2.x, p1.y);
		
		// print points 
		
		//printf("p1: %3.lf %3.lf\n",p1.x, p1.y);
		//printf("p2: %3.lf %3.lf\n",p2.x, p2.y);
		//printf("p3: %3.lf %3.lf\n",p3.x, p3.y);
		//printf("p4: %3.lf %3.lf\n",p4.x, p4.y);
		// rectangle lines
		pointsToLine(p1, p3, left); left.p=p1; left.q=p3; rectangle.push_back(left);
		pointsToLine(p3, p2, down); down.p=p3; down.q=p2; rectangle.push_back(down);
		pointsToLine(p2, p4, right); right.p=p2; right.q=p4; rectangle.push_back(right);
		pointsToLine(p4, p1, up); up.p=p4; up.q=p1; rectangle.push_back(up);
		
		if(insideRectangle(p1, p2,start) || insideRectangle(p1,p2,end)){
			puts("T");
		}else{
			line t;
			bool flag=false;
			loop(i,rectangle.size()){
				t = rectangle[i];
				if(intersectSegments(t, lineInter)){
					//printf("i= %d\n",i);
					//printf("ecuacion: a%3.lf + b%3.lf +%3.lf  -  puntos: p(%3.lf, %3.lf), q(%3.lf, %3.lf)\n", t.a, t.b, t.c, t.p.x, t.p.y, t.q.x, t.q.y);
					flag=true; 
					break;
				}
				//printf("ecuacion: a%3.lf + b%3.lf +%3.lf  -  puntos: p(%3.lf, %3.lf), q(%3.lf, %3.lf)\n", t.a, t.b, t.c, t.p.x, t.p.y, t.q.x, t.q.y);
			}
			if(flag) puts("T");
			else puts("F");
		}
		
	}	
	return 0;
}
