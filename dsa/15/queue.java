class Queue {
    int front = 0, rear = -1;
    int[] arr = new int[5];

    void enqueue(int x) {
        arr[++rear] = x;
    }

    int dequeue() {
        return arr[front++];
    }

    public static void main(String[] args) {
        Queue q = new Queue();
        q.enqueue(10);
        q.enqueue(20);
        System.out.println(q.dequeue());
    }
}
