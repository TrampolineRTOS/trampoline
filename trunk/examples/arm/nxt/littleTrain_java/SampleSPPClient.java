import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.Vector;
import java.util.concurrent.Semaphore;
 
import javax.bluetooth.DeviceClass;
import javax.bluetooth.DiscoveryAgent;
import javax.bluetooth.DiscoveryListener;
import javax.bluetooth.LocalDevice;
import javax.bluetooth.RemoteDevice;
import javax.bluetooth.ServiceRecord;
import javax.bluetooth.UUID;
import javax.microedition.io.Connector;
import javax.microedition.io.StreamConnection;

import org.jfree.ui.RefineryUtilities;

/**
* A simple SPP client that connects with an SPP server
 * MODIFICATION URU 
 
*/
public class SampleSPPClient implements DiscoveryListener{
    private OutputStream os;
    private OutputStream os2;
    private InputStream is;
    private InputStream is2;
    private static SpiderWebChartDemo1 spiderwebchartdemo1;
    private static displayProg mafenetre;
        
    private Semaphore semRequestModified = new Semaphore(1);
    private boolean requestModified = false; 
    
    public boolean bluetoothconnection = false;
    
    private byte[] request = {3,0,0,0,0};
    private byte[] temprequest = {3,0,0,0,0};
    private byte[] answer = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    private byte counter_receive=0;
    private byte counter_send=0;
    private short dx0=0, dx1=0, dx2=0;
    private short dy0=0, dy1=0, dy2=0;
    private float dx_done=0, dy_done=0;
    private short tempshort;
    
    private String NXTadress2 = "0016530DF409";
    private String NXTadress = "0016530AF599";
    
    //object used for waiting
    private Object lock=new Object();
   
    //vector containing the devices discovered
    private Vector<RemoteDevice> vecDevices=new Vector<RemoteDevice>();
   
    private String connectionURL=null;
    private String connectionURL2=null;
    
    public static void main(String[] args) throws IOException, InterruptedException {
                  	
    	mafenetre = new displayProg(new SampleSPPClient());
    	mafenetre.setVisible(true);

    	// TODO: this loop is not useful
		while(true){
			
			try {
		    	Thread.currentThread();
				Thread.sleep(100);				
		    } catch (InterruptedException e) {
		    	e.printStackTrace();
		    }
		}
		
    }//main
   
    public void changeNXTadress(String adr)
    {
    	this.NXTadress = adr;
    }

