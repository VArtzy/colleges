class Stack {
    int top = -1;
    int[] arr = new int[5];

    void push(int x) {
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    public static void main(String[] args) {
        Stack s = new Stack();
        s.push(10);
        s.push(20);
        System.out.println(s.pop());
    }
}
