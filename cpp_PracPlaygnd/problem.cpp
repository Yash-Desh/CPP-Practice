//{ Driver Code Starts
#include <iostream>
using namespace std;
#define MAX 1000 

bool isToepliz(int A[MAX][MAX],int N,int M);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[MAX][MAX];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		}

		cout<<isToepliz(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this method*/
bool isToepliz(int A[MAX][MAX],int N,int M)
{
    //Your code here
    int a1[N], a2[M];
    for(int i=0; i<N; i++)
    {
        a1[i] = A[0][i];
    }
    
    for(int j=1; j<M; j++)
    {
        a2[j] = A[j][0];
    }
    
    
    // Loop to check the upper triangle with the diagonal
    for(int i=1;i<N; i++)
    {
        int k=0;
        for(int j=i; j<M; j++)
        {
            if(a1[k] != A[i][j])
            {
                cout<<"a1"<<endl;
                return 0;
            }
            k++;
        }
    }
    
    // Loop to check lower triangle without the diagonal
    for(int i=1; i<M; i++)
    {
        int k=1;
        for(int j=i+1; j<N; j++)
        {
            if(a2[k] != A[j][i])
            {
                cout<<"a2"<<endl;
                return 0;
            }
            k++;
        }
    }
    
    return 1;
}