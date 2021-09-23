#include <iostream>
using namespace std;

int main()
{
    int a, b, c, x, y, z, tt;
    cin >> a >> b >> c >> x >> y >> z >> tt;
    int takea,takeb,takec;
    int ans=0;
    for (takea= 0; takea <=20; takea++)
    {
        for (takeb= 0; takeb <= 20; takeb++)
        {
            for (takec= 0; takec <= 20; takec++)
            {
                int time=takea*a+takeb*b+takec*c;
                if(time<240)
                {
                    ans=max(ans,takea*x+takeb*y+takec*z);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}