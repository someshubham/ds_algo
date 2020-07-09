/*
Linked List Implementation in Dart

Same logic as C++
 */

class Node<T> {
  T value;
  Node next;
  Node({this.value});
}

class LinkedList<T> {
  Node<T> head;
  List x;
  LinkedList() {
    head = null;
  }

  void insertAtStart(T value) {
    Node newNode = Node<T>(value: value);

    newNode.next = head;
    head = newNode;
  }

  T deleteAtStart() {
    Node<T> temp = head;
    head = head.next;

    return temp.value;
  }

  void insertAtEnd(T value) {
    Node<T> newNode = Node<T>(value: value);
    Node<T> temp = head;
    while (temp.next != null) {
      temp = temp.next;
    }

    temp.next = newNode;
    newNode.next = null;
  }

  T deleteAtEnd() {
    Node<T> temp = head;
    while (temp.next.next != null) {
      temp = temp.next;
    }
    Node<T> temp2 = temp.next;
    temp.next = null;
    return temp2.value;
  }

  void printList() {
    Node<T> temp = head;
    while (temp != null) {
      print('${temp.value}');
      temp = temp.next;
    }
  }
}

// Dart
void main() {
  LinkedList list = LinkedList<int>();

  list.insertAtStart(10);
  list.insertAtStart(20);
  list.insertAtEnd(30);
  list.printList();

  int deletedValue = list.deleteAtEnd();
  print('Deleted Value :$deletedValue');
  list.printList();
}
