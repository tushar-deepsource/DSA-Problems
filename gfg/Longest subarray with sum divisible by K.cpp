int ans = 0;
	    long long sum = 0;
	    unordered_map <long long, int> mp;
	    for(int i=0; i<n; i++){
	        sum += arr[i];
	        int r = sum%k;
	        r += (r<0) ? k : 0;
	        if(r == 0)
	            ans = max(ans, i+1);
	        if(mp.find(r) != mp.end())
	            ans = max(ans, i-mp[r]);
	        else
	            mp[r] = i;
	    }
	    return ans;
