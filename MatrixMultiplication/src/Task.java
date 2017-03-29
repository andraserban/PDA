import java.util.*;
import java.util.concurrent.*;


class Task implements Callable<Integer>
   {
      int rowId, columnId;
      
      Matrix matrixA, matrixB;
      
      public Task (Matrix matrixA, Matrix matrixB, int rowId, int colId)
      {
         this.rowId = rowId;
         this.columnId = colId;
         this.matrixA = matrixA;
         this.matrixB = matrixB;
      }
   
      @Override
      public Integer call() throws Exception
      {
         String mesg = String.format("A[%d] * B[%d]", rowId, columnId);
         System.out.println("Started  Task. " + mesg);
      
         int product = 0;
         for (int i = 0; i < matrixA.colCount; ++i)
            product = product + matrixA.data[rowId][i] * matrixB.data[i][columnId];
         System.out.println("Finished Task. " + mesg + " = " + product);
       
         return product;
      }
      
   }
