#include"myheader2.h"
#include <stdio.h>
#include <string.h>
#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

typedef struct {
	   unsigned int width;
	   unsigned int height;
	   unsigned int planes;
	   unsigned short bitcount;
	   unsigned int size;
	} BITMAPINFOHEADER;

    BITMAPINFOHEADER bih;

BITMAPINFOHEADER getImageData(FILE *image)
	{
	    FILE *x;
	    x=image;
	    BITMAPINFOHEADER h;
	    fseek(x,2,SEEK_SET);
	    fread(&h.size,4,1,x);
	    printf("Size=%d\n",h.size);
	    fseek(x,18,SEEK_SET);
	    fread(&h.width,4,1,x);
	    fseek(x,22,SEEK_SET);
	    fread(&h.height,4,1,x);
	    printf("Width=%d\tHeight=%d\n",h.width,h.height);
    fseek(x,26,SEEK_SET);
	    fread(&h.planes,2,1,x);
	    printf("Number of planes:%d\n",h.planes);
	    fseek(x,28,SEEK_SET);
	    fread(&h.bitcount,2,1,x);
	    printf("Bit Count:%d\n",h.bitcount);
	    return h;
	}

void readbmp(FILE *image)
{

	unsigned int i=0,j=0,count=0;




	bih=getImageData(image);
	fseek(image,54,SEEK_SET);

	/*for(i=0;i<bih.width*bih.height;i++)*/
	if(bih.bitcount==8)
    {
        while(!feof(image))

    {
		//fread(&p,sizeof(p),1,image);
		fread(&pixelData[i][j][RED],sizeof(pixelData[i][j][RED]),1,image);
		//fread(&pixelData[i][GREEN],sizeof(pixelData[i][GREEN]),1,image);
		//fread(&pixelData[i][BLUE],sizeof(pixelData[i][BLUE]),1,image);
		//fread(&pixelData[i][ALPHA],sizeof(pixelData[ALPHA]),1,image);
		//pic[i]=p;
	//	printf(" %u= %d  ",count,pixelData[i][j][0]);
        count++;
		j++;
		printf("\n%u %u\n",i,j);
		if(j==bih.width)
        {
            printf("\n");
            i++;
            j=0;
        }
        }
        printf("\n\n%d %d",bih.width,bih.height);

	}
	else if(bih.bitcount==24)
    {
        while(!feof(image))
        {
		//fread(&p,sizeof(p),1,image);
		fread(&pixelData[i][j][RED],sizeof(pixelData[i][j][RED]),1,image);
		fread(&pixelData[i][j][GREEN],sizeof(pixelData[i][j][GREEN]),1,image);
		fread(&pixelData[i][j][BLUE],sizeof(pixelData[i][j][BLUE]),1,image);
		//fread(&pixelData[i][ALPHA],sizeof(pixelData[ALPHA]),1,image);
		//pic[i]=p;
	//	printf(" %u= %d %d %d ",count+54,pixelData[i][j][0],pixelData[i][j][1],pixelData[i][j][2]);
        count++;
		j++;
		//printf("\n%d %d\n",i,j);
		if(j==bih.width)
        {
            printf("\n");
            i++;
            j=0;
        }
        }


	}
	else if(bih.bitcount==32)
    {
        while(!feof(image))
        {
		//fread(&p,sizeof(p),1,image);
		fread(&pixelData[i][j][RED],sizeof(pixelData[i][j][RED]),1,image);
		fread(&pixelData[i][j][GREEN],sizeof(pixelData[i][j][GREEN]),1,image);
		fread(&pixelData[i][j][BLUE],sizeof(pixelData[i][j][BLUE]),1,image);
		fread(&pixelData[i][j][ALPHA],sizeof(pixelData[i][j][ALPHA]),1,image);
		//pic[i]=p;
		//printf(" %u= %d %d %d\n",i+54,pixelData[i][0],pixelData[i][1],pixelData[i][2],pixelData[i][3]);
		i++;
		if(i==bih.width)
		j++;
        }


	}



	fclose(image);
	//fclose(test);

	printf("\n");


}
