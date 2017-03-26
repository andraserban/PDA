package producerConsumerSemaphore;


	public class Producer extends Thread{
	     
	    ProductQueue q;
	     
	    public Producer(ProductQueue q){
	        this.q=q;
	        this.setName("Producer Thread");
	        this.start();
	    }
	     
	    public void run(){
	        for(int i=0;i<5;i++){
	            q.putProductIntoQueue(i);
	        }
	        

	    	}
	}
