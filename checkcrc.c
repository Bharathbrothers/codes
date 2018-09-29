// crc at sender side
#include<stdio.h>
int frl,genl,dup[20],rec[20];
int rem[5],gen[5];
void remindercrc(int fr2[]){
    int i=0,j=0,k1,k,k2,k3,k4;
	for(k=0;k<frl;k++){
		k4=k;
		if(fr2[k]==1){
			for(k1=k,j=0;j<genl;j++,k1++){
				rem[j]=fr2[k1]^gen[j];
			}
			for(i=0;i<genl;i++){
				printf("%d" ,rem[i]);			
			}
			printf("\n reminder \n");
		}
		else{
			for(k1=k,j=0;j<genl;j++,k1++){
				rem[j]=fr2[k1];
				//printf("rem is %d\n",rem[j]);
			}
			for(i=0;i<genl;i++){
				printf("%d" ,rem[i]);			
			}
			printf("\n reminder\n");

		}
		for(k2=0,k3=k;k2<genl;k2++,k3++){
			fr2[k3]=rem[k2];
		}
		k=k4;
		printf("\n updated \n");
		for(i=0;i<frl;i++){
			printf("%d",fr2[i]);
		}
		printf("\n");
	}
	printf("final reminder is ");
	for(i=0;i<genl;i++){
		printf("%d",rem[i]);
	}
	printf("\n");
}
void main(){
    int fr[10],tfl,i,j;
    frl=8;
    genl=4;
    printf("enter the frame\n");
    for(i=0;i<frl;i++){
	scanf("%d",&fr[i]);
	dup[i]=fr[i];
    }
    printf("\n");
    for(i=0;i<frl;i++){
        printf("%d",fr[i]);
    }
    printf("\n");
    printf("enter the gen\n");
    for(i=0;i<genl;i++){
	scanf("%d",&gen[i]);
    }
    printf("\n");
    for(i=0;i<genl;i++){
        printf("%d",gen[i]);
    }
    printf("\n");
    tfl = frl+genl;
    for(i=frl;i<tfl-1;i++){
	dup[i]=0;
    }
	
    for(i=0;i<tfl-1;i++){
	rec[i]=dup[i];
        printf("%d",dup[i]);
    }
    printf("\n");
    remindercrc(dup);
	printf("\nreceived reminder is\n");
    for(i=0;i<genl;i++){
	printf("%d",rem[i]);	
	}
	printf("\n");
    for(i=frl,j=1;i<tfl;i++,j++){
	rec[i]=rem[j];
	printf("%d",rem[j]);
    }
	printf("\n");
    for(i=0;i<tfl-1;i++){
    printf("%d ",rec[i]);
    }
    printf("\n");
    
 }

