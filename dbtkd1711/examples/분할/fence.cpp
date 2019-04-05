 #include <iostream>
 #include <vector>

 using namespace std;

 int number_of_test, number_of_board, answer, temp;
 int i, j;
 vector<int> heights;

int find_max_rectangle(int left, int right);

 int main() {
     cin >> number_of_test;
     for(i = 0 ; i < number_of_test ; i++) {
         cin >> number_of_board;
         for(j = 0 ; j < number_of_board ; j++) {
             cin >> temp;
             heights.push_back(temp);
         }
         answer = find_max_rectangle(0, number_of_board-1);
         cout << answer << endl;
         heights.clear();
     }

     return 0;
 }

 int find_max_rectangle(int left, int right) {
    if(left == right)
        return heights[left];
    int mid = (left + right) / 2;
    int ret = max(find_max_rectangle(left, mid), find_max_rectangle(mid+1, right));

    int low = mid, high = mid + 1;
    int height = min(heights[low], heights[high]);

    ret = max(ret, height*2);

    while(left < low || high < right) {
        if(high < right && (low == left || heights[low-1] < heights[high+1])) {
            high++;
            height = min(height, heights[high]);
        }
        else {
            low--;
            height = min(height, heights[low]);
        }
        ret = max(ret, height*(high - low + 1));
    }
    return ret;
 }
