package com.ijbamboo.pattern.builder.example.soup;

import com.ijbamboo.pattern.soup.BostonClamChowder;
import com.ijbamboo.pattern.soup.BostonFishChowder;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����3:37:32
 */
public class BostonSoupBuffetBuilder extends SoupBuffetBuilder{
	public void buildClamChowder() {
	       soupBuffet.clamChowder = new BostonClamChowder();
	    }
	    public void buildFishChowder() {
	       soupBuffet.fishChowder = new BostonFishChowder();
	    }    
	    
	    public void setSoupBuffetName() {
	       soupBuffet.soupBuffetName = "Boston Soup Buffet";
	    }
}
