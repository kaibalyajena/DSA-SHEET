#include <bits/stdc++.h>
using namespace std;

//method 1
//tc nlogn+2n
//sc n
function mergeOverlappingIntervals(arr) {
    const n = arr.length; // size of the array
    //sort the given intervals:
    arr.sort((a, b) => a[0] - b[0]);
    const ans = [];
    for (let i = 0; i < n; i++) { // select an interval:
        let start = arr[i][0];
        let end = arr[i][1];
        //Skip all the merged intervals:
        if (ans.length && end <= ans[ans.length - 1][1]) {
            continue;
        }
        //check the rest of the intervals:
        for (let j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = Math.max(end, arr[j][1]);
            } else {
                break;
            }
        }
        ans.push([start, end]);
    }
    return ans;
}

// const arr = [[1, 3], [8, 10], [2, 6], [15, 18]];
// const ans = mergeOverlappingIntervals(arr);
// console.log("The merged intervals are:");
// for (let it of ans) {
//   console.log(`[${it[0]}, ${it[1]}]`);
// }


//method 2
//tc nlogn+n
//sc n
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array
    //sort the given intervals:
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}