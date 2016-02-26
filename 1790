#include <iostream>
#include <ctime>
#include <list>
using namespace std;


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
        void addEdge(int u, int v);
        void subEdge(int u, int v);
        int BFS(int );
        int resultado(int v);
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

Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}


bool Graph::isConnected(int u, int v) {
    return (A[u-1][v-1] == 1);
}

void Graph::addEdge(int u, int v) {
    A[u-1][v-1] = A[v-1][u-1] = 1;
}


void Graph::subEdge(int u, int v) {
    A[u-1][v-1] = A[v-1][u-1] = 0;
}

int Graph::BFS(int s) {
    Queue Q;

    bool *explored = new bool[n+1];
    int soma = 0;


    for (int i = 1; i <= n; ++i)
    explored[i] = false;
	//cout<<"\nBFS de S: "<<s;
    Q.enqueue(s);
    explored[s] = true; /** mark it as explored */
	

    while (!Q.isEmpty()) {

        int v = Q.dequeue();
		//cout<<"\n V : "<<v;
        for (int w = 1; w <= n; ++w)

				
            if (isConnected(v, w) && !explored[w]) {
           	//cout<<"\nExplorando V  e  W: "<<v<<w;
                Q.enqueue(w);
                explored[w] = true;
                soma++;
            

            }
    }

    delete [] explored;

    
    return soma;
}

int Graph::resultado(int v)
{
    int contador = 1;
    int retornoDfsAntesSub = 0, resultado = 0,retornoDfsDepoisSub = 0;


    while(contador <= n)
    {

       for (int w = 1; w <= n; w++)
        {
         //cout<<"\n Contador  e  W: "<<contador<<w;
            if (isConnected(contador, w)){

                if(w < contador && isConnected(contador, w) ){// (1,2) e (2,1)
                //	cout<<"\n Vazio\n";
                   
                }else{

                    retornoDfsAntesSub = BFS(contador);
                   // cout<<"\n  retornoDfsAntesSub\n"<<retornoDfsAntesSub;
                    subEdge(contador , w );//retira a aresta(vertice1, vertice2)

                    retornoDfsDepoisSub = BFS(contador); //Inicia a busca em profundidade dfs(vertice)
                   // cout<<"\n  retornoDfsDepoisSub \n"<<retornoDfsAntesSub;
                    addEdge(contador , w );//adicona a aresta que foi retirada (vertice1, vertice2)
				//	cout<<"\n  retornoDfsAntesSub "<<retornoDfsAntesSub;

                    if(retornoDfsAntesSub != retornoDfsDepoisSub ){
                     //cout<<"\n  if(retornoDfsAntesSub != retornoDfsDepoisSub ){\n";
                     //cout<<"\n  retornoDfsAntesSub "<<retornoDfsAntesSub;
                    // cout<<"\n  retornoDfsDepoisSub "<<retornoDfsDepoisSub;
                        resultado++;
                      // cout<<"\n Resultado: "<<resultado;
                    }
                    retornoDfsAntesSub = 0;
                retornoDfsDepoisSub = 0;

                }
            retornoDfsAntesSub = 0;
            retornoDfsDepoisSub = 0;
            }
		retornoDfsAntesSub = 0;
        retornoDfsDepoisSub = 0;
        }

        contador++;

    }

    return resultado;
}

int main() {

    int resultado;
    int C, P, v1, v2;
    int i;

    while ( ( scanf ( "%d %d", &C, &P) != EOF ) ) {
    	
            Graph grafo(C);
                //if (cin.eof()) break;
             for ( i=0; i<P; i++ ) {
                cin >>v1 >>v2;
                 
                 grafo.addEdge(v1, v2);
             }

        resultado = grafo.resultado(0);
        cout <<resultado << "\n";
        
    }
    return 0;

}

