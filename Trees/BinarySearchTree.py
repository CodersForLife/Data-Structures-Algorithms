class Node(object):
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

class BST(object):
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root:
            temp = self.root
            prev = temp
            while temp:
                if temp.data == data:
                    return False
                elif data < temp.data:
                    prev = temp
                    temp = temp.left
                else:
                    prev = temp
                    temp = temp.right

            if prev.data > data:
                prev.left = Node(data)
            else:
                prev.right = Node(data)

            return True

        else:
            self.root = Node(data)
            return True


    def in_order(self):
        def _in_order(root):
            if root:
                _in_order(root.left)
                print(root.data)
                _in_order(root.right)
        _in_order(self.root)

    def pre_order(self):
        def _pre_order(root):
            if root:
                print(root.data)
                _pre_order(root.left)
                _pre_order(root.right)
        _pre_order(self.root)

    def post_order(self):
        def _post_order(root):
            if root:
                _post_order(root.left)
                _post_order(root.right)
                print(root.data)
        _post_order(self.root)

if __name__ == '__main__':
    binary_seartch_tree = BST()
    binary_seartch_tree.insert(40)
    binary_seartch_tree.insert(4)
    binary_seartch_tree.insert(34)
    binary_seartch_tree.insert(45)
    binary_seartch_tree.insert(14)
    binary_seartch_tree.insert(55)
    binary_seartch_tree.insert(48)
    binary_seartch_tree.insert(13)
    binary_seartch_tree.insert(15)
    binary_seartch_tree.insert(49)
    binary_seartch_tree.insert(47)
    
    print("pre order")
    binary_seartch_tree.pre_order()
    print()
    print("in order")
    binary_seartch_tree.in_order()
    print()
    print("post order")
    binary_seartch_tree.post_order()
