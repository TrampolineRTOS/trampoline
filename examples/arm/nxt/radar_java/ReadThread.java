import java.io.IOException;

public class ReadThread extends Thread {
  private SampleSPPClient spp;
  
  public ReadThread(SampleSPPClient spp1) {
	this.spp = spp1;
  }
    
  public void run()
  {
		  
    while(true)
    {
    	try {
			spp.readCommand();
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

