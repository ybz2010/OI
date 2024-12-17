#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    double pans = ouf.readReal();
    double jans = ans.readReal();

    if (fabs(pans-jans)<=1e-5 || fabs(pans-jans)/jans<=1e-5)
        quitf(_ok, "The sum is correct.");
    else
        quitf(_wa, "The sum is wrong: expected = %lf, found = %lf", jans, pans);

    return 0;
}
