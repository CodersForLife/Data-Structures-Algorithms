public class BinaryTree {					//Java code for basic binary tree operations
	public static Node root;
	public BinaryTree()
	{
		root=null;
	}
	public static class Node{
		public long data;
		public Node left;
		public Node right;
		public Node(long val)
		{
			data=val;
			left=null;
			right=null;
		}
		
	}
	
	public static void printpre(Node root)		//Preorder Tree Traversal 
	{	if(root!=null) {
		System.out.print(root.data+" ");
		printpre(root.left);
		printpre(root.right);
		}
	}
	
	public static void printpost(Node root)		//Postorder Tree Traversal 
	{
		if(root!=null) {
			
			printpost(root.left);
			printpost(root.right);
			System.out.print(root.data+" ");
			}
	}
	
	public static void printin(Node root)		//Inorder Tree Traversal 
	{
		if(root!=null) {
			printin(root.left);
			System.out.print(root.data+" ");
			printin(root.right);
			
			}
	}
	
	public static Node insert(Node root,long value)		//Insert a node into the tree
	{
		if(root==null)
		{
			root=new Node(value);
		
		}
		
		else {
			if(root.data>=value)
			{
			root.left=insert(root.left,value);
			}
			else root.right=insert(root.right,value);
		}
		return root;
	}
	
	public static Node getminnode(Node root)		//Get the node with minimum value
	{	if(root.left==null)
		{
		
			return root;
		}
	
		else return(getminnode(root.left));
		
	}
	public static Node delete(Node root,long value)		//Delete a node
	{	
		
		if(root==null)
			return null;
		if(root.data>value)
			root.left=delete(root.left,value);
		else if(root.data<value)
			root.right=delete(root.right,value);
		else
		{
			if(root.left!=null && root.right!=null)
			{
				Node temp=root;
				Node minright=getminnode(temp.right);
				root.data=minright.data;
				root.right=delete(root.right,minright.data);
				
			}
			else if(root.right!=null)
			{
				root=root.right;
			}
			else if(root.left!=null)
			{
				root=root.left;
			}
			
			else root=null;
		}
		
		return root;
	}
