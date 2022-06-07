#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getname(char*);
struct node* addlist(struct  node*, char*);
char* namecopy(char*);
void listprint(struct node*);
struct node* invert(struct node*);

struct node
{
	char* name;
	struct node* link;
};


void struct_main(void)
{
	struct node* root = NULL;
	char name[80] = "";

	while (getname(name) != EOF)
	{
		root = addlist(root, name);
	}
	listprint(root);

	root = invert(root);
	printf("----- invert -----\n");
	listprint(root);

}

int getname(char* pname)
{
	int i = 0;
	char c = "";

	while (((c = getchar()) != '\n') && c != EOF)
	{
		*(pname + i++) = c;
	}
	if (c == '\n')
	{
		*(pname + i) = '\n';
	}
	if (c == EOF)
	{
		*pname = EOF;
	}
	return *pname;
}

struct node* addlist(struct node* p, char* w)
{
	if (p == NULL)
	{
		p = (struct node*)malloc(sizeof(struct node));
		p->name = namecopy(w);
		p->link = NULL;
	}
	else
	{
		p->link = addlist(p->link, w);
	}
	return p;
}

char* namecopy(char* str)
{
	char* name = "";
	int i = 0;
	name = (char*)malloc(strlen(str) + 1);

	while ((*(name + i) = *(str + i)) != '\n')
	{
		i++;
	}
	return name;
}

void listprint(struct node* p)
{
	while (p != NULL)
	{
		printf("%s\n", p->name);
		p = p->link;
	}
}

struct node* invert(struct node* lead)
{
	struct node* trail;
	struct node* middle = NULL;
	
	while (lead != NULL)
	{
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}

	return middle;
}