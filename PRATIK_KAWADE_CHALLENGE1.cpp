
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    float x;
    float y;
};


bool checkOnLine(Point a1, Point a2, Point p)
{
    if (p.x <= max(a1.x, a2.x) && p.x >= min(a1.x, a2.x) && p.y <= max(a1.y, a2.y) && p.y >= min(a1.y, a2.y)) {
        return true;
    }

    return false;
}


string checkSlope(Point a1, Point a2, Point p)
{
    float slope = (a1.y - a2.y) * (a1.x - a2.x) - (a2.x - p.x) * (a2.y - p.y);

    if (slope == 0){
        return "colinear";
    }else if(slope > 0){
        return "left";
    }else{
        return "right";
    }
}


bool checkIntersection(Point a1, Point a2, Point b1, Point b2)
{
    string side1, side2, side3, side4;

    side1 = checkSlope(a1, a2, b1);

    if (side1 == "colinear" && checkOnLine(a1, a2, b1)){

        return true;
    }

    side2 = checkSlope(a1, a2, b2);

    if (side2 == "colinear" && checkOnLine(a1, a2, b1)){

        return true;
    }

    side3 = checkSlope(b1, b2, a1);

    if (side3 == "colinear" && checkOnLine(b1, b2, a1)){

        return true;
    }

    side4 = checkSlope(b1, b2, a2);

    if (side4 == "colinear" && checkOnLine(b1, b2, a2)){

        return true;
    }

    if(side1 != side2 && side3 != side4){
        return true;
    }
    return false;
}

bool checkPoint(Point polygon[], int n, Point p)
{

    if (n < 3){
      return false;
    }

    Point horizontalInfPoint = {FLT_MAX, p.y};
    int count = 0, i = 0;
    int nextIndex;
    bool flag;
    do
    {
        nextIndex = (i+1)%n;

        flag = checkIntersection(polygon[i], polygon[nextIndex], p, horizontalInfPoint);

        if (flag)
        {
            if (checkSlope(polygon[i], polygon[nextIndex], p) == "colinear"){
                return checkOnLine(polygon[i], polygon[nextIndex], p);
            }

            count++;
        }

        i = nextIndex;
    } while (i != 0);


    return (count%2 == 1);
}


int main()
{
    Point polygon1[] = {{1, 0}, {8, 3}, {8,8}, {1, 5}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    Point p = {3, 5};
    bool flag = checkPoint(polygon1, n, p);

    if(flag){
        cout << "Yes \n";
    }
    else{
        cout << "No \n";
    }


    Point polygon2[] = {{-3, 2}, {-2,-0.8}, {0, 1.2}, {2.2, 0}, {2, 4.5}};
    p = {0, 0};
    n = sizeof(polygon2)/sizeof(polygon2[0]);
    flag =checkPoint(polygon2, n, p);

    if(flag){
        cout << "Yes \n";
    }
    else{
        cout << "No \n";
    }

    return 0;
}
