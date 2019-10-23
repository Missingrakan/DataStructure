#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float coef;
	int exp;
	struct node *next;
}nodetype,*polyty;

/*��β�巨������m��Ķ���ʽ������*/
polyty CreatePolyn(int m)
{
	polyty head  = (nodetype*)malloc(sizeof(nodetype));
	head->next = NULL;
	nodetype *r = head;//��ʼ��
	nodetype *pa = NULL;
	int k = 0;
	float coef = 0;
	int exp = 0;
	for (k = 0; k < m; k++)
	{
		scanf("%f,%d", &coef, &exp);//����ϵ��ָ��
		pa = (nodetype*)malloc(sizeof(nodetype));//����ռ�
		//����ڵ�
		pa->coef = coef;
		pa->exp = exp;
		//����ڵ�
		r->next = pa;
		r = pa;
	}
	r->next = NULL;
	return head;
}

//�������ʽ

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
			//��ϵ����Ϊ0�����޸Ķ���ʽa�ĸ���ϵ����
			//��la�Ľڵ�������ʽ���ͷ�lb�и���Ľ��
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
			//��ϵ��Ϊ0���� la��lb�б�ʾ����Ľڵ㶼ɾ����
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
	/*����ʽA�л���ʣ�࣬��ʣ��Ľ����뵽�Ͷ���ʽ��
	�������B�Ľڵ�*/
	if (a != NULL)
		c->next = a;
	else
		c->next = b;
}

int main()
{
	int m = 0;
	printf("������m��Ķ���ʽ\n");
	scanf("%d", &m);
	polyty psla = CreatePolyn(m);   //��������ʽa
	PrintPolyn(psla);
	polyty pslb = CreatePolyn(m);   //��������ʽb
	PrintPolyn(pslb);
	AddPolyn(psla, pslb);
	PrintPolyn(psla);
	return 0;
}
