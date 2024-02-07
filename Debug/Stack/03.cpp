// reverseStack, fun approach

void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.empty()){ // base-case
        return;
    }
    int x = input.top();
    input.pop();
    reverseStack(input,extra);
    for(int i=0; input.empty()==false; i++){ // condn
        extra.push(input.top());
        input.pop();
    }
    input.push(x);
    for(int i=0; extra.empty()==false; i++){ // condn
        input.push(extra.top());
        extra.pop();
    }
    return;
}
