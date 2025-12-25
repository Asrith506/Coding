#include<bits/stdc++.h>
#include<queue>

using namespace std;

class Recorder {
    private:
        void updateReadings() {
            while(readings.top().second < windowStart) readings.pop();
        }
    public:
        priority_queue<pair<int,int>> readings;
        int windowStart;
        int windowSize;
        int currentTime;
        Recorder(int win) {
            windowStart = 0;
            windowSize = win;
        }
        void takeReading(int t, int temp) {
            readings.push({temp,t});
            currentTime = t;
            windowStart = t-windowSize;
            updateReadings();
        }
        int getMaximumInRange() {
            return readings.top().first;
        }
};

int main() {
    Recorder *recorder = new Recorder(3);
    recorder->takeReading(1,2);
    recorder->takeReading(2,3);
    recorder->takeReading(3,7);
    recorder->takeReading(4,5);
    recorder->takeReading(5,6);
    cout << recorder->getMaximumInRange() << endl;
    return 0;
}