#include <bits/stdc++.h>
using namespace std;

#Calculate probability of game merge for HWW

int calc()
{
    double r,r2,r3,r4,r5,r6;
    int i,j,k;
    double a[20][20][20];
    double b[20],c[20];
    for(i=0;i<20;i++)
    {
        b[i]=0;c[i]=20;
        for(j=0;j<20;j++)
        {
            for(k=0;k<20;k++)
            {
                a[i][j][k]=0;
            }
        }
    }
    
    a[0][17][3]=1.0;
    
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            for(k=0;k<20;k++)
            {
                if(k==0 || k+k>=j)
                {
                    b[i] += a[i][j][k];
                }
                else if(a[i][j][k]<=0)
                {
                    a[i][j][k]=0;
                }
                else
                {
                    r=a[i][j][k]*k/j;
                    
                    r2=r/k; a[i+1][j-1][k-1]=a[i+1][j-1][k-1]+r2;
                    
                    r3=r-r2; a[i+1][j-2][k-1]=a[i+1][j-2][k-1]+r3;
                    
                    r4 = a[i][j][k]-r; a[i+1][j-2][k]=a[i+1][j-2][k]+r4;
                    
                    //cout<<i<<" - "<<j<<" - "<<k<<"\t";
                    //cout<<a[i][j][k]<<"\t"<<r2<<"\t"<<r3<<"\t"<<r4<<endl;
                }
                
            }
        }
    }
    
    /*for(i=0;i<20;i++)
    {
        cout<<"Iteration "<<i<<endl;
        cout<<"\t"; for(j=0;j<20;j++) cout<<j<<"\t"; cout<<endl;
        for(j=0;j<20;j++)
        {
            cout<<j<<"\t";
            for(k=0;k<20;k++)
            {
                cout<<a[i][j][k]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }*/
    
    for(i=0;i<20;i++)
    {
        if(i==0) c[i]=b[i];
        else c[i]=c[i-1]+b[i];
        
        double d = 1-c[i];
        double p = pow(d,5);
        double p2 = 1-p;
        
        cout<<i<<"\t- "<<b[i]<<"\t- "<<c[i]<<"\t- "<<d<<"\t- "<<p<<"\t- "<<p2<<endl;
    }
    
    return 0;
}

int main() {
    calc();
	// your code goes here
	return 0;
}
