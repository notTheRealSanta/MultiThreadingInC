#include <stdio.h>

#include <pthread.h>

struct arg_struct {
    
    int arg1;
    int arg2;
    int res;
    
};

void *doMulRowAndCol ( void *arguments ){
    
    struct arg_struct *args = arguments;
    args->res = args->arg1 * args->arg2;
    //printf(" %d + %d == %d\n",args->arg1,args->arg2,args->res);
}

int main() {
    
    pthread_t thread[20];
    int rowsA, colsA;
    int rowsB, colsB;
    int matA[10][10];
    int matB[10][10];
    
    printf("Enter rowsA : ");
    scanf("%d",&rowsA);
    
    printf("Enter colsA : ");
    scanf("%d",&colsA);
    
    printf("Enter rowsB : ");
    scanf("%d",&rowsB);
    
    printf("Enter colsB : ");
    scanf("%d",&colsB);
    
    int i,j,k;
    printf("Enter mat A : \n");
    for ( i =0 ; i < rowsA; i++ ) {
        
        for ( j = 0; j < colsA; j++ ){
            
            printf("Enter A[%d][%d] : ",i+1,j+1 );
            scanf("%d",&matA[i][j]);
            
        }
        
    }
    
    printf("Enter mat B : \n");
    for ( i =0 ; i < rowsB; i++ ) {
        
        for ( j = 0; j < colsB; j++ ){
            
            printf("Enter b[%d][%d] : ",i+1,j+1 );
            scanf("%d",&matB[i][j]);
            
        }
        
    }
    
    int matC [10] [10] ;
    int m;
    int x = 0;
    for ( j = 0; j < rowsA; j++ ){
        
        for ( i = 0 ; i < colsB; i++ ) {
            int y  = x;
            for ( k = 0; k < colsA; k++){
                
            
           	 	struct arg_struct a_s ;
            	a_s.arg1 = matA[j][k];
            	a_s.arg2 = matB[k][i];
            	a_s.res = 0;
            	if (pthread_create(&thread[x], NULL, &doMulRowAndCol, (void *)&a_s) != 0) {
                	printf("Error!\n");
                	return -1;
            	}
                
				pthread_join(thread[x], NULL)
                 x++;
                
                matC[j][i] += a_s.res;
            	printf(" %d * %d = %d :\n" ,matA[j][k],matB[k][i],a_s.res);
                
            }
            
        }
        
    }
    
    for ( i =0 ; i < rowsA; i++ ) {
        
        for ( j = 0; j < colsB; j++ ){
            
            printf("C [%d][%d] : %d \n",i+1,j+1,matC[i][j]);
            
            
        }
        
    }
    
    return 0;
    
}
