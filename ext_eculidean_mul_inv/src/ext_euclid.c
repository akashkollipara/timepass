#include <stdio.h>

int mod(int a, int b)
{
	int ret = a % b;
	ret = (ret < 0) ? b + ret : ret;
	return ret;
}

int find_mul_inv(int domain, int subject)
{
	int q, r, t1 = 0, t2 = 1, t;
	while(subject)
	{
		q = domain/subject;
		r = domain%subject;
		t = t1 - (q * t2);
		printf("DEBUG: q = %d, n1 = %d, n2 = %d, r = %d, t1 = %d, t2 = %d, t = %d\n", q, domain, subject, r, t1, t2, t);
		domain = subject;
		subject = r;
		t1 = t2;
		t2 = t;
	}
	return t1;
}

int main()
{
	int domain, subject, s_mul_inv;
	printf("Enter Domain: ");
	scanf("%d", &domain);
	printf("Enter Subject: ");
	scanf("%d", &subject);
	s_mul_inv = find_mul_inv(domain, subject);
	s_mul_inv = mod(s_mul_inv, domain);
	printf("Multiplicative inverse of %d in Z(%d) = %d\n", subject, domain, s_mul_inv);
	return 0;
}
