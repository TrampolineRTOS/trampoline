   
import java.awt.Color;
import java.awt.Dimension;   
import java.awt.Paint;
import java.awt.Stroke;

import javax.swing.JPanel;   
import org.jfree.chart.ChartPanel;   
import org.jfree.chart.JFreeChart;   
import org.jfree.chart.LegendItem;
import org.jfree.chart.LegendItemCollection;
import org.jfree.chart.LegendItemSource;
import org.jfree.chart.axis.Axis;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.axis.ValueAxis;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.Plot;
import org.jfree.chart.plot.PolarPlot;
import org.jfree.chart.plot.SpiderWebPlot;   
import org.jfree.chart.title.LegendTitle;   
import org.jfree.chart.title.TextTitle;   
import org.jfree.data.category.CategoryDataset;   
import org.jfree.data.category.DefaultCategoryDataset;   
import org.jfree.ui.*;   
   
public class SpiderWebChartDemo1 extends ApplicationFrame   
{   
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public DefaultCategoryDataset defaultcategorydataset = new DefaultCategoryDataset();  
	public String s = "name";
	
    public SpiderWebChartDemo1(String s)   
    {   
        super(s);   
        CategoryDataset categorydataset = createDataset();   
        JFreeChart jfreechart = createChart(categorydataset);   
        ChartPanel chartpanel = new ChartPanel(jfreechart);   
        chartpanel.setPreferredSize(new Dimension(600, 600));   
        setContentPane(chartpanel);   
    }   
   
    private CategoryDataset createDataset()   
    {   
    	int namenumber = 360;
    	int halfchart = 180;
    	String[] names = new String[namenumber];
    	int istr;
    	
        for (int i = 0; i < namenumber; i+=10) { 
        	if (i > halfchart)
        	{
        	   istr = i - namenumber ;
        	}
        	else
        	{
        	   istr = i;
        	}
        	
        	names[i] = istr + "¡";
        	this.defaultcategorydataset.addValue(0, s, names[i]);
        	
        }
        
        //creating the rule
        //creating a line per value (otherwise, they are linked)
        for(int j = 50; j<250; j+=50)
        {
        	String line = "line" + j;
        	for (int i = -90; i<120; i+=30 )
            {
            	this.defaultcategorydataset.addValue(j, line + "_" + i, i + "¡");
            }
        }
        
    	        
        return this.defaultcategorydataset;   
    } 
    
    public void updateDataset(long value, String line, String valuetochange)
    {
    	this.defaultcategorydataset.addValue(value, line, valuetochange);
    }
   
    private JFreeChart createChart(CategoryDataset categorydataset)   
    {   
    	
        SpiderWebPlot spiderwebplot = new SpiderWebPlot(categorydataset);
        
        /* set red color for the data serie but grey for the rule */
        Color greycolor = new Color(150, 150, 150);
        Color redcolor = new Color(255, 85, 85);
        spiderwebplot.setSeriesPaint(0, redcolor);
        for(int i = 1; i<31; i++)
        {
            spiderwebplot.setSeriesPaint(i, greycolor);
        }        
        
        JFreeChart jfreechart = new JFreeChart("Spider Chart Demo", TextTitle.DEFAULT_FONT, spiderwebplot, true);
        jfreechart.removeLegend();
        /* LegendTitle legendtitle = new LegendTitle(legendsource);   
        legendtitle.setPosition(RectangleEdge.BOTTOM);
        jfreechart.addSubtitle(legendtitle);   
        */
        
        return jfreechart;   
    }   
   
    public JPanel createDemoPanel()   
    {   
        JFreeChart jfreechart = createChart(createDataset());   
        return new ChartPanel(jfreechart);   
    }
}  