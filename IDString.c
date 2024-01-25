
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {

	int Xsteps;
	double deltaX=0.01;
	double Tsteps=100;  	//los que quiera
	double deltaT=0.0001;
	double L=1;
	double c=20;
	double x=0;
	Xsteps=L/deltaX;
	double y[Xsteps+1];
	double yanterior[Xsteps+1];
	printf("\n Xsteps: %8.4d", Xsteps);


	y[0]=0;
	y[Xsteps]=0;
	for(int i=1;i<=Xsteps;i++){
		x=x+deltaX;
			y[i]=5*sin(4*M_PI*x/L);

			printf("\n x: %8.4f", x);

			printf("\n elemento inicial de y: %8.4f", y[i]);
		}
	for(int i=1;i<=Xsteps;i++){
		y[i]=2*y[i]-y[i]+(pow(c,2)/pow(deltaX/deltaT,2))*(y[i-1]+y[i+1]-2*y[i]);
		yanterior[i]=y[i];
	}
	for(int j=1;j<Tsteps;j++){
		printf("\n evolucion del punto medio: %8.4f", y[Xsteps/2]);
		for(int i=1;i<=Xsteps;i++){

	y[i]=2*y[i]-yanterior[i]+(pow(c,2)/pow(deltaX/deltaT,2))*(y[i-1]+y[i+1]-2*y[i]);
	yanterior[i]=y[i];
	}}
    return 0;
}
