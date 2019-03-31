#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 1001

int DFSvisit[MAX_VERTICES] = { 0 };
int BFSvisit[MAX_VERTICES] = { 0 };
int queueArray[MAX_VERTICES] = { 0 };

typedef struct LinkedlistNode
{
	int vertex;                       //정점 번호
	struct LinkedlistNode* plink;     //양방향 링크 중 뒷 노드를 가리키는 포인터                    
} LinkedlistNode;

typedef struct Linkedlist
{
	int vertexCount;                  //정점의 갯수(연결 리스트의 갯수)
	LinkedlistNode* adj_list[MAX_VERTICES];  //정점 노드의 포인터 배열
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
		
		if (pNode == NULL)                         //해당 정점에 인접한 정점이 없는 경우
		{
			plist->adj_list[from] = newNode;
			pNode = newNode;
		}
	
	    else
		{
			if (newNode->vertex <= pNode->vertex)  //새로운 정점의 값이 더 작은 경우
			{
				newNode->plink = pNode;
				plist->adj_list[from] = newNode;
			}
			
			else                                   //새로운 정점의 값이 더 큰 경우
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
		if (from < 1)    printf("정점은 0보다 큰 정수입니다.\n");
		else       printf("유효하지 않은 리스트입니다.\n");
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