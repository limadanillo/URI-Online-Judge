#include <iostream>
#include <ctime>
#include <malloc.h>
#include <vector>
#include <map>
#include <string.h>
#include <set>
#include <queue>          // std::queue
using namespace std;

vector<int> adj[1009];
char str[1009][25];
map<string, int> mp;
int get(char *s) {
	string st(s);
	if(!mp.count(st)) {
    mp[st] = mp.size() - 1;
    strcpy(str[mp[st]], s);
    }

	return mp[st];
}

struct node{
    int info;
    struct node *next;
};

class stack{
    struct node *top;
    public:
        stack();
        void push(int);
        int pop();
        bool isEmpty();
        void display();
};

stack::stack(){
    top = NULL;
}

void stack::push(int data){
    node *p;
    if((p=(node*)malloc(sizeof(node)))==NULL){
        cout<<"Memory Exhausted";
        exit(0);
    }
    p = new node;
    p->info = data;
    p->next = NULL;
    if(top!=NULL){
        p->next = top;
    }
    top = p;
}

int stack::pop(){
    struct node *temp;
    int value;
    if(top==NULL){
        cout<<"\nThe stack is Empty"<<endl;
    }else{
        temp = top;
        top = top->next;
        value = temp->info;
        delete temp;
    }
    return value;
}

bool stack::isEmpty(){
    return (top == NULL);
}

void stack::display(){
    struct node *p = top;
    if(top==NULL){
        cout<<"\nNothing to Display\n";
    }else{
        cout<<"\nThe contents of Stack\n";
        while(p!=NULL){
            cout<<p->info<<endl;
            p = p->next;
        }
    }
}

class Graph {
    private:
        int n;
        int **A;

    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int x, int y);
        void DFS(int , int);
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

bool Graph::isConnected(int x, int y) {
    return (A[x][y] == 1);
}

void Graph::addEdge(int x, int y) {
    A[x][y] = A[y][x] = 1;
}

void Graph::DFS(int x, int required){

    queue<int> q;
    int nivel[1009][25];
    int dist[1009];
    bool *visited = new bool[n+1];
    int i;
    int cont = -2;
    int oqEucQuero = required;
    set<string> st;

    for(i = 0; i <= n; i++)
        visited[i] = false;
    memset(dist, -1, sizeof dist);

    q.push(x);

    visited[x] = true;

    int j = 0;
    while(!q.empty()){

        int k = q.front(); q.pop();

        for (i = n; i > -1 ; --i)
            if (isConnected(k, i) && !visited[i] ){

                q.push(i);
                visited[i] = true;


                if(dist[i] == -1) {
                    dist[i] = dist[k] + 1;
                }
                if(dist[i]+1 <= oqEucQuero){

                    st.insert(str[i]);

                }

            }
    }
    cout<<st.size()<<endl;
	for(string ss : st)
		cout<<ss.c_str()<<endl;

    delete [] visited;
}



char s1[100], s2[100];

int main(){
    int i, n, g;

	cin >>n >>g;
	get("Rerisson");
	Graph grafo(n+2);
	for(i = 0; i < n; i++) {
		cin >>s1 >>s2;
		int a = get(s1), b = get(s2);

        grafo.addEdge(a, b);
	}
	int a = get("Rerisson");
	grafo.DFS(a, g);
    return 0;
}
