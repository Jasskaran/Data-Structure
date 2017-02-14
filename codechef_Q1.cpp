#include <iostream>
using namespace std;

int main()
{
	int T,N;
	cin>>T;
	int flag=0;
	while(T)
	{
		cin>>N;
		int A[N],sum=0;
		for(int j=0;j<N;j++)
			cin>>A[j];
		for(int i=0;i<N;i++)
		{
			if(A[i]==0)
			{	
				sum=sum+1100;
				flag=1;
			}
			if(A[i]==1 && flag==1)
				sum=sum+100;
		}
		cout<<sum<<endl;
		T--;
	}
}
