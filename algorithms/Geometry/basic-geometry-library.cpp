/*
 * Basic Geometry Library
 * Point, Vector, Line, Segment
 * 
 * (c) 2013 Sylap Aliyev <sylapaliyev@gmail.com> 
 * 16/12/2013
 * */

#include <iostream>
#include <cmath>
#include <cassert>
#define  DBG(X)		cerr << #X << " : " << X << "\n"
using namespace std;

class Point {
	public:
		double x, y;
		
		Point(double x = 0, double y = 0) : x(x), y(y) {}
		
		double dist(Point other) {
			return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
		}
};

class Vector {
	public:
		double x, y;
		
		Vector(double x = 0, double y = 0) : x(x), y(y) {}
		Vector(Point point) : x(point.x), y(point.y) {}
		Vector(Point origin, Point point) : x(point.x-origin.x), y(point.y-origin.y) {}
		
		double dot(Vector other) {
			return x*other.x + y*other.y;
		}
		
		double cross(Vector other) {
			return x*other.y - other.x*y;
		}
		
		double operator*(Vector other) { // dot product
			return (*this).dot(other);
		}
		
		double operator^(Vector other) { // cross product
			return (*this).cross(other);
		}
		
		double mtude() { // magnitude
			return sqrt((*this)*(*this));
		}
		
		double angle(Vector other) {
			return acos(((*this) * other) / ((*this).mtude() * other.mtude()));
		}
};

class Line {
	private:
		pair<Point, Point> point_instances() {
			if (B == 0)
				return make_pair(Point(C/A, 0), Point(C/A, 5));
			return make_pair(Point(0, f(0)), Point(5, f(5)));
		}
	
	public:
		double A, B, C; // Ax + By = C
		
		Line(int A = 0, int B = 0, int C = 0) : A(A), B(B), C(C) {}
		Line(Point first, Point second) {
			A = second.y-first.y;
			B = first.x-second.x;
			C = A*first.x + B*first.y;
		}
		
		bool ishor() {
			return A == 0;
		}
		
		bool isver() {
			return B == 0;
		}
		
		double f(double x) { // f(x) = y
			assert(B != 0); // is not vertical
			return (C-A*x)/B;
		}
		
		double finv(double y) { // f'(y) = x
			assert(A != 0); // is not horizontal
			return (C-B*y)/A;
		}
		
		double dist(Point point) {
			pair<Point, Point> temp = point_instances();
			Point A = temp.first;
			Point B = temp.second;
			Point C = point;
			
			return fabs(Vector(A, B) ^ Vector(A, C)) / Vector(A, B).mtude();
		}
		
		Line orthaline(Point point) {
			return Line(-B, A, (-B)*point.x + A*point.y);
		}
		
		Point orthagonal(Point point) {
			return (*this).intersection(orthaline(point));
		}
		
		bool isparallel(Line other) {
			return ((A*other.B - other.A*B) == 0);
		}
		
		Point intersection(Line other) {
			assert((A*other.B - other.A*B) != 0);
			Point intr_pnt;
			intr_pnt.x = (other.B*C - B*other.C) / (A*other.B - other.A*B);
			intr_pnt.y = (A*other.C - other.A*C) / (A*other.B - other.A*B);
			return intr_pnt;
		}
		
		bool coincide(Line other) {
			if (isver() != other.isver())
				return false;
			
			if (isver() && other.isver())
				return finv(0) == other.finv(0);
			
			return f(0) == other.f(0);
		}
};

class Segment {
	private:
		double A, B, C;
		Point start;
		Point end;
	
	public:
		Segment(Point start, Point end) : start(start), end(end) {
			A = end.y-start.y;
			B = start.x-end.x;
			C = A*start.x + B*start.y;
		}
		
		void set(Point new_start, Point new_end) {
			start = new_start;
			end = new_end;
			A = end.y-start.y;
			B = start.x-end.x;
			C = A*start.x + B*start.y;
		}
		
		Point getstart() {
			return start;
		}
		
		void setstart(Point new_start) {
			start = new_start;
			A = end.y-start.y;
			B = start.x-end.x;
			C = A*start.x + B*start.y;
		}
		
		Point getend() {
			return end;
		}
		
		void setend(Point new_end) {
			end = new_end;
			A = end.y-start.y;
			B = start.x-end.x;
			C = A*start.x + B*start.y;
		}
		
		Point mid() {
			return Point((start.x+end.x)/2, (start.y+end.y)/2);
		}
		
		double dist(Point point) {
			if ((Vector(start, end) * Vector(start, point)) < 0)
				return start.dist(point);
			
			if ((Vector(end, start) * Vector(end, point)) < 0)
				return end.dist(point);
			
			return Line(start, end).dist(point);
		}
};

double rad2degree(double val) {
	return val*180.0/acos(-1);
}

int main() {
	cout << "Welcome To basic-geometry-library.cpp";
	
	return 0;
}
