//This Project is made to get relation between given Data...
//This Project Made by Dharmik Prajapati(Black Hearted Coder)...
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int i,j,size;
//function to calculate karl pearson's correlation coefficient
void karl();
//function to calculate spearman's rank correlation coefficient
void spearman();
//function to get equestion and correlation coefficient 
void regression();
//function to know which type of relation is this!!!
void relation(float);
//to find probable error...
void probable(float);

int main()
{

    int cho;
    
    printf("Enter Size:");
    scanf("%d",&size);
    printf("\n>1.karl Pearson correlation coefficient\n>2.Spearman's rank correlation coefficient\n>3.Regression coefficient & correlation coefficient\nEnter Your Choise-> ");
    scanf("%d",&cho);
    
    switch(cho)
    {
    	case 1:
    		karl();
    		break;	
    		
    	case 2:
    		spearman();
    		break;
    		
    	case 3:
    		regression();
    		break;
    		
    	default:
    		printf("Please Enter Right Choise...");
	}

    return 0;
}
karl()
{
	float *x,*y,sumofx=0,sumofy=0,sumofone=0,sumoftwo=0,sumofthree=0;

    x = (float *)malloc(size * sizeof(float));
    y = (float *)malloc(size * sizeof(float));
	  
    printf("Please Enter X:\n");
    for (i = 0; i < size; i++)
    {
    	printf("%d : ",i+1);
        scanf("%f", &x[i]);
        sumofx+=x[i];
    }

    printf("Please Enter Y:\n");
    for (i = 0; i < size; i++)
    {
    	printf("%d : ",i+1);
        scanf("%f", &y[i]);
        sumofy+=y[i];
    }
    
    float xbar = sumofx / size;
    float ybar = sumofy / size;
    
    printf("\nSum of xbar : %.4f\nSum of ybar : %.4f\n\n",xbar,ybar);
    
	int t1 =(int) xbar;
    double temp1 = t1 - xbar;
    int t2 =(int) ybar;
    double temp2 =t2- ybar;

    float r;
    if(temp1==0 && temp2==0)
    {
    	printf("x\ty\tx-xbar\ty-ybar\t(x-xbar)^2\t(y-ybar)^2\t(x-xbar)(y-ybar)\n");
    
    	for (i = 0; i < size; i++)
    	{
    		float temp1 = pow((x[i]-xbar),2);
    		sumofone += temp1;
    		float temp2 = pow((y[i]-ybar),2);
    		sumoftwo += temp2;
    		float temp3 = (x[i]-xbar) * (y[i]-ybar);
    		sumofthree += temp3;
      	  printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",x[i],y[i],x[i]-xbar,y[i]-ybar,temp1,temp2,temp3);
   		}
    	printf("\n\nsum of (x-xbar)^2 : %.4f\nsum of (y-ybar)^2 : %.4f\nsum of (x-xbar)(y-ybar) : %.4f",sumofone,sumoftwo,sumofthree);
		r = sumofthree / sqrt(sumofone) / sqrt(sumoftwo);
    	printf("\nRelation is %.5f",r);
	}
    else
    {
    	printf("x\ty\tx^2\ty^2\txy\n");
    	for (i = 0; i < size; i++)
    	{
    		float temp1 = pow(x[i],2);
    		sumofone += temp1;
    		float temp2 = pow(y[i],2);
    		sumoftwo += temp2;
    		float temp3 = x[i] * y[i];
    		sumofthree += temp3;
    		printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",x[i],y[i],temp1,temp2,temp3);
	   	}
	   	printf("\n\nSum of x : %.4f\nSum of y : %.4f\nSum of x^2 : %.4f\nSum of y^2:%.4f\nSum of xy: %.4f\n",sumofx,sumofy,sumofone,sumoftwo,sumofthree);
	   	float r1 = (size * sumofthree) - (sumofx * sumofy);
		float r2 = sqrt(size*sumofone - pow(sumofx,2)) * sqrt(size*sumoftwo - pow(sumofy,2));
		r = r1/r2;
   		printf("\nRelation is %.5f",r);
	}

    relation(r);
    probable(r);
	free(x);
	free(y);
}

