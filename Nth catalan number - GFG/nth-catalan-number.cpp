// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        if(!n)
            return 1;
        return (4 *n - 2) * findCatalan(n - 1) / (n + 1);
        // vector<long long int> fact(2 * n + 1 , 0);
        // fact[0] = 1;
        // fact[1] = 1;
        // for(int i = 2 ; i <= 2 * n ;i++ )
        // fact[i] = i * fact[i - 1];
        // return fact[2 * n] / (fact[n] * fact[n + 1]);
        //code here
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends