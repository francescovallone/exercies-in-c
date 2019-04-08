#include <stdio.h>
#include <stdlib.h>
#include "item.h"


#define MAXINT 10;


static int top = -1;
static int size = 0;


Item* resize(Item* a){
	int temp = 2*size + 1;
	a = realloc(a, temp*sizeof(Item));
	size = temp;
}


Item* decrease(Item* a){
	int temp = (size)/2;
	a = realloc(a, temp*sizeof(Item));
	size = temp;
}


int isEmpty(){
	return (size == 0);
}


void push(Item* a,Item item){
	if(top == size-1){
		a = resize(a);
	}else if(top == (size/2)-1){
		a = decrease(a);
	}
	a[++top] = item;
}


int pop(Item* a){
	top--;
	return a[top+1];
}