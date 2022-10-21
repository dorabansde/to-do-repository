#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct AC
{
	int data;
	struct AC *Rlink;
	struct AC *Llink;
}AC;

AC *front = NULL;
AC *back = NULL;

void push(int D)
{
	AC *temp = (AC*)malloc(sizeof(AC));
	temp->data = D;
	temp->Llink = NULL;
	temp->Rlink = NULL;

	if (front == NULL && back == NULL)
	{
		back = front = temp;
	}
	else
	{
		temp->Rlink = front;
		front->Llink = temp;
		front = temp;
	}
}

void front_pop()
{
	AC *t = front;
	front = front->Rlink;

	if (t == back)
	{
		free(t);
	}
	else
	{
		t->Rlink = front->Llink = NULL;
		free(t);
	}

	if (front == NULL)
	{
		back = NULL;
	}
}

void back_pop()
{
	AC *t = back;
	back = back->Llink;

	if (front == t)
	{
		free(t);
	}
	else
	{
		t->Llink = back->Rlink = NULL;
		free(t);
	}

	if (back == NULL)
	{
		front = NULL;
	}
}

int main()
{
	int T, n, x, flag, i, j, k, u;
	char p[100], temp[100];

	scanf("%d", &T);	// 처음값 T

	for (i = 0; i < T; i++)
	{
		flag = 0;
		front = NULL;
		back = NULL;

		scanf("%s", &p);	// p값

		scanf("%d\n", &n);	// n값

		for (j = 0; j < n; j++)
		{
			scanf("%c%d", &temp, &x);	// 배열x 값
			push(x);
		}
		scanf("%s", &temp); // 배열x 마지막값 ']'

		for (u = 0; u < strlen(p); u++)
		{
			if (p[u] == 'R')
				flag = !flag;
			else if (p[u] == 'D')
			{
				if (flag == 1 && front != NULL && back != NULL)
					front_pop();
				else if (flag == 0 && front != NULL && back != NULL)
					back_pop();
				else if (front == back)
					printf("error");
			}
		}

		if (flag == 1)
		{
			AC *f = front;
			while (f != NULL)
			{
				AC *ftemp = f;
				if (f == back)
				{
					printf("%d]", f->data);
					f = f->Rlink;
					free(ftemp);
				}
				else if (f == front)
				{
					printf("[%d,", f->data);
					f = f->Rlink;
					free(ftemp);
				}
				else
				{
					printf("%d,", f->data);
					f = f->Rlink;
					free(ftemp);
				}
			}
			printf("\n");
		}

		else if (flag == 0)
		{
			AC *b = back;
			while (b != NULL)
			{
				AC *btemp = b;
				if (b == front)
				{
					printf("%d]", b->data);
					b = b->Llink;
					free(btemp);
				}
				else if (b == back)
				{
					printf("[%d,", b->data);
					b = b->Llink;
					free(btemp);
				}
				else
				{
					printf("%d,", b->data);
					b = b->Llink;
					free(btemp);
				}
			}
			printf("\n");
			flag = 0;
		}
	}
	return 0;
}