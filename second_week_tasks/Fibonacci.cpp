#include <iostream>

using namespace std;

double getFibonacciSequenceMember(int);

int main()
{
	double nMember = 0.0;
	const int N = 100;
	
	if (N <= 0) {
		cout << "Error! Incorrect input: enter a positive more than zero number." << endl;
		return 1;
	}
	
	nMember = getFibonacciSequenceMember(N);
	
	cout << "The member of Fibonacci sequence number " << N << " is: " << nMember;
	
	return 0;
}

double getFibonacciSequenceMember(int numberOfMembers)
{
	double firstMember = 0;
	double nextMember = 1;
	double nMember = 0;
	
	for (int i = 1; i < numberOfMembers - 1; i++) {
		nMember = firstMember + nextMember;
		firstMember = nextMember;
		nextMember = nMember;
	}
	
	return nMember;	
}
