#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

#define MAX_VERTICES 50
typedef int element;

typedef struct{
 element queue[MAX_QUEUE_SIZE];
  int front,int rear;
}QueueType;

void error(char *message){
  fprintf(stderr,"%s\n",message);
  exit(1);
}
//큐 초기화
void queue_init(QueueType *q){
  q->front=q->rear=0;
}
int is_empty(QueueType *q){
  
 return (q->front==q->rear); 
}
int is_full(QueueType *q){
 return ((q->rear+1) %MAX_QUEUE_SIZE ==q->front);
  
}

void enqeue(QueueType *q,element item){
 if(is_full(q){
  error("큐 포화상태");
 }
 q->rear=(q->rear+1) %MAX_QUEUE_SIZE;
 q->queue[q->rear] =item;
}
element dequeue(QueueType *q){
  if(is_empty(q))
    error("큐 공백상태");
  q->front=(q->front+1)%MAX_QUEUE_SIZE;
  return q->queue[q->front];
}
   
//여기서부터 그래프
    
typedef struct Graph{
  int n;
  int adj[MAX_VERTICES][MAX_VERTICES];
}Graph;
int visited[MAX_VERTICES];
    
//그래프 초기화    
void init_graph(Graph *g){
  int r,c;
  g->n=0;
  for(r=0;r<MAX_VERTICES;r++)
    for(c=0;c<MAX_VERTICES;c++)
      g->adg[r][c]=0;
}
//정점 추가  
void insert_vertex(Graph *g,int v){
  if((g->n)+1 >MAX_VERTICES){
    fprintf(stderr,"그래프 정점 갯수 초과");
    return;
  }
  g->n++;
}

//간선 삽입
void insert_edge(Graph *g,int start,int end){
  if(start>=g->n || end>=g->n){
    fprintf(stderr,"그래프 정점 번호 오류");
    return;
  }
  g->adj[start][end]=1;
  g->adj[end][start]=1;
}
    
void bfs(Graph *g,int v){
  
  int w;
  QueueType q;
  
  queue_init(&q);
  visited[v]=TRUE;
  printf("%d 방문 -> ", v);
  enqueue(&q,v);
  while(!is_empty(&q)){
    v=dequeue(&q);
    for(w-0;w<g->n;w++)
      if(g->adj[v][w] &&!visited[w]){
        visited[w]=TRUE;
        printf("%d 방문->",ㅈ);
        enequeue(&q,w);
      }
  }
}
    
    
  






  
