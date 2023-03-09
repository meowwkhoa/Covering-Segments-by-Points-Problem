#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
    int min = 0;
    
    while(segments.size() != 0){
        for(int i = 0; i < segments.size(); i++)
            if(min == 0)
                min = segments[i].end;
            else
                if(segments[i].end < min)
                    min = segments[i].end;
        
        points.push_back(min);
        
        for(int i = 0; i < segments.size(); i++)
            if(segments[i].start <= min && segments[i].end >= min){
                segments.erase(segments.begin() + i);
                i--;
            }
        min = 0;
    }
    
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
