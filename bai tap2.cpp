#include <stdio.h>
#define PI 3.1415

int main()
{
	float daylon = 50, daybe = 23, chieucao = 30, chuvibonhoa = 12.56;
	float dientichsantruong = (daylon + daybe)*(chieucao / 2);
	float dientichbonhoa = PI * (chuvibonhoa / (2*PI) ) * (chuvibonhoa / (2*PI) );
	float dientichconlai = dientichsantruong - dientichbonhoa;
	printf("Dien tich con lai cua san truong la: %.2f\n", dientichconlai);
	return 0;
}		
