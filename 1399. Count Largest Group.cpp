// T.C: O(nlog(n))
// S.C: O(n)
class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> mp(10001, 0);
        int size = 0;
        for(int num=1; num<=n; num++){
            int sum = 0;
            int x = num;
            while(x > 0){
                sum += x % 10;
                x  = x / 10;
            }
            mp[sum]++;
            size = max(size, mp[sum]);
        }

        int ans = 0;
        for(int& num: mp){
            if(num == size){
                ans++;
            }
        }

        return ans;
    }
};

// T.C: O(nlog(n))
// S.C: O(37) ~ O(1)
class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> mp(37, 0);
        int size = 0;
        for(int num=1; num<=n; num++){
            int sum = 0;
            int x = num;
            while(x > 0){
                sum += x % 10;
                x  = x / 10;
            }
            mp[sum]++;
            size = max(size, mp[sum]);
        }

        int ans = 0;
        for(int& num: mp){
            if(num == size){
                ans++;
            }
        }

        return ans;
    }
};
