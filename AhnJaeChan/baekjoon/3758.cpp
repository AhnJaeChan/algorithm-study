#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;

class TeamInfo {
public:
  int teamID;
  int scores[101];
  int totalScore;
  int totalSubmitCount;
  int lastSubmitTime;

  void resetInfo() {
    fill_n(scores, 101, 0);
    totalScore = 0;
    totalSubmitCount = 0;
    lastSubmitTime = 0;
  }

  friend ostream &operator<<(std::ostream &os, const TeamInfo &info) {
    return os << info.teamID << " : " << info.totalScore << ", " << info.totalSubmitCount << ", "
              << info.lastSubmitTime;
  }
};

TeamInfo teams[101];

int main() {
  cin >> T;

  for (int testCase = 0; testCase < T; testCase++) {
    int n, k, t, m;
    cin >> n >> k >> t >> m;

    for (int i = 1; i <= n; i++) {
      teams[i].resetInfo();
      teams[i].teamID = i;
    }

    for (int i = 1; i <= m; i++) {
      int teamID, question, result;
      cin >> teamID >> question >> result;

      if (result > teams[teamID].scores[question]) {
        teams[teamID].scores[question] = result;
      }

      teams[teamID].lastSubmitTime = i;
      teams[teamID].totalSubmitCount++;
    }

    for (int i = 1; i <= n; i++) {
      int sum = 0;
      for (int j = 1; j <= k; j++) {
        sum += teams[i].scores[j];
      }
      teams[i].totalScore = sum;
    }

    sort(teams + 1, teams + n + 1, [](const TeamInfo &a, const TeamInfo &b) {
      if (a.totalScore != b.totalScore) {
        return a.totalScore > b.totalScore;
      } else {
        if (a.totalSubmitCount != b.totalSubmitCount) {
          return a.totalSubmitCount < b.totalSubmitCount;
        } else {
          return a.lastSubmitTime < b.lastSubmitTime;
        }
      }
    });

    for (int i = 1; i <= n; i++) {
      if (teams[i].teamID == t) {
        cout << i << endl;
      }
    }

  }

  return 0;
}