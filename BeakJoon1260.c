#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 1001

int DFSvisit[MAX_VERTICES] = { 0 };
int BFSvisit[MAX_VERTICES] = { 0 };
int queueArray[MAX_VERTICES] = { 0 };

typedef struct LinkedlistNode
{
	int vertex;                       //���� ��ȣ
	struct LinkedlistNode* plink;     //����� ��ũ �� �� ��带 ����Ű�� ������                    
} LinkedlistNode;

typedef struct Linkedlist
{
	int vertexCount;                  //������ ����(���� ����Ʈ�� ����)
	LinkedlistNode* adj_list[MAX_VERTICES];  //���� ����� ������ �迭
} Linkedlist;

Linkedlist* createLinkedlist(int n)
{
	Linkedlist* pReturn = NULL;

	if (n > 0)
	{
		pReturn = (Linkedlist*)calloc(1,sizeof(Linkedlist));
		pReturn->vertexCount = n;
	}

	return pReturn;
}

void makeNode(int from, int to, Linkedlist* plist, LinkedlistNode* newNode)
{
	LinkedlistNode* pNode = NULL;
	LinkedlistNode* pPreNode = NULL;
	
	if (from >= 1 && plist != NULL)
	{
		pNode = plist->adj_list[from];
		newNode->plink = NULL;
		newNode->vertex = to;
		
		if (pNode == NULL)                         //�ش� ������ ������ ������ ���� ���
		{
			plist->adj_list[from] = newNode;
			pNode = newNode;
		}
	
	    else
		{
			if (newNode->vertex <= pNode->vertex)  //���ο� ������ ���� �� ���� ���
			{
				newNode->plink = pNode;
				plist->adj_list[from] = newNode;
			}
			
			else                                   //���ο� ������ ���� �� ū ���
			{	
				while (pNode != NULL)
				{
					if (newNode->vertex > pNode->vertex)
					{
						pPreNode = pNode;
						pNode = pNode->plink;
					}

					else
					{
						newNode->plink = pNode;
						pPreNode->plink = newNode;
					}
				}
            }
		}
	}

	else
	{
		if (from < 1)    printf("������ 0���� ū �����Դϴ�.\n");
		else       printf("��ȿ���� ���� ����Ʈ�Դϴ�.\n");
	}
}



void DFS(int vertex, Linkedlist* plist)
{
    DFSvisit[vertex] = 1;
	printf("%d ", vertex);

	LinkedlistNode* pNode = plist->adj_list[vertex];
	while (pNode != NULL)
	{
		if (DFSvisit[pNode->vertex] == 0)
			DFS(pNode->vertex, plist);
		else
		    pNode = pNode->plink;
	}
}

void BFS(int vertex, Linkedlist* plist)
{
	int front = 1;
	int rear = 1;
	
	BFSvisit[vertex] = 1;
	printf("%d ", vertex);
	queueArray[front] = vertex;
	rear++;

	while (front < rear)
	{
		LinkedlistNode* pNode = plist->adj_list[front];
		while (pNode != NULL)
		{
			if (BFSvisit[pNode->vertex] == 0)
			{
				BFSvisit[pNode->vertex] = 1;
				printf("%d ", pNode->vertex);
				queueArray[rear++] = pNode->vertex;
			}

			else;
            pNode = pNode->plink;
		}
        front++;
	}
}

int main(int argc, char* argv[])
{
	int vertexCount, lineCount, start;
	scanf("%d %d %d", &vertexCount, &lineCount, &start);

	Linkedlist* plist = createLinkedlist(vertexCount);

	int from, to;
	LinkedlistNode* newNode;
	for (int i = 0; i < lineCount; i++)
	{
		scanf("%d %d", &from, &to);
		newNode = (LinkedlistNode*)malloc(sizeof(LinkedlistNode));
		makeNode(from, to, plist, newNode);
	}

	DFS(start, plist);
	printf("\n");
	BFS(start, plist);

	return 0;
}