package LinkedLists;

// Implementation of a queue using double linked list
// Java 8
// Aitor Alonso (https://github.com/tairosonloa)

public class StackDLinked
{

	private DNode header;
	private DNode trailer;

	public StackDLinked() {
		header = new DNode(null);
		trailer = new DNode(null);
		header.next = trailer;
		trailer.prev= header;
	}


	/**
	 * Checks if stack is empty
	 * @return true if stack is empty, false in other case
	 */
	public boolean isEmpty() {
		return (header.next == trailer);
	}


	/**
	 * Pushes an element
	 * @param elem The element to be pushed
	 */
	public void push(Object elem) {
		DNode newNode = new DNode(elem);
		newNode.next = trailer;
		newNode.prev= trailer.prev;
		trailer.prev.next = newNode;
		trailer.prev= newNode;
	}


	/**
	 * Pops an element
	 * @return elem popped, null if stack is empty
	 */
	public Object pop() {
		if (!isEmpty()) {
			Object elem = trailer.prev.elem;
			trailer.prev=trailer.prev.prev;
			trailer.prev.next=trailer;
			return elem;
		}
		else System.out.println("The stack is empty. Cannot pop.");
		return null;
	}


	/**
	 * Gets the stack size
	 * @return int with the stack size
	 */
	public int getSize() {
		int size = 0;
		if (!isEmpty()) {
			for (DNode nodeIt = header.next; nodeIt != trailer; nodeIt = nodeIt.next)
				size++;
		}
		return size;
	}


	/**
	 * Prints the stack on standard output
	 */
	public void printStack() {
		if (!isEmpty()) {
			for (DNode nodeIt = header.next; nodeIt != trailer; nodeIt = nodeIt.next) {
				System.out.print(nodeIt.elem + " ");
			}
			System.out.println("<TOP");
		}
		else System.out.println("The stack is empty.");
	}

	/**
	 * Just to check the class StackDLinked works
	 * @param args
	 */
	public static void main(String[] args) {

		// Just to check it works
		System.out.println("Testing class StackDLinked");
		StackDLinked stack = new StackDLinked();
		System.out.println("Calling method isEmpty()");
		System.out.println("stack.isEmpty(): " + stack.isEmpty());
		System.out.println("Calling method getSize()");
		System.out.println("stack.getSize(): " + stack.getSize());
		System.out.println("Trying to pop with empty stack:");
		stack.pop();
		System.out.println("Calling method push(). Pushing element 1.");
		stack.push(1);
		System.out.println("Calling method push(). Pushing element 2.");
		stack.push(2);
		System.out.println("Calling method push(). Pushing element 3.");
		stack.push(3);
		System.out.println("Printing the stack:");
		stack.printStack();
		System.out.println("Calling method isEmpty()");
		System.out.println("stack.isEmpty(): " + stack.isEmpty());
		System.out.println("Calling method getSize()");
		System.out.println("stack.getSize(): " + stack.getSize());
		System.out.println("Calling method dequeue()");
		System.out.println("Popped: " + stack.pop());
		System.out.println("Calling method isEmpty()");
		System.out.println("stack.isEmpty(): " + stack.isEmpty());
		System.out.println("Calling method getSize()");
		System.out.println("stack.getSize(): " + stack.getSize());
		System.out.println("Printing the stack:");
		stack.printStack();
		System.out.println("Test finished. Bye!");
	}
}