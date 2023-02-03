//{ Driver Code Starts
//Initial Template for Java

//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            String str[] = read.readLine().trim().split("\\s+");
            int r = Integer.parseInt(str[0]);
            int c = Integer.parseInt(str[1]);
            int matrix[][] = new int[r][c];
            
            for(int i = 0; i < r; i++)
            {
                int k = 0;
                str = read.readLine().trim().split("\\s+");
                for(int j = 0; j < c; j++){
                  matrix[i][j] = Integer.parseInt(str[k]);
                  k++;
                }
            }
            Solution obj = new Solution();
            int[] p = obj.endPoints(matrix,r,c);
            out.print("(" +  p[0]+ ", " +  p[1]+ ")" +"\n");
        }
        out.close();
    }
}


// } Driver Code Ends


//User function Template for Java

class Solution{
   static int ansx,ansy;

    

    static public void helper(int x,int y,int dir,int [][]arr,int m,int n){

        if(x >= m || x < 0 || y >= n || y < 0){

            return;

        }

        

        ansx = x;

        ansy = y;

        

        if(dir == -1){

            if(arr[x][y] == 0)

                helper(x,y+1,1,arr,m,n);

            else

                helper(x+1,y,2,arr,m,n);

        }

        else{

            if(arr[x][y] == 0){

                if(dir == 1){

                    helper(x,y+1,1,arr,m,n);

                }

                else if(dir == 2){

                    helper(x+1,y,2,arr,m,n);

                }

                else if(dir == 3){

                    helper(x,y-1,3,arr,m,n);

                }

                else{

                    helper(x-1,y,4,arr,m,n);

                }

            }

            else{

                arr[x][y] = 0;

                if(dir == 1){

                    helper(x+1,y,2,arr,m,n);

                }

                else if(dir == 2){

                    helper(x,y-1,3,arr,m,n);

                }

                else if(dir == 3){

                    helper(x-1,y,4,arr,m,n);

                }

                else{

                    helper(x,y+1,1,arr,m,n);

                }

            }

        }

    }

    

    static int [] endPoints(int [][]arr, int m, int n){

        int x = 0,y = 0;

        helper(x,y,-1,arr,m,n);

        int []a = new int[2];

        a[0] = ansx;

        a[1] = ansy;

        return (a);

    }
}