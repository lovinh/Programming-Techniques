// Giai va bien luan ax^4 + bx^2 + c = 0
//t = x^2 ==> at^2 + bt + c = 0 (t >= 0)
#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c;
    float t;
    printf("Nhap a, b, c: "); scanf("%f %f %f", &a, &b, &c);
    printf("a = %f\tb = %f\tc = %f\n", a, b, c);
    if (a == 0)
    {
    	if (b == 0)
    	{
    		if (c == 0)
    			printf("Phuong trinh vo so nghiem!\n");
    		else 
    			printf("Phuong trinh vo nghiem\n");
		} else
		{
			if ((-c/b) < 0)
			{
				printf("Phuong trinh vo nghiem\n");
			} else
			{
				printf("t1 = %f\nt2 = %f\n", sqrt(-c/b), -sqrt(-c/b));
			}
		}
	} else
	{
		float D = b * b - 4 * a * c;
		if (D < 0)
		{
			printf("Phuong trinh vo nghiem!\n");
		} else if (D == 0) 
		{
			t = -b / (2 * a);
			if (t < 0)
				printf("Phuong trinh vo nghiem!\n");
			else
				printf("Phuong trinh co 2 nghiem:\nx1 = %f\nx2 = %f\n", sqrt(t), -sqrt(t));
	
		} else
		{
			float t1 = (-b + sqrt(D)) / (2 * a);
			float t2 = (-b - sqrt(D)) / (2 * a);
			if (t1 >= 0 || t2 >= 0)
			{
				printf("Phuong trinh co nghiem: \n");
				if (t1 >= 0)
				{
					printf("x1 = %f\nx2 = %f\n", sqrt(t1), -sqrt(t1));
				}
				if (t2 >= 0)
				{
					printf("x1 = %f\nx2 = %f\n", sqrt(t2), -sqrt(t2));
				}
			}
			else 
			{
				printf("Phuong trinh vo nghiem!\n");
			}
		}
	}
    return 0;
}
