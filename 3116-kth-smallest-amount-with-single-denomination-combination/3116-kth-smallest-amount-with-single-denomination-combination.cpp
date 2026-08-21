class Solution {
public:
#define ll long long 

    ll gcd(ll a , ll b){
        while(b){
            ll t = a % b;
            a = b ;
            b = t ;
        }
        return a ;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll n = coins.size();
        ll l = 1 ;
        ll r = 1LL * (*min_element(coins.begin() , coins.end())) * k;

        while(l < r){
            ll mid = l + (r-l) / 2;
            ll cnt = 0 ;

            for (ll m = 1 ; m < (1LL << n) ; m++){
                ll x = 1 ;
                int bits = 0 ;

                for (int i = 0 ; i < n ; i++){
                    if(m & (1LL << i)){
                        bits++;

                        ll g = gcd(x , coins[i]);

                        if(x > mid / (coins[i]/g)){
                            x = mid+1;
                            break;
                        }
                        x = x / g * coins[i];
                    }
                }
                if(x > mid) continue ;
                if(bits%2) cnt+= mid/x;
                else cnt -= mid/x;
            }
            if(cnt>= k) r = mid;
            else l = mid+1;
        }
        return l;
    }
};