    public String getNXTadress()
    {
    	return this.NXTadress;
    }
    
    
    public void tryconnectbluetooth() throws IOException
    {
    	// TODO: find the NXT adress available and let the user selecting the one he wants

    	RemoteDevice remoteDevice= null;
    	RemoteDevice remoteDeviceadr2 = null;
		RemoteDevice remoteDevice2= null;
        //display local device address and name
        LocalDevice localDevice = LocalDevice.getLocalDevice();
        System.out.println("Address: "+localDevice.getBluetoothAddress());
        System.out.println("Name: "+localDevice.getFriendlyName());
        
        //find devices
        DiscoveryAgent agent = localDevice.getDiscoveryAgent();
      
        System.out.println("Starting device inquiry...");
        agent.startInquiry(DiscoveryAgent.GIAC, this);
       
        try {
            synchronized(lock){
                lock.wait();
            }
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
       
       
        System.out.println("Device Inquiry Completed. ");
       
        //print all devices in vecDevices
        int deviceCount=vecDevices.size();
       
        if(deviceCount <= 0){
            System.out.println("No Devices Found .");
            System.exit(0);
        }
        else{
            //print bluetooth device addresses and names in the format [ No. address (name) ]
            System.out.println("Bluetooth Devices: ");
            for (int i = 0; i <deviceCount; i++) {
                remoteDevice2=(RemoteDevice)vecDevices.elementAt(i);
				String addr = remoteDevice2.getBluetoothAddress();
				System.out.println(addr + "deviceCount:" + deviceCount);
				if (addr.equals(this.NXTadress)){
					//System.out.println( addr);
					remoteDevice	= remoteDevice2;
					System.out.println( " Found NXT  trusted : " + remoteDevice.isTrustedDevice() + " Encrypt :  " + remoteDevice.isEncrypted());
					
				}
				else if (addr.equals(this.NXTadress2)){
					//System.out.println( addr);
					remoteDeviceadr2	= remoteDevice2;
					System.out.println( " Found NXT2  trusted : " + remoteDeviceadr2.isTrustedDevice() + " Encrypt :  " + remoteDeviceadr2.isEncrypted());
				}
				else
				{
					System.out.println(" NXT " + this.NXTadress + " not found !! Change NXT adress.");
					return;
				}
               // System.out.println((i+1)+". "+remoteDevice.getBluetoothAddress()+" ("+remoteDevice.getFriendlyName(true)+")");
            }
        }
		

        /* *******
         * NXT1  * 
         ******* */
        
		//LocalDevice.getLocalDevice().getDiscoveryAgent().searchServices(attributes,uuids,device,listener);
		UUID[] uuidSet = new UUID[1]; // Profil SSP
        // uuidSet[0]=null;
	    uuidSet[0]=new UUID("1101",true);
		int trans = agent.searchServices(new int[]{0x0000,0x0001,0x0002,0x0003,0x0004},uuidSet,remoteDevice,this);
		System.out.println("TRy conn  " + remoteDevice + " -- "  + trans);
		try {
            synchronized(lock){
                lock.wait();
            }
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
		//agent.searchServices(null,uuidSet,remoteDevice,client);
		System.out.println("REs   "  +connectionURL );
		StreamConnection con= (StreamConnection)Connector.open(connectionURL);
				
		/* *******
         * NXT2  * 
         ******* */
        
        int trans2 = agent.searchServices(new int[]{0x0000,0x0001,0x0002,0x0003,0x0004},uuidSet,remoteDeviceadr2,this);
		System.out.println("TRy conn  " + remoteDeviceadr2 + " -- "  + trans2);
		try {
            synchronized(lock){
                lock.wait();
            }
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
		//agent.searchServices(null,uuidSet,remoteDevice,client);
        System.out.println("REs   "  +connectionURL2 );
		StreamConnection con2= (StreamConnection)Connector.open(connectionURL2);
		
		/* Both NXT are synchronized */
		
		/* NXT1 */
		os = con.openOutputStream();
		is = con.openInputStream();
        
        /* Starting a Read thread for the bluetooth */
        ReadThread bluetoothreadthread = new ReadThread(this);
        bluetoothreadthread.start();

    	/* Starting a Write thread for the bluetooth */
        WriteThread bluetoothwritethread = new WriteThread(this);
        bluetoothwritethread .start();
    	
        /* NXT2 */
		//is2 = con2.openInputStream();
		os2 = con2.openOutputStream();
        
        bluetoothconnection = true;
    
    }
    
    public void changeSpeed(byte command) throws InterruptedException, IOException  
    {
    	//update speed 		
    	
    	semRequestModified.acquire();
		request[2]=command;
//		request[3]=30;
//		request[4]=40;
    	requestModified = true;
    	semRequestModified.release();
 //   	os.write(request);
    	System.out.println("COMMAND : "+request[2]);

    	//update speed/direction on the panel
    	mafenetre.udpatePanel(request[2]);
    	    	
    }
   
    public void writeCommand() throws InterruptedException, IOException {
    	
    	//it takes 150-190ms to send datas (4 bytes in this case)

    	semRequestModified.acquire();
    	//if request is modified (by the panel arrows)
    	if (requestModified == true)
    	{
    		requestModified = false;
    		//since request seems not to be changed if we send request, we use an other array
    		temprequest[2] = request[2];
//    		temprequest[3] = request[3];
//    		temprequest[4] = request[4];
    		semRequestModified.release();
    		
    		//send datas
    		os.write(temprequest);
//        	System.out.println("Temprequest Sent");
//       	System.out.println("Request :"+request[0] + " / " + request[1] + " / " + request[2]+" / "+request[3]+" / "+request[4]+" / "+request[5]);
//        	System.out.println("temprequest :"+temprequest[0] + " / " + temprequest[1] + " / " + temprequest[2]+" / "+temprequest[3]+" / "+temprequest[4]+" / "+temprequest[5]);
        	
    	}
    	else
    	{
    		semRequestModified.release();
    		Thread.currentThread();
    		Thread.sleep(10);
    	}
    	
    	
    }
 /*##########################################################################################################################################*/
    public void readCommand() throws InterruptedException, IOException{
    	
    	//wait for datas (14 bytes only)
    	is.read(answer);
    	counter_receive ++; 
    	
    	dx0 = (short) ((answer[2])*256 + answer[3]);
    	dy0 = (short) ((answer[4])*256 + answer[5]);
    	dx1 = (short) ((answer[6])*256 + answer[7]);
    	dy1 = (short) ((answer[8])*256 + answer[9]);
    	dx2 = (short) ((answer[10])*256 + answer[11]);
    	dy2 = (short) ((answer[12])*256 + answer[13]);
    	    	
    	System.out.println(answer[0] + " values received:");
   	    System.out.println("dx0:"+Integer.toHexString((byte)dx0));
    	System.out.println("dy0:"+Integer.toHexString((byte)dy0));
        System.out.println("dx1:"+Integer.toHexString((byte)dx1));
        System.out.println("dy1:"+Integer.toHexString((byte)dy1));
        System.out.println("dx2:"+Integer.toHexString((byte)dx2));
        System.out.println("dy2:"+Integer.toHexString((byte)dy2));
        
        
        for(int i=0; i<(answer[0]/2); i++)
        {
        	tempshort = (short) ((answer[2*i+2])*256 + answer[2*i+3]);
        	if ( (i%2) == 1 )
        	{
                dy_done += ((float)(tempshort))/100;  
                System.out.println("dy_done:" + dy_done);
        	}
        	else
        	{
        		dx_done += ((float)(tempshort))/100;
        		System.out.println("dx_done:" + dx_done);
        	}
        }
        
        //System.out.println("dx_done:" + dx_done + " dy_done:" + dy_done);
        System.out.println("");
        
		// TODO: dispatch datas to other NXT ?
        
        os2.write(answer);
        counter_send ++;
    }
  
   /*##########################################################################################################################################*/
    
    //methods of DiscoveryListener
    public void deviceDiscovered(RemoteDevice btDevice, DeviceClass cod) {
		System.out.println(" TEST deviceDiscovered" );
		if (cod.getMajorDeviceClass() == 2048 && cod.getMinorDeviceClass() == 4)
			vecDevices.addElement(btDevice);
	}
	
    //implement this method since services are not being discovered
    public void servicesDiscovered(int transID, ServiceRecord[] servRecord) {
		System.out.println(" TEST servicesDiscovered transID" + transID + "servRecord" + servRecord);
		if (transID == 1)
		{
			if(servRecord!=null && servRecord.length>0){
	            connectionURL=servRecord[0].getConnectionURL(0,false);
				System.out.println(" TEST Conn " + connectionURL);
	        }
		}
		else if (transID == 2)
		{
			if(servRecord!=null && servRecord.length>0){
	            connectionURL2=servRecord[0].getConnectionURL(0,false);
				System.out.println(" TEST Conn " + connectionURL2);
	        }
		}
        synchronized(lock){
            lock.notify();
        }
        
    }
 
    //implement this method since services are not being discovered
    public void serviceSearchCompleted(int transID, int respCode) {
		System.out.println("  TEST serviceSearchCompleted" );
        synchronized(lock){
            lock.notify();
        }
    }
 
   
    public void inquiryCompleted(int discType) {
    	System.out.println("  TEST inquiryCompleted" );
        synchronized(lock){
            lock.notify();
        }
       
    }//end method
   
    static public String getString(String msg) {
        String res ="";
        System.out.print(msg);
        BufferedReader clav = new BufferedReader(new InputStreamReader(System.in));
        try {
            res = clav.readLine();
        }
        catch (IOException e) {
            System.out.println(e);
        }
        return res;
    }
   
   
}