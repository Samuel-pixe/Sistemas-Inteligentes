#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float e1[4]={0.0,0.0,1.0,1.0};
	float e2[4]={0.0,1.0,0.0,1.0};
	float tg[4]={0.0,1.0,1.0,0.0};

    float w1[3][3][100];
    float w2[3][3][100];
    float I[3][3];
    float O[3][3];
    float vt[10];
    float erro[100];
    int i,j,l,t;
    int cs;
    int n=0;
    int vmin;
    float errmax=20.0;

	
    
	for(n=0;n<100;n++){
	
    w1[0][0][n] = (rand()/32767.0)*40.0-20.0;
    w1[1][0][n] = (rand()/32767.0)*40.0-20.0;
    w1[2][0][n] = (rand()/32767.0)*40.0-20.0;

    w1[0][1][n] = (rand()/32767.0)*40.0-20.0;
    w1[1][1][n] = (rand()/32767.0)*40.0-20.0;
    w1[2][1][n] = (rand()/32767.0)*40.0-20.0;

    w2[0][0][n] = (rand()/32767.0)*40.0-20.0;
    w2[1][0][n] = (rand()/32767.0)*40.0-20.0;
    w2[2][0][n] = (rand()/32767.0)*40.0-20.0;
 	}
	n=0;
    do{
	
	erro[n]=0.0;
    for(cs=0;cs<4;cs++){

    I[0][0] = e1[cs];
    I[0][1] = e2[cs];
    I[0][2] = 1.0;


    O[0][0] = I[0][0];
    O[0][1] = I[0][1];
    O[0][2] = I[0][2];

    for(j = 0; j < 2; j++){
    	I[1][j]=0.0;
    	for(i = 0; i< 3; i++){
    		I[1][j] +=  w1[i][j][n]*O[0][i];
		}
		O[1][j]=1.0 / (1.0 + exp(-I[1][j]));
	}

    I[1][2]=1.0;
    O[1][2]=I[1][2];

   for(l = 0; l < 1; l++){
    	I[2][l]=0.0;
    	for(j = 0; j< 3; j++){
    			I[2][l] +=  w2[j][l][n]*O[1][j];
		}
		O[2][l]=1.0 / (1.0 + exp(-I[2][l]));
	}
    erro[n]+=(tg[cs]-O[2][0])*(tg[cs]-O[2][0]);
}//close for cs
	
	erro[n]=erro[n]/4.0;
    printf("Resultado:%d erro= %f \n",n,erro[n] );
    

	if(n==100){ 	
		for(int f=0;f<10; f++){
			errmax=20.0;
			for(int v=0;v<99;v++){
				if(errmax>erro[v]){
				vmin=v;
				errmax=erro[v];
				}
				vt[f]=vmin;
				erro[vmin]=20.0;	
			}
			
		}
		
		n=0; 
		for(int f=0;f<10;f++){
			t=vt[f];	
			w1[0][0][n] = w1[0][0][t];
    		w1[1][0][n] = w1[0][0][t];
    		w1[2][0][n] = w1[0][0][t];

    		w1[0][1][n] = w1[0][0][t];
    		w1[1][1][n] = w1[0][0][t];
    		w1[2][1][n] = w1[0][0][t];

    		w2[0][0][n] = w1[0][0][t];
    		w2[1][0][n] = w1[0][0][t];
    		w2[2][0][n] = w1[0][0][t];
    	}

    }
	else{ n++;}	
	
    }while(erro[n]>0.0001);




    	for(j = 0; j < 2; j++){
    		for(i = 0; i< 3; i++){
    			printf("w1[%d][%d][n]=%f; \n",i,j,w1[i][j][n]);
			}
		}
    	for(l = 0; l < 1; l++){
    		for(j = 0; j< 3; j++){
    			printf("w2[%d][%d][n]=%f; \n",j,l,w2[j][l][n]);
			}
		}



return 0;
}
