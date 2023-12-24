#include <iostream>
#include <string>
using namespace std;
int main()
{
	int ctA = 0, cta = 0,cts=0,ch=0, s;
	char A, a;
	string st;
	cin>> A;
	cin >> a;
	cin>> st;
	
	const char *ptr = st.c_str();
	for (int i = 0; i < st.length(); i++)
	{
		if (*ptr == A)
		{
			ctA++;
		}
		else if (*ptr == a)
		{
			cta++;
		}
		else
		{
			cts++;
		}
		ptr++;
	}
	ch = ctA + cta + cts;
	cout << "ctA =" << ctA << ", cta =" << cta << ", cts =" << cts<<", ch ="<<ch;
	return 0;
}
