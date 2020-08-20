#include<iostream>
using namespace std;


#define INF 10000
 
struct Point
{
    int x;
    int y;
};
 

bool onseg(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
 

int ori(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}
 

bool intersect(Point p1, Point q1, Point p2, Point q2)
{
    
    int o1 = ori(p1, q1, p2);
    int o2 = ori(p1, q1, q2);
    int o3 = ori(p2, q2, p1);
    int o4 = ori(p2, q2, q1);
 

    if (o1 != o2 && o3 != o4)
        return true;
 
   
    if (o1 == 0 && onseg(p1, p2, q1)) return true;
 

    if (o2 == 0 && onseg(p1, q2, q1)) return true;
 

    if (o3 == 0 && onseg(p2, p1, q2)) return true;
 

    if (o4 == 0 && onseg(p2, q1, q2)) return true;
 
    return false;
}
 

bool inside(Point polygon[], int n, Point p)
{

    if (n < 3)  return false;
 

    Point extreme = {INF, p.y};
 

    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
   
        if (intersect(polygon[i], polygon[next], p, extreme))
        {
            
            if (ori(polygon[i], p, polygon[next]) == 0)
               return onseg(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
   
    return count&1; 
}
 

int main()
{
    Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
    int n = sizeof(polygon1)/sizeof(polygon1[0]);
    Point p = {20, 20};
    inside(polygon1, n, p)? cout << "true \n": cout << "false \n";
    
    
    return 0;
    }
