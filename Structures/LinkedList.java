
public class LinkedList {
	public Node head = null;
	
	public int length(){ //returns length of linkedlist
		int cnt = 0;
		Node temp  = this.head;
		while(temp != null){
			temp = temp.next;
			cnt++;
		}
		return cnt;
	}
	
	public int sumOfElements(){ //returns the sum of elements in linkedlist
		int sum = 0;
		Node temp = this.head;
		while(temp != null){
			sum += temp.data;
			temp = temp.next;
		}
		return sum;
	}
	
	
	public void searchNode(Node n){
		Node temp = this.head;
		int cnt = 0;
		while(temp != null){
			if(temp == n){
				System.out.println("Node found at pos: " + cnt);
				return;
			}
			temp=temp.next;
			cnt++;
		}
		System.out.println("Node does not exist");
	}
	
	// Deletes Nodes at even position
	public void deleteEven(){
		Node temp = this.head;
		int cnt = 0;
		while(cnt != this.length()){
			if(cnt%2 == 0){
				this.deleteAtPos(cnt);
			}
			cnt++;
		}
	}
	
	public void insertAtHead(int value){
		Node newNode  = new Node(value);
		Node temp = this.head;
		if(temp == null){
			this.head = newNode;
		}
		else{
			newNode.next = this.head;
			this.head = newNode;
		}
		
	}
	
	
	public void insertAtTail(int value){
		Node newNode =  new Node(value);
		Node temp = this.head;
		if(temp == null){
			this.head = newNode;
		}
		else{
			while(temp.next != null){
				temp = temp.next;
			}
			temp.next = newNode;
		}
	}
	
	public void insertAtPos(int value, int k){
		Node temp  = this.head;
		if(k == 0){
			this.insertAtHead(value);
		}
		else{
			int cnt = 0;
			Node newNode = new Node(value);
			Node prev  = temp;
			while(temp!=null && k!=cnt){
				 prev = temp;
				temp = temp.next;
				cnt++;
			}
			if(temp == null){
				System.out.println("Invalid position");
			}
			else{
				prev.next = newNode;
				newNode.next = temp;
			}
		}
	}
	
	public void deleteAtPos(int k){
		Node temp = this.head;
		if(k == 0){
		  temp = temp.next;
		  this.head.next = null;
		  this.head = temp;
		}
		else{
			Node prev = temp;
			int  cnt = 0;
			while(temp.next != null && k!=cnt){
				prev = temp;
				temp = temp.next;
				cnt++;
			}
			if(k == this.length() - 1){
				temp.next = null;
			}
			else if(k == cnt){
				prev.next = temp.next;
				temp.next = null;
			}
			else{
				System.out.println("Invalid Position");
			}
			
		}
	}
	
	public void deleteValue(int value){
		Node temp  = this.head;
		Node prev = temp;
		while(temp.data != value && temp != null){
			prev = temp;
			temp = temp.next;
		}
		if(temp == null){
			System.out.println("Value is not present");
		}
		else{
			prev.next = temp.next;
			temp.next = null;
		}
	}
	
	public void print(){
		if(this.head == null){
			System.out.println("Empty list");
		}
		else{
			Node temp  = this.head;
			while(temp != null){
				System.out.print(temp.data + " ");
				temp = temp.next;
			}
		}
	}
	
	public static LinkedList Concat(LinkedList L1, LinkedList L2){
		LinkedList L = new LinkedList();
		L.head = L1.head;
		Node temp = L.head;
		while(temp.next != null){
			temp = temp.next;
		}
		temp.next = L2.head;
		
		return L;
	}
	
	private void reverse(Node temp, Node prev){
		if(temp == null){
			this.head = prev;
			return;
		}
		else{
			reverse(temp.next,temp);
			temp.next = prev;
			return;
		}
	} 
	
	public void reverseList(){
		this.reverse(this.head,null);
	}
	
	public void split(LinkedList l1,LinkedList l2){
		Node temp = this.head;
		int cnt = 1;
		l1.head = this.head;
		while(temp != null){
			if(cnt%2 == 0){
				l1.insertAtTail(temp.data);
			}
			else{
				l2.insertAtTail(temp.data);
			}
		}
	}
}


class Node {
	int data;
	Node next;
	Node prev;
	
	Node(){
		data = 0;
		next  = null;
		prev = null;
	}
	
	Node(int data){
		this.data = data;
		this.next = null;
		this.prev = null;
	}
}
