
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NX 201
#define NZ 201

void write (double temp[NX][NZ], int n);
int main () {
	int Xsteps=200;
	int Ysteps=200;
	double xi=-10;
	double xf=10;
	double deltaX;
	deltaX=(xf-xi)/Xsteps;

	double yi=-10;
	double yf=10;
	double deltaY;
	deltaY=(yf-yi)/Ysteps;

	double Tsteps=100;  	//los que quiera
	double deltaT=0.0001;
	double L=1;
	double c=20;
	double x=xi;
	double y=yi;

	double phi[Xsteps+1][Ysteps+1];
	double yanterior[Xsteps+1][Ysteps+1];
	printf("\n Xsteps: %8.4d", Xsteps);
    FILE* fout;

    // first, we delete the output file because later we will always append
    fout = fopen("output1_animation_temp.txt", "w");
    fclose(fout);
//BOUNDARY CONDITIONS
	for(int i=0;i<=Xsteps;i++){
		phi[i][Ysteps]=0;
		}
	for(int i=0;i<=Xsteps;i++){
		phi[Xsteps][i]=0;
		}
	for(int i=0;i<=Xsteps;i++){
		phi[i][0]=0;
		}
	for(int i=0;i<=Xsteps;i++){
		phi[0][i]=0;
		}
	for(int i=1;i<Xsteps;i++){
		x=x+deltaX;
		y=yi;
		for(int j=0;j<Xsteps;j++){
		y=y+deltaY;
			phi[i][j]=exp(-(pow(x,2)-pow(y,2))/50)*sin(2*M_PI*x/10)*sin(2*M_PI*y/10);
			printf("\n x: %8.4f", x);
			printf("\n elemento inicial de y: %8.4f", phi[i][j]);
		}}
	//FIRST STEP
	for(int i=1;i<=Xsteps;i++){
			for(int j=1;i<=Xsteps;i++){
			phi[i][j]=2*phi[i][j]-phi[i][j]+(pow(c,2)*pow(deltaT,2))*((((phi[i-1][j]+phi[i+1][j]-2*phi[i][j])/pow(deltaX,2)))+(((phi[i][j-1]+phi[i][j+1]-2*phi[i][j])/pow(deltaY,2))));
			yanterior[i][j]=phi[i][j];
		}}

	//ALGORITHM
	for(int j=1;j<Tsteps;j++){
	for(int i=1;i<=Xsteps;i++){
		for(int j=1;i<=Xsteps;i++){
		phi[i][j]=2*phi[i][j]-yanterior[i][j]+(pow(c,2)*pow(deltaT,2))*((((phi[i-1][j]+phi[i+1][j]-2*phi[i][j])/pow(deltaX,2)))+(((phi[i][j-1]+phi[i][j+1]-2*phi[i][j])/pow(deltaY,2))));
		yanterior[i][j]=phi[i][j];
	}}}
	write (phi,0);
    return 0;
}
void write (double temp[NX][NZ], int n) {
    int i, j;
    FILE* fout;
    fout = fopen("output1_animation_temp.txt", "a");

    for (i=0; i<NX; i++) {
        for (j=0; j<NZ; j++) {
            fprintf(fout, "%.16f\t", temp[i][j]);
        }
        fprintf(fout, "\n");
    }

    fclose(fout);
}
