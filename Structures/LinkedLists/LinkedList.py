class Node(object):
    def __init__ (self, data, next = None):
        self.data = data
        self.next = next

class Linked(object):
    def __init__ (self):
        self.root = None

    def insert(self, data):
        if self.root == None:
            self.root = Node(data)
        else:
            temp = self.root
            if self.search(data):
                while temp.next:
                    temp = temp.next
                temp.next = Node(data)


    def search(self, data):
        Cur = self.root

        while Cur:
            if Cur.data == data:
                return False
            Cur = Cur.next

        return True

    def delet(self, data):
        if self.root == None:
            return
        else:
            temp = self.root
            prev = temp

            if temp.data == data:
                self.root = temp.next
                del(temp)
                return True

            temp = temp.next

            while temp:
                if temp.data == data:
                    prev.next = temp.next
                    del(temp)
                    return True
                prev = temp
                temp = temp.next

            return False

    def print(self):
        if self.root == None:
            return
        else:
            temp = self.root
            while temp:
                print(temp.data)
                temp = temp.next

if __name__ == '__main__':
    LL = Linked()
    LL.insert(5)
    LL.insert(3)
    LL.insert(10)
    LL.insert(33)
    LL.insert(1)
    LL.insert(50)

    LL.print()
