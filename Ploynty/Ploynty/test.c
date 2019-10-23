#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float coef;
	int exp;
	struct node *next;
}nodetype,*polyty;

/*以尾插法创建有m项的多项式单链表*/
polyty CreatePolyn(int m)
{
	polyty head  = (nodetype*)malloc(sizeof(nodetype));
	head->next = NULL;
	nodetype *r = head;//初始化
	nodetype *pa = NULL;
	int k = 0;
	float coef = 0;
	int exp = 0;
	for (k = 0; k < m; k++)
	{
		scanf("%f,%d", &coef, &exp);//输入系数指数
		pa = (nodetype*)malloc(sizeof(nodetype));//申请空间
		//构造节点
		pa->coef = coef;
		pa->exp = exp;
		//插入节点
		r->next = pa;
		r = pa;
	}
	r->next = NULL;
	return head;
}

//输出多项式

void PrintPolyn(polyty head)
{
	nodetype *pt = head->next;
	printf("\n The polynomial is: \n");
	while (pt != NULL)
	{
		if (pt->exp > 1)
			printf("%.2fX^%d", pt->coef, pt->exp);
		else if (pt->exp == 1)
			printf("%.2fX", pt->coef);
		else
			printf("%.2f", pt->coef);
		if (pt->next != NULL)
			printf("+");
		pt = pt->next;
	}
}

void AddPolyn(polyty la, polyty lb)
{
	nodetype *a = la->next;
	nodetype *b = lb->next;
	nodetype *c = la;
	nodetype *temp = NULL;
	float sum = 0.0; 

	while (a != NULL && b != NULL)
	{
		if (a->exp < b->exp)
		{
			c->next = a;
			c = a;
			a = a->next;
		}
		else if (a->exp == b->exp)
		{
			sum = a->coef + b->coef;
			//和系数不为0，则修改多项式a的该项系数，
			//将la的节点加入多项式，释放lb中该项的结点
			if (sum != 0)
			{
				a->coef = sum;
				c->next = a;
				c = a;
				a = a->next;
				temp = b;
				b = b->next;
				free(temp);
				temp = NULL;
			}
			//和系数为0，则将 la，lb中表示该项的节点都删除掉
			else
			{
				temp = a;
				a = a->next; 
				free(temp);
				temp = b;
				b = b->next;
				free(temp);
				temp = NULL;
			}
		}
		else
		{
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	/*多项式A中还有剩余，则将剩余的结点加入到和多项式；
	否则加入B的节点*/
	if (a != NULL)
		c->next = a;
	else
		c->next = b;
}

int main()
{
	int m = 0;
	printf("创建有m项的多项式\n");
	scanf("%d", &m);
	polyty psla = CreatePolyn(m);   //创建多项式a
	PrintPolyn(psla);
	polyty pslb = CreatePolyn(m);   //创建多项式b
	PrintPolyn(pslb);
	AddPolyn(psla, pslb);
	PrintPolyn(psla);
	return 0;
}
