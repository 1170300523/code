package com.ijbamboo.pattern.builder.example.soup;

import com.ijbamboo.pattern.soup.HonoluluClamChowder;
import com.ijbamboo.pattern.soup.HonoluluFishChowder;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����3:39:12
 */
public class HonoluluSoupBuffetBuilder extends SoupBuffetBuilder{
	 public void buildClamChowder() {
	        soupBuffet.clamChowder = new HonoluluClamChowder();
	    }
	    public void buildFishChowder() {
	        soupBuffet.fishChowder = new HonoluluFishChowder();
	    }
	    
	    public void setSoupBuffetName() {
	        soupBuffet.soupBuffetName = "Honolulu Soup Buffet";
	    }
}
