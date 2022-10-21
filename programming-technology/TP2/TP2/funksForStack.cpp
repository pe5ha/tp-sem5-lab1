#include "stack.h"
class FunksForStack {
public: 
	Stack *createNewStack(int sizeStack) {
		Stack newStack(sizeStack);
		return &newStack;
	}
};