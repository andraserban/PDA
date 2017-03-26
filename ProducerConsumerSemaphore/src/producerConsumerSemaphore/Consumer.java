package producerConsumerSemaphore;


	public class Consumer extends Thread{
	     
	    ProductQueue q;
	     
	    public Consumer(ProductQueue q){
	        this.q=q;
	        this.setName("Consumer Thread");
	        this.start();
	    }
	     
	    public void run(){
	        for(int i=0;i<5;i++){
	            q.getProductFromQueue();
	        }
	         
	    }

		}
	
