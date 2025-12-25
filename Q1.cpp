// cat mouse cheese
#include<bits/stdc++.h>
using namespace std;

int manHattanDisatance(int x1,int y1, int x2, int y2) {
    return abs(x1-x2)+abs(y1-y2);
}

bool isValid(int r,int c,int n) {
    return r>=0 and r<n and c>=0 and c<n;
}

int safeManhattanDistance(int n,pair<int,int> &catPos,pair<int,int> &mousePos,pair<int,int> &cheesePos) {
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};

    int score=INT_MAX;

    int catR = catPos.first;
    int catC = catPos.second;

    vector<vector<bool>> visted(n,vector<int> (n,false));
    int mouseR = mousePos.first;
    int mouseC = mousePos.second;

    queue<pair<int,int>> q;
    visited[mouseR][mouseC] = true;
    q.push(mousePos);

    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        mouseR = p.first;
        mouseC = p.second;

        score = min(score,manHattanDistance(mouseR,mouseC,catR,catC));

        if(mouseR == cheesePos.first and mouseC == cheesePos.second) return score;

        int currScore = INT_MIN;
        int x=-1,y=-1;

        for(int i=0;i<4;i++) {
            int r = mouseR + dx[i];
            int c = mouseC + dy[i];
            if(isValid(r,c,n) and !visited[r][c]) {
                int tempScore = manHattanDistance(r,c,catC,catR);
                if(currScore < tempScore) {
                    currScore = tempScore;
                    x = r;y = c;
                }
            }
        }
        if(x!=-1) {
            q.push({x,y});
            visited[x][y] = true;
        }
    }
    return -1;
}

int main() {
    int n=5;
    pair<int,int> catPos={2,2};
    pair<int,int> mousePos={1,1};
    pair<int,int> cheesePos={4,3};

    return safeManhattanDistance(n,catPos,mousePos,cheesePos);
}