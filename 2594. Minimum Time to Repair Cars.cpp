// T.C : O(n*log(maxR*cars*cars))
// S.C : O(1)
class Solution {
public:
    typedef long long ll;

    bool isValid(vector<int>& ranks, ll mid, int cars){
        ll carCount = 0;
        for(int i=0; i<ranks.size(); i++){
            carCount += sqrt(mid/ranks[i]);
        }

        return carCount >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll ans = -1;
        int maxRank = *max_element(ranks.begin(), ranks.end());
        ll s = 1;
        ll e = 1LL * maxRank * cars * cars;

        while(s <= e){
            ll mid = s + (e-s)/2;

            if(isValid(ranks, mid, cars)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
