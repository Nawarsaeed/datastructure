#include<stdio.h>
#define MAX 20

int a[20][20];   //adjacency
int stack[20];
int top=-1;
int visit[20];
int n;


void push(int x)
{
	if(top==n-1)
		printf("Overflow");
	else
	{
		top++;
		stack[top]=x;
	}
}

int pop()
{
	if(top==-1)
		return -1;
	else
		return(stack[top--]);
}

void dfs(int s)
{
	int i;
	push(s);
	visit[s]=1;
	while(top!=-1)
	{
		s=pop();
		printf("%c-",s+65);
		for(i=0;i<n;i++)
		{
			if(a[s][i] && visit[i]==0 )
			{
				push(i);
				visit[i]=1;
			}
		}

	}


}


int main()
{
int i,j,s;
printf("Enter no of nodes:");
scanf("%d",&n);

for(i=0;i<n;i++)
	visit[i]=0;

printf("Enter adjacency");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("is %d adjacent to %d",i,j);
		scanf("%d",&a[i][j]);
	}
}

printf("Adjacency matrix is:");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d",a[i][j]);
	}
printf("\n");
}


printf("\nEnter source");
scanf("%d",&s);

dfs(s);



}
