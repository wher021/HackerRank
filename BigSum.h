#pragma once
#include <string>
#include <iostream>
using namespace std;
class BigSum
{

public:

// the two "numbers" to be added. Make them as long as you like.
//string numStr1 = "662357";
//string numStr2 = "56487";// sum should = 718844

int calculate(string numStr1, string numStr2)
{


// keeping track of which string is longest using references
//string& rLongStr = numStr1.length() > numStr2.length() ? numStr1 : numStr2;
//string& rShortStr = numStr1.length() <= numStr2.length() ? numStr1 : numStr2;
	string rLongStr, rShortStr;
if (numStr1.length() > numStr2.length())
{
	rLongStr = numStr1;
	rShortStr = numStr2;
}
else
{
	rLongStr = numStr2;
	rShortStr = numStr1;
}

// initialize the sum with the long string but with space for a final carry at the beginning
string numStrSum = '0' + rLongStr;// the '0' in case of a final carry

								  // must go through the strings backwards since the least
								  // significant digit is at the end, not the beginning.
string::reverse_iterator r_itShort, r_itSum;
r_itShort = rShortStr.rbegin();// point to last "digit" in the short string
r_itSum = numStrSum.rbegin();// same for sum string

							 // add the "digits" one by one from end to beginning of the short string
while (r_itShort != rShortStr.rend())
{
	*r_itSum += *r_itShort - '0';// "add" the digits
	if (*r_itSum > '9')// must carry a one to the next "digit"
	{
		*(r_itSum + 1) += 1;
		*r_itSum -= 10;
	}
	++r_itShort;// move back 1 character
	++r_itSum;// in each string
}
if (numStrSum.at(0) == '0')// if 1st character is stiil '0'
numStrSum.erase(0, 1);// erase it

					  // output result
cout << numStrSum;// get "718844" for the case above

cout << endl;
return 0;

}

};