#include <stdio.h>

int main(){
  int col, row;
  int i,j;
  float label;
  float data[10000];

  FILE* lmatfp, *fmatfp;
  FILE* datacsv;

  fmatfp = fopen("INTER_NN_try1.fmat","rb");
  lmatfp = fopen("INTER_NN_try1.lmat","rb");
  datacsv = fopen("data.txt","w");

  fread(&row, sizeof(int), 1, fmatfp);
  fread(&col, sizeof(int), 1, fmatfp);
  printf("%d %d\n", row, col);

  for( j=0 ; j<row ; j++ ){
    fread(&label, sizeof(float), 1, lmatfp);
    fread(data, sizeof(float), col, fmatfp);

    fprintf(datacsv, "%d ", (int)label);

    for( i=1 ; i<col ; i++ ){
      	if( data[i] != 0 )
	fprintf(datacsv,"%d:%f ",i,data[i]);
    }
    
    if (data[i] != 0 ){
    	fprintf(datacsv,"%d:%f\n",i,data[i]);
    }
    else fprintf(datacsv,"\n");
  }

  fclose(datacsv);
  fclose(fmatfp);
  fclose(lmatfp);
  
  
}
