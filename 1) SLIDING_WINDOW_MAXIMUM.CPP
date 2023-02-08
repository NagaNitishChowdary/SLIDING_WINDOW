// PROBLEM LINK --- https://leetcode.com/problems/sliding-window-maximum/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/980226?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
using namespace std ;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // BRUTEFORCE --- TLE
    /*
    vector<int> ans ;
    for(int i=0 ; i<nums.size()-k+1 ; i++){
        ans.emplace_back(*max_element(nums.begin()+i , nums.begin()+k+i)) ;
    }
    return ans ;
    */
    
    // OPTIMIZED --- MORE SPACE COMPLEXITY 
    /*
    int n = nums.size() ;
    queue<int> q ;
    map<int,int> mpp ;
    priority_queue<int> pq ;
    vector<int> ans ; 
    int maxi = INT_MIN ;
    for(int i=0 ; i<k ; i++){
        mpp[nums[i]]++ ; pq.push(nums[i]) ; ,q.push(nums[i]) ;
        maxi = max(maxi , nums[i]) ;
    }
    // ans.emplace_back(maxi) ;
    for(int i=0,j=k ;  j<=n ; i++ , j++){
        while(1){
            if(mpp[pq.top()] == 0) pq.pop() ;
            else break ;
        }
        ans.emplace_back(pq.top()) ;
        q.pop() ; 
        if(mpp[nums[i]] == 1) mpp.erase(nums[i]) ;
        else mpp[nums[i]]-- ;
        if(j != n){ mpp[nums[j]]++ ; q.push(nums[j]) ; pq.push(nums[j]) ; }
    }
    return ans ;
    */
    
    // MOST OPTIMIZED APPROACH 
    vector<int> ans ;
    deque<int> dq ;
    int n = nums.size() ;
    for(int i=0 ; i<n ; i++){
        // REMOVING OUT OF BOUND ELEMENT 
        if(!dq.empty() && dq.front() == i-k) dq.pop_front() ;
        // HERE WE ARE MAINTAINING IN DECREASING ORDER
        // IT REMOVES ALL ELEMENTS < A[I]
        while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back() ;
        // NOW THE CURRENT INDEX CAN BE TAKEN INTO DEQUE
        dq.push_back(i) ;
        if(i >= k-1) ans.emplace_back(nums[dq.front()]) ;
    }
    return ans ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> nums(n) ;
        for(int i=0 ; i<n ; i++) cin >> nums[i] ;
        int k ; cin >> k ;
        vector<int> ans =  maxSlidingWindow(nums,k) ;
        for(auto it:ans) cout << it << " " ; cout << endl ;
    }
    return 0;  
} 
