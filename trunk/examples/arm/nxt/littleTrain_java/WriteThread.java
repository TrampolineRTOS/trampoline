import java.io.IOException;

public class WriteThread extends Thread {
  private SampleSPPClient spp;
  
  public WriteThread(SampleSPPClient spp1) {
	this.spp = spp1;
  }
    
  public void run()
  {
		  
    while(true)
    {
    	try {
			spp.writeCommand();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    }
    
  }
   
  
}

