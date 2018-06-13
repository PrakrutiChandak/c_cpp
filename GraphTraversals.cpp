#include <iostream>
using namespace std;
#define MAX 10

class GraphNode {
public:
  int data;
  GraphNode *next;

  GraphNode() {
    data = 0;
    next = NULL;
  }

  GraphNode(int val) {
    data = val;
    next = NULL;
  }
};

class Stack {
public:
  int data[MAX];
  int top;

  Stack() {
    top = -1;
  }

  int isEmpty() {
    if (top == -1)
      return 1;
    return 0;
  }

  int isFull() {
    if ( top == MAX-1 )
      return 1;
    return 0;
  }

  void push(int val) {
    if (!isFull())
      data[++top] = val;
  }

  int pop() {
    if (!isEmpty())
      return data[top--];
  }
};

class Queue {
public:
  int data[MAX];
  int front, rear;

  Queue() {
    front = rear = -1;
  }

  int isEmpty() {
    if ( front == -1 && rear == -1 )
      return 1;
    return 0;
  }

  int isFull() {
    if ( rear == MAX-1 )
      return 1;
    return 0;
  }

  void insert( int val ) {
    if ( !isFull() )
    {
      if ( front == -1 && rear == -1 )
        ++front;
      data[++rear] = val;
    }
  }

  int remove() {
    if ( !isEmpty() )
    {
      int temp;

      temp = data[front];
      if ( front == rear )
      {
        front = rear = -1;
        return temp;
      }
      ++front;
      return temp;
    }
  }
};

class Graph {
public:
  GraphNode *vptrs[MAX];
  int visited[MAX];
  int n;

  Graph() {
    n = 0;
  }

  Graph(int vnum) {
    n = vnum;
  }

  void create();
  void insert(int from, int to);
  void display();
  void DFSrec(int v);
  void DFSStk();
  void BFS();
};

void Graph::create() {
  int cnt = 1, to, from;
  for ( int i = 0; i < n; i++ )
  {
    GraphNode *newNode = new GraphNode(i);
    vptrs[i] = newNode;
  }
  do {
    cout<<"Edge from vertex: ";
    cin>>from;
    cout<<"To vertex: ";
    cin>>to;
    insert(from, to);
    cout<<"Enter 1 to add more edges: ";
    cin>>cnt;
  } while(cnt == 1);
}

void Graph::insert(int from, int to) {
  GraphNode *newNode = new GraphNode(to);
  GraphNode *temp = vptrs[from];
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newNode;
}

void Graph::display() {
  for ( int i = 0; i < n; i++ )
  {
    GraphNode *temp = vptrs[i];
    while(temp!=NULL)
    {
      cout<<temp->data<<" ---> ";
      temp = temp->next;
    }
    cout<<"NULL\n";
  }
}

void Graph::DFSrec(int v) {
  std::cout<<v<<"  ";
  visited[v] = 1;
  GraphNode *temp = vptrs[v]->next;
  while (temp!=NULL) {
    if (visited[temp->data] == 0) {
      DFSrec(temp->data);
    }
    temp = temp->next;
  }
}

void Graph::DFSStk() {
  Stack stk;
  int v = 0;
  cout<<v<<"  ";
  visited[v] = 1;
  stk.push(v);
  GraphNode *temp = vptrs[v]->next;
  while( !stk.isEmpty() )
  {
    if (temp != NULL)
    {
      if(visited[temp->data]==0)
      {
        v = temp->data;
        cout<<v<<"  ";
        visited[v] = 1;
        stk.push(v);
        temp = vptrs[v]->next;
      }
      temp = temp->next;
    }
    else
    {
      v = stk.pop();
      temp = vptrs[v];
    }
  }
}

void Graph::BFS() {
  Queue q;
  int v = 0;

  q.insert(v);
  visited[v] = 1;
  GraphNode *temp;
  while ( !q.isEmpty() )
  {
    v = q.remove();
    cout<<v<<"  ";
    temp = vptrs[v]->next;
    while (temp!=NULL)
    {
      if(visited[temp->data]==0)
      {
        q.insert(temp->data);
        visited[temp->data] = 1;
      }
      temp = temp->next;
    }
  }
}

int main() {
  int choice = -1, cnt = 1, n;

  std::cout << "Enter number of vertices: " << '\n';
  std::cin >> n;
  Graph mGraph(n);

  do {
    std::cout << "__________________________________________________" << '\n';
    std::cout << "\t\tGRAPH TRAVERSALS" << '\n';
    std::cout << "__________________________________________________" << '\n';
    std::cout << "\t1 ---> Create" << '\n';
    std::cout << "\t2 ---> Insert" << '\n';
    std::cout << "\t3 ---> Display" << '\n';
    std::cout << "\t4 ---> BFS using Queue" << '\n';
    std::cout << "\t5 ---> DFS recursive" << '\n';
    std::cout << "\t6 ---> DFS using Stack" << '\n';
    std::cout << "\n\t0 ---> EXIT" << '\n';
    std::cout << "__________________________________________________" << '\n';
    std::cout << "Please enter your choice: ";
    std::cin >> choice;
    std::cout << "__________________________________________________" << '\n';
    switch (choice) {
      case 0:
        break;
      case 1:
        mGraph.create();
        break;
      case 2:

        break;
      case 3:
        mGraph.display();
        break;
      case 4:
        for(int i = 0; i < n; i++)
          mGraph.visited[i] = 0;
        mGraph.BFS();
        cout<<endl;
        break;
      case 5:
        for(int i = 0; i < n; i++)
          mGraph.visited[i] = 0;
        mGraph.DFSrec(0);
        cout<<endl;
        break;
      case 6:
        for(int i = 0; i < n; i++)
          mGraph.visited[i] = 0;
        mGraph.DFSStk();
        cout<<endl;
        break;
      default:
        std::cout << "INVALID CHOICE !" << '\n';
        choice = -1;
        break;
    }
    std::cout << "__________________________________________________" << '\n';
    std::cout << "Enter 1 to choose another operation: " << '\n';
    std::cin >> cnt;
    std::cout << "__________________________________________________" << '\n';
  } while(cnt == 1);
  return 0;
}
