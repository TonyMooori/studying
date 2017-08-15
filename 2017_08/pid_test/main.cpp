#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "pid.h"


#ifndef _USEFUL_MACROS_
#define _USEFUL_MACROS_
#define INF 99999999
#define N_PRIME 1000000007
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define OUTPUT_DEBUG
#ifdef OUTPUT_DEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x) do{}while(false)
#endif
#endif 

using namespace std;
double t=0;

float micros(){
    return t*1e6;
}

int main(void){
    const int N = 50000;
    const double dt = 1e-3;
    double theta = M_PI/4;
    double d_theta = -M_PI/4;
    const double k = 1.05;
    const double target = 0;
    const double c = 0.08;
    float input=0;
    FILE *fp = fopen("out.csv","w");
    
    double l,m,n;
    cin >> l>>m>>n;
    PID pid(l,m,n,-M_PI/4,M_PI/4,1);
    
    fprintf(fp,"t,dx,x,input\r\n");
    REP(i,N){
        t=i*dt;
        
        fprintf(fp,"%lf,%lf,%lf,%lf\r\n",t,d_theta,theta,input);
        input = pid.output(0.5*(target-theta),d_theta,theta);
        d_theta += (k*sin(theta)+input-c*d_theta+0.01)*dt;
        theta += d_theta * dt;
        
    }
    
    fclose(fp);
    
    return 0;
}
