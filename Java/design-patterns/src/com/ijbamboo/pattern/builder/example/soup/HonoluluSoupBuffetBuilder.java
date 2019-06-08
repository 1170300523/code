package com.ijbamboo.pattern.builder.example.soup;

import com.ijbamboo.pattern.soup.HonoluluClamChowder;
import com.ijbamboo.pattern.soup.HonoluluFishChowder;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午3:39:12
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
