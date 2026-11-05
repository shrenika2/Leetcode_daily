class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0,n1=arr1.size(),n2=arr2.size(),i=0,j1=0,j2=0;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        while(i<n1){
            while(j1<n2-1 && arr1[i]-arr2[j1]<d){
                j1++;
            }
            while(j2<n2-1 && arr2[j2+1]-arr1[i]<=d){
                j2++;
            }
            if(abs(arr1[i]-arr2[j1])>d && abs(arr1[i]-arr2[j2])>d)ans++;
            i++;
        }
        return ans;
    }
};