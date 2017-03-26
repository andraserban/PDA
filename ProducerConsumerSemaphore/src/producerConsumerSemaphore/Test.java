package producerConsumerSemaphore;

public class Test {
	 public static void main(String[] args) {
         
	        ProductQueue pq = new ProductQueue();
	        Producer p = new Producer(pq);
	        Consumer c= new Consumer(pq);
	    }

}
