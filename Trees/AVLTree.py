class Node(object):
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        self.BF = 0             #Balance Factor


class AVL_Tree(object):
    def __init__(self):
        self.root = None

    def insert(self, data):
        pNew = Node(data)

        if self.root == None:
            self.root = pNew
            return True

        a = self.root
        pa = None
        Cur = self.root
        pCur = None
        subroot = None

        while Cur != None:
            if Cur.data == data:
                return False
            if Cur.BF != 0:
                a = Cur
                pa = pCur
            if data < Cur.data:
                pCur = Cur
                Cur = Cur.left
            elif data > Cur.data:
                pCur = Cur;
                Cur = Cur.right

        if data < pCur.data:
            pCur.left = pNew
        else:
            pCur.right = pNew

        balance = None
        Ca = None
        CCa = None

        if data < a.data:
            Cur = a.left
            Ca = Cur
            balance = 1
        else:
            Cur = a.right
            Ca = Cur
            balance = -1

        while Cur != pNew:
            if data < Cur.data:
                Cur.BF = 1
                Cur = Cur.left
            else:
                Cur.BF = -1
                Cur = Cur.right

        if a.BF == 0 or ((a.BF + balance) == 0):
            a.BF = a.BF + balance
            return True

        if balance == 1:
            if Ca.BF == 1:
                a.left = Ca.right
                Ca.right = a
                a.BF = 0
                Ca.BF = 0
                subroot = Ca
            else:
                CCa = Ca.right
                Ca.right = CCa.left
                a.left = CCa.right
                CCa.left = Ca
                CCa.right = a

                if CCa.BF == 0:
                    a.BF = 0
                    Ca.BF = 0
                elif CCa.BF == 1:
                    a.BF = -1
                    Ca.BF = 0
                elif CCa.BF == -1:
                    a.BF = 0
                    Ca.BF = 1

                CCa.BF = 0
                subroot = CCa
        else:
            if Ca.BF == -1:
                a.right = Ca.left
                Ca.left = a
                a.BF = 0
                Ca.BF = 0
                subroot = Ca
            else:
                CCa = Ca.left
                Ca.left = CCa.right
                a.right = CCa.left
                CCa.right = Ca
                CCa.left = a

                if CCa.BF == 0:
                    a.BF = 0
                    Ca.BF = 0
                elif CCa.BF == 1:
                    a.BF = 0
                    Ca.BF = -1
                elif CCa.BF == -1:
                    a.BF = 1
                    Ca.BF = 0
                CCa.BF = 0
                subroot = CCa

        if pa == None:
            self.root = subroot
        elif a == pa.left:
            pa.left = subroot
        else:
            pa.right = subroot

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
    avl_tree = AVL_Tree()
    avl_tree.insert(40)
    avl_tree.insert(4)
    avl_tree.insert(34)
    avl_tree.insert(45)
    avl_tree.insert(14)
    avl_tree.insert(55)
    avl_tree.insert(48)
    avl_tree.insert(13)
    avl_tree.insert(15)
    avl_tree.insert(49)
    avl_tree.insert(47)

    print("pre order")
    avl_tree.pre_order()
    print()
    print("in order")
    avl_tree.in_order()
    print()
    print("post order")
    avl_tree.post_order()
