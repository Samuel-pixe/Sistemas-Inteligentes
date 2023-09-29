#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int l1[4], l2[4];

int o1[4], o2[4], o3[4];
float w1=2, w2 = 3, w3 =3, w4 = 5, w5 = 2, w6 = 4;
float t1 = 1,t2=6,t3 = 5;


int fuzzy ( float wi, float wj, int li, int lj, float t, int flag){
	float soma;
	soma = (li*wi)+(lj*wj);
	if(flag ==0){
		if(soma > t){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(soma > t){
			return 0;
		}else{
			return 1;
		}
	}
}


main(){
	for(int i = 0; i<4;i++){
		printf("\nInforme l1: ");
		scanf("%i",&l1[i]);
	}
	for(int i = 0; i<4;i++){
		printf("\nInforme l2: ");
		scanf("%i",&l2[i]);
	}
	//---------------------------------------------------------------
	for(int i = 0; i<4;i++){
		o1[i]= fuzzy(w1,w2,l1[i],l2[i], t1,0);
	}
	
	for(int i = 0; i<4;i++){
		o2[i]= fuzzy(w3,w4,l1[i],l2[i],t2, 1 );
	}
	printf("l1 | l2 | o1 | o2 | o3  \n");
	for(int i = 0; i<4;i++){
		o3[i]= fuzzy(w5,w6,o1[i],o2[i],t3, 0);
		printf("%i | %i | %i | %i | %i  \n",l1[i],l2[i],o1[i],o2[i],o3[i]);
	}
	
			
	
	
}
