class nodes:
    def __init__(self, v):
        self.v = v
        self.l_child = None
        self.r_child = None


def INorder(Root):
    if Root is not None:
        INorder(Root.l_child)
        print(Root.v, end=" ")
        INorder(Root.r_child)

def Insertion(p, v):
    if p is None:
        return nodes(v)
    if v < p.v:
        p.l_child = Insertion(p.l_child, v)
    else:
        p.r_child = Insertion(p.r_child, v)
    return p

def Deletion(Root, v):
    if Root is None:
        return Root

    if v < Root.v:
        Root.l_child = Deletion(Root.l_child, v)
        return Root
    elif (v > Root.v):
        Root.r_child = Deletion(Root.r_child, v)
        return Root

    if Root.l_child is None and Root.r_child is None:
        return None

    if Root.l_child is None:
        t = Root.r_child
        Root = None
        return t
    elif Root.r_child is None:
        t = Root.l_child
        Root = None
        return t

    succ = Root
    suc = Root.r_child
    while suc.l_child != None:
        succ = suc
        suc = suc.l_child
    if succ != Root:
        succ.l_child = suc.r_child
    else:
        succ.r_child = suc.r_child
    Root.v = suc.v

    return Root

def Searching(Root, x):
    if Root == None:
        print("\n The element is not present: ", x)
    elif Root.v == x:
        print("\n The element is present: ", x)
    elif x <= Root.v:
        return Searching(Root.l_child, x)
    else:
        return Searching(Root.r_child, x)


Root = None
Root = Insertion(Root, 20)
Root = Insertion(Root, 15)
Root = Insertion(Root, 30)
Root = Insertion(Root, 45)
Root = Insertion(Root, 40)
Root = Insertion(Root, 5)
Root = Insertion(Root, 10)
Root = Insertion(Root, 50)

print("Inorder:")
INorder(Root)
Searching(Root, 40)

print("Delete 50")
Root = Deletion(Root, 50)
print("Inorder:")
INorder(Root)
