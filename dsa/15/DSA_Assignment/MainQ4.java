import java.util.Scanner;

class Node {
    String no,nama;
    int total;
    Node next;

    Node(String n,String nm,int t){
        no=n; nama=nm; total=t;
    }
}

class Queue {
    Node front,rear;
    void enqueue(Node n){
        if(front==null) front=rear=n;
        else {rear.next=n; rear=n;}
    }
    Node dequeue(){
        if(front==null) return null;
        Node t=front;
        front=front.next;
        return t;
    }
}

class Stack {
    Node top;
    void push(Node n){
        n.next=top;
        top=n;
    }
}

public class MainQ4 {
    public static void main(String[] args){
        Queue q=new Queue();
        Stack s=new Stack();

        q.enqueue(new Node("A1","Andi",100));
        Node n=q.dequeue();
        if(n!=null) s.push(n);
    }
}
