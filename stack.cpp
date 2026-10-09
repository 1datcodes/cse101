#include <iostream>
#include <cstdlib>
class Stack {
	public: 
		int stack_arr[10] = {0};
		int top = -1;
		
		void print_stack() {
			for (int i = 0; i < 10; i++) {
				std::cout << stack_arr[i] << std::endl;
			};
		};

		void push(int val) {
			if (top >= 10) std::exit(1);
			top += 1;
			stack_arr[top] = val;
		};

		int pop() {
			if (top < 0) std::exit(1);
			int val = stack_arr[top];
			top -= 1;
			return val;
		};
			
};

int main() {
	Stack stack1;
	stack1.print_stack();

	for (int i = 0; i < 10; i++) {
		stack1.push(i);
	}

	stack1.print_stack();

	std::cout << stack1.pop() << std::endl;
	std::cout << stack1.pop() << std::endl;
}
