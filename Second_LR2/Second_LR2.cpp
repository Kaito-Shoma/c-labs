#include <stdio.h>
#include <math.h>
#include <locale.h>

const float E = 0.0001;
float Radians(int degrees)
{
	float rads;
	int twopi = 360;
	if (degrees % twopi == 0)
	{
		return 0;
	}
	if (degrees >= twopi && degrees > 0)
	{
		while (degrees >= twopi)
		{
			degrees -= twopi;
		}
	}

	else if (degrees < 0 && degrees < -twopi)
	{
		while (degrees < -twopi)
		{
			degrees += twopi;
		}
	}

	rads = 3.14 / twopi * degrees;
	return rads;
}

int func(float x, int n, float res)
{
	int fact = 1;

	for (int i = 1; i <= 2 * n + 1; i++)
	{
		fact *= i;
	}
	res += pow(-1, n) * pow(x, (double)2 * n + 1) / fact;
	printf("\niteration = %d;  %g\n", n, res);

	if (fabs(sin(x) - res) < E)
	{
		return n;
	}

	func(x, n + 1, res);

}

float check()
{
	float a;
	while (!scanf_s("%f", &a))
	{
		rewind(stdin);
		printf("Incorrect input. Try again: ");
	}
	return a;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	printf("Enter x: ");
	float x = check();

	float rad = Radians(x);
	printf("\nsin(%.1f) = %f", x, sin(rad));
	func(Radians(x), 0, 0);
}

