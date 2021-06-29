#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	char ch;
	struct Node *link;
}*top = NULL;				//struct Node *top = NULL

void push(char);
char pop();
bool isForward(char);
bool isBackward(char);
bool closing_brackets(char, char);

void main()
{
	int n;
	char *ch1;
	bool b = true;
	printf("enter no of brackets : \n");
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		ch1 = (char *)malloc(n * sizeof(char));
		printf("enter brackets : \n");
		scanf("%s", ch1);

		for (int i = 0, j = 0; i < n; i++, j++)
		{
			if (isForward(*(ch1 + i)))
				push(*(ch1 + i));

			if (isBackward(*(ch1 + i)))
			{
				char ch2 = pop();

				if (closing_brackets(ch2, *(ch1 + i)))
					j -= 2;

				else
					b = false;
			}
		}

		if (b)
			printf("\nBalanced");
		else
			printf("\nNot balanced");
	}
	else
		printf("\nNot balanced");

	_getch();
}

void push(char ch)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
	{
		printf("Stack overflow \n");
		return;
	}
	temp->ch = ch;
	temp->link = top;
	top = temp;
}

char pop()
{
	char ch;
	if (top == NULL)
	{
		printf("Stack underflow \n");
		return '-';
	}
	struct Node *temp = top;
	ch = top->ch;
	top = top->link;
	free(temp);
	printf("Deleted : %c \n", ch);
	return ch;
}

bool isForward(char ch)
{
	if (ch == '[' || ch == '{' || ch == '(')
		return true;
	else
		return false;
}

bool isBackward(char ch)
{
	if (ch == ']' || ch == '}' || ch == ')')
		return true;
	else
		return false;
}

bool closing_brackets(char ch1, char ch2)
{
	if (ch1 == '[' && ch2 == ']')
		return true;
	else if (ch1 == '{' && ch2 == '}')
		return true;
	else if (ch1 == '(' && ch2 == ')')
		return true;
	else
		return false;
}