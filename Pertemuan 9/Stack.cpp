#include <iostream>
using namespace std;

const int MAX = 5;

class Stack {
	private:
		int top;
		int stack[MAX];
		int items;
	public:
		Stack() {
			items = 0;
			top = -1;
		}
		
		int pop() {
			if (!items) {
				cout << "No items inserted yet." << endl;
				return -1;
			}
			int value = stack[top];
			top--;
			items--;
			return value;
		}
		
		void insert(int data) {
			top++;
			stack[top] = data;
			items++;
		}
		
		void printStack() {
			for (int i = 0; i <= top; i++) {
				cout << stack[i] << " berhasil dimasukkan ke stack" << endl;
			}
			cout << endl;
		}
		
		void popStack() {
			for (int j = 0; j <= top; j++) {
				cout << stack[j] << " berhasil dikeluarkan dari stack" << endl;
			}
			cout << endl;
		}
		
		void printStack2() {
			for (int k = 0; k <= top; k++) {
				cout << stack[k] << ' ';
			}
			cout << endl;
		}
};

int main() {
	Stack* stack = new Stack();
	
	stack->insert(30);
	stack->insert(45);
	stack->insert(50);
	stack->insert(55);
	
	stack->printStack();
	
	stack->pop();
	stack->pop();
	
	stack->popStack();
	
	cout << "isi stack:" << endl;
	stack->printStack2();
	
	return 0;
}
