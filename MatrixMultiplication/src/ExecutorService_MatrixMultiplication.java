import java.util.*;
import java.util.concurrent.*;
//import util.Util;

public class ExecutorService_MatrixMultiplication
{
   public static void main (String arg[]) throws Exception
   {
      int dataA[][] = new int[][]
      {
         {1, 2},
         {3, 4},
         {5, 6},
         {7, 8}
      };
      
      int dataB[][] = new int[][]
      {
         {1,  2, 3},
         {4,  5, 6}
      };
      
      ExecutorService executor = Executors.newFixedThreadPool(3);
      
      Matrix matrixA = new Matrix (dataA);
      Matrix matrixB = new Matrix (dataB);
      System.out.println(matrixA.multiply(matrixB));
      
      executor.shutdown();
   }
}