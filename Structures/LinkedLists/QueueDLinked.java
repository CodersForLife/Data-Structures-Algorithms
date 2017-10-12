package LinkedLists;

// Implementation of a queue using double linked list
// Java 8
// Aitor Alonso (https://github.com/tairosonloa)

public class QueueDLinked {

	private DNode header;
	private DNode trailer;

	public QueueDLinked() {
		header = new DNode(null);
		trailer = new DNode(null);
		header.next = trailer;
		trailer.prev= header;
	}


	/**
	 * Checks if queue is empty
	 * @return true if queue is empty, false in other case
	 */
	public boolean isEmpty() {
		return (header.next == trailer);
	}


	/**
	 * Enqueue an element
	 * @param elem The element to be enqueued
	 */
	public void enqueue(Object elem) {
		DNode newNode = new DNode(elem);
		newNode.next = trailer;
		newNode.prev= trailer.prev;
		trailer.prev.next = newNode;
		trailer.prev= newNode;
	}


	/**
	 * Dequeue an element
	 * @return elem dequeued, null if queue is empty
	 */
	public Object dequeue() {
		if (!isEmpty()) {
			Object elem = header.next.elem;
			header.next = header.next.next;
			header.next.prev = header;
			return elem;
		}
		else System.out.println("The queue is empty. Cannot dequeue.");
		return null;
	}


	/**
	 * Gets the queue size
	 * @return int with the queue size
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
	 * Prints the queue on standard output
	 */
	public void printQueue() {
		if (!isEmpty()) {
			for (DNode nodeIt = header.next; nodeIt != trailer; nodeIt = nodeIt.next) {
				System.out.print(nodeIt.elem + " ");
			}
			System.out.println();
		}
		else System.out.println("The queue is empty.");
	}


	/**
	 * Just to check the class QueueDLinked works
	 * @param args
	 */
	public static void main(String[] args) {

		// Just to check it works
		System.out.println("Testing class QueueDLinked");
		QueueDLinked queue = new QueueDLinked();
		System.out.println("Calling method isEmpty()");
		System.out.println("queue.isEmpty(): " + queue.isEmpty());
		System.out.println("Calling method getSize()");
		System.out.println("queue.getSize(): " + queue.getSize());
		System.out.println("Trying to dequeue with empty queue:");
		queue.dequeue();
		System.out.println("Calling method enqueue(). Enqueue element 1.");
		queue.enqueue(1);
		System.out.println("Calling method enqueue(). Enqueue element 2.");
		queue.enqueue(2);
		System.out.println("Calling method enqueue(). Enqueue element 3.");
		queue.enqueue(3);
		System.out.println("Printing the queue:");
		queue.printQueue();
		System.out.println("Calling method isEmpty()");
		System.out.println("queue.isEmpty(): " + queue.isEmpty());
		System.out.println("Calling method getSize()");
		System.out.println("queue.getSize(): " + queue.getSize());
		System.out.println("Calling method dequeue()");
		System.out.println("Dequeued: " + queue.dequeue());
		System.out.println("Calling method isEmpty()");
		System.out.println("queue.isEmpty(): " + queue.isEmpty());
		System.out.println("Calling method getSize()");
		System.out.println("queue.getSize(): " + queue.getSize());
		System.out.println("Printing the queue:");
		queue.printQueue();
		System.out.println("Test finished. Bye!");
	}
}