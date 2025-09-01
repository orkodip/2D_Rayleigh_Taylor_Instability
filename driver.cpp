//SOLUTION OF NAVIER STOKES EQUATION IN A CONSERVATIVE FINITE DIFFERENCE DISCRETIZATION TECHNIQUE IN A SEMI-COLOCATED GRID USING A BALANCED FORCE METHOD.
//THE ADVECTION SCHEME IS QUICK WITH FIRST ORDER UPWIND. FDQGMRES IS USED TO SOLVE THE LINEAR SYSTEMS.
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<csignal>
#include<ctime>
#define TRUNC_L 1e-7	//volume fraction lower truncation criteria
#define TRUNC_U 1e-7	//volume fraction upper truncation criteria
#define EPS 1e-6	//DO NOT CHANGE THESE TWO CONSTANTS
#define SMALL 1e-8
#define TOL 1e-6	//convergence criteria for FDQGMRES solver
using namespace std;
int LC=1;	//loop condition
void control(int n)	//signal control function
{
	cout<<"PROGRAM INTERUPTED!"<<endl;
	cout<<"Enter 0 to stop: ";
	cin>>LC;
	if(LC==0) cout<<"STOP SIGNAL RECIEVED. PROGRAM WILL STOP AFTER SIMULATING CURRENT TIME-STEP."<<endl;
	else {LC=1; cout<<"SIMULATION CONTINUES."<<endl;}
}
const int I=160,J=640;	//no of grids in i and j directions
const double WIDTH=1.0,HEIGHT=4.0;	//domain size
#include "cfd_solvers.h"
#include "mbase.cpp"
#include "GMG2.cpp"
#include "MG_FDQGMRES.cpp"
#include "ivf_wav.cpp"
#include "clsvof.cpp"
#include "NS_g.cpp"
int main()
{
	signal(SIGINT,control);	//define signal and its function (FOR MANUALLY CONTROLLING THE PROGRAM DURING RUNTIME)
	int CNT=0;
	clock_t start=clock();
	NS ms;
	double At=0.5;	//Atwood number
	ms.MBASE::ini(CNT,3.0,1.0,1e-3,1e-3,0.0,(5.0e-4/(sqrt(At))));	//count,rho_0,rho_1,mu_0,mu_1,sigma,dt
	ms.CLSVOF::ini(2.0,0.1,2.0*M_PI);	//h,a,b
	ms.grid_write();
	ms.lsvf_write(0);
	ms.write_den_vis(0);
	for(int COUNT=CNT;(LC && (COUNT<20000));COUNT++)	//manually controlled loop
	{
		ms.CLSVOF::solve();
		ms.NS::solve();
		if((((COUNT+1)%50)==0)||(COUNT==0))
		{
			ms.write(COUNT+1);
			ms.lsvf_write(COUNT+1);
			ms.write_bin(COUNT+1);
		}
	}
	clock_t end=clock();
	cout<<"Simulation Time : "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
	return 0;
}
