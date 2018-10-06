#include <vector>
#include <iostream>

using namespace std;
class Tree {
public:
    Tree () {val = -1;}
    Tree(int value) {val = value;}
    int get_value() { return val;}
    void set_value(int value) {val = value;}
    Tree& get_child(int i) { return *(children[i]);}
    Tree& add_child(Tree& tree) {children.push_back(&tree);}
    int num_children() {return children.size();}

private:
    vector<Tree*> children;
    int val;
};

//Minimax algorithm. We assume that each node can have value >= 0
int minimax(Tree& t, bool is_max=true){
    // Base case: A leaf node return its value
    if (t.get_value() > -1)
        return t.get_value();

    //Repeat the algorithm recursively and find max(min) value for the node
    vector<int> children_values;
    for (auto i = 0; i < t.num_children(); ++i)
        children_values.push_back(minimax(t.get_child(i), !is_max));

    auto curr_value = children_values[0];
    for (auto i = 1; i < children_values.size(); ++i)
        curr_value = is_max ? max(curr_value, children_values[i]) : min(curr_value, children_values[i]);
    //Set value for backtracking
    t.set_value(curr_value);
    return curr_value;
}

int main() {
    Tree base;
    Tree lc, rc;
    Tree node1(3), node2(5), node3(2), node4(9);
    base.add_child(lc); base.add_child(rc);
    lc.add_child(node1); lc.add_child(node2);
    rc.add_child(node3); rc.add_child(node4);
    cout << minimax(base, true) << endl;
}