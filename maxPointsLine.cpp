// Leetcode problem/maxPointsLine.cpp

/* Problem Statement: Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.*/

/* Solution: Use slope as the key to hash all the lines. Pay attention to the corner points, e.g., when the slope is infinity.*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty())
            return 0;
            
        int maximum = 0;
        for(int i=0; i<points.size(); i++) {
            // the slope hash origining from points[i]
            unordered_map<float, int> slopeHash;
            int samePoint = 0;
            int curMax = 0;
            for(int j=i+1; j<points.size(); j++) {
                int xOffset = points[j].x - points[i].x;
                int yOffset = points[j].y - points[i].y;
        
                if(xOffset ==0 && yOffset ==0)
                    samePoint++;
                else {
                    float slope;
                    if(xOffset == 0)
                        slope = std::numeric_limits<float>::max();
                    else
                        slope = (float)yOffset/(float)xOffset;
                
                    // search the slope hash
                    if(slopeHash.find(slope) != slopeHash.end())
                        slopeHash[slope]++;
                    else
                        slopeHash[slope] = 1;
                    // update the maximum value
                    curMax = std::max(slopeHash[slope], curMax);
                }
            }
            // caculate the maximum points in the line
            maximum = std::max(samePoint+1+curMax, maximum);
        }
        
        return maximum;
    }
};
