/*
Linked List Implementation in Dart

Same logic as C++
 */

class Node {
  int value;
  Node next;
  Node({this.value});
}

class LinkedList {
  Node head;

  LinkedList() {
    head = null;
  }

  void insertAtStart(int value) {
    Node newNode = Node(value: value);

    newNode.next = head;
    head = newNode;
  }

  Node deleteAtStart() {
    Node temp = head;
    head = head.next;

    return temp;
  }

  void insertAtEnd(int value) {
    Node newNode = Node(value: value);
    Node temp = head;
    while (temp.next != null) {
      temp = temp.next;
    }

    temp.next = newNode;
    newNode.next = null;
  }

  Node deleteAtEnd() {
    Node temp = head;
    while (temp.next.next != null) {
      temp = temp.next;
    }
    Node temp2 = temp.next;
    temp.next = null;
    return temp2;
  }

  void printList() {
    Node temp = head;
    while (temp != null) {
      print('${temp.value}');
      temp = temp.next;
    }
  }
}

// Dart
void main() {
  LinkedList list = LinkedList();

  list.insertAtStart(10);
  list.insertAtStart(20);
  list.insertAtEnd(30);
  list.printList();

  Node deletedNode = list.deleteAtEnd();
  print('Deleted Value :${deletedNode.value}');
  list.printList();
}
