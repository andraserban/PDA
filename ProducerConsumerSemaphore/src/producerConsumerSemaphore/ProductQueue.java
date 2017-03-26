package producerConsumerSemaphore;
import java.util.concurrent.Semaphore;
public class ProductQueue {
   
static Semaphore semaphoreProducer = new Semaphore(1);

static Semaphore semaphoreConsumer = new Semaphore(0);
 
int productId;
 
public void putProductIntoQueue(int productId){
    try {
        semaphoreProducer.acquire();
        this.productId=productId;
        System.out.println(Thread.currentThread().getName()+" Putting(In Q) Product ID:"+productId);
        semaphoreConsumer.release();
    } catch (InterruptedException e) {
        e.printStackTrace();
    }
}
 
public void getProductFromQueue(){
    try {
        semaphoreConsumer.acquire();
        System.out.println(Thread.currentThread().getName()+" Getting(From Q) Product ID:"+productId);
        semaphoreProducer.release();
    } catch (InterruptedException e) {
        e.printStackTrace();
    }
     
}

}