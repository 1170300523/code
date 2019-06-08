package com.ijbamboo.pattern.factorymethod.example.soup;

import com.ijbamboo.pattern.soup.ClamChowder;
import com.ijbamboo.pattern.soup.FishChowder;
import com.ijbamboo.pattern.soup.HonoluluClamChowder;
import com.ijbamboo.pattern.soup.HonoluluFishChowder;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午5:28:14
 */
public class HonoluluSoupFactoryMethodSubclass extends SoupFactoryMethod {
    public String makeBuffetName() {
        return "Honolulu Soup Buffet";
    }
    public ClamChowder makeClamChowder() {
        return new HonoluluClamChowder();
    }
    public FishChowder makeFishChowder() {
        return new HonoluluFishChowder();
    }
}
