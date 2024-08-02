//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader() { br = new BufferedReader(new InputStreamReader(System.in)); }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    Integer nextInt() { return Integer.parseInt(next()); }
}

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class GFG {
    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t > 0) {

            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(str[i]));
                tail = tail.next;
            }
            Solution ob = new Solution();
            Node ans = ob.divide(head);
            printList(ans);
            t--;
        }
    }
}
// } Driver Code Ends


// User function Template for Java

/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/

class Solution {
    Node divide(Node head) {
        // code here
        if(head == null || head.next == null) return head;
        Node even = null;
        Node evenEnd = null;
        Node odd = null;
        Node oddEnd = null;
        Node temp = head;
        while(temp!=null)
        {
            if(temp.data%2==0)
            {
                if(even==null)
                {
                    even = temp;
                    evenEnd = temp;
                }
                else
                {
                    evenEnd.next = temp;
                    evenEnd = temp;
                }
            }
            else
            {
                if(odd==null)
                {
                    odd = temp;
                    oddEnd = temp;
                }
                else
                {
                    oddEnd.next = temp;
                    oddEnd = temp;
                }
            }
            temp = temp.next;
        }
        if(even==null || odd==null) return head;
        evenEnd.next = odd;
        oddEnd.next = null;
        return even;
    }
}