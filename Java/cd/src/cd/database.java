package cd;

import java.awt.List;
import java.awt.Point;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class database {
	private ArrayList<CD> cdList = new ArrayList<CD>();
	
	public void add(CD cd)
	{
		cdList.add(cd);
	}
	public void list()
	{
		for(CD cd :cdList)
		cd.print();
	}
	public static void main(String[] args) {
//		String bString="RT @PresentLP_YT: FFA Action mit @PokeBazi, @Nestfloh &amp; @FullLifeGames! :]\nhttps://t.co/HwBsARxKOA";
//		 String regEx="@\\w*";
//		
//	
//		Pattern p = Pattern.compile(regEx);
//		Matcher m = p.matcher(bString);
//		String result="";
//		while (m.find()) {
//		result=m.group();
//		result = result.toLowerCase().replace("@", "").replaceAll(":", "");
		Set<Integer> k = new HashSet<>();
		k.add(1);
		k.add(2);
		k.add(3);
		Iterator<Integer> i = k.iterator();
		System.out.println(i.next());
		System.out.println(i.next());
		System.out.println(i.next());
		Point aPoint = new Point(1, 2);
		Point bPoint = new Point(2, 3);
		Point cPoint = new Point(1, 2);
		System.out.println(aPoint.equals(cPoint));
		
		

	        
	        
	}





}
