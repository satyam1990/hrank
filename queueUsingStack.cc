/********************************************************************
 Implement a queue using two stacks. Then process q queries, 
 where each query is one of the following 3 types:

 1 1 x: Enqueue element  into the end of the queue.
 2 2: Dequeue the element at the front of the queue.
 3 3: Print the element at the front of the queue.
 
 Input Format

 The first line contains a single integer, q, denoting the number of queries. 
 Each line i of the q subsequent lines contains a single query in the form 
 described in the problem statement above. All three queries start with an integer 
 denoting the query type, but only query 1 is followed by an additional 
 space-separated value, x, denoting the value to be enqueued.

 It is guaranteed that a valid answer always exists for each query of type 3.

 Output Format

 For each query of type 3, print the value of the element at the front of the 
 queue on a new line.

 Sample Input
 10
 1 42
 2
 1 14
 3
 1 28
 3
 1 60
 1 78
 2
 2

 Sample Output
 14
 14
 *******************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top; 
        void enqueue(int x) 
        {
            // add new element to new_top stack
            stack_newest_on_top.push(x);
        }

        void dequeue() 
        {
            // old_top stack empty then 
            // move element from new_top stack to old_top stack
            if (stack_oldest_on_top.empty())
            {
                int length = stack_newest_on_top.size();
                for (int i = 0; i < length; i++)
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }

            // remove the oldest element
            stack_oldest_on_top.pop();
        }

        int front() 
        {
            // old_top stack empty then 
            // move element from new_top stack to old_top stack
            if (stack_oldest_on_top.empty())
            {
                int length = stack_newest_on_top.size();
                for (int i = 0; i < length; i++)
                {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }

            // return the oldest element
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.enqueue(x);
        }
        else if(type == 2) {
            q1.dequeue();
        }
        else cout << q1.front() << endl;
    }
    return 0;
}

