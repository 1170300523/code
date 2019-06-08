package com.ijbamboo.pattern.builder.example.soup;

import com.ijbamboo.pattern.soup.BostonClamChowder;
import com.ijbamboo.pattern.soup.BostonFishChowder;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午3:37:32
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
