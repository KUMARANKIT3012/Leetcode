class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> l;
	    // Code here
	    for(int i= 2; i<=sqrt(N); i++){
	        if(N%i==0){
	            l.push_back(i);
	        }
	        while(N%i == 0){
	            N=N/i;
	        }
	    }
	    if(N!=1){
	        l.push_back(N);
	    }
	    return l;
	}
};
