#include <iostream>
#include <vector>
#include <algorithm>
#include "solution.h"
using namespace std;

/* Put your codes */

void Solution::value(vector<vector<int>>& points, vector<int> keypoint, int K) {
    vector<double> distance(points.size());

    for(int i=0; i<points.size(); i++) {
        distance[i] = sqrt( (keypoint[0] - points[i][0]) * (keypoint[0] - points[i][0])
         + (keypoint[1] - points[i][1]) * (keypoint[1] - points[i][1]) );
    }

    sort(distance.begin(), distance.end());
}