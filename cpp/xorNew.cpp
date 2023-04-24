#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

//function definition

int minxor(int matrix[], int length)
{
	int answer=INT_MAX,obtainedxor=0;
	for(int i=0; i<length; ++i)
		{
			obtainedxor^=matrix[i];
		}

//	int cost;
//	for(int i=0; i<length; ++i)
//		{
//			cost=abs((obtainedxor^matrix[i])-matrix[i]);
//			if(answer>cost)
//				{
//					answer=cost;
//				}
//		}

	return obtainedxor;
}

int main()
{
	//input
	int t=0;
	cin>>t;

	while(t--)
		{
			int length;
			cout<<"Len =  ";
			cin>>length;
			int matrix[length];
			cout<<"Ele= ";
			for(int i=0; i<length; ++i)
				{
					cin>>matrix[i];
				}

			//output
			cout<<minxor(matrix, length)<<"\n";
		}

	return 0;
}
