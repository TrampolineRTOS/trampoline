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
    private InputStream is;
    private static SpiderWebChartDemo1 spiderwebchartdemo1;
    private static displayProg mafenetre;
        
    private Semaphore semRequestModified = new Semaphore(1);
    private boolean requestModified = false; 
    
    public boolean bluetoothconnection = false;
    
    private byte[] request = {2, 0, 0, 0};
    private byte[] temprequest = {2, 0, 0, 0};
    private byte[] answer = {0, 0, 0, 0};
	    
    private byte ispeed = 2;
    private byte idirection = 2;
    private byte[] speed = {-80, -60, 0, 60, 80};
    private byte[] direction = {-40, -30, 0, 30, 40};
    
    private short MAX = 4;
    private short MIN = 0;
    
    private String NXTadress = "0016530DF404";
    
    //object used for waiting
    private Object lock=new Object();
   
    //vector containing the devices discovered
    private Vector<RemoteDevice> vecDevices=new Vector<RemoteDevice>();
   
    private String connectionURL=null;
    
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
				System.out.println(addr);
				if (addr.equals(this.NXTadress)){
					//System.out.println( addr);
					remoteDevice	= remoteDevice2;
					System.out.println( " Found NXT  trusted : " + remoteDevice.isTrustedDevice() + " Encrypt :  " + remoteDevice.isEncrypted());
					break;
				}
				else
				{
					System.out.println(" NXT " + this.NXTadress + " not found !! Change NXT adress.");
					return;
				}
			
               // System.out.println((i+1)+". "+remoteDevice.getBluetoothAddress()+" ("+remoteDevice.getFriendlyName(true)+")");
            }
        }
		
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
				
		os = con.openOutputStream();
		is = con.openInputStream();

		/* Starting Spider Chart */
    	spiderwebchartdemo1 = new SpiderWebChartDemo1("Spider Chart Demo");   
        spiderwebchartdemo1.pack();   
        RefineryUtilities.centerFrameOnScreen(spiderwebchartdemo1);   
        spiderwebchartdemo1.setVisible(true);
        
        
        /* Starting a Read thread for the bluetooth */
        ReadThread bluetoothreadthread = new ReadThread(this);
        bluetoothreadthread.start();

    	/* Starting a Write thread for the bluetooth */
        WriteThread bluetoothwritethread = new WriteThread(this);
        bluetoothwritethread .start();
    	
    	bluetoothconnection = true;
    
    }
    
    public void incrementSpeedOrDirection(byte deltaspeed, byte deltadirection) throws InterruptedException, IOException  
    {
    	//update speed and direction according to parameters (be careful not to send too big values!)
    	
    	if ((ispeed + deltaspeed) > MAX)
    	{
    		ispeed = (byte)MAX;
    	}
    	else if ((ispeed + deltaspeed) < MIN)
    	{
    		ispeed = (byte)MIN;
    	}
    	else
    	{
    		ispeed += deltaspeed;
    	}    	
    	
    	if ((idirection + deltadirection) > MAX)
    	{
    		idirection = (byte)MAX;
    	}
    	else if ((idirection + deltadirection) < MIN)
    	{
    		idirection = (byte)MIN;
    	}
    	else
    	{
    		idirection += deltadirection;
    	}    	
    	
    	semRequestModified.acquire();
    	request[2] = speed[ispeed];
    	request[3] = direction[idirection];
    	requestModified = true;
    	semRequestModified.release();
    	
    	//update speed/direction on the panel
    	mafenetre.udpatePanel(request[2], request[3]);
    	    	
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
    		temprequest[3] = request[3];
    		semRequestModified.release();
    		
    		//send datas
    		os.write(temprequest);
        	//System.out.println(request[0] + ";" + request[1] + ";" + request[2] + "-" + request[3]);
    		
    	}
    	else
    	{
    		semRequestModified.release();
    		Thread.currentThread();
			Thread.sleep(10);
    	}
    	
    	
    }
    
    public void readCommand() throws InterruptedException, IOException{
    	
    	//wait for datas (4 bytes only)
    	is.read(answer);
		
        //find nearer value of the angle to 10.
        int nearerangle = answer[3] - answer[3] % 10;
        //convert value (byte) into integer
        long value = (answer[2] & 0xFF);
        //update chart
        if (value == -1)
        {
      	   value = 255;
        }
         
        //update spider web charta according to the value just received
        this.spiderwebchartdemo1.updateDataset(value, spiderwebchartdemo1.s, "" + nearerangle + "¡");
        //System.out.println(nearerangle + "¡:" + value);
		
    }
    
    //methods of DiscoveryListener
    public void deviceDiscovered(RemoteDevice btDevice, DeviceClass cod) {
		System.out.println(" TEST deviceDiscovered" );
		if (cod.getMajorDeviceClass() == 2048 && cod.getMinorDeviceClass() == 4)
			vecDevices.addElement(btDevice);
	}
	
    //implement this method since services are not being discovered
    public void servicesDiscovered(int transID, ServiceRecord[] servRecord) {
		System.out.println(" TEST servicesDiscovered" );
        if(servRecord!=null && servRecord.length>0){
            connectionURL=servRecord[0].getConnectionURL(0,false);
			System.out.println(" TEST Conn " );
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