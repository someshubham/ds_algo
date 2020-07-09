import 'linked_list.dart';

/*
Implement Stack using LinkedList in Dart

 */

class Stack<T> {
  LinkedList list;
  int stackSize;

  Stack() {
    list = LinkedList<T>();
    stackSize = 0;
  }

  void push(T value) {
    list.insertAtStart(value);
    stackSize++;
  }

  T pop() {
    stackSize--;
    return list.deleteAtStart();
  }

  int get size => stackSize;

  bool isEmpty() => stackSize == 0;
}

void main() {
  Stack stack = Stack<int>();
  stack.push(10);
  stack.push(20);
  stack.push(30);

  print(stack.size);
  print(stack.pop());
  print(stack.isEmpty());
  print(stack.pop());
  print(stack.pop());
  print(stack.isEmpty());
}
