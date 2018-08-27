#ifndef _MY_TRIANGLE_H_
#define _MY_TRIANGLE_H_
#include "MyPoint.h"
class MyTriangle
{
public:
typedef enum TriangleType1 {NONTRIANGLE = 0, EQUILATERAL, RIGHTTRIANGLE, ISOSCELES, SCALENE};
 typedef enum TriangleType2 {NOT_A_TRIANGLE = 0, RIGHT_TRIANGLE, OBTUSE_TRIANGLE, ACUTE_TRIANGLE};
// constructors
 MyTriangle ();
 MyTriangle (const MyPoint &a, const MyPoint &b, const MyPoint &c);
 MyTriangle (const MyTriangle& t);
 // test funtions
 bool isInside (const MyPoint& p) const;
 bool isOnBoundary (const MyPoint& p) const;
 bool isOutside (const MyPoint& p) const;
 // utility functions
 int getArea2() const;
 TriangleType1 getType1() const;
 TriangleType2 getType2() const;
private:
 MyPoint p1, p2, p3; // are in counterclockwise(CCW) order
 int area2() const;
};
#endif // _MY_TRIANGLE_H_
