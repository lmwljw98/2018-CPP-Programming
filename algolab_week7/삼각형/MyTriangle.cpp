#include <cstdlib>
#include <cmath>
#include <iostream>
#include "MyTriangle.h"
#include "MyLineSegment.h"

using namespace std;
// constructors
MyTriangle::MyTriangle ()
: p1(0,0), p2(0,0), p3(0,0)
{
}
// set p1, p2, p3 be in counterclockwise order
MyTriangle::MyTriangle (const MyPoint& a, const MyPoint& b, const MyPoint& c)
: p1(a), p2(b), p3(c)
{
 MyLineSegment s(p1, p2);
 if (! s.isLeftSide(p3))
 {
 MyPoint p;
 p = p1;
 p1 = p3;
 p3 = p;
 }
}
MyTriangle::MyTriangle (const MyTriangle& t)
: p1(t.p1), p2(t.p2), p3(t.p3)
{
}
// test if p is inside of a triangle
bool MyTriangle::isInside (const MyPoint& p) const
{
 MyLineSegment s1(p1, p2), s2(p2, p3), s3(p3, p1);
 return s1.isLeftSide(p) && s2.isLeftSide(p) && s3.isLeftSide(p);

}
// test if p is on the boundary of a triangle
bool MyTriangle::isOnBoundary (const MyPoint& p) const
{
 MyLineSegment s1(p1, p2), s2(p2, p3), s3(p3, p1);
 return s1.isCollinear(p) || s2.isCollinear(p) || s3.isCollinear(p);
}
// test if p is outside of a triangle
bool MyTriangle::isOutside (const MyPoint& p) const
{
 if(isInside(p) || isOnBoundary(p))
 return false;
 else
 return true;
}
// positive area of triangle p1, p2, p
int MyTriangle::getArea2() const
{
 return abs(area2());
}
// return type of a triangle
MyTriangle::TriangleType1 MyTriangle::getType1() const
{
    MyLineSegment s1(p1, p2), s2(p2, p3), s3(p3, p1);
    int p1_to_p2 = s1.length2sqr();
    int p2_to_p3 = s2.length2sqr();
    int p3_to_p1 = s3.length2sqr();
    int a, b, c;
    c = max(max(p1_to_p2, p2_to_p3), p3_to_p1);
    if(c == p1_to_p2){
        a = p2_to_p3; b = p3_to_p1;
    }
    else if(c == p2_to_p3){
        a = p1_to_p2; b = p3_to_p1;
    }
    else{
        a = p1_to_p2; b = p2_to_p3;
    }
    TriangleType1 type;
    if(getArea2() == 0)
    type = NONTRIANGLE;
    else if(a == b && b == c){
        type = EQUILATERAL;
    }
    else if(c == a+b){
        type = RIGHTTRIANGLE;
    }
    else if((a == b && a != c) || (b == c && a != b) || (a == c && a != b)){
        type = ISOSCELES;
    }
    else{
        type = SCALENE;
    }
    return type;
}
// return type of a triangle
MyTriangle::TriangleType2 MyTriangle::getType2() const
{
    MyLineSegment s1(p1, p2), s2(p2, p3), s3(p3, p1);
    int p1_to_p2 = s1.length2sqr();
    int p2_to_p3 = s2.length2sqr();
    int p3_to_p1 = s3.length2sqr();
    int a, b, c;
    c = max(max(p1_to_p2, p2_to_p3), p3_to_p1);
    if(c == p1_to_p2){
        a = p2_to_p3; b = p3_to_p1;
    }
    else if(c == p2_to_p3){
        a = p1_to_p2; b = p3_to_p1;
    }
    else{
        a = p1_to_p2; b = p2_to_p3;
    }
 TriangleType2 type;
 if(getArea2() == 0)
 type = NOT_A_TRIANGLE;
 else if(c > a + b){
     type = OBTUSE_TRIANGLE;
 }
 else if(c == a + b){
     type = RIGHT_TRIANGLE;
 }
 else{
     type = ACUTE_TRIANGLE;
 }
 return type;
}
// return twice the (signed) area of triangle p1, p2, p3
int MyTriangle::area2() const
{
 int p1x, p2x, p3x, p1y, p2y, p3y;
 p1x = p1.getX();
 p1y = p1.getY();
 p2x = p2.getX();
 p2y = p2.getY();
 p3x = p3.getX();
 p3y = p3.getY();
 return p1x * p2y - p1y * p2x +
 p1y * p3x - p1x * p3y +
 p2x * p3y - p3x * p2y;
}
