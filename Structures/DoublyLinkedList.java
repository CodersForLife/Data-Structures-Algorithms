
public class DoublyLinkedList extends LinkedList{
	
	
	public void insertAtHead(int value){
		Node newNode = new Node(value);
		if(this.head == null){
			this.head = newNode;
		}
		else{
			newNode.next = this.head;
			this.head.prev = newNode;
			this.head = newNode;
		}
	}
	
	public void insertAtPos(int k,int value){
		Node newNode = new Node(value);
		int cnt = 0;
		Node temp = this.head;
		while(temp != null){
			if(cnt == k){
				temp.prev.next = newNode;
				newNode.next = temp;
				newNode.prev = temp.prev;
				temp.prev = newNode;
				return;
			}
			temp = temp.next;
		}
		System.out.println("invalid position");
	}
	
	public void deleteValue(int value){
		Node temp = this.head;
		while(temp!= null){
			if(temp.data == value){
				temp.prev.next = temp.next;
				temp.next.prev = temp.prev;
				return;
			}
		}
	}

}