spearman()
{
	float *x,*y,*rx,*ry;

    x = (float *)malloc(size * sizeof(float));
    y = (float *)malloc(size * sizeof(float));
	rx = (float *)malloc(size * sizeof(float));
	ry = (float *)malloc(size * sizeof(float));

    printf("Please Enter X:\n");
    for (i = 0; i < size; i++)
    {
    	printf("%d : ",i+1);
        scanf("%f", &x[i]);
    }

    printf("Please Enter Y:\n");
    for (i = 0; i < size; i++)
    {
    	printf("%d : ",i+1);
        scanf("%f", &y[i]);
    }

	int d=1;
    for(i=0;i<size;i++)
    {
    	float t1=1,t2=1,t3=1,t4=1;
		for(j=0;j<size;j++)
    	{
    		if(j!=i && x[j] < x[i])
    			t1++;
    		if(j!=i && x[j] == x[i])
    		{
    			t2++;
    			d++;
			}
    			
    		if(j!=i && y[j] < y[i])
    			t3++;
    		if(j!=i && y[j] == y[i])
    		{
    			t4++;
    			d++;
			}
		}
		rx[i] = t1 + (t2-1) / 2.00;
		ry[i] = t3 + (t4-1) / 2.00;
	}
	float sumofdi2=0;
	printf("\nx\ty\trx\try\td\td^2\n");
	for(i=0;i<size;i++)
	{
		float d[size];
		d[i]=rx[i]-ry[i];
		sumofdi2+=pow(d[i],2);
		printf("%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n",x[i],y[i],rx[i],ry[i],d[i],pow(d[i],2));
	}
	printf("\nsum of di^2 : %.4f",sumofdi2);
	
	if(d==1)
	{
		float r = 1 - ((6 * sumofdi2)/(size*(pow(size,2)-1)));
		printf("\n\nRelation r = %f",r);
		relation(r);
	}
	else
	{
		int *m = (int *)malloc(size * sizeof(int));
		int temp = 0;
		for (i = 0; i < size; ++i)
		{
        	int count = 1;
        	for (j = i + 1; j < size; ++j)
			{
            	if (x[i] == x[j])
				{
                	count++;
                	x[j] = -1;
            	}
        	}
       		if (count > 1 && x[i] != -1)
			{
            	m[temp] = count;
            	temp++;
        	}
   		}
    
    	for (i = 0; i < size; ++i)
		{
        	int count = 1;
        	for (j = i + 1; j < size; ++j)
			{
            	if (y[i] == y[j])
				{
                	count++;
                	y[j] = -1;
            	}
        	}
        	if (count > 1 && y[i] != -1)
			{
            	m[temp] = count;
            	temp++;
        	}
    	}
		
		printf("\n\nm:\t");
		
		for(i=0;i<temp;i++)
			printf("%d\t",m[i]);

		float cf=0;
		for(i=0;i<temp;i++)
		{
			float sumofm = (pow(m[i],3)-m[i])/12;
			cf +=sumofm;
		}
		printf("\n\ncf = %.4f",cf);
		
		float r = 1 - ((6 * (sumofdi2 + cf)) / (size * (pow(size,2)-1)));
		printf("\n\nRelation r = %f",r);
		relation(r);
		free(m);
	}
	
	free(x);
	free(y);
}
regression()
{
	float *x,*y,sumofx=0,sumofy=0,sumofone=0,sumoftwo=0,sumofthree=0;

    x = (float *)malloc(size * sizeof(float));
    y = (float *)malloc(size * sizeof(float));
	  
    printf("Please Enter X:\n");
    for (i = 0; i < size; i++)
    {
    	printf("%d : ",i+1);
        scanf("%f", &x[i]);
        sumofx+=x[i];
    }

    printf("Please Enter Y:\n");
    for (i = 0; i < size; i++)
    {
    	printf("%d : ",i+1);
        scanf("%f", &y[i]);
        sumofy+=y[i];
    }
    
    float xbar = sumofx / size;
    float ybar = sumofy / size;
    
    printf("\nSum of xbar : %.4f\nSum of ybar : %.4f\n\n",xbar,ybar);
    
	int t1 =(int) xbar;
    double temp1 = t1 - xbar;
    int t2 =(int) ybar;
    double temp2 =t2- ybar;

    float byx,bxy;
    if(temp1==0 && temp2==0)
    {
    	printf("x\ty\tx-xbar\ty-ybar\t(x-xbar)^2\t(y-ybar)^2\t(x-xbar)(y-ybar)\n");
    
    	for (i = 0; i < size; i++)
    	{
    		float temp1 = pow((x[i]-xbar),2);
    		sumofone += temp1;
    		float temp2 = pow((y[i]-ybar),2);
    		sumoftwo += temp2;
    		float temp3 = (x[i]-xbar) * (y[i]-ybar);
    		sumofthree += temp3;
      	  printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",x[i],y[i],x[i]-xbar,y[i]-ybar,temp1,temp2,temp3);
   		}
    	printf("\n\nsum of (x-xbar)^2 : %.4f\nsum of (y-ybar)^2 : %.4f\nsum of (x-xbar)(y-ybar) : %.4f",sumofone,sumoftwo,sumofthree);
		
		byx = sumofthree / sumofone;
    	printf("\nbyx = %.5f",byx);
    	
    	bxy = sumofthree / sumoftwo;
    	printf("\nbxy = %.5f",bxy);
    		
   		float r = sqrt(byx*bxy);
   		printf("\n\nCoefficient r = %.5f",r);
   		relation(r);
   		
   		printf("\n\nRegression line of y on x");
   		float temp1 = ((-1) * byx* xbar) + ybar;
   		printf("\ny = (%.5f)x + (%.5f)",byx,temp1);
   		
   		printf("\n\nRegression line of x on y");
   		float temp2 = ((-1) * bxy* ybar) + xbar;
   		printf("\nx = (%.5f)y + (%.5f)",bxy,temp2);
	}
    else
    {
    	printf("x\ty\tx^2\ty^2\txy\n");
    	for (i = 0; i < size; i++)
    	{
    		float temp1 = pow(x[i],2);
    		sumofone += temp1;
    		float temp2 = pow(y[i],2);
    		sumoftwo += temp2;
    		float temp3 = x[i] * y[i];
    		sumofthree += temp3;
    		printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",x[i],y[i],temp1,temp2,temp3);
	   	}
	   	printf("\n\nSum of x^2 : %.4f\nSum of y^2:%.4f\nSum of xy: %.4f\n",sumofone,sumoftwo,sumofthree);
	   	float r1 = (size * sumofthree) - (sumofx * sumofy);
		float r2 = (size*sumofone) - (pow(sumofx,2));
		float r3 = (size*sumoftwo) - (pow(sumofy,2));
		byx = r1/r2;
		bxy = r1/r3;
		
   		printf("\nbyx = %.5f",byx);
   		printf("\nbxy = %.5f",bxy);
   		
   		float r = sqrt(byx*bxy);
   		printf("\n\nCoefficient r = %.5f",r);
   		relation(r);
   		
   		printf("\n\nRegression line of y on x");
   		float temp1 = ((-1) * byx* xbar) + ybar;
   		printf("\ny = (%.5f)x + (%.5f)",byx,temp1);
   		
   		printf("\n\nRegression line of x on y");
   		float temp2 = ((-1) * bxy* ybar) + xbar;
   		printf("\nx = (%.5f)y + (%.5f)",bxy,temp2);
	}
	free(x);
	free(y);
}
relation(float r)
{
	if(r==1)
		printf("\nThe Relation is Perfect Positive Correlation...");
	else if(r==-1)
		printf("\nThe Relation is Perfect Negative Correlation...");
	else if(r>0 && r<1)
		printf("\nThe Relation is Positive Correlation...");
	else if(r<0 && r>-1)
		printf("\nThe Relation is Negative Correlation...");
	else
		printf("\nThe Relation is Not Possible Please Recheck Data...");
}
probable(float r)
{
	float pe = 0.6745 * (1-pow(r,2)) / sqrt(size);
	printf("\nProbable Error(P.E) : %.5f",pe);
}
