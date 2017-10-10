# Implementation of a queue using an array
# Python 3
# Aitor Alonso (https://github.com/tairosonloa)

class QueueArray:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        # We always enqueue into first position
        self.items.insert(0,item)

    def dequeue(self):
        # We always dequeue from last position
        return self.items.pop()

    def size(self):
        return len(self.items)

    def printQueue(self):
        print ("LAST>", end=" ")
        for item in self.items:
            print(item, end=" ")
        print ("<FIRST")

if __name__ == "__main__":
    # execute only if run as a script, small demostration of working, just run 'python3 QueueArray.py' in a terminal
    queue = QueueArray()
    while True:
        print("What do you want to do?")
        print("\t1 - Enqueue")
        print("\t2 - Dequeue")
        print("\t3 - Check empty")
        print("\t4 - Check size")
        print("\t5 - Print queue")
        print("\t6 - Exit")
        option = input()
        print()
        if option == '1':
            item = input("Type your item ")
            queue.enqueue(item)
            print("Item enqueued successfully!\n")
        elif option == '2':
            item = queue.dequeue()
            print("Dequeue item" , item, "\n")
        elif option == '3':
            if queue.isEmpty():
                print("Queue is empty\n")
            else:
                print("Queue is not empty\n")
        elif option == '4':
            print("The queue size is", queue.size(), "\n")
        elif option == '5':
            queue.printQueue()
            print()
        elif option == '6':
            print("Bye!")
            break
        else:
            print("Please, choose an option between 1 and 6\n")

