#include <bits/stdc++.h>
#include"tmwtypes.h"
using namespace std;

struct complNum {
	int re;
	int im;
};

int main() {
	long  len;
  	char* buf = NULL;
  	FILE* fp  = NULL;

  	fp = fopen( "cameraman1.bmp", "rb" );
  	if (!fp) return 0;

  	// Get its length (in bytes)
  	if (fseek( fp, 0, SEEK_END ) != 0)  
    {                                 
    	fclose( fp );
    	return 0;
    }

  	len = ftell( fp );
  	rewind( fp );

  	// Get a buffer big enough to hold it entirely
  	buf = (char*)malloc( len );
  	if (!buf)
    {
    	fclose( fp );
    	return 0;
    }
    

  	// Read the entire file into the buffer
  	if (!fread( buf, len, 1, fp ))
    {
    	free( buf );
    	fclose( fp );
    	return 0;
    }

  	fclose( fp );
  
  	int ascii[len];
  
  	for(int i=0; i<len; i++)
  	{
  		ascii[i]=int(buf[i])+128;
  	}
 
////////////////////////////////////////////////// decimal to binary //////////////////////////////////////////////////
  	int inseq[len*8];
  	int j,d=0;
  	for(int i=0; i<len; i++)
  	{
  		int binaryNum[8]={0,0,0,0,0,0,0,0};

    	int k = 0;
		int n=ascii[i] ;
		for(j=0; j<8; j++)
		{
			binaryNum[7-j] = n % 2;
			n = n/2;
		} 
		
////////////////////////////////////////////////// Binary sequence Generation //////////////////////////////////////////////////
	
		for( j=0; j<=7; j++)
		{
			inseq[d]=binaryNum[j];
			d++;	
		}
  	}
	  	
	int k=0;
	
	int N = len*8;
	int outseq[N];
	
	creal_T Y[N/4];
	creal_T op[N/4];
	////////////////////////////////////////// 16QAM Modulation ////////////////////////////////////////// 
	for(int i = 0; i < N; )
    {
    	// I --> Imaginary; 
		// Q --> Real;
    	if(inseq[i] == 0 && inseq[i+1] == 1 && inseq[i+2] == 0 && inseq[i+3] == 1 ) // 0101 -->33
    	{
    		Y[k].re = 3;
    		Y[k].im = 3;    		
		}
    	else if(inseq[i] == 0 && inseq[i+1] == 1 && inseq[i+2] == 0 && inseq[i+3] == 0 )//0100 -->13
    	{
    		Y[k].re = 1;
    		Y[k].im = 3;
		}
    	else if(inseq[i] == 0 && inseq[i+1] == 1 && inseq[i+2] == 1 && inseq[i+3] == 0 )//0110 --> -13
    	{
    		Y[k].re = -1;
    		Y[k].im = 3;
		}
    	else if(inseq[i] == 0 && inseq[i+1] == 1 && inseq[i+2] == 1 &&inseq[i+3] == 1 )//0111 -->-33
    	{
    		Y[k].re = -3;
    		Y[k].im = 3;
		}//L2
    	else if(inseq[i] == 0 && inseq[i+1] == 0 && inseq[i+2] == 0 &&inseq[i+3] == 1 )//0001 --> 31
    	{
    		Y[k].re = 3;
    		Y[k].im = 1;
		}
    	else if(inseq[i] == 0 && inseq[i+1] == 0 && inseq[i+2] == 0 &&inseq[i+3] == 0 )//0000 --> 11
    	{
    		Y[k].re = 1;
    		Y[k].im = 1;
		}
    	else if(inseq[i] == 0 && inseq[i+1] == 0 && inseq[i+2] == 1 &&inseq[i+3] == 0 )//0010 --> -11
    	{
    		Y[k].re = -1;
    		Y[k].im = 1;
		}
    	else if(inseq[i] == 0 && inseq[i+1] == 0 && inseq[i+2] == 1 &&inseq[i+3] == 1 )//0011 --> -31
    	{
    		Y[k].re = -3;
    		Y[k].im = 1;
		}//L3
    	else if(inseq[i] == 1 && inseq[i+1] == 0 && inseq[i+2] == 0 &&inseq[i+3] == 1 )//1001 --> 3-1
    	{
    		Y[k].re = 3;
    		Y[k].im = -1;
		}
    	else if(inseq[i] == 1 && inseq[i+1] == 0 && inseq[i+2] == 0 &&inseq[i+3] == 0 )//1000 --> 1-1
    	{
    		Y[k].re = 1;
    		Y[k].im = -1;
		}
    	else if(inseq[i] == 1 && inseq[i+1] == 0 && inseq[i+2] == 1 &&inseq[i+3] == 0 )//1010 --> -1-1
    	{
    		Y[k].re = -1;
    		Y[k].im = -1;
		}
    	else if(inseq[i] == 1 && inseq[i+1] == 0 && inseq[i+2] == 1 &&inseq[i+3] == 1 )//1011 --> -3-1
    	{
    		Y[k].re = -3;
    		Y[k].im = -1;
		}//L4
    	else if(inseq[i] == 1 && inseq[i+1] == 1 && inseq[i+2] == 0 &&inseq[i+3] == 1 )//1101 --> 3-1
    	{
    		Y[k].re = 3;
    		Y[k].im = -3;
		}
    	else if(inseq[i] == 1 && inseq[i+1] == 1 && inseq[i+2] == 0 &&inseq[i+3] == 0 )//1100 --> 1-3
    	{
    		Y[k].re = 1;
    		Y[k].im = -3;
		}
    	else if( inseq[i] == 1 && inseq[i+1] == 1 && inseq[i+2] == 1 && inseq[i+3] == 0 )//1110 --> -1-3
    	{
    		Y[k].re = -1;
    		Y[k].im = -3;
		}
    	else
    	{
    		Y[k].re = -3;
    		Y[k].im = -3;
		}
		
    	k++;
    	i = i+4;

    }
    
////////////////////////////////////////// AWGN generation with u = 0 //////////////////////////////////////////     	
	int Na=10;//number of antennas
	int n_fp = 8;
	struct complNum h[Na][(N/4)];
	struct complNum hconj[Na][(N/4)];
	float norm2[N/4];
	float norm2_h[Na][N/4];
	struct complNum y[Na][(N/4)];
	int noise[Na][N/4];
	int sum[Na] = {0,0};
	int mean[Na];

	for(int i = 0; i < Na; i++)
	{	
		for(int j = 0; j < N/4; j++)
		{
			noise[i][j] =(float)rand()/RAND_MAX*pow(2,n_fp);
			sum[i]=sum[i]+noise[i][j];
		}
		mean[i]=sum[i]/(N/4);
	}
	
	for(int i = 0; i < Na; i++)
		for(int j = 0; j < N/4; j++)
			noise[i][j] =noise[i][j]-mean[i];

////////////////////////////////////////// Noise Modelling //////////////////////////////////////////   

  	for(int i = 0; i < Na; i++)
	{	
		for(int j = 0; j < N/4; j++)
	    {
			h[i][j].re = (float)rand()/RAND_MAX*pow(2,n_fp);
			h[i][j].im = (float)rand()/RAND_MAX*pow(2,n_fp);
			
			hconj[i][j].re = h[i][j].re;
			hconj[i][j].im = -1*h[i][j].im;
			
			y[i][j].re = ((h[i][j].re*Y[j].re) - (h[i][j].im*Y[j].im) + noise[i][j])*pow(2,n_fp);
			y[i][j].im = ((h[i][j].im*Y[j].re) + (h[i][j].re*Y[j].im) + noise[i][j])*pow(2,n_fp);
	    }
	}
	
    //normalising
    for(int i=0; i< Na;i++)
	{
		for(int j=0; j<N/4; j++)
		{
				norm2_h[i][j] = pow(h[i][j].re,2) + pow(h[i][j].im,2);
				norm2_h[i][j] = pow(norm2_h[i][j],0.5);
		}
	}
	
    for(int j=0; j<N/4; j++)
    {
    	norm2[j] = 0;
    	for(int i=0; i<Na; i++)
       	{
		    norm2[j] = norm2[j] + pow(norm2_h[i][j],2);
		}
	}
	
    for(int j=0; j<N/4; j++)
    {
    	op[j].re = 0;
    	op[j].im = 0;
    	for(int i=0; i<Na; i++)
	    {
	    	op[j].re = op[j].re + (float) ((hconj[i][j].re*y[i][j].re) - (hconj[i][j].im*y[i][j].im))/(norm2[j]*pow(2, n_fp));
			op[j].im = op[j].im + (float) ((hconj[i][j].im*y[i][j].re) + (hconj[i][j].re*y[i][j].im))/(norm2[j]*pow(2, n_fp));
		}
	}
	
	
////////////////////////////////////////// 16QAM Demodulation ////////////////////////////////////////// 
	j=0;
	for(int i=0;i<N/4;i++)
	{
		if(op[i].re>2 && op[i].im>2)
		{
			outseq[j]=0;
			outseq[j+1]=1;
			outseq[j+2]=0;
			outseq[j+3]=1;
		}
		else if(op[i].re<2 && op[i].im>2 && op[i].re>0)
		{
			outseq[j]=0;
			outseq[j+1]=1;
			outseq[j+2]=0;
			outseq[j+3]=0;
		}
		
		else if(op[i].im>2 && op[i].re>-2 && op[i].re<0)
		{
			outseq[j]=0;
			outseq[j+1]=1;
			outseq[j+2]=1;
			outseq[j+3]=0;
		}
		
		else if(op[i].im>2 && op[i].re<-2 )
		{
			outseq[j]=0;
			outseq[j+1]=1;
			outseq[j+2]=1;
			outseq[j+3]=1;
		}
		
		else if(op[i].im<2 && op[i].re>2 && op[i].im>0)
		{
			outseq[j]=0;
			outseq[j+1]=0;
			outseq[j+2]=0;
			outseq[j+3]=1;
		}
		
		else if(op[i].im<2 && op[i].re<2 && op[i].re>0 && op[i].im>0)
		{
			outseq[j]=0;
			outseq[j+1]=0;
			outseq[j+2]=0;
			outseq[j+3]=0;
		}
	
		else if(op[i].im<2 && op[i].im>0 && op[i].re<0 && op[i].re>-2)
		{
			outseq[j]=0;
			outseq[j+1]=0;
			outseq[j+2]=1;
			outseq[j+3]=0;
		}
		
		else if(op[i].im<2 && op[i].im>0 && op[i].re<-2)
		{
			outseq[j]=0;
			outseq[j+1]=0;
			outseq[j+2]=1;
			outseq[j+3]=1;
		}
		
		else if(op[i].im<0 && op[i].im>-2 && op[i].re>2 )
		{
			outseq[j]=1;
			outseq[j+1]=0;
			outseq[j+2]=0;
			outseq[j+3]=1;
		}
		
		else if(op[i].im<0 && op[i].im>-2 && op[i].re>0 && op[i].re<2)
		{
			outseq[j]=1;
			outseq[j+1]=0;
			outseq[j+2]=0;
			outseq[j+3]=0;
		}
		
		else if(op[i].im<0 && op[i].im>-2 && op[i].re<0 && op[i].re>-2)
		{
			outseq[j]=1;
			outseq[j+1]=0;
			outseq[j+2]=1;
			outseq[j+3]=0;
		}
		
		else if(op[i].im<0 && op[i].im>-2 && op[i].re<-2)
		{
			outseq[j]=1;
			outseq[j+1]=0;
			outseq[j+2]=1;
			outseq[j+3]=1;
		}
		
		else if(op[i].im<-2 && op[i].re>2 )
		{
			outseq[j]=1;
			outseq[j+1]=1;
			outseq[j+2]=0;
			outseq[j+3]=1;
		}
		
		else if(op[i].im<-2 && op[i].re<2 && op[i].re>0 )
		{
			outseq[j]=1;
			outseq[j+1]=1;
			outseq[j+2]=0;
			outseq[j+3]=0;
		}
		
		else if(op[i].im<-2 && op[i].re>-2 && op[i].re<0)
		{
			outseq[j]=1;
			outseq[j+1]=1;
			outseq[j+2]=1;
			outseq[j+3]=0;
		}
		else if(op[i].im<-2 && op[i].re<-2)
		{
			outseq[j]=1;
			outseq[j+1]=1;
			outseq[j+2]=1;
			outseq[j+3]=1;
		}
		j=j+4;
	}


    int z =0;
    int dec[len];
    for(int j=0; j<len; j++)
    {
    	dec[j] = 0;
    	for (int i=0;i<8;i++)
	    {
	    	dec[j]=dec[j]+outseq[z]*pow(2,(7-i));
	    	z++;
		}	
		
	}
	
	
	char charout[len];
	
	for(int i=0; i<len; i++)
	{
		charout[i]=char(dec[i]-128);
	}
	
	// writing to the file for image
	FILE* fp1  = NULL;

  // Open the source file
  	fp1 = fopen( "ReconCameraman1.bmp", "wb" );
  	if (!fp1) return 0;

	
	////////////////////////////////////////////////// Binary to Decimal Convertor //////////////////////////////////////////////////
  // write the entire file into the buffer
  	if (!fwrite( charout, len, 1, fp1 ))
    {
    	fclose( fp1 );
    	return 0;
    }

  	fclose( fp1 );
  
  //writing to the file for text
   	ofstream QAM_16file;
    QAM_16file.open ("16QAMdata.txt");
    QAM_16file<<"TEXT"<<endl;
    for (int i=0; i<len/4;)
    {
        QAM_16file << Y[i].re<<","<<Y[i].im<<","<<Y[i+1].re<<","<<Y[i+1].im<<endl; 
        i = i + 2;
    }
    QAM_16file.close();
	return 0;

}
