package com.ijbamboo.pattern.factorymethod.example.soup;

import com.ijbamboo.pattern.soup.BostonClamChowder;
import com.ijbamboo.pattern.soup.BostonFishChowder;
import com.ijbamboo.pattern.soup.ClamChowder;
import com.ijbamboo.pattern.soup.FishChowder;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午5:26:31
 */
public class BostonSoupFactoryMethodSubclass extends SoupFactoryMethod {
    public String makeBuffetName() {
        return "Boston Soup Buffet";
    }
    public ClamChowder makeClamChowder() {
        return new BostonClamChowder();
    }
    public FishChowder makeFishChowder() {
        return new BostonFishChowder();
    }
}
