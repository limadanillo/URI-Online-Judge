#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <ctime>
#include <list>
using namespace std;

int ans[10000];

struct node {
    int info;
    node *next;
};

class Queue {
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        void display();

};

void Queue::display(){
    node *p = new node;
    p = front;
    if(front == NULL){
        cout<<"\nNothing to Display\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
}

Queue::Queue() {
    front = NULL;
    rear = NULL;
}

Queue::~Queue() {
    delete front;
}

void Queue::enqueue(int data) {
    node *temp = new node();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
    rear = temp;
}

int Queue::dequeue() {
    node *temp = new node();
    int value;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
}

bool Queue::isEmpty() {
    return (front == NULL);
}

class Graph {
    private:
        int n; /// n is the number of vertices in the graph
        int **A; /// A stores the edges between two vertices
    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int u, int v, bool flag);
        void subEdge(int u, int v);
        void BFS(int );
        int resultado(int v);
        int sizeGraph();
};

Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}
int Graph::sizeGraph() {
    return n;
}

Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}


bool Graph::isConnected(int u, int v) {
    return (A[u-1][v-1] == 1);
}

void Graph::addEdge(int u, int v, bool flag) {
    if(flag){
        A[u-1][v-1] = A[v-1][u-1] = 1;
        //cout<<"\n true add: "<<u <<v<<"...\n";
    }else{
        //cout<<"\n false add: "<<u <<v<<"...\n";
        A[u-1][v-1] = 1;
        A[v-1][u-1] = 0;
    }

}


void Graph::subEdge(int u, int v) {
    A[u-1][v-1] = A[v-1][u-1] = 0;
}

void Graph::BFS(int s) {

    Queue Q;

    bool *explored = new bool[n+1];
    int soma = 0, aux = 0;


    //cout<<"\nfor (int w = 1; i <= n; ++i)";
    for (int i = 1; i <= n; ++i)
    explored[i] = false;
    //cout<<"\n explored[i] = false;";

    Q.enqueue(s);
    explored[s] = true; /** mark it as explored */


    while (!Q.isEmpty()) {
        //cout<<"\n While";

        int v = Q.dequeue();
      	//cout<<"\n V: "<< v;
        for (int w = 1; w <= n; ++w)

            if (isConnected(v, w) && !explored[w]) {
            aux = w;
            //cout<<"\n É conectado V e W "<< v<<" " << w;
                Q.enqueue(w);
                explored[w] = true;
                soma++;
                ans[w] = 1;
             //cout<<"\n soma:"<<soma;

            }


    }
    /*int sizeGrafo;
    sizeGrafo = sizeGraph() -1;
    if(soma != sizeGrafo ){
            //cout<<"\n sizeGraph"<<sizeGraph();
            return false;
        }*/

    delete [] explored;

    //cout<<"\n Return soma:"<<soma;
    //cout<<"\n sizeGraph"<<sizeGraph();
    //return true;
}



int main() {

    bool resultado;
    int m, n, v1, v2, mao, t;
    int i, k;
    Graph grafo;

    cin >>t; //numbers of test
    for(k=0; k<t; k++) {
            //cout << "Antes do grafo(n)\n";
            memset ( ans, 0, sizeof ( ans ) );

            cin >>n;//arestas
            cin >>m;//vertices
            Graph grafo(n);

             for ( i=1; i<=m; i++ ) {
                cin >>v1 >>v2;

                grafo.addEdge(v1, v2, true);
             }

        int aux = k + 1;
        printf ( "Caso #%d: ", aux );

        int pizza = -1;
		for (int i=1; i<=n; i++){

            if (ans[i] == 0){
                grafo.BFS(i);
				pizza++;
			}
		}

        if (pizza >= 1 ) printf ( "ainda falta(m) %d estrada(s)", pizza );
        else printf ( "a promessa foi cumprida" );
        puts ( "" );
    }
    return 0;

}
