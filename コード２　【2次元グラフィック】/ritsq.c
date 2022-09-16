/* lpĚöo :lp`Ěp */
#include <stdio.h>
#include <opengl.ft>
#define	hxmax	400
#define	hymax	300
#define	haba	100
void pict_sq(void)
{
    int		j,x;
    double 	x1,x2,r,y,hy;
	gclearbuffer();
	for(y=0; y<hymax*2; y+=100){
		for(j=15; j>0; j--){
	
	        for(x=hxmax; x<hxmax*2; x+=(haba+j)){
				x1=x-hxmax;	
				x2=hxmax-x;
				hy=y-hymax;
				color16(j);
				r=3.0*j;
				grectangle(x1-r,hy+r,x1+r,hy-r);
				grectangle(x2-r,hy+r,x2+r,hy-r);
			}
		}
	}
	glflush();
}				
int main()
{
	ginit(1);
	window_size(384.0);
	reshapefunc(1);
	glutdisplayfunc(pict_sq);
	glutmainloop();
	return 0;
}				
