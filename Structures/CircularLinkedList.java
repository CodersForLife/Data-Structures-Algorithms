
public class CircularLinkedList extends LinkedList {
	
	//InsertAtHead would be same as normal LinkedList
	
	public int length(){
		Node temp = this.head;
		int cnt = 0;
		while(temp.next != this.head){
			temp = temp.next;
			cnt++;
		}
		return cnt;
	}
	
	public void print(){
		Node temp = this.head;
		while(temp.next != this.head){
			System.out.print(temp.data + ' ');
		}
	}
	
	public void insertAtTail(int value){
		Node newNode = new Node(value);
		Node temp = this.head;
		while(temp.next != this.head){
			temp = temp.next;
		}
		temp.next = newNode;
		newNode.next = this.head;
	}
	
	public void insertAfterNode(Node n,int value){
		Node newNode = new Node(value);
		Node temp = this.head;
		while(temp.next != this.head){
			if(temp == n){
				temp.next = newNode;
				newNode.next = temp.next.next;
			}
		}
	}
	
	public static CircularLinkedList Concat(CircularLinkedList l1, CircularLinkedList l2){
		CircularLinkedList l3 = new CircularLinkedList();
		l3.head = l1.head;
		Node temp = l1.head;
		while(temp.next != l1.head){
			temp = temp.next;
		}
		temp.next = l2.head;
		temp = temp.next;
		while(temp.next != l2.head){
			temp = temp.next;
		}
		temp.next = l1.head;
		
		return l3;
	}
	
	//Delete by value and delete by pos would be same as normal LinkedList
}
