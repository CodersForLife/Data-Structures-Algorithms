package Git;

import java.util.Scanner;

public class BT_boundaryTraversal {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BT_boundaryTraversal bts = new BT_boundaryTraversal();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		bt.Boundary();

	}

	private class BinaryTree {

		private class Node {
			int data;
			Node left;
			Node right;
		}

		private Node root;
		private int size;

		public BinaryTree() {
			this.root = construct(null, false);
		}

		private Node construct(Node parent, boolean ilc) {

			if (parent == null) {
				System.out.println("Enter the data for root node ? ");
			} else {
				if (ilc) {
					System.out.println("Enter the data for left " + parent.data);
				} else {
					System.out.println("Enter the data for right " + parent.data);
				}
			}

			int val = scn.nextInt();
			Node nn = new Node();
			nn.data = val;
			this.size++;

			boolean lc;
			System.out.println("Do you want left child");
			lc = scn.nextBoolean();
			if (lc) {
				nn.left = construct(nn, true);
			}

			boolean rc;
			System.out.println("Do you want right child");
			rc = scn.nextBoolean();
			if (rc) {
				nn.right = construct(nn, false);
			}

			return nn;

		}

		public void display() {
			display(this.root);
		}

		private void display(Node node) {

			if (node == null) {
				return;
			}

			String str = "";

			if (node.left != null) {
				str += node.left.data;
			} else {
				str += ".";
			}

			str += "->" + node.data + "<-";

			if (node.right != null) {
				str += node.right.data;
			} else {
				str += ".";
			}
			System.out.println(str);
			display(node.left);
			display(node.right);

		}

		public void Boundary() {

			Boundary(this.root);

		}

		private void Boundary(Node node) {

			System.out.print(node.data + " ");
			BoundaryLeft(node.left);		 
			printLeafs(node.left);
			printLeafs(node.right);
			BoundaryRight(node.right);

		}

		private void BoundaryRight(Node node) {		// Print the right nodes of tree from bottom to up excluding the rightmost node

			if (node != null) {

				if (node.right != null) {

					BoundaryRight(node.right);
					System.out.print(node.data + " ");

				} else if (node.left != null) {

					BoundaryRight(node.left);
					System.out.print(node.data + " ");
				}

			}

		}

		private void printLeafs(Node node) {	// Print the leaf nodes traversing the tree from left to right

			if (node != null) {

				printLeafs(node.left);
				if (node.left == null && node.right == null) {
					System.out.print(node.data + " ");
				}
				printLeafs(node.right);

			}

		}

		private void BoundaryLeft(Node node) {		//Print the tree's all left nodes from up to down excluding the leftmost node

			if (node != null) {

				if (node.left != null) {

					System.out.print(node.data + " ");
					BoundaryLeft(node.left);

				} else if (node.right != null) {

					System.out.print(node.data + " ");
					BoundaryLeft(node.right);

				}

			}

		}

	}
}