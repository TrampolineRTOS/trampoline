
import java.awt.Container;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.io.IOException;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.KeyStroke;

public class displayProg extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private SampleSPPClient sppclient;
	
	private Container pane;
	private JButton bpbluetooth, bpUP, bpDOWN, bpLEFT, bpRIGHT;
    public JTextArea textArea;
    public JTextArea NXTaddrLabel;
    public JTextArea NXTaddrString;
	byte maxlengthcommand = 14;

	byte up1 =1;
    byte down2 =2;
    byte left3 =3;
    byte right4 =4;
	
	
	public displayProg(SampleSPPClient spp) {
		super();
		
		sppclient = spp;
		
		this.setSize(400, 400);
		
		pane = getContentPane();
        
		/* buttons */
        GridBagLayout gridbag = new GridBagLayout();
		pane.setLayout(gridbag);
		GridBagConstraints c = new GridBagConstraints();
		//natural height, maximum width
		c.fill = GridBagConstraints.HORIZONTAL;
		
		bpUP = new JButton(new ImageIcon("faster.png"));
		c.weightx = 0.5;
		c.fill = GridBagConstraints.HORIZONTAL;
		c.gridx = 1;
		c.gridy = 0;
		bpUP.setMnemonic(KeyEvent.VK_UP);
	    bpUP.setActionCommand("up");
		bpUP.addActionListener(this);
		pane.add(bpUP, c);

		bpDOWN = new JButton(new ImageIcon("slower.png"));
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 1;
		c.gridy = 1;
		bpDOWN.setMnemonic(KeyEvent.VK_DOWN);
		bpDOWN.setActionCommand("down");
		bpDOWN.addActionListener(this);
		pane.add(bpDOWN, c);

		bpLEFT = new JButton(new ImageIcon("left.png"));
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 0;
		c.gridy = 1;
		bpLEFT.setMnemonic(KeyEvent.VK_LEFT);
	    bpLEFT.setActionCommand("left");
	    bpLEFT.addActionListener(this);
		pane.add(bpLEFT, c);

		bpRIGHT = new JButton(new ImageIcon("right.png"));
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 2;
		c.gridy = 1;
		bpRIGHT.setMnemonic(KeyEvent.VK_RIGHT);
	    bpRIGHT.setActionCommand("right");
	    bpRIGHT.addActionListener(this);
		pane.add(bpRIGHT, c);
       
		//creating a textArea to display robot's speed and direction 
        c.fill = GridBagConstraints.HORIZONTAL;
		c.weightx = 0.5;
		c.gridx = 1;
		c.gridy = 2;
		c.insets = new Insets(10,0,0,0);  //top padding
		textArea = new JTextArea();
		textArea.setBackground(pane.getBackground());
		textArea.setEditable(false);
		textArea.setText("Command:" );
		pane.add(textArea, c);
		
		//creating a textArea for the NXT address
        c.fill = GridBagConstraints.HORIZONTAL;
		//c.weightx = 0.5;
		c.gridx = 0;
		c.gridy = 3;
		NXTaddrLabel = new JTextArea();
		NXTaddrLabel.setBackground(pane.getBackground());
		NXTaddrLabel.setEditable(false);
		NXTaddrLabel.setText("NXT Address:");
		pane.add(NXTaddrLabel, c);
		
		//creating a textArea for the NXT address
        c.fill = GridBagConstraints.HORIZONTAL;
		//c.weightx = 0.5;
		c.gridx = 1;
		c.gridy = 3;
		NXTaddrString = new JTextArea();
		//NXTaddrString.setBackground(pane.getBackground());
		NXTaddrString.setEditable(true);
		NXTaddrString.setText(sppclient.getNXTadress());
		pane.add(NXTaddrString, c);
       
        
        bpbluetooth = new JButton(new ImageIcon("bt.png"));
		c.fill = GridBagConstraints.HORIZONTAL;
		c.weighty = 0.5;   //request any extra vertical space
		//c.anchor = GridBagConstraints.PAGE_END; //bottom of space
		//c.insets = new Insets(10,0,0,0);  //top padding
		c.gridx = 2;       //aligned with button 2
		c.gridwidth = 1;   //1 columns wide
		c.gridy = 3;       //third row
		bpbluetooth.setActionCommand("bluetooth");
		bpbluetooth.addActionListener(this);
		pane.add(bpbluetooth, c);
			
        setButtonsEnabled(false);
        
	};
	
	public void udpatePanel(int command)
	{	
		//speed
		String scommand = "" + command;
		String commandtext = "Command: ";
		int gapcommand = maxlengthcommand - commandtext.length() - scommand.length();
		for(int i=0; i<gapcommand; i++)
		{
			commandtext = commandtext.concat("  ");
		}		
		commandtext = commandtext.concat(scommand);

		textArea.setText(commandtext);
		
	}
 
			
	public void setButtonsEnabled(boolean bool)
	{
		bpUP.setEnabled(bool);
		bpDOWN.setEnabled(bool);
		bpLEFT.setEnabled(bool);
		bpRIGHT.setEnabled(bool);
	}
	
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		//find which button has received the event and launch action
	    if (e.getActionCommand() == "up")
	    {
	    	try {
				sppclient.changeSpeed(up1);
			} catch (InterruptedException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
	    }
	    else if (e.getActionCommand() == "down")
	    {
	    	try {
				sppclient.changeSpeed(down2);
			} catch (InterruptedException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
	
	    }
	    else if (e.getActionCommand() == "left")
	    {
	    	try {
				sppclient.changeSpeed(left3);
			} catch (InterruptedException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
				    
	    }
	    else if (e.getActionCommand() == "right")
	    {
	    	try {
				sppclient.changeSpeed(right4);
			} catch (InterruptedException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			    	
	    }
	    else if (e.getActionCommand() == "bluetooth")
	    {
	    	System.out.println("Connecting bluetooth..." + NXTaddrString.getText());
	    	sppclient.changeNXTadress(NXTaddrString.getText());
			setButtonsEnabled(false);
	    	try {
				sppclient.tryconnectbluetooth();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			setButtonsEnabled(true);
			// TODO : if connection succeed, disable button
			if (sppclient.bluetoothconnection == true)
			{
				bpbluetooth.setEnabled(false);
			}
	    }
	    
	}		
	
}
